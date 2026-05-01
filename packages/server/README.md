# td-antlers-language-server

A [Language Server Protocol](https://microsoft.github.io/language-server-protocol/) implementation for the [Antlers](https://statamic.dev/antlers) templating language used by Statamic.

Provides:

- Diagnostics powered by `td-antlers-linter`
- Semantic token highlighting for Antlers tags inside `*.antlers.html` files

## Install

```sh
npm install -g td-antlers-language-server
```

## Use

The server speaks LSP over stdio. Most editors will start it automatically once registered. Run directly with:

```sh
td-antlers-language-server --stdio
```

### Editor integrations

- **VS Code** — install the [Antlers Language Support](https://marketplace.visualstudio.com/items?itemName=josh-theory.td-antlers-vscode) extension, which bundles this server.
- **Neovim** — see [`antlers.nvim`](https://github.com/josh-theory/antlers-vscode/tree/main/nvim) in this repository, or wire it up by hand with `vim.lsp.config`:

  ```lua
  vim.lsp.config('antlers', {
    cmd = { 'td-antlers-language-server', '--stdio' },
    filetypes = { 'antlers' },
    root_markers = { 'antlerslint.config.js', 'antlerslint.config.json', '.git' },
  })
  vim.lsp.enable('antlers')
  ```

## Configuration

The server reads settings under the `antlers` key:

| Setting | Type | Default | Description |
| --- | --- | --- | --- |
| `antlers.maxNumberOfProblems` | number | `100` | Maximum number of diagnostics reported per file. |
| `antlers.trace.server` | `"off"` \| `"messages"` \| `"verbose"` | `"off"` | LSP trace level. |

Linter rules are configured per-project via `antlerslint.config.{js,mjs,cjs,json}` at the workspace root.
