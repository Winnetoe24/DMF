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

func TestAPIEditNothing(t *testing.T) {
	// Given
	dateiname := "edit-before.dmf"
	//file, err := os.ReadFile("./test-resources/duplicate-paths-success.dmf")
	file, err := os.ReadFile("./test-resources/" + dateiname)
	if err != nil {
		t.Errorf("Error reading file: %e", err)
	}

	//When
	models := make(chan *sematic_model.Model)
	trees := make(chan *tree_sitter.Tree)
	errorElements, errPos, err, lookup := ParseNewFile(string(file), trees, models)
	model := <-models
	tree := <-trees
	//packages := model.Packages
	//t.Logf("Size: %v", unsafe.Sizeof(packages))

	if err != nil {
		t.Errorf("Error parsing at Pos %v\n", errPos)
	}
	if errPos > 0 {
		t.Errorf("Error parsing at Pos %v\n", errPos)
	}
	if errorElements != nil && len(errorElements) > 0 {
		for _, element := range errorElements {
			t.Error(element.ToErrorMsg(&err_element.ErrorContext{
				Dateiname:   dateiname,
				Dateiinhalt: file,
			}))
		}
	}

	_, _, _, errorElements = ParseEdit(string(file), make([]*tree_sitter.InputEdit, 0), tree, model, &lookup)

	if errorElements != nil && len(errorElements) > 0 {
		for _, element := range errorElements {
			t.Error(element.ToErrorMsg(&err_element.ErrorContext{
				Dateiname:   dateiname,
				Dateiinhalt: file,
			}))
		}
	}

}

func TestAPIEdit(t *testing.T) {
	// Given
	dateiname := "edit-before-light.dmf"
	file, err := os.ReadFile("./test-resources/" + dateiname)
	if err != nil {
		t.Errorf("Error reading file: %e", err)
	}

	//When
	models := make(chan *sematic_model.Model)
	trees := make(chan *tree_sitter.Tree)
	errorElements, errPos, err, lookup := ParseNewFile(string(file), trees, models)
	model := <-models
	tree := <-trees
	//packages := model.Packages
	//t.Logf("Size: %v", unsafe.Sizeof(packages))

	if err != nil {
		t.Errorf("Error parsing at Pos %v\n", errPos)
	}
	if errPos > 0 {
		t.Errorf("Error parsing at Pos %v\n", errPos)
	}
	if errorElements != nil && len(errorElements) > 0 {
		for _, element := range errorElements {
			t.Error(element.ToErrorMsg(&err_element.ErrorContext{
				Dateiname:   dateiname,
				Dateiinhalt: file,
			}))
		}
	}

	dateiname = "edit-after-light.dmf"
	file, err = os.ReadFile("./test-resources/" + dateiname)
	if err != nil {
		t.Errorf("Error reading file: %e", err)
	}
	edits := make([]*tree_sitter.InputEdit, 0)
	edits = append(edits, &tree_sitter.InputEdit{
		StartByte:  121,
		OldEndByte: 121,
		NewEndByte: 151,
		StartPosition: tree_sitter.Point{
			Row:    6,
			Column: 39,
		},
		OldEndPosition: tree_sitter.Point{
			Row:    6,
			Column: 39,
		},
		NewEndPosition: tree_sitter.Point{
			Row:    7,
			Column: 35,
		},
	})
	_, _, _, errorElements = ParseEdit(string(file), edits, tree, model, &lookup)

	if errorElements != nil && len(errorElements) > 0 {
		for _, element := range errorElements {
			t.Error(element.ToErrorMsg(&err_element.ErrorContext{
				Dateiname:   dateiname,
				Dateiinhalt: file,
			}))
		}
	}

}
