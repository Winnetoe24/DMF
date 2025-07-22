package builder

// Builder ist das Interface für die Verarbeitung eines Statements
type Builder interface {
	Build() interface{}
}

type StatementType int

const (
	CONTENT_STATEMENT    = iota
	IDENTIFIER_STATEMENT = iota
	BLOCK_STATEMENT      = iota
	OVERRIDE_STATEMENT   = iota
	LANGUAGE_STATEMENT   = iota
	CONSTANT_STATEMENT   = iota
)

// ParserControl wird zum Callback zum Parser genutzt
type ParserControl interface {
}

func CreateBuilder(
	preBuilder PreBuilder,
	parserControl ParserControl,
	statementType StatementType) Builder {
	switch statementType {

	default:
		return nil
	}
}
