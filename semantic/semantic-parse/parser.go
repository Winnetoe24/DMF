package semantic_parse

import (
	"errors"
	dmf_lang "github.com/Winnetoe24/DMF/grammar/dmf_language"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"slices"
)

var errorQuery *tree_sitter.Query

func init() {
	query, queryError := dmf_lang.Query("(ERROR)")
	if queryError != nil {
		panic(queryError)
	}
	errorQuery = query
}

func Parse(text []byte, tree *tree_sitter.Tree) (smodel.Model, []errElement.ErrorElement, error) {

	cursor := tree.Walk()
	if cursor == nil {
		return smodel.Model{}, nil, errors.New("kein Cursor erstellt")
	}

	context := SemanticContext{
		ErrorElements: make([]errElement.ErrorElement, 0, 50),
		Model:         smodel.Model{},
		Text:          text,
		Cursor:        cursor,
	}
	//dmf_lang.ForEachQuery(errorQuery, tree, func(_ uint, node *tree_sitter.Node) bool {
	//	context.ErrorElements = append(context.ErrorElements, errElement.CreateErrorElement(node, errors.New("Syntax Error")))
	//	return false
	//})
	context.parseSourceFile()
	return context.Model, context.ErrorElements, nil
}

func (S *SemanticContext) parseSourceFile() {
	//node := S.Cursor.Node()

	//errorElement := assertNodeState(node, "oberste Node")
	//if errorElement != nil {
	//	S.ErrorElements = append(S.ErrorElements, *errorElement)
	//	return
	//}

	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("keine DMF Deklaration vorhanden")))
		return
	}
	S.parseDmfDeclaration()

	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("keine Model Deklaration vorhanden")))
		return
	}
	S.parseModelDeclaration()

	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("keine Model Content vorhanden")))
		return
	}
	// TODO Import Statement
	//S.parseImportStatements()
	S.parseModelContent()

}

func (S *SemanticContext) parseDmfDeclaration() {
	node := S.Cursor.Node()

	errorElement := assertNodeState(node, "DMF Declaration Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return
	}
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("keine DMF Deklaration vorhanden")))
		return
	}
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("keine DMF Version vorhanden")))
		return
	}

	version, errorEle := S.parseVersion()
	S.Cursor.GotoParent()
	S.ErrorElements = append(S.ErrorElements, errorEle...)

	if len(version) != 3 {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("kein gültiges Versionsformat")))
	} else {
		if version[0] != 1 ||
			version[1] != 0 ||
			version[2] != 0 {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("nicht Unterstützte DMF Version")))
		}
	}
	S.Model.DMFVersion = version

}

func (S *SemanticContext) parseModelDeclaration() {
	node := S.Cursor.Node()
	errorElement := assertNodeState(node, "Model Declaration Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return
	}

	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("keine Model Deklaration vorhanden")))
		return
	}
	defer S.Cursor.GotoParent()
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("kein Modellname vorhanden")))
		return
	}
	value, element := S.parseStringValue()
	if element != nil {
		S.ErrorElements = append(S.ErrorElements, *element)
	}
	S.Model.Name = value.Value

	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("die Modelldeklaration ist unvollständig")))
		return
	}

	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("keine Model Version vorhanden")))
		return
	}
	version, errorEle := S.parseVersion()

	S.ErrorElements = append(S.ErrorElements, errorEle...)
	S.Model.Version = version

}

func (S *SemanticContext) parseImportStatements() {
	node := S.Cursor.Node()
	if node.GrammarName() != "import_block" {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New(node.GrammarName())))
		return
	}
	errorElement := assertNodeState(node, "Import Block Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return
	}
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("kein Import Statement vorhanden")))
		return
	}
	defer func() {
		S.Cursor.GotoParent()
		S.Cursor.GotoNextSibling()
	}()

	if S.Cursor.Node() == nil {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Node is nil before for")))
	}
	for {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New(S.Cursor.Node().GrammarName())))
		statement, element := S.parseImportStatement()
		if element != nil {
			S.ErrorElements = append(S.ErrorElements, *element)
		} else {
			if statement.Node == nil {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Node is nil")))
			} else {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(statement.Node, errors.New("Node is not nil")))
				S.Model.ImportStatements = append(S.Model.ImportStatements, statement)
			}
		}
		if !S.Cursor.GotoNextSibling() {
			break
		}
	}
}

