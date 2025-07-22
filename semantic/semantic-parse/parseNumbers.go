package semantic_parse

import (
	util "github.com/Winnetoe24/DMF/semantic/semantic-parse/parse_util"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"strconv"
)

func (p *Parser) parseNumber(node *tree_sitter.Node) (int32, error) {
	if node == nil {
		node = p.Node()
	}

	errorElement := util.AssertNodeState(node, "DMF Statement")
	if p.AddErrorElement(errorElement) {
		return 0, ERROR_ADDED
	}

	utf8Text := node.Utf8Text(p.context.Text)
	i, err := strconv.ParseInt(utf8Text, 10, 32)
	if err != nil {
		p.AddErrorElement(errElement.CreateErrorElementRef(node, err))
		return 0, ERROR_ADDED
	}
	return int32(i), nil
}
