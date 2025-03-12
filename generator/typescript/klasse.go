package typescript

import (
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type TsKlasse struct {
	packages.EntityElement
	ImportKontext  gbase.ImportKontext
	PackageElement packages.PackageElement
}

func createTsKlasse(element packages.PackageElement, kontext gbase.ImportKontext) TsKlasse {
	klasse := TsKlasse{
		ImportKontext:  kontext,
		PackageElement: element,
	}
	switch element.(type) {
	case *packages.EntityElement:
		klasse.EntityElement = *element.(*packages.EntityElement)
	case *packages.StructElement:
		klasse.StructElement = *element.(*packages.StructElement)
	}
	return klasse
}
