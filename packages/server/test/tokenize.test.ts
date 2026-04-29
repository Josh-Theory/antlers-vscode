import { test } from 'node:test';
import assert from 'node:assert/strict';

import { tokenize } from '../src/semantic-tokens/tokenize.ts';

test('empty input → no tokens', async () => {
	assert.deepEqual(await tokenize(''), []);
});

test('plain HTML → no tokens', async () => {
	assert.deepEqual(await tokenize('<p>hello</p>'), []);
});

test('{{ foo }} → variable token at column 3 length 3', async () => {
	const tokens = await tokenize('{{ foo }}');
	assert.deepEqual(tokens, [
		{ line: 0, char: 3, length: 3, type: 'variable' }
	]);
});

test('{{ if x }}…{{ /if }} → keyword, variable, keyword (closing /if)', async () => {
	const tokens = await tokenize('{{ if x }}hi{{ /if }}');
	assert.deepEqual(tokens, [
		{ line: 0, char: 3, length: 2, type: 'keyword' },
		{ line: 0, char: 6, length: 1, type: 'variable' },
		{ line: 0, char: 15, length: 3, type: 'keyword' }
	]);
});

test('{{ unless x }} → keyword "unless" highlighted (variable positions known-broken upstream)', async () => {
	const tokens = await tokenize('{{ unless x }}');
	const keyword = tokens.find(t => t.type === 'keyword');
	assert.deepEqual(keyword, { line: 0, char: 3, length: 6, type: 'keyword' });
});

test('multi-line: tags on different lines preserve line/char positions', async () => {
	const input = '<div>\n  {{ if user }}\n    <p>{{ user | upper }}</p>\n  {{ /if }}\n</div>';
	const tokens = await tokenize(input);
	assert.deepEqual(tokens, [
		{ line: 1, char: 5, length: 2, type: 'keyword' },   // if
		{ line: 1, char: 8, length: 4, type: 'variable' },  // user (after "  {{ if ")
		{ line: 2, char: 10, length: 4, type: 'variable' }, // user (after "    <p>{{ ")
		{ line: 2, char: 15, length: 1, type: 'operator' }, // |
		{ line: 2, char: 17, length: 5, type: 'function' }, // upper
		{ line: 3, char: 5, length: 3, type: 'keyword' }    // /if
	]);
});

test('nested tags: inner if inside outer foreach', async () => {
	const input = '{{ foreach items }}{{ if x }}y{{ /if }}{{ /foreach }}';
	const tokens = await tokenize(input);
	const types = tokens.map(t => t.type);
	assert.deepEqual(types, [
		'keyword',  // foreach
		'variable', // items
		'keyword',  // if
		'variable', // x
		'keyword',  // /if
		'keyword'   // /foreach
	]);
	assert.equal(tokens[0].char, 3);
	assert.equal(tokens[0].length, 7);
	assert.equal(tokens[5].length, 8); // /foreach
});

test('LSP requires tokens sorted by (line, char)', async () => {
	const input = '<div>\n  {{ if user }}\n    <p>{{ x }}</p>\n  {{ /if }}\n</div>';
	const tokens = await tokenize(input);
	for (let i = 1; i < tokens.length; i++) {
		const prev = tokens[i - 1];
		const cur = tokens[i];
		assert.ok(
			prev.line < cur.line || (prev.line === cur.line && prev.char < cur.char),
			`token ${i} not sorted: ${JSON.stringify(prev)} → ${JSON.stringify(cur)}`
		);
	}
});

test('{{# comment #}} → single comment token spanning whole block', async () => {
	assert.deepEqual(await tokenize('{{# c #}}'), [
		{ line: 0, char: 0, length: 9, type: 'comment' }
	]);
	assert.deepEqual(await tokenize('a {{# c #}} b'), [
		{ line: 0, char: 2, length: 9, type: 'comment' }
	]);
});

test('{{ foo == "bar" }} → variable, ==, string literal (incl. quotes)', async () => {
	const tokens = await tokenize('{{ foo == "bar" }}');
	assert.deepEqual(tokens, [
		{ line: 0, char: 3, length: 3, type: 'variable' },
		{ line: 0, char: 7, length: 2, type: 'operator' },
		{ line: 0, char: 10, length: 5, type: 'string' }
	]);
});

test('{{ foo | upper }} → variable, pipe operator, modifier function', async () => {
	const tokens = await tokenize('{{ foo | upper }}');
	assert.deepEqual(tokens, [
		{ line: 0, char: 3, length: 3, type: 'variable' },
		{ line: 0, char: 7, length: 1, type: 'operator' },
		{ line: 0, char: 9, length: 5, type: 'function' }
	]);
});
