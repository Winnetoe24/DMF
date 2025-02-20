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

func capitalize(name string) string {
	return strings.ToUpper(name[:1]) + name[1:]
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
func variableType(variable packages.Variable, kontext ImportKontext) string {
	switch element := variable.(type) {
	case *packages.Argument:
		return javaPrimitiveTypeMapping(element.Typ, kontext, false)
	case *packages.Referenz:
		name := element.Typ[len(element.Typ)-1]
		path, found := kontext.ImportLookUp[name]
		if found && path.OriginalName.ToString() == element.Typ.ToString() {
			return name
		}
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

func pathType(pPath base.ModelPath, kontext ImportKontext) string {
	name := pPath[len(pPath)-1]
	path, found := kontext.ImportLookUp[name]
	if found && path.OriginalName.ToString() == pPath.ToString() {
		return name
	}
	return pPath.ToString()
}
func toArgs(argumente []packages.Argument, kontext ImportKontext) []FieldData {
	return toFields(argumente, make([]packages.Referenz, 0), make([]packages.MultiReferenz, 0), kontext)
}
func toFields(argumente []packages.Argument, referenzen []packages.Referenz, multiReferenzen []packages.MultiReferenz, kontext ImportKontext) []FieldData {
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
	for _, referenz := range multiReferenzen {
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
			typ := javaPrimitiveTypeMapping(element.Typ, kontext, false)
			data = append(data, FieldData{
				Typ:       typ,
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
			})
		case *packages.Referenz:
			data = append(data, FieldData{
				Typ:       importedName(element.Typ[len(element.Typ)-1], element.Typ.ToString(), kontext.ImportLookUp),
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
			})
		case *packages.MultiReferenz:
			var typ string
			var value string
			switch element.Typ {
			case packages.MAP:
				typ = importedName("Map", "java.util.Map", kontext.ImportLookUp)
				value = "new " + importedName("HashMap", "java.util.HashMap", kontext.ImportLookUp) + "<>()"
			case packages.SET:
				typ = importedName("Set", "java.util.Set", kontext.ImportLookUp)
				value = "new " + importedName("HashSet", "java.util.HashSet", kontext.ImportLookUp) + "<>()"
			case packages.LIST:
				typ = importedName("List", "java.util.List", kontext.ImportLookUp)
				value = "new " + importedName("ArrayList", "java.util.ArrayList", kontext.ImportLookUp) + "<>()"
			}
			typ += "<"
			typ += genericType(element.Generics[0], kontext)

			generic1 := genericType(element.Generics[1], kontext)
			if generic1 != "" {
				typ += ", "
				typ += generic1
			}
			typ += ">"
			data = append(data, FieldData{
				Typ:       typ,
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
				Value:     &value,
			})

		}
	}
	return data
}
func genericType(multiType packages.MultiType, kontext ImportKontext) string {
	if multiType.PrimitivType != nil {
		return javaPrimitiveTypeMapping(*multiType.PrimitivType, kontext, true)
	}
	if multiType.ModelPath != nil {
		path := *multiType.ModelPath
		return importedName(path[len(path)-1], path.ToString(), kontext.ImportLookUp)
	}
	return ""
}

func importedName(name string, fullQualifiedName string, up ImportLookUp) string {
	lImport, found := up[name]
	if found && lImport.OriginalName.ToString() == fullQualifiedName {
		return name
	} else {
		return fullQualifiedName
	}
}

func javaPrimitiveTypeMapping(primitivType base.PrimitivType, kontext ImportKontext, useObject bool) string {
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

func toConstructor(packageElement packages.PackageElement, kontext ImportKontext) KonstruktorData {
	data := KonstruktorData{
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
	data.Parameter = make([]VariableKontext, len(keys))
	for i, key := range keys {
		data.Parameter[i] = VariableKontext{
			Variable:      lookup[key],
			ImportKontext: kontext,
		}
	}
	return data
}

// Findet alle implementierten Funktionen
// Für Delegates wird der Caller als erster Parameter hinzugefügt
func findImplementedFunctions(pElement packages.PackageElement) []packages.Funktion {
	funktionen := make([]packages.Funktion, 0)
	switch element := pElement.(type) {
	case *packages.EntityElement:
		for s, namedElement := range element.NamedElements {
			switch namedFunktion := namedElement.(type) {
			case *packages.Funktion:
				if element.Extends != nil {
					_, found := element.Extends.GetBase().NamedElements[s]
					if !found {
						funktionen = append(funktionen, *namedFunktion)
					}
				} else {
					funktionen = append(funktionen, *namedFunktion)
				}
			}
		}
	case *packages.StructElement:
		for s, namedElement := range element.NamedElements {
			switch namedFunktion := namedElement.(type) {
			case *packages.Funktion:
				if element.Extends != nil {
					_, found := element.Extends.GetBase().NamedElements[s]
					if !found {
						funktionen = append(funktionen, *namedFunktion)
					}
				} else {
					funktionen = append(funktionen, *namedFunktion)
				}
			}
		}
	case *DelegateElement:
		for s, namedElement := range element.NamedElements {
			switch namedFunktion := namedElement.(type) {
			case *packages.Funktion:
				if element.ExtendsNamedElements != nil {
					_, found := (*element.ExtendsNamedElements)[s]
					if !found {
						funktionen = append(funktionen, element.createDelegateFunktion(*namedFunktion))
					}
				} else {
					funktionen = append(funktionen, element.createDelegateFunktion(*namedFunktion))
				}
			}
		}
	}
	return funktionen
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

func generateIdentifier(pElement packages.PackageElement) []FieldData {
	switch element := pElement.(type) {
	case *packages.EntityElement:
		data := make([]FieldData, len(element.EntityIdentifier.Variablen))
		for i, identifier := range element.EntityIdentifier.Variablen {
			data[i] = FieldData{
				Name: identifier.Name,
			}
		}
		return data
	case *packages.StructElement:
		data := make([]FieldData, 0)
		for name, namedElement := range element.NamedElements {
			switch namedElement.(type) {
			case *packages.Argument:
				data = append(data, FieldData{Name: name})
			case *packages.Referenz:

				data = append(data, FieldData{Name: name})
			}
		}
		return data
	}
	return nil
}

func isNotVoid(variable packages.Variable) bool {
	switch variable.(type) {
	case packages.VoidElement:
		return false
	}
	return true
}
