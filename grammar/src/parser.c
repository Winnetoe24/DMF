#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 289
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 148
#define ALIAS_COUNT 1
#define TOKEN_COUNT 75
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
  anon_sym_override = 6,
  anon_sym_java = 7,
  anon_sym_annotations = 8,
  anon_sym_javaDoc = 9,
  anon_sym_extends = 10,
  anon_sym_implements = 11,
  anon_sym_class = 12,
  anon_sym_name = 13,
  anon_sym_type = 14,
  anon_sym_package = 15,
  anon_sym_struct = 16,
  anon_sym_arg = 17,
  anon_sym_SEMI = 18,
  anon_sym_ref = 19,
  anon_sym_LT = 20,
  anon_sym_GT = 21,
  anon_sym_Map = 22,
  anon_sym_Set = 23,
  anon_sym_List = 24,
  anon_sym_func = 25,
  anon_sym_enum = 26,
  anon_sym__ = 27,
  anon_sym_entity = 28,
  anon_sym_identifier = 29,
  anon_sym_interface = 30,
  sym_number = 31,
  sym_identifier = 32,
  sym_comment = 33,
  sym_dot = 34,
  sym_byte_content = 35,
  anon_sym_SEMI2 = 36,
  anon_sym_COMMA = 37,
  anon_sym_LBRACE = 38,
  anon_sym_RBRACE = 39,
  anon_sym_LPAREN = 40,
  anon_sym_RPAREN = 41,
  sym__new_line = 42,
  sym_expand = 43,
  sym_byte = 44,
  sym_int = 45,
  sym_long = 46,
  sym_double = 47,
  sym_datetime = 48,
  sym_date = 49,
  sym_string = 50,
  sym_boolean = 51,
  sym_void = 52,
  anon_sym_L = 53,
  anon_sym_true = 54,
  anon_sym_false = 55,
  anon_sym_0x = 56,
  anon_sym_DQUOTE = 57,
  anon_sym_SQUOTE = 58,
  sym_string_content_single_quote = 59,
  sym_string_content_double_quote = 60,
  anon_sym_BSLASH = 61,
  aux_sym_escape_sequence_token1 = 62,
  aux_sym_escape_sequence_token2 = 63,
  aux_sym_escape_sequence_token3 = 64,
  aux_sym_escape_sequence_token4 = 65,
  anon_sym_T = 66,
  aux_sym_timeValue_token1 = 67,
  anon_sym_COLON = 68,
  aux_sym_timeValue_token2 = 69,
  anon_sym_D = 70,
  aux_sym_dateValue_token1 = 71,
  anon_sym_DASH = 72,
  aux_sym_dateValue_token2 = 73,
  aux_sym_dateValue_token3 = 74,
  sym_source_file = 75,
  sym_dmf_declaration = 76,
  sym_model_declaration = 77,
  sym_import_block = 78,
  sym_import_statement = 79,
  sym_model_content = 80,
  sym_package_content = 81,
  sym_comment_block = 82,
  sym_override_block = 83,
  sym_java_override = 84,
  sym_java_annotation = 85,
  sym_java_doc = 86,
  sym_java_extends = 87,
  sym_java_implements = 88,
  sym_java_class = 89,
  sym_java_name = 90,
  sym_java_type = 91,
  sym_package_block = 92,
  sym_struct_block = 93,
  sym_extends_block = 94,
  sym_implements_block = 95,
  sym_struct_content = 96,
  sym_arg_block = 97,
  sym_ref_block = 98,
  sym_multi_block = 99,
  sym_multi_name = 100,
  sym_func_block = 101,
  sym_param_definition = 102,
  sym_enum_block = 103,
  sym_enum_content = 104,
  sym_enum_constant = 105,
  sym_enum_index = 106,
  sym_entity_block = 107,
  sym_identifier_statement = 108,
  sym_interface_block = 109,
  sym_interface_content = 110,
  sym__semicolon = 111,
  sym__comma = 112,
  sym__left_brace = 113,
  sym__right_brace = 114,
  sym__left_paren = 115,
  sym__right_paren = 116,
  sym_reftype = 117,
  sym_package_string = 118,
  sym_primitive_type = 119,
  sym_primitive_value = 120,
  sym_version_number = 121,
  sym_integerValue = 122,
  sym_longValue = 123,
  sym_booleanValue = 124,
  sym_byteValue = 125,
  sym_doubleValue = 126,
  sym_stringValue = 127,
  sym_escape_sequence = 128,
  sym_dateTimeValue = 129,
  sym_timeValue = 130,
  sym_dateValue = 131,
  aux_sym_import_block_repeat1 = 132,
  aux_sym_model_content_repeat1 = 133,
  aux_sym_comment_block_repeat1 = 134,
  aux_sym_override_block_repeat1 = 135,
  aux_sym_java_override_repeat1 = 136,
  aux_sym_struct_block_repeat1 = 137,
  aux_sym_implements_block_repeat1 = 138,
  aux_sym_func_block_repeat1 = 139,
  aux_sym_enum_block_repeat1 = 140,
  aux_sym_enum_constant_repeat1 = 141,
  aux_sym_identifier_statement_repeat1 = 142,
  aux_sym_interface_block_repeat1 = 143,
  aux_sym_reftype_repeat1 = 144,
  aux_sym_package_string_repeat1 = 145,
  aux_sym_stringValue_repeat1 = 146,
  aux_sym_stringValue_repeat2 = 147,
  anon_alias_sym_content = 148,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_dmf] = "dmf",
  [anon_sym_model] = "model",
  [anon_sym_version] = "version",
  [anon_sym_import] = "import",
  [anon_sym_from] = "from",
  [anon_sym_override] = "override",
  [anon_sym_java] = "java",
  [anon_sym_annotations] = "annotations",
  [anon_sym_javaDoc] = "javaDoc",
  [anon_sym_extends] = "extends",
  [anon_sym_implements] = "implements",
  [anon_sym_class] = "class",
  [anon_sym_name] = "name",
  [anon_sym_type] = "type",
  [anon_sym_package] = "package",
  [anon_sym_struct] = "struct",
  [anon_sym_arg] = "arg",
  [anon_sym_SEMI] = ";",
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
  [anon_sym_SEMI2] = ";",
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
  [sym_model_content] = "model_content",
  [sym_package_content] = "package_content",
  [sym_comment_block] = "comment_block",
  [sym_override_block] = "override_block",
  [sym_java_override] = "java_override",
  [sym_java_annotation] = "java_annotation",
  [sym_java_doc] = "java_doc",
  [sym_java_extends] = "java_extends",
  [sym_java_implements] = "java_implements",
  [sym_java_class] = "java_class",
  [sym_java_name] = "java_name",
  [sym_java_type] = "java_type",
  [sym_package_block] = "package_block",
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
  [aux_sym_override_block_repeat1] = "override_block_repeat1",
  [aux_sym_java_override_repeat1] = "java_override_repeat1",
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
  [anon_sym_override] = anon_sym_override,
  [anon_sym_java] = anon_sym_java,
  [anon_sym_annotations] = anon_sym_annotations,
  [anon_sym_javaDoc] = anon_sym_javaDoc,
  [anon_sym_extends] = anon_sym_extends,
  [anon_sym_implements] = anon_sym_implements,
  [anon_sym_class] = anon_sym_class,
  [anon_sym_name] = anon_sym_name,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_package] = anon_sym_package,
  [anon_sym_struct] = anon_sym_struct,
  [anon_sym_arg] = anon_sym_arg,
  [anon_sym_SEMI] = anon_sym_SEMI,
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
  [anon_sym_SEMI2] = anon_sym_SEMI,
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
  [sym_model_content] = sym_model_content,
  [sym_package_content] = sym_package_content,
  [sym_comment_block] = sym_comment_block,
  [sym_override_block] = sym_override_block,
  [sym_java_override] = sym_java_override,
  [sym_java_annotation] = sym_java_annotation,
  [sym_java_doc] = sym_java_doc,
  [sym_java_extends] = sym_java_extends,
  [sym_java_implements] = sym_java_implements,
  [sym_java_class] = sym_java_class,
  [sym_java_name] = sym_java_name,
  [sym_java_type] = sym_java_type,
  [sym_package_block] = sym_package_block,
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
  [aux_sym_override_block_repeat1] = aux_sym_override_block_repeat1,
  [aux_sym_java_override_repeat1] = aux_sym_java_override_repeat1,
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
  [anon_sym_override] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_java] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_annotations] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_javaDoc] = {
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
  [anon_sym_class] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_name] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
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
  [anon_sym_arg] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
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
  [anon_sym_SEMI2] = {
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
  [sym_model_content] = {
    .visible = true,
    .named = true,
  },
  [sym_package_content] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_block] = {
    .visible = true,
    .named = true,
  },
  [sym_override_block] = {
    .visible = true,
    .named = true,
  },
  [sym_java_override] = {
    .visible = true,
    .named = true,
  },
  [sym_java_annotation] = {
    .visible = true,
    .named = true,
  },
  [sym_java_doc] = {
    .visible = true,
    .named = true,
  },
  [sym_java_extends] = {
    .visible = true,
    .named = true,
  },
  [sym_java_implements] = {
    .visible = true,
    .named = true,
  },
  [sym_java_class] = {
    .visible = true,
    .named = true,
  },
  [sym_java_name] = {
    .visible = true,
    .named = true,
  },
  [sym_java_type] = {
    .visible = true,
    .named = true,
  },
  [sym_package_block] = {
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
  [aux_sym_override_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_java_override_repeat1] = {
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
  [67] = 65,
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
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 78,
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
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 98,
  [117] = 99,
  [118] = 118,
  [119] = 107,
  [120] = 104,
  [121] = 115,
  [122] = 118,
  [123] = 103,
  [124] = 124,
  [125] = 30,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
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
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 38,
  [147] = 34,
  [148] = 31,
  [149] = 127,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 76,
  [160] = 77,
  [161] = 161,
  [162] = 85,
  [163] = 158,
  [164] = 86,
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
  [177] = 93,
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
  [223] = 221,
  [224] = 224,
  [225] = 225,
  [226] = 225,
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
  [238] = 238,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 243,
  [244] = 244,
  [245] = 245,
  [246] = 246,
  [247] = 247,
  [248] = 248,
  [249] = 249,
  [250] = 250,
  [251] = 251,
  [252] = 252,
  [253] = 253,
  [254] = 254,
  [255] = 255,
  [256] = 256,
  [257] = 257,
  [258] = 258,
  [259] = 157,
  [260] = 260,
  [261] = 261,
  [262] = 165,
  [263] = 263,
  [264] = 264,
  [265] = 265,
  [266] = 266,
  [267] = 267,
  [268] = 268,
  [269] = 269,
  [270] = 131,
  [271] = 271,
  [272] = 272,
  [273] = 273,
  [274] = 130,
  [275] = 275,
  [276] = 276,
  [277] = 277,
  [278] = 278,
  [279] = 279,
  [280] = 280,
  [281] = 281,
  [282] = 242,
  [283] = 283,
  [284] = 253,
  [285] = 285,
  [286] = 286,
  [287] = 286,
  [288] = 288,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(194);
      ADVANCE_MAP(
        '"', 317,
        '\'', 318,
        '(', 290,
        ')', 291,
        ',', 287,
        '-', 336,
        '.', 284,
        '/', 12,
        ':', 332,
        ';', 215,
        '<', 217,
        '>', 218,
        'D', 334,
        'L', 313,
        'M', 14,
        'S', 57,
        'T', 330,
        '\\', 323,
        '_', 227,
        'a', 100,
        'c', 90,
        'd', 21,
        'e', 101,
        'i', 41,
        'j', 19,
        'l', 115,
        'm', 114,
        'o', 166,
        'p', 15,
        's', 145,
        'u', 190,
        'v', 58,
        'x', 187,
        '{', 288,
        '}', 289,
        '8', 234,
        '9', 234,
        'b', 324,
        'f', 324,
        'n', 324,
        'r', 324,
        't', 324,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(191);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(233);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(283);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(292);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(317);
      if (lookahead == '\\') ADVANCE(323);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(321);
      if (lookahead != 0) ADVANCE(322);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(318);
      if (lookahead == '\\') ADVANCE(323);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(319);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        ')', 291,
        '.', 284,
        '2', 173,
        ';', 215,
        'b', 266,
        'd', 236,
        'i', 263,
        'l', 265,
        's', 274,
        '0', 176,
        '1', 176,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        ')', 291,
        '.', 284,
        '2', 173,
        'b', 266,
        'd', 236,
        'i', 263,
        'l', 265,
        's', 274,
        '0', 176,
        '1', 176,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 7:
      if (lookahead == ',') ADVANCE(287);
      if (lookahead == '.') ADVANCE(284);
      if (lookahead == '0') ADVANCE(175);
      if (lookahead == '3') ADVANCE(171);
      if (lookahead == '>') ADVANCE(218);
      if (lookahead == '1' ||
          lookahead == '2') ADVANCE(179);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        '.', 284,
        '0', 174,
        '1', 172,
        'b', 266,
        'd', 236,
        'i', 263,
        'l', 265,
        's', 274,
        'v', 267,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(284);
      if (lookahead == 'L') ADVANCE(254);
      if (lookahead == 'M') ADVANCE(235);
      if (lookahead == 'S') ADVANCE(248);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('0' <= lookahead && lookahead <= '5')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 10:
      if (lookahead == '/') ADVANCE(12);
      if (lookahead == 'a') ADVANCE(270);
      if (lookahead == 'o') ADVANCE(281);
      if (lookahead == '}') ADVANCE(289);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 11:
      if (lookahead == '/') ADVANCE(12);
      if (lookahead == 'a') ADVANCE(270);
      if (lookahead == '}') ADVANCE(289);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(181);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 12:
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 13:
      if (lookahead == 'D') ADVANCE(116);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(123);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(34);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(203);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(13);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(202);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(167);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(141);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(153);
      if (lookahead == 'm') ADVANCE(69);
      if (lookahead == 'o') ADVANCE(163);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(153);
      if (lookahead == 'o') ADVANCE(163);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(76);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(93);
      if (lookahead == 'r') ADVANCE(117);
      if (lookahead == 'u') ADVANCE(110);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(106);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(38);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(103);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(161);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(168);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(98);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(169);
      END_STATE();
    case 32:
      if (lookahead == 'b') ADVANCE(118);
      if (lookahead == 'd') ADVANCE(22);
      if (lookahead == 'i') ADVANCE(107);
      if (lookahead == 'j') ADVANCE(31);
      if (lookahead == 'l') ADVANCE(115);
      if (lookahead == 's') ADVANCE(159);
      if (lookahead == '}') ADVANCE(289);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(184);
      END_STATE();
    case 33:
      if (lookahead == 'b') ADVANCE(92);
      END_STATE();
    case 34:
      if (lookahead == 'c') ADVANCE(88);
      END_STATE();
    case 35:
      if (lookahead == 'c') ADVANCE(205);
      END_STATE();
    case 36:
      if (lookahead == 'c') ADVANCE(225);
      END_STATE();
    case 37:
      if (lookahead == 'c') ADVANCE(151);
      END_STATE();
    case 38:
      if (lookahead == 'c') ADVANCE(55);
      END_STATE();
    case 39:
      if (lookahead == 'd') ADVANCE(310);
      END_STATE();
    case 40:
      if (lookahead == 'd') ADVANCE(293);
      END_STATE();
    case 41:
      if (lookahead == 'd') ADVANCE(61);
      if (lookahead == 'm') ADVANCE(124);
      if (lookahead == 'n') ADVANCE(147);
      END_STATE();
    case 42:
      if (lookahead == 'd') ADVANCE(61);
      if (lookahead == 'm') ADVANCE(124);
      if (lookahead == 'n') ADVANCE(160);
      END_STATE();
    case 43:
      if (lookahead == 'd') ADVANCE(60);
      END_STATE();
    case 44:
      if (lookahead == 'd') ADVANCE(138);
      END_STATE();
    case 45:
      if (lookahead == 'd') ADVANCE(50);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(305);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(300);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(211);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(302);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(200);
      END_STATE();
    case 51:
      if (lookahead == 'e') ADVANCE(209);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(314);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(210);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(315);
      END_STATE();
    case 55:
      if (lookahead == 'e') ADVANCE(230);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(294);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(146);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(130);
      if (lookahead == 'o') ADVANCE(79);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(99);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(112);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(70);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(133);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(109);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(128);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(132);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(113);
      END_STATE();
    case 69:
      if (lookahead == 'f') ADVANCE(195);
      END_STATE();
    case 70:
      if (lookahead == 'f') ADVANCE(216);
      END_STATE();
    case 71:
      if (lookahead == 'f') ADVANCE(86);
      END_STATE();
    case 72:
      if (lookahead == 'f') ADVANCE(26);
      END_STATE();
    case 73:
      if (lookahead == 'g') ADVANCE(213);
      END_STATE();
    case 74:
      if (lookahead == 'g') ADVANCE(298);
      END_STATE();
    case 75:
      if (lookahead == 'g') ADVANCE(306);
      END_STATE();
    case 76:
      if (lookahead == 'g') ADVANCE(48);
      END_STATE();
    case 77:
      if (lookahead == 'i') ADVANCE(143);
      END_STATE();
    case 78:
      if (lookahead == 'i') ADVANCE(71);
      END_STATE();
    case 79:
      if (lookahead == 'i') ADVANCE(39);
      END_STATE();
    case 80:
      if (lookahead == 'i') ADVANCE(97);
      END_STATE();
    case 81:
      if (lookahead == 'i') ADVANCE(149);
      END_STATE();
    case 82:
      if (lookahead == 'i') ADVANCE(120);
      END_STATE();
    case 83:
      if (lookahead == 'i') ADVANCE(45);
      END_STATE();
    case 84:
      if (lookahead == 'i') ADVANCE(108);
      END_STATE();
    case 85:
      if (lookahead == 'i') ADVANCE(108);
      if (lookahead == 'u') ADVANCE(37);
      END_STATE();
    case 86:
      if (lookahead == 'i') ADVANCE(65);
      END_STATE();
    case 87:
      if (lookahead == 'i') ADVANCE(121);
      END_STATE();
    case 88:
      if (lookahead == 'k') ADVANCE(23);
      END_STATE();
    case 89:
      if (lookahead == 'l') ADVANCE(196);
      END_STATE();
    case 90:
      if (lookahead == 'l') ADVANCE(20);
      END_STATE();
    case 91:
      if (lookahead == 'l') ADVANCE(59);
      if (lookahead == 'o') ADVANCE(135);
      END_STATE();
    case 92:
      if (lookahead == 'l') ADVANCE(47);
      END_STATE();
    case 93:
      if (lookahead == 'l') ADVANCE(144);
      END_STATE();
    case 94:
      if (lookahead == 'l') ADVANCE(67);
      END_STATE();
    case 95:
      if (lookahead == 'm') ADVANCE(226);
      END_STATE();
    case 96:
      if (lookahead == 'm') ADVANCE(199);
      END_STATE();
    case 97:
      if (lookahead == 'm') ADVANCE(49);
      END_STATE();
    case 98:
      if (lookahead == 'm') ADVANCE(51);
      END_STATE();
    case 99:
      if (lookahead == 'm') ADVANCE(68);
      END_STATE();
    case 100:
      if (lookahead == 'n') ADVANCE(105);
      if (lookahead == 'r') ADVANCE(73);
      END_STATE();
    case 101:
      if (lookahead == 'n') ADVANCE(152);
      if (lookahead == 'x') ADVANCE(125);
      END_STATE();
    case 102:
      if (lookahead == 'n') ADVANCE(197);
      END_STATE();
    case 103:
      if (lookahead == 'n') ADVANCE(308);
      END_STATE();
    case 104:
      if (lookahead == 'n') ADVANCE(74);
      END_STATE();
    case 105:
      if (lookahead == 'n') ADVANCE(119);
      END_STATE();
    case 106:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 107:
      if (lookahead == 'n') ADVANCE(147);
      END_STATE();
    case 108:
      if (lookahead == 'n') ADVANCE(75);
      END_STATE();
    case 109:
      if (lookahead == 'n') ADVANCE(44);
      END_STATE();
    case 110:
      if (lookahead == 'n') ADVANCE(36);
      END_STATE();
    case 111:
      if (lookahead == 'n') ADVANCE(140);
      END_STATE();
    case 112:
      if (lookahead == 'n') ADVANCE(155);
      END_STATE();
    case 113:
      if (lookahead == 'n') ADVANCE(154);
      END_STATE();
    case 114:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 115:
      if (lookahead == 'o') ADVANCE(104);
      END_STATE();
    case 116:
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 117:
      if (lookahead == 'o') ADVANCE(96);
      END_STATE();
    case 118:
      if (lookahead == 'o') ADVANCE(122);
      if (lookahead == 'y') ADVANCE(158);
      END_STATE();
    case 119:
      if (lookahead == 'o') ADVANCE(157);
      END_STATE();
    case 120:
      if (lookahead == 'o') ADVANCE(102);
      END_STATE();
    case 121:
      if (lookahead == 'o') ADVANCE(111);
      END_STATE();
    case 122:
      if (lookahead == 'o') ADVANCE(94);
      END_STATE();
    case 123:
      if (lookahead == 'p') ADVANCE(219);
      END_STATE();
    case 124:
      if (lookahead == 'p') ADVANCE(91);
      END_STATE();
    case 125:
      if (lookahead == 'p') ADVANCE(25);
      if (lookahead == 't') ADVANCE(64);
      END_STATE();
    case 126:
      if (lookahead == 'p') ADVANCE(53);
      END_STATE();
    case 127:
      if (lookahead == 'r') ADVANCE(85);
      END_STATE();
    case 128:
      if (lookahead == 'r') ADVANCE(229);
      END_STATE();
    case 129:
      if (lookahead == 'r') ADVANCE(165);
      if (lookahead == 'y') ADVANCE(126);
      END_STATE();
    case 130:
      if (lookahead == 'r') ADVANCE(142);
      END_STATE();
    case 131:
      if (lookahead == 'r') ADVANCE(164);
      END_STATE();
    case 132:
      if (lookahead == 'r') ADVANCE(72);
      END_STATE();
    case 133:
      if (lookahead == 'r') ADVANCE(134);
      END_STATE();
    case 134:
      if (lookahead == 'r') ADVANCE(83);
      END_STATE();
    case 135:
      if (lookahead == 'r') ADVANCE(150);
      END_STATE();
    case 136:
      if (lookahead == 'r') ADVANCE(84);
      END_STATE();
    case 137:
      if (lookahead == 's') ADVANCE(208);
      END_STATE();
    case 138:
      if (lookahead == 's') ADVANCE(206);
      END_STATE();
    case 139:
      if (lookahead == 's') ADVANCE(207);
      END_STATE();
    case 140:
      if (lookahead == 's') ADVANCE(204);
      END_STATE();
    case 141:
      if (lookahead == 's') ADVANCE(137);
      END_STATE();
    case 142:
      if (lookahead == 's') ADVANCE(82);
      END_STATE();
    case 143:
      if (lookahead == 's') ADVANCE(148);
      END_STATE();
    case 144:
      if (lookahead == 's') ADVANCE(54);
      END_STATE();
    case 145:
      if (lookahead == 't') ADVANCE(127);
      END_STATE();
    case 146:
      if (lookahead == 't') ADVANCE(221);
      END_STATE();
    case 147:
      if (lookahead == 't') ADVANCE(296);
      END_STATE();
    case 148:
      if (lookahead == 't') ADVANCE(223);
      END_STATE();
    case 149:
      if (lookahead == 't') ADVANCE(170);
      END_STATE();
    case 150:
      if (lookahead == 't') ADVANCE(198);
      END_STATE();
    case 151:
      if (lookahead == 't') ADVANCE(212);
      END_STATE();
    case 152:
      if (lookahead == 't') ADVANCE(81);
      if (lookahead == 'u') ADVANCE(95);
      END_STATE();
    case 153:
      if (lookahead == 't') ADVANCE(46);
      END_STATE();
    case 154:
      if (lookahead == 't') ADVANCE(139);
      END_STATE();
    case 155:
      if (lookahead == 't') ADVANCE(78);
      END_STATE();
    case 156:
      if (lookahead == 't') ADVANCE(131);
      END_STATE();
    case 157:
      if (lookahead == 't') ADVANCE(28);
      END_STATE();
    case 158:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 159:
      if (lookahead == 't') ADVANCE(136);
      END_STATE();
    case 160:
      if (lookahead == 't') ADVANCE(66);
      END_STATE();
    case 161:
      if (lookahead == 't') ADVANCE(87);
      END_STATE();
    case 162:
      if (lookahead == 'u') ADVANCE(190);
      if (lookahead == 'x') ADVANCE(187);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(162);
      if (lookahead == '"' ||
          lookahead == '\'' ||
          lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'f' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(329);
      END_STATE();
    case 163:
      if (lookahead == 'u') ADVANCE(33);
      END_STATE();
    case 164:
      if (lookahead == 'u') ADVANCE(37);
      END_STATE();
    case 165:
      if (lookahead == 'u') ADVANCE(52);
      END_STATE();
    case 166:
      if (lookahead == 'v') ADVANCE(63);
      END_STATE();
    case 167:
      if (lookahead == 'v') ADVANCE(16);
      END_STATE();
    case 168:
      if (lookahead == 'v') ADVANCE(17);
      END_STATE();
    case 169:
      if (lookahead == 'v') ADVANCE(18);
      END_STATE();
    case 170:
      if (lookahead == 'y') ADVANCE(228);
      END_STATE();
    case 171:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(338);
      END_STATE();
    case 172:
      if (('0' <= lookahead && lookahead <= '2')) ADVANCE(337);
      END_STATE();
    case 173:
      if (('0' <= lookahead && lookahead <= '3')) ADVANCE(331);
      END_STATE();
    case 174:
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(337);
      END_STATE();
    case 175:
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(338);
      END_STATE();
    case 176:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(331);
      END_STATE();
    case 177:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(335);
      END_STATE();
    case 178:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(333);
      END_STATE();
    case 179:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(338);
      END_STATE();
    case 180:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(177);
      END_STATE();
    case 181:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(180);
      END_STATE();
    case 182:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(285);
      END_STATE();
    case 183:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(182);
      END_STATE();
    case 184:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(183);
      END_STATE();
    case 185:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(326);
      END_STATE();
    case 186:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(325);
      END_STATE();
    case 187:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(185);
      END_STATE();
    case 188:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(186);
      END_STATE();
    case 189:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(188);
      END_STATE();
    case 190:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(189);
      END_STATE();
    case 191:
      if (eof) ADVANCE(194);
      ADVANCE_MAP(
        '"', 317,
        '\'', 318,
        '(', 290,
        ')', 291,
        ',', 287,
        '-', 336,
        '.', 284,
        '/', 12,
        ':', 332,
        ';', 286,
        '<', 217,
        '>', 218,
        'D', 334,
        'L', 77,
        'M', 14,
        'S', 57,
        'T', 330,
        '\\', 323,
        '_', 227,
        'a', 100,
        'c', 90,
        'd', 21,
        'e', 101,
        'i', 41,
        'j', 19,
        'l', 115,
        'm', 114,
        'o', 166,
        'p', 15,
        's', 145,
        'u', 190,
        'v', 58,
        'x', 187,
        '{', 288,
        '}', 289,
        '8', 234,
        '9', 234,
        'b', 324,
        'f', 324,
        'n', 324,
        'r', 324,
        't', 324,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(191);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(233);
      END_STATE();
    case 192:
      if (eof) ADVANCE(194);
      ADVANCE_MAP(
        '"', 317,
        '\'', 318,
        ')', 291,
        ',', 287,
        '.', 284,
        '/', 12,
        '0', 231,
        ';', 286,
        '>', 218,
        'D', 334,
        'L', 312,
        '_', 227,
        'a', 100,
        'c', 90,
        'e', 101,
        'f', 24,
        'i', 42,
        'j', 29,
        'n', 30,
        'o', 166,
        'p', 15,
        'r', 62,
        's', 156,
        't', 129,
        '{', 288,
        '}', 289,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(193);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(234);
      END_STATE();
    case 193:
      if (eof) ADVANCE(194);
      ADVANCE_MAP(
        '"', 317,
        '\'', 318,
        ')', 291,
        ',', 287,
        '.', 284,
        '/', 12,
        '0', 231,
        ';', 286,
        '>', 218,
        'D', 334,
        '_', 227,
        'a', 100,
        'c', 90,
        'e', 101,
        'f', 24,
        'i', 42,
        'j', 29,
        'n', 30,
        'o', 166,
        'p', 15,
        'r', 62,
        's', 156,
        't', 129,
        '{', 288,
        '}', 289,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(193);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(234);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_dmf);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_model);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_version);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_from);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_override);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_override);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_java);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_java);
      if (lookahead == 'D') ADVANCE(116);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_annotations);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_javaDoc);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_extends);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_implements);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_class);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(anon_sym_struct);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_arg);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_arg);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_ref);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(anon_sym_Map);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_Map);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_Set);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_Set);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_List);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_List);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_identifier);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_interface);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'x') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(234);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(234);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(232);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(234);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(268);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(279);
      if (lookahead == 'o') ADVANCE(280);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(261);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(258);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(311);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(246);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(295);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(304);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(237);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(301);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(303);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(201);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(272);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(277);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(299);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(307);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(214);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(239);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(273);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(240);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(262);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(243);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(244);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(245);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(309);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(250);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(276);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(257);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(260);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(264);
      if (lookahead == 'y') ADVANCE(275);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(253);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(220);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(256);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(251);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(255);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(278);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(269);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(241);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(297);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(222);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(224);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(242);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(238);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'v') ADVANCE(247);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_byte_content);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(anon_sym_SEMI2);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym__new_line);
      if (lookahead == '\n') ADVANCE(292);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_expand);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_byte);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_byte);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_int);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_int);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_long);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_long);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_double);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_double);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_datetime);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_datetime);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == 't') ADVANCE(252);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == 't') ADVANCE(80);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_string);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_boolean);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_boolean);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_void);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_void);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(anon_sym_L);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(anon_sym_L);
      if (lookahead == 'i') ADVANCE(143);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(anon_sym_0x);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_string_content_single_quote);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(319);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(320);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_string_content_single_quote);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(320);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_string_content_double_quote);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(321);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(322);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_string_content_double_quote);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(322);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token2);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token3);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token4);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token4);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(327);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token4);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(328);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(anon_sym_T);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(aux_sym_timeValue_token1);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(aux_sym_timeValue_token2);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(anon_sym_D);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(aux_sym_dateValue_token1);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(aux_sym_dateValue_token2);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(aux_sym_dateValue_token3);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 192},
  [3] = {.lex_state = 192},
  [4] = {.lex_state = 192},
  [5] = {.lex_state = 192},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 192},
  [8] = {.lex_state = 192},
  [9] = {.lex_state = 192},
  [10] = {.lex_state = 192},
  [11] = {.lex_state = 8},
  [12] = {.lex_state = 192},
  [13] = {.lex_state = 192},
  [14] = {.lex_state = 5},
  [15] = {.lex_state = 5},
  [16] = {.lex_state = 5},
  [17] = {.lex_state = 192},
  [18] = {.lex_state = 192},
  [19] = {.lex_state = 192},
  [20] = {.lex_state = 192},
  [21] = {.lex_state = 192},
  [22] = {.lex_state = 192},
  [23] = {.lex_state = 192},
  [24] = {.lex_state = 192},
  [25] = {.lex_state = 192},
  [26] = {.lex_state = 192},
  [27] = {.lex_state = 192},
  [28] = {.lex_state = 192},
  [29] = {.lex_state = 192},
  [30] = {.lex_state = 192},
  [31] = {.lex_state = 192},
  [32] = {.lex_state = 192},
  [33] = {.lex_state = 11},
  [34] = {.lex_state = 192},
  [35] = {.lex_state = 192},
  [36] = {.lex_state = 11},
  [37] = {.lex_state = 192},
  [38] = {.lex_state = 192},
  [39] = {.lex_state = 192},
  [40] = {.lex_state = 192},
  [41] = {.lex_state = 192},
  [42] = {.lex_state = 192},
  [43] = {.lex_state = 192},
  [44] = {.lex_state = 192},
  [45] = {.lex_state = 11},
  [46] = {.lex_state = 192},
  [47] = {.lex_state = 192},
  [48] = {.lex_state = 192},
  [49] = {.lex_state = 192},
  [50] = {.lex_state = 192},
  [51] = {.lex_state = 192},
  [52] = {.lex_state = 192},
  [53] = {.lex_state = 192},
  [54] = {.lex_state = 9},
  [55] = {.lex_state = 192},
  [56] = {.lex_state = 192},
  [57] = {.lex_state = 192},
  [58] = {.lex_state = 192},
  [59] = {.lex_state = 192},
  [60] = {.lex_state = 192},
  [61] = {.lex_state = 192},
  [62] = {.lex_state = 192},
  [63] = {.lex_state = 192},
  [64] = {.lex_state = 192},
  [65] = {.lex_state = 32},
  [66] = {.lex_state = 192},
  [67] = {.lex_state = 32},
  [68] = {.lex_state = 192},
  [69] = {.lex_state = 192},
  [70] = {.lex_state = 192},
  [71] = {.lex_state = 192},
  [72] = {.lex_state = 192},
  [73] = {.lex_state = 192},
  [74] = {.lex_state = 192},
  [75] = {.lex_state = 192},
  [76] = {.lex_state = 192},
  [77] = {.lex_state = 192},
  [78] = {.lex_state = 192},
  [79] = {.lex_state = 192},
  [80] = {.lex_state = 192},
  [81] = {.lex_state = 192},
  [82] = {.lex_state = 192},
  [83] = {.lex_state = 192},
  [84] = {.lex_state = 192},
  [85] = {.lex_state = 192},
  [86] = {.lex_state = 192},
  [87] = {.lex_state = 192},
  [88] = {.lex_state = 7},
  [89] = {.lex_state = 10},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 192},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 192},
  [94] = {.lex_state = 7},
  [95] = {.lex_state = 10},
  [96] = {.lex_state = 7},
  [97] = {.lex_state = 10},
  [98] = {.lex_state = 7},
  [99] = {.lex_state = 32},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 3},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 32},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 10},
  [107] = {.lex_state = 3},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 192},
  [110] = {.lex_state = 10},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 4},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 192},
  [115] = {.lex_state = 3},
  [116] = {.lex_state = 7},
  [117] = {.lex_state = 32},
  [118] = {.lex_state = 4},
  [119] = {.lex_state = 3},
  [120] = {.lex_state = 4},
  [121] = {.lex_state = 3},
  [122] = {.lex_state = 4},
  [123] = {.lex_state = 32},
  [124] = {.lex_state = 192},
  [125] = {.lex_state = 11},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 162},
  [128] = {.lex_state = 7},
  [129] = {.lex_state = 11},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 7},
  [133] = {.lex_state = 32},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 192},
  [136] = {.lex_state = 192},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 192},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 11},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 11},
  [147] = {.lex_state = 11},
  [148] = {.lex_state = 11},
  [149] = {.lex_state = 162},
  [150] = {.lex_state = 11},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 7},
  [153] = {.lex_state = 3},
  [154] = {.lex_state = 4},
  [155] = {.lex_state = 7},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 4},
  [159] = {.lex_state = 7},
  [160] = {.lex_state = 7},
  [161] = {.lex_state = 192},
  [162] = {.lex_state = 7},
  [163] = {.lex_state = 3},
  [164] = {.lex_state = 7},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 192},
  [167] = {.lex_state = 192},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 192},
  [170] = {.lex_state = 192},
  [171] = {.lex_state = 192},
  [172] = {.lex_state = 192},
  [173] = {.lex_state = 192},
  [174] = {.lex_state = 192},
  [175] = {.lex_state = 192},
  [176] = {.lex_state = 192},
  [177] = {.lex_state = 7},
  [178] = {.lex_state = 32},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 192},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 192},
  [184] = {.lex_state = 192},
  [185] = {.lex_state = 32},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 192},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 192},
  [193] = {.lex_state = 192},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 192},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 192},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 192},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 192},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 5},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 192},
  [209] = {.lex_state = 192},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 192},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 7},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 7},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 2},
  [230] = {.lex_state = 2},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 192},
  [233] = {.lex_state = 0},
  [234] = {.lex_state = 2},
  [235] = {.lex_state = 7},
  [236] = {.lex_state = 2},
  [237] = {.lex_state = 2},
  [238] = {.lex_state = 0},
  [239] = {.lex_state = 192},
  [240] = {.lex_state = 7},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 7},
  [243] = {.lex_state = 7},
  [244] = {.lex_state = 2},
  [245] = {.lex_state = 8},
  [246] = {.lex_state = 7},
  [247] = {.lex_state = 0},
  [248] = {.lex_state = 32},
  [249] = {.lex_state = 11},
  [250] = {.lex_state = 192},
  [251] = {.lex_state = 0},
  [252] = {.lex_state = 9},
  [253] = {.lex_state = 5},
  [254] = {.lex_state = 7},
  [255] = {.lex_state = 2},
  [256] = {.lex_state = 2},
  [257] = {.lex_state = 9},
  [258] = {.lex_state = 7},
  [259] = {.lex_state = 2},
  [260] = {.lex_state = 5},
  [261] = {.lex_state = 7},
  [262] = {.lex_state = 2},
  [263] = {.lex_state = 7},
  [264] = {.lex_state = 0},
  [265] = {.lex_state = 0},
  [266] = {.lex_state = 192},
  [267] = {.lex_state = 0},
  [268] = {.lex_state = 2},
  [269] = {.lex_state = 2},
  [270] = {.lex_state = 7},
  [271] = {.lex_state = 7},
  [272] = {.lex_state = 0},
  [273] = {.lex_state = 7},
  [274] = {.lex_state = 7},
  [275] = {.lex_state = 2},
  [276] = {.lex_state = 7},
  [277] = {.lex_state = 0},
  [278] = {.lex_state = 2},
  [279] = {.lex_state = 2},
  [280] = {.lex_state = 0},
  [281] = {.lex_state = 0},
  [282] = {.lex_state = 7},
  [283] = {.lex_state = 2},
  [284] = {.lex_state = 5},
  [285] = {.lex_state = 0},
  [286] = {.lex_state = 7},
  [287] = {.lex_state = 7},
  [288] = {.lex_state = 7},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_dmf] = ACTIONS(1),
    [anon_sym_model] = ACTIONS(1),
    [anon_sym_version] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_override] = ACTIONS(1),
    [anon_sym_java] = ACTIONS(1),
    [anon_sym_annotations] = ACTIONS(1),
    [anon_sym_javaDoc] = ACTIONS(1),
    [anon_sym_extends] = ACTIONS(1),
    [anon_sym_implements] = ACTIONS(1),
    [anon_sym_class] = ACTIONS(1),
    [anon_sym_package] = ACTIONS(1),
    [anon_sym_struct] = ACTIONS(1),
    [anon_sym_arg] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
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
    [anon_sym_SEMI2] = ACTIONS(1),
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
    [sym_source_file] = STATE(267),
    [sym_dmf_declaration] = STATE(237),
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
    STATE(32), 1,
      sym_comment_block,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(231), 1,
      sym_model_content,
    STATE(7), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(42), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    STATE(35), 5,
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
    STATE(32), 1,
      sym_comment_block,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(35), 5,
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
    STATE(32), 1,
      sym_comment_block,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(41), 1,
      sym__right_brace,
    STATE(5), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(35), 5,
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
    STATE(32), 1,
      sym_comment_block,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(49), 1,
      sym__right_brace,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(35), 5,
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
    STATE(105), 1,
      sym_param_definition,
    STATE(116), 1,
      aux_sym_reftype_repeat1,
    STATE(160), 1,
      aux_sym_package_string_repeat1,
    STATE(187), 1,
      sym__right_paren,
    STATE(270), 1,
      sym_package_string,
    STATE(243), 2,
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
    STATE(32), 1,
      sym_comment_block,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(3), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(35), 5,
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
    STATE(32), 1,
      sym_comment_block,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(280), 1,
      sym_model_content,
    STATE(7), 2,
      sym_package_content,
      aux_sym_model_content_repeat1,
    STATE(35), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [308] = 11,
    ACTIONS(58), 1,
      anon_sym_annotations,
    ACTIONS(60), 1,
      anon_sym_javaDoc,
    ACTIONS(62), 1,
      anon_sym_extends,
    ACTIONS(64), 1,
      anon_sym_implements,
    ACTIONS(66), 1,
      anon_sym_class,
    ACTIONS(68), 1,
      anon_sym_name,
    ACTIONS(70), 1,
      anon_sym_type,
    ACTIONS(72), 1,
      anon_sym_RBRACE,
    STATE(10), 1,
      aux_sym_java_override_repeat1,
    STATE(178), 1,
      sym__right_brace,
    STATE(229), 7,
      sym_java_annotation,
      sym_java_doc,
      sym_java_extends,
      sym_java_implements,
      sym_java_class,
      sym_java_name,
      sym_java_type,
  [348] = 11,
    ACTIONS(58), 1,
      anon_sym_annotations,
    ACTIONS(60), 1,
      anon_sym_javaDoc,
    ACTIONS(62), 1,
      anon_sym_extends,
    ACTIONS(64), 1,
      anon_sym_implements,
    ACTIONS(66), 1,
      anon_sym_class,
    ACTIONS(68), 1,
      anon_sym_name,
    ACTIONS(70), 1,
      anon_sym_type,
    ACTIONS(74), 1,
      anon_sym_RBRACE,
    STATE(12), 1,
      aux_sym_java_override_repeat1,
    STATE(185), 1,
      sym__right_brace,
    STATE(229), 7,
      sym_java_annotation,
      sym_java_doc,
      sym_java_extends,
      sym_java_implements,
      sym_java_class,
      sym_java_name,
      sym_java_type,
  [388] = 8,
    ACTIONS(48), 1,
      sym_identifier,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(76), 1,
      sym_void,
    STATE(116), 1,
      aux_sym_reftype_repeat1,
    STATE(160), 1,
      aux_sym_package_string_repeat1,
    STATE(270), 1,
      sym_package_string,
    STATE(288), 2,
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
  [421] = 10,
    ACTIONS(78), 1,
      anon_sym_annotations,
    ACTIONS(81), 1,
      anon_sym_javaDoc,
    ACTIONS(84), 1,
      anon_sym_extends,
    ACTIONS(87), 1,
      anon_sym_implements,
    ACTIONS(90), 1,
      anon_sym_class,
    ACTIONS(93), 1,
      anon_sym_name,
    ACTIONS(96), 1,
      anon_sym_type,
    ACTIONS(99), 1,
      anon_sym_RBRACE,
    STATE(12), 1,
      aux_sym_java_override_repeat1,
    STATE(229), 7,
      sym_java_annotation,
      sym_java_doc,
      sym_java_extends,
      sym_java_implements,
      sym_java_class,
      sym_java_name,
      sym_java_type,
  [458] = 10,
    ACTIONS(101), 1,
      sym_number,
    ACTIONS(105), 1,
      anon_sym_0x,
    ACTIONS(107), 1,
      anon_sym_DQUOTE,
    ACTIONS(109), 1,
      anon_sym_SQUOTE,
    ACTIONS(111), 1,
      anon_sym_D,
    STATE(136), 1,
      sym_integerValue,
    STATE(168), 1,
      sym_dateValue,
    STATE(190), 1,
      sym_primitive_value,
    ACTIONS(103), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(191), 6,
      sym_longValue,
      sym_booleanValue,
      sym_byteValue,
      sym_doubleValue,
      sym_stringValue,
      sym_dateTimeValue,
  [495] = 8,
    ACTIONS(48), 1,
      sym_identifier,
    ACTIONS(50), 1,
      sym_dot,
    STATE(116), 1,
      aux_sym_reftype_repeat1,
    STATE(160), 1,
      aux_sym_package_string_repeat1,
    STATE(207), 1,
      sym_param_definition,
    STATE(270), 1,
      sym_package_string,
    STATE(243), 2,
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
  [528] = 7,
    ACTIONS(113), 1,
      sym_identifier,
    ACTIONS(115), 1,
      sym_dot,
    STATE(77), 1,
      aux_sym_package_string_repeat1,
    STATE(98), 1,
      aux_sym_reftype_repeat1,
    STATE(131), 1,
      sym_package_string,
    STATE(151), 2,
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
  [558] = 7,
    ACTIONS(113), 1,
      sym_identifier,
    ACTIONS(115), 1,
      sym_dot,
    STATE(77), 1,
      aux_sym_package_string_repeat1,
    STATE(98), 1,
      aux_sym_reftype_repeat1,
    STATE(131), 1,
      sym_package_string,
    STATE(285), 2,
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
  [588] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(123), 1,
      anon_sym_identifier,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    STATE(200), 1,
      sym_identifier_statement,
    STATE(22), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [623] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(125), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(59), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(24), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [658] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(127), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(57), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(20), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [693] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(125), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(59), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(29), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [728] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(123), 1,
      anon_sym_identifier,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    STATE(186), 1,
      sym_identifier_statement,
    STATE(27), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [763] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(123), 1,
      anon_sym_identifier,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    STATE(186), 1,
      sym_identifier_statement,
    STATE(29), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [798] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(129), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(48), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(25), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [833] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(129), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(48), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(29), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [868] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(131), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(50), 1,
      sym__right_brace,
    STATE(75), 1,
      sym_comment_block,
    STATE(29), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [903] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(123), 1,
      anon_sym_identifier,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    STATE(182), 1,
      sym_identifier_statement,
    STATE(29), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [938] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(123), 1,
      anon_sym_identifier,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    STATE(220), 1,
      sym_identifier_statement,
    STATE(29), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [973] = 10,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(123), 1,
      anon_sym_identifier,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    STATE(220), 1,
      sym_identifier_statement,
    STATE(26), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [1008] = 9,
    ACTIONS(133), 1,
      anon_sym_arg,
    ACTIONS(136), 1,
      anon_sym_ref,
    ACTIONS(139), 1,
      anon_sym_func,
    ACTIONS(144), 1,
      sym_comment,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(75), 1,
      sym_comment_block,
    ACTIONS(142), 2,
      anon_sym_identifier,
      anon_sym_RBRACE,
    STATE(29), 2,
      sym_struct_content,
      aux_sym_struct_block_repeat1,
    STATE(74), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [1041] = 1,
    ACTIONS(147), 13,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_identifier,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1057] = 1,
    ACTIONS(149), 13,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_identifier,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1073] = 7,
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
    ACTIONS(151), 1,
      sym_expand,
    STATE(39), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [1099] = 9,
    ACTIONS(153), 1,
      anon_sym_arg,
    ACTIONS(155), 1,
      sym_identifier,
    ACTIONS(157), 1,
      sym_comment,
    ACTIONS(159), 1,
      anon_sym_RBRACE,
    STATE(43), 1,
      sym__right_brace,
    STATE(129), 1,
      sym_comment_block,
    STATE(146), 1,
      aux_sym_comment_block_repeat1,
    STATE(45), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(95), 2,
      sym_arg_block,
      sym_enum_constant,
  [1129] = 3,
    ACTIONS(163), 1,
      sym_comment,
    STATE(34), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(161), 9,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_expand,
  [1147] = 3,
    ACTIONS(168), 1,
      anon_sym_override,
    STATE(69), 1,
      sym_override_block,
    ACTIONS(166), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1165] = 9,
    ACTIONS(153), 1,
      anon_sym_arg,
    ACTIONS(155), 1,
      sym_identifier,
    ACTIONS(157), 1,
      sym_comment,
    ACTIONS(170), 1,
      anon_sym_RBRACE,
    STATE(55), 1,
      sym__right_brace,
    STATE(129), 1,
      sym_comment_block,
    STATE(146), 1,
      aux_sym_comment_block_repeat1,
    STATE(33), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(95), 2,
      sym_arg_block,
      sym_enum_constant,
  [1195] = 3,
    ACTIONS(168), 1,
      anon_sym_override,
    STATE(62), 1,
      sym_override_block,
    ACTIONS(172), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1213] = 3,
    ACTIONS(176), 1,
      sym_comment,
    STATE(34), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(174), 9,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_expand,
  [1231] = 3,
    ACTIONS(168), 1,
      anon_sym_override,
    STATE(64), 1,
      sym_override_block,
    ACTIONS(178), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1249] = 1,
    ACTIONS(180), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1262] = 1,
    ACTIONS(182), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1275] = 3,
    ACTIONS(5), 1,
      anon_sym_import,
    STATE(60), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    ACTIONS(184), 7,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1292] = 1,
    ACTIONS(186), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1305] = 1,
    ACTIONS(188), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1318] = 8,
    ACTIONS(190), 1,
      anon_sym_arg,
    ACTIONS(193), 1,
      sym_identifier,
    ACTIONS(196), 1,
      sym_comment,
    ACTIONS(199), 1,
      anon_sym_RBRACE,
    STATE(129), 1,
      sym_comment_block,
    STATE(146), 1,
      aux_sym_comment_block_repeat1,
    STATE(45), 2,
      sym_enum_content,
      aux_sym_enum_block_repeat1,
    STATE(95), 2,
      sym_arg_block,
      sym_enum_constant,
  [1345] = 6,
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
    STATE(39), 5,
      sym_package_block,
      sym_struct_block,
      sym_enum_block,
      sym_entity_block,
      sym_interface_block,
  [1368] = 1,
    ACTIONS(201), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1381] = 1,
    ACTIONS(203), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1394] = 1,
    ACTIONS(205), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1407] = 1,
    ACTIONS(207), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1420] = 1,
    ACTIONS(209), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1433] = 1,
    ACTIONS(211), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1446] = 1,
    ACTIONS(213), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1459] = 8,
    ACTIONS(48), 1,
      sym_identifier,
    ACTIONS(50), 1,
      sym_dot,
    STATE(116), 1,
      aux_sym_reftype_repeat1,
    STATE(160), 1,
      aux_sym_package_string_repeat1,
    STATE(241), 1,
      sym_multi_name,
    STATE(246), 1,
      sym_reftype,
    STATE(270), 1,
      sym_package_string,
    ACTIONS(215), 3,
      anon_sym_Map,
      anon_sym_Set,
      anon_sym_List,
  [1486] = 1,
    ACTIONS(217), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1499] = 6,
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
  [1522] = 1,
    ACTIONS(219), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1535] = 1,
    ACTIONS(221), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1548] = 1,
    ACTIONS(223), 10,
      ts_builtin_sym_end,
      anon_sym_override,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1561] = 3,
    ACTIONS(225), 1,
      anon_sym_import,
    STATE(60), 2,
      sym_import_statement,
      aux_sym_import_block_repeat1,
    ACTIONS(228), 7,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1578] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(230), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(44), 1,
      sym__right_brace,
    STATE(124), 1,
      sym_func_block,
    STATE(209), 1,
      sym_comment_block,
    STATE(68), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1604] = 1,
    ACTIONS(232), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1616] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(234), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(53), 1,
      sym__right_brace,
    STATE(124), 1,
      sym_func_block,
    STATE(209), 1,
      sym_comment_block,
    STATE(70), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1642] = 1,
    ACTIONS(172), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1654] = 3,
    ACTIONS(54), 1,
      sym_date,
    STATE(286), 1,
      sym_primitive_type,
    ACTIONS(236), 7,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_string,
      sym_boolean,
  [1670] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(238), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(40), 1,
      sym__right_brace,
    STATE(124), 1,
      sym_func_block,
    STATE(209), 1,
      sym_comment_block,
    STATE(63), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1696] = 3,
    ACTIONS(54), 1,
      sym_date,
    STATE(287), 1,
      sym_primitive_type,
    ACTIONS(236), 7,
      sym_byte,
      sym_int,
      sym_long,
      sym_double,
      sym_datetime,
      sym_string,
      sym_boolean,
  [1712] = 8,
    ACTIONS(17), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_func,
    ACTIONS(238), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(40), 1,
      sym__right_brace,
    STATE(124), 1,
      sym_func_block,
    STATE(209), 1,
      sym_comment_block,
    STATE(70), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1738] = 1,
    ACTIONS(178), 9,
      ts_builtin_sym_end,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      anon_sym_RBRACE,
      sym_expand,
  [1750] = 7,
    ACTIONS(240), 1,
      anon_sym_func,
    ACTIONS(243), 1,
      sym_comment,
    ACTIONS(246), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      aux_sym_comment_block_repeat1,
    STATE(124), 1,
      sym_func_block,
    STATE(209), 1,
      sym_comment_block,
    STATE(70), 2,
      sym_interface_content,
      aux_sym_interface_block_repeat1,
  [1773] = 1,
    ACTIONS(99), 8,
      anon_sym_annotations,
      anon_sym_javaDoc,
      anon_sym_extends,
      anon_sym_implements,
      anon_sym_class,
      anon_sym_name,
      anon_sym_type,
      anon_sym_RBRACE,
  [1784] = 1,
    ACTIONS(248), 8,
      anon_sym_import,
      anon_sym_package,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_entity,
      anon_sym_interface,
      sym_comment,
      sym_expand,
  [1795] = 3,
    ACTIONS(168), 1,
      anon_sym_override,
    STATE(91), 1,
      sym_override_block,
    ACTIONS(250), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1810] = 3,
    ACTIONS(168), 1,
      anon_sym_override,
    STATE(87), 1,
      sym_override_block,
    ACTIONS(252), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1825] = 4,
    ACTIONS(117), 1,
      anon_sym_arg,
    ACTIONS(119), 1,
      anon_sym_ref,
    ACTIONS(121), 1,
      anon_sym_func,
    STATE(73), 4,
      sym_arg_block,
      sym_ref_block,
      sym_multi_block,
      sym_func_block,
  [1841] = 3,
    ACTIONS(256), 1,
      sym_dot,
    STATE(85), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(254), 5,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1855] = 3,
    ACTIONS(256), 1,
      sym_dot,
    STATE(86), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(254), 5,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1869] = 1,
    ACTIONS(258), 7,
      anon_sym_override,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1879] = 1,
    ACTIONS(260), 7,
      anon_sym_override,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1889] = 1,
    ACTIONS(262), 7,
      anon_sym_override,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1899] = 1,
    ACTIONS(264), 7,
      anon_sym_override,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1909] = 1,
    ACTIONS(266), 7,
      anon_sym_override,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1919] = 1,
    ACTIONS(268), 7,
      anon_sym_override,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1929] = 1,
    ACTIONS(270), 7,
      anon_sym_override,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1939] = 3,
    ACTIONS(256), 1,
      sym_dot,
    STATE(86), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(272), 5,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1953] = 3,
    ACTIONS(276), 1,
      sym_dot,
    STATE(86), 1,
      aux_sym_package_string_repeat1,
    ACTIONS(274), 5,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [1967] = 1,
    ACTIONS(250), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [1976] = 6,
    ACTIONS(115), 1,
      sym_dot,
    ACTIONS(279), 1,
      sym_identifier,
    STATE(77), 1,
      aux_sym_package_string_repeat1,
    STATE(98), 1,
      aux_sym_reftype_repeat1,
    STATE(131), 1,
      sym_package_string,
    STATE(137), 1,
      sym_reftype,
  [1995] = 4,
    ACTIONS(281), 1,
      anon_sym_override,
    STATE(143), 1,
      sym_override_block,
    ACTIONS(283), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(285), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2010] = 6,
    ACTIONS(287), 1,
      anon_sym_extends,
    ACTIONS(289), 1,
      anon_sym_implements,
    ACTIONS(291), 1,
      anon_sym_LBRACE,
    STATE(19), 1,
      sym__left_brace,
    STATE(126), 1,
      sym_extends_block,
    STATE(198), 1,
      sym_implements_block,
  [2029] = 1,
    ACTIONS(293), 6,
      anon_sym_arg,
      anon_sym_ref,
      anon_sym_func,
      anon_sym_identifier,
      sym_comment,
      anon_sym_RBRACE,
  [2038] = 6,
    ACTIONS(287), 1,
      anon_sym_extends,
    ACTIONS(289), 1,
      anon_sym_implements,
    ACTIONS(295), 1,
      anon_sym_LBRACE,
    STATE(17), 1,
      sym__left_brace,
    STATE(142), 1,
      sym_extends_block,
    STATE(213), 1,
      sym_implements_block,
  [2057] = 1,
    ACTIONS(274), 6,
      anon_sym_from,
      anon_sym_implements,
      anon_sym_GT,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2066] = 6,
    ACTIONS(115), 1,
      sym_dot,
    ACTIONS(279), 1,
      sym_identifier,
    STATE(77), 1,
      aux_sym_package_string_repeat1,
    STATE(98), 1,
      aux_sym_reftype_repeat1,
    STATE(131), 1,
      sym_package_string,
    STATE(224), 1,
      sym_reftype,
  [2085] = 4,
    ACTIONS(281), 1,
      anon_sym_override,
    STATE(150), 1,
      sym_override_block,
    ACTIONS(297), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(299), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2100] = 6,
    ACTIONS(115), 1,
      sym_dot,
    ACTIONS(279), 1,
      sym_identifier,
    STATE(77), 1,
      aux_sym_package_string_repeat1,
    STATE(98), 1,
      aux_sym_reftype_repeat1,
    STATE(131), 1,
      sym_package_string,
    STATE(206), 1,
      sym_reftype,
  [2119] = 2,
    ACTIONS(258), 2,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(301), 3,
      anon_sym_override,
      anon_sym_arg,
      sym_identifier,
  [2129] = 5,
    ACTIONS(115), 1,
      sym_dot,
    ACTIONS(279), 1,
      sym_identifier,
    STATE(77), 1,
      aux_sym_package_string_repeat1,
    STATE(130), 1,
      sym_package_string,
    STATE(155), 1,
      aux_sym_reftype_repeat1,
  [2145] = 4,
    ACTIONS(303), 1,
      anon_sym_java,
    ACTIONS(305), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      sym__right_brace,
    STATE(133), 2,
      sym_java_override,
      aux_sym_override_block_repeat1,
  [2159] = 5,
    ACTIONS(307), 1,
      anon_sym_COMMA,
    ACTIONS(309), 1,
      anon_sym_RPAREN,
    STATE(13), 1,
      sym__comma,
    STATE(138), 1,
      aux_sym_enum_constant_repeat1,
    STATE(193), 1,
      sym__right_paren,
  [2175] = 5,
    ACTIONS(311), 1,
      anon_sym_DQUOTE,
    ACTIONS(313), 1,
      sym_string_content_double_quote,
    ACTIONS(316), 1,
      anon_sym_BSLASH,
    STATE(101), 1,
      aux_sym_stringValue_repeat1,
    STATE(153), 1,
      sym_escape_sequence,
  [2191] = 5,
    ACTIONS(319), 1,
      anon_sym_COMMA,
    ACTIONS(321), 1,
      anon_sym_RPAREN,
    STATE(139), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(195), 1,
      sym__right_paren,
    STATE(261), 1,
      sym__comma,
  [2207] = 4,
    ACTIONS(303), 1,
      anon_sym_java,
    ACTIONS(323), 1,
      anon_sym_RBRACE,
    STATE(30), 1,
      sym__right_brace,
    STATE(99), 2,
      sym_java_override,
      aux_sym_override_block_repeat1,
  [2221] = 5,
    ACTIONS(325), 1,
      anon_sym_SQUOTE,
    ACTIONS(327), 1,
      sym_string_content_single_quote,
    ACTIONS(329), 1,
      anon_sym_BSLASH,
    STATE(118), 1,
      aux_sym_stringValue_repeat2,
    STATE(154), 1,
      sym_escape_sequence,
  [2237] = 5,
    ACTIONS(331), 1,
      anon_sym_COMMA,
    ACTIONS(333), 1,
      anon_sym_RPAREN,
    STATE(14), 1,
      sym__comma,
    STATE(108), 1,
      aux_sym_func_block_repeat1,
    STATE(199), 1,
      sym__right_paren,
  [2253] = 2,
    ACTIONS(337), 2,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(335), 3,
      anon_sym_override,
      anon_sym_arg,
      sym_identifier,
  [2263] = 5,
    ACTIONS(325), 1,
      anon_sym_DQUOTE,
    ACTIONS(339), 1,
      sym_string_content_double_quote,
    ACTIONS(341), 1,
      anon_sym_BSLASH,
    STATE(115), 1,
      aux_sym_stringValue_repeat1,
    STATE(153), 1,
      sym_escape_sequence,
  [2279] = 5,
    ACTIONS(331), 1,
      anon_sym_COMMA,
    ACTIONS(343), 1,
      anon_sym_RPAREN,
    STATE(14), 1,
      sym__comma,
    STATE(144), 1,
      aux_sym_func_block_repeat1,
    STATE(208), 1,
      sym__right_paren,
  [2295] = 2,
    ACTIONS(345), 1,
      anon_sym__,
    ACTIONS(347), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [2305] = 2,
    ACTIONS(351), 2,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(349), 3,
      anon_sym_override,
      anon_sym_arg,
      sym_identifier,
  [2315] = 5,
    ACTIONS(307), 1,
      anon_sym_COMMA,
    ACTIONS(353), 1,
      anon_sym_RPAREN,
    STATE(13), 1,
      sym__comma,
    STATE(100), 1,
      aux_sym_enum_constant_repeat1,
    STATE(180), 1,
      sym__right_paren,
  [2331] = 5,
    ACTIONS(355), 1,
      anon_sym_SQUOTE,
    ACTIONS(357), 1,
      sym_string_content_single_quote,
    ACTIONS(360), 1,
      anon_sym_BSLASH,
    STATE(112), 1,
      aux_sym_stringValue_repeat2,
    STATE(154), 1,
      sym_escape_sequence,
  [2347] = 5,
    ACTIONS(319), 1,
      anon_sym_COMMA,
    ACTIONS(363), 1,
      anon_sym_RPAREN,
    STATE(102), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(183), 1,
      sym__right_paren,
    STATE(261), 1,
      sym__comma,
  [2363] = 3,
    ACTIONS(168), 1,
      anon_sym_override,
    STATE(167), 1,
      sym_override_block,
    ACTIONS(365), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2375] = 5,
    ACTIONS(339), 1,
      sym_string_content_double_quote,
    ACTIONS(341), 1,
      anon_sym_BSLASH,
    ACTIONS(367), 1,
      anon_sym_DQUOTE,
    STATE(101), 1,
      aux_sym_stringValue_repeat1,
    STATE(153), 1,
      sym_escape_sequence,
  [2391] = 5,
    ACTIONS(50), 1,
      sym_dot,
    ACTIONS(369), 1,
      sym_identifier,
    STATE(155), 1,
      aux_sym_reftype_repeat1,
    STATE(160), 1,
      aux_sym_package_string_repeat1,
    STATE(274), 1,
      sym_package_string,
  [2407] = 4,
    ACTIONS(303), 1,
      anon_sym_java,
    ACTIONS(371), 1,
      anon_sym_RBRACE,
    STATE(148), 1,
      sym__right_brace,
    STATE(133), 2,
      sym_java_override,
      aux_sym_override_block_repeat1,
  [2421] = 5,
    ACTIONS(327), 1,
      sym_string_content_single_quote,
    ACTIONS(329), 1,
      anon_sym_BSLASH,
    ACTIONS(367), 1,
      anon_sym_SQUOTE,
    STATE(112), 1,
      aux_sym_stringValue_repeat2,
    STATE(154), 1,
      sym_escape_sequence,
  [2437] = 5,
    ACTIONS(339), 1,
      sym_string_content_double_quote,
    ACTIONS(341), 1,
      anon_sym_BSLASH,
    ACTIONS(373), 1,
      anon_sym_DQUOTE,
    STATE(121), 1,
      aux_sym_stringValue_repeat1,
    STATE(153), 1,
      sym_escape_sequence,
  [2453] = 5,
    ACTIONS(327), 1,
      sym_string_content_single_quote,
    ACTIONS(329), 1,
      anon_sym_BSLASH,
    ACTIONS(373), 1,
      anon_sym_SQUOTE,
    STATE(122), 1,
      aux_sym_stringValue_repeat2,
    STATE(154), 1,
      sym_escape_sequence,
  [2469] = 5,
    ACTIONS(339), 1,
      sym_string_content_double_quote,
    ACTIONS(341), 1,
      anon_sym_BSLASH,
    ACTIONS(375), 1,
      anon_sym_DQUOTE,
    STATE(101), 1,
      aux_sym_stringValue_repeat1,
    STATE(153), 1,
      sym_escape_sequence,
  [2485] = 5,
    ACTIONS(327), 1,
      sym_string_content_single_quote,
    ACTIONS(329), 1,
      anon_sym_BSLASH,
    ACTIONS(375), 1,
      anon_sym_SQUOTE,
    STATE(112), 1,
      aux_sym_stringValue_repeat2,
    STATE(154), 1,
      sym_escape_sequence,
  [2501] = 4,
    ACTIONS(303), 1,
      anon_sym_java,
    ACTIONS(377), 1,
      anon_sym_RBRACE,
    STATE(125), 1,
      sym__right_brace,
    STATE(117), 2,
      sym_java_override,
      aux_sym_override_block_repeat1,
  [2515] = 3,
    ACTIONS(168), 1,
      anon_sym_override,
    STATE(161), 1,
      sym_override_block,
    ACTIONS(379), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2527] = 2,
    ACTIONS(147), 2,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(381), 2,
      anon_sym_arg,
      sym_identifier,
  [2536] = 4,
    ACTIONS(289), 1,
      anon_sym_implements,
    ACTIONS(383), 1,
      anon_sym_LBRACE,
    STATE(18), 1,
      sym__left_brace,
    STATE(179), 1,
      sym_implements_block,
  [2549] = 1,
    ACTIONS(385), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2556] = 4,
    ACTIONS(256), 1,
      sym_dot,
    ACTIONS(279), 1,
      sym_identifier,
    STATE(77), 1,
      aux_sym_package_string_repeat1,
    STATE(250), 1,
      sym_package_string,
  [2569] = 3,
    ACTIONS(153), 1,
      anon_sym_arg,
    ACTIONS(155), 1,
      sym_identifier,
    STATE(89), 2,
      sym_arg_block,
      sym_enum_constant,
  [2580] = 1,
    ACTIONS(387), 4,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2587] = 1,
    ACTIONS(389), 4,
      anon_sym_implements,
      anon_sym_GT,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [2594] = 4,
    ACTIONS(256), 1,
      sym_dot,
    ACTIONS(279), 1,
      sym_identifier,
    STATE(77), 1,
      aux_sym_package_string_repeat1,
    STATE(219), 1,
      sym_package_string,
  [2607] = 3,
    ACTIONS(391), 1,
      anon_sym_java,
    ACTIONS(394), 1,
      anon_sym_RBRACE,
    STATE(133), 2,
      sym_java_override,
      aux_sym_override_block_repeat1,
  [2618] = 4,
    ACTIONS(396), 1,
      anon_sym_COMMA,
    ACTIONS(399), 1,
      anon_sym_LBRACE,
    STATE(96), 1,
      sym__comma,
    STATE(134), 1,
      aux_sym_implements_block_repeat1,
  [2631] = 1,
    ACTIONS(401), 4,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_L,
  [2638] = 3,
    ACTIONS(403), 1,
      sym_dot,
    ACTIONS(407), 1,
      anon_sym_L,
    ACTIONS(405), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2649] = 4,
    ACTIONS(409), 1,
      anon_sym_COMMA,
    ACTIONS(411), 1,
      anon_sym_LBRACE,
    STATE(96), 1,
      sym__comma,
    STATE(141), 1,
      aux_sym_implements_block_repeat1,
  [2662] = 4,
    ACTIONS(413), 1,
      anon_sym_COMMA,
    ACTIONS(416), 1,
      anon_sym_RPAREN,
    STATE(13), 1,
      sym__comma,
    STATE(138), 1,
      aux_sym_enum_constant_repeat1,
  [2675] = 4,
    ACTIONS(418), 1,
      anon_sym_COMMA,
    ACTIONS(421), 1,
      anon_sym_RPAREN,
    STATE(139), 1,
      aux_sym_identifier_statement_repeat1,
    STATE(261), 1,
      sym__comma,
  [2688] = 4,
    ACTIONS(423), 1,
      anon_sym__,
    ACTIONS(425), 1,
      sym_number,
    STATE(111), 1,
      sym_enum_index,
    STATE(216), 1,
      sym_integerValue,
  [2701] = 4,
    ACTIONS(409), 1,
      anon_sym_COMMA,
    ACTIONS(427), 1,
      anon_sym_LBRACE,
    STATE(96), 1,
      sym__comma,
    STATE(134), 1,
      aux_sym_implements_block_repeat1,
  [2714] = 4,
    ACTIONS(289), 1,
      anon_sym_implements,
    ACTIONS(429), 1,
      anon_sym_LBRACE,
    STATE(21), 1,
      sym__left_brace,
    STATE(196), 1,
      sym_implements_block,
  [2727] = 2,
    ACTIONS(431), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(433), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2736] = 4,
    ACTIONS(435), 1,
      anon_sym_COMMA,
    ACTIONS(438), 1,
      anon_sym_RPAREN,
    STATE(14), 1,
      sym__comma,
    STATE(144), 1,
      aux_sym_func_block_repeat1,
  [2749] = 4,
    ACTIONS(289), 1,
      anon_sym_implements,
    ACTIONS(440), 1,
      anon_sym_LBRACE,
    STATE(61), 1,
      sym__left_brace,
    STATE(217), 1,
      sym_implements_block,
  [2762] = 3,
    ACTIONS(444), 1,
      sym_comment,
    STATE(147), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(442), 2,
      anon_sym_arg,
      sym_identifier,
  [2773] = 3,
    ACTIONS(448), 1,
      sym_comment,
    STATE(147), 1,
      aux_sym_comment_block_repeat1,
    ACTIONS(446), 2,
      anon_sym_arg,
      sym_identifier,
  [2784] = 2,
    ACTIONS(149), 2,
      sym_comment,
      anon_sym_RBRACE,
    ACTIONS(451), 2,
      anon_sym_arg,
      sym_identifier,
  [2793] = 1,
    ACTIONS(453), 4,
      aux_sym_escape_sequence_token1,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
      aux_sym_escape_sequence_token4,
  [2800] = 2,
    ACTIONS(283), 2,
      anon_sym_arg,
      sym_identifier,
    ACTIONS(285), 2,
      sym_comment,
      anon_sym_RBRACE,
  [2809] = 3,
    ACTIONS(455), 1,
      anon_sym_GT,
    ACTIONS(457), 1,
      anon_sym_COMMA,
    STATE(16), 1,
      sym__comma,
  [2819] = 1,
    ACTIONS(459), 3,
      anon_sym_GT,
      sym_identifier,
      anon_sym_COMMA,
  [2825] = 2,
    ACTIONS(463), 1,
      sym_string_content_double_quote,
    ACTIONS(461), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2833] = 2,
    ACTIONS(467), 1,
      sym_string_content_single_quote,
    ACTIONS(465), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2841] = 3,
    ACTIONS(469), 1,
      sym_identifier,
    ACTIONS(471), 1,
      sym_dot,
    STATE(155), 1,
      aux_sym_reftype_repeat1,
  [2851] = 1,
    ACTIONS(474), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_T,
  [2857] = 1,
    ACTIONS(476), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2863] = 2,
    ACTIONS(480), 1,
      sym_string_content_single_quote,
    ACTIONS(478), 2,
      anon_sym_SQUOTE,
      anon_sym_BSLASH,
  [2871] = 3,
    ACTIONS(254), 1,
      sym_identifier,
    ACTIONS(482), 1,
      sym_dot,
    STATE(162), 1,
      aux_sym_package_string_repeat1,
  [2881] = 3,
    ACTIONS(254), 1,
      sym_identifier,
    ACTIONS(482), 1,
      sym_dot,
    STATE(164), 1,
      aux_sym_package_string_repeat1,
  [2891] = 1,
    ACTIONS(365), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2897] = 3,
    ACTIONS(272), 1,
      sym_identifier,
    ACTIONS(482), 1,
      sym_dot,
    STATE(164), 1,
      aux_sym_package_string_repeat1,
  [2907] = 2,
    ACTIONS(480), 1,
      sym_string_content_double_quote,
    ACTIONS(478), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH,
  [2915] = 3,
    ACTIONS(274), 1,
      sym_identifier,
    ACTIONS(484), 1,
      sym_dot,
    STATE(164), 1,
      aux_sym_package_string_repeat1,
  [2925] = 1,
    ACTIONS(487), 3,
      anon_sym_version,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2931] = 3,
    ACTIONS(107), 1,
      anon_sym_DQUOTE,
    ACTIONS(109), 1,
      anon_sym_SQUOTE,
    STATE(277), 1,
      sym_stringValue,
  [2941] = 1,
    ACTIONS(489), 3,
      anon_sym_func,
      sym_comment,
      anon_sym_RBRACE,
  [2947] = 2,
    ACTIONS(491), 1,
      anon_sym_T,
    ACTIONS(405), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2955] = 3,
    ACTIONS(493), 1,
      anon_sym_DQUOTE,
    ACTIONS(495), 1,
      anon_sym_SQUOTE,
    STATE(269), 1,
      sym_stringValue,
  [2965] = 3,
    ACTIONS(493), 1,
      anon_sym_DQUOTE,
    ACTIONS(495), 1,
      anon_sym_SQUOTE,
    STATE(278), 1,
      sym_stringValue,
  [2975] = 3,
    ACTIONS(493), 1,
      anon_sym_DQUOTE,
    ACTIONS(495), 1,
      anon_sym_SQUOTE,
    STATE(279), 1,
      sym_stringValue,
  [2985] = 3,
    ACTIONS(493), 1,
      anon_sym_DQUOTE,
    ACTIONS(495), 1,
      anon_sym_SQUOTE,
    STATE(275), 1,
      sym_stringValue,
  [2995] = 3,
    ACTIONS(493), 1,
      anon_sym_DQUOTE,
    ACTIONS(495), 1,
      anon_sym_SQUOTE,
    STATE(283), 1,
      sym_stringValue,
  [3005] = 3,
    ACTIONS(493), 1,
      anon_sym_DQUOTE,
    ACTIONS(495), 1,
      anon_sym_SQUOTE,
    STATE(255), 1,
      sym_stringValue,
  [3015] = 3,
    ACTIONS(493), 1,
      anon_sym_DQUOTE,
    ACTIONS(495), 1,
      anon_sym_SQUOTE,
    STATE(256), 1,
      sym_stringValue,
  [3025] = 3,
    ACTIONS(493), 1,
      anon_sym_DQUOTE,
    ACTIONS(495), 1,
      anon_sym_SQUOTE,
    STATE(230), 1,
      sym_stringValue,
  [3035] = 1,
    ACTIONS(274), 2,
      sym_identifier,
      sym_dot,
  [3040] = 1,
    ACTIONS(497), 2,
      anon_sym_java,
      anon_sym_RBRACE,
  [3045] = 2,
    ACTIONS(499), 1,
      anon_sym_LBRACE,
    STATE(23), 1,
      sym__left_brace,
  [3052] = 2,
    ACTIONS(501), 1,
      anon_sym_SEMI2,
    STATE(106), 1,
      sym__semicolon,
  [3059] = 2,
    ACTIONS(503), 1,
      anon_sym_model,
    STATE(236), 1,
      sym_model_declaration,
  [3066] = 2,
    ACTIONS(505), 1,
      anon_sym_RBRACE,
    STATE(58), 1,
      sym__right_brace,
  [3073] = 2,
    ACTIONS(507), 1,
      anon_sym_SEMI2,
    STATE(272), 1,
      sym__semicolon,
  [3080] = 2,
    ACTIONS(509), 1,
      sym_number,
    STATE(244), 1,
      sym_version_number,
  [3087] = 1,
    ACTIONS(511), 2,
      anon_sym_java,
      anon_sym_RBRACE,
  [3092] = 2,
    ACTIONS(513), 1,
      anon_sym_RBRACE,
    STATE(52), 1,
      sym__right_brace,
  [3099] = 2,
    ACTIONS(515), 1,
      anon_sym_SEMI2,
    STATE(82), 1,
      sym__semicolon,
  [3106] = 2,
    ACTIONS(517), 1,
      anon_sym_LPAREN,
    STATE(140), 1,
      sym__left_paren,
  [3113] = 1,
    ACTIONS(519), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3118] = 1,
    ACTIONS(416), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3123] = 1,
    ACTIONS(405), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3128] = 2,
    ACTIONS(509), 1,
      sym_number,
    STATE(268), 1,
      sym_version_number,
  [3135] = 2,
    ACTIONS(521), 1,
      anon_sym_SEMI2,
    STATE(110), 1,
      sym__semicolon,
  [3142] = 1,
    ACTIONS(421), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3147] = 2,
    ACTIONS(523), 1,
      anon_sym_SEMI2,
    STATE(238), 1,
      sym__semicolon,
  [3154] = 2,
    ACTIONS(525), 1,
      anon_sym_LBRACE,
    STATE(28), 1,
      sym__left_brace,
  [3161] = 2,
    ACTIONS(527), 1,
      anon_sym_SEMI2,
    STATE(80), 1,
      sym__semicolon,
  [3168] = 2,
    ACTIONS(383), 1,
      anon_sym_LBRACE,
    STATE(18), 1,
      sym__left_brace,
  [3175] = 2,
    ACTIONS(529), 1,
      anon_sym_SEMI2,
    STATE(83), 1,
      sym__semicolon,
  [3182] = 2,
    ACTIONS(531), 1,
      anon_sym_RBRACE,
    STATE(47), 1,
      sym__right_brace,
  [3189] = 1,
    ACTIONS(533), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3194] = 1,
    ACTIONS(535), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3199] = 2,
    ACTIONS(425), 1,
      sym_number,
    STATE(210), 1,
      sym_integerValue,
  [3206] = 1,
    ACTIONS(537), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3211] = 2,
    ACTIONS(539), 1,
      aux_sym_timeValue_token1,
    STATE(211), 1,
      sym_timeValue,
  [3218] = 1,
    ACTIONS(399), 2,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [3223] = 1,
    ACTIONS(438), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3228] = 2,
    ACTIONS(541), 1,
      anon_sym_SEMI2,
    STATE(84), 1,
      sym__semicolon,
  [3235] = 2,
    ACTIONS(121), 1,
      anon_sym_func,
    STATE(114), 1,
      sym_func_block,
  [3242] = 1,
    ACTIONS(543), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3247] = 1,
    ACTIONS(545), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3252] = 2,
    ACTIONS(547), 1,
      anon_sym_SEMI2,
    STATE(81), 1,
      sym__semicolon,
  [3259] = 2,
    ACTIONS(429), 1,
      anon_sym_LBRACE,
    STATE(21), 1,
      sym__left_brace,
  [3266] = 1,
    ACTIONS(549), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3271] = 2,
    ACTIONS(551), 1,
      anon_sym_LPAREN,
    STATE(6), 1,
      sym__left_paren,
  [3278] = 1,
    ACTIONS(553), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [3283] = 2,
    ACTIONS(555), 1,
      anon_sym_LBRACE,
    STATE(66), 1,
      sym__left_brace,
  [3290] = 2,
    ACTIONS(557), 1,
      anon_sym_LBRACE,
    STATE(9), 1,
      sym__left_brace,
  [3297] = 2,
    ACTIONS(559), 1,
      anon_sym_LBRACE,
    STATE(4), 1,
      sym__left_brace,
  [3304] = 2,
    ACTIONS(561), 1,
      anon_sym_RBRACE,
    STATE(51), 1,
      sym__right_brace,
  [3311] = 2,
    ACTIONS(563), 1,
      sym_identifier,
    ACTIONS(566), 1,
      sym_dot,
  [3318] = 2,
    ACTIONS(568), 1,
      anon_sym_LBRACE,
    STATE(36), 1,
      sym__left_brace,
  [3325] = 2,
    ACTIONS(566), 1,
      sym_dot,
    ACTIONS(570), 1,
      sym_identifier,
  [3332] = 1,
    ACTIONS(573), 2,
      anon_sym_implements,
      anon_sym_LBRACE,
  [3337] = 2,
    ACTIONS(575), 1,
      anon_sym_LBRACE,
    STATE(103), 1,
      sym__left_brace,
  [3344] = 2,
    ACTIONS(577), 1,
      anon_sym_LBRACE,
    STATE(123), 1,
      sym__left_brace,
  [3351] = 2,
    ACTIONS(579), 1,
      anon_sym_LPAREN,
    STATE(258), 1,
      sym__left_paren,
  [3358] = 1,
    ACTIONS(581), 1,
      anon_sym_COLON,
  [3362] = 1,
    ACTIONS(583), 1,
      sym__new_line,
  [3366] = 1,
    ACTIONS(585), 1,
      sym__new_line,
  [3370] = 1,
    ACTIONS(587), 1,
      ts_builtin_sym_end,
  [3374] = 1,
    ACTIONS(589), 1,
      sym_number,
  [3378] = 1,
    ACTIONS(591), 1,
      anon_sym_DASH,
  [3382] = 1,
    ACTIONS(593), 1,
      sym__new_line,
  [3386] = 1,
    ACTIONS(595), 1,
      sym_identifier,
  [3390] = 1,
    ACTIONS(597), 1,
      sym__new_line,
  [3394] = 1,
    ACTIONS(599), 1,
      sym__new_line,
  [3398] = 1,
    ACTIONS(601), 1,
      anon_sym_RBRACE,
  [3402] = 1,
    ACTIONS(603), 1,
      sym_number,
  [3406] = 1,
    ACTIONS(605), 1,
      sym_identifier,
  [3410] = 1,
    ACTIONS(607), 1,
      anon_sym_LT,
  [3414] = 1,
    ACTIONS(609), 1,
      sym_identifier,
  [3418] = 1,
    ACTIONS(611), 1,
      sym_identifier,
  [3422] = 1,
    ACTIONS(613), 1,
      sym__new_line,
  [3426] = 1,
    ACTIONS(615), 1,
      aux_sym_dateValue_token2,
  [3430] = 1,
    ACTIONS(617), 1,
      sym_identifier,
  [3434] = 1,
    ACTIONS(619), 1,
      anon_sym_COLON,
  [3438] = 1,
    ACTIONS(621), 1,
      sym_byte_content,
  [3442] = 1,
    ACTIONS(623), 1,
      aux_sym_dateValue_token1,
  [3446] = 1,
    ACTIONS(625), 1,
      anon_sym_from,
  [3450] = 1,
    ACTIONS(627), 1,
      anon_sym_DASH,
  [3454] = 1,
    ACTIONS(629), 1,
      aux_sym_timeValue_token2,
  [3458] = 1,
    ACTIONS(631), 1,
      anon_sym_SEMI,
  [3462] = 1,
    ACTIONS(633), 1,
      aux_sym_dateValue_token3,
  [3466] = 1,
    ACTIONS(635), 1,
      sym__new_line,
  [3470] = 1,
    ACTIONS(637), 1,
      sym__new_line,
  [3474] = 1,
    ACTIONS(639), 1,
      aux_sym_timeValue_token2,
  [3478] = 1,
    ACTIONS(641), 1,
      sym_identifier,
  [3482] = 1,
    ACTIONS(476), 1,
      sym__new_line,
  [3486] = 1,
    ACTIONS(643), 1,
      anon_sym_SEMI,
  [3490] = 1,
    ACTIONS(645), 1,
      sym_identifier,
  [3494] = 1,
    ACTIONS(487), 1,
      sym__new_line,
  [3498] = 1,
    ACTIONS(647), 1,
      sym_identifier,
  [3502] = 1,
    ACTIONS(649), 1,
      sym_dot,
  [3506] = 1,
    ACTIONS(651), 1,
      anon_sym_LT,
  [3510] = 1,
    ACTIONS(653), 1,
      sym_number,
  [3514] = 1,
    ACTIONS(655), 1,
      ts_builtin_sym_end,
  [3518] = 1,
    ACTIONS(657), 1,
      sym__new_line,
  [3522] = 1,
    ACTIONS(659), 1,
      sym__new_line,
  [3526] = 1,
    ACTIONS(389), 1,
      sym_identifier,
  [3530] = 1,
    ACTIONS(661), 1,
      sym_identifier,
  [3534] = 1,
    ACTIONS(663), 1,
      anon_sym_RBRACE,
  [3538] = 1,
    ACTIONS(665), 1,
      sym_identifier,
  [3542] = 1,
    ACTIONS(387), 1,
      sym_identifier,
  [3546] = 1,
    ACTIONS(667), 1,
      sym__new_line,
  [3550] = 1,
    ACTIONS(669), 1,
      sym_identifier,
  [3554] = 1,
    ACTIONS(671), 1,
      anon_sym_version,
  [3558] = 1,
    ACTIONS(673), 1,
      sym__new_line,
  [3562] = 1,
    ACTIONS(675), 1,
      sym__new_line,
  [3566] = 1,
    ACTIONS(677), 1,
      ts_builtin_sym_end,
  [3570] = 1,
    ACTIONS(679), 1,
      sym_dot,
  [3574] = 1,
    ACTIONS(681), 1,
      sym_identifier,
  [3578] = 1,
    ACTIONS(683), 1,
      sym__new_line,
  [3582] = 1,
    ACTIONS(685), 1,
      anon_sym_SEMI,
  [3586] = 1,
    ACTIONS(687), 1,
      anon_sym_GT,
  [3590] = 1,
    ACTIONS(689), 1,
      sym_identifier,
  [3594] = 1,
    ACTIONS(691), 1,
      sym_identifier,
  [3598] = 1,
    ACTIONS(693), 1,
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
  [SMALL_STATE(10)] = 348,
  [SMALL_STATE(11)] = 388,
  [SMALL_STATE(12)] = 421,
  [SMALL_STATE(13)] = 458,
  [SMALL_STATE(14)] = 495,
  [SMALL_STATE(15)] = 528,
  [SMALL_STATE(16)] = 558,
  [SMALL_STATE(17)] = 588,
  [SMALL_STATE(18)] = 623,
  [SMALL_STATE(19)] = 658,
  [SMALL_STATE(20)] = 693,
  [SMALL_STATE(21)] = 728,
  [SMALL_STATE(22)] = 763,
  [SMALL_STATE(23)] = 798,
  [SMALL_STATE(24)] = 833,
  [SMALL_STATE(25)] = 868,
  [SMALL_STATE(26)] = 903,
  [SMALL_STATE(27)] = 938,
  [SMALL_STATE(28)] = 973,
  [SMALL_STATE(29)] = 1008,
  [SMALL_STATE(30)] = 1041,
  [SMALL_STATE(31)] = 1057,
  [SMALL_STATE(32)] = 1073,
  [SMALL_STATE(33)] = 1099,
  [SMALL_STATE(34)] = 1129,
  [SMALL_STATE(35)] = 1147,
  [SMALL_STATE(36)] = 1165,
  [SMALL_STATE(37)] = 1195,
  [SMALL_STATE(38)] = 1213,
  [SMALL_STATE(39)] = 1231,
  [SMALL_STATE(40)] = 1249,
  [SMALL_STATE(41)] = 1262,
  [SMALL_STATE(42)] = 1275,
  [SMALL_STATE(43)] = 1292,
  [SMALL_STATE(44)] = 1305,
  [SMALL_STATE(45)] = 1318,
  [SMALL_STATE(46)] = 1345,
  [SMALL_STATE(47)] = 1368,
  [SMALL_STATE(48)] = 1381,
  [SMALL_STATE(49)] = 1394,
  [SMALL_STATE(50)] = 1407,
  [SMALL_STATE(51)] = 1420,
  [SMALL_STATE(52)] = 1433,
  [SMALL_STATE(53)] = 1446,
  [SMALL_STATE(54)] = 1459,
  [SMALL_STATE(55)] = 1486,
  [SMALL_STATE(56)] = 1499,
  [SMALL_STATE(57)] = 1522,
  [SMALL_STATE(58)] = 1535,
  [SMALL_STATE(59)] = 1548,
  [SMALL_STATE(60)] = 1561,
  [SMALL_STATE(61)] = 1578,
  [SMALL_STATE(62)] = 1604,
  [SMALL_STATE(63)] = 1616,
  [SMALL_STATE(64)] = 1642,
  [SMALL_STATE(65)] = 1654,
  [SMALL_STATE(66)] = 1670,
  [SMALL_STATE(67)] = 1696,
  [SMALL_STATE(68)] = 1712,
  [SMALL_STATE(69)] = 1738,
  [SMALL_STATE(70)] = 1750,
  [SMALL_STATE(71)] = 1773,
  [SMALL_STATE(72)] = 1784,
  [SMALL_STATE(73)] = 1795,
  [SMALL_STATE(74)] = 1810,
  [SMALL_STATE(75)] = 1825,
  [SMALL_STATE(76)] = 1841,
  [SMALL_STATE(77)] = 1855,
  [SMALL_STATE(78)] = 1869,
  [SMALL_STATE(79)] = 1879,
  [SMALL_STATE(80)] = 1889,
  [SMALL_STATE(81)] = 1899,
  [SMALL_STATE(82)] = 1909,
  [SMALL_STATE(83)] = 1919,
  [SMALL_STATE(84)] = 1929,
  [SMALL_STATE(85)] = 1939,
  [SMALL_STATE(86)] = 1953,
  [SMALL_STATE(87)] = 1967,
  [SMALL_STATE(88)] = 1976,
  [SMALL_STATE(89)] = 1995,
  [SMALL_STATE(90)] = 2010,
  [SMALL_STATE(91)] = 2029,
  [SMALL_STATE(92)] = 2038,
  [SMALL_STATE(93)] = 2057,
  [SMALL_STATE(94)] = 2066,
  [SMALL_STATE(95)] = 2085,
  [SMALL_STATE(96)] = 2100,
  [SMALL_STATE(97)] = 2119,
  [SMALL_STATE(98)] = 2129,
  [SMALL_STATE(99)] = 2145,
  [SMALL_STATE(100)] = 2159,
  [SMALL_STATE(101)] = 2175,
  [SMALL_STATE(102)] = 2191,
  [SMALL_STATE(103)] = 2207,
  [SMALL_STATE(104)] = 2221,
  [SMALL_STATE(105)] = 2237,
  [SMALL_STATE(106)] = 2253,
  [SMALL_STATE(107)] = 2263,
  [SMALL_STATE(108)] = 2279,
  [SMALL_STATE(109)] = 2295,
  [SMALL_STATE(110)] = 2305,
  [SMALL_STATE(111)] = 2315,
  [SMALL_STATE(112)] = 2331,
  [SMALL_STATE(113)] = 2347,
  [SMALL_STATE(114)] = 2363,
  [SMALL_STATE(115)] = 2375,
  [SMALL_STATE(116)] = 2391,
  [SMALL_STATE(117)] = 2407,
  [SMALL_STATE(118)] = 2421,
  [SMALL_STATE(119)] = 2437,
  [SMALL_STATE(120)] = 2453,
  [SMALL_STATE(121)] = 2469,
  [SMALL_STATE(122)] = 2485,
  [SMALL_STATE(123)] = 2501,
  [SMALL_STATE(124)] = 2515,
  [SMALL_STATE(125)] = 2527,
  [SMALL_STATE(126)] = 2536,
  [SMALL_STATE(127)] = 2549,
  [SMALL_STATE(128)] = 2556,
  [SMALL_STATE(129)] = 2569,
  [SMALL_STATE(130)] = 2580,
  [SMALL_STATE(131)] = 2587,
  [SMALL_STATE(132)] = 2594,
  [SMALL_STATE(133)] = 2607,
  [SMALL_STATE(134)] = 2618,
  [SMALL_STATE(135)] = 2631,
  [SMALL_STATE(136)] = 2638,
  [SMALL_STATE(137)] = 2649,
  [SMALL_STATE(138)] = 2662,
  [SMALL_STATE(139)] = 2675,
  [SMALL_STATE(140)] = 2688,
  [SMALL_STATE(141)] = 2701,
  [SMALL_STATE(142)] = 2714,
  [SMALL_STATE(143)] = 2727,
  [SMALL_STATE(144)] = 2736,
  [SMALL_STATE(145)] = 2749,
  [SMALL_STATE(146)] = 2762,
  [SMALL_STATE(147)] = 2773,
  [SMALL_STATE(148)] = 2784,
  [SMALL_STATE(149)] = 2793,
  [SMALL_STATE(150)] = 2800,
  [SMALL_STATE(151)] = 2809,
  [SMALL_STATE(152)] = 2819,
  [SMALL_STATE(153)] = 2825,
  [SMALL_STATE(154)] = 2833,
  [SMALL_STATE(155)] = 2841,
  [SMALL_STATE(156)] = 2851,
  [SMALL_STATE(157)] = 2857,
  [SMALL_STATE(158)] = 2863,
  [SMALL_STATE(159)] = 2871,
  [SMALL_STATE(160)] = 2881,
  [SMALL_STATE(161)] = 2891,
  [SMALL_STATE(162)] = 2897,
  [SMALL_STATE(163)] = 2907,
  [SMALL_STATE(164)] = 2915,
  [SMALL_STATE(165)] = 2925,
  [SMALL_STATE(166)] = 2931,
  [SMALL_STATE(167)] = 2941,
  [SMALL_STATE(168)] = 2947,
  [SMALL_STATE(169)] = 2955,
  [SMALL_STATE(170)] = 2965,
  [SMALL_STATE(171)] = 2975,
  [SMALL_STATE(172)] = 2985,
  [SMALL_STATE(173)] = 2995,
  [SMALL_STATE(174)] = 3005,
  [SMALL_STATE(175)] = 3015,
  [SMALL_STATE(176)] = 3025,
  [SMALL_STATE(177)] = 3035,
  [SMALL_STATE(178)] = 3040,
  [SMALL_STATE(179)] = 3045,
  [SMALL_STATE(180)] = 3052,
  [SMALL_STATE(181)] = 3059,
  [SMALL_STATE(182)] = 3066,
  [SMALL_STATE(183)] = 3073,
  [SMALL_STATE(184)] = 3080,
  [SMALL_STATE(185)] = 3087,
  [SMALL_STATE(186)] = 3092,
  [SMALL_STATE(187)] = 3099,
  [SMALL_STATE(188)] = 3106,
  [SMALL_STATE(189)] = 3113,
  [SMALL_STATE(190)] = 3118,
  [SMALL_STATE(191)] = 3123,
  [SMALL_STATE(192)] = 3128,
  [SMALL_STATE(193)] = 3135,
  [SMALL_STATE(194)] = 3142,
  [SMALL_STATE(195)] = 3147,
  [SMALL_STATE(196)] = 3154,
  [SMALL_STATE(197)] = 3161,
  [SMALL_STATE(198)] = 3168,
  [SMALL_STATE(199)] = 3175,
  [SMALL_STATE(200)] = 3182,
  [SMALL_STATE(201)] = 3189,
  [SMALL_STATE(202)] = 3194,
  [SMALL_STATE(203)] = 3199,
  [SMALL_STATE(204)] = 3206,
  [SMALL_STATE(205)] = 3211,
  [SMALL_STATE(206)] = 3218,
  [SMALL_STATE(207)] = 3223,
  [SMALL_STATE(208)] = 3228,
  [SMALL_STATE(209)] = 3235,
  [SMALL_STATE(210)] = 3242,
  [SMALL_STATE(211)] = 3247,
  [SMALL_STATE(212)] = 3252,
  [SMALL_STATE(213)] = 3259,
  [SMALL_STATE(214)] = 3266,
  [SMALL_STATE(215)] = 3271,
  [SMALL_STATE(216)] = 3278,
  [SMALL_STATE(217)] = 3283,
  [SMALL_STATE(218)] = 3290,
  [SMALL_STATE(219)] = 3297,
  [SMALL_STATE(220)] = 3304,
  [SMALL_STATE(221)] = 3311,
  [SMALL_STATE(222)] = 3318,
  [SMALL_STATE(223)] = 3325,
  [SMALL_STATE(224)] = 3332,
  [SMALL_STATE(225)] = 3337,
  [SMALL_STATE(226)] = 3344,
  [SMALL_STATE(227)] = 3351,
  [SMALL_STATE(228)] = 3358,
  [SMALL_STATE(229)] = 3362,
  [SMALL_STATE(230)] = 3366,
  [SMALL_STATE(231)] = 3370,
  [SMALL_STATE(232)] = 3374,
  [SMALL_STATE(233)] = 3378,
  [SMALL_STATE(234)] = 3382,
  [SMALL_STATE(235)] = 3386,
  [SMALL_STATE(236)] = 3390,
  [SMALL_STATE(237)] = 3394,
  [SMALL_STATE(238)] = 3398,
  [SMALL_STATE(239)] = 3402,
  [SMALL_STATE(240)] = 3406,
  [SMALL_STATE(241)] = 3410,
  [SMALL_STATE(242)] = 3414,
  [SMALL_STATE(243)] = 3418,
  [SMALL_STATE(244)] = 3422,
  [SMALL_STATE(245)] = 3426,
  [SMALL_STATE(246)] = 3430,
  [SMALL_STATE(247)] = 3434,
  [SMALL_STATE(248)] = 3438,
  [SMALL_STATE(249)] = 3442,
  [SMALL_STATE(250)] = 3446,
  [SMALL_STATE(251)] = 3450,
  [SMALL_STATE(252)] = 3454,
  [SMALL_STATE(253)] = 3458,
  [SMALL_STATE(254)] = 3462,
  [SMALL_STATE(255)] = 3466,
  [SMALL_STATE(256)] = 3470,
  [SMALL_STATE(257)] = 3474,
  [SMALL_STATE(258)] = 3478,
  [SMALL_STATE(259)] = 3482,
  [SMALL_STATE(260)] = 3486,
  [SMALL_STATE(261)] = 3490,
  [SMALL_STATE(262)] = 3494,
  [SMALL_STATE(263)] = 3498,
  [SMALL_STATE(264)] = 3502,
  [SMALL_STATE(265)] = 3506,
  [SMALL_STATE(266)] = 3510,
  [SMALL_STATE(267)] = 3514,
  [SMALL_STATE(268)] = 3518,
  [SMALL_STATE(269)] = 3522,
  [SMALL_STATE(270)] = 3526,
  [SMALL_STATE(271)] = 3530,
  [SMALL_STATE(272)] = 3534,
  [SMALL_STATE(273)] = 3538,
  [SMALL_STATE(274)] = 3542,
  [SMALL_STATE(275)] = 3546,
  [SMALL_STATE(276)] = 3550,
  [SMALL_STATE(277)] = 3554,
  [SMALL_STATE(278)] = 3558,
  [SMALL_STATE(279)] = 3562,
  [SMALL_STATE(280)] = 3566,
  [SMALL_STATE(281)] = 3570,
  [SMALL_STATE(282)] = 3574,
  [SMALL_STATE(283)] = 3578,
  [SMALL_STATE(284)] = 3582,
  [SMALL_STATE(285)] = 3586,
  [SMALL_STATE(286)] = 3590,
  [SMALL_STATE(287)] = 3594,
  [SMALL_STATE(288)] = 3598,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(263),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(132),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(263),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(271),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(273),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(276),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_model_content_repeat1, 2, 0, 0), SHIFT_REPEAT(46),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(152),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_content, 1, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(288),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_java_override_repeat1, 2, 0, 0), SHIFT_REPEAT(169),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_java_override_repeat1, 2, 0, 0), SHIFT_REPEAT(170),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_java_override_repeat1, 2, 0, 0), SHIFT_REPEAT(171),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_java_override_repeat1, 2, 0, 0), SHIFT_REPEAT(173),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_java_override_repeat1, 2, 0, 0), SHIFT_REPEAT(174),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_java_override_repeat1, 2, 0, 0), SHIFT_REPEAT(175),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_java_override_repeat1, 2, 0, 0), SHIFT_REPEAT(176),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_java_override_repeat1, 2, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [133] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_block_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_override_block, 3, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_override_block, 4, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [153] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [155] = {.entry = {.count = 1, .reusable = false}}, SHIFT(188),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0),
  [163] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 1, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 3, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_block, 1, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 2, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 5, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 4, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_block, 1, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 5, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 4, 0, 0),
  [190] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [193] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(188),
  [196] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0), SHIFT_REPEAT(146),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_block_repeat1, 2, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 5, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 6, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_block, 5, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 7, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 7, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 6, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_block, 6, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = false}}, SHIFT(265),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_block, 4, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 4, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_block, 8, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_block, 5, 0, 0),
  [225] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0), SHIFT_REPEAT(128),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_block_repeat1, 2, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_content, 4, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [240] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [243] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_interface_block_repeat1, 2, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 5, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 2, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 1, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 1, 0, 0),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_block, 4, 0, 0),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref_block, 4, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_block, 7, 0, 0),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_block, 9, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 6, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 7, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_block, 8, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_string, 2, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0),
  [276] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(242),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [281] = {.entry = {.count = 1, .reusable = false}}, SHIFT(226),
  [283] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_content, 2, 0, 0),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_content, 2, 0, 0),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_content, 3, 0, 0),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [297] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_content, 1, 0, 0),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_content, 1, 0, 0),
  [301] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_block, 4, 0, 0),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [311] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0),
  [313] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [316] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 2, 0, 0), SHIFT_REPEAT(127),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [325] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [329] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [335] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 5, 0, 0),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 5, 0, 0),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [341] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 1, 0, 0),
  [349] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constant, 6, 0, 0),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constant, 6, 0, 0),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [355] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0),
  [357] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(154),
  [360] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 2, 0, 0), SHIFT_REPEAT(149),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [365] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 2, 0, 0),
  [367] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [373] = {.entry = {.count = 1, .reusable = false}}, SHIFT(259),
  [375] = {.entry = {.count = 1, .reusable = false}}, SHIFT(262),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 1, 0, 0),
  [381] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_override_block, 3, 0, 0),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 2, 0, 0),
  [389] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reftype, 1, 0, 0),
  [391] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_override_block_repeat1, 2, 0, 0), SHIFT_REPEAT(218),
  [394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_override_block_repeat1, 2, 0, 0),
  [396] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_implements_block_repeat1, 2, 0, 0),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integerValue, 3, 0, 0),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_value, 1, 0, 0),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 2, 0, 0),
  [413] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_constant_repeat1, 2, 0, 0),
  [418] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(261),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_statement_repeat1, 2, 0, 0),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [427] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implements_block, 3, 0, 0),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [431] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_content, 3, 0, 0),
  [433] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_content, 3, 0, 0),
  [435] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [438] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_func_block_repeat1, 2, 0, 0),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [442] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment_block, 1, 0, 0),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [446] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0),
  [448] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_block_repeat1, 2, 0, 0), SHIFT_REPEAT(147),
  [451] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_override_block, 4, 0, 0),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [459] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [461] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [463] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat1, 1, 0, 0),
  [465] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_stringValue_repeat2, 1, 0, 0),
  [467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stringValue_repeat2, 1, 0, 0),
  [469] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0),
  [471] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 2, 0, 0), SHIFT_REPEAT(155),
  [474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateValue, 6, 0, 0),
  [476] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 2, 0, 0),
  [478] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [480] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(282),
  [484] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_string_repeat1, 2, 0, 0), SHIFT_REPEAT(282),
  [487] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stringValue, 3, 0, 1),
  [489] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_content, 3, 0, 0),
  [491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [497] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_java_override, 3, 0, 0),
  [499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(272),
  [509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_java_override, 4, 0, 0),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [519] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_booleanValue, 1, 0, 0),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [533] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_definition, 2, 0, 0),
  [535] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byteValue, 2, 0, 0),
  [537] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_longValue, 2, 0, 0),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [543] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doubleValue, 3, 0, 0),
  [545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dateTimeValue, 3, 0, 0),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [549] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeValue, 5, 0, 0),
  [551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [553] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_index, 1, 0, 0),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [563] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(177),
  [566] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0),
  [568] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [570] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_reftype_repeat1, 1, 0, 0), SHIFT(93),
  [573] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_extends_block, 2, 0, 0),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [585] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_java_type, 2, 0, 0),
  [587] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 5, 0, 0),
  [589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [593] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_version_number, 5, 0, 0),
  [595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [601] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 6, 0, 0),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [613] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dmf_declaration, 2, 0, 0),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(252),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [635] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_java_class, 2, 0, 0),
  [637] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_java_name, 2, 0, 0),
  [639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [643] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [649] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [651] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_name, 1, 0, 0),
  [653] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [655] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [657] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_model_declaration, 4, 0, 0),
  [659] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_java_annotation, 2, 0, 0),
  [661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [663] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_statement, 5, 0, 0),
  [665] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [669] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [671] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [673] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_java_doc, 2, 0, 0),
  [675] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_java_extends, 2, 0, 0),
  [677] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 6, 0, 0),
  [679] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [681] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [683] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_java_implements, 2, 0, 0),
  [685] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [687] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [689] = {.entry = {.count = 1, .reusable = true}}, SHIFT(284),
  [691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
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