func (S *SemanticContext) parseImportStatement() (smodel.ImportStatement, *errElement.ErrorElement) {
	node := S.Cursor.Node()
	if node == nil {
		return smodel.ImportStatement{}, errElement.CreateErrorElementRef(node, errors.New("Node ist nil vor Parse"))
	}
	errorElement := assertNodeState(node, "Import Statement Node")
	if errorElement != nil {
		return smodel.ImportStatement{}, errorElement
	}
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return smodel.ImportStatement{}, errElement.CreateErrorElementRef(node, errors.New("kein Package String vorhanden"))
	}
	defer S.Cursor.GotoParent()
	data := smodel.ImportStatement{
		ModelElement: base.ModelElement{
			Node: node,
		},
	}
	packagePath, _, element := S.parsePackageString(make(base.ModelPath, 0), false)
	if element != nil {
		return smodel.ImportStatement{}, errorElement
	}
	data.Package = packagePath

	nextSibling := S.Cursor.GotoNextSibling()
	if !nextSibling {
		return smodel.ImportStatement{}, errElement.CreateErrorElementRef(node, errors.New("Import Statement unvollständig"))
	}

	nextSibling = S.Cursor.GotoNextSibling()
	if !nextSibling {
		return smodel.ImportStatement{}, errElement.CreateErrorElementRef(node, errors.New("kein Dateiname vorhanden"))
	}
	value, errorElement := S.parseStringValue()
	if errorElement != nil {
		return smodel.ImportStatement{}, errorElement
	}
	data.FileName = value

	// modelIdentifier der Optional ist
	nextSibling = S.Cursor.GotoNextSibling()
	if !nextSibling {
		return data, nil
	}

	identifier, errorElement := S.parseModelIdentifier()
	if errorElement != nil {
		return smodel.ImportStatement{}, errorElement
	}
	data.ModelName = &identifier

	return data, nil
}

func (S *SemanticContext) parseModelIdentifier() (values.StringValue, *errElement.ErrorElement) {
	node := S.Cursor.Node()

	errorElement := assertNodeState(node, "Model EntityIdentifier Node")
	if errorElement != nil {
		return values.StringValue{}, errorElement
	}
	// (
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return values.StringValue{}, errElement.CreateErrorElementRef(node, errors.New("kein ( vorhanden"))
	}
	defer S.Cursor.GotoParent()

	// model
	nextSibling := S.Cursor.GotoNextSibling()
	if !nextSibling {
		return values.StringValue{}, errElement.CreateErrorElementRef(node, errors.New("Model EntityIdentifier unvollständig"))
	}

	// StringValue
	nextSibling = S.Cursor.GotoNextSibling()
	if !nextSibling {
		return values.StringValue{}, errElement.CreateErrorElementRef(node, errors.New("Model EntityIdentifier unvollständig"))
	}

	return S.parseStringValue()
}
func (S *SemanticContext) parseModelContent() {
	node := S.Cursor.Node()

	errorElement := assertNodeState(node, "Model Content Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return
	}
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("kein Model Content vorhanden")))
		return
	}
	defer S.Cursor.GotoParent()

	for {
		content, e := S.parsePackageContent(make(base.ModelPath, 0))
		if e != nil {
			S.ErrorElements = append(S.ErrorElements, *e)
		} else {
			if content.GetType() != base.PACKAGE {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("alle Elemente müssen Packages untergeordnet sein")))
			} else {
				S.Model.Packages = append(S.Model.Packages, *content.(*packages.Package))
			}
		}
		if !S.Cursor.GotoNextSibling() {
			break
		}
	}
}

