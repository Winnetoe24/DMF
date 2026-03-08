package semantic_parse

import (
	"errors"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/builder"
	util "github.com/Winnetoe24/DMF/semantic/semantic-parse/parse_util"
)

func (p *Parser) parseStatement() error {
	node := p.Node()

	errorElement := util.AssertNodeState(node, "Model Statement")
	if p.AddErrorElement(errorElement) {
		return ERROR_ADDED
	}
	if !p.GoToFirstChild() {
		p.AddErrorElement(util.CreateMissingElementError(node, "statement"))
		return ERROR_ADDED
	}

	preBuilder := p.PushBuilder(&builder.PreBuilder{}).(*builder.PreBuilder)

	if p.Node().GrammarName() == "comment" {
		p.GoToNextSibling()
	}

	if p.Node().GrammarName() == "expand" {
		preBuilder.Expand = true
		if !p.GoToNextSibling() {
			p.AddErrorElement(util.CreateMissingElementError(node, "statement body"))
			return ERROR_ADDED
		}
	}

	switch p.Node().GrammarName() {
	case "contentStatement":
		preBuilder.StatementType = builder.CONTENT_STATEMENT
	case "identifierStatement":
		preBuilder.StatementType = builder.IDENTIFIER_STATEMENT
	case "blockStatement":
		preBuilder.StatementType = builder.BLOCK_STATEMENT
	case "overrideStatement":
		preBuilder.StatementType = builder.OVERRIDE_STATEMENT
	case "languageStatement":
		preBuilder.StatementType = builder.LANGUAGE_STATEMENT
	case "constantStatement":
		preBuilder.StatementType = builder.CONSTANT_STATEMENT
	default:
		return errors.New("invalid statement type " + p.Node().GrammarName())
	}

	p.PushBuilder(p.Build().(builder.Builder))

	return nil
}

func (p *Parser) parseInternalStatement() {

}
