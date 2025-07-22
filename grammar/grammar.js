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
  ],

  // word: $ => $.identifier,
  rules: {

    source_file: $ => repeat(choice(
      $.statement,
    )),

    // Block

    block: $ => seq(
      '{',
      repeat(
        $.statement
      ),
      '}'
    ),

    overrideBlock: $ => seq(
      $.override,
      $.block,
    ),

    // Temp
    componentIdentifier: $ => choice(
      'componentIdentifier',
      $.reftype,
    ),
    parameter: $ => 'parameter',
    extendsStatement: $ => 'extends',
    implementsStatement: $ => 'implements',
    overrideKeyword: $ => 'overrideKeyword',

    // Statements
    statement: $ => seq(
      optional($.expand),
      choice(
        $.contentStatement,
        $.identifierStatement,
        $.blockStatement,
        $.overrideStatement,
      ),
      optional($.overrideBlock),
      $.statementEnd,
    ),

    contentStatement: $ => seq(
      $.statementKeyword,
      $.type,
      $.componentIdentifier,
      optional($.parameter),
    ),

    identifierStatement: $ => seq(
      $.identifier,
      $.parameter
    ),

    blockStatement: $ => seq(
      $.blockKeyword,
      $.componentName,
      optional($.extendsStatement),
      optional($.implementsStatement),
      optional($.overrideBlock),
      $.block,
    ),

    overrideStatement: $ => seq(
        $.overrideKeyword,
        token(":"),
        $.overrideContent,
    ),
    overrideContent: $ => choice(
      $.stringValue,
      $.reftype,
      $.decorator
    ),

    statementEnd: $ => seq(
      choice(
        token(';'),
        token(/;\n/),
        token(/\n/),
      )),

    // Types
    type: $ => choice(
      $.primitiveTypes,
      $.reftype,
      $.genericType,
    ),
    genericType: $ => seq(
      $.reftype,
      token.immediate("<"),
      $.reftype,
      repeat(seq(
        ",",
        $.reftype)),
      ">"
    ),
    reftype: $ => seq(
      $.refContent,
      repeat(choice(
        token.immediate("."),
        token.immediate(/([a-zA-Z_])+/)
        ))
    ),
    refContent: $ => choice(
      $.dot,
      $.componentName,
    ),

    componentName: $ => /([a-zA-Z_])+/,

    // Control
    semicolon: $ => ';',
    newLine: $ => /\n/,

    // Keywords
    blockKeyword: $ => choice(
      $.package,
      $.struct,
      $.enum,
      $.entity,
      $.interface,
    ),
    statementKeyword: $ => choice(
      $.arg,
      $.ref,
      $.func,
    ),

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
    override: $ => 'override',

    primitiveTypes: $ => choice(
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

    doubleValue: $ => prec(1, seq(
      $.integerValue,
      $.dot,
      $.integerValue
    )),

    decorator: $ => /@\w+/,

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
