import { test } from 'node:test';
import assert from 'node:assert/strict';

import { encode } from '../src/semantic-tokens/encode.ts';
import { tokenTypeIndex } from '../src/semantic-tokens/legend.ts';

test('empty token list → empty array', () => {
	assert.deepEqual(encode([]), []);
});

test('single token → 5 uint32 absolute (deltaLine=0, deltaStart=char)', () => {
	const data = encode([{ line: 0, char: 3, length: 3, type: 'variable' }]);
	assert.deepEqual(data, [0, 3, 3, tokenTypeIndex.variable, 0]);
});

test('two tokens on same line → second uses delta from first', () => {
	const data = encode([
		{ line: 0, char: 3, length: 3, type: 'variable' },
		{ line: 0, char: 9, length: 1, type: 'operator' }
	]);
	assert.deepEqual(data, [
		0, 3, 3, tokenTypeIndex.variable, 0,
		0, 6, 1, tokenTypeIndex.operator, 0
	]);
});

test('token on later line → deltaStart resets to absolute char', () => {
	const data = encode([
		{ line: 0, char: 3, length: 3, type: 'variable' },
		{ line: 2, char: 5, length: 2, type: 'keyword' }
	]);
	assert.deepEqual(data, [
		0, 3, 3, tokenTypeIndex.variable, 0,
		2, 5, 2, tokenTypeIndex.keyword, 0
	]);
});
