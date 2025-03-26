package gbase

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"slices"
	"strconv"
	"strings"
)

func ToFields(argumente []packages.Argument, referenzen []packages.Referenz, multiReferenzen []packages.MultiReferenz, kontext ImportKontext,
	primitiveTypeMapping func(base.PrimitivType, ImportKontext, bool) string,
	buildGenericType func(element *packages.MultiReferenz, kontext ImportKontext) (typ string, value string)) []FieldData {
	data := make([]FieldData, 0)
	lookup := make(map[uint]packages.Variable)
	keys := make([]uint, 0, len(argumente)+len(referenzen)+len(multiReferenzen))
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
			typ := primitiveTypeMapping(element.Typ, kontext, false)
			data = append(data, FieldData{
				Typ:       typ,
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
				Override:  element.Override,
			})

		case *packages.Referenz:
			data = append(data, FieldData{
				Typ:       PathType(element.Typ, kontext),
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
				Override:  element.Override,
			})
		case *packages.MultiReferenz:
			typ, value := buildGenericType(element, kontext)
			data = append(data, FieldData{
				Typ:       typ,
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
				Value:     &value,
				Override:  element.Override,
			})

		}
	}
	return data
}

//func ImportedName(name string, fullQualifiedName string, up ImportLookUp) string {
//	lImport, found := up[name]
//	if found && lImport.OriginalName.ToString() == fullQualifiedName {
//		return name
//	} else {
//		return fullQualifiedName
//	}
//}

// PathType returns the Type used in the current ImportKontext for the given base.ModelPath
func PathType(pPath base.ModelPath, kontext ImportKontext) string {
	name := pPath[len(pPath)-1]
	path, found := kontext.ImportLookUp[name]
	if found && path.OriginalName.ToString() == pPath.ToString() {
		return name
	}
	return pPath.ToString()
}

func CreateImportKontext(pElement packages.PackageElement,
	handleMultiReferenzImport func(handleImport func(path base.ModelPath), typ packages.MultiReferenzType),
	handleArgument func(*ImportLookUp, packages.Argument)) ImportKontext {
	var path base.ModelPath
	up := make(ImportLookUp)
	var basePath base.ModelPath
	switch element := pElement.(type) {
	case *packages.EntityElement:
		path = element.Path
		basePath = path[:len(path)-1]

		handleArgumente(&up, element.Argumente, handleArgument)
		for _, referenz := range element.Referenzen {
			handleImport(&up, basePath, referenz.Typ)
		}
		for _, referenz := range element.MultiReferenzen {
			handleMultiReferenz(&up, basePath, referenz, handleMultiReferenzImport)
		}
		handleFunktionen(&up, basePath, path, element.Funktionen)
		if element.ExtendsPath != nil {
			handleImport(&up, basePath, *element.ExtendsPath)
		}
		for _, implementsPath := range element.ImplementsPaths {
			handleImport(&up, basePath, implementsPath)
		}
	case *packages.StructElement:
		path = element.Path
		basePath = path[:len(path)-1]

		handleArgumente(&up, element.Argumente, handleArgument)
		for _, referenz := range element.Referenzen {
			handleImport(&up, basePath, referenz.Typ)
		}
		for _, referenz := range element.MultiReferenzen {
			handleMultiReferenz(&up, basePath, referenz, handleMultiReferenzImport)
		}
		handleFunktionen(&up, basePath, path, element.Funktionen)
		if element.ExtendsPath != nil {
			handleImport(&up, basePath, *element.ExtendsPath)
		}
		for _, implementsPath := range element.ImplementsPaths {
			handleImport(&up, basePath, implementsPath)
		}
	case *packages.EnumElement:
		path = element.Path
		basePath = path[:len(path)-1]

		handleArgumente(&up, element.Argumente, handleArgument)
	case *packages.InterfaceElement:
		path = element.Path
		basePath = path[:len(path)-1]
		handleFunktionen(&up, basePath, path, element.Funktionen)
		for _, implementsPath := range element.ImplementsPaths {
			handleImport(&up, basePath, implementsPath)
		}
	case *DelegateElement:
		path = element.Path
		basePath = path[:len(path)-1]
		for _, namedElement := range element.NamedElements {
			switch nElement := namedElement.(type) {
			case *packages.Funktion:
				handleFunktion(&up, basePath, *nElement)
			case *packages.Referenz:
				handleImport(&up, basePath, nElement.Typ)
			case *packages.Argument:
				handleArgument(&up, *nElement)
			}
		}
		handleImport(&up, basePath, element.Caller)
	}

	return ImportKontext{
		ImportLookUp: up,
		Path:         path,
	}
}
func handleArgumente(up *ImportLookUp, argumente []packages.Argument, handleArgument func(*ImportLookUp, packages.Argument)) {
	for _, argument := range argumente {
		handleArgument(up, argument)
	}
}

