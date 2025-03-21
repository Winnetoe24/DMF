package semantic_parse

import (
	"errors"
	dmf_lang "github.com/Winnetoe24/DMF/grammar/dmf_language"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"slices"
)

var errorQuery *tree_sitter.Query

func init() {
	//query, queryError := dmf_lang.Query("(ERROR)")
	//if queryError != nil {
	//	panic(queryError)
	//}
	//errorQuery = query
}

func Parse(text []byte, tree *tree_sitter.Tree,
	parseFile func(statement smodel.ImportStatement) (smodel.TypeLookUp, *errElement.ErrorElement)) (smodel.Model, []errElement.ErrorElement, error) {

	cursor := tree.Walk()
	if cursor == nil {
		return smodel.Model{}, nil, errors.New("kein Cursor erstellt")
	}

	context := SemanticContext{
		ErrorElements: make([]errElement.ErrorElement, 0, 50),
		Model:         smodel.Model{},
		Text:          text,
		Cursor:        cursor,
		ImportLookUp:  make(smodel.TypeLookUp),
		ParseFile:     parseFile,
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
	S.parseImportStatements()
	for _, statement := range S.Model.ImportStatements {
		S.handleImport(&statement)
	}
	S.parseModelContent()

}

func (S *SemanticContext) handleImport(statement *smodel.ImportStatement) {
	lookUp, elements := S.ParseFile(*statement)
	if elements != nil {
		S.ErrorElements = append(S.ErrorElements, *elements)
		statement.ImportFailed = true
		return
	}
	packageElement, found := lookUp[statement.Package.ToString()]
	if !found {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(statement.Node, errors.New("Das importierte Package konnte in der referenzierten Datei nicht gefunden werden.")))
		return
	}
	if packageElement.GetType() != base.PACKAGE {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(statement.Node, errors.New("Das importierte Element ist kein Package.")))
		return
	}
	S.addPackageToImportLookUp(statement, packageElement.(*packages.Package))
}

func (S *SemanticContext) addPackageToImportLookUp(statement *smodel.ImportStatement, p *packages.Package) {
	_, found := S.ImportLookUp[p.Path.ToString()]
	if found {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(statement.Node, errors.New("Duplicate Import")))
		return
	}
	S.ImportLookUp[p.Path.ToString()] = p

	for _, element := range p.Elements {
		switch element := element.(type) {
		case *packages.Package:
			S.addPackageToImportLookUp(statement, element)
		default:
			_, found := S.ImportLookUp[element.GetBase().Path.ToString()]
			if found {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(statement.Node, errors.New("Duplicate Import")))
			}
			S.ImportLookUp[element.GetBase().Path.ToString()] = element
		}
	}
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
		//S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New(node.GrammarName()+node.Parent().GrammarName())))
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
		//S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New(S.Cursor.Node().GrammarName())))
		statement, element := S.parseImportStatement()
		if element != nil {
			S.ErrorElements = append(S.ErrorElements, *element)
		} else {
			S.Model.ImportStatements = append(S.Model.ImportStatements, statement)
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
		Package:  nil,
		FileName: base.StringValue{},
	}

	S.Cursor.GotoNextSibling()
	packagePath, _, element := S.parsePackageString(make(base.ModelPath, 0), false)
	if element != nil {
		return smodel.ImportStatement{}, element
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

	if data.Node == nil {
		return smodel.ImportStatement{}, errElement.CreateErrorElementRef(node, errors.New("Data.Node is nil"))
	}
	return data, nil
}

