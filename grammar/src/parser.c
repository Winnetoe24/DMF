#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 247
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
  aux_sym_stringValue_repeat2, 2,
    aux_sym_stringValue_repeat2,
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
  [90] = 75,
  [91] = 77,
  [92] = 76,
  [93] = 89,
  [94] = 80,
  [95] = 95,
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
  [112] = 96,
  [113] = 113,
  [114] = 114,
  [115] = 67,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 28,
  [125] = 121,
  [126] = 62,
  [127] = 66,
  [128] = 25,
  [129] = 129,
  [130] = 130,
  [131] = 72,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 84,
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
  [177] = 132,
  [178] = 178,
  [179] = 179,
  [180] = 130,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 178,
  [185] = 185,
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
  [223] = 207,
  [224] = 224,
  [225] = 225,
  [226] = 226,
  [227] = 227,
  [228] = 228,
  [229] = 229,
  [230] = 230,
  [231] = 231,
  [232] = 232,
  [233] = 119,
  [234] = 234,
  [235] = 135,
  [236] = 236,
  [237] = 237,
  [238] = 238,
  [239] = 238,
  [240] = 240,
  [241] = 241,
  [242] = 199,
  [243] = 232,
  [244] = 209,
  [245] = 234,
  [246] = 246,
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
        'a', 95,
        'd', 11,
        'e', 74,
        'i', 24,
        'l', 86,
        'm', 87,
        'p', 10,
        's', 112,
        'u', 146,
        'v', 41,
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
        '2', 128,
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
      ADVANCE_MAP(
        '.', 207,
        '0', 130,
        '1', 127,
        'b', 196,
        'd', 172,
        'i', 193,
        'l', 195,
        's', 200,
        'v', 197,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 8:
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '0') ADVANCE(131);
      if (lookahead == '3') ADVANCE(126);
      if (lookahead == 'a') ADVANCE(199);
      if (lookahead == '}') ADVANCE(212);
      if (lookahead == '1' ||
          lookahead == '2') ADVANCE(133);
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
      if (lookahead == 'a') ADVANCE(20);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'm') ADVANCE(48);
      if (lookahead == 'o') ADVANCE(122);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'o') ADVANCE(122);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(55);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(80);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(67);
      if (lookahead == 'r') ADVANCE(90);
      if (lookahead == 'u') ADVANCE(81);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(23);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(77);
      END_STATE();
    case 18:
      if (lookahead == 'b') ADVANCE(68);
      END_STATE();
    case 19:
      if (lookahead == 'b') ADVANCE(88);
      if (lookahead == 'd') ADVANCE(12);
      if (lookahead == 'i') ADVANCE(79);
      if (lookahead == 'l') ADVANCE(86);
      if (lookahead == 's') ADVANCE(118);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      if (('0' <= lookahead && lookahead <= '5')) ADVANCE(134);
      END_STATE();
    case 20:
      if (lookahead == 'c') ADVANCE(64);
      END_STATE();
    case 21:
      if (lookahead == 'c') ADVANCE(162);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(111);
      END_STATE();
    case 23:
      if (lookahead == 'c') ADVANCE(36);
      END_STATE();
    case 24:
      if (lookahead == 'd') ADVANCE(38);
      if (lookahead == 'm') ADVANCE(92);
      if (lookahead == 'n') ADVANCE(108);
      END_STATE();
    case 25:
      if (lookahead == 'd') ADVANCE(38);
      if (lookahead == 'm') ADVANCE(92);
      if (lookahead == 'n') ADVANCE(119);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(233);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(216);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(104);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(40);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(228);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(223);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(155);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(225);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(236);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(167);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(217);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(84);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(73);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(97);
      if (lookahead == 'o') ADVANCE(57);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(98);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(101);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(85);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(83);
      END_STATE();
    case 48:
      if (lookahead == 'f') ADVANCE(150);
      END_STATE();
    case 49:
      if (lookahead == 'f') ADVANCE(161);
      END_STATE();
    case 50:
      if (lookahead == 'f') ADVANCE(60);
      END_STATE();
    case 51:
      if (lookahead == 'f') ADVANCE(16);
      END_STATE();
    case 52:
      if (lookahead == 'g') ADVANCE(159);
      END_STATE();
    case 53:
      if (lookahead == 'g') ADVANCE(221);
      END_STATE();
    case 54:
      if (lookahead == 'g') ADVANCE(229);
      END_STATE();
    case 55:
      if (lookahead == 'g') ADVANCE(32);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(50);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(72);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(109);
      END_STATE();
    case 60:
      if (lookahead == 'i') ADVANCE(43);
      END_STATE();
    case 61:
      if (lookahead == 'i') ADVANCE(89);
      END_STATE();
    case 62:
      if (lookahead == 'i') ADVANCE(82);
      END_STATE();
    case 63:
      if (lookahead == 'i') ADVANCE(82);
      if (lookahead == 'u') ADVANCE(22);
      END_STATE();
    case 64:
      if (lookahead == 'k') ADVANCE(13);
      END_STATE();
    case 65:
      if (lookahead == 'l') ADVANCE(151);
      END_STATE();
    case 66:
      if (lookahead == 'l') ADVANCE(39);
      if (lookahead == 'o') ADVANCE(102);
      END_STATE();
    case 67:
      if (lookahead == 'l') ADVANCE(107);
      END_STATE();
    case 68:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 69:
      if (lookahead == 'l') ADVANCE(45);
      END_STATE();
    case 70:
      if (lookahead == 'm') ADVANCE(163);
      END_STATE();
    case 71:
      if (lookahead == 'm') ADVANCE(154);
      END_STATE();
    case 72:
      if (lookahead == 'm') ADVANCE(33);
      END_STATE();
    case 73:
      if (lookahead == 'm') ADVANCE(46);
      END_STATE();
    case 74:
      if (lookahead == 'n') ADVANCE(114);
      if (lookahead == 'x') ADVANCE(94);
      END_STATE();
    case 75:
      if (lookahead == 'n') ADVANCE(114);
      if (lookahead == 'x') ADVANCE(93);
      END_STATE();
    case 76:
      if (lookahead == 'n') ADVANCE(152);
      END_STATE();
    case 77:
      if (lookahead == 'n') ADVANCE(231);
      END_STATE();
    case 78:
      if (lookahead == 'n') ADVANCE(53);
      END_STATE();
    case 79:
      if (lookahead == 'n') ADVANCE(108);
      END_STATE();
    case 80:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 81:
      if (lookahead == 'n') ADVANCE(21);
      END_STATE();
    case 82:
      if (lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 83:
      if (lookahead == 'n') ADVANCE(28);
      END_STATE();
    case 84:
      if (lookahead == 'n') ADVANCE(116);
      END_STATE();
    case 85:
      if (lookahead == 'n') ADVANCE(115);
      END_STATE();
    case 86:
      if (lookahead == 'o') ADVANCE(78);
      END_STATE();
    case 87:
      if (lookahead == 'o') ADVANCE(29);
      END_STATE();
    case 88:
      if (lookahead == 'o') ADVANCE(91);
      if (lookahead == 'y') ADVANCE(120);
      END_STATE();
    case 89:
      if (lookahead == 'o') ADVANCE(76);
      END_STATE();
    case 90:
      if (lookahead == 'o') ADVANCE(71);
      END_STATE();
    case 91:
      if (lookahead == 'o') ADVANCE(69);
      END_STATE();
    case 92:
      if (lookahead == 'p') ADVANCE(66);
      END_STATE();
    case 93:
      if (lookahead == 'p') ADVANCE(14);
      END_STATE();
    case 94:
      if (lookahead == 'p') ADVANCE(14);
      if (lookahead == 't') ADVANCE(47);
      END_STATE();
    case 95:
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 96:
      if (lookahead == 'r') ADVANCE(63);
      END_STATE();
    case 97:
      if (lookahead == 'r') ADVANCE(106);
      END_STATE();
    case 98:
      if (lookahead == 'r') ADVANCE(166);
      END_STATE();
    case 99:
      if (lookahead == 'r') ADVANCE(124);
      END_STATE();
    case 100:
      if (lookahead == 'r') ADVANCE(123);
      END_STATE();
    case 101:
      if (lookahead == 'r') ADVANCE(51);
      END_STATE();
    case 102:
      if (lookahead == 'r') ADVANCE(110);
      END_STATE();
    case 103:
      if (lookahead == 'r') ADVANCE(62);
      END_STATE();
    case 104:
      if (lookahead == 's') ADVANCE(157);
      END_STATE();
    case 105:
      if (lookahead == 's') ADVANCE(158);
      END_STATE();
    case 106:
      if (lookahead == 's') ADVANCE(61);
      END_STATE();
    case 107:
      if (lookahead == 's') ADVANCE(35);
      END_STATE();
    case 108:
      if (lookahead == 't') ADVANCE(219);
      END_STATE();
    case 109:
      if (lookahead == 't') ADVANCE(125);
      END_STATE();
    case 110:
      if (lookahead == 't') ADVANCE(153);
      END_STATE();
    case 111:
      if (lookahead == 't') ADVANCE(156);
      END_STATE();
    case 112:
      if (lookahead == 't') ADVANCE(96);
      END_STATE();
    case 113:
      if (lookahead == 't') ADVANCE(30);
      END_STATE();
    case 114:
      if (lookahead == 't') ADVANCE(59);
      if (lookahead == 'u') ADVANCE(70);
      END_STATE();
    case 115:
      if (lookahead == 't') ADVANCE(105);
      END_STATE();
    case 116:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 117:
      if (lookahead == 't') ADVANCE(100);
      END_STATE();
    case 118:
      if (lookahead == 't') ADVANCE(103);
      END_STATE();
    case 119:
      if (lookahead == 't') ADVANCE(44);
      END_STATE();
    case 120:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 121:
      if (lookahead == 'u') ADVANCE(146);
      if (lookahead == 'x') ADVANCE(143);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(121);
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
    case 122:
      if (lookahead == 'u') ADVANCE(18);
      END_STATE();
    case 123:
      if (lookahead == 'u') ADVANCE(22);
      END_STATE();
    case 124:
      if (lookahead == 'u') ADVANCE(34);
      END_STATE();
    case 125:
      if (lookahead == 'y') ADVANCE(165);
      END_STATE();
    case 126:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(260);
      END_STATE();
    case 127:
      if (('0' <= lookahead && lookahead <= '2')) ADVANCE(259);
      END_STATE();
    case 128:
      if (('0' <= lookahead && lookahead <= '3')) ADVANCE(253);
      END_STATE();
    case 129:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(140);
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
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(260);
      END_STATE();
    case 134:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(255);
      END_STATE();
    case 135:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(257);
      END_STATE();
    case 136:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
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
        'a', 95,
        'd', 11,
        'e', 74,
        'i', 24,
        'l', 86,
        'm', 87,
        'p', 10,
        's', 112,
        'u', 146,
        'v', 41,
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
        'a', 95,
        'e', 75,
        'f', 15,
        'i', 25,
        'p', 10,
        'r', 42,
        's', 117,
        't', 99,
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
      if (lookahead == 't') ADVANCE(58);
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
  [26] = {.lex_state = 8},
  [27] = {.lex_state = 148},
  [28] = {.lex_state = 148},
  [29] = {.lex_state = 8},
  [30] = {.lex_state = 8},
  [31] = {.lex_state = 148},
  [32] = {.lex_state = 148},
  [33] = {.lex_state = 148},
  [34] = {.lex_state = 148},
  [35] = {.lex_state = 148},
  [36] = {.lex_state = 148},
  [37] = {.lex_state = 148},
  [38] = {.lex_state = 148},
  [39] = {.lex_state = 19},
  [40] = {.lex_state = 148},
  [41] = {.lex_state = 148},
  [42] = {.lex_state = 148},
  [43] = {.lex_state = 148},
  [44] = {.lex_state = 148},
  [45] = {.lex_state = 148},
  [46] = {.lex_state = 148},
  [47] = {.lex_state = 148},
  [48] = {.lex_state = 148},
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
  [61] = {.lex_state = 6},
  [62] = {.lex_state = 148},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 148},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 148},
  [67] = {.lex_state = 148},
  [68] = {.lex_state = 6},
  [69] = {.lex_state = 6},
  [70] = {.lex_state = 148},
  [71] = {.lex_state = 148},
  [72] = {.lex_state = 148},
  [73] = {.lex_state = 6},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 6},
  [76] = {.lex_state = 4},
  [77] = {.lex_state = 3},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 3},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 148},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 4},
  [89] = {.lex_state = 3},
  [90] = {.lex_state = 6},
  [91] = {.lex_state = 3},
  [92] = {.lex_state = 4},
  [93] = {.lex_state = 3},
  [94] = {.lex_state = 4},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 121},
  [97] = {.lex_state = 148},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 6},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 148},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 8},
  [112] = {.lex_state = 121},
  [113] = {.lex_state = 6},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 6},
  [116] = {.lex_state = 148},
  [117] = {.lex_state = 148},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 148},
  [121] = {.lex_state = 3},
  [122] = {.lex_state = 4},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 6},
  [125] = {.lex_state = 4},
  [126] = {.lex_state = 6},
  [127] = {.lex_state = 6},
  [128] = {.lex_state = 6},
  [129] = {.lex_state = 148},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 6},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 3},
  [134] = {.lex_state = 148},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 6},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 6},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 148},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 148},
  [151] = {.lex_state = 148},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 148},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 148},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 5},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 2},
  [178] = {.lex_state = 6},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 2},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 6},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 148},
  [189] = {.lex_state = 6},
  [190] = {.lex_state = 2},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 6},
  [194] = {.lex_state = 2},
  [195] = {.lex_state = 6},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 6},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 6},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 6},
  [203] = {.lex_state = 6},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 2},
  [207] = {.lex_state = 2},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 148},
  [210] = {.lex_state = 7},
  [211] = {.lex_state = 2},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 148},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 6},
  [216] = {.lex_state = 8},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 6},
  [219] = {.lex_state = 19},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 6},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 2},
  [225] = {.lex_state = 129},
  [226] = {.lex_state = 6},
  [227] = {.lex_state = 6},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 6},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 6},
  [234] = {.lex_state = 0},
  [235] = {.lex_state = 6},
  [236] = {.lex_state = 6},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 148},
  [239] = {.lex_state = 148},
  [240] = {.lex_state = 2},
  [241] = {.lex_state = 2},
  [242] = {.lex_state = 6},
  [243] = {.lex_state = 0},
  [244] = {.lex_state = 148},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 19},
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
    [sym_source_file] = STATE(222),
    [sym_dmf_declaration] = STATE(190),
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
    STATE(27), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(237), 1,
      sym_model_content,
    STATE(8), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(33), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    STATE(41), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [52] = 13,
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
    ACTIONS(21), 1,
      anon_sym_RBRACE,
    STATE(27), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(38), 1,
      sym__right_brace,
    STATE(5), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(41), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [97] = 12,
    ACTIONS(25), 1,
      anon_sym_package,
    ACTIONS(28), 1,
      anon_sym_struct,
    ACTIONS(31), 1,
      anon_sym_enum,
    ACTIONS(34), 1,
      anon_sym_entity,
    ACTIONS(37), 1,
      anon_sym_interface,
    ACTIONS(40), 1,
      sym_comment,
    ACTIONS(43), 1,
      sym_expand,
    STATE(27), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    STATE(4), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(41), 5,
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
    STATE(27), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(46), 1,
      sym__right_brace,
    STATE(4), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(41), 5,
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
    STATE(86), 1,
      sym_param_definition,
    STATE(90), 1,
      aux_sym_reftype_repeat1,
    STATE(127), 1,
      aux_sym_package_string_repeat1,
    STATE(220), 1,
      sym__right_paren,
    STATE(233), 1,
      sym_package_string,
    STATE(221), 2,
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
    STATE(27), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(229), 1,
      sym_model_content,
    STATE(8), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(41), 5,
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
    STATE(27), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(4), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(41), 5,
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
    STATE(90), 1,
      aux_sym_reftype_repeat1,
    STATE(127), 1,
      aux_sym_package_string_repeat1,
    STATE(233), 1,
      sym_package_string,
    STATE(197), 2,
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
    STATE(100), 1,
      sym_integerValue,
    STATE(137), 1,
      sym_dateValue,
    STATE(160), 1,
      sym_primitive_value,
    ACTIONS(62), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(161), 6,
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
    STATE(90), 1,
      aux_sym_reftype_repeat1,
    STATE(127), 1,
      aux_sym_package_string_repeat1,
    STATE(172), 1,
      sym_param_definition,
    STATE(233), 1,
      sym_package_string,
    STATE(221), 2,
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
      anon_sym_identifier,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(70), 1,
      sym_comment_block,
    STATE(149), 1,
      sym_identifier_statement,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
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
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(40), 1,
      sym__right_brace,
    STATE(70), 1,
      sym_comment_block,
    STATE(23), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
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
    ACTIONS(82), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(47), 1,
      sym__right_brace,
    STATE(70), 1,
      sym_comment_block,
    STATE(18), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
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
    ACTIONS(84), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(56), 1,
      sym__right_brace,
    STATE(70), 1,
      sym_comment_block,
    STATE(19), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
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
    ACTIONS(78), 1,
      anon_sym_identifier,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(70), 1,
      sym_comment_block,
    STATE(183), 1,
      sym_identifier_statement,
    STATE(22), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
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
    ACTIONS(86), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(51), 1,
      sym__right_brace,
    STATE(70), 1,
      sym_comment_block,
    STATE(15), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
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
    ACTIONS(86), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(51), 1,
      sym__right_brace,
    STATE(70), 1,
      sym_comment_block,
    STATE(19), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [649] = 9,
    ACTIONS(88), 1,
      anon_sym_arg,
    ACTIONS(91), 1,
      anon_sym_ref,
    ACTIONS(94), 1,
      anon_sym_func,
    ACTIONS(99), 1,
      sym_comment,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(70), 1,
      sym_comment_block,
    ACTIONS(97), 2,
      anon_sym_identifier,
      anon_sym_RBRACE,
    STATE(19), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [681] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(78), 1,
      anon_sym_identifier,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(70), 1,
      sym_comment_block,
    STATE(183), 1,
      sym_identifier_statement,
    STATE(19), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
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
    ACTIONS(78), 1,
      anon_sym_identifier,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(70), 1,
      sym_comment_block,
    STATE(147), 1,
      sym_identifier_statement,
    STATE(24), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
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
    ACTIONS(78), 1,
      anon_sym_identifier,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(70), 1,
      sym_comment_block,
    STATE(147), 1,
      sym_identifier_statement,
    STATE(19), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
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
    ACTIONS(82), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(47), 1,
      sym__right_brace,
    STATE(70), 1,
      sym_comment_block,
    STATE(19), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
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
    ACTIONS(78), 1,
      anon_sym_identifier,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(70), 1,
      sym_comment_block,
    STATE(154), 1,
      sym_identifier_statement,
    STATE(19), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(139), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [851] = 3,
    ACTIONS(104), 1,
      sym_comment,
    STATE(25), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(102), 9,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_expand,
  [869] = 9,
    ACTIONS(107), 1,
      anon_sym_arg,
    ACTIONS(109), 1,
      sym_identifier,
    ACTIONS(111), 1,
      sym_comment,
    ACTIONS(113), 1,
      anon_sym_RBRACE,
    STATE(42), 1,
      sym__right_brace,
    STATE(124), 1,
      aux_sym_comment_block_repeat1,
    STATE(203), 1,
      sym_comment_block,
    STATE(29), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(143), 2,
      sym_arg_block,
      sym_enum_constant,
  [899] = 7,
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
    ACTIONS(115), 1,
      sym_expand,
    STATE(57), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [925] = 3,
    ACTIONS(119), 1,
      sym_comment,
    STATE(25), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(117), 9,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_expand,
  [943] = 9,
    ACTIONS(107), 1,
      anon_sym_arg,
    ACTIONS(109), 1,
      sym_identifier,
    ACTIONS(111), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_RBRACE,
    STATE(35), 1,
      sym__right_brace,
    STATE(124), 1,
      aux_sym_comment_block_repeat1,
    STATE(203), 1,
      sym_comment_block,
    STATE(30), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(143), 2,
      sym_arg_block,
      sym_enum_constant,
  [973] = 8,
    ACTIONS(123), 1,
      anon_sym_arg,
    ACTIONS(126), 1,
      sym_identifier,
    ACTIONS(129), 1,
      sym_comment,
    ACTIONS(132), 1,
      anon_sym_RBRACE,
    STATE(124), 1,
      aux_sym_comment_block_repeat1,
    STATE(203), 1,
      sym_comment_block,
    STATE(30), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(143), 2,
      sym_arg_block,
      sym_enum_constant,
  [1000] = 3,
    ACTIONS(134), 1,
      anon_sym_import,
    STATE(31), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    ACTIONS(137), 7,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1017] = 6,
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
    STATE(57), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [1040] = 3,
    ACTIONS(5), 1,
      anon_sym_import,
    STATE(31), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    ACTIONS(139), 7,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1057] = 6,
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
    STATE(37), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
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
  [1092] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(143), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(44), 1,
      sym__right_brace,
    STATE(151), 1,
      sym_comment_block,
    STATE(152), 1,
      sym_func_block,
    STATE(45), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1118] = 1,
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
  [1130] = 1,
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
  [1142] = 3,
    ACTIONS(54), 1,
      sym_date,
    STATE(193), 1,
      sym_primitive_type,
    ACTIONS(149), 7,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_string,
      sym_boolean,
  [1158] = 1,
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
  [1170] = 1,
    ACTIONS(153), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1182] = 1,
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
  [1194] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(157), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(49), 1,
      sym__right_brace,
    STATE(151), 1,
      sym_comment_block,
    STATE(152), 1,
      sym_func_block,
    STATE(50), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1220] = 1,
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
  [1232] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(157), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(49), 1,
      sym__right_brace,
    STATE(151), 1,
      sym_comment_block,
    STATE(152), 1,
      sym_func_block,
    STATE(59), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1258] = 1,
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
  [1270] = 1,
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
  [1282] = 1,
    ACTIONS(165), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
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
  [1306] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(169), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(55), 1,
      sym__right_brace,
    STATE(151), 1,
      sym_comment_block,
    STATE(152), 1,
      sym_func_block,
    STATE(59), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1332] = 1,
    ACTIONS(171), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
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
  [1427] = 7,
    ACTIONS(187), 1,
      anon_sym_func,
    ACTIONS(190), 1,
      sym_comment,
    ACTIONS(193), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(151), 1,
      sym_comment_block,
    STATE(152), 1,
      sym_func_block,
    STATE(59), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1450] = 1,
    ACTIONS(195), 8,
      anon_sym_import,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1461] = 6,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(75), 1,
      aux_sym_reftype_repeat1,
    STATE(119), 1,
      sym_package_string,
    STATE(186), 1,
      sym_reftype,
  [1480] = 3,
    ACTIONS(203), 1,
      sym_dot,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(201), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1493] = 6,
    ACTIONS(205), 1,
      anon_sym_extends,
    ACTIONS(207), 1,
      anon_sym_implements,
    ACTIONS(209), 1,
      anon_sym_LBRACE,
    STATE(13), 1,
      sym__left_brace,
    STATE(98), 1,
      sym_extends_block,
    STATE(153), 1,
      sym_implements_block,
  [1512] = 1,
    ACTIONS(211), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1521] = 6,
    ACTIONS(205), 1,
      anon_sym_extends,
    ACTIONS(207), 1,
      anon_sym_implements,
    ACTIONS(213), 1,
      anon_sym_LBRACE,
    STATE(12), 1,
      sym__left_brace,
    STATE(108), 1,
      sym_extends_block,
    STATE(156), 1,
      sym_implements_block,
  [1540] = 3,
    ACTIONS(203), 1,
      sym_dot,
    STATE(72), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(201), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1553] = 3,
    ACTIONS(203), 1,
      sym_dot,
    STATE(72), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(215), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1566] = 6,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(217), 1,
      sym_identifier,
    STATE(90), 1,
      aux_sym_reftype_repeat1,
    STATE(127), 1,
      aux_sym_package_string_repeat1,
    STATE(195), 1,
      sym_reftype,
    STATE(233), 1,
      sym_package_string,
  [1585] = 6,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(75), 1,
      aux_sym_reftype_repeat1,
    STATE(103), 1,
      sym_reftype,
    STATE(119), 1,
      sym_package_string,
  [1604] = 4,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    STATE(173), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [1619] = 1,
    ACTIONS(219), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1628] = 3,
    ACTIONS(223), 1,
      sym_dot,
    STATE(72), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(221), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1641] = 6,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(75), 1,
      aux_sym_reftype_repeat1,
    STATE(119), 1,
      sym_package_string,
    STATE(179), 1,
      sym_reftype,
  [1660] = 5,
    ACTIONS(226), 1,
      anon_sym_COMMA,
    ACTIONS(228), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(107), 1,
      aux_sym_func_block_repeat1,
    STATE(208), 1,
      sym__right_paren,
  [1676] = 5,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(135), 1,
      sym_package_string,
    STATE(136), 1,
      aux_sym_reftype_repeat1,
  [1692] = 5,
    ACTIONS(230), 1,
      anon_sym_SQUOTE,
    ACTIONS(232), 1,
      sym_string_content_single_quote,
    ACTIONS(234), 1,
      anon_sym_BSLASH,
    STATE(80), 1,
      aux_sym_stringValue_repeat2,
    STATE(122), 1,
      sym_escape_sequence,
  [1708] = 5,
    ACTIONS(230), 1,
      anon_sym_DQUOTE,
    ACTIONS(236), 1,
      sym_string_content_double_quote,
    ACTIONS(238), 1,
      anon_sym_BSLASH,
    STATE(89), 1,
      aux_sym_stringValue_repeat1,
    STATE(133), 1,
      sym_escape_sequence,
  [1724] = 2,
    ACTIONS(240), 1,
      anon_sym__,
    ACTIONS(242), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [1734] = 5,
    ACTIONS(244), 1,
      anon_sym_COMMA,
    ACTIONS(246), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(83), 1,
      aux_sym_enum_constant_repeat1,
    STATE(192), 1,
      sym__right_paren,
  [1750] = 5,
    ACTIONS(232), 1,
      sym_string_content_single_quote,
    ACTIONS(234), 1,
      anon_sym_BSLASH,
    ACTIONS(248), 1,
      anon_sym_SQUOTE,
    STATE(88), 1,
      aux_sym_stringValue_repeat2,
    STATE(122), 1,
      sym_escape_sequence,
  [1766] = 5,
    ACTIONS(250), 1,
      anon_sym_COMMA,
    ACTIONS(252), 1,
      anon_sym_RPAREN,
    STATE(85), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(155), 1,
      sym__right_paren,
    STATE(202), 1,
      sym__comma,
  [1782] = 5,
    ACTIONS(254), 1,
      anon_sym_DQUOTE,
    ACTIONS(256), 1,
      sym_string_content_double_quote,
    ACTIONS(259), 1,
      anon_sym_BSLASH,
    STATE(82), 1,
      aux_sym_stringValue_repeat1,
    STATE(133), 1,
      sym_escape_sequence,
  [1798] = 5,
    ACTIONS(244), 1,
      anon_sym_COMMA,
    ACTIONS(262), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(101), 1,
      aux_sym_enum_constant_repeat1,
    STATE(214), 1,
      sym__right_paren,
  [1814] = 1,
    ACTIONS(221), 5,
      anon_sym_from,
      anon_sym_implements,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1822] = 5,
    ACTIONS(250), 1,
      anon_sym_COMMA,
    ACTIONS(264), 1,
      anon_sym_RPAREN,
    STATE(104), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(165), 1,
      sym__right_paren,
    STATE(202), 1,
      sym__comma,
  [1838] = 5,
    ACTIONS(226), 1,
      anon_sym_COMMA,
    ACTIONS(266), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(74), 1,
      aux_sym_func_block_repeat1,
    STATE(196), 1,
      sym__right_paren,
  [1854] = 5,
    ACTIONS(244), 1,
      anon_sym_COMMA,
    ACTIONS(268), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(101), 1,
      aux_sym_enum_constant_repeat1,
    STATE(204), 1,
      sym__right_paren,
  [1870] = 5,
    ACTIONS(270), 1,
      anon_sym_SQUOTE,
    ACTIONS(272), 1,
      sym_string_content_single_quote,
    ACTIONS(275), 1,
      anon_sym_BSLASH,
    STATE(88), 1,
      aux_sym_stringValue_repeat2,
    STATE(122), 1,
      sym_escape_sequence,
  [1886] = 5,
    ACTIONS(236), 1,
      sym_string_content_double_quote,
    ACTIONS(238), 1,
      anon_sym_BSLASH,
    ACTIONS(248), 1,
      anon_sym_DQUOTE,
    STATE(82), 1,
      aux_sym_stringValue_repeat1,
    STATE(133), 1,
      sym_escape_sequence,
  [1902] = 5,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(217), 1,
      sym_identifier,
    STATE(127), 1,
      aux_sym_package_string_repeat1,
    STATE(136), 1,
      aux_sym_reftype_repeat1,
    STATE(235), 1,
      sym_package_string,
  [1918] = 5,
    ACTIONS(236), 1,
      sym_string_content_double_quote,
    ACTIONS(238), 1,
      anon_sym_BSLASH,
    ACTIONS(278), 1,
      anon_sym_DQUOTE,
    STATE(93), 1,
      aux_sym_stringValue_repeat1,
    STATE(133), 1,
      sym_escape_sequence,
  [1934] = 5,
    ACTIONS(232), 1,
      sym_string_content_single_quote,
    ACTIONS(234), 1,
      anon_sym_BSLASH,
    ACTIONS(278), 1,
      anon_sym_SQUOTE,
    STATE(94), 1,
      aux_sym_stringValue_repeat2,
    STATE(122), 1,
      sym_escape_sequence,
  [1950] = 5,
    ACTIONS(236), 1,
      sym_string_content_double_quote,
    ACTIONS(238), 1,
      anon_sym_BSLASH,
    ACTIONS(280), 1,
      anon_sym_DQUOTE,
    STATE(82), 1,
      aux_sym_stringValue_repeat1,
    STATE(133), 1,
      sym_escape_sequence,
  [1966] = 5,
    ACTIONS(232), 1,
      sym_string_content_single_quote,
    ACTIONS(234), 1,
      anon_sym_BSLASH,
    ACTIONS(280), 1,
      anon_sym_SQUOTE,
    STATE(88), 1,
      aux_sym_stringValue_repeat2,
    STATE(122), 1,
      sym_escape_sequence,
  [1982] = 5,
    ACTIONS(244), 1,
      anon_sym_COMMA,
    ACTIONS(262), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(87), 1,
      aux_sym_enum_constant_repeat1,
    STATE(214), 1,
      sym__right_paren,
  [1998] = 1,
    ACTIONS(282), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2005] = 4,
    ACTIONS(284), 1,
      anon_sym__,
    ACTIONS(286), 1,
      sym_number,
    STATE(95), 1,
      sym_enum_index,
    STATE(145), 1,
      sym_integerValue,
  [2018] = 4,
    ACTIONS(207), 1,
      anon_sym_implements,
    ACTIONS(288), 1,
      anon_sym_LBRACE,
    STATE(14), 1,
      sym__left_brace,
    STATE(182), 1,
      sym_implements_block,
  [2031] = 1,
    ACTIONS(290), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [2038] = 3,
    ACTIONS(292), 1,
      sym_dot,
    ACTIONS(296), 1,
      anon_sym_L,
    ACTIONS(294), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2049] = 4,
    ACTIONS(298), 1,
      anon_sym_COMMA,
    ACTIONS(301), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(101), 1,
      aux_sym_enum_constant_repeat1,
  [2062] = 4,
    ACTIONS(303), 1,
      anon_sym_LPAREN,
    ACTIONS(305), 1,
      sym__new_line,
    STATE(194), 1,
      sym_model_identifier,
    STATE(198), 1,
      sym__left_paren,
  [2075] = 4,
    ACTIONS(307), 1,
      anon_sym_COMMA,
    ACTIONS(309), 1,
      anon_sym_LBRACE,
    STATE(61), 1,
      sym__comma,
    STATE(106), 1,
      aux_sym_implements_block_repeat1,
  [2088] = 4,
    ACTIONS(311), 1,
      anon_sym_COMMA,
    ACTIONS(314), 1,
      anon_sym_RPAREN,
    STATE(104), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(202), 1,
      sym__comma,
  [2101] = 4,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(203), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(213), 1,
      sym_package_string,
  [2114] = 4,
    ACTIONS(307), 1,
      anon_sym_COMMA,
    ACTIONS(316), 1,
      anon_sym_LBRACE,
    STATE(61), 1,
      sym__comma,
    STATE(114), 1,
      aux_sym_implements_block_repeat1,
  [2127] = 4,
    ACTIONS(318), 1,
      anon_sym_COMMA,
    ACTIONS(321), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(107), 1,
      aux_sym_func_block_repeat1,
  [2140] = 4,
    ACTIONS(207), 1,
      anon_sym_implements,
    ACTIONS(323), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym__left_brace,
    STATE(146), 1,
      sym_implements_block,
  [2153] = 4,
    ACTIONS(284), 1,
      anon_sym__,
    ACTIONS(286), 1,
      sym_number,
    STATE(79), 1,
      sym_enum_index,
    STATE(145), 1,
      sym_integerValue,
  [2166] = 4,
    ACTIONS(207), 1,
      anon_sym_implements,
    ACTIONS(325), 1,
      anon_sym_LBRACE,
    STATE(36), 1,
      sym__left_brace,
    STATE(158), 1,
      sym_implements_block,
  [2179] = 2,
    ACTIONS(327), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(329), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2188] = 1,
    ACTIONS(331), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2195] = 4,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(203), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(162), 1,
      sym_package_string,
  [2208] = 4,
    ACTIONS(333), 1,
      anon_sym_COMMA,
    ACTIONS(336), 1,
      anon_sym_LBRACE,
    STATE(61), 1,
      sym__comma,
    STATE(114), 1,
      aux_sym_implements_block_repeat1,
  [2221] = 3,
    ACTIONS(215), 1,
      sym_identifier,
    ACTIONS(338), 1,
      sym_dot,
    STATE(131), 1,
      aux_sym_package_string_repeat1,
  [2231] = 3,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    STATE(118), 1,
      sym_stringValue,
  [2241] = 1,
    ACTIONS(340), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2247] = 3,
    ACTIONS(342), 1,
      anon_sym_version,
    ACTIONS(344), 1,
      anon_sym_RPAREN,
    STATE(211), 1,
      sym__right_paren,
  [2257] = 1,
    ACTIONS(346), 3,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2263] = 3,
    ACTIONS(348), 1,
      anon_sym_DQUOTE,
    ACTIONS(350), 1,
      anon_sym_SQUOTE,
    STATE(102), 1,
      sym_stringValue,
  [2273] = 2,
    ACTIONS(354), 1,
      sym_string_content_double_quote,
    ACTIONS(352), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2281] = 2,
    ACTIONS(358), 1,
      sym_string_content_single_quote,
    ACTIONS(356), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2289] = 1,
    ACTIONS(360), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_T,
  [2295] = 3,
    ACTIONS(117), 1,
      sym_identifier,
    ACTIONS(362), 1,
      sym_comment,
    STATE(128), 1,
      aux_sym_comment_block_repeat1,
  [2305] = 2,
    ACTIONS(354), 1,
      sym_string_content_single_quote,
    ACTIONS(352), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2313] = 3,
    ACTIONS(201), 1,
      sym_identifier,
    ACTIONS(338), 1,
      sym_dot,
    STATE(115), 1,
      aux_sym_package_string_repeat1,
  [2323] = 3,
    ACTIONS(201), 1,
      sym_identifier,
    ACTIONS(338), 1,
      sym_dot,
    STATE(131), 1,
      aux_sym_package_string_repeat1,
  [2333] = 3,
    ACTIONS(102), 1,
      sym_identifier,
    ACTIONS(364), 1,
      sym_comment,
    STATE(128), 1,
      aux_sym_comment_block_repeat1,
  [2343] = 3,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    STATE(228), 1,
      sym_stringValue,
  [2353] = 1,
    ACTIONS(367), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2359] = 3,
    ACTIONS(221), 1,
      sym_identifier,
    ACTIONS(369), 1,
      sym_dot,
    STATE(131), 1,
      aux_sym_package_string_repeat1,
  [2369] = 1,
    ACTIONS(372), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2375] = 2,
    ACTIONS(376), 1,
      sym_string_content_double_quote,
    ACTIONS(374), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2383] = 1,
    ACTIONS(378), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2389] = 1,
    ACTIONS(380), 3,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2395] = 3,
    ACTIONS(382), 1,
      sym_identifier,
    ACTIONS(384), 1,
      sym_dot,
    STATE(136), 1,
      aux_sym_reftype_repeat1,
  [2405] = 2,
    ACTIONS(387), 1,
      anon_sym_T,
    ACTIONS(294), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2413] = 1,
    ACTIONS(221), 2,
      sym_identifier,
      sym_dot,
  [2418] = 2,
    ACTIONS(389), 1,
      anon_sym_SEMI,
    STATE(71), 1,
      sym__semicolon,
  [2425] = 2,
    ACTIONS(391), 1,
      sym_number,
    STATE(240), 1,
      sym_version_number,
  [2432] = 2,
    ACTIONS(393), 1,
      anon_sym_model,
    STATE(224), 1,
      sym_model_declaration,
  [2439] = 2,
    ACTIONS(395), 1,
      anon_sym_LPAREN,
    STATE(109), 1,
      sym__left_paren,
  [2446] = 2,
    ACTIONS(397), 1,
      anon_sym_SEMI,
    STATE(111), 1,
      sym__semicolon,
  [2453] = 2,
    ACTIONS(399), 1,
      anon_sym_LPAREN,
    STATE(6), 1,
      sym__left_paren,
  [2460] = 1,
    ACTIONS(401), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2465] = 2,
    ACTIONS(403), 1,
      anon_sym_LBRACE,
    STATE(21), 1,
      sym__left_brace,
  [2472] = 2,
    ACTIONS(405), 1,
      anon_sym_RBRACE,
    STATE(52), 1,
      sym__right_brace,
  [2479] = 2,
    ACTIONS(407), 1,
      anon_sym_LPAREN,
    STATE(236), 1,
      sym__left_paren,
  [2486] = 2,
    ACTIONS(409), 1,
      anon_sym_RBRACE,
    STATE(48), 1,
      sym__right_brace,
  [2493] = 2,
    ACTIONS(391), 1,
      sym_number,
    STATE(241), 1,
      sym_version_number,
  [2500] = 2,
    ACTIONS(76), 1,
      anon_sym_func,
    STATE(185), 1,
      sym_func_block,
  [2507] = 2,
    ACTIONS(411), 1,
      anon_sym_SEMI,
    STATE(134), 1,
      sym__semicolon,
  [2514] = 2,
    ACTIONS(288), 1,
      anon_sym_LBRACE,
    STATE(14), 1,
      sym__left_brace,
  [2521] = 2,
    ACTIONS(413), 1,
      anon_sym_RBRACE,
    STATE(53), 1,
      sym__right_brace,
  [2528] = 2,
    ACTIONS(415), 1,
      anon_sym_SEMI,
    STATE(191), 1,
      sym__semicolon,
  [2535] = 2,
    ACTIONS(323), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym__left_brace,
  [2542] = 2,
    ACTIONS(417), 1,
      sym_number,
    STATE(166), 1,
      sym_version_number,
  [2549] = 2,
    ACTIONS(419), 1,
      anon_sym_LBRACE,
    STATE(43), 1,
      sym__left_brace,
  [2556] = 1,
    ACTIONS(421), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2561] = 1,
    ACTIONS(301), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2566] = 1,
    ACTIONS(294), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2571] = 2,
    ACTIONS(423), 1,
      anon_sym_LBRACE,
    STATE(3), 1,
      sym__left_brace,
  [2578] = 2,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    STATE(26), 1,
      sym__left_brace,
  [2585] = 1,
    ACTIONS(314), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2590] = 2,
    ACTIONS(427), 1,
      anon_sym_SEMI,
    STATE(205), 1,
      sym__semicolon,
  [2597] = 2,
    ACTIONS(429), 1,
      anon_sym_RPAREN,
    STATE(206), 1,
      sym__right_paren,
  [2604] = 1,
    ACTIONS(431), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2609] = 1,
    ACTIONS(433), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2614] = 2,
    ACTIONS(286), 1,
      sym_number,
    STATE(174), 1,
      sym_integerValue,
  [2621] = 1,
    ACTIONS(435), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2626] = 2,
    ACTIONS(437), 1,
      aux_sym_timeValue_token1,
    STATE(175), 1,
      sym_timeValue,
  [2633] = 1,
    ACTIONS(321), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2638] = 2,
    ACTIONS(439), 1,
      anon_sym_SEMI,
    STATE(64), 1,
      sym__semicolon,
  [2645] = 1,
    ACTIONS(441), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2650] = 1,
    ACTIONS(443), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2655] = 1,
    ACTIONS(445), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2660] = 2,
    ACTIONS(372), 1,
      sym__new_line,
    ACTIONS(447), 1,
      anon_sym_LPAREN,
  [2667] = 2,
    ACTIONS(449), 1,
      sym_identifier,
    ACTIONS(452), 1,
      sym_dot,
  [2674] = 1,
    ACTIONS(454), 2,
      anon_sym_implements,
      anon_sym_LBRACE,
  [2679] = 2,
    ACTIONS(367), 1,
      sym__new_line,
    ACTIONS(456), 1,
      anon_sym_LPAREN,
  [2686] = 2,
    ACTIONS(458), 1,
      anon_sym_LPAREN,
    STATE(97), 1,
      sym__left_paren,
  [2693] = 2,
    ACTIONS(460), 1,
      anon_sym_LBRACE,
    STATE(17), 1,
      sym__left_brace,
  [2700] = 2,
    ACTIONS(462), 1,
      anon_sym_RBRACE,
    STATE(54), 1,
      sym__right_brace,
  [2707] = 2,
    ACTIONS(452), 1,
      sym_dot,
    ACTIONS(464), 1,
      sym_identifier,
  [2714] = 2,
    ACTIONS(467), 1,
      anon_sym_SEMI,
    STATE(117), 1,
      sym__semicolon,
  [2721] = 1,
    ACTIONS(336), 2,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2726] = 1,
    ACTIONS(469), 1,
      anon_sym_DASH,
  [2730] = 1,
    ACTIONS(471), 1,
      sym_number,
  [2734] = 1,
    ACTIONS(473), 1,
      sym_identifier,
  [2738] = 1,
    ACTIONS(475), 1,
      sym__new_line,
  [2742] = 1,
    ACTIONS(477), 1,
      anon_sym_RBRACE,
  [2746] = 1,
    ACTIONS(479), 1,
      anon_sym_SEMI,
  [2750] = 1,
    ACTIONS(481), 1,
      sym_identifier,
  [2754] = 1,
    ACTIONS(483), 1,
      sym__new_line,
  [2758] = 1,
    ACTIONS(485), 1,
      sym_identifier,
  [2762] = 1,
    ACTIONS(487), 1,
      anon_sym_SEMI,
  [2766] = 1,
    ACTIONS(489), 1,
      sym_identifier,
  [2770] = 1,
    ACTIONS(491), 1,
      anon_sym_model,
  [2774] = 1,
    ACTIONS(493), 1,
      sym_identifier,
  [2778] = 1,
    ACTIONS(495), 1,
      anon_sym_DASH,
  [2782] = 1,
    ACTIONS(497), 1,
      anon_sym_SEMI,
  [2786] = 1,
    ACTIONS(499), 1,
      sym_identifier,
  [2790] = 1,
    ACTIONS(501), 1,
      sym_identifier,
  [2794] = 1,
    ACTIONS(503), 1,
      anon_sym_SEMI,
  [2798] = 1,
    ACTIONS(505), 1,
      anon_sym_RBRACE,
  [2802] = 1,
    ACTIONS(507), 1,
      sym__new_line,
  [2806] = 1,
    ACTIONS(509), 1,
      sym__new_line,
  [2810] = 1,
    ACTIONS(511), 1,
      anon_sym_SEMI,
  [2814] = 1,
    ACTIONS(513), 1,
      sym_number,
  [2818] = 1,
    ACTIONS(515), 1,
      aux_sym_dateValue_token2,
  [2822] = 1,
    ACTIONS(517), 1,
      sym__new_line,
  [2826] = 1,
    ACTIONS(519), 1,
      anon_sym_COLON,
  [2830] = 1,
    ACTIONS(521), 1,
      anon_sym_from,
  [2834] = 1,
    ACTIONS(523), 1,
      anon_sym_SEMI,
  [2838] = 1,
    ACTIONS(525), 1,
      sym_identifier,
  [2842] = 1,
    ACTIONS(527), 1,
      aux_sym_dateValue_token3,
  [2846] = 1,
    ACTIONS(529), 1,
      anon_sym_COLON,
  [2850] = 1,
    ACTIONS(531), 1,
      sym_identifier,
  [2854] = 1,
    ACTIONS(533), 1,
      aux_sym_timeValue_token2,
  [2858] = 1,
    ACTIONS(535), 1,
      anon_sym_SEMI,
  [2862] = 1,
    ACTIONS(537), 1,
      sym_identifier,
  [2866] = 1,
    ACTIONS(539), 1,
      ts_builtin_sym_end,
  [2870] = 1,
    ACTIONS(509), 1,
      anon_sym_RPAREN,
  [2874] = 1,
    ACTIONS(541), 1,
      sym__new_line,
  [2878] = 1,
    ACTIONS(543), 1,
      sym_byte_content,
  [2882] = 1,
    ACTIONS(545), 1,
      aux_sym_dateValue_token1,
  [2886] = 1,
    ACTIONS(547), 1,
      sym_identifier,
  [2890] = 1,
    ACTIONS(549), 1,
      anon_sym_version,
  [2894] = 1,
    ACTIONS(551), 1,
      ts_builtin_sym_end,
  [2898] = 1,
    ACTIONS(553), 1,
      anon_sym_SEMI,
  [2902] = 1,
    ACTIONS(555), 1,
      sym_identifier,
  [2906] = 1,
    ACTIONS(557), 1,
      sym_dot,
  [2910] = 1,
    ACTIONS(346), 1,
      sym_identifier,
  [2914] = 1,
    ACTIONS(559), 1,
      sym_dot,
  [2918] = 1,
    ACTIONS(380), 1,
      sym_identifier,
  [2922] = 1,
    ACTIONS(561), 1,
      sym_identifier,
  [2926] = 1,
    ACTIONS(563), 1,
      ts_builtin_sym_end,
  [2930] = 1,
    ACTIONS(565), 1,
      sym_number,
  [2934] = 1,
    ACTIONS(567), 1,
      sym_number,
  [2938] = 1,
    ACTIONS(569), 1,
      sym__new_line,
  [2942] = 1,
    ACTIONS(571), 1,
      sym__new_line,
  [2946] = 1,
    ACTIONS(573), 1,
      sym_identifier,
  [2950] = 1,
    ACTIONS(575), 1,
      sym_dot,
  [2954] = 1,
    ACTIONS(577), 1,
      sym_number,
  [2958] = 1,
    ACTIONS(579), 1,
      sym_dot,
  [2962] = 1,
    ACTIONS(581), 1,
      aux_sym_timeValue_token2,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 52,
  [SMALL_STATE(4)] = 97,
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
  [SMALL_STATE(20)] = 681,
  [SMALL_STATE(21)] = 715,
  [SMALL_STATE(22)] = 749,
  [SMALL_STATE(23)] = 783,
  [SMALL_STATE(24)] = 817,
  [SMALL_STATE(25)] = 851,
  [SMALL_STATE(26)] = 869,
  [SMALL_STATE(27)] = 899,
  [SMALL_STATE(28)] = 925,
  [SMALL_STATE(29)] = 943,
  [SMALL_STATE(30)] = 973,
  [SMALL_STATE(31)] = 1000,
  [SMALL_STATE(32)] = 1017,
  [SMALL_STATE(33)] = 1040,
  [SMALL_STATE(34)] = 1057,
  [SMALL_STATE(35)] = 1080,
  [SMALL_STATE(36)] = 1092,
  [SMALL_STATE(37)] = 1118,
  [SMALL_STATE(38)] = 1130,
  [SMALL_STATE(39)] = 1142,
  [SMALL_STATE(40)] = 1158,
  [SMALL_STATE(41)] = 1170,
  [SMALL_STATE(42)] = 1182,
  [SMALL_STATE(43)] = 1194,
  [SMALL_STATE(44)] = 1220,
  [SMALL_STATE(45)] = 1232,
  [SMALL_STATE(46)] = 1258,
  [SMALL_STATE(47)] = 1270,
  [SMALL_STATE(48)] = 1282,
  [SMALL_STATE(49)] = 1294,
  [SMALL_STATE(50)] = 1306,
  [SMALL_STATE(51)] = 1332,
  [SMALL_STATE(52)] = 1344,
  [SMALL_STATE(53)] = 1356,
  [SMALL_STATE(54)] = 1368,
  [SMALL_STATE(55)] = 1380,
  [SMALL_STATE(56)] = 1392,
  [SMALL_STATE(57)] = 1404,
  [SMALL_STATE(58)] = 1416,
  [SMALL_STATE(59)] = 1427,
  [SMALL_STATE(60)] = 1450,
  [SMALL_STATE(61)] = 1461,
  [SMALL_STATE(62)] = 1480,
  [SMALL_STATE(63)] = 1493,
  [SMALL_STATE(64)] = 1512,
  [SMALL_STATE(65)] = 1521,
  [SMALL_STATE(66)] = 1540,
  [SMALL_STATE(67)] = 1553,
  [SMALL_STATE(68)] = 1566,
  [SMALL_STATE(69)] = 1585,
  [SMALL_STATE(70)] = 1604,
  [SMALL_STATE(71)] = 1619,
  [SMALL_STATE(72)] = 1628,
  [SMALL_STATE(73)] = 1641,
  [SMALL_STATE(74)] = 1660,
  [SMALL_STATE(75)] = 1676,
  [SMALL_STATE(76)] = 1692,
  [SMALL_STATE(77)] = 1708,
  [SMALL_STATE(78)] = 1724,
  [SMALL_STATE(79)] = 1734,
  [SMALL_STATE(80)] = 1750,
  [SMALL_STATE(81)] = 1766,
  [SMALL_STATE(82)] = 1782,
  [SMALL_STATE(83)] = 1798,
  [SMALL_STATE(84)] = 1814,
  [SMALL_STATE(85)] = 1822,
  [SMALL_STATE(86)] = 1838,
  [SMALL_STATE(87)] = 1854,
  [SMALL_STATE(88)] = 1870,
  [SMALL_STATE(89)] = 1886,
  [SMALL_STATE(90)] = 1902,
  [SMALL_STATE(91)] = 1918,
  [SMALL_STATE(92)] = 1934,
  [SMALL_STATE(93)] = 1950,
  [SMALL_STATE(94)] = 1966,
  [SMALL_STATE(95)] = 1982,
  [SMALL_STATE(96)] = 1998,
  [SMALL_STATE(97)] = 2005,
  [SMALL_STATE(98)] = 2018,
  [SMALL_STATE(99)] = 2031,
  [SMALL_STATE(100)] = 2038,
  [SMALL_STATE(101)] = 2049,
  [SMALL_STATE(102)] = 2062,
  [SMALL_STATE(103)] = 2075,
  [SMALL_STATE(104)] = 2088,
  [SMALL_STATE(105)] = 2101,
  [SMALL_STATE(106)] = 2114,
  [SMALL_STATE(107)] = 2127,
  [SMALL_STATE(108)] = 2140,
  [SMALL_STATE(109)] = 2153,
  [SMALL_STATE(110)] = 2166,
  [SMALL_STATE(111)] = 2179,
  [SMALL_STATE(112)] = 2188,
  [SMALL_STATE(113)] = 2195,
  [SMALL_STATE(114)] = 2208,
  [SMALL_STATE(115)] = 2221,
  [SMALL_STATE(116)] = 2231,
  [SMALL_STATE(117)] = 2241,
  [SMALL_STATE(118)] = 2247,
  [SMALL_STATE(119)] = 2257,
  [SMALL_STATE(120)] = 2263,
  [SMALL_STATE(121)] = 2273,
  [SMALL_STATE(122)] = 2281,
  [SMALL_STATE(123)] = 2289,
  [SMALL_STATE(124)] = 2295,
  [SMALL_STATE(125)] = 2305,
  [SMALL_STATE(126)] = 2313,
  [SMALL_STATE(127)] = 2323,
  [SMALL_STATE(128)] = 2333,
  [SMALL_STATE(129)] = 2343,
  [SMALL_STATE(130)] = 2353,
  [SMALL_STATE(131)] = 2359,
  [SMALL_STATE(132)] = 2369,
  [SMALL_STATE(133)] = 2375,
  [SMALL_STATE(134)] = 2383,
  [SMALL_STATE(135)] = 2389,
  [SMALL_STATE(136)] = 2395,
  [SMALL_STATE(137)] = 2405,
  [SMALL_STATE(138)] = 2413,
  [SMALL_STATE(139)] = 2418,
  [SMALL_STATE(140)] = 2425,
  [SMALL_STATE(141)] = 2432,
  [SMALL_STATE(142)] = 2439,
  [SMALL_STATE(143)] = 2446,
  [SMALL_STATE(144)] = 2453,
  [SMALL_STATE(145)] = 2460,
  [SMALL_STATE(146)] = 2465,
  [SMALL_STATE(147)] = 2472,
  [SMALL_STATE(148)] = 2479,
  [SMALL_STATE(149)] = 2486,
  [SMALL_STATE(150)] = 2493,
  [SMALL_STATE(151)] = 2500,
  [SMALL_STATE(152)] = 2507,
  [SMALL_STATE(153)] = 2514,
  [SMALL_STATE(154)] = 2521,
  [SMALL_STATE(155)] = 2528,
  [SMALL_STATE(156)] = 2535,
  [SMALL_STATE(157)] = 2542,
  [SMALL_STATE(158)] = 2549,
  [SMALL_STATE(159)] = 2556,
  [SMALL_STATE(160)] = 2561,
  [SMALL_STATE(161)] = 2566,
  [SMALL_STATE(162)] = 2571,
  [SMALL_STATE(163)] = 2578,
  [SMALL_STATE(164)] = 2585,
  [SMALL_STATE(165)] = 2590,
  [SMALL_STATE(166)] = 2597,
  [SMALL_STATE(167)] = 2604,
  [SMALL_STATE(168)] = 2609,
  [SMALL_STATE(169)] = 2614,
  [SMALL_STATE(170)] = 2621,
  [SMALL_STATE(171)] = 2626,
  [SMALL_STATE(172)] = 2633,
  [SMALL_STATE(173)] = 2638,
  [SMALL_STATE(174)] = 2645,
  [SMALL_STATE(175)] = 2650,
  [SMALL_STATE(176)] = 2655,
  [SMALL_STATE(177)] = 2660,
  [SMALL_STATE(178)] = 2667,
  [SMALL_STATE(179)] = 2674,
  [SMALL_STATE(180)] = 2679,
  [SMALL_STATE(181)] = 2686,
  [SMALL_STATE(182)] = 2693,
  [SMALL_STATE(183)] = 2700,
  [SMALL_STATE(184)] = 2707,
  [SMALL_STATE(185)] = 2714,
  [SMALL_STATE(186)] = 2721,
  [SMALL_STATE(187)] = 2726,
  [SMALL_STATE(188)] = 2730,
  [SMALL_STATE(189)] = 2734,
  [SMALL_STATE(190)] = 2738,
  [SMALL_STATE(191)] = 2742,
  [SMALL_STATE(192)] = 2746,
  [SMALL_STATE(193)] = 2750,
  [SMALL_STATE(194)] = 2754,
  [SMALL_STATE(195)] = 2758,
  [SMALL_STATE(196)] = 2762,
  [SMALL_STATE(197)] = 2766,
  [SMALL_STATE(198)] = 2770,
  [SMALL_STATE(199)] = 2774,
  [SMALL_STATE(200)] = 2778,
  [SMALL_STATE(201)] = 2782,
  [SMALL_STATE(202)] = 2786,
  [SMALL_STATE(203)] = 2790,
  [SMALL_STATE(204)] = 2794,
  [SMALL_STATE(205)] = 2798,
  [SMALL_STATE(206)] = 2802,
  [SMALL_STATE(207)] = 2806,
  [SMALL_STATE(208)] = 2810,
  [SMALL_STATE(209)] = 2814,
  [SMALL_STATE(210)] = 2818,
  [SMALL_STATE(211)] = 2822,
  [SMALL_STATE(212)] = 2826,
  [SMALL_STATE(213)] = 2830,
  [SMALL_STATE(214)] = 2834,
  [SMALL_STATE(215)] = 2838,
  [SMALL_STATE(216)] = 2842,
  [SMALL_STATE(217)] = 2846,
  [SMALL_STATE(218)] = 2850,
  [SMALL_STATE(219)] = 2854,
  [SMALL_STATE(220)] = 2858,
  [SMALL_STATE(221)] = 2862,
  [SMALL_STATE(222)] = 2866,
  [SMALL_STATE(223)] = 2870,
  [SMALL_STATE(224)] = 2874,
  [SMALL_STATE(225)] = 2878,
  [SMALL_STATE(226)] = 2882,
  [SMALL_STATE(227)] = 2886,
  [SMALL_STATE(228)] = 2890,
  [SMALL_STATE(229)] = 2894,
  [SMALL_STATE(230)] = 2898,
  [SMALL_STATE(231)] = 2902,
  [SMALL_STATE(232)] = 2906,
  [SMALL_STATE(233)] = 2910,
  [SMALL_STATE(234)] = 2914,
  [SMALL_STATE(235)] = 2918,
  [SMALL_STATE(236)] = 2922,
  [SMALL_STATE(237)] = 2926,
  [SMALL_STATE(238)] = 2930,
  [SMALL_STATE(239)] = 2934,
  [SMALL_STATE(240)] = 2938,
  [SMALL_STATE(241)] = 2942,
  [SMALL_STATE(242)] = 2946,
  [SMALL_STATE(243)] = 2950,
  [SMALL_STATE(244)] = 2954,
  [SMALL_STATE(245)] = 2958,
  [SMALL_STATE(246)] = 2962,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(113),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(231),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(215),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(218),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(227),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(126),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(189),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_content, 1, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(68),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0),
  [104] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_block, 1, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [123] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(142),
  [129] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(124),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0), SHIFT_REPEAT(105),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_block, 1, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 5, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 3, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 4, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 4, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 1, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 4, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 4, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 5, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 5, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 5, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 5, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 6, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 7, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 8, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 6, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 6, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 7, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 2, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 5, 0, 0),
  [187] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [190] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 6, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 1, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 3, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 2, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 2, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0),
  [223] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(199),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [230] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [234] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [238] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 1, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0),
  [256] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(133),
  [259] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0),
  [272] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(122),
  [275] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(112),
  [278] = {.entry = {.count = 1, .reusable = false}}, SHIFT(177),
  [280] = {.entry = {.count = 1, .reusable = false}}, SHIFT(180),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 3, 0, 0),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_value, 1, 0, 0),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [298] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0),
  [303] = {.entry = {.count = 1, .reusable = false}}, SHIFT(198),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 2, 0, 0),
  [311] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(202),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 3, 0, 0),
  [318] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [327] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_content, 2, 0, 0),
  [329] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_content, 2, 0, 0),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [333] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 3, 0, 0),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 1, 0, 0),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [352] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [356] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 1, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 1, 0, 0),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateValue, 6, 0, 0),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [364] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(128),
  [367] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 3, 0, 1),
  [369] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(242),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 2, 0, 0),
  [374] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 2, 0, 0),
  [380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 2, 0, 0),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0),
  [384] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0), SHIFT_REPEAT(136),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_index, 1, 0, 0),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_booleanValue, 1, 0, 0),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [431] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_definition, 2, 0, 0),
  [433] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byteValue, 2, 0, 0),
  [435] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_longValue, 2, 0, 0),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [441] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doubleValue, 3, 0, 0),
  [443] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateTimeValue, 3, 0, 0),
  [445] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeValue, 5, 0, 0),
  [447] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 2, 0, 0),
  [449] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(84),
  [452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0),
  [454] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_extends_block, 2, 0, 0),
  [456] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 3, 0, 1),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [464] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(138),
  [467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [473] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [477] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 5, 0, 0),
  [479] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 4, 0, 0),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [487] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 6, 0, 0),
  [489] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [497] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref_block, 3, 0, 0),
  [499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [503] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 6, 0, 0),
  [505] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 6, 0, 0),
  [507] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_identifier, 6, 0, 0),
  [509] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_version_number, 5, 0, 0),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 7, 0, 0),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [517] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_identifier, 4, 0, 0),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [523] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 5, 0, 0),
  [525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [535] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 5, 0, 0),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [539] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [551] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 6, 0, 0),
  [553] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_block, 3, 0, 0),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 5, 0, 0),
  [565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [569] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dmf_declaration, 2, 0, 0),
  [571] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_declaration, 4, 0, 0),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
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
