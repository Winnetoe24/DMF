package semantic_rules

import (
	sematic_model "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"os"
	"testing"
)

func TestAPI(t *testing.T) {
	// Given
	//file, err := os.ReadFile("./test-resources/duplicate-paths-success.dmf")
	file, err := os.ReadFile("../example-file-big")
	if err != nil {
		t.Errorf("Error reading file: %e", err)
	}

	//When
	models := make(chan<- *sematic_model.Model)
	errorElements, errPos, err, _ := ParseNewFile(string(file), make(chan<- *tree_sitter.Tree), models)
	//model := <-models
	//packages := model.Packages
	//t.Logf("Size: %v", unsafe.Sizeof(packages))

	if errPos > 0 {
		t.Errorf("Error parsing at Pos %v\n", errPos)
	}
	if errorElements != nil && len(errorElements) > 0 {
		for _, element := range errorElements {
			t.Error(element.ToErrorMsg(&err_element.ErrorContext{
				Dateiname:   "example-file-big",
				Dateiinhalt: file,
			}))
		}
	}

}

// 19084305 ns  - duplicate Path
// 2228382 ns - New Error Handling
// 2243490 ns  - New Error Handling
// 2386012 ns - New Error Rendering
func BenchmarkParseNewFile(b *testing.B) {
	file, err := os.ReadFile("../example-file-big")
	if err != nil {
		b.Errorf("Error reading file: %e", err)
	}
	b.Run("ParseNewFile", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			treeChannel := make(chan *tree_sitter.Tree, 1)
			modelChannel := make(chan *sematic_model.Model, 1)
			ParseNewFile(string(file), treeChannel, modelChannel)
			_ = <-treeChannel
			_ = <-modelChannel
			close(treeChannel)
			close(modelChannel)
		}
		//f, i, err2 := ParseNewFile(string(file), treeChannel, modelChannel)
		//if err2 != nil {
		//	b.Errorf("Error parsing at Pos %v %e\n", i, err2)
		//} else {
		//	b.Logf("Parsed at Pos %v\n", f)
		//}
	})
}
