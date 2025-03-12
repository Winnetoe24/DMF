package typescript

import (
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type TsKlasse struct {
	packages.StructElement
	ImportKontext  gbase.ImportKontext
	PackageElement packages.PackageElement
}

func createTsKlasse(element packages.PackageElement, kontext gbase.ImportKontext) TsKlasse {
	klasse := TsKlasse{
		StructElement:  *element.(*packages.StructElement),
		ImportKontext:  kontext,
		PackageElement: element,
	}
	return klasse
}
