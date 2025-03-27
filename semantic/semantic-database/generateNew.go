package semantic_database

import (
	"fmt"
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
	zmodel "github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel/zwischenmodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
)

func GenerateSchemaNew(lookup smodel.TypeLookUp) (dmodel.Schema, []errElement.ErrorElement) {

	// Setup

	initialKontext := zmodel.Kontext{
		Up:                   lookup,
		RepLookUp:            createRepresentationLookUp(lookup),
		TableNameLookUp:      nil,
		CallSet:              nil,
		ImplementationLookUp: nil,
	}

	entitySet := []string{}

	// Generate Representation
	for _, name := range entitySet {
		representation := (*initialKontext.RepLookUp)[name]
		finish, err := representation.TryFinish(initialKontext)
		if err != nil {
			fmt.Println(err)
		} else {
			(*initialKontext.RepLookUp)[name] = finish
		}
	}

	//Generate Tables
	return dmodel.Schema{}, nil
}

func createRepresentationLookUp(up smodel.TypeLookUp) *map[string]zmodel.ElementRepresentation {
	m := make(map[string]zmodel.ElementRepresentation)
	for name, element := range up {
		m[name] = &zmodel.UnfinishedElement{
			Element:       element,
			ElementLookUp: make(map[string]*zmodel.NamedElementWrapper),
		}
	}
	return &m
}
