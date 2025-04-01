package typescript

import (
	"fmt"
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"
	"strconv"
	"time"
)

func toTsFields(argumente []packages.Argument, referenzen []packages.Referenz, multiReferenzen []packages.MultiReferenz, kontext gbase.ImportKontext) []gbase.FieldData {
	return gbase.ToFields(argumente, referenzen, multiReferenzen, kontext, tsPrimitiveTypeMapping, buildGenericTsType, nil)
}

func toArgs(argumente []packages.Argument) []gbase.FieldData {
	return toTsFields(argumente, []packages.Referenz{}, []packages.MultiReferenz{}, gbase.ImportKontext{})
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

func variableType(variable packages.Variable, kontext gbase.ImportKontext) string {
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

func valueInit(value values.Value) string {
	switch value := value.(type) {
	case values.IntValue:
		return strconv.FormatInt(int64(value.Value), 10)
	case values.LongValue:
		return fmt.Sprintf("BigInt(%s)", value.Value.String())
	case values.BooleanValue:
		if value.Value {
			return "true"
		} else {
			return "false"
		}
	case values.DoubleValue:
		return fmt.Sprintf("%g", value.Value)
	case base.StringValue:
		return "\"" + value.Value + "\""
	case values.DateValue:
		return fmt.Sprintf("new Date('%s')", value.Value.Format(time.RFC3339))
	case values.DateTimeValue:
		return fmt.Sprintf("new Date('%s')", value.Value.Format(time.RFC3339))
	}
	return ""
}

func variableDefaultValue(variable packages.Variable) string {
	switch element := variable.(type) {
	case *packages.Argument:
		switch element.Typ {
		case base.STRING:
			return "\"\""
		case base.DATE:
			fallthrough
		case base.DATETIME:
			return "Date()"
		case base.BOOLEAN:
			return "false"
		case base.BYTE:
			return "0"
		case base.DOUBLE:
			return "0"
		case base.INT:
			return "0"
		case base.LONG:
			return "BigInt(0)"
		default:
			return ""
		}
	case *packages.Referenz:
		return "null"
	default:
		return ""
	}
}
