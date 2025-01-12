/**
 * @file Domain Model Framework
 * @author Alexander Brand
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "dmf",
  //
  conflicts: $ => [
    //TODO entfernen wenn package_strind unf reftype richtig verwendet werden
    [$.reftype, $.package_string],
  ],

  // word: $ => $.identifier,
  rules: {
    // TODO: add the actual grammar rules


    source_file: $ =>
      seq(
        $.dmf_declaration,
        $._new_line,
        $.model_declaration,
        $._new_line,
        optional($.import_block),
        $.model_content,
      ),


    dmf_declaration: $ => seq(
      'dmf',
      $.version_number,
    ),
    model_declaration: $ => seq(
      'model',
      $.stringValue,
      'version',
      $.version_number,
    ),

    import_block: $ => repeat1($.import_statement),
    import_statement: $ => seq(
      'import',
      $.package_string,
      'from',
      $.stringValue,
      optional($.model_identifier),
      $._new_line,
    ),
    model_identifier: $ => seq(
      $._left_paren,
      'model',
      $.stringValue,
      optional(seq('version', $.version_number)),
      $._right_paren,
    ),


    model_content: $ => repeat1($.package_content),

    comment_block: $ => prec.right(repeat1($.comment)),

    // Package
    package_block: $ => seq(
      'package',
      $.package_string,
      $._left_brace,
      repeat($.package_content),
      $._right_brace,
    ),
    package_content: $ => seq(
      optional($.comment_block),
      optional($.expand),
      choice(
        $.package_block,
        $.struct_block,
        $.enum_block,
        $.entity_block,
        $.interface_block,
      )),


    // Struct
    struct_block: $ => seq(
      'struct',
      $.identifier,
      optional($.extends_block),
      optional($.implements_block),
      $._left_brace,
      repeat($.struct_content),
      $._right_brace,
    ),
    extends_block: $ => seq(
      'extends',
      $.reftype,
    ),
    implements_block: $ => seq(
      'implements',
      $.reftype,
      repeat(seq(
        $._comma,
        $.reftype
      ))
    ),
    struct_content: $ => seq(
      optional($.comment_block),
      choice(
        $.arg_block,
        $.ref_block,
        $.func_block,
      ),
    ),
    arg_block: $ => seq('arg', $.primitive_type, $.identifier, optional($._semicolon)),
    ref_block: $ => seq('ref', $.reftype, $.identifier, optional($._semicolon)),
    func_block: $ => seq('func', choice($.reftype, $.primitive_type, $.void), $.identifier,
      $._left_paren, optional(seq($.param_definition, repeat(seq($._comma, $.param_definition)))), $._right_paren,optional($._semicolon),),
    param_definition: $ => seq(choice($.reftype, $.primitive_type), $.identifier),

    // Enum
    enum_block: $ => seq(
      'enum',
      $.identifier,
      $._left_brace,
      repeat($.enum_content),
      $._right_brace,
    ),
    enum_content: $ => seq(choice($.arg_block, $.enum_constant)),
    enum_constant: $ => seq(optional($.comment_block), $.identifier, $._left_paren, $.enum_index, repeat(seq($._comma, $.primitive_value)), $._right_paren, optional($._semicolon)),
    enum_index: $ => choice('_', $.integerValue),


    // Entity
    entity_block: $ => seq(
      'entity',
      $.identifier,
      optional($.extends_block),
      optional($.implements_block),
      $._left_brace,
      repeat($.struct_content),
      $.identifier_statement,
      $._right_brace,
    ),
    identifier_statement: $ => seq('identifier', $._left_paren, $.identifier, repeat(seq($._comma, $.identifier)), $._right_paren, optional($._semicolon)),


    interface_block: $ => seq(
      'interface',
      $.identifier,
      optional($.implements_block),
      $._left_brace,
      repeat($.interface_content),
      $._right_brace,
    ),
    interface_content: $ => seq(
      optional($.comment_block),
      $.func_block
    ),


    // Tokens
    number: $ => /[0-9]+/,
    identifier: $ => /([a-zA-Z_])+/,
    comment: $ => /\/\/.*\n/,
    //nicht intern, da die Anzahl der Punkte beim reftype wichtig ist
    dot: $ => '.',
    byte_content: $ => /[0-9A-F]{4}/,

    _semicolon: $ => ';',
    _comma: $ => ',',
    _left_brace: $ => '{',
    _right_brace: $ => '}',
    _left_bracket: $ => '[',
    _right_bracket: $ => ']',
    _left_paren: $ => '(',
    _right_paren: $ => ')',
    _at: $ => '@',
    _new_line: $ => /\n/,

    reftype: $ => seq(
      repeat($.dot),
      $.package_string,
    ),

    package_string: $ => prec.left(
      choice(
        $.identifier,
        seq(
          $.identifier,
          repeat1(
            seq(
              $.dot,
              $.identifier,
            )
          )
        ),
        seq(
          repeat1(
            seq(
              $.dot,
              $.identifier,
            )
          )
        )
      )),

    primitive_type: $ => choice(
      $.byte,
      $.int,
      $.long,
      $.double,
      $.datetime,
      $.date,
      $.string,
      $.boolean,
    ),

    primitive_value: $ => choice(
      $.integerValue,
      $.doubleValue,
      $.stringValue,
      $.dateValue,
      $.dateTimeValue,
      $.booleanValue,
      $.byteValue,
      $.longValue,
    ),


    // Keywords
    package: $ => 'package',
    struct: $ => 'struct',
    enum: $ => 'enum',
    entity: $ => 'entity',
    interface: $ => 'interface',
    arg: $ => 'arg',
    ref: $ => 'ref',
    func: $ => 'func',
    expand: $ => 'expand',
    extends: $ => 'extends',
    implements: $ => 'implements',

    byte: $ => 'byte',
    int: $ => 'int',
    long: $ => 'long',
    double: $ => 'double',
    datetime: $ => 'datetime',
    date: $ => 'date',
    string: $ => 'string',
    boolean: $ => 'boolean',
    void: $ => 'void',

    //Value Tokens
    version_number: $ => seq(
      $.number,
      $.dot,
      $.number,
      $.dot,
      $.number,
    ),

    integerValue: $ => seq(
      $.number,
      optional(seq(
        '_',
        $.number,
      ))
    ),

    longValue: $ => seq($.integerValue, token.immediate('L')),

    booleanValue: $ => choice('true', 'false'),

    byteValue: $ => seq('0x', $.byte_content),

    // Basic string with escapes
    doubleValue: $ => prec(1, seq(
      $.integerValue,
      $.dot,
      $.integerValue
    )),

    // Multiline string (triple-quoted)
    stringValue: $ => choice(
      // Double quoted string
      seq(
        '"',
        alias(repeat(choice(
          $.string_content_double_quote, // Any chars except quotes or backslash
          $.escape_sequence
        )), "content"),
        '"'
      ),
      // Single quoted string
      seq(
        "'",
        alias(repeat(choice(
          $.string_content_single_quote, // Any chars except quotes or backslash
          $.escape_sequence
        )),"content"),
        "'"
      )
    ),

    string_content_single_quote: $ => /[^'\\]+/,
    string_content_double_quote: $ => /[^"\\]+/,

    // Common escape sequences
    escape_sequence: $ => seq(
      '\\',
      choice(
        /[\\'"bfnrt]/, // Single-char escapes
        /u[0-9a-fA-F]{4}/, // Unicode escapes
        /x[0-9a-fA-F]{2}/, // Hex escapes
        /[0-7]{1,3}/ // Octal escapes
      )
    ),


    //Datetime
    dateTimeValue: $ => seq(
      $.dateValue,
      'T',
      $.timeValue
    ),

    // Date component: YYYY-MM-DD
    timeValue: $ => seq(
      /(?:[01][0-9]|2[0-3])/,  // Hours: 00-23
      ':',
      /[0-5][0-9]/,            // Minutes: 00-59
      ':',
      /[0-5][0-9]/,            // Seconds: 00-59
    ),

    // Time component: HH:MM:SS
    dateValue: $ => seq(
      'D',
      /[0-9]{4}/,           // Year
      '-',
      /(?:0[1-9]|1[0-2])/,  // Month: 01-12
      '-',
      /(?:0[1-9]|[12][0-9]|3[01])/  // Day: 01-31
    ),


  }
});
