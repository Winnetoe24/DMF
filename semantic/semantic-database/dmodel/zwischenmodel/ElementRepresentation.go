package zwischenmodel

import (
	"errors"
	"fmt"
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel/utils"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"slices"
)

type ElementRepresentation interface {
	GetPackageElement() packages.PackageElement
	GetIdentifiable() Identifiable
	GetAusgelagerteElemente() []*NamedElementWrapper
	TryFinish(kontext Kontext) (ElementRepresentation, error)
}

type Identifiable interface {
	GetIdentifier() []*dmodel.Column
}

type NamedElementWrapper struct {
	Element base.NamedElement
	State   ColumnState
	Columns []*dmodel.Column
}

type Kontext struct {
	Up                   smodel.TypeLookUp
	RepLookUp            *map[string]ElementRepresentation
	TableNameLookUp      map[string]string
	CallSet              []string
	ImplementationLookUp map[string][]packages.PackageElement
}

func (kontext Kontext) addCall(callName string) Kontext {
	kontext.CallSet = append(kontext.CallSet, callName)
	return kontext
}

type ColumnWrapper struct {
	Element base.NamedElement
	State   ColumnState
	Column  *dmodel.Column
}
type ColumnState int

const (
	NotReady    ColumnState = iota
	Ausgelagert ColumnState = iota
	Ready       ColumnState = iota
)

type UnfinishedElement struct {
	Element       packages.PackageElement
	ElementLookUp map[string]*NamedElementWrapper
}

func (u *UnfinishedElement) GetAusgelagerteElemente() []*NamedElementWrapper {
	wrappers := make([]*NamedElementWrapper, 0)
	for _, wrapper := range u.ElementLookUp {
		if wrapper != nil && wrapper.State == Ausgelagert {
			wrappers = append(wrappers, wrapper)
		}
	}
	return wrappers
}

func (u *UnfinishedElement) GetPackageElement() packages.PackageElement {
	return u.Element
}

func (u *UnfinishedElement) GetIdentifiable() Identifiable {
	return nil
}

func (u *UnfinishedElement) TryFinish(kontext Kontext) (ElementRepresentation, error) {
	if slices.Contains(kontext.CallSet, u.Element.GetBase().Path.ToString()) {
		return nil, errors.New("rekursive element")
	}

	//rep := *kontext.RepLookUp
	switch element := u.Element.(type) {
	case *packages.EnumElement:
		col := []*dmodel.Column{{
			Name:       "ID",
			Type:       base.INT,
			PrimaryKey: true,
			ForeignKey: nil,
			Kommentar:  "ID des Enums",
		}}
		return &ReadyElement{
			IdentifierReadyElement: IdentifierReadyElement{
				UnfinishedElement: *u,
				Identifier:        col,
			},
			Columns: col,
		}, nil
	case *packages.EntityElement:
		// Update NamedElements
		err := u.updateNamedElements(kontext, &element.StructElement)
		if err != nil {
			return nil, err
		}

		isReady, isIdentifiable := true, true
	IsReadyLoop:
		for name, wrapper := range u.ElementLookUp {
			if wrapper == nil || wrapper.State == NotReady {
				isReady = false
				for _, identifier := range element.EntityIdentifier.Variablen {
					if name == identifier.Name {
						isIdentifiable = false
						break IsReadyLoop
					}
				}
			}
		}
		if !isIdentifiable {
			return u, nil
		}
		//IdentifierReadyElement
		identifierReadyElement := IdentifierReadyElement{
			UnfinishedElement: *u,
			Identifier:        nil,
		}

		for _, identifier := range element.EntityIdentifier.Variablen {
			wrapper, found := u.ElementLookUp[identifier.Name]
			if !found {
				return nil, errors.New("Identifier not found: " + identifier.Name)
			}
			identifierReadyElement.Identifier = append(identifierReadyElement.Identifier, wrapper.Columns...)
		}

		if isReady {
			columns := make([]*dmodel.Column, 0)
			for _, wrapper := range u.ElementLookUp {
				columns = append(columns, wrapper.Columns...)
			}
			return &ReadyElement{
				IdentifierReadyElement: identifierReadyElement,
				Columns:                columns,
			}, nil
		}
	case *packages.StructElement:
		// Update NamedElements
		err := u.updateNamedElements(kontext, element)
		if err != nil {
			return nil, err
		}
		isReady := true
		for _, wrapper := range u.ElementLookUp {
			if wrapper.State == NotReady {
				isReady = false
				break
			}
		}
		if !isReady {
			return u, nil
		}
		columns := make([]*dmodel.Column, 0)
		for _, wrapper := range u.ElementLookUp {
			columns = append(columns, wrapper.Columns...)
		}
		return &ReadyElement{
			IdentifierReadyElement: IdentifierReadyElement{
				UnfinishedElement: *u,
				Identifier:        columns,
			},
			Columns: columns,
		}, nil
	case *packages.InterfaceElement:
		//TODO Implement Interface Tables
	}
	//TODO richtig?
	return u, nil
}

