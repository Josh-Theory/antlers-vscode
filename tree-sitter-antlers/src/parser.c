#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 37
#define LARGE_STATE_COUNT 10
#define SYMBOL_COUNT 63
#define ALIAS_COUNT 0
#define TOKEN_COUNT 47
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 5

enum ts_symbol_identifiers {
  sym_text = 1,
  sym_comment = 2,
  anon_sym_LBRACE_LBRACE = 3,
  anon_sym_RBRACE_RBRACE = 4,
  anon_sym_SLASH = 5,
  anon_sym_PIPE = 6,
  anon_sym_true = 7,
  anon_sym_false = 8,
  anon_sym_null = 9,
  anon_sym_EQ_EQ_EQ = 10,
  anon_sym_BANG_EQ_EQ = 11,
  anon_sym_EQ_EQ = 12,
  anon_sym_BANG_EQ = 13,
  anon_sym_GT_EQ = 14,
  anon_sym_LT_EQ = 15,
  anon_sym_LT_EQ_GT = 16,
  anon_sym_AMP_AMP = 17,
  anon_sym_PIPE_PIPE = 18,
  anon_sym_and = 19,
  anon_sym_or = 20,
  anon_sym_xor = 21,
  anon_sym_PLUS_EQ = 22,
  anon_sym_DASH_EQ = 23,
  anon_sym_STAR_EQ = 24,
  anon_sym_SLASH_EQ = 25,
  anon_sym_PERCENT_EQ = 26,
  anon_sym_EQ = 27,
  anon_sym_STAR_STAR = 28,
  anon_sym_PLUS = 29,
  anon_sym_DASH = 30,
  anon_sym_STAR = 31,
  anon_sym_PERCENT = 32,
  anon_sym_QMARK_QMARK = 33,
  anon_sym_QMARK_COLON = 34,
  anon_sym_QMARK_EQ = 35,
  anon_sym_LT = 36,
  anon_sym_GT = 37,
  anon_sym_BANG = 38,
  sym_variable = 39,
  sym_identifier = 40,
  anon_sym_DQUOTE = 41,
  aux_sym_string_token1 = 42,
  aux_sym_string_token2 = 43,
  anon_sym_SQUOTE = 44,
  aux_sym_string_token3 = 45,
  sym_number = 46,
  sym_template = 47,
  sym__node = 48,
  sym_tag = 49,
  sym_closing_tag = 50,
  sym__tag_body = 51,
  sym_modifier = 52,
  sym__primary = 53,
  sym_boolean = 54,
  sym_operator = 55,
  sym_string = 56,
  aux_sym_template_repeat1 = 57,
  aux_sym__tag_body_repeat1 = 58,
  aux_sym__tag_body_repeat2 = 59,
  aux_sym_modifier_repeat1 = 60,
  aux_sym_string_repeat1 = 61,
  aux_sym_string_repeat2 = 62,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_text] = "text",
  [sym_comment] = "comment",
  [anon_sym_LBRACE_LBRACE] = "{{",
  [anon_sym_RBRACE_RBRACE] = "}}",
  [anon_sym_SLASH] = "/",
  [anon_sym_PIPE] = "|",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_null] = "null",
  [anon_sym_EQ_EQ_EQ] = "===",
  [anon_sym_BANG_EQ_EQ] = "!==",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_LT_EQ_GT] = "<=>",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_and] = "and",
  [anon_sym_or] = "or",
  [anon_sym_xor] = "xor",
  [anon_sym_PLUS_EQ] = "+=",
  [anon_sym_DASH_EQ] = "-=",
  [anon_sym_STAR_EQ] = "*=",
  [anon_sym_SLASH_EQ] = "/=",
  [anon_sym_PERCENT_EQ] = "%=",
  [anon_sym_EQ] = "=",
  [anon_sym_STAR_STAR] = "**",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_PERCENT] = "%",
  [anon_sym_QMARK_QMARK] = "\?\?",
  [anon_sym_QMARK_COLON] = "\?:",
  [anon_sym_QMARK_EQ] = "\?=",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_BANG] = "!",
  [sym_variable] = "variable",
  [sym_identifier] = "identifier",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [aux_sym_string_token2] = "string_token2",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_token3] = "string_token3",
  [sym_number] = "number",
  [sym_template] = "template",
  [sym__node] = "_node",
  [sym_tag] = "tag",
  [sym_closing_tag] = "closing_tag",
  [sym__tag_body] = "_tag_body",
  [sym_modifier] = "modifier",
  [sym__primary] = "_primary",
  [sym_boolean] = "boolean",
  [sym_operator] = "operator",
  [sym_string] = "string",
  [aux_sym_template_repeat1] = "template_repeat1",
  [aux_sym__tag_body_repeat1] = "_tag_body_repeat1",
  [aux_sym__tag_body_repeat2] = "_tag_body_repeat2",
  [aux_sym_modifier_repeat1] = "modifier_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_string_repeat2] = "string_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_text] = sym_text,
  [sym_comment] = sym_comment,
  [anon_sym_LBRACE_LBRACE] = anon_sym_LBRACE_LBRACE,
  [anon_sym_RBRACE_RBRACE] = anon_sym_RBRACE_RBRACE,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_null] = anon_sym_null,
  [anon_sym_EQ_EQ_EQ] = anon_sym_EQ_EQ_EQ,
  [anon_sym_BANG_EQ_EQ] = anon_sym_BANG_EQ_EQ,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_LT_EQ_GT] = anon_sym_LT_EQ_GT,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_or] = anon_sym_or,
  [anon_sym_xor] = anon_sym_xor,
  [anon_sym_PLUS_EQ] = anon_sym_PLUS_EQ,
  [anon_sym_DASH_EQ] = anon_sym_DASH_EQ,
  [anon_sym_STAR_EQ] = anon_sym_STAR_EQ,
  [anon_sym_SLASH_EQ] = anon_sym_SLASH_EQ,
  [anon_sym_PERCENT_EQ] = anon_sym_PERCENT_EQ,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_STAR_STAR] = anon_sym_STAR_STAR,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_QMARK_QMARK] = anon_sym_QMARK_QMARK,
  [anon_sym_QMARK_COLON] = anon_sym_QMARK_COLON,
  [anon_sym_QMARK_EQ] = anon_sym_QMARK_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_BANG] = anon_sym_BANG,
  [sym_variable] = sym_variable,
  [sym_identifier] = sym_identifier,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [aux_sym_string_token2] = aux_sym_string_token2,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_token3] = aux_sym_string_token3,
  [sym_number] = sym_number,
  [sym_template] = sym_template,
  [sym__node] = sym__node,
  [sym_tag] = sym_tag,
  [sym_closing_tag] = sym_closing_tag,
  [sym__tag_body] = sym__tag_body,
  [sym_modifier] = sym_modifier,
  [sym__primary] = sym__primary,
  [sym_boolean] = sym_boolean,
  [sym_operator] = sym_operator,
  [sym_string] = sym_string,
  [aux_sym_template_repeat1] = aux_sym_template_repeat1,
  [aux_sym__tag_body_repeat1] = aux_sym__tag_body_repeat1,
  [aux_sym__tag_body_repeat2] = aux_sym__tag_body_repeat2,
  [aux_sym_modifier_repeat1] = aux_sym_modifier_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_string_repeat2] = aux_sym_string_repeat2,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_null] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_xor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [sym_variable] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token3] = {
    .visible = false,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_template] = {
    .visible = true,
    .named = true,
  },
  [sym__node] = {
    .visible = false,
    .named = true,
  },
  [sym_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_closing_tag] = {
    .visible = true,
    .named = true,
  },
  [sym__tag_body] = {
    .visible = false,
    .named = true,
  },
  [sym_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym__primary] = {
    .visible = false,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_template_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__tag_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__tag_body_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_modifier_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat2] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_argument = 1,
  field_name = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_argument] = "argument",
  [field_name] = "name",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_argument, 0},
  [2] =
    {field_argument, 2, .inherited = true},
    {field_name, 1},
  [4] =
    {field_argument, 0, .inherited = true},
    {field_argument, 1, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 6,
  [15] = 7,
  [16] = 9,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 25,
  [30] = 28,
  [31] = 22,
  [32] = 23,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(18);
      ADVANCE_MAP(
        '!', 58,
        '"', 76,
        '%', 52,
        '&', 5,
        '\'', 80,
        '*', 51,
        '+', 49,
        '-', 50,
        '/', 24,
        '<', 56,
        '=', 47,
        '>', 57,
        '?', 7,
        '\\', 15,
        'a', 66,
        'f', 59,
        'n', 73,
        'o', 68,
        't', 70,
        'x', 67,
        '{', 8,
        '|', 26,
        '}', 10,
      );
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(83);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(76);
      if (lookahead == '\'') ADVANCE(80);
      if (lookahead == 'f') ADVANCE(59);
      if (lookahead == 'n') ADVANCE(73);
      if (lookahead == 't') ADVANCE(70);
      if (lookahead == '|') ADVANCE(25);
      if (lookahead == '}') ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(83);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(76);
      if (lookahead == '\\') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(77);
      if (lookahead != 0) ADVANCE(78);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(3);
      if (lookahead == '}') ADVANCE(11);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(3);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '&') ADVANCE(37);
      END_STATE();
    case 6:
      if (lookahead == '\'') ADVANCE(80);
      if (lookahead == '\\') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(81);
      if (lookahead != 0) ADVANCE(82);
      END_STATE();
    case 7:
      if (lookahead == ':') ADVANCE(54);
      if (lookahead == '=') ADVANCE(55);
      if (lookahead == '?') ADVANCE(53);
      END_STATE();
    case 8:
      if (lookahead == '{') ADVANCE(22);
      END_STATE();
    case 9:
      if (lookahead == '{') ADVANCE(22);
      if (lookahead != 0) ADVANCE(20);
      END_STATE();
    case 10:
      if (lookahead == '}') ADVANCE(23);
      END_STATE();
    case 11:
      if (lookahead == '}') ADVANCE(21);
      END_STATE();
    case 12:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(75);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      END_STATE();
    case 14:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 15:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(79);
      END_STATE();
    case 16:
      if (lookahead != 0 &&
          lookahead != '{') ADVANCE(20);
      END_STATE();
    case 17:
      if (eof) ADVANCE(18);
      if (lookahead == '{') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(19);
      if (lookahead != 0) ADVANCE(20);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '{') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(19);
      if (lookahead != 0) ADVANCE(20);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '{') ADVANCE(16);
      if (lookahead != 0) ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE);
      if (lookahead == '#') ADVANCE(4);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '=') ADVANCE(45);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '|') ADVANCE(38);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_true);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_false);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_null);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_EQ_EQ_EQ);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_BANG_EQ_EQ);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      if (lookahead == '=') ADVANCE(30);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      if (lookahead == '=') ADVANCE(31);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      if (lookahead == '>') ADVANCE(36);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_LT_EQ_GT);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_and);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_or);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_xor);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_PERCENT_EQ);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(32);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '=') ADVANCE(42);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '=') ADVANCE(43);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(48);
      if (lookahead == '=') ADVANCE(44);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '=') ADVANCE(46);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_QMARK_QMARK);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_QMARK_COLON);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_QMARK_EQ);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(35);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(34);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(33);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'a') ADVANCE(63);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'd') ADVANCE(39);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'e') ADVANCE(27);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'e') ADVANCE(28);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'l') ADVANCE(71);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'l') ADVANCE(29);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'l') ADVANCE(64);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'n') ADVANCE(60);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'o') ADVANCE(69);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'r') ADVANCE(40);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'r') ADVANCE(41);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'r') ADVANCE(72);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 's') ADVANCE(62);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'u') ADVANCE(61);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'u') ADVANCE(65);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(75);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(78);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(78);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_string_token2);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(82);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(82);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 17},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 17},
  [18] = {.lex_state = 17},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 17},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 6},
  [24] = {.lex_state = 17},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 6},
  [28] = {.lex_state = 6},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 6},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 6},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 12},
  [36] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ_EQ] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ_GT] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_or] = ACTIONS(1),
    [anon_sym_xor] = ACTIONS(1),
    [anon_sym_PLUS_EQ] = ACTIONS(1),
    [anon_sym_DASH_EQ] = ACTIONS(1),
    [anon_sym_STAR_EQ] = ACTIONS(1),
    [anon_sym_SLASH_EQ] = ACTIONS(1),
    [anon_sym_PERCENT_EQ] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_STAR_STAR] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_QMARK_QMARK] = ACTIONS(1),
    [anon_sym_QMARK_COLON] = ACTIONS(1),
    [anon_sym_QMARK_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [sym_variable] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [aux_sym_string_token2] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
  },
  [1] = {
    [sym_template] = STATE(34),
    [sym__node] = STATE(17),
    [sym_tag] = STATE(17),
    [aux_sym_template_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_text] = ACTIONS(5),
    [sym_comment] = ACTIONS(7),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(9),
  },
  [2] = {
    [sym_modifier] = STATE(19),
    [sym__primary] = STATE(4),
    [sym_boolean] = STATE(4),
    [sym_operator] = STATE(4),
    [sym_string] = STATE(4),
    [aux_sym__tag_body_repeat1] = STATE(4),
    [aux_sym__tag_body_repeat2] = STATE(19),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(11),
    [anon_sym_SLASH] = ACTIONS(13),
    [anon_sym_PIPE] = ACTIONS(15),
    [anon_sym_true] = ACTIONS(17),
    [anon_sym_false] = ACTIONS(17),
    [anon_sym_null] = ACTIONS(17),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(19),
    [anon_sym_BANG_EQ_EQ] = ACTIONS(19),
    [anon_sym_EQ_EQ] = ACTIONS(13),
    [anon_sym_BANG_EQ] = ACTIONS(13),
    [anon_sym_GT_EQ] = ACTIONS(19),
    [anon_sym_LT_EQ] = ACTIONS(13),
    [anon_sym_LT_EQ_GT] = ACTIONS(19),
    [anon_sym_AMP_AMP] = ACTIONS(19),
    [anon_sym_PIPE_PIPE] = ACTIONS(19),
    [anon_sym_and] = ACTIONS(13),
    [anon_sym_or] = ACTIONS(13),
    [anon_sym_xor] = ACTIONS(13),
    [anon_sym_PLUS_EQ] = ACTIONS(19),
    [anon_sym_DASH_EQ] = ACTIONS(19),
    [anon_sym_STAR_EQ] = ACTIONS(19),
    [anon_sym_SLASH_EQ] = ACTIONS(19),
    [anon_sym_PERCENT_EQ] = ACTIONS(19),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_STAR_STAR] = ACTIONS(19),
    [anon_sym_PLUS] = ACTIONS(13),
    [anon_sym_DASH] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_PERCENT] = ACTIONS(13),
    [anon_sym_QMARK_QMARK] = ACTIONS(19),
    [anon_sym_QMARK_COLON] = ACTIONS(19),
    [anon_sym_QMARK_EQ] = ACTIONS(19),
    [anon_sym_LT] = ACTIONS(13),
    [anon_sym_GT] = ACTIONS(13),
    [anon_sym_BANG] = ACTIONS(13),
    [sym_variable] = ACTIONS(21),
    [anon_sym_DQUOTE] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(25),
    [sym_number] = ACTIONS(27),
  },
  [3] = {
    [sym_closing_tag] = STATE(36),
    [sym__tag_body] = STATE(36),
    [sym__primary] = STATE(2),
    [sym_boolean] = STATE(2),
    [sym_operator] = STATE(2),
    [sym_string] = STATE(2),
    [aux_sym__tag_body_repeat1] = STATE(2),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(29),
    [anon_sym_SLASH] = ACTIONS(31),
    [anon_sym_true] = ACTIONS(17),
    [anon_sym_false] = ACTIONS(17),
    [anon_sym_null] = ACTIONS(17),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(19),
    [anon_sym_BANG_EQ_EQ] = ACTIONS(19),
    [anon_sym_EQ_EQ] = ACTIONS(13),
    [anon_sym_BANG_EQ] = ACTIONS(13),
    [anon_sym_GT_EQ] = ACTIONS(19),
    [anon_sym_LT_EQ] = ACTIONS(13),
    [anon_sym_LT_EQ_GT] = ACTIONS(19),
    [anon_sym_AMP_AMP] = ACTIONS(19),
    [anon_sym_PIPE_PIPE] = ACTIONS(19),
    [anon_sym_and] = ACTIONS(13),
    [anon_sym_or] = ACTIONS(13),
    [anon_sym_xor] = ACTIONS(13),
    [anon_sym_PLUS_EQ] = ACTIONS(19),
    [anon_sym_DASH_EQ] = ACTIONS(19),
    [anon_sym_STAR_EQ] = ACTIONS(19),
    [anon_sym_SLASH_EQ] = ACTIONS(19),
    [anon_sym_PERCENT_EQ] = ACTIONS(19),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_STAR_STAR] = ACTIONS(19),
    [anon_sym_PLUS] = ACTIONS(13),
    [anon_sym_DASH] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_PERCENT] = ACTIONS(13),
    [anon_sym_QMARK_QMARK] = ACTIONS(19),
    [anon_sym_QMARK_COLON] = ACTIONS(19),
    [anon_sym_QMARK_EQ] = ACTIONS(19),
    [anon_sym_LT] = ACTIONS(13),
    [anon_sym_GT] = ACTIONS(13),
    [anon_sym_BANG] = ACTIONS(13),
    [sym_variable] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(25),
    [sym_number] = ACTIONS(35),
  },
  [4] = {
    [sym__primary] = STATE(4),
    [sym_boolean] = STATE(4),
    [sym_operator] = STATE(4),
    [sym_string] = STATE(4),
    [aux_sym__tag_body_repeat1] = STATE(4),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(37),
    [anon_sym_SLASH] = ACTIONS(39),
    [anon_sym_PIPE] = ACTIONS(42),
    [anon_sym_true] = ACTIONS(44),
    [anon_sym_false] = ACTIONS(44),
    [anon_sym_null] = ACTIONS(44),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(47),
    [anon_sym_BANG_EQ_EQ] = ACTIONS(47),
    [anon_sym_EQ_EQ] = ACTIONS(39),
    [anon_sym_BANG_EQ] = ACTIONS(39),
    [anon_sym_GT_EQ] = ACTIONS(47),
    [anon_sym_LT_EQ] = ACTIONS(39),
    [anon_sym_LT_EQ_GT] = ACTIONS(47),
    [anon_sym_AMP_AMP] = ACTIONS(47),
    [anon_sym_PIPE_PIPE] = ACTIONS(47),
    [anon_sym_and] = ACTIONS(39),
    [anon_sym_or] = ACTIONS(39),
    [anon_sym_xor] = ACTIONS(39),
    [anon_sym_PLUS_EQ] = ACTIONS(47),
    [anon_sym_DASH_EQ] = ACTIONS(47),
    [anon_sym_STAR_EQ] = ACTIONS(47),
    [anon_sym_SLASH_EQ] = ACTIONS(47),
    [anon_sym_PERCENT_EQ] = ACTIONS(47),
    [anon_sym_EQ] = ACTIONS(39),
    [anon_sym_STAR_STAR] = ACTIONS(47),
    [anon_sym_PLUS] = ACTIONS(39),
    [anon_sym_DASH] = ACTIONS(39),
    [anon_sym_STAR] = ACTIONS(39),
    [anon_sym_PERCENT] = ACTIONS(39),
    [anon_sym_QMARK_QMARK] = ACTIONS(47),
    [anon_sym_QMARK_COLON] = ACTIONS(47),
    [anon_sym_QMARK_EQ] = ACTIONS(47),
    [anon_sym_LT] = ACTIONS(39),
    [anon_sym_GT] = ACTIONS(39),
    [anon_sym_BANG] = ACTIONS(39),
    [sym_variable] = ACTIONS(50),
    [anon_sym_DQUOTE] = ACTIONS(53),
    [anon_sym_SQUOTE] = ACTIONS(56),
    [sym_number] = ACTIONS(59),
  },
  [5] = {
    [anon_sym_RBRACE_RBRACE] = ACTIONS(62),
    [anon_sym_SLASH] = ACTIONS(64),
    [anon_sym_PIPE] = ACTIONS(64),
    [anon_sym_true] = ACTIONS(64),
    [anon_sym_false] = ACTIONS(64),
    [anon_sym_null] = ACTIONS(64),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(62),
    [anon_sym_BANG_EQ_EQ] = ACTIONS(62),
    [anon_sym_EQ_EQ] = ACTIONS(64),
    [anon_sym_BANG_EQ] = ACTIONS(64),
    [anon_sym_GT_EQ] = ACTIONS(62),
    [anon_sym_LT_EQ] = ACTIONS(64),
    [anon_sym_LT_EQ_GT] = ACTIONS(62),
    [anon_sym_AMP_AMP] = ACTIONS(62),
    [anon_sym_PIPE_PIPE] = ACTIONS(62),
    [anon_sym_and] = ACTIONS(64),
    [anon_sym_or] = ACTIONS(64),
    [anon_sym_xor] = ACTIONS(64),
    [anon_sym_PLUS_EQ] = ACTIONS(62),
    [anon_sym_DASH_EQ] = ACTIONS(62),
    [anon_sym_STAR_EQ] = ACTIONS(62),
    [anon_sym_SLASH_EQ] = ACTIONS(62),
    [anon_sym_PERCENT_EQ] = ACTIONS(62),
    [anon_sym_EQ] = ACTIONS(64),
    [anon_sym_STAR_STAR] = ACTIONS(62),
    [anon_sym_PLUS] = ACTIONS(64),
    [anon_sym_DASH] = ACTIONS(64),
    [anon_sym_STAR] = ACTIONS(64),
    [anon_sym_PERCENT] = ACTIONS(64),
    [anon_sym_QMARK_QMARK] = ACTIONS(62),
    [anon_sym_QMARK_COLON] = ACTIONS(62),
    [anon_sym_QMARK_EQ] = ACTIONS(62),
    [anon_sym_LT] = ACTIONS(64),
    [anon_sym_GT] = ACTIONS(64),
    [anon_sym_BANG] = ACTIONS(64),
    [sym_variable] = ACTIONS(64),
    [anon_sym_DQUOTE] = ACTIONS(62),
    [anon_sym_SQUOTE] = ACTIONS(62),
    [sym_number] = ACTIONS(62),
  },
  [6] = {
    [anon_sym_RBRACE_RBRACE] = ACTIONS(66),
    [anon_sym_SLASH] = ACTIONS(68),
    [anon_sym_PIPE] = ACTIONS(68),
    [anon_sym_true] = ACTIONS(68),
    [anon_sym_false] = ACTIONS(68),
    [anon_sym_null] = ACTIONS(68),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(66),
    [anon_sym_BANG_EQ_EQ] = ACTIONS(66),
    [anon_sym_EQ_EQ] = ACTIONS(68),
    [anon_sym_BANG_EQ] = ACTIONS(68),
    [anon_sym_GT_EQ] = ACTIONS(66),
    [anon_sym_LT_EQ] = ACTIONS(68),
    [anon_sym_LT_EQ_GT] = ACTIONS(66),
    [anon_sym_AMP_AMP] = ACTIONS(66),
    [anon_sym_PIPE_PIPE] = ACTIONS(66),
    [anon_sym_and] = ACTIONS(68),
    [anon_sym_or] = ACTIONS(68),
    [anon_sym_xor] = ACTIONS(68),
    [anon_sym_PLUS_EQ] = ACTIONS(66),
    [anon_sym_DASH_EQ] = ACTIONS(66),
    [anon_sym_STAR_EQ] = ACTIONS(66),
    [anon_sym_SLASH_EQ] = ACTIONS(66),
    [anon_sym_PERCENT_EQ] = ACTIONS(66),
    [anon_sym_EQ] = ACTIONS(68),
    [anon_sym_STAR_STAR] = ACTIONS(66),
    [anon_sym_PLUS] = ACTIONS(68),
    [anon_sym_DASH] = ACTIONS(68),
    [anon_sym_STAR] = ACTIONS(68),
    [anon_sym_PERCENT] = ACTIONS(68),
    [anon_sym_QMARK_QMARK] = ACTIONS(66),
    [anon_sym_QMARK_COLON] = ACTIONS(66),
    [anon_sym_QMARK_EQ] = ACTIONS(66),
    [anon_sym_LT] = ACTIONS(68),
    [anon_sym_GT] = ACTIONS(68),
    [anon_sym_BANG] = ACTIONS(68),
    [sym_variable] = ACTIONS(68),
    [anon_sym_DQUOTE] = ACTIONS(66),
    [anon_sym_SQUOTE] = ACTIONS(66),
    [sym_number] = ACTIONS(66),
  },
  [7] = {
    [anon_sym_RBRACE_RBRACE] = ACTIONS(70),
    [anon_sym_SLASH] = ACTIONS(72),
    [anon_sym_PIPE] = ACTIONS(72),
    [anon_sym_true] = ACTIONS(72),
    [anon_sym_false] = ACTIONS(72),
    [anon_sym_null] = ACTIONS(72),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(70),
    [anon_sym_BANG_EQ_EQ] = ACTIONS(70),
    [anon_sym_EQ_EQ] = ACTIONS(72),
    [anon_sym_BANG_EQ] = ACTIONS(72),
    [anon_sym_GT_EQ] = ACTIONS(70),
    [anon_sym_LT_EQ] = ACTIONS(72),
    [anon_sym_LT_EQ_GT] = ACTIONS(70),
    [anon_sym_AMP_AMP] = ACTIONS(70),
    [anon_sym_PIPE_PIPE] = ACTIONS(70),
    [anon_sym_and] = ACTIONS(72),
    [anon_sym_or] = ACTIONS(72),
    [anon_sym_xor] = ACTIONS(72),
    [anon_sym_PLUS_EQ] = ACTIONS(70),
    [anon_sym_DASH_EQ] = ACTIONS(70),
    [anon_sym_STAR_EQ] = ACTIONS(70),
    [anon_sym_SLASH_EQ] = ACTIONS(70),
    [anon_sym_PERCENT_EQ] = ACTIONS(70),
    [anon_sym_EQ] = ACTIONS(72),
    [anon_sym_STAR_STAR] = ACTIONS(70),
    [anon_sym_PLUS] = ACTIONS(72),
    [anon_sym_DASH] = ACTIONS(72),
    [anon_sym_STAR] = ACTIONS(72),
    [anon_sym_PERCENT] = ACTIONS(72),
    [anon_sym_QMARK_QMARK] = ACTIONS(70),
    [anon_sym_QMARK_COLON] = ACTIONS(70),
    [anon_sym_QMARK_EQ] = ACTIONS(70),
    [anon_sym_LT] = ACTIONS(72),
    [anon_sym_GT] = ACTIONS(72),
    [anon_sym_BANG] = ACTIONS(72),
    [sym_variable] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(70),
    [anon_sym_SQUOTE] = ACTIONS(70),
    [sym_number] = ACTIONS(70),
  },
  [8] = {
    [anon_sym_RBRACE_RBRACE] = ACTIONS(62),
    [anon_sym_SLASH] = ACTIONS(64),
    [anon_sym_PIPE] = ACTIONS(64),
    [anon_sym_true] = ACTIONS(64),
    [anon_sym_false] = ACTIONS(64),
    [anon_sym_null] = ACTIONS(64),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(62),
    [anon_sym_BANG_EQ_EQ] = ACTIONS(62),
    [anon_sym_EQ_EQ] = ACTIONS(64),
    [anon_sym_BANG_EQ] = ACTIONS(64),
    [anon_sym_GT_EQ] = ACTIONS(62),
    [anon_sym_LT_EQ] = ACTIONS(64),
    [anon_sym_LT_EQ_GT] = ACTIONS(62),
    [anon_sym_AMP_AMP] = ACTIONS(62),
    [anon_sym_PIPE_PIPE] = ACTIONS(62),
    [anon_sym_and] = ACTIONS(64),
    [anon_sym_or] = ACTIONS(64),
    [anon_sym_xor] = ACTIONS(64),
    [anon_sym_PLUS_EQ] = ACTIONS(62),
    [anon_sym_DASH_EQ] = ACTIONS(62),
    [anon_sym_STAR_EQ] = ACTIONS(62),
    [anon_sym_SLASH_EQ] = ACTIONS(62),
    [anon_sym_PERCENT_EQ] = ACTIONS(62),
    [anon_sym_EQ] = ACTIONS(64),
    [anon_sym_STAR_STAR] = ACTIONS(62),
    [anon_sym_PLUS] = ACTIONS(64),
    [anon_sym_DASH] = ACTIONS(64),
    [anon_sym_STAR] = ACTIONS(64),
    [anon_sym_PERCENT] = ACTIONS(64),
    [anon_sym_QMARK_QMARK] = ACTIONS(62),
    [anon_sym_QMARK_COLON] = ACTIONS(62),
    [anon_sym_QMARK_EQ] = ACTIONS(62),
    [anon_sym_LT] = ACTIONS(64),
    [anon_sym_GT] = ACTIONS(64),
    [anon_sym_BANG] = ACTIONS(64),
    [sym_variable] = ACTIONS(74),
    [anon_sym_DQUOTE] = ACTIONS(62),
    [anon_sym_SQUOTE] = ACTIONS(62),
    [sym_number] = ACTIONS(62),
  },
  [9] = {
    [anon_sym_RBRACE_RBRACE] = ACTIONS(76),
    [anon_sym_SLASH] = ACTIONS(78),
    [anon_sym_PIPE] = ACTIONS(78),
    [anon_sym_true] = ACTIONS(78),
    [anon_sym_false] = ACTIONS(78),
    [anon_sym_null] = ACTIONS(78),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(76),
    [anon_sym_BANG_EQ_EQ] = ACTIONS(76),
    [anon_sym_EQ_EQ] = ACTIONS(78),
    [anon_sym_BANG_EQ] = ACTIONS(78),
    [anon_sym_GT_EQ] = ACTIONS(76),
    [anon_sym_LT_EQ] = ACTIONS(78),
    [anon_sym_LT_EQ_GT] = ACTIONS(76),
    [anon_sym_AMP_AMP] = ACTIONS(76),
    [anon_sym_PIPE_PIPE] = ACTIONS(76),
    [anon_sym_and] = ACTIONS(78),
    [anon_sym_or] = ACTIONS(78),
    [anon_sym_xor] = ACTIONS(78),
    [anon_sym_PLUS_EQ] = ACTIONS(76),
    [anon_sym_DASH_EQ] = ACTIONS(76),
    [anon_sym_STAR_EQ] = ACTIONS(76),
    [anon_sym_SLASH_EQ] = ACTIONS(76),
    [anon_sym_PERCENT_EQ] = ACTIONS(76),
    [anon_sym_EQ] = ACTIONS(78),
    [anon_sym_STAR_STAR] = ACTIONS(76),
    [anon_sym_PLUS] = ACTIONS(78),
    [anon_sym_DASH] = ACTIONS(78),
    [anon_sym_STAR] = ACTIONS(78),
    [anon_sym_PERCENT] = ACTIONS(78),
    [anon_sym_QMARK_QMARK] = ACTIONS(76),
    [anon_sym_QMARK_COLON] = ACTIONS(76),
    [anon_sym_QMARK_EQ] = ACTIONS(76),
    [anon_sym_LT] = ACTIONS(78),
    [anon_sym_GT] = ACTIONS(78),
    [anon_sym_BANG] = ACTIONS(78),
    [sym_variable] = ACTIONS(78),
    [anon_sym_DQUOTE] = ACTIONS(76),
    [anon_sym_SQUOTE] = ACTIONS(76),
    [sym_number] = ACTIONS(76),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(84), 1,
      sym_variable,
    ACTIONS(86), 1,
      anon_sym_DQUOTE,
    ACTIONS(88), 1,
      anon_sym_SQUOTE,
    ACTIONS(90), 1,
      sym_number,
    STATE(11), 1,
      aux_sym_modifier_repeat1,
    ACTIONS(80), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
    ACTIONS(82), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(13), 3,
      sym__primary,
      sym_boolean,
      sym_string,
  [30] = 8,
    ACTIONS(97), 1,
      sym_variable,
    ACTIONS(100), 1,
      anon_sym_DQUOTE,
    ACTIONS(103), 1,
      anon_sym_SQUOTE,
    ACTIONS(106), 1,
      sym_number,
    STATE(11), 1,
      aux_sym_modifier_repeat1,
    ACTIONS(92), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
    ACTIONS(94), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(13), 3,
      sym__primary,
      sym_boolean,
      sym_string,
  [60] = 8,
    ACTIONS(84), 1,
      sym_variable,
    ACTIONS(86), 1,
      anon_sym_DQUOTE,
    ACTIONS(88), 1,
      anon_sym_SQUOTE,
    ACTIONS(90), 1,
      sym_number,
    STATE(10), 1,
      aux_sym_modifier_repeat1,
    ACTIONS(109), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
    ACTIONS(82), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(13), 3,
      sym__primary,
      sym_boolean,
      sym_string,
  [90] = 2,
    ACTIONS(113), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
      sym_variable,
    ACTIONS(111), 5,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_number,
  [104] = 2,
    ACTIONS(68), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
      sym_variable,
    ACTIONS(66), 5,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_number,
  [118] = 2,
    ACTIONS(72), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
      sym_variable,
    ACTIONS(70), 5,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_number,
  [132] = 2,
    ACTIONS(78), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
      sym_variable,
    ACTIONS(76), 5,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_number,
  [146] = 5,
    ACTIONS(9), 1,
      anon_sym_LBRACE_LBRACE,
    ACTIONS(115), 1,
      ts_builtin_sym_end,
    ACTIONS(117), 1,
      sym_text,
    ACTIONS(119), 1,
      sym_comment,
    STATE(18), 3,
      sym__node,
      sym_tag,
      aux_sym_template_repeat1,
  [164] = 5,
    ACTIONS(121), 1,
      ts_builtin_sym_end,
    ACTIONS(123), 1,
      sym_text,
    ACTIONS(126), 1,
      sym_comment,
    ACTIONS(129), 1,
      anon_sym_LBRACE_LBRACE,
    STATE(18), 3,
      sym__node,
      sym_tag,
      aux_sym_template_repeat1,
  [182] = 3,
    ACTIONS(132), 1,
      anon_sym_RBRACE_RBRACE,
    ACTIONS(134), 1,
      anon_sym_PIPE,
    STATE(26), 2,
      sym_modifier,
      aux_sym__tag_body_repeat2,
  [193] = 2,
    ACTIONS(136), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(138), 2,
      sym_comment,
      anon_sym_LBRACE_LBRACE,
  [202] = 4,
    ACTIONS(140), 1,
      anon_sym_DQUOTE,
    ACTIONS(142), 1,
      aux_sym_string_token1,
    ACTIONS(145), 1,
      aux_sym_string_token2,
    STATE(21), 1,
      aux_sym_string_repeat1,
  [215] = 4,
    ACTIONS(148), 1,
      anon_sym_DQUOTE,
    ACTIONS(150), 1,
      aux_sym_string_token1,
    ACTIONS(152), 1,
      aux_sym_string_token2,
    STATE(21), 1,
      aux_sym_string_repeat1,
  [228] = 4,
    ACTIONS(148), 1,
      anon_sym_SQUOTE,
    ACTIONS(154), 1,
      aux_sym_string_token2,
    ACTIONS(156), 1,
      aux_sym_string_token3,
    STATE(27), 1,
      aux_sym_string_repeat2,
  [241] = 2,
    ACTIONS(158), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(160), 2,
      sym_comment,
      anon_sym_LBRACE_LBRACE,
  [250] = 4,
    ACTIONS(162), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      aux_sym_string_token1,
    ACTIONS(166), 1,
      aux_sym_string_token2,
    STATE(22), 1,
      aux_sym_string_repeat1,
  [263] = 3,
    ACTIONS(168), 1,
      anon_sym_RBRACE_RBRACE,
    ACTIONS(170), 1,
      anon_sym_PIPE,
    STATE(26), 2,
      sym_modifier,
      aux_sym__tag_body_repeat2,
  [274] = 4,
    ACTIONS(173), 1,
      aux_sym_string_token2,
    ACTIONS(176), 1,
      anon_sym_SQUOTE,
    ACTIONS(178), 1,
      aux_sym_string_token3,
    STATE(27), 1,
      aux_sym_string_repeat2,
  [287] = 4,
    ACTIONS(162), 1,
      anon_sym_SQUOTE,
    ACTIONS(181), 1,
      aux_sym_string_token2,
    ACTIONS(183), 1,
      aux_sym_string_token3,
    STATE(23), 1,
      aux_sym_string_repeat2,
  [300] = 4,
    ACTIONS(185), 1,
      anon_sym_DQUOTE,
    ACTIONS(187), 1,
      aux_sym_string_token1,
    ACTIONS(189), 1,
      aux_sym_string_token2,
    STATE(31), 1,
      aux_sym_string_repeat1,
  [313] = 4,
    ACTIONS(185), 1,
      anon_sym_SQUOTE,
    ACTIONS(191), 1,
      aux_sym_string_token2,
    ACTIONS(193), 1,
      aux_sym_string_token3,
    STATE(32), 1,
      aux_sym_string_repeat2,
  [326] = 4,
    ACTIONS(150), 1,
      aux_sym_string_token1,
    ACTIONS(152), 1,
      aux_sym_string_token2,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    STATE(21), 1,
      aux_sym_string_repeat1,
  [339] = 4,
    ACTIONS(154), 1,
      aux_sym_string_token2,
    ACTIONS(156), 1,
      aux_sym_string_token3,
    ACTIONS(195), 1,
      anon_sym_SQUOTE,
    STATE(27), 1,
      aux_sym_string_repeat2,
  [352] = 1,
    ACTIONS(197), 1,
      anon_sym_RBRACE_RBRACE,
  [356] = 1,
    ACTIONS(199), 1,
      ts_builtin_sym_end,
  [360] = 1,
    ACTIONS(201), 1,
      sym_identifier,
  [364] = 1,
    ACTIONS(203), 1,
      anon_sym_RBRACE_RBRACE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(10)] = 0,
  [SMALL_STATE(11)] = 30,
  [SMALL_STATE(12)] = 60,
  [SMALL_STATE(13)] = 90,
  [SMALL_STATE(14)] = 104,
  [SMALL_STATE(15)] = 118,
  [SMALL_STATE(16)] = 132,
  [SMALL_STATE(17)] = 146,
  [SMALL_STATE(18)] = 164,
  [SMALL_STATE(19)] = 182,
  [SMALL_STATE(20)] = 193,
  [SMALL_STATE(21)] = 202,
  [SMALL_STATE(22)] = 215,
  [SMALL_STATE(23)] = 228,
  [SMALL_STATE(24)] = 241,
  [SMALL_STATE(25)] = 250,
  [SMALL_STATE(26)] = 263,
  [SMALL_STATE(27)] = 274,
  [SMALL_STATE(28)] = 287,
  [SMALL_STATE(29)] = 300,
  [SMALL_STATE(30)] = 313,
  [SMALL_STATE(31)] = 326,
  [SMALL_STATE(32)] = 339,
  [SMALL_STATE(33)] = 352,
  [SMALL_STATE(34)] = 356,
  [SMALL_STATE(35)] = 360,
  [SMALL_STATE(36)] = 364,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__tag_body, 1, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator, 1, 0, 0),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator, 1, 0, 0),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean, 1, 0, 0),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_modifier, 3, 0, 3),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [84] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4), SHIFT_REPEAT(14),
  [97] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4), SHIFT_REPEAT(13),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4), SHIFT_REPEAT(29),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4), SHIFT_REPEAT(30),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4), SHIFT_REPEAT(13),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_modifier, 2, 0, 1),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_modifier_repeat1, 1, 0, 2),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_modifier_repeat1, 1, 0, 2),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [129] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__tag_body, 2, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 3, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 3, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [145] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [152] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 2, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 2, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat2, 2, 0, 0),
  [170] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat2, 2, 0, 0), SHIFT_REPEAT(35),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0), SHIFT_REPEAT(27),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0),
  [178] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0), SHIFT_REPEAT(27),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [185] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [189] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [191] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_closing_tag, 2, 0, 1),
  [199] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_antlers(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
