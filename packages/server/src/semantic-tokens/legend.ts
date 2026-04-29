export const tokenTypes = [
	'operator',
	'variable',
	'function',
	'string',
	'number',
	'comment',
	'keyword'
] as const;

export type TokenType = (typeof tokenTypes)[number];

export const tokenTypeIndex: Record<TokenType, number> = tokenTypes.reduce(
	(acc, type, i) => {
		acc[type] = i;
		return acc;
	},
	{} as Record<TokenType, number>
);

export const tokenModifiers: readonly string[] = [];
