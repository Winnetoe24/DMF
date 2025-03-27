package semantic_database

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"testing"
)

func TestGenerate(t *testing.T) {
	// Given
	var lookup = make(smodel.TypeLookUp)
	lookup["de.Obst"] = &packages.StructElement{
		PackageElement: base.PackageElement{
			ModelElement: base.ModelElement{},
			Path:         base.ModelPath{"de", "Obst"},
			Identifier: base.ElementIdentifier{
				Name: "Obst",
			},
			NamedElements: map[string]base.NamedElement{
				"geerntetAm": &packages.Argument{
					Typ: base.DATE,
					Name: base.ElementIdentifier{
						Name: "geerntetAm",
					},
				},
				"anzahl": &packages.Argument{
					Typ: base.INT,
					Name: base.ElementIdentifier{
						Name: "anzahl",
					},
				},
			},
		},
	}
	lookup["de.Apfel"] = &packages.EntityElement{
		StructElement: packages.StructElement{
			PackageElement: base.PackageElement{
				ModelElement: base.ModelElement{},
				Path:         base.ModelPath{"de", "Apfel"},
				Identifier: base.ElementIdentifier{
					Name: "Apfel",
				},
				NamedElements: map[string]base.NamedElement{
					"geerntetAm": &packages.Argument{
						Typ: base.DATE,
						Name: base.ElementIdentifier{
							Name: "geerntetAm",
						},
					},
					"anzahl": &packages.Argument{
						Typ: base.INT,
						Name: base.ElementIdentifier{
							Name: "anzahl",
						},
					},
				},
			},
		},
		EntityIdentifier: packages.EntityIdentifier{
			Variablen: []base.ElementIdentifier{{Name: "geerntetAm"}},
		},
	}
	lookup["de.Ernte"] = &packages.EntityElement{
		StructElement: packages.StructElement{
			PackageElement: base.PackageElement{
				ModelElement: base.ModelElement{},
				Path:         base.ModelPath{"de", "Ernte"},
				Identifier: base.ElementIdentifier{
					Name: "Ernte",
				},
				NamedElements: map[string]base.NamedElement{
					"inhalt": &packages.MultiReferenz{
						ModelElement: base.ModelElement{},
						Typ:          packages.LIST,
						Name: base.ElementIdentifier{
							ModelElement: base.ModelElement{},
							Name:         "inhalt",
						},
						Generics: [2]packages.MultiType{
							{
								ModelPath: &base.ModelPath{"de", "Obst"},
							},
						},
					},
					"wert": &packages.Argument{
						Typ: base.DOUBLE,
						Name: base.ElementIdentifier{
							Name: "wert",
						},
					},
					"session": &packages.Argument{
						Typ: base.INT,
						Name: base.ElementIdentifier{
							Name: "session",
						},
					},
				},
			},
		},
		EntityIdentifier: packages.EntityIdentifier{
			Variablen: []base.ElementIdentifier{{Name: "session"}},
		},
	}

	// When
	schema, elements := GenerateSchemaNew(lookup)

	// Then
	if len(schema.TableLookUp) != 2 {
		t.Errorf("schema has %d tables, should be 2", len(schema.TableLookUp))
	}
	if len(elements) != 0 {
		t.Errorf("schema has %d elements, should be 0", len(elements))
		for _, element := range elements {
			t.Error(element.Error)
		}
	}
}

func TestGenerateEmpty(t *testing.T) {
	// Given
	var lookup = make(smodel.TypeLookUp)

	// When
	schema, elements := GenerateSchema(lookup)

	// Then
	if len(schema.TableLookUp) != 0 {
		t.Errorf("schema has %d table, should be 0", len(schema.TableLookUp))
	}
	if len(elements) != 0 {
		t.Errorf("schema has %d elements, should be 0", len(elements))
		for _, element := range elements {
			t.Error(element.Error)
		}
	}
}
