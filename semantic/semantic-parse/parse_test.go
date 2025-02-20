package semantic_parse

import (
	"fmt"
	tree_sitter_dmf "github.com/Winnetoe24/DMF/grammar/dmf_language"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/stretchr/testify/assert"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"os"
	"strings"
	"testing"
)

func TestParse(t *testing.T) {

	file, err := os.ReadFile("../example.dmf")
	if err != nil {
		t.Errorf("Kann test Resource nicht lesen: %e", err)
		return
	}
	text := string(file)

	language := tree_sitter.NewLanguage(tree_sitter_dmf.Language())
	parser := tree_sitter.NewParser()
	err = parser.SetLanguage(language)
	if err != nil {
		t.Errorf("Error setting Language: %e", err)
	}

	parse := parser.Parse(file, nil)

	c := parse.Walk()
	defer c.Close()
	var visit func(depth int)
	visit = func(depth int) {
		printNode(c.Node(), depth, c.FieldName())
		ok := c.GotoFirstChild()
		if ok {
			defer c.GotoParent()
		}
		for ok = ok; ok; ok = c.GotoNextSibling() {
			visit(depth + 1)
		}

	}
	//visit(0)

	model, parseErrElements, err := Parse([]byte(text), parse)
	if err != nil {
		t.Errorf("Error Parsing: %e", err)
	}

	for _, element := range parseErrElements {
		t.Error(element.ToErrorMsg(&err_element.ErrorContext{
			Dateiname:   "example-file",
			Dateiinhalt: file,
		}))
	}

	t.Logf("%+v", model)
	t.Logf("%+v", *model.Packages[0].Override.JavaOverride)
	other := model.Packages[0].Elements[1].(*packages.Package)
	Inte := other.Elements[4].(*packages.InterfaceElement)
	t.Logf("%+v", Inte.Funktionen)
	funktion := Inte.Funktionen[0]
	t.Logf("%+v", funktion.Override)
	//t.Logf("%+v", funktion.Override.JavaOverride)
	t.Logf("%+v", funktion.Override.JavaOverride)

	assert.Equal(t, []int32{0, 0, 1}, model.Version, "False Version geparsed: %+v", model.Version)
}

func printNode(n *tree_sitter.Node, depth int, name string) {
	prefix := ""
	if name != "" {
		prefix = name + ": "
	}
	fmt.Printf("%s%s%s [%d-%d]\n", strings.Repeat("    ", depth), prefix, n.Kind(), n.StartByte(), n.EndByte())
}
