package javaGenBase

import (
	"bytes"
	"github.com/Winnetoe24/DMF/semantic"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"os"
	"testing"
)

func TestClass(t *testing.T) {
	//data := map[string]interface{}{
	//	"Name": "TestKlasse",
	//	"Fields": []map[string]interface{}{
	//		{
	//			"Typ":  "int",
	//			"Name": "i",
	//		},
	//	},
	//}
	//comment := gbase.Comment([]string{"TestKommentar"})
	//data := packages.StructElement{
	//	PackageElement: gbase.PackageElement{
	//		ModelElement: gbase.ModelElement{
	//			Kommentar: &comment,
	//			Node:      nil,
	//		},
	//		Path:          gbase.ModelPath([]string{"de", "test", "TestKlasse"}),
	//		EntityIdentifier:    gbase.ElementIdentifier{},
	//		NamedElements: nil,
	//		Expand:        false,
	//	},
	//	ExtendsPath:     nil,
	//	Extends:         nil,
	//	ImplementsPaths: nil,
	//	Implements:      nil,
	//	Argumente: []packages.Argument{{
	//		ModelElement: gbase.ModelElement{},
	//		Typ:          gbase.INT,
	//		Name: gbase.ElementIdentifier{
	//			ModelElement: gbase.ModelElement{},
	//			Name:         "i",
	//		},
	//	}},
	//	Referenzen: nil,
	//	Funktionen: nil,
	//}

	file, err := os.ReadFile("./testClass.dmf")
	if err != nil {
		t.Errorf("Error reading file: %e", err)
	}

	afterTree := make(chan *tree_sitter.Tree, 1)
	defer close(afterTree)
	afterModel := make(chan *smodel.Model, 1)
	defer close(afterModel)
	_, _, _, up := semantic.ParseNewFile(string(file), afterTree, afterModel)
	data := up["de.test.TestKlasse"]
	template := NewTemplate()
	bufferString := bytes.NewBufferString("")
	err = template.GenerateStruct(bufferString, data.(*packages.StructElement))
	if err != nil {
		t.Error(err)
	}
	println(bufferString.String())
}