func (S *SemanticContext) parsePackageContent(current base.ModelPath) (packages.PackageElement, *errElement.ErrorElement) {
	node := S.Cursor.Node()
	errorElement := assertNodeState(node, "Package Content Node")
	if errorElement != nil {
		return &base.PackageElement{}, errorElement
	}

	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return &base.PackageElement{}, errElement.CreateErrorElementRef(node, errors.New("kein Inhalt im Package"))
	}
	defer S.Cursor.GotoParent()
	var comment base.Comment
	expand := false

	for {
		switch S.Cursor.Node().Kind() {
		case dmf_lang.COMMENT_BLOCK:
			comment, errorElement = S.ParseComment()
			if errorElement != nil {
				return &base.PackageElement{}, errorElement
			}
		case "expand":
			expand = true
		case dmf_lang.PACKAGE_BLOCK:
			packageBlock := S.parsePackageBlock(slices.Clone(current), &comment, expand)
			return &packageBlock, nil
		case dmf_lang.STRUCT_BLOCK:
			structBlock, _ := S.parseStructBlock(slices.Clone(current), &comment, expand, false)
			return &structBlock, nil
		case dmf_lang.ENTITY_BLOCK:
			entityBlock := S.parseEntityBlock(slices.Clone(current), &comment, expand)
			return &entityBlock, nil
		case dmf_lang.INTERFACE_BLOCK:
			interfaceBlock := S.parseInterfaceBlock(slices.Clone(current), &comment, expand)
			return &interfaceBlock, nil
		case dmf_lang.ENUM_BLOCK:
			enumBlock := S.parseEnumBlock(slices.Clone(current), &comment, expand)
			return &enumBlock, nil
		}
		if !S.Cursor.GotoNextSibling() {
			break
		}
	}

	return nil, errElement.CreateErrorElementRef(node, errors.New("kein Inhalt im Package:"+S.Cursor.Node().Kind()))

}

func (S *SemanticContext) parsePackageBlock(current base.ModelPath, comment *base.Comment, expand bool) packages.Package {
	node := S.Cursor.Node()
	p := packages.Package{
		PackageElement: base.PackageElement{
			ModelElement: base.ModelElement{
				Kommentar: comment,
				Node:      node,
			},
			Path:   current,
			Expand: expand,
		},
		Elements: nil,
	}
	errorElement := assertNodeState(node, "Package Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}

	// 'package'
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("package Keyword fehlt")))
		return p
	}
	defer S.Cursor.GotoParent()

	// Package String
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("kein Package GetName vorhanden")))
	}
	packageString, elementIdentifier, errorElement := S.parsePackageString(current, false)
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}
	p.Path = packageString
	p.Identifier = elementIdentifier

	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("kein Package Body vorhanden")))
	}

	// Elements in Package
	for S.Cursor.GotoNextSibling() {
		if S.Cursor.Node().Kind() != dmf_lang.PACKAGE_CONTENT {
			continue
		}
		content, e := S.parsePackageContent(packageString)
		if e != nil {
			S.ErrorElements = append(S.ErrorElements, *e)
		} else {
			p.Elements = append(p.Elements, content)
		}
	}

	return p
}

func (S *SemanticContext) parseStructBlock(current base.ModelPath, comment *base.Comment, expand bool, entity bool) (packages.StructElement, *packages.EntityIdentifier) {
	cursor := S.Cursor
	node := cursor.Node()

	structElement := packages.StructElement{
		PackageElement: base.PackageElement{
			ModelElement: base.ModelElement{
				Kommentar: comment,
				Node:      node,
			},
			Path:   nil,
			Expand: expand,
		},
		ExtendsPath:     nil,
		ImplementsPaths: nil,
		Argumente:       nil,
		Referenzen:      nil,
		Funktionen:      nil,
	}

	// 'struct'
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("keyword fehlt")))
		return structElement, nil
	}
	defer cursor.GotoParent()

	// identifier
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("kein Struct EntityIdentifier vorhanden")))
		return structElement, nil
	}
	structElement.Identifier = S.parseIdentifier()
	structElement.Path = append(current, structElement.Identifier.Name)

	// extends
	hasNextSibling = cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("struct Header unvollständig")))
		return structElement, nil
	}
	extendsPath, errorElement := S.parseExtendsBlock(current)
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	} else if extendsPath != nil {
		structElement.ExtendsPath = &extendsPath
	}

	// implements
	if extendsPath != nil || errorElement != nil {
		hasNextSibling = cursor.GotoNextSibling()
		if !hasNextSibling {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("struct Header unvollständig")))
			return structElement, nil
		}
	}

	block, elements := S.parseImplementsBlock(current)
	if elements != nil {
		S.ErrorElements = append(S.ErrorElements, elements...)
	}
	structElement.ImplementsPaths = block

	// skip to '{'
	if cursor.Node().Kind() != "{" {
		hasNextSibling = cursor.GotoNextSibling()
		if !hasNextSibling {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein {")))
			return structElement, nil
		}
	}

	var identifier *packages.EntityIdentifier
	for cursor.GotoNextSibling() {
		if cursor.Node().Kind() == "}" {
			break
		}
		if cursor.Node().Kind() == dmf_lang.STRUCT_CONTENT {
			S.parseStructContent(current, &structElement)
		} else {
			if entity {
				identifier = S.parseIdentifierStatement()
			} else {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cursor.Node(), errors.New("unbekannte Node"), node))
			}
		}
	}

	return structElement, identifier
}

