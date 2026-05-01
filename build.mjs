import * as esbuild from 'esbuild';
import { fileURLToPath } from 'node:url';
import { dirname, resolve } from 'node:path';

const __dirname = dirname(fileURLToPath(import.meta.url));
const clientDir = resolve(__dirname, 'packages/client');
const serverDir = resolve(__dirname, 'packages/server');

const isWatch = process.argv.includes('--watch');
const isProduction = process.argv.includes('--production');

const common = {
	bundle: true,
	minify: isProduction,
	sourcemap: !isProduction,
	platform: 'node',
	target: 'node18',
	format: 'cjs',
	logLevel: 'info'
};

const configs = [
	{
		...common,
		entryPoints: [resolve(__dirname, 'packages/client/src/extension.ts')],
		outfile: resolve(clientDir, 'dist/extension.js'),
		external: ['vscode']
	},
	{
		...common,
		entryPoints: [resolve(__dirname, 'packages/server/src/server.ts')],
		outfile: resolve(clientDir, 'dist/server.js'),
		external: []
	},
	{
		...common,
		entryPoints: [resolve(__dirname, 'packages/server/src/server.ts')],
		outfile: resolve(serverDir, 'dist/server.js'),
		external: []
	}
];

if (isWatch) {
	const ctxs = await Promise.all(configs.map(c => esbuild.context(c)));
	await Promise.all(ctxs.map(c => c.watch()));
	console.log('esbuild: watching for changes...');
} else {
	await Promise.all(configs.map(c => esbuild.build(c)));
}
