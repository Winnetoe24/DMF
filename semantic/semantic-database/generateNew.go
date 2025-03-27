package semantic_database

import (
	"fmt"
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
	zmodel "github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel/zwischenmodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

func GenerateSchemaNew(lookup smodel.TypeLookUp) (dmodel.Schema, []errElement.ErrorElement) {

	// Setup
	initialKontext := zmodel.Kontext{
		Up:                   lookup,
		RepLookUp:            createRepresentationLookUp(lookup),
		TableNameLookUp:      createTableLookUp(lookup),
		CallSet:              []string{},
		ImplementationLookUp: createImplementationLookUp(lookup),
	}

	entitySet := createEntitySet(lookup)

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
	schema := dmodel.Schema{
		TableLookUp: make(map[string]*dmodel.Table),
	}

	// Generate Entity Tables
	for _, name := range entitySet {
		representation := (*initialKontext.RepLookUp)[name].(*zmodel.ReadyElement)
		for _, column := range representation.Identifier {
			column.PrimaryKey = true
		}
		schema.TableLookUp[name] = &dmodel.Table{
			Name:              initialKontext.TableNameLookUp[name],
			Columns:           representation.Columns,
			TablesForElements: nil,
		}
	}

	return schema, nil
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

func createEntitySet(up smodel.TypeLookUp) []string {
	entitySet := []string{}
	for path, element := range up {
		switch element.(type) {
		case *packages.EntityElement:
			entitySet = append(entitySet, path)
		}
	}
	return entitySet
}
