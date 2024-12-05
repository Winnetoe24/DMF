package semantic_parse

import (
	"errors"
	"github.com/Winnetoe24/DMF/grammar/dmf_language"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"

	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
)

func (S *SemanticContext) parseIdentifier() base.ElementIdentifier {
	identifierNode := S.Cursor.Node()
	errorElement := assertNodeState(S.Text, identifierNode, "Identifier Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}
	identifierName := identifierNode.Utf8Text(S.Text)
	return base.ElementIdentifier{
		ModelElement: base.ModelElement{
			Node: identifierNode,
		},
		Name: identifierName,
	}
}

func (S *SemanticContext) parseExtendsBlock(current base.ModelPath) (base.ModelPath, *errElement.ErrorElement) {
	extendsNode := S.Cursor.Node()
	if extendsNode.Kind() != dmf_language.EXTENDS_BLOCK {
		return nil, nil
	}
	errorElement := assertNodeState(S.Text, extendsNode, "ExtendsPath Block Node")
	if errorElement != nil {
		return nil, errorElement
	}

	// 'extends'
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return nil, errElement.CreateErrorElementRef(S.Text, extendsNode, errors.New("extends Keyword fehlt"))
	}
	defer S.Cursor.GotoParent()

	// refTyp
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		return nil, errElement.CreateErrorElementRef(S.Text, extendsNode, errors.New("kein Referenzierter Typ"))
	}
	return S.parseRefType(current)
}

func (S *SemanticContext) parseImplementsBlock(current base.ModelPath) ([]base.ModelPath, []errElement.ErrorElement) {
	implementsNode := S.Cursor.Node()
	if implementsNode.Kind() != dmf_language.IMPLEMENTS_BLOCK {
		return nil, nil
	}

	// 'implements'
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return nil, []errElement.ErrorElement{errElement.CreateErrorElement(S.Text, implementsNode, errors.New("implements Keyword fehlt"))}
	}
	defer S.Cursor.GotoParent()

	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		return nil, []errElement.ErrorElement{errElement.CreateErrorElement(S.Text, implementsNode, errors.New("keine Implementierte Typen vorhanden"))}
	}
	implementierteTypen := make([]base.ModelPath, 0)
	errorsElemente := make([]errElement.ErrorElement, 0)

	refType, elementError := S.parseRefType(current)
	if elementError != nil {
		errorsElemente = append(errorsElemente, *elementError)
	} else {
		implementierteTypen = append(implementierteTypen, refType)
	}

	// War letzte Node comma?
	commaMode := false

	for S.Cursor.GotoNextSibling() {
		if commaMode {
			refType, elementError := S.parseRefType(current)
			implementierteTypen = append(implementierteTypen, refType)
			if elementError != nil {
				errorsElemente = append(errorsElemente, *elementError)
			}
			commaMode = false
		} else {
			elementError = assertNodeState(S.Text, S.Cursor.Node(), "Comma Node")
			if elementError != nil {
				errorsElemente = append(errorsElemente, *elementError)
			}
			commaMode = true
		}
	}

	return implementierteTypen, errorsElemente
}

func (S *SemanticContext) parseArgBlock(comment base.Comment) packages.Argument {
	node := S.Cursor.Node()
	arg := packages.Argument{
		ModelElement: base.ModelElement{
			Kommentar: &comment,
			Node:      node,
		},
		Typ:  "",
		Name: base.ElementIdentifier{},
	}

	errorElement := assertNodeState(S.Text, node, "Arg Block Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return arg
	}

	// 'arg'
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, S.Cursor.Node(), errors.New("arg Keyword fehlt")))
		return arg
	}
	defer S.Cursor.GotoParent()

	// type
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, S.Cursor.Node(), errors.New("es fehlt ein Primitive Type")))
		return arg
	}
	primitiveType, element := S.parsePrimitiveType()
	if element != nil {
		S.ErrorElements = append(S.ErrorElements, *element)
	} else {
		arg.Typ = primitiveType
	}

	// identifier
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, S.Cursor.Node(), errors.New("es fehlt ein Identifier")))
		return arg
	}
	arg.Name = S.parseIdentifier()

	return arg
}

