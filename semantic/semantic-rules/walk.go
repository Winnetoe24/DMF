package semantic_rules

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type walkModelWithTypes interface {
	handleStruct(fileContent []byte, element *packages.StructElement, entity *packages.EntityElement)
	handleInterface(fileContent []byte, element *packages.InterfaceElement)
	handleEnumeration(fileContent []byte, element *packages.EnumElement)
	getErrorElements() []errElement.ErrorElement
	setTypeLookUp(ITypeLookUp)
}

type modelWithTypesWalker struct {
	handler []walkModelWithTypes
}

func (c *modelWithTypesWalker) SemanticRule(fileContent []byte, model *smodel.Model, extra ITypeLookUp) ([]errElement.ErrorElement, any) {
	for _, types := range c.handler {
		types.setTypeLookUp(extra)
	}
	for _, pack := range model.Packages {
		c.handlePackage(fileContent, &pack)
	}
	var errs []errElement.ErrorElement
	for _, types := range c.handler {
		errs = append(errs, types.getErrorElements()...)
	}
	return errs, nil
}

func (c *modelWithTypesWalker) handlePackage(fileContent []byte, pack *packages.Package) {
	for _, elem := range pack.Elements {
		switch elem.(type) {
		case *packages.Package:
			c.handlePackage(fileContent, elem.(*packages.Package))
		case *packages.StructElement:
			for _, handler := range c.handler {
				handler.handleStruct(fileContent, elem.(*packages.StructElement), nil)
			}
		case *packages.EntityElement:
			entityElement := elem.(*packages.EntityElement)
			for _, handler := range c.handler {
				handler.handleStruct(fileContent, &entityElement.StructElement, entityElement)
			}
		case *packages.InterfaceElement:
			for _, handler := range c.handler {
				handler.handleInterface(fileContent, elem.(*packages.InterfaceElement))
			}
		case *packages.EnumElement:
			for _, handler := range c.handler {
				handler.handleEnumeration(fileContent, elem.(*packages.EnumElement))
			}
		}
	}
}
