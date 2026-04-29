import type { TokenType } from './legend.js';

export interface Token {
	line: number;
	char: number;
	length: number;
	type: TokenType;
}

interface PositionLike {
	offset: number;
	line: number;
	char: number;
}

interface NodeLike {
	constructor: { name: string };
	startPosition?: PositionLike;
	endPosition?: PositionLike;
	runtimeNodes?: NodeLike[];
	isComment?: boolean;
	isTagNode?: boolean;
}

interface RuntimeRule {
	type: TokenType;
	startShift: number;
	lengthAdjust?: number;
}

const RUNTIME_RULES: Record<string, RuntimeRule> = {
	VariableNode: { type: 'variable', startShift: 1 },
	ModifierSeparator: { type: 'operator', startShift: 0 },
	ModifierNameNode: { type: 'function', startShift: 1 },
	EqualCompOperator: { type: 'operator', startShift: 0 },
	StringValueNode: { type: 'string', startShift: 0, lengthAdjust: 1 }
};

export async function tokenize(text: string): Promise<Token[]> {
	const { AntlersDocument } = await import('td-antlers-parser');
	const doc = AntlersDocument.fromText(text);
	const tokens: Token[] = [];
	for (const node of doc.getAllNodes() as NodeLike[]) {
		collectFromNode(text, node, tokens);
	}
	return tokens;
}

const COMMENT_RULE: RuntimeRule = { type: 'comment', startShift: 0, lengthAdjust: 1 };
const TAG_NAME_CHAR = /[A-Za-z0-9_:]/;

const CONTROL_KEYWORDS = new Set([
	'if', 'elseif', 'else', 'unless',
	'endif', 'endunless',
	'foreach', 'for', 'each',
	'endforeach', 'endfor', 'endeach'
]);

interface KeywordHit {
	token: Token;
	sourceStart: number;
	sourceEnd: number;
}

function collectFromNode(text: string, node: NodeLike, tokens: Token[]): void {
	if (node.constructor.name !== 'AntlersNode') return;
	if (node.isComment) {
		const tok = makeToken(node, COMMENT_RULE);
		if (tok) tokens.push(tok);
		return;
	}
	const kw = node.isTagNode ? findKeyword(text, node) : null;
	if (kw) tokens.push(kw.token);
	for (const inner of node.runtimeNodes ?? []) {
		const rule = RUNTIME_RULES[inner.constructor.name];
		if (!rule) continue;
		if (kw && overlapsKeyword(inner, kw)) continue;
		const tok = makeToken(inner, rule);
		if (tok) tokens.push(tok);
	}
}

function findKeyword(text: string, node: NodeLike): KeywordHit | null {
	const start = node.startPosition;
	if (!start) return null;
	let i = start.offset + 2; // skip "{{"
	while (i < text.length && /\s/.test(text[i])) i++;
	const slashStart = i;
	if (text[i] === '/') i++;
	const nameStart = i;
	while (i < text.length && TAG_NAME_CHAR.test(text[i])) i++;
	const nameEnd = i;
	if (nameEnd === nameStart) return null;
	const bareName = text.slice(nameStart, nameEnd);
	if (!CONTROL_KEYWORDS.has(bareName)) return null;
	return {
		token: {
			line: start.line - 1,
			char: start.char - 1 + (slashStart - start.offset),
			length: nameEnd - slashStart,
			type: 'keyword'
		},
		sourceStart: slashStart,
		sourceEnd: nameEnd
	};
}

function overlapsKeyword(node: NodeLike, kw: KeywordHit): boolean {
	const s = node.startPosition?.offset;
	const e = node.endPosition?.offset;
	if (s === undefined || e === undefined) return false;
	return s < kw.sourceEnd && e > kw.sourceStart;
}

function makeToken(node: NodeLike, rule: RuntimeRule): Token | null {
	const start = node.startPosition;
	const end = node.endPosition;
	if (!start || !end) return null;
	return {
		line: start.line - 1,
		char: start.char - 1 + rule.startShift,
		length: end.offset - start.offset + (rule.lengthAdjust ?? 0),
		type: rule.type
	};
}
