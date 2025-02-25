package semantic_rules

import (
	"errors"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type checkReferenzen struct {
	*walkRule
}

func newCheckReferenzen(lookup *smodel.TypeLookUp) *checkReferenzen {
	referenzen := checkReferenzen{
		walkRule: &walkRule{
			lookup:   lookup,
			elements: make([]errElement.ErrorElement, 0),
		},
	}
	referenzen.iWalkRule = &referenzen
	return &referenzen
}

func (c *checkReferenzen) handleStruct(element *packages.StructElement, _ *packages.EntityElement) {
	for _, referenz := range element.Referenzen {
		typString := referenz.Typ.ToString()
		_, found := (*c.lookup)[typString]
		if !found {
			c.elements = append(c.elements, errElement.CreateErrorElementCxt(referenz.Node.Child(1), errors.New("Referenzierter Typ nicht gefunden!"), referenz.Node))
		}
	}

	for _, referenz := range element.MultiReferenzen {
		if referenz.Generics[0].ModelPath != nil {
			typString := referenz.Generics[0].ModelPath.ToString()
			_, found := (*c.lookup)[typString]
			if !found {
				c.elements = append(c.elements, errElement.CreateErrorElementCxt(referenz.Node.Child(1), errors.New("Referenzierter Typ nicht gefunden!"), referenz.Node))
			}
		}

		if referenz.Generics[1].ModelPath != nil {
			typString := referenz.Generics[1].ModelPath.ToString()
			_, found := (*c.lookup)[typString]
			if !found {
				c.elements = append(c.elements, errElement.CreateErrorElementCxt(referenz.Node.Child(1), errors.New("Referenzierter Typ nicht gefunden!"), referenz.Node))
			}
		}
	}

	for _, funktion := range element.Funktionen {
		for _, variable := range funktion.Parameter {
			variablePath, _, _ := variable.GetVariableType()
			if variablePath != nil {
				variableString := variablePath.ToString()
				_, found := (*c.lookup)[variableString]
				if !found {
					referenz := variable.(*packages.Referenz)
					c.elements = append(c.elements, errElement.CreateErrorElementCxt(referenz.Node.Child(1), errors.New("Referenzierter Typ des Parameter nicht gefunden!"), referenz.Node))
				}
			}
		}
		returnType := funktion.ReturnType
		variablePath, _, _ := returnType.GetVariableType()
		if variablePath != nil {
			variableString := variablePath.ToString()
			_, found := (*c.lookup)[variableString]
			if !found {
				referenz := returnType.(*packages.Referenz)
				c.elements = append(c.elements, errElement.CreateErrorElementCxt(referenz.Node.Child(1), errors.New("Referenzierter Typ des Return Typs nicht gefunden!"), referenz.Node))
			}
		}
	}
}

func (c *checkReferenzen) handleInterface(element *packages.InterfaceElement) {
	for _, funktion := range element.Funktionen {
		for _, variable := range funktion.Parameter {
			variablePath, _, _ := variable.GetVariableType()
			if variablePath != nil {
				variableString := variablePath.ToString()
				_, found := (*c.lookup)[variableString]
				if !found {
					referenz := variable.(*packages.Referenz)
					c.elements = append(c.elements, errElement.CreateErrorElementCxt(referenz.Node, errors.New("Referenzierter Typ des Parameter nicht gefunden!"), funktion.Node))
				}
			}
		}
		returnType := funktion.ReturnType
		variablePath, _, _ := returnType.GetVariableType()
		if variablePath != nil {
			variableString := variablePath.ToString()
			_, found := (*c.lookup)[variableString]
			if !found {
				referenz := returnType.(*packages.Referenz)
				c.elements = append(c.elements, errElement.CreateErrorElementCxt(referenz.Node.Child(1), errors.New("Referenzierter Typ des Return Typs nicht gefunden!"), referenz.Node))
			}
		}
	}
}
