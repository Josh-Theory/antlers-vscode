import { tokenTypeIndex } from './legend.js';
import type { Token } from './tokenize.js';

export function encode(tokens: Token[]): number[] {
	const data: number[] = [];
	let prevLine = 0;
	let prevChar = 0;
	for (const tok of tokens) {
		const deltaLine = tok.line - prevLine;
		const deltaChar = deltaLine === 0 ? tok.char - prevChar : tok.char;
		data.push(deltaLine, deltaChar, tok.length, tokenTypeIndex[tok.type], 0);
		prevLine = tok.line;
		prevChar = tok.char;
	}
	return data;
}
