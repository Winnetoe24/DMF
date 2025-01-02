package javaGenBase

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

func createImportKontext(pElement packages.PackageElement) ImportKontext {
	var path base.ModelPath
	up := make(ImportLookUp)
	var basePath base.ModelPath
	switch element := pElement.(type) {
	case *packages.EntityElement:
		path = element.Path
		basePath = path[:len(path)-1]

		handleArgumente(&up, element.Argumente)
		for _, referenz := range element.Referenzen {
			handleImport(&up, basePath, referenz.Typ)
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

	return ImportKontext{
		ImportLookUp: up,
		Path:         path,
	}
}
func handleArgumente(up *ImportLookUp, argumente []packages.Argument) {
	for _, argument := range argumente {
		handleArgument(up, argument)
	}
}

func handleArgument(up *ImportLookUp, argument packages.Argument) {
	if argument.Typ == base.DATE {
		(*up)["LocalDate"] = Import{OriginalName: []string{"java", "time", "LocalDate"}}
	} else if argument.Typ == base.DATETIME {
		(*up)["LocalDateTime"] = Import{OriginalName: []string{"java", "time", "LocalDateTime"}}
	}
}
func handleFunktionen(up *ImportLookUp, basePath base.ModelPath, path base.ModelPath, funktionen []packages.Funktion) {
	for _, funktion := range funktionen {
		handleFunktion(up, basePath, funktion)
	}
}

func handleFunktion(up *ImportLookUp, basePath base.ModelPath, funktion packages.Funktion) {
	returnModelPath, _ := funktion.ReturnType.GetVariableType()
	if returnModelPath != nil {
		handleImport(up, basePath, *returnModelPath)
	}

	for _, variable := range funktion.Parameter {
		variablePath, _ := variable.GetVariableType()
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

func getImports(kontext ImportKontext) []string {

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

func getImportedName(up ImportLookUp, path base.ModelPath) string {
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

func createFunktionKontextOverride(funktion packages.Funktion, kontext ImportKontext) FunktionKontext {
	funktionKontext := createFunktionKontext(funktion, kontext)
	funktionKontext.Override = true
	return funktionKontext
}
func createFunktionKontext(funktion packages.Funktion, kontext ImportKontext) FunktionKontext {
	return FunktionKontext{
		Funktion:      funktion,
		ImportKontext: kontext,
	}
}

func createParameterKontext(variablen []packages.Variable, kontext ImportKontext) ParameterKontext {
	variableKontexts := make([]VariableKontext, len(variablen))
	for i, variable := range variablen {
		variableKontexts[i] = VariableKontext{
			Variable:      variable,
			ImportKontext: kontext,
		}
	}
	return ParameterKontext{
		Parameter:     variableKontexts,
		ImportKontext: kontext,
	}
}

func createVererbungKontext(extendsPath *base.ModelPath, implPaths []base.ModelPath, kontext ImportKontext) VererbungKontext {
	return VererbungKontext{
		ImportKontext:   kontext,
		ExtendsPath:     extendsPath,
		ImplementsPaths: implPaths,
	}
}
