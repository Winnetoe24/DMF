package semantic_rules

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFillTypeLookUp(t *testing.T) {

	// Given

	t.Run("success", func(t *testing.T) {
		filename := "./test-resources/duplicate-paths-success.dmf"
		model, ctx := testSetup(t, filename)
		_, errorElements := newFillTypeLookUp().Fill(&model)
		checkErrorCount(t, ctx, errorElements, 0)
	})
	t.Run("errors", func(t *testing.T) {
		filename := "./test-resources/duplicate-paths-error.dmf"
		model, ctx := testSetup(t, filename)
		_, errorElements := newFillTypeLookUp().Fill(&model)
		checkErrorCount(t, ctx, errorElements, 6)
	})
}

func BenchmarkFillTypeLookUp(b *testing.B) {
	// Given
	model, _ := testSetup(b, "test-resources/duplicate-paths-success.dmf")

	//When
	b.Run("fillTypeLookUp", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			_, _ = newFillTypeLookUp().Fill(&model)
		}
	})
}

func TestCheckSuperTypes(t *testing.T) {
	// Given
	t.Run("success", func(t *testing.T) {

		filename := "./test-resources/check-Super-Types-success.dmf"
		model, ctx := testSetup(t, filename)
		lookup, errorElements := newFillTypeLookUp().Fill(&model)
		checkErrorCount(t, ctx, errorElements, 0)

		errorElements = newComputeSuperTypes(&lookup).walk()
		checkErrorCount(t, ctx, errorElements, 0)
	})
	t.Run("errors", func(t *testing.T) {
		filename := "./test-resources/check-Super-Types-error.dmf"
		model, ctx := testSetup(t, filename)
		lookup, errorElements := newFillTypeLookUp().Fill(&model)
		checkErrorCount(t, ctx, errorElements, 0)

		errorElements = newComputeSuperTypes(&lookup).walk()
		checkErrorCount(t, ctx, errorElements, 5)
	})
}

func TestSuperTypes(t *testing.T) {
	// Given
	filename := "./test-resources/check-Super-Types-Vererbung.dmf"
	model, ctx := testSetup(t, filename)

	lookup, errorElements := newFillTypeLookUp().Fill(&model)
	checkErrorCount(t, ctx, errorElements, 0)

	errorElements = newComputeSuperTypes(&lookup).walk()
	checkErrorCount(t, ctx, errorElements, 0)

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

func BenchmarkComputeSuperTypes(b *testing.B) {
	// Given

	filename := "test-resources/duplicate-paths-success.dmf"
	model, _ := testSetup(b, filename)

	lookup, _ := newFillTypeLookUp().Fill(&model)

	//When
	b.Run("computeSuperTypes", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			_ = newComputeSuperTypes(&lookup).walk()
		}
	})
}

func TestComputeElements(t *testing.T) {
	// Given

	t.Run("success", func(t *testing.T) {

		filename := "./test-resources/duplicate-elements-success.dmf"
		model, ctx := testSetup(t, filename)

		lookup, errorElements := newFillTypeLookUp().Fill(&model)
		checkErrorCount(t, ctx, errorElements, 0)

		errorElements = newComputeSuperTypes(&lookup).walk()
		checkErrorCount(t, ctx, errorElements, 0)

		errorElements = newComputeElements(&lookup).walk()
		checkErrorCount(t, ctx, errorElements, 0)

	})
	t.Run("error", func(t *testing.T) {

		filename := "./test-resources/duplicate-elements-error.dmf"
		model, ctx := testSetup(t, filename)
		lookup, errorElements := newFillTypeLookUp().Fill(&model)
		checkErrorCount(t, ctx, errorElements, 0)

		errorElements = newComputeSuperTypes(&lookup).walk()
		checkErrorCount(t, ctx, errorElements, 0)

		errorElements = newComputeElements(&lookup).walk()
		checkErrorCount(t, ctx, errorElements, 1)
	})
}

//TODO: CheckEnumConstants
