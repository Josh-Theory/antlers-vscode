# Antlers Language Support — Packaging & Distribution Guide

This repository ships Antlers tooling along two independent distribution paths:

| Path | Artifact | Source | Distribution channel |
| --- | --- | --- | --- |
| **VS Code** | `td-antlers-vscode` extension | `packages/client/` (bundles `packages/server/`) | Visual Studio Marketplace / VSIX |
| **Neovim** | `td-antlers-language-server` (npm) + `tree-sitter-antlers` grammar + `antlers.nvim` plugin | `packages/server/`, `tree-sitter-antlers/`, `nvim/` | npm + Git |

Both paths are driven by the same language server (`packages/server/`). VS Code bundles it inline; Neovim installs it from npm and uses a tree-sitter grammar for highlighting.

The workspace root `package.json` is `"private": true` — never run `npm publish` from the workspace root. Publishing happens from individual package directories.

---

## Prerequisites

For anyone publishing from this repo:

- Node.js ≥ 18
- A clone of the repo with `npm install` run from the workspace root

Path-specific extras are listed under each section below.

---

# Path 1 — VS Code

## What ships

A single `.vsix` (or Marketplace listing) containing:

```
extension/
├─ package.json
├─ dist/
│  ├─ extension.js   ← bundled VS Code client
│  └─ server.js      ← bundled language server (linter + parser inlined)
└─ syntaxes/
   └─ antlers.tmLanguage.json
```

Recipients do **not** need Node.js or any build tools.

## Publishing — VSIX

Use this for private/team distribution.

1. Bump `"version"` in `packages/client/package.json`.
2. From the workspace root:

   ```bash
   npm run package
   ```

   This runs three steps:

   1. `npm run check` — TypeScript type-checks both packages
   2. `npm run compile:prod` — esbuild bundles client + server (minified) into `packages/client/dist/`
   3. `vsce package` — creates `td-antlers-vscode-<version>.vsix` in the workspace root
3. Install the generated VSIX locally and smoke-test against an `.antlers.html` file.
4. Share the `.vsix` via Slack / email / shared drive / GitHub release.

## Publishing — Marketplace

Use this for public or organization-wide distribution.

One-time setup:

1. Confirm `packages/client/package.json` Marketplace metadata is correct (`publisher`, `name`, `displayName`, `description`, `categories`, `repository`, `license`).
2. Create / verify the Visual Studio Marketplace publisher account for that publisher ID.
3. Generate a Marketplace publishing token and log in:

   ```bash
   cd packages/client
   npx vsce login josh-theory
   ```

Each release:

```bash
# Bump packages/client/package.json "version" first
npm run package

cd packages/client
npx vsce publish --packagePath ../../td-antlers-vscode-<version>.vsix
```

Replace `<version>` with the version you just bumped to.

> `vsce publish` is the publish action for this project. `npm publish` would push JS package metadata to the npm registry, which does **not** install as a VS Code extension.

## Installing — Marketplace

VS Code UI:

1. Extensions panel (`Ctrl+Shift+X` / `Cmd+Shift+X`)
2. Search **Antlers Language Support** (publisher `josh-theory`)
3. Install, reload if prompted

CLI:

```bash
code --install-extension josh-theory.td-antlers-vscode
```

## Installing — VSIX

VS Code UI:

1. Extensions panel → `...` menu → **Install from VSIX...**
2. Select the `.vsix`, reload when prompted

CLI:

```bash
code --install-extension td-antlers-vscode-<version>.vsix
```

## What you get

| Feature | Description |
| --- | --- |
| Syntax highlighting | Grammar-based coloring for Antlers tags, variables, modifiers |
| Semantic tokens | Precise token-level coloring (variables, functions, operators, strings, keywords, comments) |
| Diagnostics | Linting errors and warnings inline, powered by `td-antlers-linter` |
| Linter config | Place an `antlerslint.config.{js,mjs,cjs,json}` in your workspace root |

Settings (VS Code `settings.json`):

```jsonc
{
  // Maximum number of linter diagnostics shown per file (default: 100)
  "antlers.maxNumberOfProblems": 100,

  // Log client-server communication — useful for debugging (default: "off")
  "antlers.trace.server": "off"  // or "messages" | "verbose"
}
```

---

# Path 2 — Neovim

## What ships

Three independent artifacts. End users always need (1); (2) and (3) are optional but recommended for a full experience:

1. **`td-antlers-language-server`** — the LSP binary, installed from npm.
2. **`tree-sitter-antlers`** grammar — checked into this repo at `tree-sitter-antlers/`, compiled locally by `nvim-treesitter`.
3. **`antlers.nvim`** plugin — the `nvim/` directory in this repo, loaded by a Lua plugin manager.

## Publishing — npm (language server)