func (S *SemanticContext) parseStructContent(current base.ModelPath, element *packages.StructElement) {
	cursor := S.Cursor
	node := cursor.Node()
	errorElement := assertNodeState(node, "Struct Content Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return
	}

	// comment?
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt Struct Content")))
	}
	defer cursor.GotoParent()

	var comment base.Comment
	if cursor.Node().Kind() == dmf_lang.COMMENT_BLOCK {
		comment, errorElement = S.ParseComment()
		if errorElement != nil {
			S.ErrorElements = append(S.ErrorElements, *errorElement)
		}

		hasNextSibling := cursor.GotoNextSibling()
		if !hasNextSibling {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt Struct Content")))
			return
		}
	}

	switch cursor.Node().Kind() {
	case dmf_lang.ARG_BLOCK:
		argBlock := S.parseArgBlock(comment)
		element.Argumente = append(element.Argumente, argBlock)
	case dmf_lang.REF_BLOCK:
		refBlock := S.parseRefBlock(current, comment)
		element.Referenzen = append(element.Referenzen, refBlock)
	case dmf_lang.MULTI_BLOCK:
		multiBlock := S.parseMultiBlock(current, comment)
		element.MultiReferenzen = append(element.MultiReferenzen, multiBlock)
	case dmf_lang.FUNC_BLOCK:
		funcBlock := S.parseFuncBlock(current, comment)
		element.Funktionen = append(element.Funktionen, funcBlock)
	}

}

func (S *SemanticContext) parseEntityBlock(current base.ModelPath, comment *base.Comment, expand bool) packages.EntityElement {
	node := S.Cursor.Node()
	block, identifier := S.parseStructBlock(current, comment, expand, true)
	entityElement := packages.EntityElement{
		StructElement: block,
	}
	if identifier == nil {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("entity muss einen EntityIdentifier beinhaltet")))
	} else {
		entityElement.EntityIdentifier = *identifier
	}
	return entityElement
}

func (S *SemanticContext) parseInterfaceBlock(current base.ModelPath, comment *base.Comment, expand bool) packages.InterfaceElement {
	cursor := S.Cursor
	node := cursor.Node()

	interfaceElement := packages.InterfaceElement{
		PackageElement: base.PackageElement{
			ModelElement: base.ModelElement{
				Kommentar: comment,
				Node:      node,
			},
			Expand: expand,
		},
	}

	// 'interface'
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("keyword fehlt")))
		return interfaceElement
	}
	defer cursor.GotoParent()

	// identifier
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("kein Interface EntityIdentifier vorhanden")))
		return interfaceElement
	}
	interfaceElement.Identifier = S.parseIdentifier()
	interfaceElement.Path = append(current, interfaceElement.Identifier.Name)

	// implements
	hasNextSibling = cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("interface Header unvollständig")))
		return interfaceElement
	}
	block, elements := S.parseImplementsBlock(current)
	if elements != nil {
		S.ErrorElements = append(S.ErrorElements, elements...)
	}
	interfaceElement.ImplementsPaths = block

	// skip to '{'
	if cursor.Node().Kind() != "{" {
		hasNextSibling = cursor.GotoNextSibling()
		if !hasNextSibling {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein {")))
			return interfaceElement
		}
	}

	for cursor.GotoNextSibling() {
		if cursor.Node().Kind() == "}" {
			break
		}
		if cursor.Node().Kind() == dmf_lang.INTERFACE_CONTENT {
			S.parseInterfaceContent(current, &interfaceElement)
		} else {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cursor.Node(), errors.New("unbekannte Node"), node))
		}
	}
	return interfaceElement
}

