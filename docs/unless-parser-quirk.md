# `{{ unless }}` parser quirk

Variables and expressions inside `{{ unless … }}` and `{{ elseunless … }}` blocks
are reported by `td-antlers-parser` with positions that don't match the source
text. This breaks any consumer that uses parser-reported positions for source
mapping — most visibly, semantic-tokens highlighting in this LSP server.

The keyword (`unless` / `elseunless` / `endunless`) itself highlights correctly
because we resolve it from the source text directly. Everything inside the tag
is wrong.

## Reproduction

```js
import { AntlersDocument } from 'td-antlers-parser';
const doc = AntlersDocument.fromText('{{ unless x }}');
for (const r of doc.getAllNodes()[0].runtimeNodes) {
  console.log(r.constructor.name, r.startPosition.offset, r.endPosition.offset);
}
```

Output:

```
LogicalNegationOperator 3 4
LogicGroupBegin         4 5
VariableNode            5 6
LogicGroupEnd           8 9
```

In the source `{{ unless x }}` (length 14), `x` is at offset 10. The parser
reports it at offset 5 (the `l` in `unless`). The synthetic `!`, `(`, `)` nodes
have offsets that map onto subranges of the `unless` keyword.

## Root cause

`runtime/parser/antlersNodeParser.ts:251-280` rewrites every `{{ unless X }}`
node into a synthetic `{{ if !(X) }}` and re-lexes the synthetic content:

```ts
// antlersNodeParser.ts:264-272
if (node.isClosingTag == false) {
    const originalContent = node.getContent() ?? '',
        unlessContent = ' if !(' + originalContent + ') ';

    replacedNode.content = unlessContent;
    replacedNode.originalNode = node;
    replacedNode.resetContentCache();

    replacedNode.runtimeNodes = this.lexer.tokenize(replacedNode, replacedNode.getContent() ?? '');
    ...
}
```

The lexer then assigns positions assuming `replacedNode.getContent()` is the
real source — but it's the rewritten string. The positions are therefore
offsets into ` if !(x) `, not into the original ` unless x `. The lexer doesn't
know it's been handed synthetic content.

`elseunless` has the same treatment at `antlersNodeParser.ts:280-300`.

The original node is preserved on `replacedNode.originalNode`, which is the
hook a fix would build on.

## Fix on the parser side

Two viable approaches.

### Option A — preserve original positions (preferred)

After re-tokenizing the synthetic content, walk `replacedNode.runtimeNodes` and
remap each position back to a source offset in the *original* `unless`
expression. The mapping is straightforward because the rewrite is a fixed
prefix/suffix:

```
synthetic:  ' if !(<originalContent>) '
                 ^^^^^                 ^^
                 +6 prefix             +2 suffix
```

So a synthetic offset `s` in the rewritten string maps to an original-content
offset of `s - 6`, which then offsets from `node.originalNode.startPosition`.
Positions inside the synthetic prefix/suffix (the `!`, `(`, `)` nodes) should
either be dropped or marked `isVirtual: true` so consumers can filter them.

### Option B — flag the synthetic nodes and emit a real one

Mark the synthetic `LogicalNegationOperator` / `LogicGroupBegin` /
`LogicGroupEnd` with `isVirtual: true` (an existing flag on `AbstractNode`),
*and* additionally emit a real-position `VariableNode` (or whatever was inside
the original `unless x`) pointing at the source. Consumers filter `isVirtual`.

Option A is cleaner — it gives accurate positions for every inner node, not
just the top-level identifier — and doesn't require consumers to know about
`isVirtual`.

### Tests to add to the parser

`test/conditional_nodes.test.ts` already covers `unless` semantics. Add cases
that assert `runtimeNodes[i].startPosition.offset` equals the offset of the
corresponding token in the original source — for both `unless` and
`elseunless`, opening and closing tags, and a few inner expression shapes
(`{{ unless x }}`, `{{ unless x == "y" }}`, `{{ unless x | upper }}`).

## Cleanup needed in this repo once fixed

When the parser ships the fix:

1. **Remove the workaround test** in
   `packages/server/test/tokenize.test.ts`:

   ```ts
   test('{{ unless x }} → keyword "unless" highlighted (variable positions known-broken upstream)', ...)
   ```

   Replace with a full positional assertion matching the pattern of the other
   tests:

   ```ts
   test('{{ unless x }} → keyword + variable at correct positions', async () => {
     assert.deepEqual(await tokenize('{{ unless x }}'), [
       { line: 0, char: 3, length: 6, type: 'keyword' },
       { line: 0, char: 10, length: 1, type: 'variable' }
     ]);
   });
   ```

2. **If the parser uses Option B** (keeps synthetic nodes with
   `isVirtual: true`), filter them in
   `packages/server/src/semantic-tokens/tokenize.ts`:

   ```ts
   for (const inner of node.runtimeNodes ?? []) {
     if (inner.isVirtual) continue;
     ...
   }
   ```

   Add `isVirtual?: boolean` to the `NodeLike` interface.

   If the parser uses Option A (no synthetic nodes), no source change is
   required — the existing tokenizer logic Just Works because it relies on
   reported positions.

3. **Add a corresponding test for `elseunless`** — it has the same parser
   bug and the same fix, but no test currently covers it here because the
   broken-position case made it not worth asserting.

4. **Bump the `td-antlers-parser` version constraint** in
   `packages/server/package.json` to the version containing the fix, so the
   broken behavior can't be regressed onto by an older parser.

## How to verify the fix end-to-end

1. With the new parser version installed, run `npm test` from
   `packages/server` — the rewritten `unless` test (step 1 above) should pass.
2. Open `sample.antlers.html` in the Extension Dev Host and replace one of
   the `{{ if … }}` blocks with `{{ unless … }}`. The variable inside should
   be highlighted at its correct position, not somewhere inside the `unless`
   keyword.