func (u *UnfinishedElement) updateNamedElements(kontext Kontext, element *packages.StructElement) error {
	for name, namedElement := range element.NamedElements {
		// Funktionen werden hier nicht beachtet, da sie nicht im Datenmodell vorkommen
		switch namedElement.(type) {
		case *packages.Funktion:
			continue
		}
		wrapper, found := u.ElementLookUp[name]
		if !found {
			// New Element
			switch element := namedElement.(type) {
			case *packages.Argument:
				wrapper = &NamedElementWrapper{
					Element: element,
					State:   Ready,
					Columns: []*dmodel.Column{{
						Name:      name,
						Type:      element.Typ,
						Kommentar: utils.ComputeComment(element.Kommentar),
					}},
				}
			case *packages.MultiReferenz:
				wrapper = &NamedElementWrapper{
					Element: element,
					State:   Ausgelagert,
					Columns: []*dmodel.Column{},
				}
			case *packages.Referenz:
				typ := element.Typ.ToString()
				switch kontext.Up[typ].(type) {
				case *packages.InterfaceElement:
					// Referenz zu Interface
					wrapper = &NamedElementWrapper{
						Element: element,
						State:   Ausgelagert,
						Columns: []*dmodel.Column{{
							Name:      name,
							Type:      base.INT,
							Kommentar: utils.ComputeComment(element.Kommentar),
							ForeignKey: &dmodel.ColumnReference{
								TableName: kontext.TableNameLookUp[typ],
								Column: &dmodel.Column{
									Name:       "ID",
									Type:       base.INT,
									PrimaryKey: true,
									ForeignKey: nil,
									Kommentar:  "Die ID für eine Instanz des Interfaces",
								},
							},
						}},
					}
				default:
					wrapper = &NamedElementWrapper{
						Element: element,
						State:   NotReady,
					}
					nWrapper, err := u.updateReferenz(kontext, element, wrapper)
					if err != nil {
						return err
					}
					wrapper = nWrapper
				}
			}
			if wrapper != nil {
				u.ElementLookUp[name] = wrapper
			}
		} else {
			// Update Element
			if wrapper.State == NotReady {
				switch element := wrapper.Element.(type) {
				case *packages.Referenz:
					wrapper, err := u.updateReferenz(kontext, element, wrapper)
					if err != nil {
						return err
					}
					u.ElementLookUp[name] = wrapper
				}
			}

		}
	}
	return nil
}

func (u *UnfinishedElement) updateReferenz(kontext Kontext,
	element *packages.Referenz,
	wrapper *NamedElementWrapper) (*NamedElementWrapper, error) {

	rep := *kontext.RepLookUp
	typ := element.Typ.ToString()
	isEntity := false
	switch kontext.Up[typ].(type) {
	case *packages.EntityElement:
		isEntity = true
	}
	representation, found := rep[typ]
	if !found {
		return nil, errors.New("No Representation found for: " + element.Typ.ToString())
	}
	identifiable := representation.GetIdentifiable()
	// Rekursive Call
	if identifiable == nil {

		finish, err := representation.TryFinish(kontext.addCall(u.Element.GetBase().Path.ToString()))
		if err != nil {
			fmt.Printf("Error while trying to finish element %s:%s\n", element.Typ.ToString(), err)
		} else {
			rep[typ] = finish
			representation = finish
			identifiable = representation.GetIdentifiable()
		}
	}
	// Element kann referenziert werden
	if identifiable != nil {
		identifier := identifiable.GetIdentifier()
		for _, column := range identifier {
			col := &dmodel.Column{
				Name:       element.Name.Name + column.Name,
				Type:       column.Type,
				PrimaryKey: false,
				ForeignKey: nil,
				Kommentar:  utils.ComputeComment(element.Kommentar),
			}
			if isEntity {
				col.ForeignKey = &dmodel.ColumnReference{
					TableName: kontext.TableNameLookUp[typ],
					Column:    column,
				}
			}
			wrapper.Columns = append(wrapper.Columns, col)
		}
		wrapper.State = Ready
	}
	return wrapper, nil
}
