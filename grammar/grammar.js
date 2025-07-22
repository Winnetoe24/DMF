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
  conflicts: $ => [],

  // word: $ => $.identifier,
  rules: {

    source_file: $ => seq(
      $.dmfStatement,
      $.modelStatement,
      repeat(choice(
        $.statement,
    ))),

    dmfStatement: $ => seq(
      "dmf",
      $.versionNumber,
    ),

    modelStatement: $ => seq(
      "model",
      $.stringValue,
      "version",
      $.versionNumber,
    ),

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
    extendsStatement: $ => seq(
      $.extends,
      $.reftype
    ),
    implementsStatement: $ => seq(
      $.implements,
      $.reftype,
      repeat(seq(
        ",",
        $.reftype
      ))
    ),

    // Statements
    statement: $ => seq(
      optional($.comment),
      optional($.expand),
      choice(
        $.contentStatement,
        $.identifierStatement,
        $.blockStatement,
        $.overrideStatement,
        $.languageStatement,
        $.constantStatement,
      ),
      optional($.overrideBlock),
      $.statementEnd,
    ),

    contentStatement: $ => seq(
      $.statementKeyword,
      $.type,
      $.reftype,
      optional($.parameter),
    ),

    identifierStatement: $ => seq(
      $.identifier,
      $.parameter
    ),

    constantStatement: $ => seq(
      $.componentName,
      $.parameter,
    ),

    blockStatement: $ => seq(
      $.blockKeyword,
      $.reftype,
      optional($.extendsStatement),
      optional($.implementsStatement),
      optional($.overrideBlock),
      $.block,
    ),

    // Override

    overrideStatement: $ => seq(
      $.componentName,
      token(":"),
      $.overrideContent,
      repeat(seq(
        ",",
        $.overrideContent
      ))
    ),
    overrideContent: $ => choice(
      $.stringValue,
      $.reftype,
      $.decorator
    ),

    languageStatement: $ => seq(
      $.language,
      $.block,
    ),
    language: $ => choice(
      "java",
      "typescript",
      "ts"
    ),


    statementEnd: $ => seq(
      choice(
        token(';'),
        token(/;\n/),
        token(/\n/),
      )),

    // Comment
    comment: $ => prec.right(repeat1($.commentLine)),
    commentLine: $ => /\/\/.*\n/,


    //Parameter
    parameter: $ => seq(
      "(",
      optional(seq(
        $.parameterContent,
        repeat(
          seq(
            ",",
            $.parameterContent,
          )
        ),
      )),
      ")"
    ),
    parameterContent: $ => choice(
      $.value,
      $.componentName,
      seq(
        $.reftype,
        $.componentName,
      )
    ),

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
    byteContent: $ => /[0-9A-F]{4}/,

    //Value Tokens
    value: $ => choice(
      $.integerValue,
      $.longValue,
      $.booleanValue,
      $.byteValue,
      $.doubleValue,
      $.stringValue,
      $.dateTimeValue,
      $.dateValue,
    ),
    versionNumber: $ => seq(
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

    byteValue: $ => seq('0x', $.byteContent),

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
          $.stringContentDoubleQuote, // Any chars except quotes or backslash
          $.escapeSequence
        )), "content"),
        '"'
      ),
      // Single quoted string
      seq(
        "'",
        alias(repeat(choice(
          $.stringContentSingleQuote, // Any chars except quotes or backslash
          $.escapeSequence
        )), "content"),
        "'"
      )
    ),

    stringContentSingleQuote: $ => /[^'\\]+/,
    stringContentDoubleQuote: $ => /[^"\\]+/,

    // Common escape sequences
    escapeSequence: $ => seq(
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
