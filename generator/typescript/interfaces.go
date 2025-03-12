package typescript

import (
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type TsInterface struct {
	packages.InterfaceElement
	ImportKontext gbase.ImportKontext
}

func createTsInterface(element *packages.InterfaceElement, importKontext gbase.ImportKontext) TsInterface {
	return TsInterface{
		InterfaceElement: *element,
		ImportKontext:    importKontext,
	}
}
