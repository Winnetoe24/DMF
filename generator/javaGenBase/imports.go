package javaGenBase

import (
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

func getImports(kontext gbase.ImportKontext) []string {

	basePath := kontext.Path[:len(kontext.Path)-1]
	imports := make([]string, 0)
	for _, lImport := range kontext.ImportLookUp {
		// Ignore Element in same Package
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
	funktionKontext := gbase.CreateFunktionKontext(funktion, kontext)
	funktionKontext.UseDelegate = false
	return funktionKontext
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