func (S *SemanticContext) parseRefBlock(current base.ModelPath, comment base.Comment) packages.Referenz {
	node := S.Cursor.Node()
	referenz := packages.Referenz{
		ModelElement: base.ModelElement{
			Kommentar: &comment,
			Node:      node,
		},
		Typ:  nil,
		Name: base.ElementIdentifier{},
	}

	errorElement := assertNodeState(S.Text, node, "Ref Block Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return referenz
	}

	// 'ref'
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, S.Cursor.Node(), errors.New("ref Keyword fehlt")))
		return referenz
	}
	defer S.Cursor.GotoParent()

	// type
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, S.Cursor.Node(), errors.New("es fehlt ein Referenz Typ")))
		return referenz
	}
	refType, element := S.parseRefType(current)
	if element != nil {
		S.ErrorElements = append(S.ErrorElements, *element)
	} else {
		referenz.Typ = refType
	}

	// identifier
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, S.Cursor.Node(), errors.New("es fehlt ein Identifier")))
		return referenz
	}
	referenz.Name = S.parseIdentifier()

	return referenz
}

func (S *SemanticContext) parseFuncBlock(current base.ModelPath, comment base.Comment) packages.Funktion {
	cursor := S.Cursor
	node := cursor.Node()
	funktion := packages.Funktion{
		ModelElement: base.ModelElement{
			Kommentar: &comment,
			Node:      node,
		},
		Name:       base.ElementIdentifier{},
		ReturnType: nil,
		Parameter:  nil,
	}

	errorElement := assertNodeState(S.Text, node, "Funktion Block Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return funktion
	}

	// 'func'
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, cursor.Node(), errors.New("func Keyword fehlt")))
		return funktion
	}
	defer cursor.GotoParent()

	// Return Type
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, cursor.Node(), errors.New("return-Type fehlt")))
		return funktion
	}
	switch cursor.Node().Kind() {
	case dmf_language.VOID:
		funktion.ReturnType = packages.VoidElement{
			ModelElement: base.ModelElement{
				Kommentar: nil,
				Node:      cursor.Node(),
			},
		}
	case dmf_language.PRIMITIVE_TYPE:
		funktion.ReturnType = S.parseArgument()
	case dmf_language.REFTYPE:
		referenz := S.parseReferenz(current)
		funktion.ReturnType = referenz
	default:
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(S.Text, cursor.Node(), errors.New("return-Type ungültig"), node))
	}

	// Funktion Name
	hasNextSibling = cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, node, errors.New("Name fehlt")))
		return funktion
	}
	funktion.Name = S.parseIdentifier()

	// '('
	hasNextSibling = cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, node, errors.New("'(' fehlt")))
		return funktion
	}

	commaMode := false
	closedParameter := false
ParameterSchleife:
	for cursor.GotoNextSibling() {
		switch cursor.Node().Kind() {
		case ")":
			closedParameter = true
			break ParameterSchleife
		case dmf_language.PARAM_DEFINITION:
			definition, elements := S.parseParameterDefinition(current)
			if elements != nil {
				S.ErrorElements = append(S.ErrorElements, elements...)
			}
			funktion.Parameter = append(funktion.Parameter, definition)
			commaMode = false
		case ",":
			if commaMode {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(S.Text, cursor.Node(), errors.New("es dürfen keine 2 Kommas hintereinander vorkommen"), node))
			}
			commaMode = !commaMode
		default:
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(S.Text, cursor.Node(), errors.New(cursor.Node().Kind()+" ungültiger Parameter"), node))
		}
	}

	if !closedParameter {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(S.Text, cursor.Node(), errors.New("parameter nicht beendet. ')' fehlt"), node))
	}

	return funktion
}

func (S *SemanticContext) parseReferenz(current base.ModelPath) *packages.Referenz {
	refType, element := S.parseRefType(current)
	if element != nil {
		S.ErrorElements = append(S.ErrorElements, *element)
	}
	referenz := packages.Referenz{
		ModelElement: base.ModelElement{
			Kommentar: nil,
			Node:      S.Cursor.Node(),
		},
		Typ:  refType,
		Name: base.ElementIdentifier{},
	}
	return &referenz
}