func handleMultiReferenz(up *ImportLookUp, basePath base.ModelPath, referenz packages.MultiReferenz, handleMultiReferenzImport func(handleImport func(path base.ModelPath), typ packages.MultiReferenzType)) {
	if referenz.Generics[0].ModelPath != nil {
		handleImport(up, basePath, *referenz.Generics[0].ModelPath)
	}
	if referenz.Generics[1].ModelPath != nil {
		handleImport(up, basePath, *referenz.Generics[1].ModelPath)
	}
	handleMultiReferenzImport(
		func(path base.ModelPath) {
			handleImport(up, basePath, path)
		},
		referenz.Typ,
	)
}
func handleFunktionen(up *ImportLookUp, basePath base.ModelPath, path base.ModelPath, funktionen []packages.Funktion) {
	for _, funktion := range funktionen {
		handleFunktion(up, basePath, funktion)
	}
}

func handleFunktion(up *ImportLookUp, basePath base.ModelPath, funktion packages.Funktion) {
	returnModelPath, _, _ := funktion.ReturnType.GetVariableType()
	if returnModelPath != nil {
		handleImport(up, basePath, *returnModelPath)
	}

	for _, variable := range funktion.Parameter {
		variablePath, _, _ := variable.GetVariableType()
		if variablePath != nil {
			handleImport(up, basePath, *variablePath)
		}
	}
}
func handleImport(up *ImportLookUp, basePath base.ModelPath, path base.ModelPath) {
	name := path[len(path)-1]
	_, found := (*up)[name]
	if !found || basePath.ToString() == path[:len(path)-1].ToString() {
		(*up)[name] = Import{
			OriginalName: path,
		}
	}
}

func PackagePath(path base.ModelPath) string {
	return strings.Join(path[:len(path)-1], ".")
}

func ToUpperCase(name string) string {
	return strings.ToUpper(name)
}

func Capitalize(name string) string {
	return strings.ToUpper(name[:1]) + name[1:]
}
func VariableName(variable packages.Variable) string {
	switch element := variable.(type) {
	case *packages.Argument:
		return element.Name.Name
	case *packages.Referenz:
		return element.Name.Name
	default:
		return ""
	}
}
func RemoveNewLine(input string) string {
	return strings.TrimSuffix(input, "\n")
}

func IsNotVoid(variable packages.Variable) bool {
	switch variable.(type) {
	case packages.VoidElement:
		return false
	}
	return true
}
func CreateFunktionKontext(funktion packages.Funktion, kontext ImportKontext) FunktionKontext {
	return FunktionKontext{
		Funktion:      funktion,
		ImportKontext: kontext,
		UseDelegate:   true,
	}
}

// Findet alle implementierten Funktionen
// Für Delegates wird der Caller als erster Parameter hinzugefügt
func FindImplementedFunctions(pElement packages.PackageElement) []packages.Funktion {
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
						funktionen = append(funktionen, element.CreateDelegateFunktion(*namedFunktion))
					}
				} else {
					funktionen = append(funktionen, element.CreateDelegateFunktion(*namedFunktion))
				}
			}
		}
	}
	return funktionen
}
