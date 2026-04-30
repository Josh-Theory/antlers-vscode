# Antlers Language Support — Packaging & Distribution Guide

## Overview

This extension provides Antlers template language support in VS Code (syntax highlighting,
semantic tokens, and diagnostics via the Antlers linter). The build system uses esbuild to
bundle the VS Code client extension and the language server — plus all their dependencies —
into two self-contained JS files inside `packages/client/dist/`. The resulting `.vsix` file
is fully plug-and-play: no `npm install` or compile step needed by the recipient.

---

## Prerequisites (for the person packaging)

- **Node.js** ≥ 18
- **VS Code** ≥ 1.100.0
- `npm install` run from the workspace root at least once

---

## Packaging

From the workspace root, run:

```bash
npm run package
```

This runs three steps in order:

1. **`npm run check`** — TypeScript type-checks both packages (no output emitted)
2. **`npm run compile:prod`** — esbuild bundles `packages/client/src/extension.ts` and
   `packages/server/src/server.ts` into minified files at `packages/client/dist/`
3. **`vsce package`** — creates `td-antlers-vscode-<version>.vsix` in the workspace root

The VSIX contains:
```
extension/
├─ package.json
├─ dist/
│  ├─ extension.js   ← bundled client (vscode-languageclient + extension code)
│  └─ server.js      ← bundled server (language server + linter + parser)
└─ syntaxes/
   └─ antlers.tmLanguage.json
```

### Bumping the version before a release

Edit `"version"` in `packages/client/package.json`. The VSIX filename reflects this version.

---

## Sharing with the team

Send the `.vsix` file directly (Slack, email, shared drive, GitHub release, etc.).

Recipients do **not** need Node.js or any build tools.

---

## Installation (recipient steps)

### Option A — VS Code UI

1. Open VS Code
2. Open the Extensions panel (`Ctrl+Shift+X` / `Cmd+Shift+X`)
3. Click the **`···`** menu (top-right of the Extensions panel)
4. Choose **Install from VSIX...**
5. Select the `.vsix` file
6. Reload VS Code when prompted

### Option B — Command line

```bash
code --install-extension td-antlers-vscode-0.0.1.vsix
```

---

## Using the extension

Once installed, the extension activates automatically whenever you open a file with the
`.antlers.html` extension.

**What you get:**

| Feature | Description |
|---|---|
| Syntax highlighting | Grammar-based coloring for Antlers tags, variables, and modifiers |
| Semantic tokens | Precise token-level coloring (variables, functions, operators, strings, keywords, comments) |
| Diagnostics | Linting errors and warnings inline, powered by `td-antlers-linter` |
| Linter config | Place an `antlerslint.config.{js,mjs,cjs,json}` in your workspace root to customize rules |

**Settings** (VS Code settings.json):

```jsonc
{
  // Maximum number of linter diagnostics shown per file (default: 100)
  "antlers.maxNumberOfProblems": 100,

  // Log client-server communication — useful for debugging (default: "off")
  "antlers.trace.server": "off"  // or "messages" | "verbose"
}
```

---

## Development workflow (for contributors)

```bash
# Install dependencies
npm install

# Type-check only (no output)
npm run check

# Build bundles for development (with source maps, no minification)
npm run compile

# Build and watch for changes
npm run compile:watch

# Launch the extension in a VS Code Extension Development Host
# (use F5 in VS Code with this repo open — runs compile first via preLaunchTask)
```

To debug both the client and the server simultaneously, use the **Client + Server**
compound launch configuration in `.vscode/launch.json`. The server exposes a debug port
on `6009` which the "Attach to Server" config connects to.
