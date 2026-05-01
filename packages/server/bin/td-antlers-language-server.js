#!/usr/bin/env node
'use strict';

const { spawn } = require('node:child_process');
const path = require('node:path');

const serverPath = path.join(__dirname, '..', 'dist', 'server.js');
const args = process.argv.slice(2);
if (!args.some(a => a === '--stdio' || a === '--node-ipc' || a.startsWith('--socket'))) {
	args.unshift('--stdio');
}

const child = spawn(process.execPath, [serverPath, ...args], {
	stdio: 'inherit'
});

child.on('exit', code => process.exit(code ?? 0));
child.on('error', err => {
	process.stderr.write(`failed to launch antlers language server: ${err.message}\n`);
	process.exit(1);
});
