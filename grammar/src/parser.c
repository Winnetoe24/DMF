#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 248
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 123
#define ALIAS_COUNT 1
#define TOKEN_COUNT 62
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  anon_sym_dmf = 1,
  anon_sym_model = 2,
  anon_sym_version = 3,
  anon_sym_import = 4,
  anon_sym_from = 5,
  anon_sym_package = 6,
  anon_sym_struct = 7,
  anon_sym_extends = 8,
  anon_sym_implements = 9,
  anon_sym_arg = 10,
  anon_sym_ref = 11,
  anon_sym_func = 12,
  anon_sym_enum = 13,
  anon_sym__ = 14,
  anon_sym_entity = 15,
  anon_sym_identifier = 16,
  anon_sym_interface = 17,
  sym_number = 18,
  sym_identifier = 19,
  sym_comment = 20,
  sym_dot = 21,
  sym_byte_content = 22,
  anon_sym_SEMI = 23,
  anon_sym_COMMA = 24,
  anon_sym_LBRACE = 25,
  anon_sym_RBRACE = 26,
  anon_sym_LPAREN = 27,
  anon_sym_RPAREN = 28,
  sym__new_line = 29,
  sym_expand = 30,
  sym_byte = 31,
  sym_int = 32,
  sym_long = 33,
  sym_double = 34,
  sym_datetime = 35,
  sym_date = 36,
  sym_string = 37,
  sym_boolean = 38,
  sym_void = 39,
  anon_sym_L = 40,
  anon_sym_true = 41,
  anon_sym_false = 42,
  anon_sym_0x = 43,
  anon_sym_DQUOTE = 44,
  anon_sym_SQUOTE = 45,
  sym_string_content_single_quote = 46,
  sym_string_content_double_quote = 47,
  anon_sym_BSLASH = 48,
  aux_sym_escape_sequence_token1 = 49,
  aux_sym_escape_sequence_token2 = 50,
  aux_sym_escape_sequence_token3 = 51,
  aux_sym_escape_sequence_token4 = 52,
  anon_sym_T = 53,
  aux_sym_timeValue_token1 = 54,
  anon_sym_COLON = 55,
  aux_sym_timeValue_token2 = 56,
  anon_sym_D = 57,
  aux_sym_dateValue_token1 = 58,
  anon_sym_DASH = 59,
  aux_sym_dateValue_token2 = 60,
  aux_sym_dateValue_token3 = 61,
  sym_source_file = 62,
  sym_dmf_declaration = 63,
  sym_model_declaration = 64,
  sym_import_block = 65,
  sym_import_statement = 66,
  sym_model_identifier = 67,
  sym_model_content = 68,
  sym_comment_block = 69,
  sym_package_block = 70,
  sym_package_content = 71,
  sym_struct_block = 72,
  sym_extends_block = 73,
  sym_implements_block = 74,
  sym_struct_content = 75,
  sym_arg_block = 76,
  sym_ref_block = 77,
  sym_func_block = 78,
  sym_param_definition = 79,
  sym_enum_block = 80,
  sym_enum_content = 81,
  sym_enum_constant = 82,
  sym_enum_index = 83,
  sym_entity_block = 84,
  sym_identifier_statement = 85,
  sym_interface_block = 86,
  sym_interface_content = 87,
  sym__semicolon = 88,
  sym__comma = 89,
  sym__left_brace = 90,
  sym__right_brace = 91,
  sym__left_paren = 92,
  sym__right_paren = 93,
  sym_reftype = 94,
  sym_package_string = 95,
  sym_primitive_type = 96,
  sym_primitive_value = 97,
  sym_version_number = 98,
  sym_integerValue = 99,
  sym_longValue = 100,
  sym_booleanValue = 101,
  sym_byteValue = 102,
  sym_doubleValue = 103,
  sym_stringValue = 104,
  sym_escape_sequence = 105,
  sym_dateTimeValue = 106,
  sym_timeValue = 107,
  sym_dateValue = 108,
  aux_sym_import_block_repeat1 = 109,
  aux_sym_model_content_repeat1 = 110,
  aux_sym_comment_block_repeat1 = 111,
  aux_sym_struct_block_repeat1 = 112,
  aux_sym_implements_block_repeat1 = 113,
  aux_sym_func_block_repeat1 = 114,
  aux_sym_enum_block_repeat1 = 115,
  aux_sym_enum_constant_repeat1 = 116,
  aux_sym_identifier_statement_repeat1 = 117,
  aux_sym_interface_block_repeat1 = 118,
  aux_sym_reftype_repeat1 = 119,
  aux_sym_package_string_repeat1 = 120,
  aux_sym_stringValue_repeat1 = 121,
  aux_sym_stringValue_repeat2 = 122,
  anon_alias_sym_content = 123,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_dmf] = "dmf",
  [anon_sym_model] = "model",
  [anon_sym_version] = "version",
  [anon_sym_import] = "import",
  [anon_sym_from] = "from",
  [anon_sym_package] = "package",
  [anon_sym_struct] = "struct",
  [anon_sym_extends] = "extends",
  [anon_sym_implements] = "implements",
  [anon_sym_arg] = "arg",
  [anon_sym_ref] = "ref",
  [anon_sym_func] = "func",
  [anon_sym_enum] = "enum",
  [anon_sym__] = "_",
  [anon_sym_entity] = "entity",
  [anon_sym_identifier] = "identifier",
  [anon_sym_interface] = "interface",
  [sym_number] = "number",
  [sym_identifier] = "identifier",
  [sym_comment] = "comment",
  [sym_dot] = "dot",
  [sym_byte_content] = "byte_content",
  [anon_sym_SEMI] = ";",
  [anon_sym_COMMA] = ",",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym__new_line] = "_new_line",
  [sym_expand] = "expand",
  [sym_byte] = "byte",
  [sym_int] = "int",
  [sym_long] = "long",
  [sym_double] = "double",
  [sym_datetime] = "datetime",
  [sym_date] = "date",
  [sym_string] = "string",
  [sym_boolean] = "boolean",
  [sym_void] = "void",
  [anon_sym_L] = "L",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_0x] = "0x",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym_string_content_single_quote] = "string_content_single_quote",
  [sym_string_content_double_quote] = "string_content_double_quote",
  [anon_sym_BSLASH] = "\\",
  [aux_sym_escape_sequence_token1] = "escape_sequence_token1",
  [aux_sym_escape_sequence_token2] = "escape_sequence_token2",
  [aux_sym_escape_sequence_token3] = "escape_sequence_token3",
  [aux_sym_escape_sequence_token4] = "escape_sequence_token4",
  [anon_sym_T] = "T",
  [aux_sym_timeValue_token1] = "timeValue_token1",
  [anon_sym_COLON] = ":",
  [aux_sym_timeValue_token2] = "timeValue_token2",
  [anon_sym_D] = "D",
  [aux_sym_dateValue_token1] = "dateValue_token1",
  [anon_sym_DASH] = "-",
  [aux_sym_dateValue_token2] = "dateValue_token2",
  [aux_sym_dateValue_token3] = "dateValue_token3",
  [sym_source_file] = "source_file",
  [sym_dmf_declaration] = "dmf_declaration",
  [sym_model_declaration] = "model_declaration",
  [sym_import_block] = "import_block",
  [sym_import_statement] = "import_statement",
  [sym_model_identifier] = "model_identifier",
  [sym_model_content] = "model_content",
  [sym_comment_block] = "comment_block",
  [sym_package_block] = "package_block",
  [sym_package_content] = "package_content",
  [sym_struct_block] = "struct_block",
  [sym_extends_block] = "extends_block",
  [sym_implements_block] = "implements_block",
  [sym_struct_content] = "struct_content",
  [sym_arg_block] = "arg_block",
  [sym_ref_block] = "ref_block",
  [sym_func_block] = "func_block",
  [sym_param_definition] = "param_definition",
  [sym_enum_block] = "enum_block",
  [sym_enum_content] = "enum_content",
  [sym_enum_constant] = "enum_constant",
  [sym_enum_index] = "enum_index",
  [sym_entity_block] = "entity_block",
  [sym_identifier_statement] = "identifier_statement",
  [sym_interface_block] = "interface_block",
  [sym_interface_content] = "interface_content",
  [sym__semicolon] = "_semicolon",
  [sym__comma] = "_comma",
  [sym__left_brace] = "_left_brace",
  [sym__right_brace] = "_right_brace",
  [sym__left_paren] = "_left_paren",
  [sym__right_paren] = "_right_paren",
  [sym_reftype] = "reftype",
  [sym_package_string] = "package_string",
  [sym_primitive_type] = "primitive_type",
  [sym_primitive_value] = "primitive_value",
  [sym_version_number] = "version_number",
  [sym_integerValue] = "integerValue",
  [sym_longValue] = "longValue",
  [sym_booleanValue] = "booleanValue",
  [sym_byteValue] = "byteValue",
  [sym_doubleValue] = "doubleValue",
  [sym_stringValue] = "stringValue",
  [sym_escape_sequence] = "escape_sequence",
  [sym_dateTimeValue] = "dateTimeValue",
  [sym_timeValue] = "timeValue",
  [sym_dateValue] = "dateValue",
  [aux_sym_import_block_repeat1] = "import_block_repeat1",
  [aux_sym_model_content_repeat1] = "model_content_repeat1",
  [aux_sym_comment_block_repeat1] = "comment_block_repeat1",
  [aux_sym_struct_block_repeat1] = "struct_block_repeat1",
  [aux_sym_implements_block_repeat1] = "implements_block_repeat1",
  [aux_sym_func_block_repeat1] = "func_block_repeat1",
  [aux_sym_enum_block_repeat1] = "enum_block_repeat1",
  [aux_sym_enum_constant_repeat1] = "enum_constant_repeat1",
  [aux_sym_identifier_statement_repeat1] = "identifier_statement_repeat1",
  [aux_sym_interface_block_repeat1] = "interface_block_repeat1",
  [aux_sym_reftype_repeat1] = "reftype_repeat1",
  [aux_sym_package_string_repeat1] = "package_string_repeat1",
  [aux_sym_stringValue_repeat1] = "stringValue_repeat1",
  [aux_sym_stringValue_repeat2] = "stringValue_repeat2",
  [anon_alias_sym_content] = "content",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_dmf] = anon_sym_dmf,
  [anon_sym_model] = anon_sym_model,
  [anon_sym_version] = anon_sym_version,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_from] = anon_sym_from,
  [anon_sym_package] = anon_sym_package,
  [anon_sym_struct] = anon_sym_struct,
  [anon_sym_extends] = anon_sym_extends,
  [anon_sym_implements] = anon_sym_implements,
  [anon_sym_arg] = anon_sym_arg,
  [anon_sym_ref] = anon_sym_ref,
  [anon_sym_func] = anon_sym_func,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym__] = anon_sym__,
  [anon_sym_entity] = anon_sym_entity,
  [anon_sym_identifier] = anon_sym_identifier,
  [anon_sym_interface] = anon_sym_interface,
  [sym_number] = sym_number,
  [sym_identifier] = sym_identifier,
  [sym_comment] = sym_comment,
  [sym_dot] = sym_dot,
  [sym_byte_content] = sym_byte_content,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym__new_line] = sym__new_line,
  [sym_expand] = sym_expand,
  [sym_byte] = sym_byte,
  [sym_int] = sym_int,
  [sym_long] = sym_long,
  [sym_double] = sym_double,
  [sym_datetime] = sym_datetime,
  [sym_date] = sym_date,
  [sym_string] = sym_string,
  [sym_boolean] = sym_boolean,
  [sym_void] = sym_void,
  [anon_sym_L] = anon_sym_L,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_0x] = anon_sym_0x,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_string_content_single_quote] = sym_string_content_single_quote,
  [sym_string_content_double_quote] = sym_string_content_double_quote,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [aux_sym_escape_sequence_token1] = aux_sym_escape_sequence_token1,
  [aux_sym_escape_sequence_token2] = aux_sym_escape_sequence_token2,
  [aux_sym_escape_sequence_token3] = aux_sym_escape_sequence_token3,
  [aux_sym_escape_sequence_token4] = aux_sym_escape_sequence_token4,
  [anon_sym_T] = anon_sym_T,
  [aux_sym_timeValue_token1] = aux_sym_timeValue_token1,
  [anon_sym_COLON] = anon_sym_COLON,
  [aux_sym_timeValue_token2] = aux_sym_timeValue_token2,
  [anon_sym_D] = anon_sym_D,
  [aux_sym_dateValue_token1] = aux_sym_dateValue_token1,
  [anon_sym_DASH] = anon_sym_DASH,
  [aux_sym_dateValue_token2] = aux_sym_dateValue_token2,
  [aux_sym_dateValue_token3] = aux_sym_dateValue_token3,
  [sym_source_file] = sym_source_file,
  [sym_dmf_declaration] = sym_dmf_declaration,
  [sym_model_declaration] = sym_model_declaration,
  [sym_import_block] = sym_import_block,
  [sym_import_statement] = sym_import_statement,
  [sym_model_identifier] = sym_model_identifier,
  [sym_model_content] = sym_model_content,
  [sym_comment_block] = sym_comment_block,
  [sym_package_block] = sym_package_block,
  [sym_package_content] = sym_package_content,
  [sym_struct_block] = sym_struct_block,
  [sym_extends_block] = sym_extends_block,
  [sym_implements_block] = sym_implements_block,
  [sym_struct_content] = sym_struct_content,
  [sym_arg_block] = sym_arg_block,
  [sym_ref_block] = sym_ref_block,
  [sym_func_block] = sym_func_block,
  [sym_param_definition] = sym_param_definition,
  [sym_enum_block] = sym_enum_block,
  [sym_enum_content] = sym_enum_content,
  [sym_enum_constant] = sym_enum_constant,
  [sym_enum_index] = sym_enum_index,
  [sym_entity_block] = sym_entity_block,
  [sym_identifier_statement] = sym_identifier_statement,
  [sym_interface_block] = sym_interface_block,
  [sym_interface_content] = sym_interface_content,
  [sym__semicolon] = sym__semicolon,
  [sym__comma] = sym__comma,
  [sym__left_brace] = sym__left_brace,
  [sym__right_brace] = sym__right_brace,
  [sym__left_paren] = sym__left_paren,
  [sym__right_paren] = sym__right_paren,
  [sym_reftype] = sym_reftype,
  [sym_package_string] = sym_package_string,
  [sym_primitive_type] = sym_primitive_type,
  [sym_primitive_value] = sym_primitive_value,
  [sym_version_number] = sym_version_number,
  [sym_integerValue] = sym_integerValue,
  [sym_longValue] = sym_longValue,
  [sym_booleanValue] = sym_booleanValue,
  [sym_byteValue] = sym_byteValue,
  [sym_doubleValue] = sym_doubleValue,
  [sym_stringValue] = sym_stringValue,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_dateTimeValue] = sym_dateTimeValue,
  [sym_timeValue] = sym_timeValue,
  [sym_dateValue] = sym_dateValue,
  [aux_sym_import_block_repeat1] = aux_sym_import_block_repeat1,
  [aux_sym_model_content_repeat1] = aux_sym_model_content_repeat1,
  [aux_sym_comment_block_repeat1] = aux_sym_comment_block_repeat1,
  [aux_sym_struct_block_repeat1] = aux_sym_struct_block_repeat1,
  [aux_sym_implements_block_repeat1] = aux_sym_implements_block_repeat1,
  [aux_sym_func_block_repeat1] = aux_sym_func_block_repeat1,
  [aux_sym_enum_block_repeat1] = aux_sym_enum_block_repeat1,
  [aux_sym_enum_constant_repeat1] = aux_sym_enum_constant_repeat1,
  [aux_sym_identifier_statement_repeat1] = aux_sym_identifier_statement_repeat1,
  [aux_sym_interface_block_repeat1] = aux_sym_interface_block_repeat1,
  [aux_sym_reftype_repeat1] = aux_sym_reftype_repeat1,
  [aux_sym_package_string_repeat1] = aux_sym_package_string_repeat1,
  [aux_sym_stringValue_repeat1] = aux_sym_stringValue_repeat1,
  [aux_sym_stringValue_repeat2] = aux_sym_stringValue_repeat2,
  [anon_alias_sym_content] = anon_alias_sym_content,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_dmf] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_model] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_version] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_from] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_package] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_struct] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_extends] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_implements] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_arg] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ref] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_func] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_entity] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_identifier] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_interface] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_dot] = {
    .visible = true,
    .named = true,
  },
  [sym_byte_content] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym__new_line] = {
    .visible = false,
    .named = true,
  },
  [sym_expand] = {
    .visible = true,
    .named = true,
  },
  [sym_byte] = {
    .visible = true,
    .named = true,
  },
  [sym_int] = {
    .visible = true,
    .named = true,
  },
  [sym_long] = {
    .visible = true,
    .named = true,
  },
  [sym_double] = {
    .visible = true,
    .named = true,
  },
  [sym_datetime] = {
    .visible = true,
    .named = true,
  },
  [sym_date] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_void] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_L] = {
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
  [anon_sym_0x] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_string_content_single_quote] = {
    .visible = true,
    .named = true,
  },
  [sym_string_content_double_quote] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_escape_sequence_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_escape_sequence_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_escape_sequence_token3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_escape_sequence_token4] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_T] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_timeValue_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_timeValue_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_D] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_dateValue_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_dateValue_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dateValue_token3] = {
    .visible = false,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_dmf_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_model_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_import_block] = {
    .visible = true,
    .named = true,
  },
  [sym_import_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_model_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_model_content] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_block] = {
    .visible = true,
    .named = true,
  },
  [sym_package_block] = {
    .visible = true,
    .named = true,
  },
  [sym_package_content] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_block] = {
    .visible = true,
    .named = true,
  },
  [sym_extends_block] = {
    .visible = true,
    .named = true,
  },
  [sym_implements_block] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_content] = {
    .visible = true,
    .named = true,
  },
  [sym_arg_block] = {
    .visible = true,
    .named = true,
  },
  [sym_ref_block] = {
    .visible = true,
    .named = true,
  },
  [sym_func_block] = {
    .visible = true,
    .named = true,
  },
  [sym_param_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_block] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_content] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_constant] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_index] = {
    .visible = true,
    .named = true,
  },
  [sym_entity_block] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_interface_block] = {
    .visible = true,
    .named = true,
  },
  [sym_interface_content] = {
    .visible = true,
    .named = true,
  },
  [sym__semicolon] = {
    .visible = false,
    .named = true,
  },
  [sym__comma] = {
    .visible = false,
    .named = true,
  },
  [sym__left_brace] = {
    .visible = false,
    .named = true,
  },
  [sym__right_brace] = {
    .visible = false,
    .named = true,
  },
  [sym__left_paren] = {
    .visible = false,
    .named = true,
  },
  [sym__right_paren] = {
    .visible = false,
    .named = true,
  },
  [sym_reftype] = {
    .visible = true,
    .named = true,
  },
  [sym_package_string] = {
    .visible = true,
    .named = true,
  },
  [sym_primitive_type] = {
    .visible = true,
    .named = true,
  },
  [sym_primitive_value] = {
    .visible = true,
    .named = true,
  },
  [sym_version_number] = {
    .visible = true,
    .named = true,
  },
  [sym_integerValue] = {
    .visible = true,
    .named = true,
  },
  [sym_longValue] = {
    .visible = true,
    .named = true,
  },
  [sym_booleanValue] = {
    .visible = true,
    .named = true,
  },
  [sym_byteValue] = {
    .visible = true,
    .named = true,
  },
  [sym_doubleValue] = {
    .visible = true,
    .named = true,
  },
  [sym_stringValue] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_dateTimeValue] = {
    .visible = true,
    .named = true,
  },
  [sym_timeValue] = {
    .visible = true,
    .named = true,
  },
  [sym_dateValue] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_import_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_model_content_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_comment_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_struct_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_implements_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_func_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_constant_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_identifier_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_interface_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_reftype_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_package_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_stringValue_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_stringValue_repeat2] = {
    .visible = false,
    .named = false,
  },
  [anon_alias_sym_content] = {
    .visible = true,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [1] = anon_alias_sym_content,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  aux_sym_stringValue_repeat1, 2,
    aux_sym_stringValue_repeat1,
    anon_alias_sym_content,
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
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 75,
  [92] = 78,
  [93] = 79,
  [94] = 80,
  [95] = 74,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 98,
  [113] = 113,
  [114] = 114,
  [115] = 26,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 29,
  [131] = 123,
  [132] = 69,
  [133] = 70,
  [134] = 64,
  [135] = 62,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 179,
  [180] = 117,
  [181] = 181,
  [182] = 124,
  [183] = 127,
  [184] = 81,
  [185] = 152,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 194,
  [195] = 195,
  [196] = 196,
  [197] = 197,
  [198] = 198,
  [199] = 199,
  [200] = 200,
  [201] = 201,
  [202] = 202,
  [203] = 203,
  [204] = 204,
  [205] = 205,
  [206] = 206,
  [207] = 207,
  [208] = 208,
  [209] = 209,
  [210] = 210,
  [211] = 211,
  [212] = 212,
  [213] = 213,
  [214] = 214,
  [215] = 215,
  [216] = 216,
  [217] = 217,
  [218] = 218,
  [219] = 219,
  [220] = 220,
  [221] = 221,
  [222] = 222,
  [223] = 203,
  [224] = 224,
  [225] = 225,
  [226] = 226,
  [227] = 227,
  [228] = 228,
  [229] = 229,
  [230] = 230,
  [231] = 231,
  [232] = 232,
  [233] = 233,
  [234] = 136,
  [235] = 235,
  [236] = 137,
  [237] = 237,
  [238] = 238,
  [239] = 218,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 193,
  [244] = 216,
  [245] = 230,
  [246] = 242,
  [247] = 247,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(149);
      ADVANCE_MAP(
        '"', 239,
        '\'', 240,
        '(', 213,
        ')', 214,
        ',', 210,
        '-', 258,
        '.', 207,
        '/', 9,
        ':', 254,
        ';', 209,
        'D', 256,
        'L', 235,
        'T', 252,
        '\\', 245,
        '_', 164,
        'a', 96,
        'd', 12,
        'e', 75,
        'i', 25,
        'l', 87,
        'm', 88,
        'p', 11,
        's', 113,
        'u', 146,
        'v', 42,
        'x', 143,
        '{', 211,
        '}', 212,
        '8', 171,
        '9', 171,
        'b', 246,
        'f', 246,
        'n', 246,
        'r', 246,
        't', 246,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(147);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(170);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(206);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(215);
      if (lookahead == '(') ADVANCE(213);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(239);
      if (lookahead == '\\') ADVANCE(245);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(243);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(240);
      if (lookahead == '\\') ADVANCE(245);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(241);
      if (lookahead != 0) ADVANCE(242);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        ')', 214,
        '.', 207,
        '2', 129,
        'b', 196,
        'd', 172,
        'i', 193,
        'l', 195,
        's', 200,
        '0', 132,
        '1', 132,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 6:
      if (lookahead == '.') ADVANCE(207);
      if (lookahead == '/') ADVANCE(9);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(207);
      if (lookahead == 'b') ADVANCE(196);
      if (lookahead == 'd') ADVANCE(172);
      if (lookahead == 'i') ADVANCE(193);
      if (lookahead == 'l') ADVANCE(195);
      if (lookahead == 's') ADVANCE(200);
      if (lookahead == 'v') ADVANCE(197);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '5')) ADVANCE(133);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 8:
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '0') ADVANCE(130);
      if (lookahead == '1') ADVANCE(128);
      if (lookahead == 'a') ADVANCE(199);
      if (lookahead == '}') ADVANCE(212);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 9:
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 10:
      if (lookahead == '0') ADVANCE(131);
      if (lookahead == '3') ADVANCE(127);
      if (lookahead == '1' ||
          lookahead == '2') ADVANCE(135);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(21);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(114);
      if (lookahead == 'm') ADVANCE(49);
      if (lookahead == 'o') ADVANCE(123);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(114);
      if (lookahead == 'o') ADVANCE(123);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(56);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(81);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(68);
      if (lookahead == 'r') ADVANCE(91);
      if (lookahead == 'u') ADVANCE(82);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(24);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(78);
      END_STATE();
    case 19:
      if (lookahead == 'b') ADVANCE(69);
      END_STATE();
    case 20:
      if (lookahead == 'b') ADVANCE(89);
      if (lookahead == 'd') ADVANCE(13);
      if (lookahead == 'i') ADVANCE(80);
      if (lookahead == 'l') ADVANCE(87);
      if (lookahead == 's') ADVANCE(119);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(140);
      END_STATE();
    case 21:
      if (lookahead == 'c') ADVANCE(65);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(162);
      END_STATE();
    case 23:
      if (lookahead == 'c') ADVANCE(112);
      END_STATE();
    case 24:
      if (lookahead == 'c') ADVANCE(37);
      END_STATE();
    case 25:
      if (lookahead == 'd') ADVANCE(39);
      if (lookahead == 'm') ADVANCE(93);
      if (lookahead == 'n') ADVANCE(109);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(39);
      if (lookahead == 'm') ADVANCE(93);
      if (lookahead == 'n') ADVANCE(120);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(233);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(216);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(105);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(41);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(228);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(223);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(155);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(225);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(236);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(167);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(217);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(85);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(74);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(98);
      if (lookahead == 'o') ADVANCE(58);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(50);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(99);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(102);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(18);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(86);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(84);
      END_STATE();
    case 49:
      if (lookahead == 'f') ADVANCE(150);
      END_STATE();
    case 50:
      if (lookahead == 'f') ADVANCE(161);
      END_STATE();
    case 51:
      if (lookahead == 'f') ADVANCE(61);
      END_STATE();
    case 52:
      if (lookahead == 'f') ADVANCE(17);
      END_STATE();
    case 53:
      if (lookahead == 'g') ADVANCE(159);
      END_STATE();
    case 54:
      if (lookahead == 'g') ADVANCE(221);
      END_STATE();
    case 55:
      if (lookahead == 'g') ADVANCE(229);
      END_STATE();
    case 56:
      if (lookahead == 'g') ADVANCE(33);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(51);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(73);
      END_STATE();
    case 60:
      if (lookahead == 'i') ADVANCE(110);
      END_STATE();
    case 61:
      if (lookahead == 'i') ADVANCE(44);
      END_STATE();
    case 62:
      if (lookahead == 'i') ADVANCE(90);
      END_STATE();
    case 63:
      if (lookahead == 'i') ADVANCE(83);
      END_STATE();
    case 64:
      if (lookahead == 'i') ADVANCE(83);
      if (lookahead == 'u') ADVANCE(23);
      END_STATE();
    case 65:
      if (lookahead == 'k') ADVANCE(14);
      END_STATE();
    case 66:
      if (lookahead == 'l') ADVANCE(151);
      END_STATE();
    case 67:
      if (lookahead == 'l') ADVANCE(40);
      if (lookahead == 'o') ADVANCE(103);
      END_STATE();
    case 68:
      if (lookahead == 'l') ADVANCE(108);
      END_STATE();
    case 69:
      if (lookahead == 'l') ADVANCE(32);
      END_STATE();
    case 70:
      if (lookahead == 'l') ADVANCE(46);
      END_STATE();
    case 71:
      if (lookahead == 'm') ADVANCE(163);
      END_STATE();
    case 72:
      if (lookahead == 'm') ADVANCE(154);
      END_STATE();
    case 73:
      if (lookahead == 'm') ADVANCE(34);
      END_STATE();
    case 74:
      if (lookahead == 'm') ADVANCE(47);
      END_STATE();
    case 75:
      if (lookahead == 'n') ADVANCE(115);
      if (lookahead == 'x') ADVANCE(95);
      END_STATE();
    case 76:
      if (lookahead == 'n') ADVANCE(115);
      if (lookahead == 'x') ADVANCE(94);
      END_STATE();
    case 77:
      if (lookahead == 'n') ADVANCE(152);
      END_STATE();
    case 78:
      if (lookahead == 'n') ADVANCE(231);
      END_STATE();
    case 79:
      if (lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 80:
      if (lookahead == 'n') ADVANCE(109);
      END_STATE();
    case 81:
      if (lookahead == 'n') ADVANCE(28);
      END_STATE();
    case 82:
      if (lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 83:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 84:
      if (lookahead == 'n') ADVANCE(29);
      END_STATE();
    case 85:
      if (lookahead == 'n') ADVANCE(117);
      END_STATE();
    case 86:
      if (lookahead == 'n') ADVANCE(116);
      END_STATE();
    case 87:
      if (lookahead == 'o') ADVANCE(79);
      END_STATE();
    case 88:
      if (lookahead == 'o') ADVANCE(30);
      END_STATE();
    case 89:
      if (lookahead == 'o') ADVANCE(92);
      if (lookahead == 'y') ADVANCE(121);
      END_STATE();
    case 90:
      if (lookahead == 'o') ADVANCE(77);
      END_STATE();
    case 91:
      if (lookahead == 'o') ADVANCE(72);
      END_STATE();
    case 92:
      if (lookahead == 'o') ADVANCE(70);
      END_STATE();
    case 93:
      if (lookahead == 'p') ADVANCE(67);
      END_STATE();
    case 94:
      if (lookahead == 'p') ADVANCE(15);
      END_STATE();
    case 95:
      if (lookahead == 'p') ADVANCE(15);
      if (lookahead == 't') ADVANCE(48);
      END_STATE();
    case 96:
      if (lookahead == 'r') ADVANCE(53);
      END_STATE();
    case 97:
      if (lookahead == 'r') ADVANCE(64);
      END_STATE();
    case 98:
      if (lookahead == 'r') ADVANCE(107);
      END_STATE();
    case 99:
      if (lookahead == 'r') ADVANCE(166);
      END_STATE();
    case 100:
      if (lookahead == 'r') ADVANCE(125);
      END_STATE();
    case 101:
      if (lookahead == 'r') ADVANCE(124);
      END_STATE();
    case 102:
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 103:
      if (lookahead == 'r') ADVANCE(111);
      END_STATE();
    case 104:
      if (lookahead == 'r') ADVANCE(63);
      END_STATE();
    case 105:
      if (lookahead == 's') ADVANCE(157);
      END_STATE();
    case 106:
      if (lookahead == 's') ADVANCE(158);
      END_STATE();
    case 107:
      if (lookahead == 's') ADVANCE(62);
      END_STATE();
    case 108:
      if (lookahead == 's') ADVANCE(36);
      END_STATE();
    case 109:
      if (lookahead == 't') ADVANCE(219);
      END_STATE();
    case 110:
      if (lookahead == 't') ADVANCE(126);
      END_STATE();
    case 111:
      if (lookahead == 't') ADVANCE(153);
      END_STATE();
    case 112:
      if (lookahead == 't') ADVANCE(156);
      END_STATE();
    case 113:
      if (lookahead == 't') ADVANCE(97);
      END_STATE();
    case 114:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 115:
      if (lookahead == 't') ADVANCE(60);
      if (lookahead == 'u') ADVANCE(71);
      END_STATE();
    case 116:
      if (lookahead == 't') ADVANCE(106);
      END_STATE();
    case 117:
      if (lookahead == 't') ADVANCE(57);
      END_STATE();
    case 118:
      if (lookahead == 't') ADVANCE(101);
      END_STATE();
    case 119:
      if (lookahead == 't') ADVANCE(104);
      END_STATE();
    case 120:
      if (lookahead == 't') ADVANCE(45);
      END_STATE();
    case 121:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 122:
      if (lookahead == 'u') ADVANCE(146);
      if (lookahead == 'x') ADVANCE(143);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(122);
      if (lookahead == '"' ||
          lookahead == '\'' ||
          lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'f' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(251);
      END_STATE();
    case 123:
      if (lookahead == 'u') ADVANCE(19);
      END_STATE();
    case 124:
      if (lookahead == 'u') ADVANCE(23);
      END_STATE();
    case 125:
      if (lookahead == 'u') ADVANCE(35);
      END_STATE();
    case 126:
      if (lookahead == 'y') ADVANCE(165);
      END_STATE();
    case 127:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(260);
      END_STATE();
    case 128:
      if (('0' <= lookahead && lookahead <= '2')) ADVANCE(259);
      END_STATE();
    case 129:
      if (('0' <= lookahead && lookahead <= '3')) ADVANCE(253);
      END_STATE();
    case 130:
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(259);
      END_STATE();
    case 131:
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(260);
      END_STATE();
    case 132:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(253);
      END_STATE();
    case 133:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(255);
      END_STATE();
    case 134:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(257);
      END_STATE();
    case 135:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(260);
      END_STATE();
    case 136:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 137:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 138:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(208);
      END_STATE();
    case 139:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(138);
      END_STATE();
    case 140:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(139);
      END_STATE();
    case 141:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(248);
      END_STATE();
    case 142:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(247);
      END_STATE();
    case 143:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(141);
      END_STATE();
    case 144:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(142);
      END_STATE();
    case 145:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(144);
      END_STATE();
    case 146:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(145);
      END_STATE();
    case 147:
      if (eof) ADVANCE(149);
      ADVANCE_MAP(
        '"', 239,
        '\'', 240,
        '(', 213,
        ')', 214,
        ',', 210,
        '-', 258,
        '.', 207,
        '/', 9,
        ':', 254,
        ';', 209,
        'D', 256,
        'T', 252,
        '\\', 245,
        '_', 164,
        'a', 96,
        'd', 12,
        'e', 75,
        'i', 25,
        'l', 87,
        'm', 88,
        'p', 11,
        's', 113,
        'u', 146,
        'v', 42,
        'x', 143,
        '{', 211,
        '}', 212,
        '8', 171,
        '9', 171,
        'b', 246,
        'f', 246,
        'n', 246,
        'r', 246,
        't', 246,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(147);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(170);
      END_STATE();
    case 148:
      if (eof) ADVANCE(149);
      ADVANCE_MAP(
        '"', 239,
        '\'', 240,
        ',', 210,
        '.', 207,
        '/', 9,
        '0', 168,
        'D', 256,
        '_', 164,
        'a', 96,
        'e', 76,
        'f', 16,
        'i', 26,
        'p', 11,
        'r', 43,
        's', 118,
        't', 100,
        '{', 211,
        '}', 212,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(148);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(171);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_dmf);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_model);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_version);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_from);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_struct);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_extends);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_implements);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_arg);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_arg);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_ref);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_identifier);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_interface);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'x') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(171);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(171);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(169);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(171);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(203);
      if (lookahead == 'o') ADVANCE(204);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(191);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(234);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(218);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(227);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(173);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(224);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(226);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(222);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(230);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(160);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(189);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(175);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(192);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(179);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(180);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(181);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(232);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(182);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(202);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(190);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(194);
      if (lookahead == 'y') ADVANCE(201);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(185);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(183);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(198);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(176);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(220);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(177);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(174);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_byte_content);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym__new_line);
      if (lookahead == '\n') ADVANCE(215);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_expand);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_byte);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_byte);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_int);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_int);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_long);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_long);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_double);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_double);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_datetime);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_datetime);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == 't') ADVANCE(184);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == 't') ADVANCE(59);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_string);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_boolean);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_boolean);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_void);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_void);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_L);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_0x);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_string_content_single_quote);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(241);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(242);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_string_content_single_quote);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(242);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_string_content_double_quote);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(243);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(244);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_string_content_double_quote);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(244);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token2);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token3);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token4);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token4);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(249);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token4);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(250);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(anon_sym_T);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(aux_sym_timeValue_token1);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(aux_sym_timeValue_token2);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_D);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(aux_sym_dateValue_token1);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(aux_sym_dateValue_token2);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(aux_sym_dateValue_token3);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 148},
  [3] = {.lex_state = 148},
  [4] = {.lex_state = 148},
  [5] = {.lex_state = 148},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 148},
  [8] = {.lex_state = 148},
  [9] = {.lex_state = 7},
  [10] = {.lex_state = 148},
  [11] = {.lex_state = 5},
  [12] = {.lex_state = 148},
  [13] = {.lex_state = 148},
  [14] = {.lex_state = 148},
  [15] = {.lex_state = 148},
  [16] = {.lex_state = 148},
  [17] = {.lex_state = 148},
  [18] = {.lex_state = 148},
  [19] = {.lex_state = 148},
  [20] = {.lex_state = 148},
  [21] = {.lex_state = 148},
  [22] = {.lex_state = 148},
  [23] = {.lex_state = 148},
  [24] = {.lex_state = 148},
  [25] = {.lex_state = 148},
  [26] = {.lex_state = 148},
  [27] = {.lex_state = 8},
  [28] = {.lex_state = 8},
  [29] = {.lex_state = 148},
  [30] = {.lex_state = 148},
  [31] = {.lex_state = 148},
  [32] = {.lex_state = 148},
  [33] = {.lex_state = 148},
  [34] = {.lex_state = 8},
  [35] = {.lex_state = 148},
  [36] = {.lex_state = 148},
  [37] = {.lex_state = 148},
  [38] = {.lex_state = 148},
  [39] = {.lex_state = 148},
  [40] = {.lex_state = 148},
  [41] = {.lex_state = 148},
  [42] = {.lex_state = 148},
  [43] = {.lex_state = 148},
  [44] = {.lex_state = 148},
  [45] = {.lex_state = 148},
  [46] = {.lex_state = 148},
  [47] = {.lex_state = 148},
  [48] = {.lex_state = 20},
  [49] = {.lex_state = 148},
  [50] = {.lex_state = 148},
  [51] = {.lex_state = 148},
  [52] = {.lex_state = 148},
  [53] = {.lex_state = 148},
  [54] = {.lex_state = 148},
  [55] = {.lex_state = 148},
  [56] = {.lex_state = 148},
  [57] = {.lex_state = 148},
  [58] = {.lex_state = 148},
  [59] = {.lex_state = 148},
  [60] = {.lex_state = 148},
  [61] = {.lex_state = 148},
  [62] = {.lex_state = 148},
  [63] = {.lex_state = 148},
  [64] = {.lex_state = 148},
  [65] = {.lex_state = 148},
  [66] = {.lex_state = 6},
  [67] = {.lex_state = 6},
  [68] = {.lex_state = 6},
  [69] = {.lex_state = 148},
  [70] = {.lex_state = 148},
  [71] = {.lex_state = 6},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 4},
  [75] = {.lex_state = 6},
  [76] = {.lex_state = 3},
  [77] = {.lex_state = 4},
  [78] = {.lex_state = 3},
  [79] = {.lex_state = 4},
  [80] = {.lex_state = 3},
  [81] = {.lex_state = 148},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 6},
  [92] = {.lex_state = 3},
  [93] = {.lex_state = 4},
  [94] = {.lex_state = 3},
  [95] = {.lex_state = 4},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 122},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 6},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 6},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 148},
  [111] = {.lex_state = 148},
  [112] = {.lex_state = 122},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 8},
  [115] = {.lex_state = 6},
  [116] = {.lex_state = 6},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 3},
  [119] = {.lex_state = 148},
  [120] = {.lex_state = 148},
  [121] = {.lex_state = 148},
  [122] = {.lex_state = 148},
  [123] = {.lex_state = 3},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 148},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 6},
  [131] = {.lex_state = 4},
  [132] = {.lex_state = 6},
  [133] = {.lex_state = 6},
  [134] = {.lex_state = 6},
  [135] = {.lex_state = 6},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 148},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 148},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 6},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 148},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 148},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 148},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 5},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 2},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 2},
  [183] = {.lex_state = 2},
  [184] = {.lex_state = 6},
  [185] = {.lex_state = 6},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 7},
  [189] = {.lex_state = 6},
  [190] = {.lex_state = 6},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 6},
  [193] = {.lex_state = 6},
  [194] = {.lex_state = 6},
  [195] = {.lex_state = 6},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 148},
  [198] = {.lex_state = 2},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 6},
  [202] = {.lex_state = 2},
  [203] = {.lex_state = 2},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 2},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 2},
  [210] = {.lex_state = 8},
  [211] = {.lex_state = 6},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 2},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 6},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 148},
  [219] = {.lex_state = 7},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 20},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 6},
  [225] = {.lex_state = 148},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 6},
  [228] = {.lex_state = 6},
  [229] = {.lex_state = 2},
  [230] = {.lex_state = 148},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 6},
  [233] = {.lex_state = 0},
  [234] = {.lex_state = 6},
  [235] = {.lex_state = 0},
  [236] = {.lex_state = 6},
  [237] = {.lex_state = 2},
  [238] = {.lex_state = 0},
  [239] = {.lex_state = 148},
  [240] = {.lex_state = 6},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 6},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 148},
  [246] = {.lex_state = 0},
  [247] = {.lex_state = 10},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_dmf] = ACTIONS(1),
    [anon_sym_model] = ACTIONS(1),
    [anon_sym_version] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_package] = ACTIONS(1),
    [anon_sym_struct] = ACTIONS(1),
    [anon_sym_extends] = ACTIONS(1),
    [anon_sym_implements] = ACTIONS(1),
    [anon_sym_arg] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_entity] = ACTIONS(1),
    [anon_sym_identifier] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [sym_dot] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_expand] = ACTIONS(1),
    [sym_int] = ACTIONS(1),
    [sym_long] = ACTIONS(1),
    [sym_double] = ACTIONS(1),
    [sym_datetime] = ACTIONS(1),
    [sym_date] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [sym_void] = ACTIONS(1),
    [anon_sym_L] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [aux_sym_escape_sequence_token1] = ACTIONS(1),
    [aux_sym_escape_sequence_token2] = ACTIONS(1),
    [aux_sym_escape_sequence_token3] = ACTIONS(1),
    [aux_sym_escape_sequence_token4] = ACTIONS(1),
    [anon_sym_T] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_D] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(199),
    [sym_dmf_declaration] = STATE(229),
    [anon_sym_dmf] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 15,
    ACTIONS(5), 1,
      anon_sym_import,
    ACTIONS(7), 1,
      anon_sym_package,
    ACTIONS(9), 1,
      anon_sym_struct,
    ACTIONS(11), 1,
      anon_sym_enum,
    ACTIONS(13), 1,
      anon_sym_entity,
    ACTIONS(15), 1,
      anon_sym_interface,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(19), 1,
      sym_expand,
    STATE(7), 1,
      sym_import_block,
    STATE(25), 1,
      sym_comment_block,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(220), 1,
      sym_model_content,
    STATE(8), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(32), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    STATE(38), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [52] = 12,
    ACTIONS(23), 1,
      anon_sym_package,
    ACTIONS(26), 1,
      anon_sym_struct,
    ACTIONS(29), 1,
      anon_sym_enum,
    ACTIONS(32), 1,
      anon_sym_entity,
    ACTIONS(35), 1,
      anon_sym_interface,
    ACTIONS(38), 1,
      sym_comment,
    ACTIONS(41), 1,
      sym_expand,
    STATE(25), 1,
      sym_comment_block,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(38), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [95] = 13,
    ACTIONS(7), 1,
      anon_sym_package,
    ACTIONS(9), 1,
      anon_sym_struct,
    ACTIONS(11), 1,
      anon_sym_enum,
    ACTIONS(13), 1,
      anon_sym_entity,
    ACTIONS(15), 1,
      anon_sym_interface,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(19), 1,
      sym_expand,
    ACTIONS(44), 1,
      anon_sym_RBRACE,
    STATE(25), 1,
      sym_comment_block,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(45), 1,
      sym__right_brace,
    STATE(5), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(38), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [140] = 13,
    ACTIONS(7), 1,
      anon_sym_package,
    ACTIONS(9), 1,
      anon_sym_struct,
    ACTIONS(11), 1,
      anon_sym_enum,
    ACTIONS(13), 1,
      anon_sym_entity,
    ACTIONS(15), 1,
      anon_sym_interface,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(19), 1,
      sym_expand,
    ACTIONS(46), 1,
      anon_sym_RBRACE,
    STATE(25), 1,
      sym_comment_block,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(44), 1,
      sym__right_brace,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(38), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [185] = 10,
    ACTIONS(48), 1,
      sym_identifier,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(52), 1,
      anon_sym_RPAREN,
    STATE(88), 1,
      sym_param_definition,
    STATE(91), 1,
      aux_sym_reftype_repeat1,
    STATE(133), 1,
      aux_sym_package_string_repeat1,
    STATE(207), 1,
      sym__right_paren,
    STATE(234), 1,
      sym_package_string,
    STATE(211), 2,
      sym_reftype,
      sym_primitive_type,
    ACTIONS(54), 8,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_date,
      sym_string,
      sym_boolean,
  [224] = 12,
    ACTIONS(7), 1,
      anon_sym_package,
    ACTIONS(9), 1,
      anon_sym_struct,
    ACTIONS(11), 1,
      anon_sym_enum,
    ACTIONS(13), 1,
      anon_sym_entity,
    ACTIONS(15), 1,
      anon_sym_interface,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(19), 1,
      sym_expand,
    STATE(25), 1,
      sym_comment_block,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(233), 1,
      sym_model_content,
    STATE(8), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(38), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [266] = 12,
    ACTIONS(7), 1,
      anon_sym_package,
    ACTIONS(9), 1,
      anon_sym_struct,
    ACTIONS(11), 1,
      anon_sym_enum,
    ACTIONS(13), 1,
      anon_sym_entity,
    ACTIONS(15), 1,
      anon_sym_interface,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(19), 1,
      sym_expand,
    ACTIONS(56), 1,
      ts_builtin_sym_end,
    STATE(25), 1,
      sym_comment_block,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(38), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [308] = 8,
    ACTIONS(48), 1,
      sym_identifier,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(58), 1,
      sym_void,
    STATE(91), 1,
      aux_sym_reftype_repeat1,
    STATE(133), 1,
      aux_sym_package_string_repeat1,
    STATE(234), 1,
      sym_package_string,
    STATE(215), 2,
      sym_reftype,
      sym_primitive_type,
    ACTIONS(54), 8,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_date,
      sym_string,
      sym_boolean,
  [341] = 10,
    ACTIONS(60), 1,
      sym_number,
    ACTIONS(64), 1,
      anon_sym_0x,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    ACTIONS(70), 1,
      anon_sym_D,
    STATE(103), 1,
      sym_integerValue,
    STATE(128), 1,
      sym_dateValue,
    STATE(163), 1,
      sym_primitive_value,
    ACTIONS(62), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(165), 6,
      sym_longValue,
      sym_booleanValue,
      sym_byteValue,
      sym_doubleValue,
      sym_stringValue,
      sym_dateTimeValue,
  [378] = 8,
    ACTIONS(48), 1,
      sym_identifier,
    ACTIONS(50), 1,
      sym_dot,
    STATE(91), 1,
      aux_sym_reftype_repeat1,
    STATE(133), 1,
      aux_sym_package_string_repeat1,
    STATE(176), 1,
      sym_param_definition,
    STATE(234), 1,
      sym_package_string,
    STATE(211), 2,
      sym_reftype,
      sym_primitive_type,
    ACTIONS(54), 8,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_date,
      sym_string,
      sym_boolean,
  [411] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(78), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(52), 1,
      sym__right_brace,
    STATE(63), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [445] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(80), 1,
      anon_sym_identifier,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(63), 1,
      sym_comment_block,
    STATE(158), 1,
      sym_identifier_statement,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [479] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(80), 1,
      anon_sym_identifier,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(63), 1,
      sym_comment_block,
    STATE(160), 1,
      sym_identifier_statement,
    STATE(18), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [513] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(82), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(53), 1,
      sym__right_brace,
    STATE(63), 1,
      sym_comment_block,
    STATE(17), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [547] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(84), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(46), 1,
      sym__right_brace,
    STATE(63), 1,
      sym_comment_block,
    STATE(22), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [581] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(84), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(46), 1,
      sym__right_brace,
    STATE(63), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [615] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(80), 1,
      anon_sym_identifier,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(63), 1,
      sym_comment_block,
    STATE(181), 1,
      sym_identifier_statement,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [649] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(80), 1,
      anon_sym_identifier,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(63), 1,
      sym_comment_block,
    STATE(181), 1,
      sym_identifier_statement,
    STATE(24), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [683] = 9,
    ACTIONS(86), 1,
      anon_sym_arg,
    ACTIONS(89), 1,
      anon_sym_ref,
    ACTIONS(92), 1,
      anon_sym_func,
    ACTIONS(97), 1,
      sym_comment,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(63), 1,
      sym_comment_block,
    ACTIONS(95), 2,
      anon_sym_identifier,
      anon_sym_RBRACE,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [715] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(100), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(35), 1,
      sym__right_brace,
    STATE(63), 1,
      sym_comment_block,
    STATE(12), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [749] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(100), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(35), 1,
      sym__right_brace,
    STATE(63), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [783] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(80), 1,
      anon_sym_identifier,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(63), 1,
      sym_comment_block,
    STATE(149), 1,
      sym_identifier_statement,
    STATE(13), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [817] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(80), 1,
      anon_sym_identifier,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(63), 1,
      sym_comment_block,
    STATE(149), 1,
      sym_identifier_statement,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(142), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [851] = 7,
    ACTIONS(7), 1,
      anon_sym_package,
    ACTIONS(9), 1,
      anon_sym_struct,
    ACTIONS(11), 1,
      anon_sym_enum,
    ACTIONS(13), 1,
      anon_sym_entity,
    ACTIONS(15), 1,
      anon_sym_interface,
    ACTIONS(102), 1,
      sym_expand,
    STATE(54), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [877] = 3,
    ACTIONS(106), 1,
      sym_comment,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(104), 9,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_expand,
  [895] = 9,
    ACTIONS(109), 1,
      anon_sym_arg,
    ACTIONS(111), 1,
      sym_identifier,
    ACTIONS(113), 1,
      sym_comment,
    ACTIONS(115), 1,
      anon_sym_RBRACE,
    STATE(37), 1,
      sym__right_brace,
    STATE(130), 1,
      aux_sym_comment_block_repeat1,
    STATE(189), 1,
      sym_comment_block,
    STATE(28), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(148), 2,
      sym_arg_block,
      sym_enum_constant,
  [925] = 9,
    ACTIONS(109), 1,
      anon_sym_arg,
    ACTIONS(111), 1,
      sym_identifier,
    ACTIONS(113), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_RBRACE,
    STATE(47), 1,
      sym__right_brace,
    STATE(130), 1,
      aux_sym_comment_block_repeat1,
    STATE(189), 1,
      sym_comment_block,
    STATE(34), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(148), 2,
      sym_arg_block,
      sym_enum_constant,
  [955] = 3,
    ACTIONS(121), 1,
      sym_comment,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(119), 9,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_expand,
  [973] = 3,
    ACTIONS(123), 1,
      anon_sym_import,
    STATE(30), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    ACTIONS(126), 7,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [990] = 6,
    ACTIONS(7), 1,
      anon_sym_package,
    ACTIONS(9), 1,
      anon_sym_struct,
    ACTIONS(11), 1,
      anon_sym_enum,
    ACTIONS(13), 1,
      anon_sym_entity,
    ACTIONS(15), 1,
      anon_sym_interface,
    STATE(40), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [1013] = 3,
    ACTIONS(5), 1,
      anon_sym_import,
    STATE(30), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    ACTIONS(128), 7,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1030] = 6,
    ACTIONS(7), 1,
      anon_sym_package,
    ACTIONS(9), 1,
      anon_sym_struct,
    ACTIONS(11), 1,
      anon_sym_enum,
    ACTIONS(13), 1,
      anon_sym_entity,
    ACTIONS(15), 1,
      anon_sym_interface,
    STATE(54), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [1053] = 8,
    ACTIONS(130), 1,
      anon_sym_arg,
    ACTIONS(133), 1,
      sym_identifier,
    ACTIONS(136), 1,
      sym_comment,
    ACTIONS(139), 1,
      anon_sym_RBRACE,
    STATE(130), 1,
      aux_sym_comment_block_repeat1,
    STATE(189), 1,
      sym_comment_block,
    STATE(34), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(148), 2,
      sym_arg_block,
      sym_enum_constant,
  [1080] = 1,
    ACTIONS(141), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1092] = 1,
    ACTIONS(143), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1104] = 1,
    ACTIONS(145), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1116] = 1,
    ACTIONS(147), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1128] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(149), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(42), 1,
      sym__right_brace,
    STATE(164), 1,
      sym_comment_block,
    STATE(166), 1,
      sym_func_block,
    STATE(43), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1154] = 1,
    ACTIONS(151), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1166] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(50), 1,
      sym__right_brace,
    STATE(164), 1,
      sym_comment_block,
    STATE(166), 1,
      sym_func_block,
    STATE(51), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1192] = 1,
    ACTIONS(155), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1204] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(50), 1,
      sym__right_brace,
    STATE(164), 1,
      sym_comment_block,
    STATE(166), 1,
      sym_func_block,
    STATE(60), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1230] = 1,
    ACTIONS(157), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1242] = 1,
    ACTIONS(159), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1254] = 1,
    ACTIONS(161), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1266] = 1,
    ACTIONS(163), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1278] = 3,
    ACTIONS(54), 1,
      sym_date,
    STATE(232), 1,
      sym_primitive_type,
    ACTIONS(165), 7,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_string,
      sym_boolean,
  [1294] = 1,
    ACTIONS(167), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1306] = 1,
    ACTIONS(169), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1318] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(171), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(55), 1,
      sym__right_brace,
    STATE(164), 1,
      sym_comment_block,
    STATE(166), 1,
      sym_func_block,
    STATE(60), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1344] = 1,
    ACTIONS(173), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1356] = 1,
    ACTIONS(175), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1368] = 1,
    ACTIONS(177), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1380] = 1,
    ACTIONS(179), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1392] = 1,
    ACTIONS(181), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1404] = 1,
    ACTIONS(183), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1416] = 1,
    ACTIONS(185), 8,
      anon_sym_import,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1427] = 1,
    ACTIONS(187), 8,
      anon_sym_import,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1438] = 7,
    ACTIONS(189), 1,
      anon_sym_func,
    ACTIONS(192), 1,
      sym_comment,
    ACTIONS(195), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    STATE(164), 1,
      sym_comment_block,
    STATE(166), 1,
      sym_func_block,
    STATE(60), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1461] = 1,
    ACTIONS(197), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1470] = 3,
    ACTIONS(201), 1,
      sym_dot,
    STATE(62), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(199), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1483] = 4,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    STATE(140), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [1498] = 3,
    ACTIONS(206), 1,
      sym_dot,
    STATE(62), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(204), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1511] = 1,
    ACTIONS(208), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1520] = 6,
    ACTIONS(210), 1,
      sym_identifier,
    ACTIONS(212), 1,
      sym_dot,
    STATE(70), 1,
      aux_sym_package_string_repeat1,
    STATE(75), 1,
      aux_sym_reftype_repeat1,
    STATE(100), 1,
      sym_reftype,
    STATE(136), 1,
      sym_package_string,
  [1539] = 6,
    ACTIONS(210), 1,
      sym_identifier,
    ACTIONS(212), 1,
      sym_dot,
    STATE(70), 1,
      aux_sym_package_string_repeat1,
    STATE(75), 1,
      aux_sym_reftype_repeat1,
    STATE(136), 1,
      sym_package_string,
    STATE(141), 1,
      sym_reftype,
  [1558] = 6,
    ACTIONS(210), 1,
      sym_identifier,
    ACTIONS(212), 1,
      sym_dot,
    STATE(70), 1,
      aux_sym_package_string_repeat1,
    STATE(75), 1,
      aux_sym_reftype_repeat1,
    STATE(136), 1,
      sym_package_string,
    STATE(162), 1,
      sym_reftype,
  [1577] = 3,
    ACTIONS(206), 1,
      sym_dot,
    STATE(64), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(214), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1590] = 3,
    ACTIONS(206), 1,
      sym_dot,
    STATE(62), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(214), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1603] = 6,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(216), 1,
      sym_identifier,
    STATE(91), 1,
      aux_sym_reftype_repeat1,
    STATE(133), 1,
      aux_sym_package_string_repeat1,
    STATE(234), 1,
      sym_package_string,
    STATE(240), 1,
      sym_reftype,
  [1622] = 6,
    ACTIONS(218), 1,
      anon_sym_extends,
    ACTIONS(220), 1,
      anon_sym_implements,
    ACTIONS(222), 1,
      anon_sym_LBRACE,
    STATE(14), 1,
      sym__left_brace,
    STATE(97), 1,
      sym_extends_block,
    STATE(155), 1,
      sym_implements_block,
  [1641] = 6,
    ACTIONS(218), 1,
      anon_sym_extends,
    ACTIONS(220), 1,
      anon_sym_implements,
    ACTIONS(224), 1,
      anon_sym_LBRACE,
    STATE(15), 1,
      sym__left_brace,
    STATE(96), 1,
      sym_extends_block,
    STATE(151), 1,
      sym_implements_block,
  [1660] = 4,
    ACTIONS(226), 1,
      anon_sym_SQUOTE,
    ACTIONS(228), 1,
      sym_string_content_single_quote,
    ACTIONS(230), 1,
      anon_sym_BSLASH,
    STATE(77), 2,
      sym_escape_sequence,
      aux_sym_stringValue_repeat2,
  [1674] = 5,
    ACTIONS(210), 1,
      sym_identifier,
    ACTIONS(212), 1,
      sym_dot,
    STATE(70), 1,
      aux_sym_package_string_repeat1,
    STATE(116), 1,
      aux_sym_reftype_repeat1,
    STATE(137), 1,
      sym_package_string,
  [1690] = 5,
    ACTIONS(232), 1,
      anon_sym_DQUOTE,
    ACTIONS(234), 1,
      sym_string_content_double_quote,
    ACTIONS(237), 1,
      anon_sym_BSLASH,
    STATE(76), 1,
      aux_sym_stringValue_repeat1,
    STATE(118), 1,
      sym_escape_sequence,
  [1706] = 4,
    ACTIONS(240), 1,
      anon_sym_SQUOTE,
    ACTIONS(242), 1,
      sym_string_content_single_quote,
    ACTIONS(245), 1,
      anon_sym_BSLASH,
    STATE(77), 2,
      sym_escape_sequence,
      aux_sym_stringValue_repeat2,
  [1720] = 5,
    ACTIONS(248), 1,
      anon_sym_DQUOTE,
    ACTIONS(250), 1,
      sym_string_content_double_quote,
    ACTIONS(252), 1,
      anon_sym_BSLASH,
    STATE(80), 1,
      aux_sym_stringValue_repeat1,
    STATE(118), 1,
      sym_escape_sequence,
  [1736] = 4,
    ACTIONS(230), 1,
      anon_sym_BSLASH,
    ACTIONS(248), 1,
      anon_sym_SQUOTE,
    ACTIONS(254), 1,
      sym_string_content_single_quote,
    STATE(74), 2,
      sym_escape_sequence,
      aux_sym_stringValue_repeat2,
  [1750] = 5,
    ACTIONS(250), 1,
      sym_string_content_double_quote,
    ACTIONS(252), 1,
      anon_sym_BSLASH,
    ACTIONS(256), 1,
      anon_sym_DQUOTE,
    STATE(76), 1,
      aux_sym_stringValue_repeat1,
    STATE(118), 1,
      sym_escape_sequence,
  [1766] = 1,
    ACTIONS(199), 5,
      anon_sym_from,
      anon_sym_implements,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1774] = 2,
    ACTIONS(258), 1,
      anon_sym__,
    ACTIONS(260), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [1784] = 5,
    ACTIONS(262), 1,
      anon_sym_COMMA,
    ACTIONS(264), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(85), 1,
      aux_sym_enum_constant_repeat1,
    STATE(231), 1,
      sym__right_paren,
  [1800] = 5,
    ACTIONS(266), 1,
      anon_sym_COMMA,
    ACTIONS(268), 1,
      anon_sym_RPAREN,
    STATE(87), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(159), 1,
      sym__right_paren,
    STATE(194), 1,
      sym__comma,
  [1816] = 5,
    ACTIONS(262), 1,
      anon_sym_COMMA,
    ACTIONS(270), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(104), 1,
      aux_sym_enum_constant_repeat1,
    STATE(238), 1,
      sym__right_paren,
  [1832] = 5,
    ACTIONS(262), 1,
      anon_sym_COMMA,
    ACTIONS(270), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(89), 1,
      aux_sym_enum_constant_repeat1,
    STATE(238), 1,
      sym__right_paren,
  [1848] = 5,
    ACTIONS(266), 1,
      anon_sym_COMMA,
    ACTIONS(272), 1,
      anon_sym_RPAREN,
    STATE(106), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(169), 1,
      sym__right_paren,
    STATE(194), 1,
      sym__comma,
  [1864] = 5,
    ACTIONS(274), 1,
      anon_sym_COMMA,
    ACTIONS(276), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(90), 1,
      aux_sym_func_block_repeat1,
    STATE(196), 1,
      sym__right_paren,
  [1880] = 5,
    ACTIONS(262), 1,
      anon_sym_COMMA,
    ACTIONS(278), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(104), 1,
      aux_sym_enum_constant_repeat1,
    STATE(204), 1,
      sym__right_paren,
  [1896] = 5,
    ACTIONS(274), 1,
      anon_sym_COMMA,
    ACTIONS(280), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(108), 1,
      aux_sym_func_block_repeat1,
    STATE(208), 1,
      sym__right_paren,
  [1912] = 5,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(216), 1,
      sym_identifier,
    STATE(116), 1,
      aux_sym_reftype_repeat1,
    STATE(133), 1,
      aux_sym_package_string_repeat1,
    STATE(236), 1,
      sym_package_string,
  [1928] = 5,
    ACTIONS(250), 1,
      sym_string_content_double_quote,
    ACTIONS(252), 1,
      anon_sym_BSLASH,
    ACTIONS(282), 1,
      anon_sym_DQUOTE,
    STATE(94), 1,
      aux_sym_stringValue_repeat1,
    STATE(118), 1,
      sym_escape_sequence,
  [1944] = 4,
    ACTIONS(230), 1,
      anon_sym_BSLASH,
    ACTIONS(282), 1,
      anon_sym_SQUOTE,
    ACTIONS(284), 1,
      sym_string_content_single_quote,
    STATE(95), 2,
      sym_escape_sequence,
      aux_sym_stringValue_repeat2,
  [1958] = 5,
    ACTIONS(250), 1,
      sym_string_content_double_quote,
    ACTIONS(252), 1,
      anon_sym_BSLASH,
    ACTIONS(286), 1,
      anon_sym_DQUOTE,
    STATE(76), 1,
      aux_sym_stringValue_repeat1,
    STATE(118), 1,
      sym_escape_sequence,
  [1974] = 4,
    ACTIONS(228), 1,
      sym_string_content_single_quote,
    ACTIONS(230), 1,
      anon_sym_BSLASH,
    ACTIONS(288), 1,
      anon_sym_SQUOTE,
    STATE(77), 2,
      sym_escape_sequence,
      aux_sym_stringValue_repeat2,
  [1988] = 4,
    ACTIONS(220), 1,
      anon_sym_implements,
    ACTIONS(290), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym__left_brace,
    STATE(145), 1,
      sym_implements_block,
  [2001] = 4,
    ACTIONS(220), 1,
      anon_sym_implements,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    STATE(19), 1,
      sym__left_brace,
    STATE(154), 1,
      sym_implements_block,
  [2014] = 1,
    ACTIONS(294), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2021] = 4,
    ACTIONS(296), 1,
      anon_sym_COMMA,
    ACTIONS(298), 1,
      anon_sym_LBRACE,
    STATE(67), 1,
      sym__comma,
    STATE(101), 1,
      aux_sym_implements_block_repeat1,
  [2034] = 4,
    ACTIONS(296), 1,
      anon_sym_COMMA,
    ACTIONS(300), 1,
      anon_sym_LBRACE,
    STATE(67), 1,
      sym__comma,
    STATE(99), 1,
      aux_sym_implements_block_repeat1,
  [2047] = 4,
    ACTIONS(302), 1,
      anon_sym_COMMA,
    ACTIONS(305), 1,
      anon_sym_LBRACE,
    STATE(67), 1,
      sym__comma,
    STATE(101), 1,
      aux_sym_implements_block_repeat1,
  [2060] = 1,
    ACTIONS(307), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [2067] = 3,
    ACTIONS(309), 1,
      sym_dot,
    ACTIONS(313), 1,
      anon_sym_L,
    ACTIONS(311), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2078] = 4,
    ACTIONS(315), 1,
      anon_sym_COMMA,
    ACTIONS(318), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(104), 1,
      aux_sym_enum_constant_repeat1,
  [2091] = 4,
    ACTIONS(206), 1,
      sym_dot,
    ACTIONS(210), 1,
      sym_identifier,
    STATE(70), 1,
      aux_sym_package_string_repeat1,
    STATE(197), 1,
      sym_package_string,
  [2104] = 4,
    ACTIONS(320), 1,
      anon_sym_COMMA,
    ACTIONS(323), 1,
      anon_sym_RPAREN,
    STATE(106), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(194), 1,
      sym__comma,
  [2117] = 4,
    ACTIONS(206), 1,
      sym_dot,
    ACTIONS(210), 1,
      sym_identifier,
    STATE(70), 1,
      aux_sym_package_string_repeat1,
    STATE(139), 1,
      sym_package_string,
  [2130] = 4,
    ACTIONS(325), 1,
      anon_sym_COMMA,
    ACTIONS(328), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(108), 1,
      aux_sym_func_block_repeat1,
  [2143] = 4,
    ACTIONS(220), 1,
      anon_sym_implements,
    ACTIONS(330), 1,
      anon_sym_LBRACE,
    STATE(39), 1,
      sym__left_brace,
    STATE(167), 1,
      sym_implements_block,
  [2156] = 4,
    ACTIONS(332), 1,
      anon_sym__,
    ACTIONS(334), 1,
      sym_number,
    STATE(83), 1,
      sym_enum_index,
    STATE(146), 1,
      sym_integerValue,
  [2169] = 4,
    ACTIONS(332), 1,
      anon_sym__,
    ACTIONS(334), 1,
      sym_number,
    STATE(86), 1,
      sym_enum_index,
    STATE(146), 1,
      sym_integerValue,
  [2182] = 1,
    ACTIONS(336), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2189] = 4,
    ACTIONS(338), 1,
      anon_sym_LPAREN,
    ACTIONS(340), 1,
      sym__new_line,
    STATE(209), 1,
      sym_model_identifier,
    STATE(235), 1,
      sym__left_paren,
  [2202] = 2,
    ACTIONS(342), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(344), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2211] = 3,
    ACTIONS(104), 1,
      sym_identifier,
    ACTIONS(346), 1,
      sym_comment,
    STATE(115), 1,
      aux_sym_comment_block_repeat1,
  [2221] = 3,
    ACTIONS(349), 1,
      sym_identifier,
    ACTIONS(351), 1,
      sym_dot,
    STATE(116), 1,
      aux_sym_reftype_repeat1,
  [2231] = 1,
    ACTIONS(354), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2237] = 2,
    ACTIONS(358), 1,
      sym_string_content_double_quote,
    ACTIONS(356), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2245] = 3,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    STATE(222), 1,
      sym_stringValue,
  [2255] = 1,
    ACTIONS(360), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2261] = 3,
    ACTIONS(362), 1,
      anon_sym_DQUOTE,
    ACTIONS(364), 1,
      anon_sym_SQUOTE,
    STATE(113), 1,
      sym_stringValue,
  [2271] = 3,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    STATE(126), 1,
      sym_stringValue,
  [2281] = 2,
    ACTIONS(368), 1,
      sym_string_content_double_quote,
    ACTIONS(366), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2289] = 1,
    ACTIONS(370), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2295] = 1,
    ACTIONS(372), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2301] = 3,
    ACTIONS(374), 1,
      anon_sym_version,
    ACTIONS(376), 1,
      anon_sym_RPAREN,
    STATE(202), 1,
      sym__right_paren,
  [2311] = 1,
    ACTIONS(378), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2317] = 2,
    ACTIONS(380), 1,
      anon_sym_T,
    ACTIONS(311), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2325] = 1,
    ACTIONS(382), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_T,
  [2331] = 3,
    ACTIONS(119), 1,
      sym_identifier,
    ACTIONS(384), 1,
      sym_comment,
    STATE(115), 1,
      aux_sym_comment_block_repeat1,
  [2341] = 2,
    ACTIONS(368), 1,
      sym_string_content_single_quote,
    ACTIONS(366), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2349] = 3,
    ACTIONS(214), 1,
      sym_identifier,
    ACTIONS(386), 1,
      sym_dot,
    STATE(134), 1,
      aux_sym_package_string_repeat1,
  [2359] = 3,
    ACTIONS(214), 1,
      sym_identifier,
    ACTIONS(386), 1,
      sym_dot,
    STATE(135), 1,
      aux_sym_package_string_repeat1,
  [2369] = 3,
    ACTIONS(204), 1,
      sym_identifier,
    ACTIONS(386), 1,
      sym_dot,
    STATE(135), 1,
      aux_sym_package_string_repeat1,
  [2379] = 3,
    ACTIONS(199), 1,
      sym_identifier,
    ACTIONS(388), 1,
      sym_dot,
    STATE(135), 1,
      aux_sym_package_string_repeat1,
  [2389] = 1,
    ACTIONS(391), 3,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2395] = 1,
    ACTIONS(393), 3,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2401] = 1,
    ACTIONS(395), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2406] = 2,
    ACTIONS(397), 1,
      anon_sym_LBRACE,
    STATE(4), 1,
      sym__left_brace,
  [2413] = 2,
    ACTIONS(399), 1,
      anon_sym_SEMI,
    STATE(61), 1,
      sym__semicolon,
  [2420] = 1,
    ACTIONS(305), 2,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2425] = 2,
    ACTIONS(401), 1,
      anon_sym_SEMI,
    STATE(65), 1,
      sym__semicolon,
  [2432] = 2,
    ACTIONS(403), 1,
      sym_number,
    STATE(213), 1,
      sym_version_number,
  [2439] = 2,
    ACTIONS(405), 1,
      anon_sym_LPAREN,
    STATE(6), 1,
      sym__left_paren,
  [2446] = 2,
    ACTIONS(407), 1,
      anon_sym_LBRACE,
    STATE(21), 1,
      sym__left_brace,
  [2453] = 1,
    ACTIONS(409), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2458] = 2,
    ACTIONS(411), 1,
      anon_sym_LPAREN,
    STATE(110), 1,
      sym__left_paren,
  [2465] = 2,
    ACTIONS(413), 1,
      anon_sym_SEMI,
    STATE(114), 1,
      sym__semicolon,
  [2472] = 2,
    ACTIONS(415), 1,
      anon_sym_RBRACE,
    STATE(57), 1,
      sym__right_brace,
  [2479] = 2,
    ACTIONS(403), 1,
      sym_number,
    STATE(198), 1,
      sym_version_number,
  [2486] = 2,
    ACTIONS(290), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym__left_brace,
  [2493] = 2,
    ACTIONS(417), 1,
      sym_identifier,
    ACTIONS(420), 1,
      sym_dot,
  [2500] = 2,
    ACTIONS(422), 1,
      anon_sym_LPAREN,
    STATE(111), 1,
      sym__left_paren,
  [2507] = 2,
    ACTIONS(424), 1,
      anon_sym_LBRACE,
    STATE(23), 1,
      sym__left_brace,
  [2514] = 2,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    STATE(19), 1,
      sym__left_brace,
  [2521] = 2,
    ACTIONS(426), 1,
      anon_sym_model,
    STATE(237), 1,
      sym_model_declaration,
  [2528] = 2,
    ACTIONS(428), 1,
      anon_sym_LPAREN,
    STATE(228), 1,
      sym__left_paren,
  [2535] = 2,
    ACTIONS(430), 1,
      anon_sym_RBRACE,
    STATE(36), 1,
      sym__right_brace,
  [2542] = 2,
    ACTIONS(432), 1,
      anon_sym_SEMI,
    STATE(191), 1,
      sym__semicolon,
  [2549] = 2,
    ACTIONS(434), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      sym__right_brace,
  [2556] = 2,
    ACTIONS(436), 1,
      sym_number,
    STATE(170), 1,
      sym_version_number,
  [2563] = 1,
    ACTIONS(438), 2,
      anon_sym_implements,
      anon_sym_LBRACE,
  [2568] = 1,
    ACTIONS(318), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2573] = 2,
    ACTIONS(76), 1,
      anon_sym_func,
    STATE(186), 1,
      sym_func_block,
  [2580] = 1,
    ACTIONS(311), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2585] = 2,
    ACTIONS(440), 1,
      anon_sym_SEMI,
    STATE(120), 1,
      sym__semicolon,
  [2592] = 2,
    ACTIONS(442), 1,
      anon_sym_LBRACE,
    STATE(41), 1,
      sym__left_brace,
  [2599] = 1,
    ACTIONS(323), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2604] = 2,
    ACTIONS(444), 1,
      anon_sym_SEMI,
    STATE(205), 1,
      sym__semicolon,
  [2611] = 2,
    ACTIONS(446), 1,
      anon_sym_RPAREN,
    STATE(206), 1,
      sym__right_paren,
  [2618] = 1,
    ACTIONS(448), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2623] = 1,
    ACTIONS(450), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2628] = 2,
    ACTIONS(334), 1,
      sym_number,
    STATE(177), 1,
      sym_integerValue,
  [2635] = 1,
    ACTIONS(452), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2640] = 2,
    ACTIONS(454), 1,
      aux_sym_timeValue_token1,
    STATE(178), 1,
      sym_timeValue,
  [2647] = 1,
    ACTIONS(328), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2652] = 1,
    ACTIONS(456), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2657] = 1,
    ACTIONS(458), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2662] = 1,
    ACTIONS(460), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2667] = 2,
    ACTIONS(354), 1,
      sym__new_line,
    ACTIONS(462), 1,
      anon_sym_LPAREN,
  [2674] = 2,
    ACTIONS(464), 1,
      anon_sym_RBRACE,
    STATE(56), 1,
      sym__right_brace,
  [2681] = 2,
    ACTIONS(370), 1,
      sym__new_line,
    ACTIONS(466), 1,
      anon_sym_LPAREN,
  [2688] = 2,
    ACTIONS(378), 1,
      sym__new_line,
    ACTIONS(468), 1,
      anon_sym_LPAREN,
  [2695] = 1,
    ACTIONS(199), 2,
      sym_identifier,
      sym_dot,
  [2700] = 2,
    ACTIONS(420), 1,
      sym_dot,
    ACTIONS(470), 1,
      sym_identifier,
  [2707] = 2,
    ACTIONS(473), 1,
      anon_sym_SEMI,
    STATE(125), 1,
      sym__semicolon,
  [2714] = 2,
    ACTIONS(475), 1,
      anon_sym_LBRACE,
    STATE(27), 1,
      sym__left_brace,
  [2721] = 1,
    ACTIONS(477), 1,
      aux_sym_timeValue_token2,
  [2725] = 1,
    ACTIONS(479), 1,
      sym_identifier,
  [2729] = 1,
    ACTIONS(481), 1,
      sym_identifier,
  [2733] = 1,
    ACTIONS(483), 1,
      anon_sym_RBRACE,
  [2737] = 1,
    ACTIONS(485), 1,
      sym_identifier,
  [2741] = 1,
    ACTIONS(487), 1,
      sym_identifier,
  [2745] = 1,
    ACTIONS(489), 1,
      sym_identifier,
  [2749] = 1,
    ACTIONS(491), 1,
      sym_identifier,
  [2753] = 1,
    ACTIONS(493), 1,
      anon_sym_SEMI,
  [2757] = 1,
    ACTIONS(495), 1,
      anon_sym_from,
  [2761] = 1,
    ACTIONS(497), 1,
      sym__new_line,
  [2765] = 1,
    ACTIONS(499), 1,
      ts_builtin_sym_end,
  [2769] = 1,
    ACTIONS(501), 1,
      anon_sym_DASH,
  [2773] = 1,
    ACTIONS(503), 1,
      sym_identifier,
  [2777] = 1,
    ACTIONS(505), 1,
      sym__new_line,
  [2781] = 1,
    ACTIONS(507), 1,
      sym__new_line,
  [2785] = 1,
    ACTIONS(509), 1,
      anon_sym_SEMI,
  [2789] = 1,
    ACTIONS(511), 1,
      anon_sym_RBRACE,
  [2793] = 1,
    ACTIONS(513), 1,
      sym__new_line,
  [2797] = 1,
    ACTIONS(515), 1,
      anon_sym_SEMI,
  [2801] = 1,
    ACTIONS(517), 1,
      anon_sym_SEMI,
  [2805] = 1,
    ACTIONS(519), 1,
      sym__new_line,
  [2809] = 1,
    ACTIONS(521), 1,
      aux_sym_dateValue_token2,
  [2813] = 1,
    ACTIONS(523), 1,
      sym_identifier,
  [2817] = 1,
    ACTIONS(525), 1,
      anon_sym_COLON,
  [2821] = 1,
    ACTIONS(527), 1,
      sym__new_line,
  [2825] = 1,
    ACTIONS(529), 1,
      anon_sym_DASH,
  [2829] = 1,
    ACTIONS(531), 1,
      sym_identifier,
  [2833] = 1,
    ACTIONS(533), 1,
      sym_dot,
  [2837] = 1,
    ACTIONS(535), 1,
      anon_sym_COLON,
  [2841] = 1,
    ACTIONS(537), 1,
      sym_number,
  [2845] = 1,
    ACTIONS(539), 1,
      aux_sym_timeValue_token2,
  [2849] = 1,
    ACTIONS(541), 1,
      ts_builtin_sym_end,
  [2853] = 1,
    ACTIONS(543), 1,
      sym_byte_content,
  [2857] = 1,
    ACTIONS(545), 1,
      anon_sym_version,
  [2861] = 1,
    ACTIONS(507), 1,
      anon_sym_RPAREN,
  [2865] = 1,
    ACTIONS(547), 1,
      aux_sym_dateValue_token1,
  [2869] = 1,
    ACTIONS(549), 1,
      sym_number,
  [2873] = 1,
    ACTIONS(551), 1,
      anon_sym_SEMI,
  [2877] = 1,
    ACTIONS(553), 1,
      sym_identifier,
  [2881] = 1,
    ACTIONS(555), 1,
      sym_identifier,
  [2885] = 1,
    ACTIONS(557), 1,
      sym__new_line,
  [2889] = 1,
    ACTIONS(559), 1,
      sym_number,
  [2893] = 1,
    ACTIONS(561), 1,
      anon_sym_SEMI,
  [2897] = 1,
    ACTIONS(563), 1,
      sym_identifier,
  [2901] = 1,
    ACTIONS(565), 1,
      ts_builtin_sym_end,
  [2905] = 1,
    ACTIONS(391), 1,
      sym_identifier,
  [2909] = 1,
    ACTIONS(567), 1,
      anon_sym_model,
  [2913] = 1,
    ACTIONS(393), 1,
      sym_identifier,
  [2917] = 1,
    ACTIONS(569), 1,
      sym__new_line,
  [2921] = 1,
    ACTIONS(571), 1,
      anon_sym_SEMI,
  [2925] = 1,
    ACTIONS(573), 1,
      sym_number,
  [2929] = 1,
    ACTIONS(575), 1,
      sym_identifier,
  [2933] = 1,
    ACTIONS(577), 1,
      anon_sym_SEMI,
  [2937] = 1,
    ACTIONS(579), 1,
      sym_dot,
  [2941] = 1,
    ACTIONS(581), 1,
      sym_identifier,
  [2945] = 1,
    ACTIONS(583), 1,
      sym_dot,
  [2949] = 1,
    ACTIONS(585), 1,
      sym_number,
  [2953] = 1,
    ACTIONS(587), 1,
      sym_dot,
  [2957] = 1,
    ACTIONS(589), 1,
      aux_sym_dateValue_token3,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 52,
  [SMALL_STATE(4)] = 95,
  [SMALL_STATE(5)] = 140,
  [SMALL_STATE(6)] = 185,
  [SMALL_STATE(7)] = 224,
  [SMALL_STATE(8)] = 266,
  [SMALL_STATE(9)] = 308,
  [SMALL_STATE(10)] = 341,
  [SMALL_STATE(11)] = 378,
  [SMALL_STATE(12)] = 411,
  [SMALL_STATE(13)] = 445,
  [SMALL_STATE(14)] = 479,
  [SMALL_STATE(15)] = 513,
  [SMALL_STATE(16)] = 547,
  [SMALL_STATE(17)] = 581,
  [SMALL_STATE(18)] = 615,
  [SMALL_STATE(19)] = 649,
  [SMALL_STATE(20)] = 683,
  [SMALL_STATE(21)] = 715,
  [SMALL_STATE(22)] = 749,
  [SMALL_STATE(23)] = 783,
  [SMALL_STATE(24)] = 817,
  [SMALL_STATE(25)] = 851,
  [SMALL_STATE(26)] = 877,
  [SMALL_STATE(27)] = 895,
  [SMALL_STATE(28)] = 925,
  [SMALL_STATE(29)] = 955,
  [SMALL_STATE(30)] = 973,
  [SMALL_STATE(31)] = 990,
  [SMALL_STATE(32)] = 1013,
  [SMALL_STATE(33)] = 1030,
  [SMALL_STATE(34)] = 1053,
  [SMALL_STATE(35)] = 1080,
  [SMALL_STATE(36)] = 1092,
  [SMALL_STATE(37)] = 1104,
  [SMALL_STATE(38)] = 1116,
  [SMALL_STATE(39)] = 1128,
  [SMALL_STATE(40)] = 1154,
  [SMALL_STATE(41)] = 1166,
  [SMALL_STATE(42)] = 1192,
  [SMALL_STATE(43)] = 1204,
  [SMALL_STATE(44)] = 1230,
  [SMALL_STATE(45)] = 1242,
  [SMALL_STATE(46)] = 1254,
  [SMALL_STATE(47)] = 1266,
  [SMALL_STATE(48)] = 1278,
  [SMALL_STATE(49)] = 1294,
  [SMALL_STATE(50)] = 1306,
  [SMALL_STATE(51)] = 1318,
  [SMALL_STATE(52)] = 1344,
  [SMALL_STATE(53)] = 1356,
  [SMALL_STATE(54)] = 1368,
  [SMALL_STATE(55)] = 1380,
  [SMALL_STATE(56)] = 1392,
  [SMALL_STATE(57)] = 1404,
  [SMALL_STATE(58)] = 1416,
  [SMALL_STATE(59)] = 1427,
  [SMALL_STATE(60)] = 1438,
  [SMALL_STATE(61)] = 1461,
  [SMALL_STATE(62)] = 1470,
  [SMALL_STATE(63)] = 1483,
  [SMALL_STATE(64)] = 1498,
  [SMALL_STATE(65)] = 1511,
  [SMALL_STATE(66)] = 1520,
  [SMALL_STATE(67)] = 1539,
  [SMALL_STATE(68)] = 1558,
  [SMALL_STATE(69)] = 1577,
  [SMALL_STATE(70)] = 1590,
  [SMALL_STATE(71)] = 1603,
  [SMALL_STATE(72)] = 1622,
  [SMALL_STATE(73)] = 1641,
  [SMALL_STATE(74)] = 1660,
  [SMALL_STATE(75)] = 1674,
  [SMALL_STATE(76)] = 1690,
  [SMALL_STATE(77)] = 1706,
  [SMALL_STATE(78)] = 1720,
  [SMALL_STATE(79)] = 1736,
  [SMALL_STATE(80)] = 1750,
  [SMALL_STATE(81)] = 1766,
  [SMALL_STATE(82)] = 1774,
  [SMALL_STATE(83)] = 1784,
  [SMALL_STATE(84)] = 1800,
  [SMALL_STATE(85)] = 1816,
  [SMALL_STATE(86)] = 1832,
  [SMALL_STATE(87)] = 1848,
  [SMALL_STATE(88)] = 1864,
  [SMALL_STATE(89)] = 1880,
  [SMALL_STATE(90)] = 1896,
  [SMALL_STATE(91)] = 1912,
  [SMALL_STATE(92)] = 1928,
  [SMALL_STATE(93)] = 1944,
  [SMALL_STATE(94)] = 1958,
  [SMALL_STATE(95)] = 1974,
  [SMALL_STATE(96)] = 1988,
  [SMALL_STATE(97)] = 2001,
  [SMALL_STATE(98)] = 2014,
  [SMALL_STATE(99)] = 2021,
  [SMALL_STATE(100)] = 2034,
  [SMALL_STATE(101)] = 2047,
  [SMALL_STATE(102)] = 2060,
  [SMALL_STATE(103)] = 2067,
  [SMALL_STATE(104)] = 2078,
  [SMALL_STATE(105)] = 2091,
  [SMALL_STATE(106)] = 2104,
  [SMALL_STATE(107)] = 2117,
  [SMALL_STATE(108)] = 2130,
  [SMALL_STATE(109)] = 2143,
  [SMALL_STATE(110)] = 2156,
  [SMALL_STATE(111)] = 2169,
  [SMALL_STATE(112)] = 2182,
  [SMALL_STATE(113)] = 2189,
  [SMALL_STATE(114)] = 2202,
  [SMALL_STATE(115)] = 2211,
  [SMALL_STATE(116)] = 2221,
  [SMALL_STATE(117)] = 2231,
  [SMALL_STATE(118)] = 2237,
  [SMALL_STATE(119)] = 2245,
  [SMALL_STATE(120)] = 2255,
  [SMALL_STATE(121)] = 2261,
  [SMALL_STATE(122)] = 2271,
  [SMALL_STATE(123)] = 2281,
  [SMALL_STATE(124)] = 2289,
  [SMALL_STATE(125)] = 2295,
  [SMALL_STATE(126)] = 2301,
  [SMALL_STATE(127)] = 2311,
  [SMALL_STATE(128)] = 2317,
  [SMALL_STATE(129)] = 2325,
  [SMALL_STATE(130)] = 2331,
  [SMALL_STATE(131)] = 2341,
  [SMALL_STATE(132)] = 2349,
  [SMALL_STATE(133)] = 2359,
  [SMALL_STATE(134)] = 2369,
  [SMALL_STATE(135)] = 2379,
  [SMALL_STATE(136)] = 2389,
  [SMALL_STATE(137)] = 2395,
  [SMALL_STATE(138)] = 2401,
  [SMALL_STATE(139)] = 2406,
  [SMALL_STATE(140)] = 2413,
  [SMALL_STATE(141)] = 2420,
  [SMALL_STATE(142)] = 2425,
  [SMALL_STATE(143)] = 2432,
  [SMALL_STATE(144)] = 2439,
  [SMALL_STATE(145)] = 2446,
  [SMALL_STATE(146)] = 2453,
  [SMALL_STATE(147)] = 2458,
  [SMALL_STATE(148)] = 2465,
  [SMALL_STATE(149)] = 2472,
  [SMALL_STATE(150)] = 2479,
  [SMALL_STATE(151)] = 2486,
  [SMALL_STATE(152)] = 2493,
  [SMALL_STATE(153)] = 2500,
  [SMALL_STATE(154)] = 2507,
  [SMALL_STATE(155)] = 2514,
  [SMALL_STATE(156)] = 2521,
  [SMALL_STATE(157)] = 2528,
  [SMALL_STATE(158)] = 2535,
  [SMALL_STATE(159)] = 2542,
  [SMALL_STATE(160)] = 2549,
  [SMALL_STATE(161)] = 2556,
  [SMALL_STATE(162)] = 2563,
  [SMALL_STATE(163)] = 2568,
  [SMALL_STATE(164)] = 2573,
  [SMALL_STATE(165)] = 2580,
  [SMALL_STATE(166)] = 2585,
  [SMALL_STATE(167)] = 2592,
  [SMALL_STATE(168)] = 2599,
  [SMALL_STATE(169)] = 2604,
  [SMALL_STATE(170)] = 2611,
  [SMALL_STATE(171)] = 2618,
  [SMALL_STATE(172)] = 2623,
  [SMALL_STATE(173)] = 2628,
  [SMALL_STATE(174)] = 2635,
  [SMALL_STATE(175)] = 2640,
  [SMALL_STATE(176)] = 2647,
  [SMALL_STATE(177)] = 2652,
  [SMALL_STATE(178)] = 2657,
  [SMALL_STATE(179)] = 2662,
  [SMALL_STATE(180)] = 2667,
  [SMALL_STATE(181)] = 2674,
  [SMALL_STATE(182)] = 2681,
  [SMALL_STATE(183)] = 2688,
  [SMALL_STATE(184)] = 2695,
  [SMALL_STATE(185)] = 2700,
  [SMALL_STATE(186)] = 2707,
  [SMALL_STATE(187)] = 2714,
  [SMALL_STATE(188)] = 2721,
  [SMALL_STATE(189)] = 2725,
  [SMALL_STATE(190)] = 2729,
  [SMALL_STATE(191)] = 2733,
  [SMALL_STATE(192)] = 2737,
  [SMALL_STATE(193)] = 2741,
  [SMALL_STATE(194)] = 2745,
  [SMALL_STATE(195)] = 2749,
  [SMALL_STATE(196)] = 2753,
  [SMALL_STATE(197)] = 2757,
  [SMALL_STATE(198)] = 2761,
  [SMALL_STATE(199)] = 2765,
  [SMALL_STATE(200)] = 2769,
  [SMALL_STATE(201)] = 2773,
  [SMALL_STATE(202)] = 2777,
  [SMALL_STATE(203)] = 2781,
  [SMALL_STATE(204)] = 2785,
  [SMALL_STATE(205)] = 2789,
  [SMALL_STATE(206)] = 2793,
  [SMALL_STATE(207)] = 2797,
  [SMALL_STATE(208)] = 2801,
  [SMALL_STATE(209)] = 2805,
  [SMALL_STATE(210)] = 2809,
  [SMALL_STATE(211)] = 2813,
  [SMALL_STATE(212)] = 2817,
  [SMALL_STATE(213)] = 2821,
  [SMALL_STATE(214)] = 2825,
  [SMALL_STATE(215)] = 2829,
  [SMALL_STATE(216)] = 2833,
  [SMALL_STATE(217)] = 2837,
  [SMALL_STATE(218)] = 2841,
  [SMALL_STATE(219)] = 2845,
  [SMALL_STATE(220)] = 2849,
  [SMALL_STATE(221)] = 2853,
  [SMALL_STATE(222)] = 2857,
  [SMALL_STATE(223)] = 2861,
  [SMALL_STATE(224)] = 2865,
  [SMALL_STATE(225)] = 2869,
  [SMALL_STATE(226)] = 2873,
  [SMALL_STATE(227)] = 2877,
  [SMALL_STATE(228)] = 2881,
  [SMALL_STATE(229)] = 2885,
  [SMALL_STATE(230)] = 2889,
  [SMALL_STATE(231)] = 2893,
  [SMALL_STATE(232)] = 2897,
  [SMALL_STATE(233)] = 2901,
  [SMALL_STATE(234)] = 2905,
  [SMALL_STATE(235)] = 2909,
  [SMALL_STATE(236)] = 2913,
  [SMALL_STATE(237)] = 2917,
  [SMALL_STATE(238)] = 2921,
  [SMALL_STATE(239)] = 2925,
  [SMALL_STATE(240)] = 2929,
  [SMALL_STATE(241)] = 2933,
  [SMALL_STATE(242)] = 2937,
  [SMALL_STATE(243)] = 2941,
  [SMALL_STATE(244)] = 2945,
  [SMALL_STATE(245)] = 2949,
  [SMALL_STATE(246)] = 2953,
  [SMALL_STATE(247)] = 2957,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(192),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(201),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(190),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(195),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(227),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_content, 1, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(215),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_block, 1, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0), SHIFT_REPEAT(105),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_block, 1, 0, 0),
  [130] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [133] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(147),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 6, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 8, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 4, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 1, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 3, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 4, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 5, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 4, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 5, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 5, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 5, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 5, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 7, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 4, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 2, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 6, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 6, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 7, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 5, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 6, 0, 0),
  [189] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [192] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 3, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0),
  [201] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(193),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 2, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 2, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 1, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [226] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [230] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0),
  [234] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(118),
  [237] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(98),
  [240] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0),
  [242] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(77),
  [245] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(112),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [252] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(124),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 1, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [282] = {.entry = {.count = 1, .reusable = false}}, SHIFT(180),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [286] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [288] = {.entry = {.count = 1, .reusable = false}}, SHIFT(183),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 3, 0, 0),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 2, 0, 0),
  [302] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 3, 0, 0),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_value, 1, 0, 0),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [315] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0),
  [320] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(194),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0),
  [325] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [338] = {.entry = {.count = 1, .reusable = false}}, SHIFT(235),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [342] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_content, 2, 0, 0),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_content, 2, 0, 0),
  [346] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0),
  [351] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0), SHIFT_REPEAT(116),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 2, 0, 0),
  [356] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 2, 0, 0),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [366] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [368] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 3, 0, 1),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 3, 0, 0),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 3, 0, 0),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateValue, 6, 0, 0),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [388] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(243),
  [391] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 1, 0, 0),
  [393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 2, 0, 0),
  [395] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_booleanValue, 1, 0, 0),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_index, 1, 0, 0),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [417] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(81),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [438] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_extends_block, 2, 0, 0),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_definition, 2, 0, 0),
  [450] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byteValue, 2, 0, 0),
  [452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_longValue, 2, 0, 0),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [456] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doubleValue, 3, 0, 0),
  [458] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateTimeValue, 3, 0, 0),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeValue, 5, 0, 0),
  [462] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 2, 0, 0),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [466] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 3, 0, 1),
  [468] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 3, 0, 0),
  [470] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(184),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [483] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 5, 0, 0),
  [485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [487] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [489] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [493] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 6, 0, 0),
  [495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [497] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dmf_declaration, 2, 0, 0),
  [499] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [505] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_identifier, 4, 0, 0),
  [507] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_version_number, 5, 0, 0),
  [509] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 6, 0, 0),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 6, 0, 0),
  [513] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_identifier, 6, 0, 0),
  [515] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 5, 0, 0),
  [517] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 7, 0, 0),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [527] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_declaration, 4, 0, 0),
  [529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 5, 0, 0),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [551] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_block, 3, 0, 0),
  [553] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [561] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 4, 0, 0),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 6, 0, 0),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [571] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 5, 0, 0),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(241),
  [577] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref_block, 3, 0, 0),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
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

TS_PUBLIC const TSLanguage *tree_sitter_dmf(void) {
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
