package semantic_parse

import (
	"errors"
	"fmt"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/builder"
	util "github.com/Winnetoe24/DMF/semantic/semantic-parse/parse_util"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
)

func (p *Parser) parseDMF() error {
	node := p.Node()

	errorElement := util.AssertNodeState(node, "DMF Statement")
	if p.AddErrorElement(errorElement) {
		return ERROR_ADDED
	}

	if !p.GoToFirstChild() {
		p.AddErrorElement(util.CreateMissingElementError(node, "dmf keyword"))
		return ERROR_ADDED
	}

	// DMF Version
	if !p.GoToNextSibling() {
		p.AddErrorElement(util.CreateMissingElementError(node, "dmf version"))
		return ERROR_ADDED
	}
	version, err := p.parseVersion()
	if err != nil {
		return err
	}
	if version[0] != 2 ||
		version[1] != 0 ||
		version[2] != 0 {
		p.AddErrorElement(errElement.CreateErrorElementRef(p.Node(), errors.New("unsupported DMF version")))
		return ERROR_ADDED
	}

	modelBuilder, ok := p.currentBuilder.(*builder.ModelBuilder)
	if !ok {
		return errors.New(fmt.Sprintf("current builder is not ModelBuilder: %+v", p.currentBuilder))
	}

	modelBuilder.DMFVersion = version

	return nil
}

func (p *Parser) parseModel() error {
	node := p.Node()

	errorElement := util.AssertNodeState(node, "Model Statement")
	if p.AddErrorElement(errorElement) {
		return ERROR_ADDED
	}
	if !p.GoToFirstChild() {
		p.AddErrorElement(util.CreateMissingElementError(node, "model statement"))
		return ERROR_ADDED
	}

	// ModelName
	if !p.GoToNextSibling() {
		p.AddErrorElement(util.CreateMissingElementError(node, "model name"))
		return ERROR_ADDED
	}
	modelName, err := p.parseString()
	if err != nil {
		return err
	}

	modelBuilder, ok := p.currentBuilder.(*builder.ModelBuilder)
	if !ok {
		return errors.New(fmt.Sprintf("current builder is not ModelBuilder: %+v", p.currentBuilder))
	}

	modelBuilder.ModelName = modelName

	// version keyword
	if !p.GoToNextSibling() {
		p.AddErrorElement(util.CreateMissingElementError(node, "model version"))
		return ERROR_ADDED
	}

	// version
	if !p.GoToNextSibling() {
		p.AddErrorElement(util.CreateMissingElementError(node, "model version"))
		return ERROR_ADDED
	}
	version, err := p.parseVersion()
	if err != nil {
		return err
	}
	modelBuilder.ModelVersion = version

	return nil

}

func (p *Parser) parseVersion() ([]int32, error) {
	node := p.Node()
	errorElement := util.AssertNodeState(node, "DMF Statement")
	if p.AddErrorElement(errorElement) {
		return nil, ERROR_ADDED
	}

	var version []int32
	var err error = nil

	for i, child := range node.Children(p.context.Cursor.Copy()) {
		if i == 0 || i == 2 || i == 4 {
			node.GrammarName()
			number, errNumber := p.parseNumber(&child)
			if errNumber != nil {
				err = errNumber
				version = append(version, 0)
			} else {
				version = append(version, number)
			}
		}
		if i > 4 {
			p.AddErrorElement(errElement.CreateErrorElementRef(&child, errors.New("zu Viele Versions Elemente")))
		}
	}
	if version == nil {
		p.AddErrorElement(errElement.CreateErrorElementRef(node, errors.New("keine Version angegeben")))
		return nil, ERROR_ADDED
	}

	if err != nil {
		return nil, ERROR_ADDED
	}

	return version, nil
}
