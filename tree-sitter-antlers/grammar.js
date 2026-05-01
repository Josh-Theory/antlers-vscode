/**
 * @file Tree-sitter grammar for the Antlers templating language.
 * @license MIT
 *
 * Focused on Antlers tags (`{{ ... }}` and `{{# ... #}}`); surrounding HTML
 * is captured as `text` nodes so editors can layer an HTML parser on top
 * via language injection (see queries/injections.scm).
 *
 * Antlers control-flow words (`if`, `foreach`, etc.) are emitted as plain
 * `variable` nodes; highlights.scm tags them via #match? predicates.
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
	name: 'antlers',

	extras: $ => [/[ \t\r\n]/],

	rules: {
		template: $ => repeat($._node),

		_node: $ => choice(
			$.comment,
			$.tag,
			$.text,
		),

		// Anything that isn't the start of an Antlers delimiter.
		text: $ => token(prec(-1, /([^{]|\{[^{])+/)),

		comment: $ => token(seq(
			'{{#',
			/([^#]|#+[^}#])*/,
			/#+\}\}/,
		)),

		tag: $ => seq(
			'{{',
			optional(choice(
				$.closing_tag,
				$._tag_body,
			)),
			'}}',
		),

		closing_tag: $ => prec(1, seq('/', field('name', $.variable))),

		_tag_body: $ => seq(
			repeat1(choice($._primary, $.operator)),
			repeat($.modifier),
		),

		modifier: $ => seq(
			'|',
			field('name', $.identifier),
			repeat(field('argument', $._primary)),
		),

		_primary: $ => choice(
			$.string,
			$.number,
			$.boolean,
			$.variable,
		),

		boolean: $ => choice('true', 'false', 'null'),

		operator: $ => choice(
			'==', '!=', '>=', '<=', '&&', '||', '??',
			'+', '-', '*', '/', '<', '>', '=', '!',
		),

		// Antlers variable paths, e.g. `posts:title` or `user.name`.
		variable: $ => /[a-zA-Z_][a-zA-Z0-9_]*([:.][a-zA-Z_][a-zA-Z0-9_]*)*/,

		identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

		string: $ => choice(
			seq('"', repeat(choice(/[^"\\]+/, /\\./)), '"'),
			seq("'", repeat(choice(/[^'\\]+/, /\\./)), "'"),
		),

		number: $ => /\d+(\.\d+)?/,
	},
});
