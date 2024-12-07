package semantic_rules

import (
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type iWalkRule interface {
	// Verarbeitet ein StructElement. Ist das Struct Element auch eine Entity so wird auch die Entity übergeben.
	// Wird von walk aufgerufen und von den Regeln implementiert.
	handleStruct(element *packages.StructElement, entity *packages.EntityElement)

	// Verarbeitet ein InterfaceElement.
	// Wird von walk aufgerufen und von den Regeln implementiert.
	handleInterface(element *packages.InterfaceElement)

	// Verarbeitet ein EnumElement.
	// Wird von walk aufgerufen und von den Regeln implementiert.
	handleEnumeration(element *packages.EnumElement)

	// Siehe walkRule
	walk() []errElement.ErrorElement
}

// Supertyp alle Regeln, welche alle Typen durchlaufen.
type walkRule struct {
	lookup    *TypeLookUp
	elements  []errElement.ErrorElement
	iWalkRule iWalkRule
}

func newWalkRule(lookup *TypeLookUp) *walkRule {
	return &walkRule{
		lookup:    lookup,
		elements:  make([]errElement.ErrorElement, 0),
		iWalkRule: nil,
	}
}

var _ iWalkRule = &walkRule{}

// Verarbeitet ein StructElement. Ist das Struct Element auch eine Entity so wird auch die Entity übergeben.
// Wird von walk aufgerufen und von den Regeln implementiert.
func (w *walkRule) handleStruct(element *packages.StructElement, entity *packages.EntityElement) {}

// Verarbeitet ein InterfaceElement.
// Wird von walk aufgerufen und von den Regeln implementiert.
func (w *walkRule) handleInterface(element *packages.InterfaceElement) {}

// Verarbeitet ein EnumElement.
// Wird von walk aufgerufen und von den Regeln implementiert.
func (w *walkRule) handleEnumeration(element *packages.EnumElement) {}

// Durchläuft alle Typen im TypeLookUp und ruft die entsprechenden Regeln auf.
func (w *walkRule) walk() []errElement.ErrorElement {
	for _, element := range *w.lookup {
		switch element := element.(type) {
		case *packages.StructElement:
			w.iWalkRule.handleStruct(element, nil)
		case *packages.EntityElement:
			structElement := element.StructElement
			w.iWalkRule.handleStruct(&structElement, element)
		case *packages.InterfaceElement:
			w.iWalkRule.handleInterface(element)
		case *packages.EnumElement:
			w.iWalkRule.handleEnumeration(element)
		}
	}

	return w.elements

}
