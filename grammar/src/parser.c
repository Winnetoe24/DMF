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
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 54,
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
  [87] = 81,
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
  [98] = 97,
  [99] = 80,
  [100] = 84,
  [101] = 85,
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
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 69,
  [120] = 120,
  [121] = 121,
  [122] = 114,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 79,
  [127] = 127,
  [128] = 128,
  [129] = 125,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 28,
  [143] = 143,
  [144] = 68,
  [145] = 66,
  [146] = 26,
  [147] = 72,
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
  [190] = 127,
  [191] = 191,
  [192] = 134,
  [193] = 193,
  [194] = 194,
  [195] = 195,
  [196] = 86,
  [197] = 197,
  [198] = 187,
  [199] = 191,
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
  [232] = 232,
  [233] = 233,
  [234] = 234,
  [235] = 235,
  [236] = 143,
  [237] = 237,
  [238] = 138,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 242,
  [244] = 244,
  [245] = 245,
  [246] = 214,
  [247] = 247,
  [248] = 229,
  [249] = 239,
  [250] = 230,
  [251] = 251,
  [252] = 208,
  [253] = 226,
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
  [25] = {.lex_state = 148},
  [26] = {.lex_state = 148},
  [27] = {.lex_state = 8},
  [28] = {.lex_state = 148},
  [29] = {.lex_state = 8},
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
  [48] = {.lex_state = 148},
  [49] = {.lex_state = 148},
  [50] = {.lex_state = 148},
  [51] = {.lex_state = 148},
  [52] = {.lex_state = 148},
  [53] = {.lex_state = 148},
  [54] = {.lex_state = 10},
  [55] = {.lex_state = 148},
  [56] = {.lex_state = 148},
  [57] = {.lex_state = 148},
  [58] = {.lex_state = 10},
  [59] = {.lex_state = 148},
  [60] = {.lex_state = 148},
  [61] = {.lex_state = 148},
  [62] = {.lex_state = 6},
  [63] = {.lex_state = 6},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 148},
  [67] = {.lex_state = 6},
  [68] = {.lex_state = 148},
  [69] = {.lex_state = 148},
  [70] = {.lex_state = 148},
  [71] = {.lex_state = 148},
  [72] = {.lex_state = 148},
  [73] = {.lex_state = 148},
  [74] = {.lex_state = 6},
  [75] = {.lex_state = 148},
  [76] = {.lex_state = 148},
  [77] = {.lex_state = 148},
  [78] = {.lex_state = 148},
  [79] = {.lex_state = 148},
  [80] = {.lex_state = 3},
  [81] = {.lex_state = 4},
  [82] = {.lex_state = 3},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 4},
  [85] = {.lex_state = 3},
  [86] = {.lex_state = 148},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 6},
  [98] = {.lex_state = 6},
  [99] = {.lex_state = 3},
  [100] = {.lex_state = 4},
  [101] = {.lex_state = 3},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 6},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 8},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 148},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 121},
  [115] = {.lex_state = 8},
  [116] = {.lex_state = 148},
  [117] = {.lex_state = 8},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 8},
  [120] = {.lex_state = 8},
  [121] = {.lex_state = 6},
  [122] = {.lex_state = 121},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 4},
  [126] = {.lex_state = 6},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 3},
  [129] = {.lex_state = 3},
  [130] = {.lex_state = 148},
  [131] = {.lex_state = 148},
  [132] = {.lex_state = 4},
  [133] = {.lex_state = 148},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 148},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 6},
  [140] = {.lex_state = 148},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 6},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 6},
  [145] = {.lex_state = 6},
  [146] = {.lex_state = 6},
  [147] = {.lex_state = 6},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 148},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 148},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 148},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0},
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
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 6},
  [188] = {.lex_state = 148},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 2},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 2},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 6},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 6},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 2},
  [203] = {.lex_state = 6},
  [204] = {.lex_state = 6},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 2},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 6},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 7},
  [212] = {.lex_state = 148},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 6},
  [215] = {.lex_state = 6},
  [216] = {.lex_state = 6},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 8},
  [219] = {.lex_state = 10},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 8},
  [223] = {.lex_state = 2},
  [224] = {.lex_state = 148},
  [225] = {.lex_state = 2},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 6},
  [228] = {.lex_state = 6},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 148},
  [231] = {.lex_state = 2},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 2},
  [234] = {.lex_state = 129},
  [235] = {.lex_state = 0},
  [236] = {.lex_state = 6},
  [237] = {.lex_state = 6},
  [238] = {.lex_state = 6},
  [239] = {.lex_state = 6},
  [240] = {.lex_state = 6},
  [241] = {.lex_state = 6},
  [242] = {.lex_state = 148},
  [243] = {.lex_state = 148},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 2},
  [246] = {.lex_state = 6},
  [247] = {.lex_state = 6},
  [248] = {.lex_state = 0},
  [249] = {.lex_state = 6},
  [250] = {.lex_state = 148},
  [251] = {.lex_state = 6},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 2},
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
    [sym_source_file] = STATE(201),
    [sym_dmf_declaration] = STATE(231),
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
    STATE(8), 1,
      sym_import_block,
    STATE(25), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(232), 1,
      sym_model_content,
    STATE(7), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(31), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    STATE(43), 5,
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
    STATE(25), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(35), 1,
      sym__right_brace,
    STATE(4), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(43), 5,
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
    STATE(25), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    STATE(4), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(43), 5,
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
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(47), 1,
      sym__right_brace,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(43), 5,
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
    STATE(94), 1,
      sym_param_definition,
    STATE(98), 1,
      aux_sym_reftype_repeat1,
    STATE(145), 1,
      aux_sym_package_string_repeat1,
    STATE(161), 1,
      sym__right_paren,
    STATE(236), 1,
      sym_package_string,
    STATE(228), 2,
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
    ACTIONS(56), 1,
      ts_builtin_sym_end,
    STATE(25), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(4), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(43), 5,
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
    STATE(25), 1,
      sym_comment_block,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(244), 1,
      sym_model_content,
    STATE(7), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(43), 5,
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
    STATE(98), 1,
      aux_sym_reftype_repeat1,
    STATE(145), 1,
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
    STATE(108), 1,
      sym_integerValue,
    STATE(137), 1,
      sym_dateValue,
    STATE(164), 1,
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
    STATE(98), 1,
      aux_sym_reftype_repeat1,
    STATE(145), 1,
      aux_sym_package_string_repeat1,
    STATE(182), 1,
      sym_param_definition,
    STATE(236), 1,
      sym_package_string,
    STATE(228), 2,
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
    STATE(75), 1,
      sym_comment_block,
    STATE(152), 1,
      sym_identifier_statement,
    STATE(17), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    STATE(36), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(18), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    STATE(44), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    ACTIONS(78), 1,
      anon_sym_identifier,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    STATE(149), 1,
      sym_identifier_statement,
    STATE(21), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    STATE(75), 1,
      sym_comment_block,
    STATE(157), 1,
      sym_identifier_statement,
    STATE(15), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    STATE(157), 1,
      sym_identifier_statement,
    STATE(21), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(44), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(21), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    ACTIONS(84), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(53), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(22), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [683] = 10,
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
    STATE(53), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(21), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [717] = 9,
    ACTIONS(86), 1,
      anon_sym_arg,
    ACTIONS(89), 1,
      anon_sym_ref,
    ACTIONS(92), 1,
      anon_sym_func,
    ACTIONS(97), 1,
      sym_comment,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    ACTIONS(95), 2,
      anon_sym_identifier,
      anon_sym_RBRACE,
    STATE(21), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(55), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(21), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    STATE(149), 1,
      sym_identifier_statement,
    STATE(24), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    STATE(75), 1,
      sym_comment_block,
    STATE(158), 1,
      sym_identifier_statement,
    STATE(21), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(71), 3,
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
    STATE(42), 5,
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
    STATE(142), 1,
      aux_sym_comment_block_repeat1,
    STATE(204), 1,
      sym_comment_block,
    STATE(29), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(120), 2,
      sym_arg_block,
      sym_enum_constant,
  [925] = 3,
    ACTIONS(119), 1,
      sym_comment,
    STATE(26), 1,
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
    ACTIONS(109), 1,
      anon_sym_arg,
    ACTIONS(111), 1,
      sym_identifier,
    ACTIONS(113), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_RBRACE,
    STATE(46), 1,
      sym__right_brace,
    STATE(142), 1,
      aux_sym_comment_block_repeat1,
    STATE(204), 1,
      sym_comment_block,
    STATE(34), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(120), 2,
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
    STATE(41), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [996] = 3,
    ACTIONS(5), 1,
      anon_sym_import,
    STATE(32), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    ACTIONS(123), 7,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1013] = 3,
    ACTIONS(125), 1,
      anon_sym_import,
    STATE(32), 2,
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
    STATE(42), 5,
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
    STATE(142), 1,
      aux_sym_comment_block_repeat1,
    STATE(204), 1,
      sym_comment_block,
    STATE(34), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(120), 2,
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
  [1116] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(147), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(49), 1,
      sym__right_brace,
    STATE(136), 1,
      sym_func_block,
    STATE(156), 1,
      sym_comment_block,
    STATE(50), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1142] = 1,
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
  [1154] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(147), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(49), 1,
      sym__right_brace,
    STATE(136), 1,
      sym_func_block,
    STATE(156), 1,
      sym_comment_block,
    STATE(60), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1180] = 1,
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
  [1192] = 1,
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
  [1204] = 1,
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
  [1216] = 1,
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
  [1228] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(159), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(39), 1,
      sym__right_brace,
    STATE(136), 1,
      sym_func_block,
    STATE(156), 1,
      sym_comment_block,
    STATE(40), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
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
  [1278] = 1,
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
  [1290] = 1,
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
  [1302] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_func,
    ACTIONS(169), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(56), 1,
      sym__right_brace,
    STATE(136), 1,
      sym_func_block,
    STATE(156), 1,
      sym_comment_block,
    STATE(60), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1328] = 1,
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
  [1340] = 1,
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
  [1352] = 1,
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
  [1364] = 3,
    ACTIONS(54), 1,
      sym_date,
    STATE(239), 1,
      sym_primitive_type,
    ACTIONS(177), 7,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_string,
      sym_boolean,
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
  [1416] = 3,
    ACTIONS(54), 1,
      sym_date,
    STATE(249), 1,
      sym_primitive_type,
    ACTIONS(177), 7,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_string,
      sym_boolean,
  [1432] = 1,
    ACTIONS(185), 8,
      anon_sym_import,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1443] = 7,
    ACTIONS(187), 1,
      anon_sym_func,
    ACTIONS(190), 1,
      sym_comment,
    ACTIONS(193), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_comment_block_repeat1,
    STATE(136), 1,
      sym_func_block,
    STATE(156), 1,
      sym_comment_block,
    STATE(60), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1466] = 1,
    ACTIONS(195), 8,
      anon_sym_import,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1477] = 6,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(197), 1,
      sym_identifier,
    STATE(98), 1,
      aux_sym_reftype_repeat1,
    STATE(145), 1,
      aux_sym_package_string_repeat1,
    STATE(236), 1,
      sym_package_string,
    STATE(240), 1,
      sym_reftype,
  [1496] = 6,
    ACTIONS(199), 1,
      sym_identifier,
    ACTIONS(201), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(97), 1,
      aux_sym_reftype_repeat1,
    STATE(143), 1,
      sym_package_string,
    STATE(171), 1,
      sym_reftype,
  [1515] = 6,
    ACTIONS(203), 1,
      anon_sym_extends,
    ACTIONS(205), 1,
      anon_sym_implements,
    ACTIONS(207), 1,
      anon_sym_LBRACE,
    STATE(13), 1,
      sym__left_brace,
    STATE(118), 1,
      sym_extends_block,
    STATE(151), 1,
      sym_implements_block,
  [1534] = 6,
    ACTIONS(203), 1,
      anon_sym_extends,
    ACTIONS(205), 1,
      anon_sym_implements,
    ACTIONS(209), 1,
      anon_sym_LBRACE,
    STATE(12), 1,
      sym__left_brace,
    STATE(123), 1,
      sym_extends_block,
    STATE(153), 1,
      sym_implements_block,
  [1553] = 3,
    ACTIONS(213), 1,
      sym_dot,
    STATE(79), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(211), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1566] = 6,
    ACTIONS(199), 1,
      sym_identifier,
    ACTIONS(201), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(97), 1,
      aux_sym_reftype_repeat1,
    STATE(143), 1,
      sym_package_string,
    STATE(172), 1,
      sym_reftype,
  [1585] = 3,
    ACTIONS(213), 1,
      sym_dot,
    STATE(72), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(211), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1598] = 1,
    ACTIONS(215), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1607] = 1,
    ACTIONS(217), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1616] = 1,
    ACTIONS(219), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1625] = 3,
    ACTIONS(213), 1,
      sym_dot,
    STATE(79), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(221), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1638] = 1,
    ACTIONS(223), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1647] = 6,
    ACTIONS(199), 1,
      sym_identifier,
    ACTIONS(201), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(97), 1,
      aux_sym_reftype_repeat1,
    STATE(103), 1,
      sym_reftype,
    STATE(143), 1,
      sym_package_string,
  [1666] = 4,
    ACTIONS(72), 1,
      anon_sym_arg,
    ACTIONS(74), 1,
      anon_sym_ref,
    ACTIONS(76), 1,
      anon_sym_func,
    STATE(73), 3,
      sym_arg_block,
      sym_ref_block,
      sym_func_block,
  [1681] = 1,
    ACTIONS(225), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1690] = 1,
    ACTIONS(227), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1699] = 1,
    ACTIONS(229), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1708] = 3,
    ACTIONS(233), 1,
      sym_dot,
    STATE(79), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(231), 4,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1721] = 5,
    ACTIONS(236), 1,
      anon_sym_DQUOTE,
    ACTIONS(238), 1,
      sym_string_content_double_quote,
    ACTIONS(240), 1,
      anon_sym_BSLASH,
    STATE(85), 1,
      aux_sym_stringValue_repeat1,
    STATE(128), 1,
      sym_escape_sequence,
  [1737] = 5,
    ACTIONS(242), 1,
      anon_sym_SQUOTE,
    ACTIONS(244), 1,
      sym_string_content_single_quote,
    ACTIONS(246), 1,
      anon_sym_BSLASH,
    STATE(83), 1,
      aux_sym_stringValue_repeat2,
    STATE(132), 1,
      sym_escape_sequence,
  [1753] = 5,
    ACTIONS(248), 1,
      anon_sym_DQUOTE,
    ACTIONS(250), 1,
      sym_string_content_double_quote,
    ACTIONS(253), 1,
      anon_sym_BSLASH,
    STATE(82), 1,
      aux_sym_stringValue_repeat1,
    STATE(128), 1,
      sym_escape_sequence,
  [1769] = 5,
    ACTIONS(256), 1,
      anon_sym_SQUOTE,
    ACTIONS(258), 1,
      sym_string_content_single_quote,
    ACTIONS(261), 1,
      anon_sym_BSLASH,
    STATE(83), 1,
      aux_sym_stringValue_repeat2,
    STATE(132), 1,
      sym_escape_sequence,
  [1785] = 5,
    ACTIONS(236), 1,
      anon_sym_SQUOTE,
    ACTIONS(244), 1,
      sym_string_content_single_quote,
    ACTIONS(246), 1,
      anon_sym_BSLASH,
    STATE(87), 1,
      aux_sym_stringValue_repeat2,
    STATE(132), 1,
      sym_escape_sequence,
  [1801] = 5,
    ACTIONS(238), 1,
      sym_string_content_double_quote,
    ACTIONS(240), 1,
      anon_sym_BSLASH,
    ACTIONS(264), 1,
      anon_sym_DQUOTE,
    STATE(82), 1,
      aux_sym_stringValue_repeat1,
    STATE(128), 1,
      sym_escape_sequence,
  [1817] = 1,
    ACTIONS(231), 5,
      anon_sym_from,
      anon_sym_implements,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1825] = 5,
    ACTIONS(244), 1,
      sym_string_content_single_quote,
    ACTIONS(246), 1,
      anon_sym_BSLASH,
    ACTIONS(264), 1,
      anon_sym_SQUOTE,
    STATE(83), 1,
      aux_sym_stringValue_repeat2,
    STATE(132), 1,
      sym_escape_sequence,
  [1841] = 2,
    ACTIONS(266), 1,
      anon_sym__,
    ACTIONS(268), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [1851] = 5,
    ACTIONS(270), 1,
      anon_sym_COMMA,
    ACTIONS(272), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(91), 1,
      aux_sym_enum_constant_repeat1,
    STATE(155), 1,
      sym__right_paren,
  [1867] = 5,
    ACTIONS(274), 1,
      anon_sym_COMMA,
    ACTIONS(276), 1,
      anon_sym_RPAREN,
    STATE(93), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(159), 1,
      sym__right_paren,
    STATE(209), 1,
      sym__comma,
  [1883] = 5,
    ACTIONS(270), 1,
      anon_sym_COMMA,
    ACTIONS(278), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(110), 1,
      aux_sym_enum_constant_repeat1,
    STATE(166), 1,
      sym__right_paren,
  [1899] = 5,
    ACTIONS(270), 1,
      anon_sym_COMMA,
    ACTIONS(278), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(95), 1,
      aux_sym_enum_constant_repeat1,
    STATE(166), 1,
      sym__right_paren,
  [1915] = 5,
    ACTIONS(274), 1,
      anon_sym_COMMA,
    ACTIONS(280), 1,
      anon_sym_RPAREN,
    STATE(112), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(170), 1,
      sym__right_paren,
    STATE(209), 1,
      sym__comma,
  [1931] = 5,
    ACTIONS(282), 1,
      anon_sym_COMMA,
    ACTIONS(284), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(96), 1,
      aux_sym_func_block_repeat1,
    STATE(174), 1,
      sym__right_paren,
  [1947] = 5,
    ACTIONS(270), 1,
      anon_sym_COMMA,
    ACTIONS(286), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(110), 1,
      aux_sym_enum_constant_repeat1,
    STATE(181), 1,
      sym__right_paren,
  [1963] = 5,
    ACTIONS(282), 1,
      anon_sym_COMMA,
    ACTIONS(288), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(102), 1,
      aux_sym_func_block_repeat1,
    STATE(183), 1,
      sym__right_paren,
  [1979] = 5,
    ACTIONS(199), 1,
      sym_identifier,
    ACTIONS(201), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(138), 1,
      sym_package_string,
    STATE(139), 1,
      aux_sym_reftype_repeat1,
  [1995] = 5,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(197), 1,
      sym_identifier,
    STATE(139), 1,
      aux_sym_reftype_repeat1,
    STATE(145), 1,
      aux_sym_package_string_repeat1,
    STATE(238), 1,
      sym_package_string,
  [2011] = 5,
    ACTIONS(238), 1,
      sym_string_content_double_quote,
    ACTIONS(240), 1,
      anon_sym_BSLASH,
    ACTIONS(290), 1,
      anon_sym_DQUOTE,
    STATE(101), 1,
      aux_sym_stringValue_repeat1,
    STATE(128), 1,
      sym_escape_sequence,
  [2027] = 5,
    ACTIONS(244), 1,
      sym_string_content_single_quote,
    ACTIONS(246), 1,
      anon_sym_BSLASH,
    ACTIONS(290), 1,
      anon_sym_SQUOTE,
    STATE(81), 1,
      aux_sym_stringValue_repeat2,
    STATE(132), 1,
      sym_escape_sequence,
  [2043] = 5,
    ACTIONS(238), 1,
      sym_string_content_double_quote,
    ACTIONS(240), 1,
      anon_sym_BSLASH,
    ACTIONS(242), 1,
      anon_sym_DQUOTE,
    STATE(82), 1,
      aux_sym_stringValue_repeat1,
    STATE(128), 1,
      sym_escape_sequence,
  [2059] = 4,
    ACTIONS(292), 1,
      anon_sym_COMMA,
    ACTIONS(295), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(102), 1,
      aux_sym_func_block_repeat1,
  [2072] = 4,
    ACTIONS(297), 1,
      anon_sym_COMMA,
    ACTIONS(299), 1,
      anon_sym_LBRACE,
    STATE(63), 1,
      sym__comma,
    STATE(124), 1,
      aux_sym_implements_block_repeat1,
  [2085] = 4,
    ACTIONS(205), 1,
      anon_sym_implements,
    ACTIONS(301), 1,
      anon_sym_LBRACE,
    STATE(45), 1,
      sym__left_brace,
    STATE(154), 1,
      sym_implements_block,
  [2098] = 4,
    ACTIONS(303), 1,
      anon_sym_COMMA,
    ACTIONS(306), 1,
      anon_sym_LBRACE,
    STATE(63), 1,
      sym__comma,
    STATE(105), 1,
      aux_sym_implements_block_repeat1,
  [2111] = 4,
    ACTIONS(199), 1,
      sym_identifier,
    ACTIONS(213), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(224), 1,
      sym_package_string,
  [2124] = 1,
    ACTIONS(308), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [2131] = 3,
    ACTIONS(310), 1,
      sym_dot,
    ACTIONS(314), 1,
      anon_sym_L,
    ACTIONS(312), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2142] = 2,
    ACTIONS(316), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(318), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2151] = 4,
    ACTIONS(320), 1,
      anon_sym_COMMA,
    ACTIONS(323), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      sym__comma,
    STATE(110), 1,
      aux_sym_enum_constant_repeat1,
  [2164] = 4,
    ACTIONS(325), 1,
      anon_sym__,
    ACTIONS(327), 1,
      sym_number,
    STATE(89), 1,
      sym_enum_index,
    STATE(195), 1,
      sym_integerValue,
  [2177] = 4,
    ACTIONS(329), 1,
      anon_sym_COMMA,
    ACTIONS(332), 1,
      anon_sym_RPAREN,
    STATE(112), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(209), 1,
      sym__comma,
  [2190] = 4,
    ACTIONS(334), 1,
      anon_sym_LPAREN,
    ACTIONS(336), 1,
      sym__new_line,
    STATE(202), 1,
      sym_model_identifier,
    STATE(207), 1,
      sym__left_paren,
  [2203] = 1,
    ACTIONS(338), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2210] = 2,
    ACTIONS(340), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(342), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2219] = 4,
    ACTIONS(325), 1,
      anon_sym__,
    ACTIONS(327), 1,
      sym_number,
    STATE(92), 1,
      sym_enum_index,
    STATE(195), 1,
      sym_integerValue,
  [2232] = 2,
    ACTIONS(344), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(346), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2241] = 4,
    ACTIONS(205), 1,
      anon_sym_implements,
    ACTIONS(348), 1,
      anon_sym_LBRACE,
    STATE(14), 1,
      sym__left_brace,
    STATE(186), 1,
      sym_implements_block,
  [2254] = 2,
    ACTIONS(215), 2,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(350), 2,
      anon_sym_arg,
      sym_identifier,
  [2263] = 2,
    ACTIONS(352), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(354), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2272] = 4,
    ACTIONS(199), 1,
      sym_identifier,
    ACTIONS(213), 1,
      sym_dot,
    STATE(66), 1,
      aux_sym_package_string_repeat1,
    STATE(167), 1,
      sym_package_string,
  [2285] = 1,
    ACTIONS(356), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2292] = 4,
    ACTIONS(205), 1,
      anon_sym_implements,
    ACTIONS(358), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym__left_brace,
    STATE(197), 1,
      sym_implements_block,
  [2305] = 4,
    ACTIONS(297), 1,
      anon_sym_COMMA,
    ACTIONS(360), 1,
      anon_sym_LBRACE,
    STATE(63), 1,
      sym__comma,
    STATE(105), 1,
      aux_sym_implements_block_repeat1,
  [2318] = 2,
    ACTIONS(364), 1,
      sym_string_content_single_quote,
    ACTIONS(362), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2326] = 3,
    ACTIONS(231), 1,
      sym_identifier,
    ACTIONS(366), 1,
      sym_dot,
    STATE(126), 1,
      aux_sym_package_string_repeat1,
  [2336] = 1,
    ACTIONS(369), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2342] = 2,
    ACTIONS(373), 1,
      sym_string_content_double_quote,
    ACTIONS(371), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2350] = 2,
    ACTIONS(364), 1,
      sym_string_content_double_quote,
    ACTIONS(362), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2358] = 3,
    ACTIONS(375), 1,
      anon_sym_DQUOTE,
    ACTIONS(377), 1,
      anon_sym_SQUOTE,
    STATE(113), 1,
      sym_stringValue,
  [2368] = 1,
    ACTIONS(379), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2374] = 2,
    ACTIONS(383), 1,
      sym_string_content_single_quote,
    ACTIONS(381), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2382] = 3,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    STATE(135), 1,
      sym_stringValue,
  [2392] = 1,
    ACTIONS(385), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2398] = 3,
    ACTIONS(387), 1,
      anon_sym_version,
    ACTIONS(389), 1,
      anon_sym_RPAREN,
    STATE(223), 1,
      sym__right_paren,
  [2408] = 1,
    ACTIONS(391), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2414] = 2,
    ACTIONS(393), 1,
      anon_sym_T,
    ACTIONS(312), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2422] = 1,
    ACTIONS(395), 3,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2428] = 3,
    ACTIONS(397), 1,
      sym_identifier,
    ACTIONS(399), 1,
      sym_dot,
    STATE(139), 1,
      aux_sym_reftype_repeat1,
  [2438] = 3,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    STATE(210), 1,
      sym_stringValue,
  [2448] = 1,
    ACTIONS(402), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_T,
  [2454] = 3,
    ACTIONS(117), 1,
      sym_identifier,
    ACTIONS(404), 1,
      sym_comment,
    STATE(146), 1,
      aux_sym_comment_block_repeat1,
  [2464] = 1,
    ACTIONS(406), 3,
      anon_sym_implements,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2470] = 3,
    ACTIONS(211), 1,
      sym_identifier,
    ACTIONS(408), 1,
      sym_dot,
    STATE(147), 1,
      aux_sym_package_string_repeat1,
  [2480] = 3,
    ACTIONS(211), 1,
      sym_identifier,
    ACTIONS(408), 1,
      sym_dot,
    STATE(126), 1,
      aux_sym_package_string_repeat1,
  [2490] = 3,
    ACTIONS(104), 1,
      sym_identifier,
    ACTIONS(410), 1,
      sym_comment,
    STATE(146), 1,
      aux_sym_comment_block_repeat1,
  [2500] = 3,
    ACTIONS(221), 1,
      sym_identifier,
    ACTIONS(408), 1,
      sym_dot,
    STATE(126), 1,
      aux_sym_package_string_repeat1,
  [2510] = 2,
    ACTIONS(413), 1,
      anon_sym_LPAREN,
    STATE(111), 1,
      sym__left_paren,
  [2517] = 2,
    ACTIONS(415), 1,
      anon_sym_RBRACE,
    STATE(57), 1,
      sym__right_brace,
  [2524] = 2,
    ACTIONS(417), 1,
      anon_sym_LPAREN,
    STATE(216), 1,
      sym__left_paren,
  [2531] = 2,
    ACTIONS(348), 1,
      anon_sym_LBRACE,
    STATE(14), 1,
      sym__left_brace,
  [2538] = 2,
    ACTIONS(419), 1,
      anon_sym_RBRACE,
    STATE(48), 1,
      sym__right_brace,
  [2545] = 2,
    ACTIONS(358), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym__left_brace,
  [2552] = 2,
    ACTIONS(421), 1,
      anon_sym_LBRACE,
    STATE(38), 1,
      sym__left_brace,
  [2559] = 2,
    ACTIONS(423), 1,
      anon_sym_SEMI,
    STATE(109), 1,
      sym__semicolon,
  [2566] = 2,
    ACTIONS(76), 1,
      anon_sym_func,
    STATE(131), 1,
      sym_func_block,
  [2573] = 2,
    ACTIONS(425), 1,
      anon_sym_RBRACE,
    STATE(51), 1,
      sym__right_brace,
  [2580] = 2,
    ACTIONS(427), 1,
      anon_sym_RBRACE,
    STATE(52), 1,
      sym__right_brace,
  [2587] = 2,
    ACTIONS(429), 1,
      anon_sym_SEMI,
    STATE(221), 1,
      sym__semicolon,
  [2594] = 2,
    ACTIONS(431), 1,
      sym_number,
    STATE(200), 1,
      sym_version_number,
  [2601] = 2,
    ACTIONS(433), 1,
      anon_sym_SEMI,
    STATE(76), 1,
      sym__semicolon,
  [2608] = 2,
    ACTIONS(435), 1,
      sym_number,
    STATE(225), 1,
      sym_version_number,
  [2615] = 1,
    ACTIONS(437), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2620] = 1,
    ACTIONS(323), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2625] = 1,
    ACTIONS(312), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2630] = 2,
    ACTIONS(439), 1,
      anon_sym_SEMI,
    STATE(115), 1,
      sym__semicolon,
  [2637] = 2,
    ACTIONS(441), 1,
      anon_sym_LBRACE,
    STATE(5), 1,
      sym__left_brace,
  [2644] = 2,
    ACTIONS(443), 1,
      anon_sym_LPAREN,
    STATE(116), 1,
      sym__left_paren,
  [2651] = 1,
    ACTIONS(332), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2656] = 2,
    ACTIONS(445), 1,
      anon_sym_SEMI,
    STATE(205), 1,
      sym__semicolon,
  [2663] = 1,
    ACTIONS(306), 2,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2668] = 1,
    ACTIONS(447), 2,
      anon_sym_implements,
      anon_sym_LBRACE,
  [2673] = 2,
    ACTIONS(449), 1,
      anon_sym_model,
    STATE(245), 1,
      sym_model_declaration,
  [2680] = 2,
    ACTIONS(451), 1,
      anon_sym_SEMI,
    STATE(77), 1,
      sym__semicolon,
  [2687] = 1,
    ACTIONS(453), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2692] = 1,
    ACTIONS(455), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2697] = 2,
    ACTIONS(327), 1,
      sym_number,
    STATE(184), 1,
      sym_integerValue,
  [2704] = 1,
    ACTIONS(457), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2709] = 2,
    ACTIONS(459), 1,
      aux_sym_timeValue_token1,
    STATE(185), 1,
      sym_timeValue,
  [2716] = 2,
    ACTIONS(461), 1,
      anon_sym_LBRACE,
    STATE(27), 1,
      sym__left_brace,
  [2723] = 2,
    ACTIONS(463), 1,
      anon_sym_SEMI,
    STATE(117), 1,
      sym__semicolon,
  [2730] = 1,
    ACTIONS(295), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2735] = 2,
    ACTIONS(465), 1,
      anon_sym_SEMI,
    STATE(78), 1,
      sym__semicolon,
  [2742] = 1,
    ACTIONS(467), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2747] = 1,
    ACTIONS(469), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2752] = 2,
    ACTIONS(471), 1,
      anon_sym_LBRACE,
    STATE(19), 1,
      sym__left_brace,
  [2759] = 2,
    ACTIONS(473), 1,
      sym_identifier,
    ACTIONS(476), 1,
      sym_dot,
  [2766] = 2,
    ACTIONS(435), 1,
      sym_number,
    STATE(233), 1,
      sym_version_number,
  [2773] = 1,
    ACTIONS(478), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2778] = 2,
    ACTIONS(369), 1,
      sym__new_line,
    ACTIONS(480), 1,
      anon_sym_LPAREN,
  [2785] = 2,
    ACTIONS(482), 1,
      anon_sym_SEMI,
    STATE(69), 1,
      sym__semicolon,
  [2792] = 2,
    ACTIONS(385), 1,
      sym__new_line,
    ACTIONS(484), 1,
      anon_sym_LPAREN,
  [2799] = 2,
    ACTIONS(486), 1,
      anon_sym_SEMI,
    STATE(70), 1,
      sym__semicolon,
  [2806] = 2,
    ACTIONS(488), 1,
      anon_sym_LPAREN,
    STATE(6), 1,
      sym__left_paren,
  [2813] = 1,
    ACTIONS(490), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2818] = 1,
    ACTIONS(231), 2,
      sym_identifier,
      sym_dot,
  [2823] = 2,
    ACTIONS(492), 1,
      anon_sym_LBRACE,
    STATE(23), 1,
      sym__left_brace,
  [2830] = 2,
    ACTIONS(476), 1,
      sym_dot,
    ACTIONS(494), 1,
      sym_identifier,
  [2837] = 2,
    ACTIONS(497), 1,
      anon_sym_SEMI,
    STATE(119), 1,
      sym__semicolon,
  [2844] = 2,
    ACTIONS(499), 1,
      anon_sym_RPAREN,
    STATE(206), 1,
      sym__right_paren,
  [2851] = 1,
    ACTIONS(501), 1,
      ts_builtin_sym_end,
  [2855] = 1,
    ACTIONS(503), 1,
      sym__new_line,
  [2859] = 1,
    ACTIONS(505), 1,
      sym_identifier,
  [2863] = 1,
    ACTIONS(507), 1,
      sym_identifier,
  [2867] = 1,
    ACTIONS(509), 1,
      anon_sym_RBRACE,
  [2871] = 1,
    ACTIONS(511), 1,
      sym__new_line,
  [2875] = 1,
    ACTIONS(513), 1,
      anon_sym_model,
  [2879] = 1,
    ACTIONS(515), 1,
      sym_dot,
  [2883] = 1,
    ACTIONS(517), 1,
      sym_identifier,
  [2887] = 1,
    ACTIONS(519), 1,
      anon_sym_version,
  [2891] = 1,
    ACTIONS(521), 1,
      aux_sym_dateValue_token2,
  [2895] = 1,
    ACTIONS(523), 1,
      sym_number,
  [2899] = 1,
    ACTIONS(525), 1,
      anon_sym_COLON,
  [2903] = 1,
    ACTIONS(527), 1,
      sym_identifier,
  [2907] = 1,
    ACTIONS(529), 1,
      sym_identifier,
  [2911] = 1,
    ACTIONS(531), 1,
      sym_identifier,
  [2915] = 1,
    ACTIONS(533), 1,
      anon_sym_DASH,
  [2919] = 1,
    ACTIONS(535), 1,
      aux_sym_timeValue_token2,
  [2923] = 1,
    ACTIONS(537), 1,
      aux_sym_dateValue_token3,
  [2927] = 1,
    ACTIONS(539), 1,
      anon_sym_COLON,
  [2931] = 1,
    ACTIONS(541), 1,
      anon_sym_RBRACE,
  [2935] = 1,
    ACTIONS(543), 1,
      aux_sym_timeValue_token2,
  [2939] = 1,
    ACTIONS(545), 1,
      sym__new_line,
  [2943] = 1,
    ACTIONS(547), 1,
      anon_sym_from,
  [2947] = 1,
    ACTIONS(549), 1,
      sym__new_line,
  [2951] = 1,
    ACTIONS(551), 1,
      anon_sym_RPAREN,
  [2955] = 1,
    ACTIONS(553), 1,
      sym_identifier,
  [2959] = 1,
    ACTIONS(555), 1,
      sym_identifier,
  [2963] = 1,
    ACTIONS(557), 1,
      sym_dot,
  [2967] = 1,
    ACTIONS(559), 1,
      sym_number,
  [2971] = 1,
    ACTIONS(561), 1,
      sym__new_line,
  [2975] = 1,
    ACTIONS(563), 1,
      ts_builtin_sym_end,
  [2979] = 1,
    ACTIONS(565), 1,
      sym__new_line,
  [2983] = 1,
    ACTIONS(567), 1,
      sym_byte_content,
  [2987] = 1,
    ACTIONS(569), 1,
      anon_sym_DASH,
  [2991] = 1,
    ACTIONS(406), 1,
      sym_identifier,
  [2995] = 1,
    ACTIONS(571), 1,
      sym_identifier,
  [2999] = 1,
    ACTIONS(395), 1,
      sym_identifier,
  [3003] = 1,
    ACTIONS(573), 1,
      sym_identifier,
  [3007] = 1,
    ACTIONS(575), 1,
      sym_identifier,
  [3011] = 1,
    ACTIONS(577), 1,
      sym_identifier,
  [3015] = 1,
    ACTIONS(579), 1,
      sym_number,
  [3019] = 1,
    ACTIONS(581), 1,
      sym_number,
  [3023] = 1,
    ACTIONS(583), 1,
      ts_builtin_sym_end,
  [3027] = 1,
    ACTIONS(585), 1,
      sym__new_line,
  [3031] = 1,
    ACTIONS(587), 1,
      sym_identifier,
  [3035] = 1,
    ACTIONS(589), 1,
      aux_sym_dateValue_token1,
  [3039] = 1,
    ACTIONS(591), 1,
      sym_dot,
  [3043] = 1,
    ACTIONS(593), 1,
      sym_identifier,
  [3047] = 1,
    ACTIONS(595), 1,
      sym_number,
  [3051] = 1,
    ACTIONS(597), 1,
      sym_identifier,
  [3055] = 1,
    ACTIONS(599), 1,
      sym_dot,
  [3059] = 1,
    ACTIONS(551), 1,
      sym__new_line,
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
  [SMALL_STATE(20)] = 683,
  [SMALL_STATE(21)] = 717,
  [SMALL_STATE(22)] = 749,
  [SMALL_STATE(23)] = 783,
  [SMALL_STATE(24)] = 817,
  [SMALL_STATE(25)] = 851,
  [SMALL_STATE(26)] = 877,
  [SMALL_STATE(27)] = 895,
  [SMALL_STATE(28)] = 925,
  [SMALL_STATE(29)] = 943,
  [SMALL_STATE(30)] = 973,
  [SMALL_STATE(31)] = 996,
  [SMALL_STATE(32)] = 1013,
  [SMALL_STATE(33)] = 1030,
  [SMALL_STATE(34)] = 1053,
  [SMALL_STATE(35)] = 1080,
  [SMALL_STATE(36)] = 1092,
  [SMALL_STATE(37)] = 1104,
  [SMALL_STATE(38)] = 1116,
  [SMALL_STATE(39)] = 1142,
  [SMALL_STATE(40)] = 1154,
  [SMALL_STATE(41)] = 1180,
  [SMALL_STATE(42)] = 1192,
  [SMALL_STATE(43)] = 1204,
  [SMALL_STATE(44)] = 1216,
  [SMALL_STATE(45)] = 1228,
  [SMALL_STATE(46)] = 1254,
  [SMALL_STATE(47)] = 1266,
  [SMALL_STATE(48)] = 1278,
  [SMALL_STATE(49)] = 1290,
  [SMALL_STATE(50)] = 1302,
  [SMALL_STATE(51)] = 1328,
  [SMALL_STATE(52)] = 1340,
  [SMALL_STATE(53)] = 1352,
  [SMALL_STATE(54)] = 1364,
  [SMALL_STATE(55)] = 1380,
  [SMALL_STATE(56)] = 1392,
  [SMALL_STATE(57)] = 1404,
  [SMALL_STATE(58)] = 1416,
  [SMALL_STATE(59)] = 1432,
  [SMALL_STATE(60)] = 1443,
  [SMALL_STATE(61)] = 1466,
  [SMALL_STATE(62)] = 1477,
  [SMALL_STATE(63)] = 1496,
  [SMALL_STATE(64)] = 1515,
  [SMALL_STATE(65)] = 1534,
  [SMALL_STATE(66)] = 1553,
  [SMALL_STATE(67)] = 1566,
  [SMALL_STATE(68)] = 1585,
  [SMALL_STATE(69)] = 1598,
  [SMALL_STATE(70)] = 1607,
  [SMALL_STATE(71)] = 1616,
  [SMALL_STATE(72)] = 1625,
  [SMALL_STATE(73)] = 1638,
  [SMALL_STATE(74)] = 1647,
  [SMALL_STATE(75)] = 1666,
  [SMALL_STATE(76)] = 1681,
  [SMALL_STATE(77)] = 1690,
  [SMALL_STATE(78)] = 1699,
  [SMALL_STATE(79)] = 1708,
  [SMALL_STATE(80)] = 1721,
  [SMALL_STATE(81)] = 1737,
  [SMALL_STATE(82)] = 1753,
  [SMALL_STATE(83)] = 1769,
  [SMALL_STATE(84)] = 1785,
  [SMALL_STATE(85)] = 1801,
  [SMALL_STATE(86)] = 1817,
  [SMALL_STATE(87)] = 1825,
  [SMALL_STATE(88)] = 1841,
  [SMALL_STATE(89)] = 1851,
  [SMALL_STATE(90)] = 1867,
  [SMALL_STATE(91)] = 1883,
  [SMALL_STATE(92)] = 1899,
  [SMALL_STATE(93)] = 1915,
  [SMALL_STATE(94)] = 1931,
  [SMALL_STATE(95)] = 1947,
  [SMALL_STATE(96)] = 1963,
  [SMALL_STATE(97)] = 1979,
  [SMALL_STATE(98)] = 1995,
  [SMALL_STATE(99)] = 2011,
  [SMALL_STATE(100)] = 2027,
  [SMALL_STATE(101)] = 2043,
  [SMALL_STATE(102)] = 2059,
  [SMALL_STATE(103)] = 2072,
  [SMALL_STATE(104)] = 2085,
  [SMALL_STATE(105)] = 2098,
  [SMALL_STATE(106)] = 2111,
  [SMALL_STATE(107)] = 2124,
  [SMALL_STATE(108)] = 2131,
  [SMALL_STATE(109)] = 2142,
  [SMALL_STATE(110)] = 2151,
  [SMALL_STATE(111)] = 2164,
  [SMALL_STATE(112)] = 2177,
  [SMALL_STATE(113)] = 2190,
  [SMALL_STATE(114)] = 2203,
  [SMALL_STATE(115)] = 2210,
  [SMALL_STATE(116)] = 2219,
  [SMALL_STATE(117)] = 2232,
  [SMALL_STATE(118)] = 2241,
  [SMALL_STATE(119)] = 2254,
  [SMALL_STATE(120)] = 2263,
  [SMALL_STATE(121)] = 2272,
  [SMALL_STATE(122)] = 2285,
  [SMALL_STATE(123)] = 2292,
  [SMALL_STATE(124)] = 2305,
  [SMALL_STATE(125)] = 2318,
  [SMALL_STATE(126)] = 2326,
  [SMALL_STATE(127)] = 2336,
  [SMALL_STATE(128)] = 2342,
  [SMALL_STATE(129)] = 2350,
  [SMALL_STATE(130)] = 2358,
  [SMALL_STATE(131)] = 2368,
  [SMALL_STATE(132)] = 2374,
  [SMALL_STATE(133)] = 2382,
  [SMALL_STATE(134)] = 2392,
  [SMALL_STATE(135)] = 2398,
  [SMALL_STATE(136)] = 2408,
  [SMALL_STATE(137)] = 2414,
  [SMALL_STATE(138)] = 2422,
  [SMALL_STATE(139)] = 2428,
  [SMALL_STATE(140)] = 2438,
  [SMALL_STATE(141)] = 2448,
  [SMALL_STATE(142)] = 2454,
  [SMALL_STATE(143)] = 2464,
  [SMALL_STATE(144)] = 2470,
  [SMALL_STATE(145)] = 2480,
  [SMALL_STATE(146)] = 2490,
  [SMALL_STATE(147)] = 2500,
  [SMALL_STATE(148)] = 2510,
  [SMALL_STATE(149)] = 2517,
  [SMALL_STATE(150)] = 2524,
  [SMALL_STATE(151)] = 2531,
  [SMALL_STATE(152)] = 2538,
  [SMALL_STATE(153)] = 2545,
  [SMALL_STATE(154)] = 2552,
  [SMALL_STATE(155)] = 2559,
  [SMALL_STATE(156)] = 2566,
  [SMALL_STATE(157)] = 2573,
  [SMALL_STATE(158)] = 2580,
  [SMALL_STATE(159)] = 2587,
  [SMALL_STATE(160)] = 2594,
  [SMALL_STATE(161)] = 2601,
  [SMALL_STATE(162)] = 2608,
  [SMALL_STATE(163)] = 2615,
  [SMALL_STATE(164)] = 2620,
  [SMALL_STATE(165)] = 2625,
  [SMALL_STATE(166)] = 2630,
  [SMALL_STATE(167)] = 2637,
  [SMALL_STATE(168)] = 2644,
  [SMALL_STATE(169)] = 2651,
  [SMALL_STATE(170)] = 2656,
  [SMALL_STATE(171)] = 2663,
  [SMALL_STATE(172)] = 2668,
  [SMALL_STATE(173)] = 2673,
  [SMALL_STATE(174)] = 2680,
  [SMALL_STATE(175)] = 2687,
  [SMALL_STATE(176)] = 2692,
  [SMALL_STATE(177)] = 2697,
  [SMALL_STATE(178)] = 2704,
  [SMALL_STATE(179)] = 2709,
  [SMALL_STATE(180)] = 2716,
  [SMALL_STATE(181)] = 2723,
  [SMALL_STATE(182)] = 2730,
  [SMALL_STATE(183)] = 2735,
  [SMALL_STATE(184)] = 2742,
  [SMALL_STATE(185)] = 2747,
  [SMALL_STATE(186)] = 2752,
  [SMALL_STATE(187)] = 2759,
  [SMALL_STATE(188)] = 2766,
  [SMALL_STATE(189)] = 2773,
  [SMALL_STATE(190)] = 2778,
  [SMALL_STATE(191)] = 2785,
  [SMALL_STATE(192)] = 2792,
  [SMALL_STATE(193)] = 2799,
  [SMALL_STATE(194)] = 2806,
  [SMALL_STATE(195)] = 2813,
  [SMALL_STATE(196)] = 2818,
  [SMALL_STATE(197)] = 2823,
  [SMALL_STATE(198)] = 2830,
  [SMALL_STATE(199)] = 2837,
  [SMALL_STATE(200)] = 2844,
  [SMALL_STATE(201)] = 2851,
  [SMALL_STATE(202)] = 2855,
  [SMALL_STATE(203)] = 2859,
  [SMALL_STATE(204)] = 2863,
  [SMALL_STATE(205)] = 2867,
  [SMALL_STATE(206)] = 2871,
  [SMALL_STATE(207)] = 2875,
  [SMALL_STATE(208)] = 2879,
  [SMALL_STATE(209)] = 2883,
  [SMALL_STATE(210)] = 2887,
  [SMALL_STATE(211)] = 2891,
  [SMALL_STATE(212)] = 2895,
  [SMALL_STATE(213)] = 2899,
  [SMALL_STATE(214)] = 2903,
  [SMALL_STATE(215)] = 2907,
  [SMALL_STATE(216)] = 2911,
  [SMALL_STATE(217)] = 2915,
  [SMALL_STATE(218)] = 2919,
  [SMALL_STATE(219)] = 2923,
  [SMALL_STATE(220)] = 2927,
  [SMALL_STATE(221)] = 2931,
  [SMALL_STATE(222)] = 2935,
  [SMALL_STATE(223)] = 2939,
  [SMALL_STATE(224)] = 2943,
  [SMALL_STATE(225)] = 2947,
  [SMALL_STATE(226)] = 2951,
  [SMALL_STATE(227)] = 2955,
  [SMALL_STATE(228)] = 2959,
  [SMALL_STATE(229)] = 2963,
  [SMALL_STATE(230)] = 2967,
  [SMALL_STATE(231)] = 2971,
  [SMALL_STATE(232)] = 2975,
  [SMALL_STATE(233)] = 2979,
  [SMALL_STATE(234)] = 2983,
  [SMALL_STATE(235)] = 2987,
  [SMALL_STATE(236)] = 2991,
  [SMALL_STATE(237)] = 2995,
  [SMALL_STATE(238)] = 2999,
  [SMALL_STATE(239)] = 3003,
  [SMALL_STATE(240)] = 3007,
  [SMALL_STATE(241)] = 3011,
  [SMALL_STATE(242)] = 3015,
  [SMALL_STATE(243)] = 3019,
  [SMALL_STATE(244)] = 3023,
  [SMALL_STATE(245)] = 3027,
  [SMALL_STATE(246)] = 3031,
  [SMALL_STATE(247)] = 3035,
  [SMALL_STATE(248)] = 3039,
  [SMALL_STATE(249)] = 3043,
  [SMALL_STATE(250)] = 3047,
  [SMALL_STATE(251)] = 3051,
  [SMALL_STATE(252)] = 3055,
  [SMALL_STATE(253)] = 3059,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(121),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(227),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(203),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(251),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(215),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(237),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_content, 1, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(241),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_block, 1, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_block, 1, 0, 0),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0), SHIFT_REPEAT(106),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0),
  [130] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(58),
  [133] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(148),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(142),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 5, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 4, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 4, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 4, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 3, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 2, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 1, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 5, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 5, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 4, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 5, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 5, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 6, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 8, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 6, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 7, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 6, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 7, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 5, 0, 0),
  [187] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [190] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 6, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 1, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_block, 4, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref_block, 4, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 1, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 2, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 2, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 6, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 7, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 8, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0),
  [233] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(214),
  [236] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [240] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [242] = {.entry = {.count = 1, .reusable = false}}, SHIFT(192),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0),
  [250] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(128),
  [253] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(114),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0),
  [258] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(132),
  [261] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(122),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 1, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [290] = {.entry = {.count = 1, .reusable = false}}, SHIFT(190),
  [292] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 2, 0, 0),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [303] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 3, 0, 0),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_value, 1, 0, 0),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 5, 0, 0),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 5, 0, 0),
  [320] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [329] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(209),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0),
  [334] = {.entry = {.count = 1, .reusable = false}}, SHIFT(207),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [340] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 6, 0, 0),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 6, 0, 0),
  [344] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 7, 0, 0),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 7, 0, 0),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [350] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_block, 4, 0, 0),
  [352] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_content, 1, 0, 0),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_content, 1, 0, 0),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 3, 0, 0),
  [362] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [366] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(246),
  [369] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 2, 0, 0),
  [371] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 2, 0, 0),
  [381] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 1, 0, 0),
  [383] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 1, 0, 0),
  [385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 3, 0, 1),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [391] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 1, 0, 0),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [395] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 2, 0, 0),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0),
  [399] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0), SHIFT_REPEAT(139),
  [402] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateValue, 6, 0, 0),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [406] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 1, 0, 0),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [410] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(146),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(252),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [437] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_booleanValue, 1, 0, 0),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_extends_block, 2, 0, 0),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [453] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_definition, 2, 0, 0),
  [455] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byteValue, 2, 0, 0),
  [457] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_longValue, 2, 0, 0),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doubleValue, 3, 0, 0),
  [469] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateTimeValue, 3, 0, 0),
  [471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [473] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(86),
  [476] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeValue, 5, 0, 0),
  [480] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 2, 0, 0),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [484] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 3, 0, 1),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [490] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_index, 1, 0, 0),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [494] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(196),
  [497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [501] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [509] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 6, 0, 0),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_identifier, 6, 0, 0),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 5, 0, 0),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_identifier, 4, 0, 0),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [549] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dmf_declaration, 2, 0, 0),
  [551] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_version_number, 5, 0, 0),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 5, 0, 0),
  [565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_declaration, 4, 0, 0),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [571] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [583] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 6, 0, 0),
  [585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
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
