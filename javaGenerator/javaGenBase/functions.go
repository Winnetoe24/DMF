package javaGenBase

import (
	"fmt"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"
	"slices"
	"strconv"
	"strings"
)

func packagePath(path base.ModelPath) string {
	return strings.Join(path[:len(path)-1], ".")
}

func toUpperCase(name string) string {
	return strings.ToUpper(name)
}

func variableName(variable packages.Variable) string {
	switch element := variable.(type) {
	case *packages.Argument:
		return element.Name.Name
	case *packages.Referenz:
		return element.Name.Name
	default:
		return ""
	}
}
func removeNewLine(input string) string {
	return strings.TrimSuffix(input, "\n")
}
func variableType(variable packages.Variable) string {
	switch element := variable.(type) {
	case *packages.Argument:
		return javaPrimitiveTypeMapping(element.Typ)
	case *packages.Referenz:
		return element.Typ.ToString()
	case packages.VoidElement:
		return "void"
	default:
		return ""
	}
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
			return "null"
		case base.BOOLEAN:
			return "false"
		case base.BYTE:
			return "0x0"
		case base.DOUBLE:
			return "0d"
		case base.INT:
			return "0"
		case base.LONG:
			return "0L"
		default:
			return ""
		}
	case *packages.Referenz:
		return "null"
	default:
		return ""
	}
}
func toArgs(argumente []packages.Argument) []FieldData {
	return toFields(argumente, make([]packages.Referenz, 0))
}
func toFields(argumente []packages.Argument, referenzen []packages.Referenz) []FieldData {
	data := make([]FieldData, 0)
	lookup := make(map[uint]packages.Variable)
	keys := make([]uint, 0, len(argumente)+len(referenzen))
	for _, argument := range argumente {
		startByte := argument.Node.StartByte()
		_, found := lookup[startByte]
		if found {
			position := argument.Node.StartPosition()
			panic("Duplicate Elements at Pos: " + strconv.FormatUint(uint64(position.Row), 10) + ":" + strconv.FormatUint(uint64(position.Column), 10))
		}
		keys = append(keys, startByte)
		lookup[startByte] = &argument
	}
	for _, referenz := range referenzen {
		startByte := referenz.Node.StartByte()
		_, found := lookup[startByte]
		if found {
			position := referenz.Node.StartPosition()
			panic("Duplicate Elements at Pos: " + strconv.FormatUint(uint64(position.Row), 10) + ":" + strconv.FormatUint(uint64(position.Column), 10))
		}
		keys = append(keys, startByte)
		lookup[startByte] = &referenz
	}
	slices.Sort(keys)
	for _, key := range keys {
		variable := lookup[key]
		switch element := variable.(type) {
		case *packages.Argument:
			typ := javaPrimitiveTypeMapping(element.Typ)
			data = append(data, FieldData{
				Typ:       typ,
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
			})
		case *packages.Referenz:
			data = append(data, FieldData{
				Typ:       element.Typ.ToString(),
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
			})
		}
	}
	return data
}

func javaPrimitiveTypeMapping(primitivType base.PrimitivType) string {
	typ := string(primitivType)
	switch typ {
	case string(base.STRING):
		typ = "String"
	case string(base.DATE):
		typ = "java.time.LocalDate"
	case string(base.DATETIME):
		typ = "java.time.LocalDateTime"
	}
	return typ
}

func toConstructor(packageElement packages.PackageElement) KonstruktorData {
	data := KonstruktorData{
		Name:      packageElement.GetBase().Path[len(packageElement.GetBase().Path)-1],
		Parameter: nil,
	}
	lookup := make(map[uint]packages.Variable)
	keys := make([]uint, 0)
	switch element := packageElement.(type) {
	case *packages.EntityElement:
		for _, argument := range element.Argumente {
			startByte := argument.Node.StartByte()
			_, found := lookup[startByte]
			if found {
				position := argument.Node.StartPosition()
				panic("Duplicate Elements at Pos: " + strconv.FormatUint(uint64(position.Row), 10) + ":" + strconv.FormatUint(uint64(position.Column), 10))
			}
			keys = append(keys, startByte)
			lookup[startByte] = &argument
		}
		for _, referenz := range element.Referenzen {
			startByte := referenz.Node.StartByte()
			_, found := lookup[startByte]
			if found {
				position := referenz.Node.StartPosition()
				panic("Duplicate Elements at Pos: " + strconv.FormatUint(uint64(position.Row), 10) + ":" + strconv.FormatUint(uint64(position.Column), 10))
			}
			keys = append(keys, startByte)
			lookup[startByte] = &referenz
		}
	case *packages.StructElement:
		for _, argument := range element.Argumente {
			startByte := argument.Node.StartByte()
			_, found := lookup[startByte]
			if found {
				position := argument.Node.StartPosition()
				panic("Duplicate Elements at Pos: " + strconv.FormatUint(uint64(position.Row), 10) + ":" + strconv.FormatUint(uint64(position.Column), 10))
			}
			keys = append(keys, startByte)
			lookup[startByte] = &argument
		}
		for _, referenz := range element.Referenzen {
			startByte := referenz.Node.StartByte()
			_, found := lookup[startByte]
			if found {
				position := referenz.Node.StartPosition()
				panic("Duplicate Elements at Pos: " + strconv.FormatUint(uint64(position.Row), 10) + ":" + strconv.FormatUint(uint64(position.Column), 10))
			}
			keys = append(keys, startByte)
			lookup[startByte] = &referenz
		}
	case *packages.EnumElement:
		for _, argument := range element.Argumente {
			startByte := argument.Node.StartByte()
			_, found := lookup[startByte]
			if found {
				position := argument.Node.StartPosition()
				panic("Duplicate Elements at Pos: " + strconv.FormatUint(uint64(position.Row), 10) + ":" + strconv.FormatUint(uint64(position.Column), 10))
			}
			keys = append(keys, startByte)
			lookup[startByte] = &argument
		}
	}
	data.Parameter = make([]packages.Variable, len(keys))
	for i, key := range keys {
		data.Parameter[i] = lookup[key]
	}
	return data
}

func valueInit(value values.Value) string {
	switch value := value.(type) {
	case values.IntValue:
		return strconv.FormatInt(int64(value.Value), 10)
	case values.LongValue:
		return value.Value.String() + "L"
	case values.BooleanValue:
		if value.Value {
			return "true"
		} else {
			return "false"
		}
	case values.DoubleValue:
		return fmt.Sprintf("%g", value.Value) + "d"
	case values.StringValue:
		return "\"" + "TODO" + "\"" // TODO Fix String Value
	case values.DateValue:
		return fmt.Sprintf("java.time.LocalDate.of(%v, %v, %v)", value.Value.Year(), int(value.Value.Month()), value.Value.Day())
	case values.DateTimeValue:
		return fmt.Sprintf("java.time.LocalDateTime.of(%v, %v, %v, %v, %v, %v, %v)", value.Value.Year(), int(value.Value.Month()), value.Value.Day(), value.Value.Hour(), value.Value.Month(), value.Value.Second(), value.Value.Nanosecond())
	default:
		return "null"
	}
}
