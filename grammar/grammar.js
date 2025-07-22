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
    // [$.reftype, $.package_string],
  ],

  // word: $ => $.identifier,
  rules: {

    source_file: $ => repeat(choice(
      $.statement,
      $.identifierStatement,
    )),

    // Block

    block: $ => seq(
      '{',
      repeat(choice(
        $.statement,
        $.identifierStatement
      )),
      '}'
    ),

    // Temp
    keyword: $ => 'keyword',
    componentIdentifier: $ => choice(
      'componentIdentifier',
      $.reftype,
    ),
    parameter: $ => 'parameter',
    overrideBlock: $ => 'overrideBlock',
    type: $ => 'type',
    extendsStatement: $ => 'extends',
    implementsStatement: $ => 'implements',

    // Statements
    statement: $ => seq(
      $.keyword,
      $.type,
      $.componentIdentifier,
      optional($.parameter),
      optional($.overrideBlock),
      prec(2, $.statementEnd),
    ),

    identifierStatement: $ => seq(
      $.identifier,
      optional($.overrideBlock),
      $.statementEnd,
    ),

    blockStatement: $ => seq(
      $.blockKeyword,
      $.componentName,
      optional($.extendsStatement),
      optional($.implementsStatement),
      optional($.overrideBlock),
      $.block,
    ),

    statementEndBuffer: $ => new RustRegex("[[:blank:]]+"),
    statementEnd: $ => seq(
      optional($.statementEndBuffer),
      choice(
        token.immediate(';'),
        token.immediate(/\n/),
      )),


    // Reftype
    reftype: $ => seq(
      repeat(choice(
        $.dot,
        $.componentName,
      )),
      $.componentName,
    ),

    // packageString: $ => prec.left(
    //   choice(
    //     $.componentName,
    //     seq(
    //       $.componentName,
    //       repeat1(
    //         seq(
    //           $.dot,
    //           $.componentName,
    //         )
    //       )
    //     ),
    //     seq(
    //       repeat1(
    //         seq(
    //           $.dot,
    //           $.componentName,
    //         )
    //       )
    //     )
    //   )),

    componentName: $ => 'cn',

    // Control
    semicolon: $ => ';',
    newLine: $ => /\n/,

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
    identifier: $ => 'identifier',

    types: $ => choice(
      $.byte,
      $.int,
      $.long,
      $.double,
      $.datetime,
      $.date,
      $.string,
      $.boolean,
      $.void,
    ),
    byte: $ => 'byte',
    int: $ => 'int',
    long: $ => 'long',
    double: $ => 'double',
    datetime: $ => 'datetime',
    date: $ => 'date',
    string: $ => 'string',
    boolean: $ => 'boolean',
    void: $ => 'void',



    number: $ => /[0-9]+/,
    dot: $ => token('.'),
    byte_content: $ => /[0-9A-F]{4}/,

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
        )), "content"),
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
