package hibernate

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"

func hibernateType(primitivType base.PrimitivType) string {
	switch primitivType {
	case base.INT:
		return "integer"
	case base.LONG:
		return "long"
	case base.DOUBLE:
		return "double"
	case base.BYTE:
		return "byte"
	case base.BOOLEAN:
		return "boolean"
	case base.STRING:
		return "string"
	case base.DATE:
		return "date"
	case base.DATETIME:
		return "timestamp"
	}
	return "string"
}

func hibernateJavaType(primitivType base.PrimitivType) string {
	switch primitivType {
	case base.INT:
		return "int"
	case base.LONG:
		return "long"
	case base.DOUBLE:
		return "double"
	case base.BYTE:
		return "byte"
	case base.BOOLEAN:
		return "boolean"
	case base.STRING:
		return "String"
	case base.DATE:
		return "LocalDate"
	case base.DATETIME:
		return "LocalDateTime"
	}
	return "String"
}

func idGenerator(primitivType base.PrimitivType) string {
	switch primitivType {
	case base.INT, base.LONG, base.DOUBLE, base.BYTE:
		return "native"
	default:
		return "assigned"
	}
}
