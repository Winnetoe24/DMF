package semantic_rules

import (
	"errors"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type duplicateElements struct {
	finds    TypeLookUp
	err      []err_element.ErrorElement
	finished map[string]bool
}

var _ semanticRule[TypeLookUp, any] = (*duplicateElements)(nil)

func (d *duplicateElements) SemanticRule(fileContent []byte, model *smodel.Model, extra TypeLookUp) ([]err_element.ErrorElement, any) {
	d.err = make([]err_element.ErrorElement, 0)
	d.finds = extra.getTypeLookUp()
	d.finished = make(map[string]bool, len(d.finds))
	for _, element := range d.finds {
		switch element.(type) {
		case *packages.StructElement:
			d.computeStruct(fileContent, element.(*packages.StructElement))
		case *packages.EntityElement:
			d.computeStruct(fileContent, &element.(*packages.EntityElement).StructElement)
		case *packages.EnumElement:
			d.computeEnum(fileContent, element.(*packages.EnumElement))
		case *packages.InterfaceElement:
			d.computeInterface(fileContent, element.(*packages.InterfaceElement))
		}
	}

	for _, element := range d.finds {
		d.handlePackageElement(fileContent, element)
	}
	return d.err, nil
}

func (d *duplicateElements) computeStruct(fileContent []byte, element *packages.StructElement) {
	if element.NamedElements != nil {
		return
	}
	element.NamedElements = make(map[string]base.NamedElement)

	for _, argument := range element.Argumente {
		d.addElement(fileContent, &element.NamedElements, &argument)
	}
	for _, referenz := range element.Referenzen {
		d.addElement(fileContent, &element.NamedElements, &referenz)
	}
	for _, funktion := range element.Funktionen {
		d.addElement(fileContent, &element.NamedElements, &funktion)
	}
	d.finds[element.GetPath().ToString()] = element
}
func (d *duplicateElements) computeInterface(fileContent []byte, element *packages.InterfaceElement) {
	if element.NamedElements != nil {
		return
	}
	element.NamedElements = make(map[string]base.NamedElement)

	for _, funktion := range element.Funktionen {
		d.addElement(fileContent, &element.NamedElements, &funktion)
	}
	d.finds[element.GetPath().ToString()] = element

}
func (d *duplicateElements) computeEnum(fileContent []byte, element *packages.EnumElement) {
	if element.NamedElements != nil {
		return
	}
	element.NamedElements = make(map[string]base.NamedElement)

	for _, argument := range element.Argumente {
		d.addElement(fileContent, &element.NamedElements, &argument)
	}
	for _, konstante := range element.Konstanten {
		d.addElement(fileContent, &element.NamedElements, &konstante)
	}
	d.finds[element.Path.ToString()] = element

}

func (d *duplicateElements) handlePackageElement(fileContent []byte, element packages.PackageElement) *map[string]base.NamedElement {
	_, found := d.finished[element.GetBase().Identifier.Name]

	switch element.(type) {
	case *packages.StructElement:
		structElement := element.(*packages.StructElement)
		if found {
			return &structElement.NamedElements
		}
		if structElement.Extends != nil {
			extendsElements := d.handlePackageElement(fileContent, structElement.Extends)
			d.addElements(fileContent, &structElement.NamedElements, extendsElements)
		}
		if structElement.Implements != nil {
			for _, implement := range structElement.Implements {
				implementElements := d.handlePackageElement(fileContent, implement)
				d.addElements(fileContent, &structElement.NamedElements, implementElements)
			}
		}
		d.finished[element.GetBase().Identifier.Name] = true
		return &structElement.NamedElements
	case *packages.EntityElement:
		entityElement := element.(*packages.EntityElement)
		if found {
			return &entityElement.NamedElements
		}
		if entityElement.Extends != nil {
			extendsElements := d.handlePackageElement(fileContent, entityElement.Extends)
			d.addElements(fileContent, &entityElement.NamedElements, extendsElements)
		}
		if entityElement.Implements != nil {
			for _, implement := range entityElement.Implements {
				implementElements := d.handlePackageElement(fileContent, implement)
				d.addElements(fileContent, &entityElement.NamedElements, implementElements)
			}
		}
		d.finished[entityElement.GetBase().Identifier.Name] = true
		return &entityElement.NamedElements
	case *packages.InterfaceElement:
		interfaceElement := element.(*packages.InterfaceElement)
		if found {
			return &interfaceElement.NamedElements
		}
		if interfaceElement.Implements != nil {
			for _, implement := range interfaceElement.Implements {
				implementElements := d.handlePackageElement(fileContent, implement)
				d.addElements(fileContent, &interfaceElement.NamedElements, implementElements)
			}
		}
		d.finished[interfaceElement.GetBase().Identifier.Name] = true
		return &interfaceElement.NamedElements
	}
	return nil
}

// Hilfsmethoden

func (d *duplicateElements) addElements(fileContent []byte, namedElements *map[string]base.NamedElement, add *map[string]base.NamedElement) {
	if add == nil {
		return
	}
	for _, element := range *add {
		d.addElement(fileContent, namedElements, element)
	}
}

func (d *duplicateElements) addElement(fileContent []byte, namedElements *map[string]base.NamedElement, element base.NamedElement) {
	name := element.GetName()
	ele, found := (*namedElements)[name]
	if found {
		d.err = append(d.err, err_element.CreateErrorElementCause(fileContent, element.Element().Node, errors.New("Name Doppelt Vergeben!"), ele.Element().Node))
	} else {
		(*namedElements)[name] = element
	}
}
