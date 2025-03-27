package semantic_database

import (
	"fmt"
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
	zmodel "github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel/zwischenmodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"slices"
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
		FileOrdner:  entitySet,
	}
	var errElemente []errElement.ErrorElement
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

	// Generate Ausgelagerte Tables
	for _, name := range entitySet {
		representation := (*initialKontext.RepLookUp)[name]
		parentTable := schema.TableLookUp[name]
		for _, wrapper := range representation.GetAusgelagerteElemente() {
			switch element := wrapper.Element.(type) {
			case *packages.MultiReferenz:
				table := &dmodel.Table{
					Name:              initialKontext.TableNameLookUp[name] + "_" + element.Name.Name,
					Columns:           nil,
					TablesForElements: nil,
				}

				for _, column := range representation.GetIdentifiable().GetIdentifier() {
					table.Columns = append(table.Columns, &dmodel.Column{
						Name:       "Ref" + column.Name,
						Type:       column.Type,
						PrimaryKey: true,
						ForeignKey: &dmodel.ColumnReference{
							TableName: parentTable.Name,
							Column:    column,
						},
						Kommentar: "Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.",
					})
				}
				switch element.Typ {
				case packages.MAP:
					// Key
					keyGeneric := element.Generics[0]
					handleGeneric(keyGeneric, initialKontext,
						func(primitivType base.PrimitivType) {
							table.Columns = append(table.Columns, &dmodel.Column{
								Name:       "Key",
								Type:       primitivType,
								PrimaryKey: true,
								ForeignKey: nil,
								Kommentar:  "Key der Map",
							})
						},
						func(referenceTableName string, referenceColumn *dmodel.Column, foreignKey *dmodel.ColumnReference) {
							table.Columns = append(table.Columns, &dmodel.Column{
								Name:       "Key" + referenceColumn.Name,
								Type:       referenceColumn.Type,
								PrimaryKey: true,
								ForeignKey: foreignKey,
								Kommentar:  "Teil des Keys der Map",
							})
						})

					// Value
					valueGeneric := element.Generics[1]
					handleGeneric(valueGeneric, initialKontext,
						func(primitivType base.PrimitivType) {
							table.Columns = append(table.Columns, &dmodel.Column{
								Name:       "Value",
								Type:       primitivType,
								PrimaryKey: false,
								ForeignKey: nil,
								Kommentar:  "Wert der Map",
							})
						},
						func(referenceTableName string, referenceColumn *dmodel.Column, foreignKey *dmodel.ColumnReference) {
							table.Columns = append(table.Columns, &dmodel.Column{
								Name:       "Value" + referenceColumn.Name,
								Type:       referenceColumn.Type,
								PrimaryKey: false,
								ForeignKey: foreignKey,
								Kommentar:  "Teil des Werts der Map",
							})
						})

				case packages.LIST:
					table.Columns = append(table.Columns, &dmodel.Column{
						Name:       "Index",
						Type:       base.INT,
						PrimaryKey: true,
						ForeignKey: nil,
						Kommentar:  "Die Index des Listeneintrags",
					})

					//Werte
					valueGeneric := element.Generics[0]
					handleGeneric(valueGeneric, initialKontext,
						func(primitivType base.PrimitivType) {
							table.Columns = append(table.Columns, &dmodel.Column{
								Name:       "Value",
								Type:       *valueGeneric.PrimitivType,
								PrimaryKey: false,
								Kommentar:  "Werte der Liste",
							})
						},
						func(referenceTableName string, referenceColumn *dmodel.Column, foreignKey *dmodel.ColumnReference) {
							table.Columns = append(table.Columns, &dmodel.Column{
								Name:       "Value" + referenceColumn.Name,
								Type:       referenceColumn.Type,
								PrimaryKey: false,
								ForeignKey: foreignKey,
								Kommentar:  "Teil der Werte der Liste",
							})
						})

				case packages.SET:
					valueGeneric := element.Generics[0]
					handleGeneric(valueGeneric, initialKontext,
						func(primitivType base.PrimitivType) {
							table.Columns = append(table.Columns, &dmodel.Column{
								Name:       "Value",
								Type:       *valueGeneric.PrimitivType,
								PrimaryKey: true,
								Kommentar:  "Werte des Sets",
							})
						},
						func(referenceTableName string, referenceColumn *dmodel.Column, foreignKey *dmodel.ColumnReference) {
							table.Columns = append(table.Columns, &dmodel.Column{
								Name:       "Value" + referenceColumn.Name,
								Type:       referenceColumn.Type,
								PrimaryKey: true,
								ForeignKey: foreignKey,
								Kommentar:  "Teil der Werte des Sets",
							})
						})
				}
				parentTable.TablesForElements = append(parentTable.TablesForElements, dmodel.TableReference{
					Referenzname: element.Name.Name,
					Table:        table,
				})
			}
		}
	}

	return schema, errElemente
}

func handleGeneric(multiType packages.MultiType, kontext zmodel.Kontext,
	handlePrimitive func(primitivType base.PrimitivType),
	handleReference func(referenceTableName string, referenceColumn *dmodel.Column, foreignKey *dmodel.ColumnReference)) bool {
	if multiType.PrimitivType != nil {
		handlePrimitive(*multiType.PrimitivType)
	} else {
		referenceName := multiType.ModelPath.ToString()
		referenceRepresentation := (*kontext.RepLookUp)[referenceName]
		isEntity := referenceRepresentation.GetPackageElement().GetType() == base.ENTITY
		identifiable := referenceRepresentation.GetIdentifiable()
		if identifiable == nil {
			nRep, err := referenceRepresentation.TryFinish(kontext)
			if err != nil {
				fmt.Println(err)
			} else {
				(*kontext.RepLookUp)[referenceName] = nRep
				referenceRepresentation = nRep
				identifiable = nRep.GetIdentifiable()
			}
		}
		if identifiable == nil {
			return true
		}
		referenceTableName := kontext.TableNameLookUp[referenceName]
		for _, column := range identifiable.GetIdentifier() {
			var foreignKey *dmodel.ColumnReference
			if isEntity {
				foreignKey = &dmodel.ColumnReference{
					TableName: referenceTableName,
					Column:    column,
				}
			}
			handleReference(referenceTableName, column, foreignKey)
		}

	}
	return false
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
	slices.SortFunc(entitySet, func(a, b string) int {
		peA := up[a]
		peB := up[b]
		nodeA := peA.GetBase().Node
		nodeB := peB.GetBase().Node
		if nodeA == nil {
			if nodeB == nil {
				return 0
			}
			return -1
		} else if nodeB == nil {
			return 1
		}

		if nodeA.StartPosition().Row == nodeB.StartPosition().Row {
			return int(nodeA.StartPosition().Column) - int(nodeB.StartPosition().Column)
		}
		return int(nodeA.StartPosition().Row) - int(nodeB.StartPosition().Row)
	})
	return entitySet
}
