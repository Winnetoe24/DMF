package semantic_rules

import (
	"errors"
	sematic_model "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element2 "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type duplicatePathRule struct {
	finds TypeLookUp
	err   []err_element2.ErrorElement
}

var DuplicatePathError = errors.New("duplicate path error")

func (d *duplicatePathRule) SemanticRule(fileContent []byte, model *sematic_model.Model, _ *any) ([]err_element2.ErrorElement, TypeLookUp) {
	d.err = make([]err_element2.ErrorElement, 0)
	d.finds = make(TypeLookUp, 5)
	for _, pack := range model.Packages {
		d.handlePackage(fileContent, &pack)
	}
	return d.err, d.finds
}

func (d *duplicatePathRule) handlePackage(fileContent []byte, pack *packages.Package) {
	d.handleElement(fileContent, pack)

	for _, elem := range pack.Elements {
		switch elem.(type) {
		case *packages.Package:
			d.handlePackage(fileContent, elem.(*packages.Package))
		default:
			d.handleBaseElement(fileContent, elem)
		}
	}
}

func (d *duplicatePathRule) handleBaseElement(fileContent []byte, element packages.PackageElement) {
	d.handleElement(fileContent, element)
}

func (d *duplicatePathRule) handleElement(fileContent []byte, ePE packages.PackageElement) {
	path := ePE.GetBase().Path.ToString()
	packageElement, found := d.finds[path]
	if found {
		node := packageElement.GetBase().Node
		eNode := ePE.GetBase().Node
		d.err = append(d.err,
			err_element2.CreateErrorElementCause(fileContent, node, DuplicatePathError, eNode),
			err_element2.CreateErrorElementCause(fileContent, eNode, DuplicatePathError, node))
	} else {
		d.finds[path] = ePE
	}
}
