package semantic_rules

import (
	"fmt"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestDuplicateRule(t *testing.T) {
	// Given
	rule := duplicatePathRule{}

	t.Run("success", func(t *testing.T) {
		filename := "./test-resources/duplicate-paths-success.dmf"
		file, model := testSetup(t, filename)
		testSemanticRule(t, &rule, filename, 0, nil, file, &model)
	})
	t.Run("errors", func(t *testing.T) {
		filename := "./test-resources/duplicate-paths-error.dmf"
		file, model := testSetup(t, filename)
		testSemanticRule(t, &rule, filename, 6, nil, file, &model)
	})
}

func BenchmarkDuplicatePathRule(b *testing.B) {
	// Given
	rule := duplicatePathRule{}

	file, model := testSetup(b, "test-resources/duplicate-paths-success.dmf")

	//When
	b.Run("duplicatePathRule", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			_, _ = rule.SemanticRule(file, &model, nil)
		}
	})
}

func TestCheckSuperTypes(t *testing.T) {
	// Given
	rule := modelWithTypesWalker{
		handler: []walkModelWithTypes{&checkSuperTypes{
			lookup:     make(TypeLookUp),
			nodeLookup: make(TypeNodeLookup),
			err:        nil,
		}},
	}

	t.Run("success", func(t *testing.T) {

		filename := "./test-resources/check-Super-Types-success.dmf"
		file, model := testSetup(t, filename)
		typeLookUp := testSemanticRule(t, &duplicatePathRule{}, filename, 0, nil, file, &model)
		_ = testSemanticRule(t, &rule, filename, 0, ITypeLookUp(typeLookUp), file, &model)
	})
	t.Run("errors", func(t *testing.T) {
		filename := "./test-resources/check-Super-Types-error.dmf"
		file, model := testSetup(t, filename)
		typeLookUp := testSemanticRule(t, &duplicatePathRule{}, filename, 0, nil, file, &model)
		_ = testSemanticRule(t, &rule, filename, 5, ITypeLookUp(typeLookUp), file, &model)
	})
}

func TestSuperTypes(t *testing.T) {
	// Given
	rule := modelWithTypesWalker{
		handler: []walkModelWithTypes{&checkSuperTypes{
			lookup:     make(TypeLookUp),
			nodeLookup: make(TypeNodeLookup),
			err:        nil,
		}},
	}
	filename := "./test-resources/check-Super-Types-Vererbung.dmf"
	file, model := testSetup(t, filename)
	typeLookUp := testSemanticRule(t, &duplicatePathRule{}, filename, 0, nil, file, &model)

	elements, a := rule.SemanticRule(file, &model, typeLookUp)
	fmt.Printf("elements: %v, a: %v\n", elements, a)

	landElement := model.Packages[0].Elements[1]
	for _, packageElement := range landElement.(*packages.Package).Elements {
		if packageElement.GetBase().Path.ToString() == "base.land.ElectricCar" {
			electricCar := packageElement.(*packages.StructElement)
			assert.NotNil(t, electricCar)
			assert.NotNil(t, electricCar.Extends)

			car := electricCar.Extends.(*packages.StructElement)
			assert.Equal(t, car.Path.ToString(), "base.land.Car")
			assert.NotNil(t, car.Extends)

			landVehicle := car.Extends.(*packages.StructElement)
			assert.Equal(t, landVehicle.Path.ToString(), "base.land.LandVehicle")
			assert.NotNil(t, landVehicle.Extends)

			baseVehicle := landVehicle.Extends.(*packages.StructElement)
			assert.Equal(t, baseVehicle.Path.ToString(), "base.transport.BaseVehicle")
			assert.Nil(t, baseVehicle.Extends)

		}
	}
}

func BenchmarkCheckSuperTypes(b *testing.B) {
	// Given
	rule := modelWithTypesWalker{
		handler: []walkModelWithTypes{&checkSuperTypes{}},
	}
	file, model := testSetup(b, "test-resources/duplicate-paths-success.dmf")
	_, typeLookUp := (&duplicatePathRule{}).SemanticRule(file, &model, nil)

	//When
	b.Run("checkSuperTypesRule", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			_, _ = rule.SemanticRule(file, &model, typeLookUp)
		}
	})
}

func TestDuplicateElements(t *testing.T) {
	// Given

	t.Run("success", func(t *testing.T) {

		filename := "./test-resources/duplicate-elements-success.dmf"
		file, model := testSetup(t, filename)
		typeLookUp := testSemanticRule(t, &duplicatePathRule{}, filename, 0, nil, file, &model)
		_ = testSemanticRule(t, &modelWithTypesWalker{
			handler: []walkModelWithTypes{&checkSuperTypes{
				lookup:     make(TypeLookUp),
				nodeLookup: make(TypeNodeLookup),
				err:        nil,
			}},
		}, filename, 0, ITypeLookUp(typeLookUp), file, &model)
		testSemanticRule(t, &duplicateElements{}, filename, 0, typeLookUp, file, &model)
	})
	t.Run("error", func(t *testing.T) {

		filename := "./test-resources/duplicate-elements-error.dmf"
		file, model := testSetup(t, filename)
		typeLookUp := testSemanticRule(t, &duplicatePathRule{}, filename, 0, nil, file, &model)
		_ = testSemanticRule(t, &modelWithTypesWalker{
			handler: []walkModelWithTypes{&checkSuperTypes{
				lookup:     make(TypeLookUp),
				nodeLookup: make(TypeNodeLookup),
				err:        nil,
			}},
		}, filename, 0, ITypeLookUp(typeLookUp), file, &model)
		testSemanticRule(t, &duplicateElements{}, filename, 1, typeLookUp, file, &model)
	})
	//t.Run("errors", func(t *testing.T) {
	//	filename := "./test-resources/check-Super-Types-error.dmf"
	//	typeLookUp := testSemanticRule(t, &duplicatePathRule{}, filename, 0, nil)
	//	_ = testSemanticRule(t, &rule, filename, 5, ITypeLookUp(typeLookUp))
	//})
}

//TODO: CheckEnumConstants
