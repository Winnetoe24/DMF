package semantic_parse

import (
	"errors"
	"github.com/Winnetoe24/DMF/semantic/data"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/builder"
	util "github.com/Winnetoe24/DMF/semantic/semantic-parse/parse_util"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

var ERROR_ADDED = errors.New("error element added")

// Ablauf
// 1. Parser wird erstellt
// 2. Parser durchläuft Ast und ruft nach der extraktion von einem Sematischen Element die Builder auf
// 3. (After Parse)
//	importierte Dateien werden geparsed
// 4. Importierte Elemente werden auf das Modell angewendet
// 5. Semantische Verarbeitung

type Parser struct {
	context           util.ParseContext
	currentPreBuilder *builder.PreBuilder
	currentBuilder    builder.Builder
	builders          *data.Stack[builder.Builder]
}

func Parse(text []byte, tree *tree_sitter.Tree,
	parseFile func(statement smodel.ImportStatement) (smodel.TypeLookUp, *errElement.ErrorElement)) (smodel.Model, []errElement.ErrorElement, error) {

	parser := createParser(text, tree, parseFile)
	parser.parse()
	return smodel.Model{}, nil, nil
}

func createParser(text []byte, tree *tree_sitter.Tree,
	parseFile func(statement smodel.ImportStatement) (smodel.TypeLookUp, *errElement.ErrorElement)) *Parser {
	initialBuilder := &builder.ModelBuilder{}
	return &Parser{
		context: util.ParseContext{
			ErrorElements: nil,
			Text:          text,
			Cursor:        tree.Walk(),
			ParseFile:     parseFile,
			ImportLookUp:  nil,
			UsedFiles:     nil,
		},
		currentPreBuilder: nil,
		currentBuilder:    initialBuilder,
		builders:          data.CreateStack[builder.Builder](initialBuilder),
	}
}

func (p *Parser) parse() error {
	if !p.GoToFirstChild() {
		return ERROR_ADDED
	}
	err := p.parseDMF()
	if err != nil {
		return err
	}

	return nil
}
