package gbase

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"slices"
)

type DelegateElement struct {
	base.PackageElement
	ExtendsNamedElements *map[string]base.NamedElement
	Caller               base.ModelPath
}

func CreateDelegate(pElement packages.PackageElement) *DelegateElement {
	kommentar := []string{"Delegate von ", "Wird nur initial generiert.\n\n", "Methoden müssen implementiert werden.\n\n"}

	switch element := pElement.(type) {
	case *packages.EntityElement:
		kommentar[0] += element.StructElement.Identifier.Name
		var eNamedElements *map[string]base.NamedElement
		if element.Extends != nil {
			eNamedElements = &element.Extends.GetBase().NamedElements
		}
		return &DelegateElement{
			Caller: slices.Clone(element.Path),
			PackageElement: base.PackageElement{
				ModelElement: base.ModelElement{
					Kommentar: (*base.Comment)(&kommentar),
				},
				Path: CreateDelegatePath(element.Path),
				Identifier: base.ElementIdentifier{
					Name: element.StructElement.Identifier.Name + "Delegate\n\n",
				},
				NamedElements: element.NamedElements,
				Expand:        element.Expand,
			},
			ExtendsNamedElements: eNamedElements,
		}
	case *packages.StructElement:
		kommentar[0] += element.Identifier.Name
		var eNamedElements *map[string]base.NamedElement
		if element.Extends != nil {
			eNamedElements = &element.Extends.GetBase().NamedElements
		}
		return &DelegateElement{
			Caller: slices.Clone(element.Path),
			PackageElement: base.PackageElement{
				ModelElement: base.ModelElement{
					Kommentar: (*base.Comment)(&kommentar),
				},
				Path: CreateDelegatePath(element.Path),
				Identifier: base.ElementIdentifier{
					Name: element.Identifier.Name + "Delegate",
				},
				NamedElements: element.NamedElements,
				Expand:        element.Expand,
			},
			ExtendsNamedElements: eNamedElements,
		}
	case *packages.InterfaceElement:
		kommentar[0] += element.Identifier.Name
		return &DelegateElement{
			Caller: slices.Clone(element.Path),
			PackageElement: base.PackageElement{
				ModelElement: base.ModelElement{
					Kommentar: (*base.Comment)(&kommentar),
				},
				Path: CreateDelegatePath(element.Path),
				Identifier: base.ElementIdentifier{

					Name: element.Identifier.Name + "Delegate",
				},
				NamedElements: element.NamedElements,
				Expand:        element.Expand,
			},
		}
	}
	return nil
}

func CreateDelegatePath(path base.ModelPath) base.ModelPath {
	return append(path[:len(path)-1], path[len(path)-1]+"Delegate")
}
func CreateDelegateInterfacePath(path base.ModelPath) base.ModelPath {
	return append(path[:len(path)-1], "I"+path[len(path)-1]+"Delegate")
}

func (d *DelegateElement) CreateDelegateFunktion(funktion packages.Funktion) packages.Funktion {
	ref := packages.Referenz{
		ModelElement: base.ModelElement{},
		Typ:          d.Caller,
		Name: base.ElementIdentifier{
			ModelElement: base.ModelElement{},
			Name:         "caller",
		},
	}
	return packages.Funktion{
		ModelElement: funktion.ModelElement,
		Name:         funktion.Name,
		ReturnType:   funktion.ReturnType,
		Parameter:    append([]packages.Variable{&ref}, funktion.Parameter...),
	}
}
