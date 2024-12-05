package semantic_rules

import (
	"errors"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type checkEntityIdentifier struct {
	err []errElement.ErrorElement
}

func (c *checkEntityIdentifier) handleStruct(fileContent []byte, element *packages.StructElement, entity *packages.EntityElement) {
	if entity != nil {
		cEntity := *entity

		var varNamen = make(map[string]bool)
		c.calculateVariables(element, &varNamen)
		for _, variable := range cEntity.Identifier.Variablen {
			exists := varNamen[variable.Name]
			if !exists {
				c.err = append(c.err, errElement.CreateErrorElementCxt(fileContent, variable.Node, errors.New("Referenzierte Variable nicht gefunden!"), cEntity.Identifier.Node))
			}
		}
	}
}

func (c *checkEntityIdentifier) calculateVariables(element *packages.StructElement, varNamen *map[string]bool) {
	for _, arg := range element.Argumente {
		exists := (*varNamen)[arg.Name.Name]
		if exists {
			return
		}
		(*varNamen)[arg.Name.Name] = true
	}
	for _, ref := range element.Referenzen {
		exists := (*varNamen)[ref.Name.Name]
		if exists {
			return
		}
		(*varNamen)[ref.Name.Name] = true
	}
	if element.Extends != nil {
		c.calculateVariables(element.Extends.(*packages.StructElement), varNamen)
	}
}

func (c *checkEntityIdentifier) handleInterface(fileContent []byte, element *packages.InterfaceElement) {
	// Ignored
}

func (c *checkEntityIdentifier) handleEnumeration(fileContent []byte, element *packages.EnumElement) {
	//Ignored
}

func (c *checkEntityIdentifier) getErrorElements() []errElement.ErrorElement {
	return c.err
}

func (c *checkEntityIdentifier) setTypeLookUp(up ITypeLookUp) {}
