package typescript

import (
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"slices"
)

func createTsImportKontext(pElement packages.PackageElement) gbase.ImportKontext {
	return gbase.CreateImportKontext(pElement, handleTsGenericTypeImport, handleTsArgumentImport)
}

func handleTsArgumentImport(up *gbase.ImportLookUp, argument packages.Argument) {

}
func handleTsGenericTypeImport(handleImport func(path base.ModelPath), typ packages.MultiReferenzType) {

}

// TsImport is a Map from relative file Path to the imported Elements
type TsImport map[string][]string

func getImports(kontext gbase.ImportKontext) TsImport {
	imports := make(TsImport)
	for _, lImport := range kontext.ImportLookUp {
		if lImport.OriginalName.ToString() == kontext.Path.ToString() {
			continue
		}
		relativeFilePath := pathToRelativeFilePath(lImport.OriginalName, kontext.Path)
		names, found := imports[relativeFilePath]
		elementName := lImport.OriginalName[len(lImport.OriginalName)-1]
		if !found {
			imports[relativeFilePath] = []string{elementName}
		} else {
			if !slices.Contains(names, relativeFilePath) {
				imports[relativeFilePath] = append(names, elementName)
			}
		}
	}
	return imports
}

func pathToRelativeFilePath(path base.ModelPath, kontextPath base.ModelPath) string {
	diffIndex := len(path)
	for i, element := range path {
		if len(kontextPath) <= i {
			//Import aus SubPackage
		} else if element != kontextPath[i] {
			diffIndex = i
			break
		}
	}

	pfad := ""
	for i := 0; i < len(kontextPath)-diffIndex-1; i++ {
		pfad += "../"
	}
	if pfad == "" {
		pfad = "./"
	}

	for i := diffIndex; i < len(path); i++ {
		pfad += path[i]
		if i != len(path)-1 {
			pfad += "/"
		} else {
			pfad += ".ts"
		}
	}

	return pfad
}
