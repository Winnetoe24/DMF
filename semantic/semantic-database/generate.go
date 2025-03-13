package semantic_database

import (
	"errors"
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"slices"
)

func GenerateSchema(lookup smodel.TypeLookUp) (dmodel.Schema, []errElement.ErrorElement) {
	schema := dmodel.Schema{
		TableLookUp: make(map[string]*dmodel.Table),
	}
	errorElemente := make([]errElement.ErrorElement, 0)
	schluessel := computePrimaerSchluessel(lookup)
	for _, pElement := range lookup {
		switch element := pElement.(type) {
		case *packages.EntityElement:
			table := dmodel.Table{
				Name:              element.Identifier.Name,
				Columns:           make([]*dmodel.Column, 0),
				TablesForElements: make([]dmodel.TableReference, 0),
			}
			columnLookUp := make(map[string]*dmodel.Column)
			schema.TableLookUp[table.Name] = &table

			// Primärschluessel
			columns := schluessel[table.Name]
			for _, column := range columns {
				table.Columns = append(table.Columns, column)
				columnLookUp[column.Name] = column
			}

			// Restliche Spalten
			for name, namedElement := range element.NamedElements {

				if column, found := columnLookUp[name]; found {
					if !column.PrimaryKey {
						errorElemente = append(errorElemente, errElement.CreateErrorElement(namedElement.Element().Node, errors.New("doppelter Spaltenname")))
					}
					// Doppelt oder schon durch Primärschluessel enthalten
					continue
				}

				switch nElement := namedElement.(type) {
				case *packages.Argument:
					column := dmodel.Column{
						Name:       nElement.Name.Name,
						Type:       nElement.Typ,
						PrimaryKey: false,
						ForeignKey: nil,
						Kommentar:  computeComment(nElement.Kommentar),
					}
					table.Columns = append(table.Columns, &column)
					columnLookUp[column.Name] = &column
				case *packages.Referenz:
					referenzierterTable := nElement.Typ[len(nElement.Typ)-1]
					primaerschluessel, found := schluessel[referenzierterTable]
					if !found {
						errorElemente = append(errorElemente, errElement.CreateErrorElement(namedElement.Element().Node, errors.New("keine Primärschlüssel für Referenz gefunden")))
						continue
					}
					for _, schluesselColumn := range primaerschluessel {
						column := dmodel.Column{
							Name:       schluesselColumn.Name,
							Type:       schluesselColumn.Type,
							PrimaryKey: false,
							ForeignKey: &dmodel.ColumnReference{
								TableName: referenzierterTable,
								Column:    schluesselColumn,
							},
						}
						if columnLookUp[schluesselColumn.Name] != nil {
							errorElemente = append(errorElemente, errElement.CreateErrorElement(namedElement.Element().Node, errors.New("doppelter Spaltenname")))
							continue
						}
						table.Columns = append(table.Columns, &column)
						columnLookUp[column.Name] = &column

						//TODO Restliche Attribute
					}
				case *packages.MultiReferenz:
					referenzTable := dmodel.Table{
						Name:              table.Name + nElement.Name.Name,
						Columns:           make([]*dmodel.Column, 0),
						TablesForElements: make([]dmodel.TableReference, 0),
					}
					// Primärschlüssel der Tabelle der Ursprungstabelle
					for _, column := range columns {
						schluesselColumn := dmodel.Column{
							Name:       column.Name,
							Type:       column.Type,
							PrimaryKey: true,
							ForeignKey: &dmodel.ColumnReference{
								TableName: table.Name,
								Column:    column,
							},
							Kommentar: "Referenz zur Ursprungstabelle",
						}
						referenzTable.Columns = append(referenzTable.Columns, &schluesselColumn)
					}

					switch nElement.Typ {
					case packages.LIST:
						fallthrough
					case packages.SET:
						// Value
						genericColumns, errorElement := addGenericColumns(nElement, nElement.Generics[0], schluessel, nElement.Typ == packages.SET)
						if errorElement != nil {
							errorElemente = append(errorElemente, *errorElement)
							continue
						}
						referenzTable.Columns = append(referenzTable.Columns, genericColumns...)
					case packages.MAP:
						// Key
						genericColumns, errorElement := addGenericColumns(nElement, nElement.Generics[0], schluessel, true)
						if errorElement != nil {
							errorElemente = append(errorElemente, *errorElement)
							continue
						}
						referenzTable.Columns = append(referenzTable.Columns, genericColumns...)

						// Value
						genericColumns, errorElement = addGenericColumns(nElement, nElement.Generics[1], schluessel, false)
						if errorElement != nil {
							errorElemente = append(errorElemente, *errorElement)
							continue
						}
						referenzTable.Columns = append(referenzTable.Columns, genericColumns...)

					}
					schema.TableLookUp[referenzTable.Name] = &referenzTable
					table.TablesForElements = append(table.TablesForElements, dmodel.TableReference{
						Referenzname: name,
						Table:        &referenzTable,
					})

				}
			}
		}
	}

	return schema, errorElemente
}

