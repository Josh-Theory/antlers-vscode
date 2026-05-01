# tree-sitter-antlers

A [Tree-sitter](https://tree-sitter.github.io/) grammar for the [Antlers](https://statamic.dev/antlers) templating language.

The grammar parses Antlers tags (`{{ ... }}` and `{{# ... #}}`); HTML between tags is exposed as `text` nodes so editors can layer the HTML grammar via [language injection](./queries/injections.scm).

## Build

```sh
npm install
npx tree-sitter generate
npx tree-sitter test
```

## Use in Neovim

Install with [`nvim-treesitter`](https://github.com/nvim-treesitter/nvim-treesitter) by registering the parser in your config (until/unless this lands upstream):

```lua
local parser_config = require('nvim-treesitter.parsers').get_parser_configs()
parser_config.antlers = {
  install_info = {
    url = 'https://github.com/josh-theory/antlers-vscode',
    location = 'tree-sitter-antlers',
    files = { 'src/parser.c' },
    branch = 'main',
  },
  filetype = 'antlers',
}
```

Then `:TSInstall antlers`. The [`antlers.nvim`](../nvim) plugin in this repo handles this for you.

## Grammar shape

| Node | Meaning |
| --- | --- |
| `tag` | `{{ ... }}` block, contains primaries / operators / modifiers |
| `closing_tag` | `{{ /name }}` |
| `comment` | `{{# ... #}}` |
| `modifier` | `\| name args...` inside a tag |
| `variable`, `string`, `number`, `boolean`, `operator` | terminals inside a tag |
| `text` | everything outside tags (gets HTML injected) |

Antlers control-flow words (`if`, `foreach`, etc.) are emitted as `variable` nodes; `highlights.scm` flags them as `@keyword.control` via a `#match?` predicate.
