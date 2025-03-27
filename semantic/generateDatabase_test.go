package semantic

import (
	"fmt"
	semantic_database "github.com/Winnetoe24/DMF/semantic/semantic-database"
	"os"
	"testing"
)

func BenchmarkGenerateDatabase(b *testing.B) {
	file, err := os.ReadFile("../intellijTest/riesig.dmf")
	if err != nil {
		b.Errorf("Error reading file: %e", err)
	}

	errorElements, _, _, _, _, lookup := ParseNewFile(string(file), nil, []string{})
	if len(errorElements) > 0 {
		for _, element := range errorElements {
			b.Errorf("Error parsing file: %+v\n", element)
		}
	}
	//When
	for i := 0; i < b.N; i++ {
		semantic_database.GenerateSchemaNew(lookup)
	}
}

func TestGenerateDatabase(t *testing.T) {
	file, err := os.ReadFile("../intellijTest/riesig.dmf")
	//file, err := os.ReadFile("./simpleDatabaseTest.dmf")
	if err != nil {
		t.Errorf("Error reading file: %e", err)
	}

	errorElements, _, _, _, _, lookup := ParseNewFile(string(file), nil, []string{})
	if len(errorElements) > 0 {
		for _, element := range errorElements {
			t.Errorf("Error parsing file: %+v\n", element)
		}
	}
	//When
	schemaNew, elements := semantic_database.GenerateSchemaNew(lookup)
	if len(elements) > 0 {
		for _, element := range elements {
			t.Errorf("Error parsing file: %+v\n", element)
		}
	}

	fmt.Printf("schemaNew: %+v\n", schemaNew)

}
