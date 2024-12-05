package semantic_rules

import (
	"testing"
)

func TestDuplicateRule(t *testing.T) {
	// Given
	rule := duplicatePathRule{}

	t.Run("success", func(t *testing.T) {
		testSemanticRule(t, &rule, "./test-resources/duplicate-paths-success.dmf", 0, nil)
	})
	t.Run("errors", func(t *testing.T) {
		testSemanticRule(t, &rule, "./test-resources/duplicate-paths-error.dmf", 6, nil)
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
		typeLookUp := testSemanticRule(t, &duplicatePathRule{}, filename, 0, nil)
		_ = testSemanticRule(t, &rule, filename, 0, ITypeLookUp(typeLookUp))
	})
	t.Run("errors", func(t *testing.T) {
		filename := "./test-resources/check-Super-Types-error.dmf"
		typeLookUp := testSemanticRule(t, &duplicatePathRule{}, filename, 0, nil)
		_ = testSemanticRule(t, &rule, filename, 5, ITypeLookUp(typeLookUp))
	})
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

//TODO: CheckEnumConstants
