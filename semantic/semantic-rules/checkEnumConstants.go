package semantic_rules

import (
	"errors"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"

	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
)

type checkEnumConstants struct {
	*walkRule
}

func newCheckEnumConstants(lookup *smodel.TypeLookUp) *checkEnumConstants {
	constants := checkEnumConstants{
		walkRule: &walkRule{
			lookup:   lookup,
			elements: make([]errElement.ErrorElement, 0),
		},
	}
	constants.iWalkRule = &constants
	return &constants
}

func (c *checkEnumConstants) handleEnumeration(element *packages.EnumElement) {

	nameSet := make(map[string]packages.Konstante)
	indexSet := make(map[int]packages.Konstante)
	lastIndex := -1
	for _, konst := range element.Konstanten {
		duplikat, exists := nameSet[konst.Name.Name]
		if exists {
			c.elements = append(c.elements, errElement.CreateErrorElementFull(konst.Name.Node, errors.New("Konstanten-Namen doppelt vergeben!"), konst.Node, duplikat.Name.Node, duplikat.Node))
		} else {
			nameSet[konst.Name.Name] = konst
		}

		for i, value := range konst.Values {
			if i == 0 {
				if value.GetDataType() != base.INT {
					c.elements = append(c.elements, errElement.CreateErrorElement(element.Node, errors.New("eine Konstante muss als ersten Wert einen Integer für den Index beinhalten")))
				} else {
					intValue := value.(values.IntValue)
					if intValue.Ignored {
						lastIndex++
						intValue.Value = lastIndex
						konst.Values[i] = intValue
					} else {
						lastIndex = intValue.Value
					}

					duplikat, exists := indexSet[lastIndex]
					if exists {
						c.elements = append(c.elements, errElement.CreateErrorElementFull(intValue.Node, errors.New("Konstanten-Index doppelt vergeben!"), konst.Node, duplikat.Values[0].GetNode(), duplikat.Node))
					} else {
						indexSet[lastIndex] = konst
					}
				}
			} else {
				if len(element.Argumente) <= i-1 {
					c.elements = append(c.elements, errElement.CreateErrorElementCxt(value.GetNode(), errors.New("mehr Werte in der Konstante angegeben als im Enum definiert sind"), konst.Node))
				} else {
					argument := element.Argumente[i-1]
					_, primitivType, _ := argument.GetVariableType()
					if primitivType == nil || *primitivType != value.GetDataType() {
						c.elements = append(c.elements, errElement.CreateErrorElementFull(value.GetNode(), errors.New("der Datentyp stimmt nicht mit dem deklarierten Datentyp überein"), konst.Node, argument.Node, argument.Node))

					}
				}
			}

		}

	}
}