func (S *SemanticContext) parseModelIdentifier() (base.StringValue, *errElement.ErrorElement) {
	node := S.Cursor.Node()

	errorElement := assertNodeState(node, "Model EntityIdentifier Node")
	if errorElement != nil {
		return base.StringValue{}, errorElement
	}
	// (
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return base.StringValue{}, errElement.CreateErrorElementRef(node, errors.New("kein ( vorhanden"))
	}
	defer S.Cursor.GotoParent()

	// model
	nextSibling := S.Cursor.GotoNextSibling()
	if !nextSibling {
		return base.StringValue{}, errElement.CreateErrorElementRef(node, errors.New("Model EntityIdentifier unvollständig"))
	}

	// StringValue
	nextSibling = S.Cursor.GotoNextSibling()
	if !nextSibling {
		return base.StringValue{}, errElement.CreateErrorElementRef(node, errors.New("Model EntityIdentifier unvollständig"))
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
	var packageElement packages.PackageElement
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
			packageElement = &packageBlock
		case dmf_lang.STRUCT_BLOCK:
			structBlock, _ := S.parseStructBlock(slices.Clone(current), &comment, expand, false)
			packageElement = &structBlock
		case dmf_lang.ENTITY_BLOCK:
			entityBlock := S.parseEntityBlock(slices.Clone(current), &comment, expand)
			packageElement = &entityBlock
		case dmf_lang.INTERFACE_BLOCK:
			interfaceBlock := S.parseInterfaceBlock(slices.Clone(current), &comment, expand)
			packageElement = &interfaceBlock
		case dmf_lang.ENUM_BLOCK:
			enumBlock := S.parseEnumBlock(slices.Clone(current), &comment, expand)
			packageElement = &enumBlock
		case dmf_lang.OVERRIDE_BLOCK:
			override := S.parseOverride()
			if packageElement != nil {
				packageElement.GetBase().Override = override
			} else {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("Override ohne PackageElement")))
			}
		default:
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("unbekanntes Element: "+S.Cursor.Node().GrammarName())))

		}
		if !S.Cursor.GotoNextSibling() {
			break
		}
	}
	if packageElement != nil {
		return packageElement, nil
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
	var importedPackage *packages.Package
	if expand {
		element, found := S.ImportLookUp[packageString.ToString()]
		if !found {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(p.Node, errors.New("Erweitertes Element nicht gefunden")))
		} else {
			switch element := element.(type) {
			case *packages.Package:
				importedPackage = element
			default:
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(p.Node, errors.New("Erweitertes Element ist kein Package")))
			}
		}

	}
	if importedPackage != nil {
		if p.Kommentar == nil {
			p.Kommentar = importedPackage.Kommentar
		}
	}

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
	if importedPackage != nil {
		elementsToAdd := make([]packages.PackageElement, 0)
	ImportedElementsLoop:
		for _, element := range importedPackage.Elements {
			for _, packageElement := range p.Elements {
				if packageElement.GetBase().Path.Equals(element.GetBase().Path) {
					if !packageElement.GetBase().Expand {
						S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(packageElement.GetBase().Node, errors.New("erweitertes Element ohne Expand Keyword")))
					}
					continue ImportedElementsLoop
				}
			}
			elementsToAdd = append(elementsToAdd, element)
		}
		p.Elements = append(p.Elements, elementsToAdd...)
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
	structElement.Identifier = S.parseIdentifier(false)
	structElement.Path = append(current, structElement.Identifier.Name)

	var identifier *packages.EntityIdentifier
	if expand {
		element, found := S.ImportLookUp[structElement.Path.ToString()]
		if !found {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Erweitertes Element nicht gefunden")))
		} else {
			var importedStructElement *packages.StructElement
			var importedEntityIdentifier *packages.EntityIdentifier
			switch element := element.(type) {
			case *packages.EntityElement:
				if entity {
					importedStructElement = &element.StructElement
					importedEntityIdentifier = &element.EntityIdentifier
				} else {
					S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Erweitertes Element ist eine Entity und kein Struct")))
				}
			case *packages.StructElement:
				if !entity {
					importedStructElement = element
				} else {
					S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Erweitertes Element ist ein Struct und keine Entity")))
				}
			default:
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Erweitertes Element ist kein Struct")))
			}

			if importedStructElement != nil {
				structElement.NamedElements = importedStructElement.NamedElements
				if structElement.Kommentar == nil {
					structElement.Kommentar = importedStructElement.Kommentar
				}
				structElement.Override = importedStructElement.Override
				structElement.ExtendsPath = importedStructElement.ExtendsPath
				structElement.ImplementsPaths = importedStructElement.ImplementsPaths
				structElement.Argumente = importedStructElement.Argumente
				structElement.Referenzen = importedStructElement.Referenzen
				structElement.MultiReferenzen = importedStructElement.MultiReferenzen
				structElement.Funktionen = importedStructElement.Funktionen
			}

			identifier = importedEntityIdentifier
		}
	}

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
		if structElement.ExtendsPath == nil {
			structElement.ExtendsPath = &extendsPath
		} else {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("Es darf keine Abstraktion festgelegt werden, wenn schon im importierten Modell eine festgelegt wurde.")))
		}
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
	structElement.ImplementsPaths = append(structElement.ImplementsPaths, block...)

	// skip to '{'
	if cursor.Node().Kind() != "{" {
		hasNextSibling = cursor.GotoNextSibling()
		if !hasNextSibling {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein {")))
			return structElement, nil
		}
	}

	for cursor.GotoNextSibling() {
		kind := cursor.Node().Kind()
		n := cursor.Node()
		child := n.Child(0)
		if kind == "}" {
			break
		}
		if kind == dmf_lang.STRUCT_CONTENT || child.Kind() == "ref" || child.Kind() == "arg" || child.Kind() == "func" {
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
	var errorElement *errElement.ErrorElement
	//errorElement := assertNodeState(node, "Struct Content Node")
	//if errorElement != nil {
	//	S.ErrorElements = append(S.ErrorElements, *errorElement)
	//	return
	//}
	if !node.IsError() {
		// comment?
		hasFirstChild := cursor.GotoFirstChild()
		if !hasFirstChild {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt Struct Content")))
		}
		defer cursor.GotoParent()

	}

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

	//Error Kompensation
	contentNode := cursor.Node()
	kind := contentNode.Kind()
	if kind == "ERROR" && contentNode.ChildCount() > 0 {
		child := contentNode.Child(0)
		switch child.Kind() {
		case dmf_lang.ARG:
			kind = dmf_lang.ARG_BLOCK
		case dmf_lang.FUNC:
			kind = dmf_lang.FUNC
		case dmf_lang.REF:
			if contentNode.ChildCount() < 2 {
				kind = dmf_lang.REF_BLOCK
			} else {
				typeNode := contentNode.Child(1)
				if typeNode.Kind() == dmf_lang.MULTI_NAME {
					kind = dmf_lang.MULTI_BLOCK
				} else {
					kind = dmf_lang.REF_BLOCK
				}
			}
		}
	}
	switch kind {
	case dmf_lang.ARG_BLOCK:
		argBlock := S.parseArgBlock(comment)
		if cursor.GotoNextSibling() {
			override := S.parseOverride()
			argBlock.Override = override
		}
		element.Argumente = append(element.Argumente, argBlock)
	case dmf_lang.REF_BLOCK:
		refBlock := S.parseRefBlock(current, comment)
		if refBlock != nil {
			refBlock := *refBlock
			if cursor.GotoNextSibling() {
				override := S.parseOverride()
				refBlock.Override = override
			}
			element.Referenzen = append(element.Referenzen, refBlock)
		}

	case dmf_lang.MULTI_BLOCK:
		multiBlock := S.parseMultiBlock(current, comment)
		if cursor.GotoNextSibling() {
			override := S.parseOverride()
			multiBlock.Override = override
		}
		element.MultiReferenzen = append(element.MultiReferenzen, multiBlock)
	case dmf_lang.FUNC_BLOCK:
		funcBlock := S.parseFuncBlock(current, comment)
		if funcBlock != nil {
			funcBlock := *funcBlock
			if cursor.GotoNextSibling() {
				override := S.parseOverride()
				funcBlock.Override = override
			}
			element.Funktionen = append(element.Funktionen, funcBlock)
		}
	default:
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Unbekannter Struct Content: "+kind)))

	}

	//// Override
	//if cursor.GotoNextSibling() {
	//	override := S.parseOverride()
	//	if modelElement == nil {
	//		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Override ohne Element")))
	//	} else {
	//		modelElement.Override = override
	//	}
	//
	//}

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
	interfaceElement.Identifier = S.parseIdentifier(false)
	interfaceElement.Path = append(current, interfaceElement.Identifier.Name)

	if expand {
		element, found := S.ImportLookUp[interfaceElement.Path.ToString()]
		if !found {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Erweitertes Element nicht gefunden")))
		} else {
			switch element := element.(type) {
			case *packages.InterfaceElement:
				interfaceElement.NamedElements = element.NamedElements
				if interfaceElement.Kommentar == nil {
					interfaceElement.Kommentar = element.Kommentar
				}
				interfaceElement.Override = element.Override
				interfaceElement.ImplementsPaths = element.ImplementsPaths
				interfaceElement.Funktionen = element.Funktionen
			default:
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Erweitertes Element ist kein Interface")))
			}
		}
	}
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
	if funcBlock != nil {
		funcBlock := *funcBlock
		if cursor.GotoNextSibling() {
			override := S.parseOverride()
			funcBlock.Override = override
		}
		element.Funktionen = append(element.Funktionen, funcBlock)
	}

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
	enumElement.Identifier = S.parseIdentifier(false)
	enumElement.Path = append(current, enumElement.Identifier.Name)

	if expand {
		element, found := S.ImportLookUp[enumElement.Path.ToString()]
		if !found {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Erweitertes Element nicht gefunden")))
		} else {
			switch element := element.(type) {
			case *packages.EnumElement:
				enumElement.NamedElements = element.NamedElements
				if enumElement.Kommentar == nil {
					enumElement.Kommentar = element.Kommentar
				}
				enumElement.Override = element.Override
				enumElement.Argumente = element.Argumente
				enumElement.Konstanten = element.Konstanten
			default:
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("Erweitertes Element ist kein Enum")))
			}
		}
	}
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
		if cursor.GotoNextSibling() {
			override := S.parseOverride()
			argBlock.Override = override
		}
		element.Argumente = append(element.Argumente, argBlock)
	case dmf_lang.ENUM_CONSTANT:
		konstante := S.parseEnumConstant(comment)
		if cursor.GotoNextSibling() {
			override := S.parseOverride()
			konstante.Override = override
		}
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
