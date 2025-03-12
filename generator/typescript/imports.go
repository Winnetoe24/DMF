package typescript

import (
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"slices"
)

func createTsImportKontext(pElement packages.PackageElement, hasDelegate bool) gbase.ImportKontext {
	kontext := gbase.CreateImportKontext(pElement, handleTsGenericTypeImport, handleTsArgumentImport)
	kontext.HasDelegate = hasDelegate
	return kontext
}

func handleTsArgumentImport(up *gbase.ImportLookUp, argument packages.Argument) {

}
func handleTsGenericTypeImport(handleImport func(path base.ModelPath), typ packages.MultiReferenzType) {

}

type TsImport struct {
	// Map from relative file Path to the imported Elements
	Map map[string][]string
	// Path to the File containing all Delegate Methods
	DelegatePath *string
}

func getImports(kontext gbase.ImportKontext) TsImport {
	imports := make(map[string][]string)
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
	var delegatePath *string = nil
	if kontext.HasDelegate {
		path := createDelegatePath(kontext.Path)
		delegatePath = &path
	}

	return TsImport{
		Map:          imports,
		DelegatePath: delegatePath,
	}
}

func createDelegatePath(path base.ModelPath) string {
	pfad := "delegates"
	for i := 0; i < len(path)-1; i++ {
		pfad = "../" + pfad + "/" + path[i]
	}

	pfad = pfad + "/"
	pfad += path[len(path)-1] + "Delegate"
	return pfad
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
		}
	}

	return pfad
}
