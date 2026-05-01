# antlers.nvim

Neovim integration for the Antlers templating language. Bundles:

- Filetype detection for `*.antlers.html`
- LSP setup for [`td-antlers-language-server`](../packages/server) (diagnostics + semantic tokens)
- Tree-sitter grammar registration with HTML language injection

## Requirements

- Neovim 0.10+ (0.11+ recommended for `vim.lsp.config`)
- [`td-antlers-language-server`](https://www.npmjs.com/package/td-antlers-language-server) on `$PATH`
  ```sh
  npm install -g td-antlers-language-server
  ```
- Optional, for highlights: [`nvim-treesitter`](https://github.com/nvim-treesitter/nvim-treesitter)

## Install

### lazy.nvim

```lua
{
  'josh-theory/antlers-vscode',
  -- Pull just the nvim plugin from the monorepo.
  config = function()
    vim.opt.runtimepath:append(vim.fn.stdpath('data') .. '/lazy/antlers-vscode/nvim')
    require('antlers').setup()
  end,
  ft = { 'antlers' },
}
```

### packer / manual

Add the `nvim/` directory to your `runtimepath`, then call `require('antlers').setup()`.

## Configuration

`setup()` accepts:

| Option | Default | Description |
| --- | --- | --- |
| `cmd` | `{ 'td-antlers-language-server', '--stdio' }` | LSP launch command. |
| `root_markers` | `antlerslint.config.*`, `composer.json`, `.git` | Files/dirs that anchor the workspace root. |
| `settings` | `{ antlers = { maxNumberOfProblems = 100 } }` | Sent as LSP `workspace/configuration`. |
| `auto_install_treesitter` | `true` | Attempt `:TSInstall antlers` if the parser is missing. |
| `on_attach` | `nil` | Standard LSP `on_attach` callback. |

Example with custom keymaps:

```lua
require('antlers').setup({
  on_attach = function(_, bufnr)
    vim.keymap.set('n', 'gd', vim.lsp.buf.definition, { buffer = bufnr })
  end,
  settings = {
    antlers = { maxNumberOfProblems = 200 },
  },
})
```

## Without this plugin

If you'd rather wire things up by hand:

```lua
-- Filetype
vim.filetype.add({ pattern = { ['.*%.antlers%.html'] = 'antlers' } })

-- LSP (Neovim 0.11+)
vim.lsp.config('antlers', {
  cmd = { 'td-antlers-language-server', '--stdio' },
  filetypes = { 'antlers' },
  root_markers = { 'antlerslint.config.json', '.git' },
})
vim.lsp.enable('antlers')

-- Tree-sitter (with nvim-treesitter)
require('nvim-treesitter.parsers').get_parser_configs().antlers = {
  install_info = {
    url = 'https://github.com/josh-theory/antlers-vscode',
    location = 'tree-sitter-antlers',
    files = { 'src/parser.c' },
    branch = 'main',
  },
  filetype = 'antlers',
}
```