func (S *SemanticContext) parseInterfaceContent(current base.ModelPath, element *packages.InterfaceElement) {
	cursor := S.Cursor
	node := cursor.Node()
	errorElement := assertNodeState(node, "Interface Content Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return
	}

	// comment?
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt Interface Content")))
	}
	defer cursor.GotoParent()

	var comment base.Comment
	if cursor.Node().Kind() == dmf_lang.COMMENT_BLOCK {
		comment, errorElement = S.ParseComment()
		if errorElement != nil {
			S.ErrorElements = append(S.ErrorElements, *errorElement)
		}

		hasNextSibling := cursor.GotoNextSibling()
		if !hasNextSibling {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt Interface Content")))
			return
		}
	}

	funcBlock := S.parseFuncBlock(current, comment)
	element.Funktionen = append(element.Funktionen, funcBlock)
	//
	//hasNextSibling := cursor.GotoNextSibling()
	//if !hasNextSibling {
	//	S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein Semikolon")))
	//	return
	//}
	//errorElement = assertNodeState(cursor.Node(), "Semikolon")
	//if errorElement != nil {
	//	S.ErrorElements = append(S.ErrorElements, *errorElement)
	//}
}

func (S *SemanticContext) parseEnumBlock(current base.ModelPath, comment *base.Comment, expand bool) packages.EnumElement {
	cursor := S.Cursor
	node := cursor.Node()

	enumElement := packages.EnumElement{
		PackageElement: base.PackageElement{
			ModelElement: base.ModelElement{
				Kommentar: comment,
				Node:      node,
			},
			Expand: expand,
		},
	}

	// 'enum'
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("keyword fehlt")))
		return enumElement
	}
	defer cursor.GotoParent()

	// identifier
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("kein Interface EntityIdentifier vorhanden")))
		return enumElement
	}
	enumElement.Identifier = S.parseIdentifier()
	enumElement.Path = append(current, enumElement.Identifier.Name)

	// '{'
	hasNextSibling = cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("kein { vorhanden")))
		return enumElement
	}

	for cursor.GotoNextSibling() {
		if cursor.Node().Kind() == "}" {
			break
		}
		if cursor.Node().Kind() == dmf_lang.ENUM_CONTENT {
			S.parseEnumContent(&enumElement)
		} else {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cursor.Node(), errors.New(cursor.Node().Kind()+" unbekannte Node"), node))
		}
	}
	return enumElement
}

func (S *SemanticContext) parseEnumContent(element *packages.EnumElement) {
	cursor := S.Cursor
	node := cursor.Node()
	errorElement := assertNodeState(node, "Enum Content Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return
	}

	// comment?
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt Enum Content")))
	}
	defer cursor.GotoParent()

	var comment base.Comment
	if cursor.Node().Kind() == dmf_lang.COMMENT_BLOCK {
		comment, errorElement = S.ParseComment()
		if errorElement != nil {
			S.ErrorElements = append(S.ErrorElements, *errorElement)
		}

		hasNextSibling := cursor.GotoNextSibling()
		if !hasNextSibling {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt Enum Content")))
			return
		}
	}

	// arg or const
	switch cursor.Node().Kind() {
	case dmf_lang.ARG_BLOCK:
		argBlock := S.parseArgBlock(comment)
		element.Argumente = append(element.Argumente, argBlock)
	case dmf_lang.ENUM_CONSTANT:
		konstante := S.parseEnumConstant(comment)
		element.Konstanten = append(element.Konstanten, konstante)
	}

	//hasNextSibling := cursor.GotoNextSibling()
	//if !hasNextSibling {
	//	S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein Semikolon")))
	//	return
	//}
	//errorElement = assertNodeState(cursor.Node(), "Semikolon")
	//if errorElement != nil {
	//	S.ErrorElements = append(S.ErrorElements, *errorElement)
	//}
}

//TODO Fehler von Enum ausgeben
