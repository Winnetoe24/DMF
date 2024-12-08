package semantic_rules

import (
	"errors"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type checkEntityIdentifier struct {
	*walkRule
}

func newCheckEntityIdentifier(lookup *smodel.TypeLookUp) *checkEntityIdentifier {
	identifier := checkEntityIdentifier{
		walkRule: &walkRule{
			lookup:   lookup,
			elements: make([]errElement.ErrorElement, 0),
		},
	}
	identifier.iWalkRule = &identifier
	return &identifier
}

func (c *checkEntityIdentifier) handleStruct(_ *packages.StructElement, entity *packages.EntityElement) {
	if entity != nil {
		cEntity := *entity

		for _, variable := range cEntity.Identifier.Variablen {
			_, exists := cEntity.NamedElements[variable.Name]
			if !exists {
				c.elements = append(c.elements, errElement.CreateErrorElementCxt(variable.Node, errors.New("Referenzierte Variable nicht gefunden!"), cEntity.Identifier.Node))
			}
		}
	}
}