func addGenericColumns(nElement *packages.MultiReferenz, multiType packages.MultiType, schluessel map[string][]*dmodel.Column, shouldBePrimaryKey bool) ([]*dmodel.Column, *errElement.ErrorElement) {
	var genericColumns []*dmodel.Column
	if multiType.PrimitivType != nil {
		genericColumns = append(genericColumns, &dmodel.Column{
			Name:       nElement.Name.Name,
			Type:       *multiType.PrimitivType,
			PrimaryKey: shouldBePrimaryKey,
			ForeignKey: nil,
			Kommentar:  computeComment(nElement.Kommentar),
		})
	} else if multiType.ModelPath != nil {
		referenzierterTable := (*multiType.ModelPath)[len(*multiType.ModelPath)-1]
		primaerschluessel, found := schluessel[referenzierterTable]
		if !found {
			return nil, errElement.CreateErrorElementRef(nElement.Node, errors.New("keine Primärschlüssel für Referenz gefunden"))
		}
		for _, schluesselColumn := range primaerschluessel {
			column := dmodel.Column{
				Name:       schluesselColumn.Name,
				Type:       schluesselColumn.Type,
				PrimaryKey: shouldBePrimaryKey,
				ForeignKey: &dmodel.ColumnReference{
					TableName: referenzierterTable,
					Column:    schluesselColumn,
				},
			}
			genericColumns = append(genericColumns, &column)
		}
	}
	return genericColumns, nil
}

func computeComment(comment *base.Comment) string {
	if comment == nil {
		return ""
	}

	out := ""
	for _, s := range *comment {
		out += s
	}
	return out
}

func computePrimaerSchluessel(lookup smodel.TypeLookUp) map[string][]*dmodel.Column {
	schluesselLookup := make(map[string][]*dmodel.Column)
	for _, element := range lookup {
		determineSchluessel(element, lookup, &schluesselLookup, []string{})
	}
	return schluesselLookup
}

func determineSchluessel(element packages.PackageElement, lookup smodel.TypeLookUp, schluesselLookup *map[string][]*dmodel.Column, calledFrom []string) *errElement.ErrorElement {
	tableName := element.GetBase().Path[len(element.GetBase().Path)-1]
	if _, found := (*schluesselLookup)[tableName]; found {
		return nil
	} else if slices.Contains(calledFrom, tableName) {
		return errElement.CreateErrorElementRef(element.GetBase().Node, errors.New("zyklische Referenzen"))
	}
	switch element := element.(type) {
	case *packages.EnumElement:
		(*schluesselLookup)[tableName] = []*dmodel.Column{{
			Name:       "ID",
			Type:       base.INT,
			PrimaryKey: true,
			ForeignKey: nil,
			Kommentar:  "ID des Enums",
		}}
	case *packages.EntityElement:
		columns := make([]*dmodel.Column, 0)
		for _, identifier := range element.EntityIdentifier.Variablen {
			namedElement := element.NamedElements[identifier.Name]
			switch namedElement := namedElement.(type) {
			case *packages.Argument:
				columns = append(columns, &dmodel.Column{
					Name:       namedElement.Name.Name,
					Type:       namedElement.Typ,
					PrimaryKey: true,
					ForeignKey: nil,
					Kommentar:  computeComment(namedElement.Kommentar),
				})
			case *packages.Referenz:
				packageElement := lookup[namedElement.Typ.ToString()]

				errorElement := determineSchluessel(packageElement, lookup, schluesselLookup, append(calledFrom, tableName))
				if errorElement != nil {
					return errorElement
				}
				referenzierterTable := packageElement.GetBase().Path[len(packageElement.GetBase().Path)-1]
				referenzSchluessel, found := (*schluesselLookup)[referenzierterTable]
				if !found {
					return errElement.CreateErrorElementRef(namedElement.Node, errors.New("keine Schlüssel für Referenz gefunden"))
				}
				for _, column := range referenzSchluessel {
					columns = append(columns, &dmodel.Column{
						Name:       namedElement.Name.Name + "_" + column.Name,
						Type:       column.Type,
						PrimaryKey: true,
						ForeignKey: &dmodel.ColumnReference{
							TableName: referenzierterTable,
							Column:    column,
						},
						Kommentar: computeComment(namedElement.Kommentar),
					})
				}
			default:
				return errElement.CreateErrorElementRef(namedElement.Element().Node, errors.New("dieses Element kann nicht in einem Identifier genutzt werden"))
			}
		}
		(*schluesselLookup)[tableName] = columns
	case *packages.StructElement:
		columns := make([]*dmodel.Column, 0)
		for _, namedElement := range element.NamedElements {
			switch namedElement := namedElement.(type) {
			case *packages.Argument:
				columns = append(columns, &dmodel.Column{
					Name:       namedElement.Name.Name,
					Type:       namedElement.Typ,
					PrimaryKey: true,
					ForeignKey: nil,
					Kommentar:  computeComment(namedElement.Kommentar),
				})
			case *packages.Referenz:
				packageElement := lookup[namedElement.Typ.ToString()]

				errorElement := determineSchluessel(packageElement, lookup, schluesselLookup, append(calledFrom, tableName))
				if errorElement != nil {
					return errorElement
				}
				referenzierterTable := packageElement.GetBase().Path[len(packageElement.GetBase().Path)-1]
				referenzSchluessel, found := (*schluesselLookup)[referenzierterTable]
				if !found {
					return errElement.CreateErrorElementRef(namedElement.Node, errors.New("keine Schlüssel für Referenz gefunden"))
				}
				for _, column := range referenzSchluessel {
					columns = append(columns, &dmodel.Column{
						Name:       namedElement.Name.Name + "_" + column.Name,
						Type:       column.Type,
						PrimaryKey: true,
						ForeignKey: &dmodel.ColumnReference{
							TableName: referenzierterTable,
							Column:    column,
						},
						Kommentar: computeComment(namedElement.Kommentar),
					})
				}
			}
		}
		(*schluesselLookup)[tableName] = columns
	}
	return nil
}
