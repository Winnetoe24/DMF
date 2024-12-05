package semantic_rules

import (
	"errors"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"

	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
)

type checkEnumConstants struct {
	lookup TypeLookUp
	err    []errElement.ErrorElement
}

func (c *checkEnumConstants) getErrorElements() []errElement.ErrorElement {
	if c.err == nil {
		return make([]errElement.ErrorElement, 0)
	}
	return c.err
}

func (c *checkEnumConstants) setTypeLookUp(up ITypeLookUp) {
	c.lookup = up.getTypeLookUp()
}

func (c *checkEnumConstants) handleStruct([]byte, *packages.StructElement, *packages.EntityElement) {

}

func (c *checkEnumConstants) handleInterface([]byte, *packages.InterfaceElement) {

}

func (c *checkEnumConstants) handleEnumeration(fileContent []byte, element *packages.EnumElement) {

	nameSet := make(map[string]packages.Konstante)
	indexSet := make(map[int]packages.Konstante)
	lastIndex := -1
	for _, konst := range element.Konstanten {
		duplikat, exists := nameSet[konst.Name.Name]
		if exists {
			c.err = append(c.err, errElement.CreateErrorElementFull(fileContent, konst.Name.Node, errors.New("Konstanten-Namen doppelt vergeben!"), konst.Node, duplikat.Name.Node, duplikat.Node))
		} else {
			nameSet[konst.Name.Name] = konst
		}

		for i, value := range konst.Values {
			if i == 0 {
				if value.GetDataType() != base.INT {
					c.err = append(c.err, errElement.CreateErrorElement(fileContent, element.Node, errors.New("eine Konstante muss als ersten Wert einen Integer für den Index beinhalten")))
				} else {
					intValue := value.(values.IntValue)
					if intValue.Ignored {
						lastIndex++
					} else {
						lastIndex = intValue.Value
					}

					duplikat, exists := indexSet[lastIndex]
					if exists {
						c.err = append(c.err, errElement.CreateErrorElementFull(fileContent, intValue.Node, errors.New("Konstanten-Index doppelt vergeben!"), konst.Node, duplikat.Values[0].GetNode(), duplikat.Node))
					} else {
						indexSet[lastIndex] = konst
					}
				}
			} else {
				if len(element.Argumente) <= i-1 {
					c.err = append(c.err, errElement.CreateErrorElementCxt(fileContent, value.GetNode(), errors.New("mehr Werte in der Konstante angegeben als im Enum definiert sind"), konst.Node))
				} else {
					argument := element.Argumente[i-1]
					_, primitivType := argument.GetVariableType()
					if primitivType == nil || *primitivType != value.GetDataType() {
						c.err = append(c.err, errElement.CreateErrorElementFull(fileContent, value.GetNode(), errors.New("der Datentyp stimmt nicht mit dem deklarierten Datentyp überein"), konst.Node, argument.Node, argument.Node))

					}
				}
			}

		}

	}
}
