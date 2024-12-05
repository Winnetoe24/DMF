package semantic_rules

import (
	"errors"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"

	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
)

type checkSuperTypes struct {
	lookup     TypeLookUp
	nodeLookup TypeNodeLookup
	err        []errElement.ErrorElement
}

var _ walkModelWithTypes = (*checkSuperTypes)(nil)

func (c *checkSuperTypes) getErrorElements() []errElement.ErrorElement {
	if c.err == nil {
		return make([]errElement.ErrorElement, 0)
	}
	return c.err
}

func (c *checkSuperTypes) setTypeLookUp(up ITypeLookUp) {
	c.lookup = up.getTypeLookUp()
}

func (c *checkSuperTypes) handleStruct(fileContent []byte, element packages.StructElement, entity *packages.EntityElement) {
	if element.ExtendsPath != nil {
		extendsPath := element.ExtendsPath.ToString()
		extendsElement, found := c.lookup[extendsPath]
		if !found {
			c.err = append(c.err, errElement.CreateErrorElement(fileContent, element.Node, errors.New("Der Supertyp wurde nicht gefunden!")))
		} else {
			if extendsPath == element.Path.ToString() {
				c.err = append(c.err, errElement.CreateErrorElement(fileContent, element.Node, errors.New("Es sind keine Rekursiven ExtendsPath erlaubt!")))
			}
			switch extendsElement.(type) {
			case packages.EntityElement:
				if entity != nil {
					c.calculateTypeNode(fileContent, element, entity, make([]string, 0))
				} else {
					c.err = append(c.err, errElement.CreateErrorElementCause(fileContent, element.Node, errors.New("Der Supertyp ist eine Entity! Structs können nur von Structs erben."), extendsElement.GetBase().Node))
				}
			case packages.StructElement:
				c.calculateTypeNode(fileContent, element, entity, make([]string, 0))

			// Extra kein Fallthrough
			default:
				c.err = append(c.err, errElement.CreateErrorElementCause(fileContent, element.Node, errors.New("Der Supertyp ist kein struct oder entity!"), extendsElement.GetBase().Node))
			}
		}
	}
	c.handleImplements(fileContent, element.ImplementsPaths, element.PackageElement)
}

// Zum Top Down Durchlaufen des Typ-Baums
type topDownTypeNode struct {
	Name    string
	Parents []topDownTypeNode
}

func (c *checkSuperTypes) calculateTypeNode(fileContent []byte, current packages.StructElement, currentEntity *packages.EntityElement, subTypes []string) {
	if current.Extends != nil || (current.ExtendsPath == nil && len(current.ImplementsPaths) == 0) {
		return
	}

	currentPath := current.Path.ToString()
	rekursiv := false
	for _, subType := range subTypes {
		if subType == currentPath {
			c.err = append(c.err, errElement.CreateErrorElement(fileContent, current.Node, errors.New("Rekursive Vererbung!")))
			//println("Found", subType, node.Path)
			rekursiv = true
		}
	}

	if rekursiv {
		return
	}

	if current.ExtendsPath != nil && len(*current.ExtendsPath) > 0 && !rekursiv {
		extendsString := current.ExtendsPath.ToString()
		extendsElement, found := c.lookup[extendsString]
		if !found {
			//TODO err
		}

		if found {

			var entityElement *packages.EntityElement
			var structElement *packages.StructElement
			switch extendsElement.(type) {
			case packages.EntityElement:
				element := extendsElement.(packages.EntityElement)
				entityElement = &element
				if element.Extends == nil {
					c.calculateTypeNode(fileContent, entityElement.StructElement, entityElement, append(subTypes, currentPath))
				}

			case packages.StructElement:
				element := extendsElement.(packages.StructElement)
				structElement = &element
				if element.Extends == nil {
					c.calculateTypeNode(fileContent, *structElement, nil, append(subTypes, currentPath))
				}
			}
			if entityElement != nil {
				if currentEntity == nil {
					c.err = append(c.err, errElement.CreateErrorElement(fileContent, current.Node, errors.New("Ein Struct darf nur von einem Struct erben!")))
				} else {
					structElement = &entityElement.StructElement
				}
			}
			if structElement == nil {
				c.err = append(c.err, errElement.CreateErrorElement(fileContent, current.Node, errors.New("Der Supertyp muss ein Struct oder eine Entity sein!")))
			}

			current.Extends = extendsElement
		} else {
			c.err = append(c.err, errElement.CreateErrorElement(fileContent, current.Node, errors.New("Der Supertyp konnte nicht gefunden werden!")))
		}
	}
	c.lookup[currentPath] = current
}

func (c *checkSuperTypes) handleInterface(fileContent []byte, element packages.InterfaceElement) {
	c.handleImplements(fileContent, element.Implements, element.PackageElement)
}

func (c *checkSuperTypes) handleImplements(fileContent []byte, implements []base.ModelPath, element base.PackageElement) {
	if implements != nil {
		for _, implPath := range implements {
			if implPath == nil {
				continue
			}
			implString := implPath.ToString()
			implElement, found := c.lookup[implString]
			if !found {
				c.err = append(c.err, errElement.CreateErrorElement(fileContent, element.Node, errors.New("Das implementierte Interface wurde nicht gefunden!")))
			} else {
				_, ok := implElement.(packages.InterfaceElement)
				if !ok {
					c.err = append(c.err, errElement.CreateErrorElement(fileContent, element.Node, errors.New("Der Implementierte Typ ist kein Interface!")))
				} else {
					if implString == element.Path.ToString() {
						c.err = append(c.err, errElement.CreateErrorElement(fileContent, element.Node, errors.New("Ein Interface kann sich nicht selber implementieren!")))
					}
				}

			}
		}
	}
}

func (c *checkSuperTypes) handleEnumeration(_ []byte, _ packages.EnumElement) {

}
