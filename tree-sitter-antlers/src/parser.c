#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 30
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 48
#define ALIAS_COUNT 0
#define TOKEN_COUNT 32
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
  anon_sym_EQ_EQ = 10,
  anon_sym_BANG_EQ = 11,
  anon_sym_GT_EQ = 12,
  anon_sym_LT_EQ = 13,
  anon_sym_AMP_AMP = 14,
  anon_sym_PIPE_PIPE = 15,
  anon_sym_QMARK_QMARK = 16,
  anon_sym_PLUS = 17,
  anon_sym_DASH = 18,
  anon_sym_STAR = 19,
  anon_sym_LT = 20,
  anon_sym_GT = 21,
  anon_sym_EQ = 22,
  anon_sym_BANG = 23,
  sym_variable = 24,
  sym_identifier = 25,
  anon_sym_DQUOTE = 26,
  aux_sym_string_token1 = 27,
  aux_sym_string_token2 = 28,
  anon_sym_SQUOTE = 29,
  aux_sym_string_token3 = 30,
  sym_number = 31,
  sym_template = 32,
  sym__node = 33,
  sym_tag = 34,
  sym_closing_tag = 35,
  sym__tag_body = 36,
  sym_modifier = 37,
  sym__primary = 38,
  sym_boolean = 39,
  sym_operator = 40,
  sym_string = 41,
  aux_sym_template_repeat1 = 42,
  aux_sym__tag_body_repeat1 = 43,
  aux_sym__tag_body_repeat2 = 44,
  aux_sym_modifier_repeat1 = 45,
  aux_sym_string_repeat1 = 46,
  aux_sym_string_repeat2 = 47,
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
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_QMARK_QMARK] = "\?\?",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_EQ] = "=",
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
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_QMARK_QMARK] = anon_sym_QMARK_QMARK,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_EQ] = anon_sym_EQ,
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
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK_QMARK] = {
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
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
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
  [14] = 14,
  [15] = 15,
  [16] = 16,
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
  [29] = 29,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(17);
      ADVANCE_MAP(
        '!', 41,
        '"', 54,
        '&', 4,
        '\'', 58,
        '*', 37,
        '+', 35,
        '-', 36,
        '/', 23,
        '<', 38,
        '=', 40,
        '>', 39,
        '?', 6,
        '\\', 14,
        'f', 42,
        'n', 51,
        't', 48,
        '{', 7,
        '|', 24,
        '}', 9,
      );
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(61);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(54);
      if (lookahead == '\\') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(55);
      if (lookahead != 0) ADVANCE(56);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(2);
      if (lookahead == '}') ADVANCE(10);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(2);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '&') ADVANCE(32);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(58);
      if (lookahead == '\\') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(59);
      if (lookahead != 0) ADVANCE(60);
      END_STATE();
    case 6:
      if (lookahead == '?') ADVANCE(34);
      END_STATE();
    case 7:
      if (lookahead == '{') ADVANCE(21);
      END_STATE();
    case 8:
      if (lookahead == '{') ADVANCE(21);
      if (lookahead != 0) ADVANCE(19);
      END_STATE();
    case 9:
      if (lookahead == '}') ADVANCE(22);
      END_STATE();
    case 10:
      if (lookahead == '}') ADVANCE(20);
      END_STATE();
    case 11:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(62);
      END_STATE();
    case 13:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 14:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(57);
      END_STATE();
    case 15:
      if (lookahead != 0 &&
          lookahead != '{') ADVANCE(19);
      END_STATE();
    case 16:
      if (eof) ADVANCE(17);
      if (lookahead == '{') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead != 0) ADVANCE(19);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '{') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead != 0) ADVANCE(19);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '{') ADVANCE(15);
      if (lookahead != 0) ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE);
      if (lookahead == '#') ADVANCE(3);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '|') ADVANCE(33);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_true);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_false);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_null);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_QMARK_QMARK);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(31);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(30);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(28);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(29);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'a') ADVANCE(45);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'e') ADVANCE(25);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'e') ADVANCE(26);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'l') ADVANCE(49);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'l') ADVANCE(27);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'l') ADVANCE(46);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'r') ADVANCE(50);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 's') ADVANCE(44);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'u') ADVANCE(43);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == 'u') ADVANCE(47);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_variable);
      if (lookahead == '.' ||
          lookahead == ':') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(56);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_string_token2);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(59);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(60);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(62);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 16},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 16},
  [15] = {.lex_state = 16},
  [16] = {.lex_state = 16},
  [17] = {.lex_state = 5},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 16},
  [22] = {.lex_state = 5},
  [23] = {.lex_state = 5},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 11},
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
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_QMARK_QMARK] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [sym_variable] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [aux_sym_string_token2] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
  },
  [1] = {
    [sym_template] = STATE(26),
    [sym__node] = STATE(14),
    [sym_tag] = STATE(14),
    [aux_sym_template_repeat1] = STATE(14),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_text] = ACTIONS(5),
    [sym_comment] = ACTIONS(7),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(9),
  },
  [2] = {
    [sym_modifier] = STATE(20),
    [sym__primary] = STATE(4),
    [sym_boolean] = STATE(4),
    [sym_operator] = STATE(4),
    [sym_string] = STATE(4),
    [aux_sym__tag_body_repeat1] = STATE(4),
    [aux_sym__tag_body_repeat2] = STATE(20),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(11),
    [anon_sym_SLASH] = ACTIONS(13),
    [anon_sym_PIPE] = ACTIONS(15),
    [anon_sym_true] = ACTIONS(17),
    [anon_sym_false] = ACTIONS(17),
    [anon_sym_null] = ACTIONS(17),
    [anon_sym_EQ_EQ] = ACTIONS(13),
    [anon_sym_BANG_EQ] = ACTIONS(13),
    [anon_sym_GT_EQ] = ACTIONS(13),
    [anon_sym_LT_EQ] = ACTIONS(13),
    [anon_sym_AMP_AMP] = ACTIONS(13),
    [anon_sym_PIPE_PIPE] = ACTIONS(13),
    [anon_sym_QMARK_QMARK] = ACTIONS(13),
    [anon_sym_PLUS] = ACTIONS(13),
    [anon_sym_DASH] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_LT] = ACTIONS(19),
    [anon_sym_GT] = ACTIONS(19),
    [anon_sym_EQ] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(19),
    [sym_variable] = ACTIONS(21),
    [anon_sym_DQUOTE] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(25),
    [sym_number] = ACTIONS(27),
  },
  [3] = {
    [sym_closing_tag] = STATE(27),
    [sym__tag_body] = STATE(27),
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
    [anon_sym_EQ_EQ] = ACTIONS(13),
    [anon_sym_BANG_EQ] = ACTIONS(13),
    [anon_sym_GT_EQ] = ACTIONS(13),
    [anon_sym_LT_EQ] = ACTIONS(13),
    [anon_sym_AMP_AMP] = ACTIONS(13),
    [anon_sym_PIPE_PIPE] = ACTIONS(13),
    [anon_sym_QMARK_QMARK] = ACTIONS(13),
    [anon_sym_PLUS] = ACTIONS(13),
    [anon_sym_DASH] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_LT] = ACTIONS(19),
    [anon_sym_GT] = ACTIONS(19),
    [anon_sym_EQ] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(19),
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
    [anon_sym_EQ_EQ] = ACTIONS(39),
    [anon_sym_BANG_EQ] = ACTIONS(39),
    [anon_sym_GT_EQ] = ACTIONS(39),
    [anon_sym_LT_EQ] = ACTIONS(39),
    [anon_sym_AMP_AMP] = ACTIONS(39),
    [anon_sym_PIPE_PIPE] = ACTIONS(39),
    [anon_sym_QMARK_QMARK] = ACTIONS(39),
    [anon_sym_PLUS] = ACTIONS(39),
    [anon_sym_DASH] = ACTIONS(39),
    [anon_sym_STAR] = ACTIONS(39),
    [anon_sym_LT] = ACTIONS(47),
    [anon_sym_GT] = ACTIONS(47),
    [anon_sym_EQ] = ACTIONS(47),
    [anon_sym_BANG] = ACTIONS(47),
    [sym_variable] = ACTIONS(50),
    [anon_sym_DQUOTE] = ACTIONS(53),
    [anon_sym_SQUOTE] = ACTIONS(56),
    [sym_number] = ACTIONS(59),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(66), 1,
      sym_variable,
    ACTIONS(64), 8,
      anon_sym_PIPE,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_EQ,
      anon_sym_BANG,
    ACTIONS(62), 15,
      anon_sym_RBRACE_RBRACE,
      anon_sym_SLASH,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_QMARK_QMARK,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_number,
  [31] = 2,
    ACTIONS(64), 9,
      anon_sym_PIPE,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_EQ,
      anon_sym_BANG,
      sym_variable,
    ACTIONS(62), 15,
      anon_sym_RBRACE_RBRACE,
      anon_sym_SLASH,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_QMARK_QMARK,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_number,
  [60] = 2,
    ACTIONS(70), 9,
      anon_sym_PIPE,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_EQ,
      anon_sym_BANG,
      sym_variable,
    ACTIONS(68), 15,
      anon_sym_RBRACE_RBRACE,
      anon_sym_SLASH,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_QMARK_QMARK,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_number,
  [89] = 2,
    ACTIONS(74), 9,
      anon_sym_PIPE,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_EQ,
      anon_sym_BANG,
      sym_variable,
    ACTIONS(72), 15,
      anon_sym_RBRACE_RBRACE,
      anon_sym_SLASH,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_QMARK_QMARK,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_number,
  [118] = 2,
    ACTIONS(78), 9,
      anon_sym_PIPE,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_EQ,
      anon_sym_BANG,
      sym_variable,
    ACTIONS(76), 15,
      anon_sym_RBRACE_RBRACE,
      anon_sym_SLASH,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_QMARK_QMARK,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_number,
  [147] = 8,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_SQUOTE,
    ACTIONS(82), 1,
      sym_variable,
    ACTIONS(84), 1,
      sym_number,
    STATE(11), 1,
      aux_sym_modifier_repeat1,
    ACTIONS(80), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
    ACTIONS(17), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(13), 3,
      sym__primary,
      sym_boolean,
      sym_string,
  [177] = 8,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_SQUOTE,
    ACTIONS(82), 1,
      sym_variable,
    ACTIONS(84), 1,
      sym_number,
    STATE(12), 1,
      aux_sym_modifier_repeat1,
    ACTIONS(86), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
    ACTIONS(17), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(13), 3,
      sym__primary,
      sym_boolean,
      sym_string,
  [207] = 8,
    ACTIONS(93), 1,
      sym_variable,
    ACTIONS(96), 1,
      anon_sym_DQUOTE,
    ACTIONS(99), 1,
      anon_sym_SQUOTE,
    ACTIONS(102), 1,
      sym_number,
    STATE(12), 1,
      aux_sym_modifier_repeat1,
    ACTIONS(88), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
    ACTIONS(90), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(13), 3,
      sym__primary,
      sym_boolean,
      sym_string,
  [237] = 2,
    ACTIONS(107), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
      sym_variable,
    ACTIONS(105), 5,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PIPE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      sym_number,
  [251] = 5,
    ACTIONS(9), 1,
      anon_sym_LBRACE_LBRACE,
    ACTIONS(109), 1,
      ts_builtin_sym_end,
    ACTIONS(111), 1,
      sym_text,
    ACTIONS(113), 1,
      sym_comment,
    STATE(15), 3,
      sym__node,
      sym_tag,
      aux_sym_template_repeat1,
  [269] = 5,
    ACTIONS(115), 1,
      ts_builtin_sym_end,
    ACTIONS(117), 1,
      sym_text,
    ACTIONS(120), 1,
      sym_comment,
    ACTIONS(123), 1,
      anon_sym_LBRACE_LBRACE,
    STATE(15), 3,
      sym__node,
      sym_tag,
      aux_sym_template_repeat1,
  [287] = 2,
    ACTIONS(126), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(128), 2,
      sym_comment,
      anon_sym_LBRACE_LBRACE,
  [296] = 4,
    ACTIONS(130), 1,
      aux_sym_string_token2,
    ACTIONS(132), 1,
      anon_sym_SQUOTE,
    ACTIONS(134), 1,
      aux_sym_string_token3,
    STATE(22), 1,
      aux_sym_string_repeat2,
  [309] = 4,
    ACTIONS(132), 1,
      anon_sym_DQUOTE,
    ACTIONS(136), 1,
      aux_sym_string_token1,
    ACTIONS(138), 1,
      aux_sym_string_token2,
    STATE(24), 1,
      aux_sym_string_repeat1,
  [322] = 3,
    ACTIONS(140), 1,
      anon_sym_RBRACE_RBRACE,
    ACTIONS(142), 1,
      anon_sym_PIPE,
    STATE(19), 2,
      sym_modifier,
      aux_sym__tag_body_repeat2,
  [333] = 3,
    ACTIONS(145), 1,
      anon_sym_RBRACE_RBRACE,
    ACTIONS(147), 1,
      anon_sym_PIPE,
    STATE(19), 2,
      sym_modifier,
      aux_sym__tag_body_repeat2,
  [344] = 2,
    ACTIONS(149), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(151), 2,
      sym_comment,
      anon_sym_LBRACE_LBRACE,
  [353] = 4,
    ACTIONS(153), 1,
      aux_sym_string_token2,
    ACTIONS(155), 1,
      anon_sym_SQUOTE,
    ACTIONS(157), 1,
      aux_sym_string_token3,
    STATE(23), 1,
      aux_sym_string_repeat2,
  [366] = 4,
    ACTIONS(159), 1,
      aux_sym_string_token2,
    ACTIONS(162), 1,
      anon_sym_SQUOTE,
    ACTIONS(164), 1,
      aux_sym_string_token3,
    STATE(23), 1,
      aux_sym_string_repeat2,
  [379] = 4,
    ACTIONS(155), 1,
      anon_sym_DQUOTE,
    ACTIONS(167), 1,
      aux_sym_string_token1,
    ACTIONS(169), 1,
      aux_sym_string_token2,
    STATE(25), 1,
      aux_sym_string_repeat1,
  [392] = 4,
    ACTIONS(171), 1,
      anon_sym_DQUOTE,
    ACTIONS(173), 1,
      aux_sym_string_token1,
    ACTIONS(176), 1,
      aux_sym_string_token2,
    STATE(25), 1,
      aux_sym_string_repeat1,
  [405] = 1,
    ACTIONS(179), 1,
      ts_builtin_sym_end,
  [409] = 1,
    ACTIONS(181), 1,
      anon_sym_RBRACE_RBRACE,
  [413] = 1,
    ACTIONS(183), 1,
      anon_sym_RBRACE_RBRACE,
  [417] = 1,
    ACTIONS(185), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 31,
  [SMALL_STATE(7)] = 60,
  [SMALL_STATE(8)] = 89,
  [SMALL_STATE(9)] = 118,
  [SMALL_STATE(10)] = 147,
  [SMALL_STATE(11)] = 177,
  [SMALL_STATE(12)] = 207,
  [SMALL_STATE(13)] = 237,
  [SMALL_STATE(14)] = 251,
  [SMALL_STATE(15)] = 269,
  [SMALL_STATE(16)] = 287,
  [SMALL_STATE(17)] = 296,
  [SMALL_STATE(18)] = 309,
  [SMALL_STATE(19)] = 322,
  [SMALL_STATE(20)] = 333,
  [SMALL_STATE(21)] = 344,
  [SMALL_STATE(22)] = 353,
  [SMALL_STATE(23)] = 366,
  [SMALL_STATE(24)] = 379,
  [SMALL_STATE(25)] = 392,
  [SMALL_STATE(26)] = 405,
  [SMALL_STATE(27)] = 409,
  [SMALL_STATE(28)] = 413,
  [SMALL_STATE(29)] = 417,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__tag_body, 1, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator, 1, 0, 0),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator, 1, 0, 0),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean, 1, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_modifier, 2, 0, 1),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_modifier, 3, 0, 3),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4), SHIFT_REPEAT(7),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4), SHIFT_REPEAT(13),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4), SHIFT_REPEAT(18),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4), SHIFT_REPEAT(17),
  [102] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_modifier_repeat1, 2, 0, 4), SHIFT_REPEAT(13),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_modifier_repeat1, 1, 0, 2),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_modifier_repeat1, 1, 0, 2),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0),
  [117] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [120] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [123] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 2, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 2, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat2, 2, 0, 0),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__tag_body_repeat2, 2, 0, 0), SHIFT_REPEAT(29),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__tag_body, 2, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 3, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 3, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [155] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [159] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0), SHIFT_REPEAT(23),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0),
  [164] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0), SHIFT_REPEAT(23),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [169] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [173] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [176] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [179] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_closing_tag, 2, 0, 1),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
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
