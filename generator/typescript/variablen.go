package typescript

import (
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

func toTsFields(argumente []packages.Argument, referenzen []packages.Referenz, multiReferenzen []packages.MultiReferenz, kontext gbase.ImportKontext) []gbase.FieldData {
	return gbase.ToFields(argumente, referenzen, multiReferenzen, kontext, tsPrimitiveTypeMapping, buildGenericTsType)
}

func buildGenericTsType(element *packages.MultiReferenz, kontext gbase.ImportKontext) (typ string, value string) {
	genericType := func(multiType packages.MultiType, kontext gbase.ImportKontext) string {
		if multiType.PrimitivType != nil {
			return tsPrimitiveTypeMapping(*multiType.PrimitivType, kontext, true)
		}
		if multiType.ModelPath != nil {
			path := *multiType.ModelPath
			return gbase.PathType(path, kontext)
		}
		return ""
	}

	genericBlock := "<"
	generic0 := genericType(element.Generics[0], kontext)
	genericBlock += generic0
	generic1 := genericType(element.Generics[1], kontext)
	if generic1 != "" {
		genericBlock += ", "
		genericBlock += generic1
	}
	genericBlock += ">"

	switch element.Typ {
	case packages.MAP:
		typ = "Map" + genericBlock
		value = "new Map" + genericBlock + "()"
	case packages.SET:
		typ = "Set" + genericBlock
		value = "new Set" + genericBlock + "()"
	case packages.LIST:
		typ = generic0 + "[]"
		value = "[]"
	}
	return typ, value
}

func tsPrimitiveTypeMapping(primitivType base.PrimitivType, kontext gbase.ImportKontext, useObject bool) string {
	switch primitivType {
	case base.BYTE:
		fallthrough
	case base.INT:
		fallthrough
	case base.DOUBLE:
		return "number"

	case base.LONG:
		return "bigint"

	case base.BOOLEAN:
		return "boolean"

	case base.STRING:
		return "string"

	case base.DATE:
		fallthrough
	case base.DATETIME:
		return "Date"
	}
	return string(primitivType)
}

func variableType2(variable packages.Variable, kontext gbase.ImportKontext) string {
	switch element := variable.(type) {
	case *packages.Argument:
		return tsPrimitiveTypeMapping(element.Typ, kontext, false)
	case *packages.Referenz:
		return gbase.PathType(element.Typ, kontext)
	case packages.VoidElement:
		return "void"
	default:
		return ""
	}
}
