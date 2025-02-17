package semantic_rules

import (
	"errors"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type computeElements struct {
	*walkRule
	finished map[string]bool
}

func newComputeElements(lookup *smodel.TypeLookUp) *computeElements {
	elements := computeElements{
		walkRule: newWalkRule(lookup),
		finished: make(map[string]bool, len(*lookup)),
	}
	elements.iWalkRule = &elements
	return &elements
}

func (c *computeElements) walk() []errElement.ErrorElement {
	c.walkRule.walk()

	for _, element := range *c.lookup {
		c.handleAbstraction(element)
	}

	return c.elements
}

func (c *computeElements) handleStruct(element *packages.StructElement, entity *packages.EntityElement) {

	if element.NamedElements != nil {
		return
	}
	element.NamedElements = make(map[string]base.NamedElement)

	for _, argument := range element.Argumente {
		c.addElement(&element.NamedElements, &argument)
	}
	for _, referenz := range element.Referenzen {
		c.addElement(&element.NamedElements, &referenz)
	}
	for _, referenz := range element.MultiReferenzen {
		c.addElement(&element.NamedElements, &referenz)
	}
	for _, funktion := range element.Funktionen {
		c.addElement(&element.NamedElements, &funktion)
	}
	if entity != nil {
		entity.StructElement = *element
		(*c.lookup)[element.GetPath().ToString()] = entity
	} else {
		(*c.lookup)[element.GetPath().ToString()] = element
	}
}

func (c *computeElements) handleInterface(element *packages.InterfaceElement) {
	if element.NamedElements != nil {
		return
	}
	element.NamedElements = make(map[string]base.NamedElement)

	for _, funktion := range element.Funktionen {
		c.addElement(&element.NamedElements, &funktion)
	}

	(*c.lookup)[element.GetPath().ToString()] = element

}
func (c *computeElements) handleEnumeration(element *packages.EnumElement) {
	if element.NamedElements != nil {
		return
	}
	element.NamedElements = make(map[string]base.NamedElement)

	for _, argument := range element.Argumente {
		c.addElement(&element.NamedElements, &argument)
	}
	for _, konstante := range element.Konstanten {
		c.addElement(&element.NamedElements, &konstante)
	}

	(*c.lookup)[element.Path.ToString()] = element
}

// Zweiter Durchlauf der Elemente. Verarbeitet Extends und Implements.
func (c *computeElements) handleAbstraction(pElement packages.PackageElement) *map[string]base.NamedElement {
	_, found := c.finished[pElement.GetBase().Identifier.Name]

	switch element := pElement.(type) {
	case *packages.EntityElement:
		if found {
			return &element.NamedElements
		}
		if element.Extends != nil {
			extendsElements := c.handleAbstraction(element.Extends)
			c.addElements(&element.NamedElements, extendsElements)
		}
		if element.Implements != nil {
			for _, implement := range element.Implements {
				implementElements := c.handleAbstraction(implement)
				c.addElements(&element.NamedElements, implementElements)
			}
		}
		c.finished[element.GetBase().Identifier.Name] = true
		return &element.NamedElements
	case *packages.StructElement:
		if found {
			return &element.NamedElements
		}
		if element.Extends != nil {
			extendsElements := c.handleAbstraction(element.Extends)
			c.addElements(&element.NamedElements, extendsElements)
		}
		if element.Implements != nil {
			for _, implement := range element.Implements {
				implementElements := c.handleAbstraction(implement)
				c.addElements(&element.NamedElements, implementElements)
			}
		}
		c.finished[pElement.GetBase().Identifier.Name] = true
		return &element.NamedElements

	case *packages.InterfaceElement:
		if found {
			return &element.NamedElements
		}
		if element.Implements != nil {
			for _, implement := range element.Implements {
				implementElements := c.handleAbstraction(implement)
				c.addElements(&element.NamedElements, implementElements)
			}
		}
		c.finished[element.GetBase().Identifier.Name] = true
		return &element.NamedElements
	}
	return nil
}

// Hilfsmethoden

func (c *computeElements) addElements(namedElements *map[string]base.NamedElement, add *map[string]base.NamedElement) {
	if add == nil {
		return
	}
	for _, element := range *add {
		c.addElement(namedElements, element)
	}
}

func (c *computeElements) addElement(namedElements *map[string]base.NamedElement, element base.NamedElement) {
	name := element.GetName()
	ele, found := (*namedElements)[name]
	if found {
		c.elements = append(c.elements, errElement.CreateErrorElementCause(element.Element().Node, errors.New("Name Doppelt Vergeben!"), ele.Element().Node))
	} else {
		(*namedElements)[name] = element
	}
}
