package javaGenBase

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

func createImportKontext(path base.ModelPath, argumente []packages.Argument, referenzen []packages.Referenz, funktionen []packages.Funktion) ImportKontext {
	up := make(ImportLookUp)
	basePath := path[:len(path)-1]
	for _, argument := range argumente {
		if argument.Typ == base.DATE {
			up["LocalDate"] = Import{OriginalName: []string{"java", "time", "LocalDate"}}
		} else if argument.Typ == base.DATETIME {
			up["LocalDateTime"] = Import{OriginalName: []string{"java", "time", "LocalDateTime"}}
		}
	}
	for _, referenz := range referenzen {
		handleImport(&up, basePath, referenz.Typ)
	}
	for _, funktion := range funktionen {
		returnModelPath, _ := funktion.ReturnType.GetVariableType()
		if returnModelPath != nil {
			handleImport(&up, basePath, *returnModelPath)
		}

		for _, variable := range funktion.Parameter {
			variablePath, _ := variable.GetVariableType()
			if variablePath != nil {
				handleImport(&up, basePath, *variablePath)
			}
		}
	}
	return ImportKontext{
		ImportLookUp: up,
		Path:         path,
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