func (S *SemanticContext) parseArgument() *packages.Argument {
	primitiveType, element := S.parsePrimitiveType()
	if element != nil {
		S.ErrorElements = append(S.ErrorElements, *element)
	}
	return &packages.Argument{
		ModelElement: base.ModelElement{
			Kommentar: nil,
			Node:      S.Cursor.Node(),
		},
		Typ:  primitiveType,
		Name: base.ElementIdentifier{},
	}
}

func (S *SemanticContext) parseParameterDefinition(current base.ModelPath) (packages.Variable, []errElement.ErrorElement) {
	cursor := S.Cursor
	node := cursor.Node()
	var sErrors []errElement.ErrorElement
	// type
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		sErrors = append(sErrors, errElement.CreateErrorElementCxt(S.Text, cursor.Node(), errors.New("type fehlt"), node))
		return nil, sErrors
	}
	defer cursor.GotoParent()

	var cVar packages.Variable
	switch cursor.Node().Kind() {
	case dmf_language.PRIMITIVE_TYPE:
		cVar = S.parseArgument()
	case dmf_language.REFTYPE:
		cVar = S.parseReferenz(current)
	default:
		sErrors = append(sErrors, errElement.CreateErrorElement(S.Text, node, errors.New(cursor.Node().Kind()+" ist kein gültiger Parameter Typ")))
		return nil, sErrors
	}

	// Identifier
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		sErrors = append(sErrors, errElement.CreateErrorElement(S.Text, node, errors.New("Name fehlt")))
		return nil, sErrors
	}

	identifier := S.parseIdentifier()
	cVar.SetName(identifier)
	return cVar, sErrors
}

func (S *SemanticContext) parseIdentifierStatement() *packages.Identifier {
	cursor := S.Cursor
	node := cursor.Node()

	state := assertNodeState(S.Text, node, "Identifier Statement Node")
	if state != nil {
		return nil
	}
	iden := &packages.Identifier{
		ModelElement: base.ModelElement{
			Node: node,
		},
	}
	// 'identifier'
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, node, errors.New("identifier fehlt")))
		return iden
	}
	defer cursor.GotoParent()

	// '('
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, node, errors.New("( fehlt")))
		return iden
	}

	commaMode := false
IdentifierLoop:
	for cursor.GotoNextSibling() {
		cNode := cursor.Node()
		switch cNode.Kind() {
		case dmf_language.IDENTIFIER:
			identifier := S.parseIdentifier()
			iden.Variablen = append(iden.Variablen, identifier)
			commaMode = false
		case ",":
			if commaMode {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(S.Text, cNode, errors.New("kein zweites komma erlaubt"), node))
			}
			commaMode = true
		case ")":
			break IdentifierLoop
		default:
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(S.Text, cNode, errors.New("unbekanntes Element"), node))
		}
	}

	return iden

}

func (S *SemanticContext) parseEnumConstant(comment base.Comment) packages.Konstante {
	cursor := S.Cursor
	node := cursor.Node()

	konstante := packages.Konstante{
		ModelElement: base.ModelElement{
			Node:      node,
			Kommentar: &comment,
		},
	}
	// 'identifier'
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, node, errors.New("identifier fehlt")))
		return konstante
	}
	defer cursor.GotoParent()

	konstante.Name = S.parseIdentifier()

	// '('
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Text, node, errors.New("( fehlt")))
		return konstante
	}

	commaMode := false
ValueLoop:
	for cursor.GotoNextSibling() {
		cNode := cursor.Node()
		switch cNode.Kind() {
		case dmf_language.ENUM_INDEX:
			fallthrough
		case dmf_language.PRIMITIVE_VALUE:
			value, element := S.parsePrimitiveValue()
			if element != nil {
				S.ErrorElements = append(S.ErrorElements, *element)
			} else {
				konstante.Values = append(konstante.Values, value)
			}
			commaMode = false
		case ",":
			if commaMode {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(S.Text, cNode, errors.New("kein zweites komma erlaubt"), node))
			}
			commaMode = true
		case ")":
			break ValueLoop
		default:
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(S.Text, cNode, errors.New("unbekanntes Element"), node))
		}
	}

	return konstante
}
