package javaGenBase

import (
	"fmt"
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"
	"strconv"
)

func variableType(variable packages.Variable, kontext gbase.ImportKontext) string {
	switch element := variable.(type) {
	case *packages.Argument:
		return javaPrimitiveTypeMapping(element.Typ, kontext, false)
	case *packages.Referenz:
		return gbase.PathType(element.Typ, kontext)
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

func toArgs(argumente []packages.Argument, kontext gbase.ImportKontext) []gbase.FieldData {
	return toJavaFields(argumente, make([]packages.Referenz, 0), make([]packages.MultiReferenz, 0), kontext)
}
func toJavaFields(argumente []packages.Argument, referenzen []packages.Referenz, multiReferenzen []packages.MultiReferenz, kontext gbase.ImportKontext) []gbase.FieldData {
	return gbase.ToFields(argumente, referenzen, multiReferenzen, kontext, javaPrimitiveTypeMapping, buildGenericJavaType)
}

var javaMapPath = base.ModelPath([]string{"java", "util", "Map"})
var javaHashMapPath = base.ModelPath([]string{"java", "util", "HashMap"})
var javaSetPath = base.ModelPath([]string{"java", "util", "Set"})
var javaHashSetPath = base.ModelPath([]string{"java", "util", "HashSet"})
var javaListPath = base.ModelPath([]string{"java", "util", "List"})
var javaArrayListPath = base.ModelPath([]string{"java", "util", "ArrayList"})

func buildGenericJavaType(element *packages.MultiReferenz, kontext gbase.ImportKontext) (typ string, value string) {
	genericType := func(multiType packages.MultiType, kontext gbase.ImportKontext) string {
		if multiType.PrimitivType != nil {
			return javaPrimitiveTypeMapping(*multiType.PrimitivType, kontext, true)
		}
		if multiType.ModelPath != nil {
			path := *multiType.ModelPath
			return gbase.PathType(path, kontext)
		}
		return ""
	}

	switch element.Typ {
	case packages.MAP:
		typ = gbase.PathType(javaMapPath, kontext)
		value = "new " + gbase.PathType(javaHashMapPath, kontext) + "<>()"
	case packages.SET:
		typ = gbase.PathType(javaSetPath, kontext)
		value = "new " + gbase.PathType(javaHashSetPath, kontext) + "<>()"
	case packages.LIST:
		typ = gbase.PathType(javaListPath, kontext)
		value = "new " + gbase.PathType(javaArrayListPath, kontext) + "<>()"
	}
	typ += "<"
	typ += genericType(element.Generics[0], kontext)

	generic1 := genericType(element.Generics[1], kontext)
	if generic1 != "" {
		typ += ", "
		typ += generic1
	}
	typ += ">"
	return typ, value
}

func createJavaImportKontext(pElement packages.PackageElement) gbase.ImportKontext {
	return gbase.CreateImportKontext(pElement, handleJavaGenericTypeImport, handleJavaArgumentImport)
}

func handleJavaArgumentImport(up *gbase.ImportLookUp, argument packages.Argument) {
	if argument.Typ == base.DATE {
		(*up)["LocalDate"] = gbase.Import{OriginalName: []string{"java", "time", "LocalDate"}}
	} else if argument.Typ == base.DATETIME {
		(*up)["LocalDateTime"] = gbase.Import{OriginalName: []string{"java", "time", "LocalDateTime"}}
	}
}
func handleJavaGenericTypeImport(handleImport func(path base.ModelPath), typ packages.MultiReferenzType) {
	switch typ {
	case packages.MAP:
		handleImport(base.ModelPath{"java", "util", "Map"})
		handleImport(base.ModelPath{"java", "util", "HashMap"})
	case packages.SET:
		handleImport(base.ModelPath{"java", "util", "Set"})
		handleImport(base.ModelPath{"java", "util", "HashSet"})
	case packages.LIST:
		handleImport(base.ModelPath{"java", "util", "List"})
		handleImport(base.ModelPath{"java", "util", "ArrayList"})

	}
}

func javaPrimitiveTypeMapping(primitivType base.PrimitivType, kontext gbase.ImportKontext, useObject bool) string {
	typ := string(primitivType)
	switch typ {
	case string(base.STRING):
		typ = "String"
	case string(base.DATE):
		lImport, found := kontext.ImportLookUp["LocalDate"]
		if found && lImport.OriginalName.ToString() == "java.time.LocalDate" {
			typ = "LocalDate"
		} else {
			typ = "java.time.LocalDate"
		}
	case string(base.DATETIME):
		lImport, found := kontext.ImportLookUp["LocalDateTime"]
		if found && lImport.OriginalName.ToString() == "java.time.LocalDateTime" {
			typ = "LocalDateTime"
		} else {
			typ = "java.time.LocalDateTime"
		}
	}
	if useObject {
		switch typ {
		case string(base.INT):
			typ = "Integer"
		case string(base.LONG):
			typ = "Long"
		case string(base.DOUBLE):
			typ = "Double"
		case string(base.BYTE):
			typ = "Byte"
		case string(base.BOOLEAN):
			typ = "Boolean"
		}
	}
	return typ
}

func toConstructor(packageElement packages.PackageElement, kontext gbase.ImportKontext) gbase.KonstruktorData {
	data := gbase.KonstruktorData{
		Name:          packageElement.GetBase().Path[len(packageElement.GetBase().Path)-1],
		Parameter:     nil,
		ImportKontext: kontext,
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
	data.Parameter = make([]gbase.VariableKontext, len(keys))
	for i, key := range keys {
		data.Parameter[i] = gbase.VariableKontext{
			Variable:      lookup[key],
			ImportKontext: kontext,
		}
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
	case base.StringValue:
		return "\"" + value.Value + "\""
	case values.DateValue:
		return fmt.Sprintf("java.time.LocalDate.of(%v, %v, %v)", value.Value.Year(), int(value.Value.Month()), value.Value.Day())
	case values.DateTimeValue:
		return fmt.Sprintf("java.time.LocalDateTime.of(%v, %v, %v, %v, %v, %v, %v)", value.Value.Year(), int(value.Value.Month()), value.Value.Day(), value.Value.Hour(), value.Value.Minute(), value.Value.Second(), value.Value.Nanosecond())
	default:
		return "null"
	}
}

func generateIdentifier(pElement packages.PackageElement) []gbase.FieldData {
	switch element := pElement.(type) {
	case *packages.EntityElement:
		data := make([]gbase.FieldData, len(element.EntityIdentifier.Variablen))
		for i, identifier := range element.EntityIdentifier.Variablen {
			data[i] = gbase.FieldData{
				Name: identifier.Name,
			}
		}
		return data
	case *packages.StructElement:
		data := make([]gbase.FieldData, 0)
		for name, namedElement := range element.NamedElements {
			switch namedElement.(type) {
			case *packages.Argument:
				data = append(data, gbase.FieldData{Name: name})
			case *packages.Referenz:

				data = append(data, gbase.FieldData{Name: name})
			}
		}
		return data
	}
	return nil
}
