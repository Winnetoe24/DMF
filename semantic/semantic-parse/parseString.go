package semantic_parse

import (
	util "github.com/Winnetoe24/DMF/semantic/semantic-parse/parse_util"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
)

func (p *Parser) parseString() (base.StringValue, error) {
	node := p.Node()

	errorElement := util.AssertNodeState(node, "String")
	if p.AddErrorElement(errorElement) {
		return base.StringValue{}, ERROR_ADDED
	}

	if !p.GoToFirstChild() {
		p.AddErrorElement(util.CreateMissingElementError(node, "string"))
		return base.StringValue{}, ERROR_ADDED
	}
	defer p.GoToParent()

	var lastValue, value = "", ""

	for {
		hasSibling := p.GoToNextSibling()
		if !hasSibling {
			break
		}

		value += lastValue
		lastValue = p.context.Cursor.Node().Utf8Text(p.context.Text)
	}
	return base.StringValue{
		ModelElement: base.ModelElement{
			Node: node,
		},
		Value: value,
	}, nil
}