The server in `packages/server/` is published as [`td-antlers-language-server`](https://www.npmjs.com/package/td-antlers-language-server).

One-time setup: log in to npm with a publisher account that owns (or can claim) the package name.

```bash
npm login
```

Each release:

1. Bump `"version"` in `packages/server/package.json`.
2. Publish:

   ```bash
   cd packages/server
   npm publish --access public
   ```

   `prepublishOnly` re-runs the production bundle, so `dist/server.js` is always rebuilt before publish. The tarball ships `dist/`, `bin/`, and `README.md` (see the `files` field).
3. Verify with `npx td-antlers-language-server@<version> --stdio` (it should hang waiting for an LSP `initialize`, which is correct).

## Publishing — tree-sitter grammar

The grammar source lives in `tree-sitter-antlers/`. The generated `src/parser.c` is checked in, so consumers don't need `tree-sitter-cli`.

After editing `grammar.js`:

```bash
cd tree-sitter-antlers
npm install
npx tree-sitter generate     # regenerates src/parser.c
npx tree-sitter test         # runs corpus tests in test/corpus/
git add src/ grammar.js test/ queries/
git commit -m "tree-sitter: <description>"
```

Distribution today is **source-only via this Git repo**. `nvim-treesitter` clones the repo and compiles `src/parser.c` on `:TSInstall antlers`. If the grammar matures, options for wider distribution:

- Publish to npm as `tree-sitter-antlers` (for consumers using `tree-sitter` from JS).
- Submit upstream to `nvim-treesitter/nvim-treesitter` so users get it without registering the parser themselves.

Neither of those is required for this repo's plugin to work.

## Publishing — Neovim plugin

The plugin is the `nvim/` directory of this repo. There is no separate registry — Neovim plugin managers fetch directly from Git. To "publish" a new version:

1. Make sure `nvim/lua/antlers/init.lua` and `nvim/README.md` reflect the change.
2. Tag a release (optional but recommended so users can pin):

   ```bash
   git tag nvim-v<version>
   git push origin nvim-v<version>
   ```
3. Announce the tag / commit. Users update by re-syncing their plugin manager.

## Installing — end-user setup

Users install in three steps. The first two are prerequisites; the third pulls in this repo.

### 1. Install the language server

```bash
npm install -g td-antlers-language-server
```

Verify `td-antlers-language-server` is on `$PATH`.

### 2. (Optional) Install nvim-treesitter

[`nvim-treesitter`](https://github.com/nvim-treesitter/nvim-treesitter) is required for tree-sitter highlighting. Skip if you don't want syntax highlighting beyond what the LSP provides via semantic tokens.

### 3. Install antlers.nvim

**lazy.nvim:**

```lua
{
  'josh-theory/antlers-vscode',
  config = function()
    vim.opt.runtimepath:append(vim.fn.stdpath('data') .. '/lazy/antlers-vscode/nvim')
    require('antlers').setup()
  end,
  ft = { 'antlers' },
}
```

**packer / vim-plug / manual:** clone the repo, then add `nvim/` to `runtimepath` and call `require('antlers').setup()`.

`setup()` accepts:

| Option | Default | Description |
| --- | --- | --- |
| `cmd` | `{ 'td-antlers-language-server', '--stdio' }` | LSP launch command |
| `root_markers` | `antlerslint.config.*`, `composer.json`, `.git` | Workspace anchors |
| `settings` | `{ antlers = { maxNumberOfProblems = 100 } }` | LSP `workspace/configuration` payload |
| `auto_install_treesitter` | `true` | Run `:TSInstall antlers` if the parser is missing |
| `on_attach` | `nil` | Standard LSP `on_attach` callback |

## Installing — without the plugin

If you'd rather wire it up by hand:

```lua
-- Filetype detection
vim.filetype.add({ pattern = { ['.*%.antlers%.html'] = 'antlers' } })

-- LSP (Neovim 0.11+)
vim.lsp.config('antlers', {
  cmd = { 'td-antlers-language-server', '--stdio' },
  filetypes = { 'antlers' },
  root_markers = { 'antlerslint.config.json', '.git' },
  settings = { antlers = { maxNumberOfProblems = 100 } },
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
-- :TSInstall antlers
```

## What you get

Same diagnostics and semantic-token coverage as VS Code (it's the same server). Tree-sitter additionally provides static highlighting and HTML injection (HTML inside `.antlers.html` files is parsed by tree-sitter-html and inherits its highlight set).

---

# Development workflow (contributors, both paths)

```bash
# Install workspace dependencies
npm install

# Type-check both packages (no output emitted)
npm run check

# Build dev bundles (sourcemaps, no minification) — emits to
#   packages/client/dist/extension.js
#   packages/client/dist/server.js
#   packages/server/dist/server.js
npm run compile

# Build and watch
npm run compile:watch

# Server unit tests
cd packages/server && npm test

# Tree-sitter grammar tests
cd tree-sitter-antlers && npx tree-sitter test
```

To debug both the VS Code client and server simultaneously, use the **Client + Server** compound launch configuration in `.vscode/launch.json`. The server exposes a debug port on `6009` which the "Attach to Server" config connects to.

To debug the Neovim path, run the published binary against a test document:

```bash
echo '{"jsonrpc":"2.0","id":1,"method":"initialize","params":{"capabilities":{}}}' \
  | td-antlers-language-server --stdio
```

(Wrap in proper LSP `Content-Length` framing for a real round-trip.)
