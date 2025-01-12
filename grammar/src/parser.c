#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 254
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
  [52] = 36,
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
  [87] = 59,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
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
  [106] = 89,
  [107] = 92,
  [108] = 93,
  [109] = 95,
  [110] = 96,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
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
  [128] = 73,
  [129] = 129,
  [130] = 130,
  [131] = 115,
  [132] = 132,
  [133] = 133,
  [134] = 28,
  [135] = 135,
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
  [146] = 26,
  [147] = 147,
  [148] = 78,
  [149] = 72,
  [150] = 150,
  [151] = 76,
  [152] = 67,
  [153] = 153,
  [154] = 147,
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
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 144,
  [191] = 191,
  [192] = 192,
  [193] = 155,
  [194] = 194,
  [195] = 195,
  [196] = 196,
  [197] = 94,
  [198] = 170,
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
  [223] = 223,
  [224] = 224,
  [225] = 225,
  [226] = 226,
  [227] = 227,
  [228] = 228,
  [229] = 229,
  [230] = 230,
  [231] = 231,
  [232] = 226,
  [233] = 233,
  [234] = 234,
  [235] = 235,
  [236] = 138,
  [237] = 237,
  [238] = 140,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 204,
  [244] = 244,
  [245] = 245,
  [246] = 246,
  [247] = 208,
  [248] = 234,
  [249] = 249,
  [250] = 250,
  [251] = 229,
  [252] = 237,
  [253] = 249,
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
        'd', 12,
        'e', 74,
        'i', 24,
        'l', 86,
        'm', 87,
        'p', 11,
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
      if (lookahead == ';') ADVANCE(209);
      if (lookahead == 'a') ADVANCE(199);
      if (lookahead == '}') ADVANCE(212);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('0' <= lookahead && lookahead <= '5')) ADVANCE(133);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 9:
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 10:
      ADVANCE_MAP(
        '0', 131,
        '3', 126,
        'b', 88,
        'd', 13,
        'i', 79,
        'l', 86,
        's', 118,
        '1', 134,
        '2', 134,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(20);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'm') ADVANCE(48);
      if (lookahead == 'o') ADVANCE(122);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'o') ADVANCE(122);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(55);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(80);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(67);
      if (lookahead == 'r') ADVANCE(90);
      if (lookahead == 'u') ADVANCE(81);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(23);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(77);
      END_STATE();
    case 19:
      if (lookahead == 'b') ADVANCE(68);
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
      if (lookahead == 'e') ADVANCE(18);
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
      if (lookahead == 'f') ADVANCE(17);
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
      if (lookahead == 'k') ADVANCE(14);
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
      if (lookahead == 'p') ADVANCE(15);
      END_STATE();
    case 94:
      if (lookahead == 'p') ADVANCE(15);
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
      if (lookahead == 'u') ADVANCE(19);
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
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(255);
      END_STATE();
    case 134:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(260);
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
        'd', 12,
        'e', 74,
        'i', 24,
        'l', 86,
        'm', 87,
        'p', 11,
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
        ';', 209,
        'D', 256,
        '_', 164,
        'a', 95,
        'e', 75,
        'f', 16,
        'i', 25,
        'p', 11,
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
  [25] = {.lex_state = 8},
  [26] = {.lex_state = 148},
  [27] = {.lex_state = 148},
  [28] = {.lex_state = 148},
  [29] = {.lex_state = 8},
  [30] = {.lex_state = 148},
  [31] = {.lex_state = 148},
  [32] = {.lex_state = 148},
  [33] = {.lex_state = 8},
  [34] = {.lex_state = 148},
  [35] = {.lex_state = 148},
  [36] = {.lex_state = 10},
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
  [48] = {.lex_state = 148},
  [49] = {.lex_state = 148},
  [50] = {.lex_state = 148},
  [51] = {.lex_state = 148},
  [52] = {.lex_state = 10},
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
  [66] = {.lex_state = 148},
  [67] = {.lex_state = 148},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 6},
  [71] = {.lex_state = 6},
  [72] = {.lex_state = 148},
  [73] = {.lex_state = 148},
  [74] = {.lex_state = 148},
  [75] = {.lex_state = 6},
  [76] = {.lex_state = 148},
  [77] = {.lex_state = 8},
  [78] = {.lex_state = 148},
  [79] = {.lex_state = 148},
  [80] = {.lex_state = 8},
  [81] = {.lex_state = 148},
  [82] = {.lex_state = 8},
  [83] = {.lex_state = 148},
  [84] = {.lex_state = 6},
  [85] = {.lex_state = 148},
  [86] = {.lex_state = 148},
  [87] = {.lex_state = 8},
  [88] = {.lex_state = 148},
  [89] = {.lex_state = 6},
  [90] = {.lex_state = 3},
  [91] = {.lex_state = 4},
  [92] = {.lex_state = 3},
  [93] = {.lex_state = 4},
  [94] = {.lex_state = 148},
  [95] = {.lex_state = 3},
  [96] = {.lex_state = 4},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 6},
  [107] = {.lex_state = 3},
  [108] = {.lex_state = 4},
  [109] = {.lex_state = 3},
  [110] = {.lex_state = 4},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 148},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 121},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 8},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 148},
  [123] = {.lex_state = 6},
  [124] = {.lex_state = 8},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 8},
  [128] = {.lex_state = 8},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 6},
  [131] = {.lex_state = 121},
  [132] = {.lex_state = 8},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 6},
  [135] = {.lex_state = 148},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 148},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 4},
  [142] = {.lex_state = 6},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 6},
  [147] = {.lex_state = 4},
  [148] = {.lex_state = 6},
  [149] = {.lex_state = 6},
  [150] = {.lex_state = 148},
  [151] = {.lex_state = 6},
  [152] = {.lex_state = 6},
  [153] = {.lex_state = 3},
  [154] = {.lex_state = 3},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 148},
  [158] = {.lex_state = 148},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 148},
  [165] = {.lex_state = 148},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 6},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 148},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 5},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 148},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 2},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 2},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 6},
  [198] = {.lex_state = 6},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 148},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 6},
  [203] = {.lex_state = 6},
  [204] = {.lex_state = 148},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 2},
  [207] = {.lex_state = 2},
  [208] = {.lex_state = 6},
  [209] = {.lex_state = 2},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 7},
  [212] = {.lex_state = 148},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 2},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 8},
  [219] = {.lex_state = 10},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 2},
  [222] = {.lex_state = 8},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 148},
  [225] = {.lex_state = 6},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 6},
  [228] = {.lex_state = 6},
  [229] = {.lex_state = 148},
  [230] = {.lex_state = 6},
  [231] = {.lex_state = 6},
  [232] = {.lex_state = 2},
  [233] = {.lex_state = 6},
  [234] = {.lex_state = 6},
  [235] = {.lex_state = 6},
  [236] = {.lex_state = 6},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 6},
  [239] = {.lex_state = 2},
  [240] = {.lex_state = 6},
  [241] = {.lex_state = 6},
  [242] = {.lex_state = 2},
  [243] = {.lex_state = 148},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 6},
  [247] = {.lex_state = 6},
  [248] = {.lex_state = 6},
  [249] = {.lex_state = 0},
  [250] = {.lex_state = 129},
  [251] = {.lex_state = 148},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 0},
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
    [sym_source_file] = STATE(210),
    [sym_dmf_declaration] = STATE(209),
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(27), 1,
      sym_comment_block,
    STATE(216), 1,
      sym_model_content,
    STATE(8), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(34), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    STATE(42), 5,
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(27), 1,
      sym_comment_block,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(42), 5,
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(27), 1,
      sym_comment_block,
    STATE(41), 1,
      sym__right_brace,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(42), 5,
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(27), 1,
      sym_comment_block,
    STATE(47), 1,
      sym__right_brace,
    STATE(4), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(42), 5,
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
    STATE(66), 1,
      sym__right_paren,
    STATE(89), 1,
      aux_sym_reftype_repeat1,
    STATE(103), 1,
      sym_param_definition,
    STATE(149), 1,
      aux_sym_package_string_repeat1,
    STATE(236), 1,
      sym_package_string,
    STATE(231), 2,
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(27), 1,
      sym_comment_block,
    STATE(215), 1,
      sym_model_content,
    STATE(8), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(42), 5,
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(27), 1,
      sym_comment_block,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(42), 5,
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
    STATE(89), 1,
      aux_sym_reftype_repeat1,
    STATE(149), 1,
      aux_sym_package_string_repeat1,
    STATE(236), 1,
      sym_package_string,
    STATE(241), 2,
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
    STATE(117), 1,
      sym_integerValue,
    STATE(156), 1,
      sym_dateValue,
    STATE(168), 1,
      sym_primitive_value,
    ACTIONS(62), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(169), 6,
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
    STATE(89), 1,
      aux_sym_reftype_repeat1,
    STATE(149), 1,
      aux_sym_package_string_repeat1,
    STATE(182), 1,
      sym_param_definition,
    STATE(236), 1,
      sym_package_string,
    STATE(231), 2,
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(79), 1,
      sym_comment_block,
    STATE(195), 1,
      sym_identifier_statement,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(43), 1,
      sym__right_brace,
    STATE(79), 1,
      sym_comment_block,
    STATE(19), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    ACTIONS(78), 1,
      anon_sym_identifier,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(79), 1,
      sym_comment_block,
    STATE(187), 1,
      sym_identifier_statement,
    STATE(17), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    ACTIONS(80), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(43), 1,
      sym__right_brace,
    STATE(79), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(79), 1,
      sym_comment_block,
    STATE(166), 1,
      sym_identifier_statement,
    STATE(12), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    ACTIONS(78), 1,
      anon_sym_identifier,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(79), 1,
      sym_comment_block,
    STATE(166), 1,
      sym_identifier_statement,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    ACTIONS(82), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(51), 1,
      sym__right_brace,
    STATE(79), 1,
      sym_comment_block,
    STATE(21), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    ACTIONS(82), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(51), 1,
      sym__right_brace,
    STATE(79), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [683] = 9,
    ACTIONS(84), 1,
      anon_sym_arg,
    ACTIONS(87), 1,
      anon_sym_ref,
    ACTIONS(90), 1,
      anon_sym_func,
    ACTIONS(95), 1,
      sym_comment,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(79), 1,
      sym_comment_block,
    ACTIONS(93), 2,
      anon_sym_identifier,
      anon_sym_RBRACE,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    ACTIONS(98), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(55), 1,
      sym__right_brace,
    STATE(79), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(79), 1,
      sym_comment_block,
    STATE(195), 1,
      sym_identifier_statement,
    STATE(23), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    ACTIONS(78), 1,
      anon_sym_identifier,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(79), 1,
      sym_comment_block,
    STATE(163), 1,
      sym_identifier_statement,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
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
    ACTIONS(100), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(58), 1,
      sym__right_brace,
    STATE(79), 1,
      sym_comment_block,
    STATE(15), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(86), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [851] = 9,
    ACTIONS(102), 1,
      anon_sym_arg,
    ACTIONS(104), 1,
      sym_identifier,
    ACTIONS(106), 1,
      sym_comment,
    ACTIONS(108), 1,
      anon_sym_RBRACE,
    STATE(45), 1,
      sym__right_brace,
    STATE(146), 1,
      aux_sym_comment_block_repeat1,
    STATE(233), 1,
      sym_comment_block,
    STATE(33), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(132), 2,
      sym_arg_block,
      sym_enum_constant,
  [881] = 3,
    ACTIONS(112), 1,
      sym_comment,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(110), 9,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_expand,
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
    ACTIONS(114), 1,
      sym_expand,
    STATE(40), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [925] = 3,
    ACTIONS(118), 1,
      sym_comment,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(116), 9,
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
    ACTIONS(102), 1,
      anon_sym_arg,
    ACTIONS(104), 1,
      sym_identifier,
    ACTIONS(106), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_RBRACE,
    STATE(37), 1,
      sym__right_brace,
    STATE(146), 1,
      aux_sym_comment_block_repeat1,
    STATE(233), 1,
      sym_comment_block,
    STATE(25), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(132), 2,
      sym_arg_block,
      sym_enum_constant,
  [973] = 6,
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
  [996] = 6,
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
    STATE(46), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [1019] = 3,
    ACTIONS(123), 1,
      anon_sym_import,
    STATE(32), 2,
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
  [1036] = 8,
    ACTIONS(128), 1,
      anon_sym_arg,
    ACTIONS(131), 1,
      sym_identifier,
    ACTIONS(134), 1,
      sym_comment,
    ACTIONS(137), 1,
      anon_sym_RBRACE,
    STATE(146), 1,
      aux_sym_comment_block_repeat1,
    STATE(233), 1,
      sym_comment_block,
    STATE(33), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(132), 2,
      sym_arg_block,
      sym_enum_constant,
  [1063] = 3,
    ACTIONS(5), 1,
      anon_sym_import,
    STATE(32), 2,
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
  [1080] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(141), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(49), 1,
      sym__right_brace,
    STATE(135), 1,
      sym_func_block,
    STATE(200), 1,
      sym_comment_block,
    STATE(60), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1106] = 3,
    ACTIONS(54), 1,
      sym_date,
    STATE(248), 1,
      sym_primitive_type,
    ACTIONS(143), 7,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_string,
      sym_boolean,
  [1122] = 1,
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
  [1134] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(141), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(49), 1,
      sym__right_brace,
    STATE(135), 1,
      sym_func_block,
    STATE(200), 1,
      sym_comment_block,
    STATE(50), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1160] = 1,
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
  [1172] = 1,
    ACTIONS(149), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1184] = 1,
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
  [1196] = 1,
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
  [1208] = 1,
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
  [1220] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(157), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(39), 1,
      sym__right_brace,
    STATE(135), 1,
      sym_func_block,
    STATE(200), 1,
      sym_comment_block,
    STATE(35), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1246] = 1,
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
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(54), 1,
      sym__right_brace,
    STATE(135), 1,
      sym_func_block,
    STATE(200), 1,
      sym_comment_block,
    STATE(60), 2,
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
  [1344] = 3,
    ACTIONS(54), 1,
      sym_date,
    STATE(234), 1,
      sym_primitive_type,
    ACTIONS(143), 7,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_string,
      sym_boolean,
  [1360] = 1,
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
  [1372] = 1,
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
  [1384] = 1,
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
  [1396] = 1,
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
  [1408] = 1,
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
  [1420] = 1,
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
  [1432] = 3,
    ACTIONS(187), 1,
      anon_sym_SEMI,
    STATE(73), 1,
      sym__semicolon,
    ACTIONS(185), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1447] = 7,
    ACTIONS(189), 1,
      anon_sym_func,
    ACTIONS(192), 1,
      sym_comment,
    ACTIONS(195), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym_comment_block_repeat1,
    STATE(135), 1,
      sym_func_block,
    STATE(200), 1,
      sym_comment_block,
    STATE(60), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1470] = 1,
    ACTIONS(197), 8,
      anon_sym_import,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1481] = 1,
    ACTIONS(199), 8,
      anon_sym_import,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1492] = 3,
    ACTIONS(203), 1,
      anon_sym_SEMI,
    STATE(74), 1,
      sym__semicolon,
    ACTIONS(201), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1507] = 3,
    ACTIONS(207), 1,
      anon_sym_SEMI,
    STATE(85), 1,
      sym__semicolon,
    ACTIONS(205), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1522] = 3,
    ACTIONS(211), 1,
      anon_sym_SEMI,
    STATE(83), 1,
      sym__semicolon,
    ACTIONS(209), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1537] = 3,
    ACTIONS(215), 1,
      anon_sym_SEMI,
    STATE(81), 1,
      sym__semicolon,
    ACTIONS(213), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1552] = 3,
    ACTIONS(219), 1,
      sym_dot,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(217), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1565] = 6,
    ACTIONS(222), 1,
      anon_sym_extends,
    ACTIONS(224), 1,
      anon_sym_implements,
    ACTIONS(226), 1,
      anon_sym_LBRACE,
    STATE(24), 1,
      sym__left_brace,
    STATE(114), 1,
      sym_extends_block,
    STATE(196), 1,
      sym_implements_block,
  [1584] = 6,
    ACTIONS(222), 1,
      anon_sym_extends,
    ACTIONS(224), 1,
      anon_sym_implements,
    ACTIONS(228), 1,
      anon_sym_LBRACE,
    STATE(14), 1,
      sym__left_brace,
    STATE(111), 1,
      sym_extends_block,
    STATE(199), 1,
      sym_implements_block,
  [1603] = 6,
    ACTIONS(230), 1,
      sym_identifier,
    ACTIONS(232), 1,
      sym_dot,
    STATE(72), 1,
      aux_sym_package_string_repeat1,
    STATE(106), 1,
      aux_sym_reftype_repeat1,
    STATE(138), 1,
      sym_package_string,
    STATE(174), 1,
      sym_reftype,
  [1622] = 6,
    ACTIONS(230), 1,
      sym_identifier,
    ACTIONS(232), 1,
      sym_dot,
    STATE(72), 1,
      aux_sym_package_string_repeat1,
    STATE(106), 1,
      aux_sym_reftype_repeat1,
    STATE(138), 1,
      sym_package_string,
    STATE(173), 1,
      sym_reftype,
  [1641] = 3,
    ACTIONS(236), 1,
      sym_dot,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(234), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1654] = 1,
    ACTIONS(238), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1663] = 1,
    ACTIONS(240), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1672] = 6,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(242), 1,
      sym_identifier,
    STATE(89), 1,
      aux_sym_reftype_repeat1,
    STATE(149), 1,
      aux_sym_package_string_repeat1,
    STATE(236), 1,
      sym_package_string,
    STATE(240), 1,
      sym_reftype,
  [1691] = 3,
    ACTIONS(236), 1,
      sym_dot,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(244), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1704] = 4,
    ACTIONS(250), 1,
      anon_sym_SEMI,
    STATE(118), 1,
      sym__semicolon,
    ACTIONS(246), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(248), 2,
      sym_comment,
      anon_sym_RBRACE,
  [1719] = 3,
    ACTIONS(236), 1,
      sym_dot,
    STATE(76), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(234), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1732] = 4,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    STATE(88), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [1747] = 4,
    ACTIONS(256), 1,
      anon_sym_SEMI,
    STATE(124), 1,
      sym__semicolon,
    ACTIONS(252), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(254), 2,
      sym_comment,
      anon_sym_RBRACE,
  [1762] = 1,
    ACTIONS(209), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1771] = 4,
    ACTIONS(262), 1,
      anon_sym_SEMI,
    STATE(127), 1,
      sym__semicolon,
    ACTIONS(258), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(260), 2,
      sym_comment,
      anon_sym_RBRACE,
  [1786] = 1,
    ACTIONS(205), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1795] = 6,
    ACTIONS(230), 1,
      sym_identifier,
    ACTIONS(232), 1,
      sym_dot,
    STATE(72), 1,
      aux_sym_package_string_repeat1,
    STATE(106), 1,
      aux_sym_reftype_repeat1,
    STATE(125), 1,
      sym_reftype,
    STATE(138), 1,
      sym_package_string,
  [1814] = 1,
    ACTIONS(264), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1823] = 1,
    ACTIONS(266), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1832] = 4,
    ACTIONS(270), 1,
      anon_sym_SEMI,
    STATE(128), 1,
      sym__semicolon,
    ACTIONS(185), 2,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(268), 2,
      anon_sym_arg,
      sym_identifier,
  [1847] = 1,
    ACTIONS(272), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1856] = 5,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(242), 1,
      sym_identifier,
    STATE(142), 1,
      aux_sym_reftype_repeat1,
    STATE(149), 1,
      aux_sym_package_string_repeat1,
    STATE(238), 1,
      sym_package_string,
  [1872] = 5,
    ACTIONS(274), 1,
      anon_sym_DQUOTE,
    ACTIONS(276), 1,
      sym_string_content_double_quote,
    ACTIONS(279), 1,
      anon_sym_BSLASH,
    STATE(90), 1,
      aux_sym_stringValue_repeat1,
    STATE(153), 1,
      sym_escape_sequence,
  [1888] = 5,
    ACTIONS(282), 1,
      anon_sym_SQUOTE,
    ACTIONS(284), 1,
      sym_string_content_single_quote,
    ACTIONS(287), 1,
      anon_sym_BSLASH,
    STATE(91), 1,
      aux_sym_stringValue_repeat2,
    STATE(141), 1,
      sym_escape_sequence,
  [1904] = 5,
    ACTIONS(290), 1,
      anon_sym_DQUOTE,
    ACTIONS(292), 1,
      sym_string_content_double_quote,
    ACTIONS(294), 1,
      anon_sym_BSLASH,
    STATE(95), 1,
      aux_sym_stringValue_repeat1,
    STATE(153), 1,
      sym_escape_sequence,
  [1920] = 5,
    ACTIONS(290), 1,
      anon_sym_SQUOTE,
    ACTIONS(296), 1,
      sym_string_content_single_quote,
    ACTIONS(298), 1,
      anon_sym_BSLASH,
    STATE(96), 1,
      aux_sym_stringValue_repeat2,
    STATE(141), 1,
      sym_escape_sequence,
  [1936] = 1,
    ACTIONS(217), 5,
      anon_sym_from,
      anon_sym_implements,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1944] = 5,
    ACTIONS(292), 1,
      sym_string_content_double_quote,
    ACTIONS(294), 1,
      anon_sym_BSLASH,
    ACTIONS(300), 1,
      anon_sym_DQUOTE,
    STATE(90), 1,
      aux_sym_stringValue_repeat1,
    STATE(153), 1,
      sym_escape_sequence,
  [1960] = 5,
    ACTIONS(296), 1,
      sym_string_content_single_quote,
    ACTIONS(298), 1,
      anon_sym_BSLASH,
    ACTIONS(300), 1,
      anon_sym_SQUOTE,
    STATE(91), 1,
      aux_sym_stringValue_repeat2,
    STATE(141), 1,
      sym_escape_sequence,
  [1976] = 2,
    ACTIONS(302), 1,
      anon_sym__,
    ACTIONS(304), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [1986] = 5,
    ACTIONS(306), 1,
      anon_sym_COMMA,
    ACTIONS(308), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(77), 1,
      sym__right_paren,
    STATE(100), 1,
      aux_sym_enum_constant_repeat1,
  [2002] = 5,
    ACTIONS(310), 1,
      anon_sym_COMMA,
    ACTIONS(312), 1,
      anon_sym_RPAREN,
    STATE(102), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(143), 1,
      sym__right_paren,
    STATE(235), 1,
      sym__comma,
  [2018] = 5,
    ACTIONS(306), 1,
      anon_sym_COMMA,
    ACTIONS(314), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(80), 1,
      sym__right_paren,
    STATE(119), 1,
      aux_sym_enum_constant_repeat1,
  [2034] = 5,
    ACTIONS(306), 1,
      anon_sym_COMMA,
    ACTIONS(314), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(80), 1,
      sym__right_paren,
    STATE(104), 1,
      aux_sym_enum_constant_repeat1,
  [2050] = 5,
    ACTIONS(310), 1,
      anon_sym_COMMA,
    ACTIONS(316), 1,
      anon_sym_RPAREN,
    STATE(121), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(136), 1,
      sym__right_paren,
    STATE(235), 1,
      sym__comma,
  [2066] = 5,
    ACTIONS(318), 1,
      anon_sym_COMMA,
    ACTIONS(320), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(65), 1,
      sym__right_paren,
    STATE(105), 1,
      aux_sym_func_block_repeat1,
  [2082] = 5,
    ACTIONS(306), 1,
      anon_sym_COMMA,
    ACTIONS(322), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(82), 1,
      sym__right_paren,
    STATE(119), 1,
      aux_sym_enum_constant_repeat1,
  [2098] = 5,
    ACTIONS(318), 1,
      anon_sym_COMMA,
    ACTIONS(324), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(64), 1,
      sym__right_paren,
    STATE(126), 1,
      aux_sym_func_block_repeat1,
  [2114] = 5,
    ACTIONS(230), 1,
      sym_identifier,
    ACTIONS(232), 1,
      sym_dot,
    STATE(72), 1,
      aux_sym_package_string_repeat1,
    STATE(140), 1,
      sym_package_string,
    STATE(142), 1,
      aux_sym_reftype_repeat1,
  [2130] = 5,
    ACTIONS(292), 1,
      sym_string_content_double_quote,
    ACTIONS(294), 1,
      anon_sym_BSLASH,
    ACTIONS(326), 1,
      anon_sym_DQUOTE,
    STATE(109), 1,
      aux_sym_stringValue_repeat1,
    STATE(153), 1,
      sym_escape_sequence,
  [2146] = 5,
    ACTIONS(296), 1,
      sym_string_content_single_quote,
    ACTIONS(298), 1,
      anon_sym_BSLASH,
    ACTIONS(326), 1,
      anon_sym_SQUOTE,
    STATE(110), 1,
      aux_sym_stringValue_repeat2,
    STATE(141), 1,
      sym_escape_sequence,
  [2162] = 5,
    ACTIONS(292), 1,
      sym_string_content_double_quote,
    ACTIONS(294), 1,
      anon_sym_BSLASH,
    ACTIONS(328), 1,
      anon_sym_DQUOTE,
    STATE(90), 1,
      aux_sym_stringValue_repeat1,
    STATE(153), 1,
      sym_escape_sequence,
  [2178] = 5,
    ACTIONS(296), 1,
      sym_string_content_single_quote,
    ACTIONS(298), 1,
      anon_sym_BSLASH,
    ACTIONS(328), 1,
      anon_sym_SQUOTE,
    STATE(91), 1,
      aux_sym_stringValue_repeat2,
    STATE(141), 1,
      sym_escape_sequence,
  [2194] = 4,
    ACTIONS(224), 1,
      anon_sym_implements,
    ACTIONS(330), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym__left_brace,
    STATE(159), 1,
      sym_implements_block,
  [2207] = 4,
    ACTIONS(332), 1,
      anon_sym__,
    ACTIONS(334), 1,
      sym_number,
    STATE(98), 1,
      sym_enum_index,
    STATE(191), 1,
      sym_integerValue,
  [2220] = 4,
    ACTIONS(336), 1,
      anon_sym_LPAREN,
    ACTIONS(338), 1,
      sym__new_line,
    STATE(201), 1,
      sym__left_paren,
    STATE(214), 1,
      sym_model_identifier,
  [2233] = 4,
    ACTIONS(224), 1,
      anon_sym_implements,
    ACTIONS(340), 1,
      anon_sym_LBRACE,
    STATE(13), 1,
      sym__left_brace,
    STATE(183), 1,
      sym_implements_block,
  [2246] = 1,
    ACTIONS(342), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2253] = 1,
    ACTIONS(344), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [2260] = 3,
    ACTIONS(346), 1,
      sym_dot,
    ACTIONS(350), 1,
      anon_sym_L,
    ACTIONS(348), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2271] = 2,
    ACTIONS(252), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(254), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2280] = 4,
    ACTIONS(352), 1,
      anon_sym_COMMA,
    ACTIONS(355), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(119), 1,
      aux_sym_enum_constant_repeat1,
  [2293] = 4,
    ACTIONS(357), 1,
      anon_sym_COMMA,
    ACTIONS(359), 1,
      anon_sym_LBRACE,
    STATE(70), 1,
      sym__comma,
    STATE(133), 1,
      aux_sym_implements_block_repeat1,
  [2306] = 4,
    ACTIONS(361), 1,
      anon_sym_COMMA,
    ACTIONS(364), 1,
      anon_sym_RPAREN,
    STATE(121), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(235), 1,
      sym__comma,
  [2319] = 4,
    ACTIONS(332), 1,
      anon_sym__,
    ACTIONS(334), 1,
      sym_number,
    STATE(101), 1,
      sym_enum_index,
    STATE(191), 1,
      sym_integerValue,
  [2332] = 4,
    ACTIONS(230), 1,
      sym_identifier,
    ACTIONS(236), 1,
      sym_dot,
    STATE(72), 1,
      aux_sym_package_string_repeat1,
    STATE(212), 1,
      sym_package_string,
  [2345] = 2,
    ACTIONS(258), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(260), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2354] = 4,
    ACTIONS(357), 1,
      anon_sym_COMMA,
    ACTIONS(366), 1,
      anon_sym_LBRACE,
    STATE(70), 1,
      sym__comma,
    STATE(120), 1,
      aux_sym_implements_block_repeat1,
  [2367] = 4,
    ACTIONS(368), 1,
      anon_sym_COMMA,
    ACTIONS(371), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(126), 1,
      aux_sym_func_block_repeat1,
  [2380] = 2,
    ACTIONS(373), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(375), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2389] = 2,
    ACTIONS(238), 2,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(377), 2,
      anon_sym_arg,
      sym_identifier,
  [2398] = 4,
    ACTIONS(224), 1,
      anon_sym_implements,
    ACTIONS(379), 1,
      anon_sym_LBRACE,
    STATE(44), 1,
      sym__left_brace,
    STATE(161), 1,
      sym_implements_block,
  [2411] = 4,
    ACTIONS(230), 1,
      sym_identifier,
    ACTIONS(236), 1,
      sym_dot,
    STATE(72), 1,
      aux_sym_package_string_repeat1,
    STATE(180), 1,
      sym_package_string,
  [2424] = 1,
    ACTIONS(381), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2431] = 2,
    ACTIONS(383), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(385), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2440] = 4,
    ACTIONS(387), 1,
      anon_sym_COMMA,
    ACTIONS(390), 1,
      anon_sym_LBRACE,
    STATE(70), 1,
      sym__comma,
    STATE(133), 1,
      aux_sym_implements_block_repeat1,
  [2453] = 3,
    ACTIONS(116), 1,
      sym_identifier,
    ACTIONS(392), 1,
      sym_comment,
    STATE(134), 1,
      aux_sym_comment_block_repeat1,
  [2463] = 1,
    ACTIONS(395), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2469] = 3,
    ACTIONS(397), 1,
      anon_sym_SEMI,
    ACTIONS(399), 1,
      anon_sym_RBRACE,
    STATE(205), 1,
      sym__semicolon,
  [2479] = 3,
    ACTIONS(401), 1,
      anon_sym_version,
    ACTIONS(403), 1,
      anon_sym_RPAREN,
    STATE(221), 1,
      sym__right_paren,
  [2489] = 1,
    ACTIONS(405), 3,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2495] = 3,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    STATE(137), 1,
      sym_stringValue,
  [2505] = 1,
    ACTIONS(407), 3,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2511] = 2,
    ACTIONS(411), 1,
      sym_string_content_single_quote,
    ACTIONS(409), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2519] = 3,
    ACTIONS(413), 1,
      sym_identifier,
    ACTIONS(415), 1,
      sym_dot,
    STATE(142), 1,
      aux_sym_reftype_repeat1,
  [2529] = 3,
    ACTIONS(418), 1,
      anon_sym_SEMI,
    ACTIONS(420), 1,
      anon_sym_RBRACE,
    STATE(223), 1,
      sym__semicolon,
  [2539] = 1,
    ACTIONS(422), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2545] = 1,
    ACTIONS(424), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_T,
  [2551] = 3,
    ACTIONS(110), 1,
      sym_identifier,
    ACTIONS(426), 1,
      sym_comment,
    STATE(134), 1,
      aux_sym_comment_block_repeat1,
  [2561] = 2,
    ACTIONS(430), 1,
      sym_string_content_single_quote,
    ACTIONS(428), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2569] = 3,
    ACTIONS(234), 1,
      sym_identifier,
    ACTIONS(432), 1,
      sym_dot,
    STATE(151), 1,
      aux_sym_package_string_repeat1,
  [2579] = 3,
    ACTIONS(234), 1,
      sym_identifier,
    ACTIONS(432), 1,
      sym_dot,
    STATE(152), 1,
      aux_sym_package_string_repeat1,
  [2589] = 3,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    STATE(244), 1,
      sym_stringValue,
  [2599] = 3,
    ACTIONS(244), 1,
      sym_identifier,
    ACTIONS(432), 1,
      sym_dot,
    STATE(152), 1,
      aux_sym_package_string_repeat1,
  [2609] = 3,
    ACTIONS(217), 1,
      sym_identifier,
    ACTIONS(434), 1,
      sym_dot,
    STATE(152), 1,
      aux_sym_package_string_repeat1,
  [2619] = 2,
    ACTIONS(439), 1,
      sym_string_content_double_quote,
    ACTIONS(437), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2627] = 2,
    ACTIONS(430), 1,
      sym_string_content_double_quote,
    ACTIONS(428), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2635] = 1,
    ACTIONS(441), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2641] = 2,
    ACTIONS(443), 1,
      anon_sym_T,
    ACTIONS(348), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2649] = 1,
    ACTIONS(445), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2655] = 3,
    ACTIONS(447), 1,
      anon_sym_DQUOTE,
    ACTIONS(449), 1,
      anon_sym_SQUOTE,
    STATE(113), 1,
      sym_stringValue,
  [2665] = 2,
    ACTIONS(451), 1,
      anon_sym_LBRACE,
    STATE(22), 1,
      sym__left_brace,
  [2672] = 2,
    ACTIONS(453), 1,
      anon_sym_model,
    STATE(207), 1,
      sym_model_declaration,
  [2679] = 2,
    ACTIONS(455), 1,
      anon_sym_LBRACE,
    STATE(38), 1,
      sym__left_brace,
  [2686] = 2,
    ACTIONS(457), 1,
      anon_sym_LPAREN,
    STATE(122), 1,
      sym__left_paren,
  [2693] = 2,
    ACTIONS(459), 1,
      anon_sym_RBRACE,
    STATE(57), 1,
      sym__right_brace,
  [2700] = 2,
    ACTIONS(461), 1,
      sym_number,
    STATE(239), 1,
      sym_version_number,
  [2707] = 2,
    ACTIONS(463), 1,
      sym_number,
    STATE(172), 1,
      sym_version_number,
  [2714] = 2,
    ACTIONS(465), 1,
      anon_sym_RBRACE,
    STATE(53), 1,
      sym__right_brace,
  [2721] = 1,
    ACTIONS(467), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2726] = 1,
    ACTIONS(355), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2731] = 1,
    ACTIONS(348), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2736] = 2,
    ACTIONS(469), 1,
      sym_identifier,
    ACTIONS(472), 1,
      sym_dot,
  [2743] = 1,
    ACTIONS(364), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2748] = 2,
    ACTIONS(474), 1,
      anon_sym_RPAREN,
    STATE(206), 1,
      sym__right_paren,
  [2755] = 1,
    ACTIONS(476), 2,
      anon_sym_implements,
      anon_sym_LBRACE,
  [2760] = 1,
    ACTIONS(390), 2,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2765] = 1,
    ACTIONS(478), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2770] = 1,
    ACTIONS(480), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2775] = 2,
    ACTIONS(334), 1,
      sym_number,
    STATE(185), 1,
      sym_integerValue,
  [2782] = 1,
    ACTIONS(482), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2787] = 2,
    ACTIONS(484), 1,
      aux_sym_timeValue_token1,
    STATE(186), 1,
      sym_timeValue,
  [2794] = 2,
    ACTIONS(486), 1,
      anon_sym_LBRACE,
    STATE(5), 1,
      sym__left_brace,
  [2801] = 2,
    ACTIONS(488), 1,
      anon_sym_LPAREN,
    STATE(203), 1,
      sym__left_paren,
  [2808] = 1,
    ACTIONS(371), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2813] = 2,
    ACTIONS(490), 1,
      anon_sym_LBRACE,
    STATE(18), 1,
      sym__left_brace,
  [2820] = 2,
    ACTIONS(461), 1,
      sym_number,
    STATE(242), 1,
      sym_version_number,
  [2827] = 1,
    ACTIONS(492), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2832] = 1,
    ACTIONS(494), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2837] = 2,
    ACTIONS(496), 1,
      anon_sym_RBRACE,
    STATE(48), 1,
      sym__right_brace,
  [2844] = 2,
    ACTIONS(498), 1,
      anon_sym_LPAREN,
    STATE(6), 1,
      sym__left_paren,
  [2851] = 1,
    ACTIONS(500), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2856] = 2,
    ACTIONS(422), 1,
      sym__new_line,
    ACTIONS(502), 1,
      anon_sym_LPAREN,
  [2863] = 1,
    ACTIONS(504), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2868] = 2,
    ACTIONS(506), 1,
      anon_sym_LBRACE,
    STATE(29), 1,
      sym__left_brace,
  [2875] = 2,
    ACTIONS(441), 1,
      sym__new_line,
    ACTIONS(508), 1,
      anon_sym_LPAREN,
  [2882] = 2,
    ACTIONS(510), 1,
      anon_sym_LPAREN,
    STATE(112), 1,
      sym__left_paren,
  [2889] = 2,
    ACTIONS(512), 1,
      anon_sym_RBRACE,
    STATE(56), 1,
      sym__right_brace,
  [2896] = 2,
    ACTIONS(340), 1,
      anon_sym_LBRACE,
    STATE(13), 1,
      sym__left_brace,
  [2903] = 1,
    ACTIONS(217), 2,
      sym_identifier,
      sym_dot,
  [2908] = 2,
    ACTIONS(472), 1,
      sym_dot,
    ACTIONS(514), 1,
      sym_identifier,
  [2915] = 2,
    ACTIONS(330), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym__left_brace,
  [2922] = 2,
    ACTIONS(76), 1,
      anon_sym_func,
    STATE(157), 1,
      sym_func_block,
  [2929] = 1,
    ACTIONS(517), 1,
      anon_sym_model,
  [2933] = 1,
    ACTIONS(519), 1,
      sym_identifier,
  [2937] = 1,
    ACTIONS(521), 1,
      sym_identifier,
  [2941] = 1,
    ACTIONS(523), 1,
      sym_number,
  [2945] = 1,
    ACTIONS(525), 1,
      anon_sym_RBRACE,
  [2949] = 1,
    ACTIONS(527), 1,
      sym__new_line,
  [2953] = 1,
    ACTIONS(529), 1,
      sym__new_line,
  [2957] = 1,
    ACTIONS(531), 1,
      sym_identifier,
  [2961] = 1,
    ACTIONS(533), 1,
      sym__new_line,
  [2965] = 1,
    ACTIONS(535), 1,
      ts_builtin_sym_end,
  [2969] = 1,
    ACTIONS(537), 1,
      aux_sym_dateValue_token2,
  [2973] = 1,
    ACTIONS(539), 1,
      anon_sym_from,
  [2977] = 1,
    ACTIONS(541), 1,
      anon_sym_COLON,
  [2981] = 1,
    ACTIONS(543), 1,
      sym__new_line,
  [2985] = 1,
    ACTIONS(545), 1,
      ts_builtin_sym_end,
  [2989] = 1,
    ACTIONS(547), 1,
      ts_builtin_sym_end,
  [2993] = 1,
    ACTIONS(549), 1,
      anon_sym_DASH,
  [2997] = 1,
    ACTIONS(551), 1,
      aux_sym_timeValue_token2,
  [3001] = 1,
    ACTIONS(553), 1,
      aux_sym_dateValue_token3,
  [3005] = 1,
    ACTIONS(555), 1,
      anon_sym_COLON,
  [3009] = 1,
    ACTIONS(557), 1,
      sym__new_line,
  [3013] = 1,
    ACTIONS(559), 1,
      aux_sym_timeValue_token2,
  [3017] = 1,
    ACTIONS(399), 1,
      anon_sym_RBRACE,
  [3021] = 1,
    ACTIONS(561), 1,
      sym_number,
  [3025] = 1,
    ACTIONS(563), 1,
      aux_sym_dateValue_token1,
  [3029] = 1,
    ACTIONS(565), 1,
      anon_sym_RPAREN,
  [3033] = 1,
    ACTIONS(567), 1,
      sym_identifier,
  [3037] = 1,
    ACTIONS(569), 1,
      sym_identifier,
  [3041] = 1,
    ACTIONS(571), 1,
      sym_number,
  [3045] = 1,
    ACTIONS(573), 1,
      sym_identifier,
  [3049] = 1,
    ACTIONS(575), 1,
      sym_identifier,
  [3053] = 1,
    ACTIONS(565), 1,
      sym__new_line,
  [3057] = 1,
    ACTIONS(577), 1,
      sym_identifier,
  [3061] = 1,
    ACTIONS(579), 1,
      sym_identifier,
  [3065] = 1,
    ACTIONS(581), 1,
      sym_identifier,
  [3069] = 1,
    ACTIONS(405), 1,
      sym_identifier,
  [3073] = 1,
    ACTIONS(583), 1,
      sym_dot,
  [3077] = 1,
    ACTIONS(407), 1,
      sym_identifier,
  [3081] = 1,
    ACTIONS(585), 1,
      sym__new_line,
  [3085] = 1,
    ACTIONS(587), 1,
      sym_identifier,
  [3089] = 1,
    ACTIONS(589), 1,
      sym_identifier,
  [3093] = 1,
    ACTIONS(591), 1,
      sym__new_line,
  [3097] = 1,
    ACTIONS(593), 1,
      sym_number,
  [3101] = 1,
    ACTIONS(595), 1,
      anon_sym_version,
  [3105] = 1,
    ACTIONS(597), 1,
      anon_sym_DASH,
  [3109] = 1,
    ACTIONS(599), 1,
      sym_identifier,
  [3113] = 1,
    ACTIONS(601), 1,
      sym_identifier,
  [3117] = 1,
    ACTIONS(603), 1,
      sym_identifier,
  [3121] = 1,
    ACTIONS(605), 1,
      sym_dot,
  [3125] = 1,
    ACTIONS(607), 1,
      sym_byte_content,
  [3129] = 1,
    ACTIONS(609), 1,
      sym_number,
  [3133] = 1,
    ACTIONS(611), 1,
      sym_dot,
  [3137] = 1,
    ACTIONS(613), 1,
      sym_dot,
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
  [SMALL_STATE(26)] = 881,
  [SMALL_STATE(27)] = 899,
  [SMALL_STATE(28)] = 925,
  [SMALL_STATE(29)] = 943,
  [SMALL_STATE(30)] = 973,
  [SMALL_STATE(31)] = 996,
  [SMALL_STATE(32)] = 1019,
  [SMALL_STATE(33)] = 1036,
  [SMALL_STATE(34)] = 1063,
  [SMALL_STATE(35)] = 1080,
  [SMALL_STATE(36)] = 1106,
  [SMALL_STATE(37)] = 1122,
  [SMALL_STATE(38)] = 1134,
  [SMALL_STATE(39)] = 1160,
  [SMALL_STATE(40)] = 1172,
  [SMALL_STATE(41)] = 1184,
  [SMALL_STATE(42)] = 1196,
  [SMALL_STATE(43)] = 1208,
  [SMALL_STATE(44)] = 1220,
  [SMALL_STATE(45)] = 1246,
  [SMALL_STATE(46)] = 1258,
  [SMALL_STATE(47)] = 1270,
  [SMALL_STATE(48)] = 1282,
  [SMALL_STATE(49)] = 1294,
  [SMALL_STATE(50)] = 1306,
  [SMALL_STATE(51)] = 1332,
  [SMALL_STATE(52)] = 1344,
  [SMALL_STATE(53)] = 1360,
  [SMALL_STATE(54)] = 1372,
  [SMALL_STATE(55)] = 1384,
  [SMALL_STATE(56)] = 1396,
  [SMALL_STATE(57)] = 1408,
  [SMALL_STATE(58)] = 1420,
  [SMALL_STATE(59)] = 1432,
  [SMALL_STATE(60)] = 1447,
  [SMALL_STATE(61)] = 1470,
  [SMALL_STATE(62)] = 1481,
  [SMALL_STATE(63)] = 1492,
  [SMALL_STATE(64)] = 1507,
  [SMALL_STATE(65)] = 1522,
  [SMALL_STATE(66)] = 1537,
  [SMALL_STATE(67)] = 1552,
  [SMALL_STATE(68)] = 1565,
  [SMALL_STATE(69)] = 1584,
  [SMALL_STATE(70)] = 1603,
  [SMALL_STATE(71)] = 1622,
  [SMALL_STATE(72)] = 1641,
  [SMALL_STATE(73)] = 1654,
  [SMALL_STATE(74)] = 1663,
  [SMALL_STATE(75)] = 1672,
  [SMALL_STATE(76)] = 1691,
  [SMALL_STATE(77)] = 1704,
  [SMALL_STATE(78)] = 1719,
  [SMALL_STATE(79)] = 1732,
  [SMALL_STATE(80)] = 1747,
  [SMALL_STATE(81)] = 1762,
  [SMALL_STATE(82)] = 1771,
  [SMALL_STATE(83)] = 1786,
  [SMALL_STATE(84)] = 1795,
  [SMALL_STATE(85)] = 1814,
  [SMALL_STATE(86)] = 1823,
  [SMALL_STATE(87)] = 1832,
  [SMALL_STATE(88)] = 1847,
  [SMALL_STATE(89)] = 1856,
  [SMALL_STATE(90)] = 1872,
  [SMALL_STATE(91)] = 1888,
  [SMALL_STATE(92)] = 1904,
  [SMALL_STATE(93)] = 1920,
  [SMALL_STATE(94)] = 1936,
  [SMALL_STATE(95)] = 1944,
  [SMALL_STATE(96)] = 1960,
  [SMALL_STATE(97)] = 1976,
  [SMALL_STATE(98)] = 1986,
  [SMALL_STATE(99)] = 2002,
  [SMALL_STATE(100)] = 2018,
  [SMALL_STATE(101)] = 2034,
  [SMALL_STATE(102)] = 2050,
  [SMALL_STATE(103)] = 2066,
  [SMALL_STATE(104)] = 2082,
  [SMALL_STATE(105)] = 2098,
  [SMALL_STATE(106)] = 2114,
  [SMALL_STATE(107)] = 2130,
  [SMALL_STATE(108)] = 2146,
  [SMALL_STATE(109)] = 2162,
  [SMALL_STATE(110)] = 2178,
  [SMALL_STATE(111)] = 2194,
  [SMALL_STATE(112)] = 2207,
  [SMALL_STATE(113)] = 2220,
  [SMALL_STATE(114)] = 2233,
  [SMALL_STATE(115)] = 2246,
  [SMALL_STATE(116)] = 2253,
  [SMALL_STATE(117)] = 2260,
  [SMALL_STATE(118)] = 2271,
  [SMALL_STATE(119)] = 2280,
  [SMALL_STATE(120)] = 2293,
  [SMALL_STATE(121)] = 2306,
  [SMALL_STATE(122)] = 2319,
  [SMALL_STATE(123)] = 2332,
  [SMALL_STATE(124)] = 2345,
  [SMALL_STATE(125)] = 2354,
  [SMALL_STATE(126)] = 2367,
  [SMALL_STATE(127)] = 2380,
  [SMALL_STATE(128)] = 2389,
  [SMALL_STATE(129)] = 2398,
  [SMALL_STATE(130)] = 2411,
  [SMALL_STATE(131)] = 2424,
  [SMALL_STATE(132)] = 2431,
  [SMALL_STATE(133)] = 2440,
  [SMALL_STATE(134)] = 2453,
  [SMALL_STATE(135)] = 2463,
  [SMALL_STATE(136)] = 2469,
  [SMALL_STATE(137)] = 2479,
  [SMALL_STATE(138)] = 2489,
  [SMALL_STATE(139)] = 2495,
  [SMALL_STATE(140)] = 2505,
  [SMALL_STATE(141)] = 2511,
  [SMALL_STATE(142)] = 2519,
  [SMALL_STATE(143)] = 2529,
  [SMALL_STATE(144)] = 2539,
  [SMALL_STATE(145)] = 2545,
  [SMALL_STATE(146)] = 2551,
  [SMALL_STATE(147)] = 2561,
  [SMALL_STATE(148)] = 2569,
  [SMALL_STATE(149)] = 2579,
  [SMALL_STATE(150)] = 2589,
  [SMALL_STATE(151)] = 2599,
  [SMALL_STATE(152)] = 2609,
  [SMALL_STATE(153)] = 2619,
  [SMALL_STATE(154)] = 2627,
  [SMALL_STATE(155)] = 2635,
  [SMALL_STATE(156)] = 2641,
  [SMALL_STATE(157)] = 2649,
  [SMALL_STATE(158)] = 2655,
  [SMALL_STATE(159)] = 2665,
  [SMALL_STATE(160)] = 2672,
  [SMALL_STATE(161)] = 2679,
  [SMALL_STATE(162)] = 2686,
  [SMALL_STATE(163)] = 2693,
  [SMALL_STATE(164)] = 2700,
  [SMALL_STATE(165)] = 2707,
  [SMALL_STATE(166)] = 2714,
  [SMALL_STATE(167)] = 2721,
  [SMALL_STATE(168)] = 2726,
  [SMALL_STATE(169)] = 2731,
  [SMALL_STATE(170)] = 2736,
  [SMALL_STATE(171)] = 2743,
  [SMALL_STATE(172)] = 2748,
  [SMALL_STATE(173)] = 2755,
  [SMALL_STATE(174)] = 2760,
  [SMALL_STATE(175)] = 2765,
  [SMALL_STATE(176)] = 2770,
  [SMALL_STATE(177)] = 2775,
  [SMALL_STATE(178)] = 2782,
  [SMALL_STATE(179)] = 2787,
  [SMALL_STATE(180)] = 2794,
  [SMALL_STATE(181)] = 2801,
  [SMALL_STATE(182)] = 2808,
  [SMALL_STATE(183)] = 2813,
  [SMALL_STATE(184)] = 2820,
  [SMALL_STATE(185)] = 2827,
  [SMALL_STATE(186)] = 2832,
  [SMALL_STATE(187)] = 2837,
  [SMALL_STATE(188)] = 2844,
  [SMALL_STATE(189)] = 2851,
  [SMALL_STATE(190)] = 2856,
  [SMALL_STATE(191)] = 2863,
  [SMALL_STATE(192)] = 2868,
  [SMALL_STATE(193)] = 2875,
  [SMALL_STATE(194)] = 2882,
  [SMALL_STATE(195)] = 2889,
  [SMALL_STATE(196)] = 2896,
  [SMALL_STATE(197)] = 2903,
  [SMALL_STATE(198)] = 2908,
  [SMALL_STATE(199)] = 2915,
  [SMALL_STATE(200)] = 2922,
  [SMALL_STATE(201)] = 2929,
  [SMALL_STATE(202)] = 2933,
  [SMALL_STATE(203)] = 2937,
  [SMALL_STATE(204)] = 2941,
  [SMALL_STATE(205)] = 2945,
  [SMALL_STATE(206)] = 2949,
  [SMALL_STATE(207)] = 2953,
  [SMALL_STATE(208)] = 2957,
  [SMALL_STATE(209)] = 2961,
  [SMALL_STATE(210)] = 2965,
  [SMALL_STATE(211)] = 2969,
  [SMALL_STATE(212)] = 2973,
  [SMALL_STATE(213)] = 2977,
  [SMALL_STATE(214)] = 2981,
  [SMALL_STATE(215)] = 2985,
  [SMALL_STATE(216)] = 2989,
  [SMALL_STATE(217)] = 2993,
  [SMALL_STATE(218)] = 2997,
  [SMALL_STATE(219)] = 3001,
  [SMALL_STATE(220)] = 3005,
  [SMALL_STATE(221)] = 3009,
  [SMALL_STATE(222)] = 3013,
  [SMALL_STATE(223)] = 3017,
  [SMALL_STATE(224)] = 3021,
  [SMALL_STATE(225)] = 3025,
  [SMALL_STATE(226)] = 3029,
  [SMALL_STATE(227)] = 3033,
  [SMALL_STATE(228)] = 3037,
  [SMALL_STATE(229)] = 3041,
  [SMALL_STATE(230)] = 3045,
  [SMALL_STATE(231)] = 3049,
  [SMALL_STATE(232)] = 3053,
  [SMALL_STATE(233)] = 3057,
  [SMALL_STATE(234)] = 3061,
  [SMALL_STATE(235)] = 3065,
  [SMALL_STATE(236)] = 3069,
  [SMALL_STATE(237)] = 3073,
  [SMALL_STATE(238)] = 3077,
  [SMALL_STATE(239)] = 3081,
  [SMALL_STATE(240)] = 3085,
  [SMALL_STATE(241)] = 3089,
  [SMALL_STATE(242)] = 3093,
  [SMALL_STATE(243)] = 3097,
  [SMALL_STATE(244)] = 3101,
  [SMALL_STATE(245)] = 3105,
  [SMALL_STATE(246)] = 3109,
  [SMALL_STATE(247)] = 3113,
  [SMALL_STATE(248)] = 3117,
  [SMALL_STATE(249)] = 3121,
  [SMALL_STATE(250)] = 3125,
  [SMALL_STATE(251)] = 3129,
  [SMALL_STATE(252)] = 3133,
  [SMALL_STATE(253)] = 3137,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(246),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(227),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(202),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(228),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(230),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_content, 1, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(241),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(52),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(194),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_block, 1, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0),
  [118] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0), SHIFT_REPEAT(123),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0),
  [128] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [131] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(194),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(146),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_block, 1, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 4, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 4, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 2, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 5, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 1, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 5, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 5, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 3, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 4, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 5, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 5, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 6, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 6, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 6, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 7, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 7, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 8, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 4, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_block, 3, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [189] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [192] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 6, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 5, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref_block, 3, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 7, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 6, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 5, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0),
  [219] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(208),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 1, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_block, 4, 0, 0),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref_block, 4, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 2, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 4, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 4, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 5, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 5, 0, 0),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 6, 0, 0),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 6, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 8, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 1, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_block, 3, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 2, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0),
  [276] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [279] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0),
  [284] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(141),
  [287] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(131),
  [290] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [294] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [298] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [300] = {.entry = {.count = 1, .reusable = false}}, SHIFT(155),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 1, 0, 0),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [326] = {.entry = {.count = 1, .reusable = false}}, SHIFT(190),
  [328] = {.entry = {.count = 1, .reusable = false}}, SHIFT(193),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [336] = {.entry = {.count = 1, .reusable = false}}, SHIFT(201),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 3, 0, 0),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_value, 1, 0, 0),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [352] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [355] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 3, 0, 0),
  [361] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(235),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 2, 0, 0),
  [368] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [371] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0),
  [373] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 7, 0, 0),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 7, 0, 0),
  [377] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_block, 4, 0, 0),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [383] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_content, 1, 0, 0),
  [385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_content, 1, 0, 0),
  [387] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0),
  [392] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [395] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 1, 0, 0),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 5, 0, 0),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 1, 0, 0),
  [407] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 2, 0, 0),
  [409] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 1, 0, 0),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 1, 0, 0),
  [413] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0),
  [415] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0), SHIFT_REPEAT(142),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 4, 0, 0),
  [422] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 2, 0, 0),
  [424] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateValue, 6, 0, 0),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [428] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [434] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(247),
  [437] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [441] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 3, 0, 1),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [445] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 2, 0, 0),
  [447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(252),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_booleanValue, 1, 0, 0),
  [469] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(94),
  [472] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [476] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_extends_block, 2, 0, 0),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_definition, 2, 0, 0),
  [480] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byteValue, 2, 0, 0),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_longValue, 2, 0, 0),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doubleValue, 3, 0, 0),
  [494] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateTimeValue, 3, 0, 0),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [500] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeValue, 5, 0, 0),
  [502] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 2, 0, 0),
  [504] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_index, 1, 0, 0),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [508] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 3, 0, 1),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [514] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(197),
  [517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [525] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 6, 0, 0),
  [527] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_identifier, 6, 0, 0),
  [529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [535] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 6, 0, 0),
  [547] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 5, 0, 0),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [557] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_identifier, 4, 0, 0),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_version_number, 5, 0, 0),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [573] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [585] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dmf_declaration, 2, 0, 0),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [591] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_declaration, 4, 0, 0),
  [593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [601] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
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
