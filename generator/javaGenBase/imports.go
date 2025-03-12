package javaGenBase

import (
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

func createImportKontext(pElement packages.PackageElement) gbase.ImportKontext {
	var path base.ModelPath
	up := make(gbase.ImportLookUp)
	var basePath base.ModelPath
	switch element := pElement.(type) {
	case *packages.EntityElement:
		path = element.Path
		basePath = path[:len(path)-1]

		handleArgumente(&up, element.Argumente)
		for _, referenz := range element.Referenzen {
			handleImport(&up, basePath, referenz.Typ)
		}
		for _, referenz := range element.MultiReferenzen {
			handleMultiReferenz(&up, basePath, referenz)
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

		handleArgumente(&up, element.Argumente)
		for _, referenz := range element.Referenzen {
			handleImport(&up, basePath, referenz.Typ)
		}
		for _, referenz := range element.MultiReferenzen {
			handleMultiReferenz(&up, basePath, referenz)
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

		handleArgumente(&up, element.Argumente)
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

	return gbase.ImportKontext{
		ImportLookUp: up,
		Path:         path,
	}
}

func handleArgumente(up *gbase.ImportLookUp, argumente []packages.Argument) {
	for _, argument := range argumente {
		handleArgument(up, argument)
	}
}
func handleArgument(up *gbase.ImportLookUp, argument packages.Argument) {
	if argument.Typ == base.DATE {
		(*up)["LocalDate"] = gbase.Import{OriginalName: []string{"java", "time", "LocalDate"}}
	} else if argument.Typ == base.DATETIME {
		(*up)["LocalDateTime"] = gbase.Import{OriginalName: []string{"java", "time", "LocalDateTime"}}
	}
}

func handleMultiReferenz(up *gbase.ImportLookUp, basePath base.ModelPath, referenz packages.MultiReferenz) {
	if referenz.Generics[0].ModelPath != nil {
		handleImport(up, basePath, *referenz.Generics[0].ModelPath)
	}
	if referenz.Generics[1].ModelPath != nil {
		handleImport(up, basePath, *referenz.Generics[1].ModelPath)
	}
	switch referenz.Typ {
	case packages.MAP:
		handleImport(up, basePath, base.ModelPath{"java", "util", "Map"})
		handleImport(up, basePath, base.ModelPath{"java", "util", "HashMap"})
	case packages.SET:
		handleImport(up, basePath, base.ModelPath{"java", "util", "Set"})
		handleImport(up, basePath, base.ModelPath{"java", "util", "HashSet"})
	case packages.LIST:
		handleImport(up, basePath, base.ModelPath{"java", "util", "List"})
		handleImport(up, basePath, base.ModelPath{"java", "util", "ArrayList"})

	}
}
func handleFunktionen(up *gbase.ImportLookUp, basePath base.ModelPath, path base.ModelPath, funktionen []packages.Funktion) {
	for _, funktion := range funktionen {
		handleFunktion(up, basePath, funktion)
	}
}

func handleFunktion(up *gbase.ImportLookUp, basePath base.ModelPath, funktion packages.Funktion) {
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
func handleImport(up *gbase.ImportLookUp, basePath base.ModelPath, path base.ModelPath) {
	name := path[len(path)-1]
	_, found := (*up)[name]
	if !found || basePath.ToString() == path[:len(path)-1].ToString() {
		(*up)[name] = gbase.Import{
			OriginalName: path,
		}
	}
}

func getImports(kontext gbase.ImportKontext) []string {

	basePath := kontext.Path[:len(kontext.Path)-1]
	imports := make([]string, 0)
	for _, lImport := range kontext.ImportLookUp {
		if basePath.ToString() == lImport.OriginalName[:len(lImport.OriginalName)-1].ToString() {
			continue
		}
		imports = append(imports, lImport.OriginalName.ToString())
	}
	//fmt.Printf("Imports: %v\n", imports)
	return imports
}

func getImportedName(up gbase.ImportLookUp, path base.ModelPath) string {
	name := path[len(path)-1]
	lImport, found := up[name]
	if !found {
		return path.ToString()
	}
	if lImport.OriginalName.ToString() == path.ToString() {
		return name
	}
	return path.ToString()
}

func createFunktionKontextDelegate(funktion packages.Funktion, kontext gbase.ImportKontext) gbase.FunktionKontext {
	funktionKontext := createFunktionKontext(funktion, kontext)
	funktionKontext.UseDelegate = false
	return funktionKontext
}
func createFunktionKontext(funktion packages.Funktion, kontext gbase.ImportKontext) gbase.FunktionKontext {
	return gbase.FunktionKontext{
		Funktion:      funktion,
		ImportKontext: kontext,
		UseDelegate:   true,
	}
}

func prependThis(variablen []packages.Variable) []packages.Variable {
	return append([]packages.Variable{&packages.Referenz{
		ModelElement: base.ModelElement{},
		Typ:          nil,
		Name: base.ElementIdentifier{
			ModelElement: base.ModelElement{},
			Name:         "this",
		},
	}}, variablen...)
}

func createParameterKontext(variablen []packages.Variable, kontext gbase.ImportKontext) gbase.ParameterKontext {
	variableKontexts := make([]gbase.VariableKontext, len(variablen))
	for i, variable := range variablen {
		variableKontexts[i] = gbase.VariableKontext{
			Variable:      variable,
			ImportKontext: kontext,
		}
	}
	return gbase.ParameterKontext{
		Parameter:     variableKontexts,
		ImportKontext: kontext,
	}
}

func createVererbungKontext(extendsPath *base.ModelPath, implPaths []base.ModelPath, kontext gbase.ImportKontext) gbase.VererbungKontext {
	return gbase.VererbungKontext{
		ImportKontext:   kontext,
		ExtendsPath:     extendsPath,
		ImplementsPaths: implPaths,
	}
}
func createVererbungKontextInterface(extendsPath *base.ModelPath, implPaths []base.ModelPath, kontext gbase.ImportKontext) gbase.VererbungKontext {
	return gbase.VererbungKontext{
		ImportKontext:   kontext,
		ExtendsPath:     extendsPath,
		ImplementsPaths: implPaths,
		Interface:       true,
	}
}
