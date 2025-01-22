#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 266
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 130
#define ALIAS_COUNT 1
#define TOKEN_COUNT 67
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 9
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
  anon_sym_LT = 12,
  anon_sym_GT = 13,
  anon_sym_Map = 14,
  anon_sym_Set = 15,
  anon_sym_List = 16,
  anon_sym_func = 17,
  anon_sym_enum = 18,
  anon_sym__ = 19,
  anon_sym_entity = 20,
  anon_sym_identifier = 21,
  anon_sym_interface = 22,
  sym_number = 23,
  sym_identifier = 24,
  sym_comment = 25,
  sym_dot = 26,
  sym_byte_content = 27,
  anon_sym_SEMI = 28,
  anon_sym_COMMA = 29,
  anon_sym_LBRACE = 30,
  anon_sym_RBRACE = 31,
  anon_sym_LPAREN = 32,
  anon_sym_RPAREN = 33,
  sym__new_line = 34,
  sym_expand = 35,
  sym_byte = 36,
  sym_int = 37,
  sym_long = 38,
  sym_double = 39,
  sym_datetime = 40,
  sym_date = 41,
  sym_string = 42,
  sym_boolean = 43,
  sym_void = 44,
  anon_sym_L = 45,
  anon_sym_true = 46,
  anon_sym_false = 47,
  anon_sym_0x = 48,
  anon_sym_DQUOTE = 49,
  anon_sym_SQUOTE = 50,
  sym_string_content_single_quote = 51,
  sym_string_content_double_quote = 52,
  anon_sym_BSLASH = 53,
  aux_sym_escape_sequence_token1 = 54,
  aux_sym_escape_sequence_token2 = 55,
  aux_sym_escape_sequence_token3 = 56,
  aux_sym_escape_sequence_token4 = 57,
  anon_sym_T = 58,
  aux_sym_timeValue_token1 = 59,
  anon_sym_COLON = 60,
  aux_sym_timeValue_token2 = 61,
  anon_sym_D = 62,
  aux_sym_dateValue_token1 = 63,
  anon_sym_DASH = 64,
  aux_sym_dateValue_token2 = 65,
  aux_sym_dateValue_token3 = 66,
  sym_source_file = 67,
  sym_dmf_declaration = 68,
  sym_model_declaration = 69,
  sym_import_block = 70,
  sym_import_statement = 71,
  sym_model_identifier = 72,
  sym_model_content = 73,
  sym_comment_block = 74,
  sym_package_block = 75,
  sym_package_content = 76,
  sym_struct_block = 77,
  sym_extends_block = 78,
  sym_implements_block = 79,
  sym_struct_content = 80,
  sym_arg_block = 81,
  sym_ref_block = 82,
  sym_multi_block = 83,
  sym_multi_name = 84,
  sym_func_block = 85,
  sym_param_definition = 86,
  sym_enum_block = 87,
  sym_enum_content = 88,
  sym_enum_constant = 89,
  sym_enum_index = 90,
  sym_entity_block = 91,
  sym_identifier_statement = 92,
  sym_interface_block = 93,
  sym_interface_content = 94,
  sym__semicolon = 95,
  sym__comma = 96,
  sym__left_brace = 97,
  sym__right_brace = 98,
  sym__left_paren = 99,
  sym__right_paren = 100,
  sym_reftype = 101,
  sym_package_string = 102,
  sym_primitive_type = 103,
  sym_primitive_value = 104,
  sym_version_number = 105,
  sym_integerValue = 106,
  sym_longValue = 107,
  sym_booleanValue = 108,
  sym_byteValue = 109,
  sym_doubleValue = 110,
  sym_stringValue = 111,
  sym_escape_sequence = 112,
  sym_dateTimeValue = 113,
  sym_timeValue = 114,
  sym_dateValue = 115,
  aux_sym_import_block_repeat1 = 116,
  aux_sym_model_content_repeat1 = 117,
  aux_sym_comment_block_repeat1 = 118,
  aux_sym_struct_block_repeat1 = 119,
  aux_sym_implements_block_repeat1 = 120,
  aux_sym_func_block_repeat1 = 121,
  aux_sym_enum_block_repeat1 = 122,
  aux_sym_enum_constant_repeat1 = 123,
  aux_sym_identifier_statement_repeat1 = 124,
  aux_sym_interface_block_repeat1 = 125,
  aux_sym_reftype_repeat1 = 126,
  aux_sym_package_string_repeat1 = 127,
  aux_sym_stringValue_repeat1 = 128,
  aux_sym_stringValue_repeat2 = 129,
  anon_alias_sym_content = 130,
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
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_Map] = "Map",
  [anon_sym_Set] = "Set",
  [anon_sym_List] = "List",
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
  [sym_multi_block] = "multi_block",
  [sym_multi_name] = "multi_name",
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
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_Map] = anon_sym_Map,
  [anon_sym_Set] = anon_sym_Set,
  [anon_sym_List] = anon_sym_List,
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
  [sym_multi_block] = sym_multi_block,
  [sym_multi_name] = sym_multi_name,
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
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Map] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Set] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_List] = {
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
  [sym_multi_block] = {
    .visible = true,
    .named = true,
  },
  [sym_multi_name] = {
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
  [56] = 43,
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
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 86,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 88,
  [103] = 99,
  [104] = 96,
  [105] = 100,
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
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 70,
  [125] = 125,
  [126] = 126,
  [127] = 110,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 68,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 31,
  [140] = 140,
  [141] = 65,
  [142] = 67,
  [143] = 29,
  [144] = 144,
  [145] = 69,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 140,
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
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 152,
  [195] = 151,
  [196] = 196,
  [197] = 197,
  [198] = 198,
  [199] = 78,
  [200] = 200,
  [201] = 161,
  [202] = 202,
  [203] = 203,
  [204] = 204,
  [205] = 205,
  [206] = 206,
  [207] = 200,
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
  [236] = 236,
  [237] = 237,
  [238] = 230,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 243,
  [244] = 244,
  [245] = 245,
  [246] = 246,
  [247] = 247,
  [248] = 122,
  [249] = 249,
  [250] = 118,
  [251] = 251,
  [252] = 252,
  [253] = 253,
  [254] = 253,
  [255] = 255,
  [256] = 256,
  [257] = 257,
  [258] = 220,
  [259] = 259,
  [260] = 242,
  [261] = 255,
  [262] = 225,
  [263] = 263,
  [264] = 247,
  [265] = 265,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(157);
      ADVANCE_MAP(
        '"', 263,
        '\'', 264,
        '(', 236,
        ')', 237,
        ',', 233,
        '-', 282,
        '.', 230,
        '/', 10,
        ':', 278,
        ';', 232,
        '<', 170,
        '>', 171,
        'D', 280,
        'L', 259,
        'M', 11,
        'S', 40,
        'T', 276,
        '\\', 269,
        '_', 180,
        'a', 100,
        'd', 13,
        'e', 78,
        'i', 28,
        'l', 90,
        'm', 91,
        'p', 12,
        's', 120,
        'u', 153,
        'v', 44,
        'x', 150,
        '{', 234,
        '}', 235,
        '8', 187,
        '9', 187,
        'b', 270,
        'f', 270,
        'n', 270,
        'r', 270,
        't', 270,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(154);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(186);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(229);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(238);
      if (lookahead == '(') ADVANCE(236);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(263);
      if (lookahead == '\\') ADVANCE(269);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(267);
      if (lookahead != 0) ADVANCE(268);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(264);
      if (lookahead == '\\') ADVANCE(269);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(265);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        ')', 237,
        '.', 230,
        '2', 136,
        'b', 215,
        'd', 189,
        'i', 212,
        'l', 214,
        's', 221,
        '0', 139,
        '1', 139,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 6:
      if (lookahead == ',') ADVANCE(233);
      if (lookahead == '.') ADVANCE(230);
      if (lookahead == '/') ADVANCE(10);
      if (lookahead == '0') ADVANCE(138);
      if (lookahead == '3') ADVANCE(134);
      if (lookahead == '>') ADVANCE(171);
      if (lookahead == '1' ||
          lookahead == '2') ADVANCE(142);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(230);
      if (lookahead == 'L') ADVANCE(204);
      if (lookahead == 'M') ADVANCE(188);
      if (lookahead == 'S') ADVANCE(198);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '5')) ADVANCE(141);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(230);
      if (lookahead == 'b') ADVANCE(215);
      if (lookahead == 'd') ADVANCE(189);
      if (lookahead == 'i') ADVANCE(212);
      if (lookahead == 'l') ADVANCE(214);
      if (lookahead == 's') ADVANCE(221);
      if (lookahead == 'v') ADVANCE(216);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 9:
      if (lookahead == '/') ADVANCE(10);
      if (lookahead == '0') ADVANCE(137);
      if (lookahead == '1') ADVANCE(135);
      if (lookahead == 'a') ADVANCE(219);
      if (lookahead == '}') ADVANCE(235);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 10:
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(96);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(22);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(121);
      if (lookahead == 'm') ADVANCE(51);
      if (lookahead == 'o') ADVANCE(130);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(121);
      if (lookahead == 'o') ADVANCE(130);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(58);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(83);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(71);
      if (lookahead == 'r') ADVANCE(94);
      if (lookahead == 'u') ADVANCE(84);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(25);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(81);
      END_STATE();
    case 20:
      if (lookahead == 'b') ADVANCE(72);
      END_STATE();
    case 21:
      if (lookahead == 'b') ADVANCE(92);
      if (lookahead == 'd') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(85);
      if (lookahead == 'l') ADVANCE(90);
      if (lookahead == 's') ADVANCE(126);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(21);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(147);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(68);
      END_STATE();
    case 23:
      if (lookahead == 'c') ADVANCE(178);
      END_STATE();
    case 24:
      if (lookahead == 'c') ADVANCE(119);
      END_STATE();
    case 25:
      if (lookahead == 'c') ADVANCE(38);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(256);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(239);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(41);
      if (lookahead == 'm') ADVANCE(97);
      if (lookahead == 'n') ADVANCE(115);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(41);
      if (lookahead == 'm') ADVANCE(97);
      if (lookahead == 'n') ADVANCE(127);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(109);
      END_STATE();
    case 31:
      if (lookahead == 'd') ADVANCE(43);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(251);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(246);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(163);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(248);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(260);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(261);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(183);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(240);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(114);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(77);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(69);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(103);
      if (lookahead == 'o') ADVANCE(61);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(102);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(106);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(87);
      END_STATE();
    case 51:
      if (lookahead == 'f') ADVANCE(158);
      END_STATE();
    case 52:
      if (lookahead == 'f') ADVANCE(169);
      END_STATE();
    case 53:
      if (lookahead == 'f') ADVANCE(18);
      END_STATE();
    case 54:
      if (lookahead == 'f') ADVANCE(64);
      END_STATE();
    case 55:
      if (lookahead == 'g') ADVANCE(167);
      END_STATE();
    case 56:
      if (lookahead == 'g') ADVANCE(244);
      END_STATE();
    case 57:
      if (lookahead == 'g') ADVANCE(252);
      END_STATE();
    case 58:
      if (lookahead == 'g') ADVANCE(34);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(112);
      END_STATE();
    case 60:
      if (lookahead == 'i') ADVANCE(54);
      END_STATE();
    case 61:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 62:
      if (lookahead == 'i') ADVANCE(76);
      END_STATE();
    case 63:
      if (lookahead == 'i') ADVANCE(117);
      END_STATE();
    case 64:
      if (lookahead == 'i') ADVANCE(46);
      END_STATE();
    case 65:
      if (lookahead == 'i') ADVANCE(93);
      END_STATE();
    case 66:
      if (lookahead == 'i') ADVANCE(86);
      END_STATE();
    case 67:
      if (lookahead == 'i') ADVANCE(86);
      if (lookahead == 'u') ADVANCE(24);
      END_STATE();
    case 68:
      if (lookahead == 'k') ADVANCE(15);
      END_STATE();
    case 69:
      if (lookahead == 'l') ADVANCE(159);
      END_STATE();
    case 70:
      if (lookahead == 'l') ADVANCE(42);
      if (lookahead == 'o') ADVANCE(107);
      END_STATE();
    case 71:
      if (lookahead == 'l') ADVANCE(113);
      END_STATE();
    case 72:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 73:
      if (lookahead == 'l') ADVANCE(49);
      END_STATE();
    case 74:
      if (lookahead == 'm') ADVANCE(179);
      END_STATE();
    case 75:
      if (lookahead == 'm') ADVANCE(162);
      END_STATE();
    case 76:
      if (lookahead == 'm') ADVANCE(35);
      END_STATE();
    case 77:
      if (lookahead == 'm') ADVANCE(48);
      END_STATE();
    case 78:
      if (lookahead == 'n') ADVANCE(122);
      if (lookahead == 'x') ADVANCE(99);
      END_STATE();
    case 79:
      if (lookahead == 'n') ADVANCE(122);
      if (lookahead == 'x') ADVANCE(98);
      END_STATE();
    case 80:
      if (lookahead == 'n') ADVANCE(160);
      END_STATE();
    case 81:
      if (lookahead == 'n') ADVANCE(254);
      END_STATE();
    case 82:
      if (lookahead == 'n') ADVANCE(56);
      END_STATE();
    case 83:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 84:
      if (lookahead == 'n') ADVANCE(23);
      END_STATE();
    case 85:
      if (lookahead == 'n') ADVANCE(115);
      END_STATE();
    case 86:
      if (lookahead == 'n') ADVANCE(57);
      END_STATE();
    case 87:
      if (lookahead == 'n') ADVANCE(30);
      END_STATE();
    case 88:
      if (lookahead == 'n') ADVANCE(124);
      END_STATE();
    case 89:
      if (lookahead == 'n') ADVANCE(123);
      END_STATE();
    case 90:
      if (lookahead == 'o') ADVANCE(82);
      END_STATE();
    case 91:
      if (lookahead == 'o') ADVANCE(31);
      END_STATE();
    case 92:
      if (lookahead == 'o') ADVANCE(95);
      if (lookahead == 'y') ADVANCE(128);
      END_STATE();
    case 93:
      if (lookahead == 'o') ADVANCE(80);
      END_STATE();
    case 94:
      if (lookahead == 'o') ADVANCE(75);
      END_STATE();
    case 95:
      if (lookahead == 'o') ADVANCE(73);
      END_STATE();
    case 96:
      if (lookahead == 'p') ADVANCE(172);
      END_STATE();
    case 97:
      if (lookahead == 'p') ADVANCE(70);
      END_STATE();
    case 98:
      if (lookahead == 'p') ADVANCE(16);
      END_STATE();
    case 99:
      if (lookahead == 'p') ADVANCE(16);
      if (lookahead == 't') ADVANCE(50);
      END_STATE();
    case 100:
      if (lookahead == 'r') ADVANCE(55);
      END_STATE();
    case 101:
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 102:
      if (lookahead == 'r') ADVANCE(182);
      END_STATE();
    case 103:
      if (lookahead == 'r') ADVANCE(111);
      END_STATE();
    case 104:
      if (lookahead == 'r') ADVANCE(132);
      END_STATE();
    case 105:
      if (lookahead == 'r') ADVANCE(131);
      END_STATE();
    case 106:
      if (lookahead == 'r') ADVANCE(53);
      END_STATE();
    case 107:
      if (lookahead == 'r') ADVANCE(118);
      END_STATE();
    case 108:
      if (lookahead == 'r') ADVANCE(66);
      END_STATE();
    case 109:
      if (lookahead == 's') ADVANCE(165);
      END_STATE();
    case 110:
      if (lookahead == 's') ADVANCE(166);
      END_STATE();
    case 111:
      if (lookahead == 's') ADVANCE(65);
      END_STATE();
    case 112:
      if (lookahead == 's') ADVANCE(116);
      END_STATE();
    case 113:
      if (lookahead == 's') ADVANCE(37);
      END_STATE();
    case 114:
      if (lookahead == 't') ADVANCE(174);
      END_STATE();
    case 115:
      if (lookahead == 't') ADVANCE(242);
      END_STATE();
    case 116:
      if (lookahead == 't') ADVANCE(176);
      END_STATE();
    case 117:
      if (lookahead == 't') ADVANCE(133);
      END_STATE();
    case 118:
      if (lookahead == 't') ADVANCE(161);
      END_STATE();
    case 119:
      if (lookahead == 't') ADVANCE(164);
      END_STATE();
    case 120:
      if (lookahead == 't') ADVANCE(101);
      END_STATE();
    case 121:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 122:
      if (lookahead == 't') ADVANCE(63);
      if (lookahead == 'u') ADVANCE(74);
      END_STATE();
    case 123:
      if (lookahead == 't') ADVANCE(110);
      END_STATE();
    case 124:
      if (lookahead == 't') ADVANCE(60);
      END_STATE();
    case 125:
      if (lookahead == 't') ADVANCE(105);
      END_STATE();
    case 126:
      if (lookahead == 't') ADVANCE(108);
      END_STATE();
    case 127:
      if (lookahead == 't') ADVANCE(47);
      END_STATE();
    case 128:
      if (lookahead == 't') ADVANCE(39);
      END_STATE();
    case 129:
      if (lookahead == 'u') ADVANCE(153);
      if (lookahead == 'x') ADVANCE(150);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(129);
      if (lookahead == '"' ||
          lookahead == '\'' ||
          lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'f' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(275);
      END_STATE();
    case 130:
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 131:
      if (lookahead == 'u') ADVANCE(24);
      END_STATE();
    case 132:
      if (lookahead == 'u') ADVANCE(36);
      END_STATE();
    case 133:
      if (lookahead == 'y') ADVANCE(181);
      END_STATE();
    case 134:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(284);
      END_STATE();
    case 135:
      if (('0' <= lookahead && lookahead <= '2')) ADVANCE(283);
      END_STATE();
    case 136:
      if (('0' <= lookahead && lookahead <= '3')) ADVANCE(277);
      END_STATE();
    case 137:
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(283);
      END_STATE();
    case 138:
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(284);
      END_STATE();
    case 139:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(277);
      END_STATE();
    case 140:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(281);
      END_STATE();
    case 141:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(279);
      END_STATE();
    case 142:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(284);
      END_STATE();
    case 143:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(140);
      END_STATE();
    case 144:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(143);
      END_STATE();
    case 145:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(231);
      END_STATE();
    case 146:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(145);
      END_STATE();
    case 147:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(146);
      END_STATE();
    case 148:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(272);
      END_STATE();
    case 149:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(271);
      END_STATE();
    case 150:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(148);
      END_STATE();
    case 151:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(149);
      END_STATE();
    case 152:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(151);
      END_STATE();
    case 153:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(152);
      END_STATE();
    case 154:
      if (eof) ADVANCE(157);
      ADVANCE_MAP(
        '"', 263,
        '\'', 264,
        '(', 236,
        ')', 237,
        ',', 233,
        '-', 282,
        '.', 230,
        '/', 10,
        ':', 278,
        ';', 232,
        '<', 170,
        '>', 171,
        'D', 280,
        'L', 59,
        'M', 11,
        'S', 40,
        'T', 276,
        '\\', 269,
        '_', 180,
        'a', 100,
        'd', 13,
        'e', 78,
        'i', 28,
        'l', 90,
        'm', 91,
        'p', 12,
        's', 120,
        'u', 153,
        'v', 44,
        'x', 150,
        '{', 234,
        '}', 235,
        '8', 187,
        '9', 187,
        'b', 270,
        'f', 270,
        'n', 270,
        'r', 270,
        't', 270,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(154);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(186);
      END_STATE();
    case 155:
      if (eof) ADVANCE(157);
      ADVANCE_MAP(
        '"', 263,
        '\'', 264,
        ')', 237,
        ',', 233,
        '.', 230,
        '/', 10,
        '0', 184,
        '>', 171,
        'D', 280,
        'L', 258,
        '_', 180,
        'a', 100,
        'e', 79,
        'f', 17,
        'i', 29,
        'p', 12,
        'r', 45,
        's', 125,
        't', 104,
        '{', 234,
        '}', 235,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(156);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 156:
      if (eof) ADVANCE(157);
      ADVANCE_MAP(
        '"', 263,
        '\'', 264,
        ')', 237,
        ',', 233,
        '.', 230,
        '/', 10,
        '0', 184,
        '>', 171,
        'D', 280,
        '_', 180,
        'a', 100,
        'e', 79,
        'f', 17,
        'i', 29,
        'p', 12,
        'r', 45,
        's', 125,
        't', 104,
        '{', 234,
        '}', 235,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(156);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_dmf);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_model);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_version);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_from);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_struct);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_extends);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_implements);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_arg);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_arg);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_ref);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_Map);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_Map);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_Set);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_Set);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_List);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_List);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_identifier);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_interface);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'x') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(187);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(185);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(217);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(226);
      if (lookahead == 'o') ADVANCE(227);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(210);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(207);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(257);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(241);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(250);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(190);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(247);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(224);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(245);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(253);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(168);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(208);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(192);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(220);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(211);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(195);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(196);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(199);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(255);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(200);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(223);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(206);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(209);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(213);
      if (lookahead == 'y') ADVANCE(222);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(203);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(173);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(201);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(225);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(218);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(193);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(243);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(175);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(177);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(194);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(191);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_byte_content);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym__new_line);
      if (lookahead == '\n') ADVANCE(238);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_expand);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_byte);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_byte);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_int);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_int);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_long);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_long);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_double);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_double);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_datetime);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_datetime);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == 't') ADVANCE(202);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == 't') ADVANCE(62);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_string);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_boolean);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_boolean);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_void);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_void);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(anon_sym_L);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(anon_sym_L);
      if (lookahead == 'i') ADVANCE(112);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(anon_sym_0x);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_string_content_single_quote);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(265);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(266);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_string_content_single_quote);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(266);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_string_content_double_quote);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(267);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(268);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_string_content_double_quote);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(268);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token2);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token3);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token4);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token4);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(273);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token4);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(274);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(anon_sym_T);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(aux_sym_timeValue_token1);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(aux_sym_timeValue_token2);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_D);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(aux_sym_dateValue_token1);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(aux_sym_dateValue_token2);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(aux_sym_dateValue_token3);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 155},
  [3] = {.lex_state = 155},
  [4] = {.lex_state = 155},
  [5] = {.lex_state = 155},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 155},
  [8] = {.lex_state = 155},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 8},
  [11] = {.lex_state = 155},
  [12] = {.lex_state = 5},
  [13] = {.lex_state = 5},
  [14] = {.lex_state = 155},
  [15] = {.lex_state = 155},
  [16] = {.lex_state = 155},
  [17] = {.lex_state = 155},
  [18] = {.lex_state = 155},
  [19] = {.lex_state = 155},
  [20] = {.lex_state = 155},
  [21] = {.lex_state = 155},
  [22] = {.lex_state = 155},
  [23] = {.lex_state = 155},
  [24] = {.lex_state = 155},
  [25] = {.lex_state = 155},
  [26] = {.lex_state = 155},
  [27] = {.lex_state = 9},
  [28] = {.lex_state = 9},
  [29] = {.lex_state = 155},
  [30] = {.lex_state = 155},
  [31] = {.lex_state = 155},
  [32] = {.lex_state = 155},
  [33] = {.lex_state = 155},
  [34] = {.lex_state = 7},
  [35] = {.lex_state = 155},
  [36] = {.lex_state = 9},
  [37] = {.lex_state = 155},
  [38] = {.lex_state = 155},
  [39] = {.lex_state = 155},
  [40] = {.lex_state = 155},
  [41] = {.lex_state = 155},
  [42] = {.lex_state = 155},
  [43] = {.lex_state = 21},
  [44] = {.lex_state = 155},
  [45] = {.lex_state = 155},
  [46] = {.lex_state = 155},
  [47] = {.lex_state = 155},
  [48] = {.lex_state = 155},
  [49] = {.lex_state = 155},
  [50] = {.lex_state = 155},
  [51] = {.lex_state = 155},
  [52] = {.lex_state = 155},
  [53] = {.lex_state = 155},
  [54] = {.lex_state = 155},
  [55] = {.lex_state = 155},
  [56] = {.lex_state = 21},
  [57] = {.lex_state = 155},
  [58] = {.lex_state = 155},
  [59] = {.lex_state = 155},
  [60] = {.lex_state = 155},
  [61] = {.lex_state = 155},
  [62] = {.lex_state = 155},
  [63] = {.lex_state = 155},
  [64] = {.lex_state = 155},
  [65] = {.lex_state = 155},
  [66] = {.lex_state = 155},
  [67] = {.lex_state = 155},
  [68] = {.lex_state = 155},
  [69] = {.lex_state = 155},
  [70] = {.lex_state = 155},
  [71] = {.lex_state = 155},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 155},
  [74] = {.lex_state = 6},
  [75] = {.lex_state = 155},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 6},
  [78] = {.lex_state = 155},
  [79] = {.lex_state = 6},
  [80] = {.lex_state = 155},
  [81] = {.lex_state = 155},
  [82] = {.lex_state = 155},
  [83] = {.lex_state = 155},
  [84] = {.lex_state = 155},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 4},
  [87] = {.lex_state = 155},
  [88] = {.lex_state = 6},
  [89] = {.lex_state = 3},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 4},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 4},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 4},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 3},
  [100] = {.lex_state = 3},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 6},
  [103] = {.lex_state = 3},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 3},
  [106] = {.lex_state = 155},
  [107] = {.lex_state = 6},
  [108] = {.lex_state = 9},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 129},
  [111] = {.lex_state = 9},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 155},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 2},
  [116] = {.lex_state = 9},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 9},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 9},
  [125] = {.lex_state = 155},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 129},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 155},
  [130] = {.lex_state = 6},
  [131] = {.lex_state = 6},
  [132] = {.lex_state = 3},
  [133] = {.lex_state = 4},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 155},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 6},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 6},
  [140] = {.lex_state = 4},
  [141] = {.lex_state = 6},
  [142] = {.lex_state = 6},
  [143] = {.lex_state = 6},
  [144] = {.lex_state = 155},
  [145] = {.lex_state = 6},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 6},
  [148] = {.lex_state = 155},
  [149] = {.lex_state = 3},
  [150] = {.lex_state = 155},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 155},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 6},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 155},
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
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 155},
  [180] = {.lex_state = 155},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 5},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 155},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 2},
  [195] = {.lex_state = 2},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 155},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 6},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 6},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 155},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 21},
  [212] = {.lex_state = 8},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 2},
  [215] = {.lex_state = 2},
  [216] = {.lex_state = 6},
  [217] = {.lex_state = 6},
  [218] = {.lex_state = 6},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 6},
  [221] = {.lex_state = 9},
  [222] = {.lex_state = 6},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 6},
  [225] = {.lex_state = 155},
  [226] = {.lex_state = 6},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 7},
  [230] = {.lex_state = 2},
  [231] = {.lex_state = 6},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 0},
  [234] = {.lex_state = 7},
  [235] = {.lex_state = 6},
  [236] = {.lex_state = 2},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 0},
  [239] = {.lex_state = 2},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 155},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 6},
  [244] = {.lex_state = 2},
  [245] = {.lex_state = 6},
  [246] = {.lex_state = 0},
  [247] = {.lex_state = 0},
  [248] = {.lex_state = 6},
  [249] = {.lex_state = 0},
  [250] = {.lex_state = 6},
  [251] = {.lex_state = 6},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 155},
  [254] = {.lex_state = 155},
  [255] = {.lex_state = 6},
  [256] = {.lex_state = 2},
  [257] = {.lex_state = 2},
  [258] = {.lex_state = 6},
  [259] = {.lex_state = 0},
  [260] = {.lex_state = 0},
  [261] = {.lex_state = 6},
  [262] = {.lex_state = 155},
  [263] = {.lex_state = 6},
  [264] = {.lex_state = 0},
  [265] = {.lex_state = 6},
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
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_Map] = ACTIONS(1),
    [anon_sym_Set] = ACTIONS(1),
    [anon_sym_List] = ACTIONS(1),
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
    [sym_source_file] = STATE(249),
    [sym_dmf_declaration] = STATE(236),
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
    STATE(30), 1,
      sym_comment_block,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(252), 1,
      sym_model_content,
    STATE(7), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(32), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    STATE(39), 5,
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
    STATE(30), 1,
      sym_comment_block,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(39), 5,
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
    STATE(30), 1,
      sym_comment_block,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(49), 1,
      sym__right_brace,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(39), 5,
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
    STATE(30), 1,
      sym_comment_block,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(42), 1,
      sym__right_brace,
    STATE(4), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(39), 5,
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
    STATE(97), 1,
      sym_param_definition,
    STATE(102), 1,
      aux_sym_reftype_repeat1,
    STATE(142), 1,
      aux_sym_package_string_repeat1,
    STATE(166), 1,
      sym__right_paren,
    STATE(248), 1,
      sym_package_string,
    STATE(263), 2,
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
    STATE(30), 1,
      sym_comment_block,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(39), 5,
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
    STATE(30), 1,
      sym_comment_block,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(233), 1,
      sym_model_content,
    STATE(7), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(39), 5,
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
    STATE(102), 1,
      aux_sym_reftype_repeat1,
    STATE(142), 1,
      aux_sym_package_string_repeat1,
    STATE(185), 1,
      sym_param_definition,
    STATE(248), 1,
      sym_package_string,
    STATE(263), 2,
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
  [341] = 8,
    ACTIONS(48), 1,
      sym_identifier,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(58), 1,
      sym_void,
    STATE(102), 1,
      aux_sym_reftype_repeat1,
    STATE(142), 1,
      aux_sym_package_string_repeat1,
    STATE(248), 1,
      sym_package_string,
    STATE(224), 2,
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
  [374] = 10,
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
    STATE(129), 1,
      sym_integerValue,
    STATE(136), 1,
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
  [411] = 7,
    ACTIONS(72), 1,
      sym_identifier,
    ACTIONS(74), 1,
      sym_dot,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    STATE(88), 1,
      aux_sym_reftype_repeat1,
    STATE(122), 1,
      sym_package_string,
    STATE(146), 2,
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
  [441] = 7,
    ACTIONS(72), 1,
      sym_identifier,
    ACTIONS(74), 1,
      sym_dot,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    STATE(88), 1,
      aux_sym_reftype_repeat1,
    STATE(122), 1,
      sym_package_string,
    STATE(246), 2,
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
  [471] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(82), 1,
      anon_sym_identifier,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(66), 1,
      sym_comment_block,
    STATE(183), 1,
      sym_identifier_statement,
    STATE(25), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [506] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(84), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(50), 1,
      sym__right_brace,
    STATE(66), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [541] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(86), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(45), 1,
      sym__right_brace,
    STATE(66), 1,
      sym_comment_block,
    STATE(15), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [576] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(84), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(50), 1,
      sym__right_brace,
    STATE(66), 1,
      sym_comment_block,
    STATE(22), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [611] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(82), 1,
      anon_sym_identifier,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(66), 1,
      sym_comment_block,
    STATE(205), 1,
      sym_identifier_statement,
    STATE(19), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [646] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(82), 1,
      anon_sym_identifier,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(66), 1,
      sym_comment_block,
    STATE(183), 1,
      sym_identifier_statement,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [681] = 9,
    ACTIONS(88), 1,
      anon_sym_arg,
    ACTIONS(91), 1,
      anon_sym_ref,
    ACTIONS(94), 1,
      anon_sym_func,
    ACTIONS(99), 1,
      sym_comment,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(66), 1,
      sym_comment_block,
    ACTIONS(97), 2,
      anon_sym_identifier,
      anon_sym_RBRACE,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [714] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(102), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(55), 1,
      sym__right_brace,
    STATE(66), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [749] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(104), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(57), 1,
      sym__right_brace,
    STATE(66), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [784] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(82), 1,
      anon_sym_identifier,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(66), 1,
      sym_comment_block,
    STATE(155), 1,
      sym_identifier_statement,
    STATE(24), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [819] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(82), 1,
      anon_sym_identifier,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(66), 1,
      sym_comment_block,
    STATE(162), 1,
      sym_identifier_statement,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [854] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(82), 1,
      anon_sym_identifier,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(66), 1,
      sym_comment_block,
    STATE(155), 1,
      sym_identifier_statement,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [889] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(104), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(57), 1,
      sym__right_brace,
    STATE(66), 1,
      sym_comment_block,
    STATE(21), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [924] = 9,
    ACTIONS(106), 1,
      anon_sym_arg,
    ACTIONS(108), 1,
      sym_identifier,
    ACTIONS(110), 1,
      sym_comment,
    ACTIONS(112), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      sym__right_brace,
    STATE(139), 1,
      aux_sym_comment_block_repeat1,
    STATE(265), 1,
      sym_comment_block,
    STATE(36), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(111), 2,
      sym_arg_block,
      sym_enum_constant,
  [954] = 9,
    ACTIONS(106), 1,
      anon_sym_arg,
    ACTIONS(108), 1,
      sym_identifier,
    ACTIONS(110), 1,
      sym_comment,
    ACTIONS(114), 1,
      anon_sym_RBRACE,
    STATE(46), 1,
      sym__right_brace,
    STATE(139), 1,
      aux_sym_comment_block_repeat1,
    STATE(265), 1,
      sym_comment_block,
    STATE(27), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(111), 2,
      sym_arg_block,
      sym_enum_constant,
  [984] = 3,
    ACTIONS(118), 1,
      sym_comment,
    STATE(29), 1,
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
  [1002] = 7,
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
    ACTIONS(121), 1,
      sym_expand,
    STATE(51), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [1028] = 3,
    ACTIONS(125), 1,
      sym_comment,
    STATE(29), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(123), 9,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_expand,
  [1046] = 3,
    ACTIONS(5), 1,
      anon_sym_import,
    STATE(37), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    ACTIONS(127), 7,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1063] = 6,
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
    STATE(51), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [1086] = 8,
    ACTIONS(48), 1,
      sym_identifier,
    ACTIONS(50), 1,
      sym_dot,
    STATE(102), 1,
      aux_sym_reftype_repeat1,
    STATE(142), 1,
      aux_sym_package_string_repeat1,
    STATE(219), 1,
      sym_multi_name,
    STATE(222), 1,
      sym_reftype,
    STATE(248), 1,
      sym_package_string,
    ACTIONS(129), 3,
      anon_sym_Map,
      anon_sym_Set,
      anon_sym_List,
  [1113] = 6,
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
  [1136] = 8,
    ACTIONS(131), 1,
      anon_sym_arg,
    ACTIONS(134), 1,
      sym_identifier,
    ACTIONS(137), 1,
      sym_comment,
    ACTIONS(140), 1,
      anon_sym_RBRACE,
    STATE(139), 1,
      aux_sym_comment_block_repeat1,
    STATE(265), 1,
      sym_comment_block,
    STATE(36), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(111), 2,
      sym_arg_block,
      sym_enum_constant,
  [1163] = 3,
    ACTIONS(142), 1,
      anon_sym_import,
    STATE(37), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    ACTIONS(145), 7,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1180] = 1,
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
  [1192] = 1,
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
  [1204] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(151), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(47), 1,
      sym__right_brace,
    STATE(135), 1,
      sym_func_block,
    STATE(179), 1,
      sym_comment_block,
    STATE(44), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1230] = 1,
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
  [1242] = 1,
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
  [1254] = 3,
    ACTIONS(54), 1,
      sym_date,
    STATE(255), 1,
      sym_primitive_type,
    ACTIONS(157), 7,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_string,
      sym_boolean,
  [1270] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(159), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(53), 1,
      sym__right_brace,
    STATE(135), 1,
      sym_func_block,
    STATE(179), 1,
      sym_comment_block,
    STATE(63), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1296] = 1,
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
  [1308] = 1,
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
  [1320] = 1,
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
  [1332] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(159), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(53), 1,
      sym__right_brace,
    STATE(135), 1,
      sym_func_block,
    STATE(179), 1,
      sym_comment_block,
    STATE(54), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1358] = 1,
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
  [1370] = 1,
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
  [1382] = 1,
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
  [1394] = 1,
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
  [1406] = 1,
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
  [1418] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(80), 1,
      anon_sym_func,
    ACTIONS(177), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(58), 1,
      sym__right_brace,
    STATE(135), 1,
      sym_func_block,
    STATE(179), 1,
      sym_comment_block,
    STATE(63), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1444] = 1,
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
  [1456] = 3,
    ACTIONS(54), 1,
      sym_date,
    STATE(261), 1,
      sym_primitive_type,
    ACTIONS(157), 7,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_string,
      sym_boolean,
  [1472] = 1,
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
  [1484] = 1,
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
  [1496] = 1,
    ACTIONS(185), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1508] = 1,
    ACTIONS(187), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1520] = 1,
    ACTIONS(189), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1532] = 1,
    ACTIONS(191), 8,
      anon_sym_import,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1543] = 7,
    ACTIONS(193), 1,
      anon_sym_func,
    ACTIONS(196), 1,
      sym_comment,
    ACTIONS(199), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      aux_sym_comment_block_repeat1,
    STATE(135), 1,
      sym_func_block,
    STATE(179), 1,
      sym_comment_block,
    STATE(63), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1566] = 1,
    ACTIONS(201), 8,
      anon_sym_import,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1577] = 3,
    ACTIONS(205), 1,
      sym_dot,
    STATE(68), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(203), 5,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1591] = 4,
    ACTIONS(76), 1,
      anon_sym_arg,
    ACTIONS(78), 1,
      anon_sym_ref,
    ACTIONS(80), 1,
      anon_sym_func,
    STATE(71), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [1607] = 3,
    ACTIONS(205), 1,
      sym_dot,
    STATE(69), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(203), 5,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1621] = 3,
    ACTIONS(205), 1,
      sym_dot,
    STATE(69), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(207), 5,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1635] = 3,
    ACTIONS(211), 1,
      sym_dot,
    STATE(69), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(209), 5,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1649] = 1,
    ACTIONS(214), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1658] = 1,
    ACTIONS(216), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1667] = 6,
    ACTIONS(218), 1,
      anon_sym_extends,
    ACTIONS(220), 1,
      anon_sym_implements,
    ACTIONS(222), 1,
      anon_sym_LBRACE,
    STATE(18), 1,
      sym__left_brace,
    STATE(117), 1,
      sym_extends_block,
    STATE(156), 1,
      sym_implements_block,
  [1686] = 1,
    ACTIONS(224), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1695] = 6,
    ACTIONS(74), 1,
      sym_dot,
    ACTIONS(226), 1,
      sym_identifier,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    STATE(88), 1,
      aux_sym_reftype_repeat1,
    STATE(122), 1,
      sym_package_string,
    STATE(196), 1,
      sym_reftype,
  [1714] = 1,
    ACTIONS(228), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1723] = 6,
    ACTIONS(218), 1,
      anon_sym_extends,
    ACTIONS(220), 1,
      anon_sym_implements,
    ACTIONS(230), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym__left_brace,
    STATE(128), 1,
      sym_extends_block,
    STATE(206), 1,
      sym_implements_block,
  [1742] = 6,
    ACTIONS(74), 1,
      sym_dot,
    ACTIONS(226), 1,
      sym_identifier,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    STATE(88), 1,
      aux_sym_reftype_repeat1,
    STATE(122), 1,
      sym_package_string,
    STATE(123), 1,
      sym_reftype,
  [1761] = 1,
    ACTIONS(209), 6,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_GT,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1770] = 6,
    ACTIONS(74), 1,
      sym_dot,
    ACTIONS(226), 1,
      sym_identifier,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    STATE(88), 1,
      aux_sym_reftype_repeat1,
    STATE(122), 1,
      sym_package_string,
    STATE(164), 1,
      sym_reftype,
  [1789] = 1,
    ACTIONS(232), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1798] = 1,
    ACTIONS(234), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1807] = 1,
    ACTIONS(236), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1816] = 1,
    ACTIONS(238), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1825] = 1,
    ACTIONS(240), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1834] = 5,
    ACTIONS(242), 1,
      anon_sym_COMMA,
    ACTIONS(244), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(92), 1,
      aux_sym_enum_constant_repeat1,
    STATE(159), 1,
      sym__right_paren,
  [1850] = 5,
    ACTIONS(246), 1,
      anon_sym_SQUOTE,
    ACTIONS(248), 1,
      sym_string_content_single_quote,
    ACTIONS(250), 1,
      anon_sym_BSLASH,
    STATE(91), 1,
      aux_sym_stringValue_repeat2,
    STATE(133), 1,
      sym_escape_sequence,
  [1866] = 2,
    ACTIONS(252), 1,
      anon_sym__,
    ACTIONS(254), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [1876] = 5,
    ACTIONS(74), 1,
      sym_dot,
    ACTIONS(226), 1,
      sym_identifier,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    STATE(118), 1,
      sym_package_string,
    STATE(147), 1,
      aux_sym_reftype_repeat1,
  [1892] = 5,
    ACTIONS(256), 1,
      anon_sym_DQUOTE,
    ACTIONS(258), 1,
      sym_string_content_double_quote,
    ACTIONS(261), 1,
      anon_sym_BSLASH,
    STATE(89), 1,
      aux_sym_stringValue_repeat1,
    STATE(132), 1,
      sym_escape_sequence,
  [1908] = 5,
    ACTIONS(264), 1,
      anon_sym_COMMA,
    ACTIONS(266), 1,
      anon_sym_RPAREN,
    STATE(95), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(163), 1,
      sym__right_paren,
    STATE(235), 1,
      sym__comma,
  [1924] = 5,
    ACTIONS(268), 1,
      anon_sym_SQUOTE,
    ACTIONS(270), 1,
      sym_string_content_single_quote,
    ACTIONS(273), 1,
      anon_sym_BSLASH,
    STATE(91), 1,
      aux_sym_stringValue_repeat2,
    STATE(133), 1,
      sym_escape_sequence,
  [1940] = 5,
    ACTIONS(242), 1,
      anon_sym_COMMA,
    ACTIONS(276), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(109), 1,
      aux_sym_enum_constant_repeat1,
    STATE(170), 1,
      sym__right_paren,
  [1956] = 5,
    ACTIONS(242), 1,
      anon_sym_COMMA,
    ACTIONS(276), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(98), 1,
      aux_sym_enum_constant_repeat1,
    STATE(170), 1,
      sym__right_paren,
  [1972] = 5,
    ACTIONS(248), 1,
      sym_string_content_single_quote,
    ACTIONS(250), 1,
      anon_sym_BSLASH,
    ACTIONS(278), 1,
      anon_sym_SQUOTE,
    STATE(91), 1,
      aux_sym_stringValue_repeat2,
    STATE(133), 1,
      sym_escape_sequence,
  [1988] = 5,
    ACTIONS(264), 1,
      anon_sym_COMMA,
    ACTIONS(280), 1,
      anon_sym_RPAREN,
    STATE(112), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(173), 1,
      sym__right_paren,
    STATE(235), 1,
      sym__comma,
  [2004] = 5,
    ACTIONS(248), 1,
      sym_string_content_single_quote,
    ACTIONS(250), 1,
      anon_sym_BSLASH,
    ACTIONS(282), 1,
      anon_sym_SQUOTE,
    STATE(94), 1,
      aux_sym_stringValue_repeat2,
    STATE(133), 1,
      sym_escape_sequence,
  [2020] = 5,
    ACTIONS(284), 1,
      anon_sym_COMMA,
    ACTIONS(286), 1,
      anon_sym_RPAREN,
    STATE(9), 1,
      sym__comma,
    STATE(101), 1,
      aux_sym_func_block_repeat1,
    STATE(177), 1,
      sym__right_paren,
  [2036] = 5,
    ACTIONS(242), 1,
      anon_sym_COMMA,
    ACTIONS(288), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(109), 1,
      aux_sym_enum_constant_repeat1,
    STATE(184), 1,
      sym__right_paren,
  [2052] = 5,
    ACTIONS(282), 1,
      anon_sym_DQUOTE,
    ACTIONS(290), 1,
      sym_string_content_double_quote,
    ACTIONS(292), 1,
      anon_sym_BSLASH,
    STATE(100), 1,
      aux_sym_stringValue_repeat1,
    STATE(132), 1,
      sym_escape_sequence,
  [2068] = 5,
    ACTIONS(278), 1,
      anon_sym_DQUOTE,
    ACTIONS(290), 1,
      sym_string_content_double_quote,
    ACTIONS(292), 1,
      anon_sym_BSLASH,
    STATE(89), 1,
      aux_sym_stringValue_repeat1,
    STATE(132), 1,
      sym_escape_sequence,
  [2084] = 5,
    ACTIONS(284), 1,
      anon_sym_COMMA,
    ACTIONS(294), 1,
      anon_sym_RPAREN,
    STATE(9), 1,
      sym__comma,
    STATE(119), 1,
      aux_sym_func_block_repeat1,
    STATE(186), 1,
      sym__right_paren,
  [2100] = 5,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(296), 1,
      sym_identifier,
    STATE(142), 1,
      aux_sym_package_string_repeat1,
    STATE(147), 1,
      aux_sym_reftype_repeat1,
    STATE(250), 1,
      sym_package_string,
  [2116] = 5,
    ACTIONS(290), 1,
      sym_string_content_double_quote,
    ACTIONS(292), 1,
      anon_sym_BSLASH,
    ACTIONS(298), 1,
      anon_sym_DQUOTE,
    STATE(105), 1,
      aux_sym_stringValue_repeat1,
    STATE(132), 1,
      sym_escape_sequence,
  [2132] = 5,
    ACTIONS(248), 1,
      sym_string_content_single_quote,
    ACTIONS(250), 1,
      anon_sym_BSLASH,
    ACTIONS(298), 1,
      anon_sym_SQUOTE,
    STATE(86), 1,
      aux_sym_stringValue_repeat2,
    STATE(133), 1,
      sym_escape_sequence,
  [2148] = 5,
    ACTIONS(246), 1,
      anon_sym_DQUOTE,
    ACTIONS(290), 1,
      sym_string_content_double_quote,
    ACTIONS(292), 1,
      anon_sym_BSLASH,
    STATE(89), 1,
      aux_sym_stringValue_repeat1,
    STATE(132), 1,
      sym_escape_sequence,
  [2164] = 1,
    ACTIONS(300), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [2171] = 4,
    ACTIONS(205), 1,
      sym_dot,
    ACTIONS(226), 1,
      sym_identifier,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    STATE(158), 1,
      sym_package_string,
  [2184] = 2,
    ACTIONS(302), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(304), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2193] = 4,
    ACTIONS(306), 1,
      anon_sym_COMMA,
    ACTIONS(309), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__comma,
    STATE(109), 1,
      aux_sym_enum_constant_repeat1,
  [2206] = 1,
    ACTIONS(311), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2213] = 2,
    ACTIONS(313), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(315), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2222] = 4,
    ACTIONS(317), 1,
      anon_sym_COMMA,
    ACTIONS(320), 1,
      anon_sym_RPAREN,
    STATE(112), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(235), 1,
      sym__comma,
  [2235] = 4,
    ACTIONS(322), 1,
      anon_sym__,
    ACTIONS(324), 1,
      sym_number,
    STATE(93), 1,
      sym_enum_index,
    STATE(204), 1,
      sym_integerValue,
  [2248] = 4,
    ACTIONS(326), 1,
      anon_sym_COMMA,
    ACTIONS(328), 1,
      anon_sym_LBRACE,
    STATE(74), 1,
      sym__comma,
    STATE(121), 1,
      aux_sym_implements_block_repeat1,
  [2261] = 4,
    ACTIONS(330), 1,
      anon_sym_LPAREN,
    ACTIONS(332), 1,
      sym__new_line,
    STATE(210), 1,
      sym__left_paren,
    STATE(256), 1,
      sym_model_identifier,
  [2274] = 2,
    ACTIONS(334), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(336), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2283] = 4,
    ACTIONS(220), 1,
      anon_sym_implements,
    ACTIONS(338), 1,
      anon_sym_LBRACE,
    STATE(14), 1,
      sym__left_brace,
    STATE(198), 1,
      sym_implements_block,
  [2296] = 1,
    ACTIONS(340), 4,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2303] = 4,
    ACTIONS(342), 1,
      anon_sym_COMMA,
    ACTIONS(345), 1,
      anon_sym_RPAREN,
    STATE(9), 1,
      sym__comma,
    STATE(119), 1,
      aux_sym_func_block_repeat1,
  [2316] = 2,
    ACTIONS(347), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(349), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2325] = 4,
    ACTIONS(351), 1,
      anon_sym_COMMA,
    ACTIONS(354), 1,
      anon_sym_LBRACE,
    STATE(74), 1,
      sym__comma,
    STATE(121), 1,
      aux_sym_implements_block_repeat1,
  [2338] = 1,
    ACTIONS(356), 4,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2345] = 4,
    ACTIONS(326), 1,
      anon_sym_COMMA,
    ACTIONS(358), 1,
      anon_sym_LBRACE,
    STATE(74), 1,
      sym__comma,
    STATE(114), 1,
      aux_sym_implements_block_repeat1,
  [2358] = 2,
    ACTIONS(214), 2,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(360), 2,
      anon_sym_arg,
      sym_identifier,
  [2367] = 4,
    ACTIONS(322), 1,
      anon_sym__,
    ACTIONS(324), 1,
      sym_number,
    STATE(85), 1,
      sym_enum_index,
    STATE(204), 1,
      sym_integerValue,
  [2380] = 4,
    ACTIONS(220), 1,
      anon_sym_implements,
    ACTIONS(362), 1,
      anon_sym_LBRACE,
    STATE(40), 1,
      sym__left_brace,
    STATE(157), 1,
      sym_implements_block,
  [2393] = 1,
    ACTIONS(364), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2400] = 4,
    ACTIONS(220), 1,
      anon_sym_implements,
    ACTIONS(366), 1,
      anon_sym_LBRACE,
    STATE(17), 1,
      sym__left_brace,
    STATE(171), 1,
      sym_implements_block,
  [2413] = 3,
    ACTIONS(368), 1,
      sym_dot,
    ACTIONS(372), 1,
      anon_sym_L,
    ACTIONS(370), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2424] = 4,
    ACTIONS(205), 1,
      sym_dot,
    ACTIONS(226), 1,
      sym_identifier,
    STATE(67), 1,
      aux_sym_package_string_repeat1,
    STATE(209), 1,
      sym_package_string,
  [2437] = 3,
    ACTIONS(207), 1,
      sym_identifier,
    ACTIONS(374), 1,
      sym_dot,
    STATE(145), 1,
      aux_sym_package_string_repeat1,
  [2447] = 2,
    ACTIONS(378), 1,
      sym_string_content_double_quote,
    ACTIONS(376), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2455] = 2,
    ACTIONS(382), 1,
      sym_string_content_single_quote,
    ACTIONS(380), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2463] = 3,
    ACTIONS(384), 1,
      anon_sym_version,
    ACTIONS(386), 1,
      anon_sym_RPAREN,
    STATE(244), 1,
      sym__right_paren,
  [2473] = 1,
    ACTIONS(388), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2479] = 2,
    ACTIONS(390), 1,
      anon_sym_T,
    ACTIONS(370), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2487] = 1,
    ACTIONS(392), 3,
      anon_sym_GT,
      sym_identifier,
      anon_sym_COMMA,
  [2493] = 1,
    ACTIONS(394), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_T,
  [2499] = 3,
    ACTIONS(123), 1,
      sym_identifier,
    ACTIONS(396), 1,
      sym_comment,
    STATE(143), 1,
      aux_sym_comment_block_repeat1,
  [2509] = 2,
    ACTIONS(400), 1,
      sym_string_content_single_quote,
    ACTIONS(398), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2517] = 3,
    ACTIONS(203), 1,
      sym_identifier,
    ACTIONS(374), 1,
      sym_dot,
    STATE(131), 1,
      aux_sym_package_string_repeat1,
  [2527] = 3,
    ACTIONS(203), 1,
      sym_identifier,
    ACTIONS(374), 1,
      sym_dot,
    STATE(145), 1,
      aux_sym_package_string_repeat1,
  [2537] = 3,
    ACTIONS(116), 1,
      sym_identifier,
    ACTIONS(402), 1,
      sym_comment,
    STATE(143), 1,
      aux_sym_comment_block_repeat1,
  [2547] = 3,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    STATE(227), 1,
      sym_stringValue,
  [2557] = 3,
    ACTIONS(209), 1,
      sym_identifier,
    ACTIONS(405), 1,
      sym_dot,
    STATE(145), 1,
      aux_sym_package_string_repeat1,
  [2567] = 3,
    ACTIONS(408), 1,
      anon_sym_GT,
    ACTIONS(410), 1,
      anon_sym_COMMA,
    STATE(13), 1,
      sym__comma,
  [2577] = 3,
    ACTIONS(412), 1,
      sym_identifier,
    ACTIONS(414), 1,
      sym_dot,
    STATE(147), 1,
      aux_sym_reftype_repeat1,
  [2587] = 3,
    ACTIONS(417), 1,
      anon_sym_DQUOTE,
    ACTIONS(419), 1,
      anon_sym_SQUOTE,
    STATE(115), 1,
      sym_stringValue,
  [2597] = 2,
    ACTIONS(400), 1,
      sym_string_content_double_quote,
    ACTIONS(398), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2605] = 1,
    ACTIONS(421), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2611] = 1,
    ACTIONS(423), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2617] = 1,
    ACTIONS(425), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2623] = 3,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    STATE(134), 1,
      sym_stringValue,
  [2633] = 2,
    ACTIONS(427), 1,
      anon_sym_SEMI,
    STATE(75), 1,
      sym__semicolon,
  [2640] = 2,
    ACTIONS(429), 1,
      anon_sym_RBRACE,
    STATE(60), 1,
      sym__right_brace,
  [2647] = 2,
    ACTIONS(338), 1,
      anon_sym_LBRACE,
    STATE(14), 1,
      sym__left_brace,
  [2654] = 2,
    ACTIONS(431), 1,
      anon_sym_LBRACE,
    STATE(48), 1,
      sym__left_brace,
  [2661] = 2,
    ACTIONS(433), 1,
      anon_sym_LBRACE,
    STATE(5), 1,
      sym__left_brace,
  [2668] = 2,
    ACTIONS(435), 1,
      anon_sym_SEMI,
    STATE(108), 1,
      sym__semicolon,
  [2675] = 2,
    ACTIONS(437), 1,
      anon_sym_LBRACE,
    STATE(28), 1,
      sym__left_brace,
  [2682] = 2,
    ACTIONS(439), 1,
      sym_identifier,
    ACTIONS(442), 1,
      sym_dot,
  [2689] = 2,
    ACTIONS(444), 1,
      anon_sym_RBRACE,
    STATE(61), 1,
      sym__right_brace,
  [2696] = 2,
    ACTIONS(446), 1,
      anon_sym_SEMI,
    STATE(240), 1,
      sym__semicolon,
  [2703] = 1,
    ACTIONS(448), 2,
      anon_sym_implements,
      anon_sym_LBRACE,
  [2708] = 2,
    ACTIONS(450), 1,
      sym_number,
    STATE(175), 1,
      sym_version_number,
  [2715] = 2,
    ACTIONS(452), 1,
      anon_sym_SEMI,
    STATE(80), 1,
      sym__semicolon,
  [2722] = 1,
    ACTIONS(454), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2727] = 1,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2732] = 1,
    ACTIONS(370), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2737] = 2,
    ACTIONS(456), 1,
      anon_sym_SEMI,
    STATE(116), 1,
      sym__semicolon,
  [2744] = 2,
    ACTIONS(458), 1,
      anon_sym_LBRACE,
    STATE(26), 1,
      sym__left_brace,
  [2751] = 1,
    ACTIONS(320), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2756] = 2,
    ACTIONS(460), 1,
      anon_sym_SEMI,
    STATE(213), 1,
      sym__semicolon,
  [2763] = 2,
    ACTIONS(462), 1,
      anon_sym_LPAREN,
    STATE(113), 1,
      sym__left_paren,
  [2770] = 2,
    ACTIONS(464), 1,
      anon_sym_RPAREN,
    STATE(214), 1,
      sym__right_paren,
  [2777] = 2,
    ACTIONS(466), 1,
      anon_sym_SEMI,
    STATE(81), 1,
      sym__semicolon,
  [2784] = 2,
    ACTIONS(468), 1,
      anon_sym_SEMI,
    STATE(82), 1,
      sym__semicolon,
  [2791] = 1,
    ACTIONS(470), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2796] = 2,
    ACTIONS(80), 1,
      anon_sym_func,
    STATE(150), 1,
      sym_func_block,
  [2803] = 2,
    ACTIONS(324), 1,
      sym_number,
    STATE(188), 1,
      sym_integerValue,
  [2810] = 1,
    ACTIONS(472), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2815] = 2,
    ACTIONS(474), 1,
      aux_sym_timeValue_token1,
    STATE(189), 1,
      sym_timeValue,
  [2822] = 2,
    ACTIONS(476), 1,
      anon_sym_RBRACE,
    STATE(59), 1,
      sym__right_brace,
  [2829] = 2,
    ACTIONS(478), 1,
      anon_sym_SEMI,
    STATE(120), 1,
      sym__semicolon,
  [2836] = 1,
    ACTIONS(345), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2841] = 2,
    ACTIONS(480), 1,
      anon_sym_SEMI,
    STATE(83), 1,
      sym__semicolon,
  [2848] = 2,
    ACTIONS(482), 1,
      anon_sym_model,
    STATE(239), 1,
      sym_model_declaration,
  [2855] = 1,
    ACTIONS(484), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2860] = 1,
    ACTIONS(486), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2865] = 2,
    ACTIONS(488), 1,
      anon_sym_SEMI,
    STATE(84), 1,
      sym__semicolon,
  [2872] = 2,
    ACTIONS(490), 1,
      sym_number,
    STATE(215), 1,
      sym_version_number,
  [2879] = 2,
    ACTIONS(492), 1,
      anon_sym_LPAREN,
    STATE(125), 1,
      sym__left_paren,
  [2886] = 1,
    ACTIONS(494), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2891] = 2,
    ACTIONS(425), 1,
      sym__new_line,
    ACTIONS(496), 1,
      anon_sym_LPAREN,
  [2898] = 2,
    ACTIONS(423), 1,
      sym__new_line,
    ACTIONS(498), 1,
      anon_sym_LPAREN,
  [2905] = 1,
    ACTIONS(354), 2,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2910] = 2,
    ACTIONS(490), 1,
      sym_number,
    STATE(257), 1,
      sym_version_number,
  [2917] = 2,
    ACTIONS(500), 1,
      anon_sym_LBRACE,
    STATE(23), 1,
      sym__left_brace,
  [2924] = 1,
    ACTIONS(209), 2,
      sym_identifier,
      sym_dot,
  [2929] = 2,
    ACTIONS(502), 1,
      anon_sym_SEMI,
    STATE(70), 1,
      sym__semicolon,
  [2936] = 2,
    ACTIONS(442), 1,
      sym_dot,
    ACTIONS(504), 1,
      sym_identifier,
  [2943] = 2,
    ACTIONS(507), 1,
      anon_sym_LPAREN,
    STATE(218), 1,
      sym__left_paren,
  [2950] = 2,
    ACTIONS(509), 1,
      anon_sym_LPAREN,
    STATE(6), 1,
      sym__left_paren,
  [2957] = 1,
    ACTIONS(511), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2962] = 2,
    ACTIONS(513), 1,
      anon_sym_RBRACE,
    STATE(52), 1,
      sym__right_brace,
  [2969] = 2,
    ACTIONS(366), 1,
      anon_sym_LBRACE,
    STATE(17), 1,
      sym__left_brace,
  [2976] = 2,
    ACTIONS(515), 1,
      anon_sym_SEMI,
    STATE(124), 1,
      sym__semicolon,
  [2983] = 1,
    ACTIONS(517), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2988] = 1,
    ACTIONS(519), 1,
      anon_sym_from,
  [2992] = 1,
    ACTIONS(521), 1,
      anon_sym_model,
  [2996] = 1,
    ACTIONS(523), 1,
      sym_byte_content,
  [3000] = 1,
    ACTIONS(525), 1,
      aux_sym_dateValue_token1,
  [3004] = 1,
    ACTIONS(527), 1,
      anon_sym_RBRACE,
  [3008] = 1,
    ACTIONS(529), 1,
      sym__new_line,
  [3012] = 1,
    ACTIONS(531), 1,
      sym__new_line,
  [3016] = 1,
    ACTIONS(533), 1,
      sym_identifier,
  [3020] = 1,
    ACTIONS(535), 1,
      sym_identifier,
  [3024] = 1,
    ACTIONS(537), 1,
      sym_identifier,
  [3028] = 1,
    ACTIONS(539), 1,
      anon_sym_LT,
  [3032] = 1,
    ACTIONS(541), 1,
      sym_identifier,
  [3036] = 1,
    ACTIONS(543), 1,
      aux_sym_dateValue_token2,
  [3040] = 1,
    ACTIONS(545), 1,
      sym_identifier,
  [3044] = 1,
    ACTIONS(547), 1,
      anon_sym_COLON,
  [3048] = 1,
    ACTIONS(549), 1,
      sym_identifier,
  [3052] = 1,
    ACTIONS(551), 1,
      sym_number,
  [3056] = 1,
    ACTIONS(553), 1,
      sym_identifier,
  [3060] = 1,
    ACTIONS(555), 1,
      anon_sym_version,
  [3064] = 1,
    ACTIONS(557), 1,
      anon_sym_DASH,
  [3068] = 1,
    ACTIONS(559), 1,
      aux_sym_timeValue_token2,
  [3072] = 1,
    ACTIONS(561), 1,
      sym__new_line,
  [3076] = 1,
    ACTIONS(563), 1,
      aux_sym_dateValue_token3,
  [3080] = 1,
    ACTIONS(565), 1,
      anon_sym_COLON,
  [3084] = 1,
    ACTIONS(567), 1,
      ts_builtin_sym_end,
  [3088] = 1,
    ACTIONS(569), 1,
      aux_sym_timeValue_token2,
  [3092] = 1,
    ACTIONS(571), 1,
      sym_identifier,
  [3096] = 1,
    ACTIONS(573), 1,
      sym__new_line,
  [3100] = 1,
    ACTIONS(575), 1,
      anon_sym_LT,
  [3104] = 1,
    ACTIONS(561), 1,
      anon_sym_RPAREN,
  [3108] = 1,
    ACTIONS(577), 1,
      sym__new_line,
  [3112] = 1,
    ACTIONS(579), 1,
      anon_sym_RBRACE,
  [3116] = 1,
    ACTIONS(581), 1,
      sym_number,
  [3120] = 1,
    ACTIONS(583), 1,
      sym_dot,
  [3124] = 1,
    ACTIONS(585), 1,
      sym_identifier,
  [3128] = 1,
    ACTIONS(587), 1,
      sym__new_line,
  [3132] = 1,
    ACTIONS(589), 1,
      sym_identifier,
  [3136] = 1,
    ACTIONS(591), 1,
      anon_sym_GT,
  [3140] = 1,
    ACTIONS(593), 1,
      sym_dot,
  [3144] = 1,
    ACTIONS(356), 1,
      sym_identifier,
  [3148] = 1,
    ACTIONS(595), 1,
      ts_builtin_sym_end,
  [3152] = 1,
    ACTIONS(340), 1,
      sym_identifier,
  [3156] = 1,
    ACTIONS(597), 1,
      sym_identifier,
  [3160] = 1,
    ACTIONS(599), 1,
      ts_builtin_sym_end,
  [3164] = 1,
    ACTIONS(601), 1,
      sym_number,
  [3168] = 1,
    ACTIONS(603), 1,
      sym_number,
  [3172] = 1,
    ACTIONS(605), 1,
      sym_identifier,
  [3176] = 1,
    ACTIONS(607), 1,
      sym__new_line,
  [3180] = 1,
    ACTIONS(609), 1,
      sym__new_line,
  [3184] = 1,
    ACTIONS(611), 1,
      sym_identifier,
  [3188] = 1,
    ACTIONS(613), 1,
      anon_sym_DASH,
  [3192] = 1,
    ACTIONS(615), 1,
      sym_dot,
  [3196] = 1,
    ACTIONS(617), 1,
      sym_identifier,
  [3200] = 1,
    ACTIONS(619), 1,
      sym_number,
  [3204] = 1,
    ACTIONS(621), 1,
      sym_identifier,
  [3208] = 1,
    ACTIONS(623), 1,
      sym_dot,
  [3212] = 1,
    ACTIONS(625), 1,
      sym_identifier,
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
  [SMALL_STATE(11)] = 374,
  [SMALL_STATE(12)] = 411,
  [SMALL_STATE(13)] = 441,
  [SMALL_STATE(14)] = 471,
  [SMALL_STATE(15)] = 506,
  [SMALL_STATE(16)] = 541,
  [SMALL_STATE(17)] = 576,
  [SMALL_STATE(18)] = 611,
  [SMALL_STATE(19)] = 646,
  [SMALL_STATE(20)] = 681,
  [SMALL_STATE(21)] = 714,
  [SMALL_STATE(22)] = 749,
  [SMALL_STATE(23)] = 784,
  [SMALL_STATE(24)] = 819,
  [SMALL_STATE(25)] = 854,
  [SMALL_STATE(26)] = 889,
  [SMALL_STATE(27)] = 924,
  [SMALL_STATE(28)] = 954,
  [SMALL_STATE(29)] = 984,
  [SMALL_STATE(30)] = 1002,
  [SMALL_STATE(31)] = 1028,
  [SMALL_STATE(32)] = 1046,
  [SMALL_STATE(33)] = 1063,
  [SMALL_STATE(34)] = 1086,
  [SMALL_STATE(35)] = 1113,
  [SMALL_STATE(36)] = 1136,
  [SMALL_STATE(37)] = 1163,
  [SMALL_STATE(38)] = 1180,
  [SMALL_STATE(39)] = 1192,
  [SMALL_STATE(40)] = 1204,
  [SMALL_STATE(41)] = 1230,
  [SMALL_STATE(42)] = 1242,
  [SMALL_STATE(43)] = 1254,
  [SMALL_STATE(44)] = 1270,
  [SMALL_STATE(45)] = 1296,
  [SMALL_STATE(46)] = 1308,
  [SMALL_STATE(47)] = 1320,
  [SMALL_STATE(48)] = 1332,
  [SMALL_STATE(49)] = 1358,
  [SMALL_STATE(50)] = 1370,
  [SMALL_STATE(51)] = 1382,
  [SMALL_STATE(52)] = 1394,
  [SMALL_STATE(53)] = 1406,
  [SMALL_STATE(54)] = 1418,
  [SMALL_STATE(55)] = 1444,
  [SMALL_STATE(56)] = 1456,
  [SMALL_STATE(57)] = 1472,
  [SMALL_STATE(58)] = 1484,
  [SMALL_STATE(59)] = 1496,
  [SMALL_STATE(60)] = 1508,
  [SMALL_STATE(61)] = 1520,
  [SMALL_STATE(62)] = 1532,
  [SMALL_STATE(63)] = 1543,
  [SMALL_STATE(64)] = 1566,
  [SMALL_STATE(65)] = 1577,
  [SMALL_STATE(66)] = 1591,
  [SMALL_STATE(67)] = 1607,
  [SMALL_STATE(68)] = 1621,
  [SMALL_STATE(69)] = 1635,
  [SMALL_STATE(70)] = 1649,
  [SMALL_STATE(71)] = 1658,
  [SMALL_STATE(72)] = 1667,
  [SMALL_STATE(73)] = 1686,
  [SMALL_STATE(74)] = 1695,
  [SMALL_STATE(75)] = 1714,
  [SMALL_STATE(76)] = 1723,
  [SMALL_STATE(77)] = 1742,
  [SMALL_STATE(78)] = 1761,
  [SMALL_STATE(79)] = 1770,
  [SMALL_STATE(80)] = 1789,
  [SMALL_STATE(81)] = 1798,
  [SMALL_STATE(82)] = 1807,
  [SMALL_STATE(83)] = 1816,
  [SMALL_STATE(84)] = 1825,
  [SMALL_STATE(85)] = 1834,
  [SMALL_STATE(86)] = 1850,
  [SMALL_STATE(87)] = 1866,
  [SMALL_STATE(88)] = 1876,
  [SMALL_STATE(89)] = 1892,
  [SMALL_STATE(90)] = 1908,
  [SMALL_STATE(91)] = 1924,
  [SMALL_STATE(92)] = 1940,
  [SMALL_STATE(93)] = 1956,
  [SMALL_STATE(94)] = 1972,
  [SMALL_STATE(95)] = 1988,
  [SMALL_STATE(96)] = 2004,
  [SMALL_STATE(97)] = 2020,
  [SMALL_STATE(98)] = 2036,
  [SMALL_STATE(99)] = 2052,
  [SMALL_STATE(100)] = 2068,
  [SMALL_STATE(101)] = 2084,
  [SMALL_STATE(102)] = 2100,
  [SMALL_STATE(103)] = 2116,
  [SMALL_STATE(104)] = 2132,
  [SMALL_STATE(105)] = 2148,
  [SMALL_STATE(106)] = 2164,
  [SMALL_STATE(107)] = 2171,
  [SMALL_STATE(108)] = 2184,
  [SMALL_STATE(109)] = 2193,
  [SMALL_STATE(110)] = 2206,
  [SMALL_STATE(111)] = 2213,
  [SMALL_STATE(112)] = 2222,
  [SMALL_STATE(113)] = 2235,
  [SMALL_STATE(114)] = 2248,
  [SMALL_STATE(115)] = 2261,
  [SMALL_STATE(116)] = 2274,
  [SMALL_STATE(117)] = 2283,
  [SMALL_STATE(118)] = 2296,
  [SMALL_STATE(119)] = 2303,
  [SMALL_STATE(120)] = 2316,
  [SMALL_STATE(121)] = 2325,
  [SMALL_STATE(122)] = 2338,
  [SMALL_STATE(123)] = 2345,
  [SMALL_STATE(124)] = 2358,
  [SMALL_STATE(125)] = 2367,
  [SMALL_STATE(126)] = 2380,
  [SMALL_STATE(127)] = 2393,
  [SMALL_STATE(128)] = 2400,
  [SMALL_STATE(129)] = 2413,
  [SMALL_STATE(130)] = 2424,
  [SMALL_STATE(131)] = 2437,
  [SMALL_STATE(132)] = 2447,
  [SMALL_STATE(133)] = 2455,
  [SMALL_STATE(134)] = 2463,
  [SMALL_STATE(135)] = 2473,
  [SMALL_STATE(136)] = 2479,
  [SMALL_STATE(137)] = 2487,
  [SMALL_STATE(138)] = 2493,
  [SMALL_STATE(139)] = 2499,
  [SMALL_STATE(140)] = 2509,
  [SMALL_STATE(141)] = 2517,
  [SMALL_STATE(142)] = 2527,
  [SMALL_STATE(143)] = 2537,
  [SMALL_STATE(144)] = 2547,
  [SMALL_STATE(145)] = 2557,
  [SMALL_STATE(146)] = 2567,
  [SMALL_STATE(147)] = 2577,
  [SMALL_STATE(148)] = 2587,
  [SMALL_STATE(149)] = 2597,
  [SMALL_STATE(150)] = 2605,
  [SMALL_STATE(151)] = 2611,
  [SMALL_STATE(152)] = 2617,
  [SMALL_STATE(153)] = 2623,
  [SMALL_STATE(154)] = 2633,
  [SMALL_STATE(155)] = 2640,
  [SMALL_STATE(156)] = 2647,
  [SMALL_STATE(157)] = 2654,
  [SMALL_STATE(158)] = 2661,
  [SMALL_STATE(159)] = 2668,
  [SMALL_STATE(160)] = 2675,
  [SMALL_STATE(161)] = 2682,
  [SMALL_STATE(162)] = 2689,
  [SMALL_STATE(163)] = 2696,
  [SMALL_STATE(164)] = 2703,
  [SMALL_STATE(165)] = 2708,
  [SMALL_STATE(166)] = 2715,
  [SMALL_STATE(167)] = 2722,
  [SMALL_STATE(168)] = 2727,
  [SMALL_STATE(169)] = 2732,
  [SMALL_STATE(170)] = 2737,
  [SMALL_STATE(171)] = 2744,
  [SMALL_STATE(172)] = 2751,
  [SMALL_STATE(173)] = 2756,
  [SMALL_STATE(174)] = 2763,
  [SMALL_STATE(175)] = 2770,
  [SMALL_STATE(176)] = 2777,
  [SMALL_STATE(177)] = 2784,
  [SMALL_STATE(178)] = 2791,
  [SMALL_STATE(179)] = 2796,
  [SMALL_STATE(180)] = 2803,
  [SMALL_STATE(181)] = 2810,
  [SMALL_STATE(182)] = 2815,
  [SMALL_STATE(183)] = 2822,
  [SMALL_STATE(184)] = 2829,
  [SMALL_STATE(185)] = 2836,
  [SMALL_STATE(186)] = 2841,
  [SMALL_STATE(187)] = 2848,
  [SMALL_STATE(188)] = 2855,
  [SMALL_STATE(189)] = 2860,
  [SMALL_STATE(190)] = 2865,
  [SMALL_STATE(191)] = 2872,
  [SMALL_STATE(192)] = 2879,
  [SMALL_STATE(193)] = 2886,
  [SMALL_STATE(194)] = 2891,
  [SMALL_STATE(195)] = 2898,
  [SMALL_STATE(196)] = 2905,
  [SMALL_STATE(197)] = 2910,
  [SMALL_STATE(198)] = 2917,
  [SMALL_STATE(199)] = 2924,
  [SMALL_STATE(200)] = 2929,
  [SMALL_STATE(201)] = 2936,
  [SMALL_STATE(202)] = 2943,
  [SMALL_STATE(203)] = 2950,
  [SMALL_STATE(204)] = 2957,
  [SMALL_STATE(205)] = 2962,
  [SMALL_STATE(206)] = 2969,
  [SMALL_STATE(207)] = 2976,
  [SMALL_STATE(208)] = 2983,
  [SMALL_STATE(209)] = 2988,
  [SMALL_STATE(210)] = 2992,
  [SMALL_STATE(211)] = 2996,
  [SMALL_STATE(212)] = 3000,
  [SMALL_STATE(213)] = 3004,
  [SMALL_STATE(214)] = 3008,
  [SMALL_STATE(215)] = 3012,
  [SMALL_STATE(216)] = 3016,
  [SMALL_STATE(217)] = 3020,
  [SMALL_STATE(218)] = 3024,
  [SMALL_STATE(219)] = 3028,
  [SMALL_STATE(220)] = 3032,
  [SMALL_STATE(221)] = 3036,
  [SMALL_STATE(222)] = 3040,
  [SMALL_STATE(223)] = 3044,
  [SMALL_STATE(224)] = 3048,
  [SMALL_STATE(225)] = 3052,
  [SMALL_STATE(226)] = 3056,
  [SMALL_STATE(227)] = 3060,
  [SMALL_STATE(228)] = 3064,
  [SMALL_STATE(229)] = 3068,
  [SMALL_STATE(230)] = 3072,
  [SMALL_STATE(231)] = 3076,
  [SMALL_STATE(232)] = 3080,
  [SMALL_STATE(233)] = 3084,
  [SMALL_STATE(234)] = 3088,
  [SMALL_STATE(235)] = 3092,
  [SMALL_STATE(236)] = 3096,
  [SMALL_STATE(237)] = 3100,
  [SMALL_STATE(238)] = 3104,
  [SMALL_STATE(239)] = 3108,
  [SMALL_STATE(240)] = 3112,
  [SMALL_STATE(241)] = 3116,
  [SMALL_STATE(242)] = 3120,
  [SMALL_STATE(243)] = 3124,
  [SMALL_STATE(244)] = 3128,
  [SMALL_STATE(245)] = 3132,
  [SMALL_STATE(246)] = 3136,
  [SMALL_STATE(247)] = 3140,
  [SMALL_STATE(248)] = 3144,
  [SMALL_STATE(249)] = 3148,
  [SMALL_STATE(250)] = 3152,
  [SMALL_STATE(251)] = 3156,
  [SMALL_STATE(252)] = 3160,
  [SMALL_STATE(253)] = 3164,
  [SMALL_STATE(254)] = 3168,
  [SMALL_STATE(255)] = 3172,
  [SMALL_STATE(256)] = 3176,
  [SMALL_STATE(257)] = 3180,
  [SMALL_STATE(258)] = 3184,
  [SMALL_STATE(259)] = 3188,
  [SMALL_STATE(260)] = 3192,
  [SMALL_STATE(261)] = 3196,
  [SMALL_STATE(262)] = 3200,
  [SMALL_STATE(263)] = 3204,
  [SMALL_STATE(264)] = 3208,
  [SMALL_STATE(265)] = 3212,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(226),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(243),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(217),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(251),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(141),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_content, 1, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(224),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [108] = {.entry = {.count = 1, .reusable = false}}, SHIFT(192),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0),
  [118] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_block, 1, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_block, 1, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(237),
  [131] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [134] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(192),
  [137] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(139),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 5, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 1, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 3, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 4, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 4, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 4, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 4, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 5, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 5, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 2, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 5, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 5, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 7, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 6, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 6, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 6, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 7, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 8, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 5, 0, 0),
  [193] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [196] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 6, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 1, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 2, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0),
  [211] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(220),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_block, 4, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 2, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 1, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref_block, 4, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 6, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_block, 7, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 7, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 8, 0, 0),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_block, 9, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(195),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [250] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(241),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 1, 0, 0),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0),
  [258] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(132),
  [261] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0),
  [270] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(133),
  [273] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(127),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [278] = {.entry = {.count = 1, .reusable = false}}, SHIFT(151),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [282] = {.entry = {.count = 1, .reusable = false}}, SHIFT(152),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [292] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [298] = {.entry = {.count = 1, .reusable = false}}, SHIFT(194),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 3, 0, 0),
  [302] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 5, 0, 0),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 5, 0, 0),
  [306] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [313] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_content, 1, 0, 0),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_content, 1, 0, 0),
  [317] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(235),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 3, 0, 0),
  [330] = {.entry = {.count = 1, .reusable = false}}, SHIFT(210),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [334] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 6, 0, 0),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 6, 0, 0),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 2, 0, 0),
  [342] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [345] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0),
  [347] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 7, 0, 0),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 7, 0, 0),
  [351] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 1, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 2, 0, 0),
  [360] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_block, 4, 0, 0),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_value, 1, 0, 0),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [376] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [380] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 1, 0, 0),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 1, 0, 0),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [388] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 1, 0, 0),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateValue, 6, 0, 0),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [398] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [400] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [402] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(143),
  [405] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(258),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [412] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0),
  [414] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0), SHIFT_REPEAT(147),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 2, 0, 0),
  [423] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 3, 0, 1),
  [425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 2, 0, 0),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [439] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(78),
  [442] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_extends_block, 2, 0, 0),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [454] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_booleanValue, 1, 0, 0),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_definition, 2, 0, 0),
  [472] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_longValue, 2, 0, 0),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [484] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doubleValue, 3, 0, 0),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateTimeValue, 3, 0, 0),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [494] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeValue, 5, 0, 0),
  [496] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 2, 0, 0),
  [498] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stringValue, 3, 0, 1),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [504] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(199),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_index, 1, 0, 0),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [517] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byteValue, 2, 0, 0),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [527] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 6, 0, 0),
  [529] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_identifier, 6, 0, 0),
  [531] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dmf_declaration, 2, 0, 0),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [561] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_version_number, 5, 0, 0),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [567] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 6, 0, 0),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [575] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_name, 1, 0, 0),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 5, 0, 0),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [587] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_identifier, 4, 0, 0),
  [589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [595] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [599] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 5, 0, 0),
  [601] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [609] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_declaration, 4, 0, 0),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
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
