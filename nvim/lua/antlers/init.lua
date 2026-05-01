-- antlers.nvim
--
-- Wires up the Antlers language server (`td-antlers-language-server`) and the
-- Antlers tree-sitter grammar inside Neovim. Run `require('antlers').setup()`
-- from your config.

local M = {}

---@class antlers.Config
---@field cmd? string[]                    Override the LSP command.
---@field root_markers? string[]           Files / dirs that anchor the workspace.
---@field settings? table                  LSP `workspace/configuration` payload.
---@field auto_install_treesitter? boolean Try `:TSInstall antlers` if missing (default: true).
---@field on_attach? fun(client: vim.lsp.Client, bufnr: integer)

local defaults = {
	cmd = { 'td-antlers-language-server', '--stdio' },
	root_markers = {
		'antlerslint.config.js',
		'antlerslint.config.mjs',
		'antlerslint.config.cjs',
		'antlerslint.config.json',
		'composer.json',
		'.git',
	},
	settings = {
		antlers = {
			maxNumberOfProblems = 100,
		},
	},
	auto_install_treesitter = true,
}

local function register_treesitter(opts)
	local ok, parsers = pcall(require, 'nvim-treesitter.parsers')
	if not ok then
		return
	end

	local configs = parsers.get_parser_configs()
	if configs.antlers == nil then
		configs.antlers = {
			install_info = {
				url = 'https://github.com/josh-theory/antlers-vscode',
				location = 'tree-sitter-antlers',
				files = { 'src/parser.c' },
				branch = 'main',
			},
			filetype = 'antlers',
		}
	end

	if opts.auto_install_treesitter then
		local has_parser = pcall(vim.treesitter.language.inspect, 'antlers')
		if not has_parser then
			pcall(vim.cmd, 'TSInstall! antlers')
		end
	end
end

local function register_lsp(opts)
	-- Prefer the modern vim.lsp.config API (Neovim 0.11+); fall back to manual start.
	if vim.lsp.config and vim.lsp.enable then
		vim.lsp.config('antlers', {
			cmd = opts.cmd,
			filetypes = { 'antlers' },
			root_markers = opts.root_markers,
			settings = opts.settings,
			on_attach = opts.on_attach,
		})
		vim.lsp.enable('antlers')
		return
	end

	vim.api.nvim_create_autocmd('FileType', {
		pattern = 'antlers',
		callback = function(args)
			local root = vim.fs.root(args.buf, opts.root_markers) or vim.fn.getcwd()
			vim.lsp.start({
				name = 'antlers',
				cmd = opts.cmd,
				root_dir = root,
				settings = opts.settings,
				on_attach = opts.on_attach,
			})
		end,
	})
end

function M.setup(user_opts)
	local opts = vim.tbl_deep_extend('force', defaults, user_opts or {})
	register_treesitter(opts)
	register_lsp(opts)
end

return M
