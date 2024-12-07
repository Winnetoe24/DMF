package semantic_rules

import (
	"errors"
	sematic_model "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type fillTypeLookUp struct {
	finds TypeLookUp
	err   []err_element.ErrorElement
}

func newFillTypeLookUp() *fillTypeLookUp {
	return &fillTypeLookUp{finds: make(TypeLookUp, 10), err: make([]err_element.ErrorElement, 0)}
}

var DuplicatePathError = errors.New("duplicate path error")

func (d *fillTypeLookUp) Fill(model *sematic_model.Model) (TypeLookUp, []err_element.ErrorElement) {
	for _, pack := range model.Packages {
		d.handlePackage(&pack)
	}
	return d.finds, d.err
}

func (d *fillTypeLookUp) handlePackage(pack *packages.Package) {
	d.handleElement(pack)

	for _, elem := range pack.Elements {
		switch elem.(type) {
		case *packages.Package:
			d.handlePackage(elem.(*packages.Package))
		default:
			d.handleElement(elem)
		}
	}
}

func (d *fillTypeLookUp) handleElement(ePE packages.PackageElement) {
	path := ePE.GetBase().Path.ToString()
	packageElement, found := d.finds[path]
	if found {
		node := packageElement.GetBase().Node
		eNode := ePE.GetBase().Node
		d.err = append(d.err,
			err_element.CreateErrorElementCause(node, DuplicatePathError, eNode),
			err_element.CreateErrorElementCause(eNode, DuplicatePathError, node))
	} else {
		d.finds[path] = ePE
	}
}
