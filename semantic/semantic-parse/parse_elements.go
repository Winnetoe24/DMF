package semantic_parse

import (
	"errors"
	"github.com/Winnetoe24/DMF/grammar/dmf_language"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"strings"

	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
)

func (S *SemanticContext) parseIdentifier(errorMode bool) base.ElementIdentifier {
	identifierNode := S.Cursor.Node()
	identifierName := identifierNode.Utf8Text(S.Text)

	if errorMode {
		index := strings.Index(identifierName, " ")
		if index >= 0 {
			identifierName = identifierName[:index]
			identifierName = strings.Trim(identifierName, " ")
		}
	} else {
		errorElement := assertNodeState(identifierNode, "Identifier Node")
		if errorElement != nil {
			S.ErrorElements = append(S.ErrorElements, *errorElement)
		}
	}

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
	errorElement := assertNodeState(extendsNode, "ExtendsPath Block Node")
	if errorElement != nil {
		return nil, errorElement
	}

	// 'extends'
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return nil, errElement.CreateErrorElementRef(extendsNode, errors.New("extends Keyword fehlt"))
	}
	defer S.Cursor.GotoParent()

	// refTyp
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		return nil, errElement.CreateErrorElementRef(extendsNode, errors.New("kein Referenzierter Typ"))
	}
	return S.ParseRefType(current)
}

func (S *SemanticContext) parseImplementsBlock(current base.ModelPath) ([]base.ModelPath, []errElement.ErrorElement) {
	implementsNode := S.Cursor.Node()
	if implementsNode.Kind() != dmf_language.IMPLEMENTS_BLOCK {
		return nil, nil
	}

	// 'implements'
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return nil, []errElement.ErrorElement{errElement.CreateErrorElement(implementsNode, errors.New("implements Keyword fehlt"))}
	}
	defer S.Cursor.GotoParent()

	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		return nil, []errElement.ErrorElement{errElement.CreateErrorElement(implementsNode, errors.New("keine Implementierte Typen vorhanden"))}
	}
	implementierteTypen := make([]base.ModelPath, 0)
	errorsElemente := make([]errElement.ErrorElement, 0)

	refType, elementError := S.ParseRefType(current)
	if elementError != nil {
		errorsElemente = append(errorsElemente, *elementError)
	} else {
		implementierteTypen = append(implementierteTypen, refType)
	}

	// War letzte Node comma?
	commaMode := false

	for S.Cursor.GotoNextSibling() {
		if commaMode {
			refType, elementError := S.ParseRefType(current)
			implementierteTypen = append(implementierteTypen, refType)
			if elementError != nil {
				errorsElemente = append(errorsElemente, *elementError)
			}
			commaMode = false
		} else {
			elementError = assertNodeState(S.Cursor.Node(), "Comma Node")
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

	errorElement := assertNodeState(node, "Arg Block Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return arg
	}

	// 'arg'
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("arg Keyword fehlt")))
		return arg
	}
	defer S.Cursor.GotoParent()
	errorElement = assertNodeStateGrammar(S.Cursor.Node(), "arg", dmf_language.ARG)
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return arg
	}

	// type
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein Primitive Type")))
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
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein EntityIdentifier")))
		return arg
	}
	arg.Name = S.parseIdentifier(false)
	identifierNode := S.Cursor.Node()

	// Semikolon
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein Semikolon")))
		return arg
	}
	errorElement = assertNodeStateGrammar(S.Cursor.Node(), "Semikolon", ";")
	if errorElement != nil {
		//S.ErrorElements = append(S.ErrorElements, *errorElement)
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(identifierNode, errors.New("es fehlt ein Semikolon")))
	}
	//S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New(S.Cursor.Node().GrammarName())))

	return arg
}

func (S *SemanticContext) parseRefBlock(current base.ModelPath, comment base.Comment) *packages.Referenz {
	node := S.Cursor.Node()
	referenz := packages.Referenz{
		ModelElement: base.ModelElement{
			Kommentar: &comment,
			Node:      node,
		},
		Typ:  nil,
		Name: base.ElementIdentifier{},
	}

	var errorElement *errElement.ErrorElement
	//errorElement := assertNodeState(node, "Ref Block Node")
	//if errorElement != nil {
	//	S.ErrorElements = append(S.ErrorElements, *errorElement)
	//	return nil
	//}

	// 'ref'
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("ref Keyword fehlt")))
		return nil
	}
	defer S.Cursor.GotoParent()
	if S.Cursor.Node().Kind() != dmf_language.REF {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("ref Keyword fehlt")))
		return nil
	}
	errorElement = assertNodeState(S.Cursor.Node(), "Ref Keyword Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return nil
	}

	// type
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein Referenz Typ")))
		return nil
	}
	refType, element := S.ParseRefType(current)
	if element != nil {
		S.ErrorElements = append(S.ErrorElements, *element)
		return nil
	} else {
		referenz.Typ = refType
	}

	// identifier
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein EntityIdentifier")))
		return nil
	}
	if strings.HasPrefix(S.Cursor.Node().Utf8Text(S.Text), " ") {
		errorElement = assertNodeState(S.Cursor.Node(), "Referenz Identifier Node")
	} else {
		errorElement = assertNodeState(S.Cursor.Node(), "Referenz Type Node")
	}
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		referenz.Name = S.parseIdentifier(true)
		return &referenz
	} else {
		referenz.Name = S.parseIdentifier(false)
	}

	// Semikolon
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein Semikolon")))
	}
	errorElement = assertNodeState(S.Cursor.Node(), "Semikolon")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}
	return &referenz
}

func (S *SemanticContext) parseMultiBlock(current base.ModelPath, comment base.Comment) packages.MultiReferenz {
	node := S.Cursor.Node()
	referenz := packages.MultiReferenz{
		ModelElement: base.ModelElement{
			Kommentar: &comment,
			Node:      node,
		},
		Name: base.ElementIdentifier{},
	}

	errorElement := assertNodeState(node, "Ref Block Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return referenz
	}

	// 'ref'
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("ref Keyword fehlt")))
		return referenz
	}
	defer S.Cursor.GotoParent()
	errorElement = assertNodeState(S.Cursor.Node(), "Ref Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}

	// MultiReferenzType
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein Multi Referenz Typ")))
		return referenz
	}
	multiType, element := S.parseMultiReferenzTyp()
	if element != nil {
		S.ErrorElements = append(S.ErrorElements, *element)
	} else {
		referenz.Typ = multiType
	}

	// '<'
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein <")))
		return referenz
	}
	errorElement = assertNodeState(S.Cursor.Node(), "<")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}

	// Generic Type
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein Generic Referenz Typ")))
		return referenz
	}
	S.parseGeneric(current, &referenz.Generics[0])

	// is , oder >
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein >")))
		return referenz
	}

	// ,
	if S.Cursor.Node().GrammarName() != ">" {
		errorElement = assertNodeState(S.Cursor.Node(), ",")
		if errorElement != nil {
			S.ErrorElements = append(S.ErrorElements, *errorElement)
		}

		hasNextSibling = S.Cursor.GotoNextSibling()
		if !hasNextSibling {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein Generic Referenz Typ")))
			return referenz
		}
		S.parseGeneric(current, &referenz.Generics[1])

		hasNextSibling = S.Cursor.GotoNextSibling()
		if !hasNextSibling {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein >")))
			return referenz
		}

		if S.Cursor.Node().GrammarName() != ">" {
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein > (Zu viele Generics)")))
			return referenz
		}
	}

	// >
	errorElement = assertNodeState(S.Cursor.Node(), ">")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}

	// identifier
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(S.Cursor.Node(), errors.New("es fehlt ein EntityIdentifier")))
		return referenz
	}
	referenz.Name = S.parseIdentifier(false)

	// Semikolon
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein Semikolon")))
		return referenz
	}
	errorElement = assertNodeState(S.Cursor.Node(), "Semikolon")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}

	return referenz
}

func (S *SemanticContext) parseGeneric(current base.ModelPath, genericType *packages.MultiType) {
	errorElement := assertNodeState(S.Cursor.Node(), "Generic Type")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}
	if S.Cursor.Node().GrammarName() == dmf_language.PRIMITIVE_TYPE {
		primitiveType, element := S.parsePrimitiveType()
		if element != nil {
			S.ErrorElements = append(S.ErrorElements, *element)
		} else {
			genericType.PrimitivType = &primitiveType
		}
	} else {
		refType, element := S.ParseRefType(current)
		if element != nil {
			S.ErrorElements = append(S.ErrorElements, *element)
		} else {
			genericType.ModelPath = &refType
		}
	}
}

func (S *SemanticContext) parseMultiReferenzTyp() (packages.MultiReferenzType, *errElement.ErrorElement) {
	node := S.Cursor.Node()
	errorElement := assertNodeState(node, "Ref Block Node")
	if errorElement != nil {
		return "", errorElement
	}

	text := node.Utf8Text(S.Text)
	switch text {
	case string(packages.MAP):
		return packages.MAP, nil
	case string(packages.SET):
		return packages.SET, nil
	case string(packages.LIST):
		return packages.LIST, nil
	default:
		return "", errElement.CreateErrorElementRef(node, errors.New("Unbekannter Multi Referenz Typ"))
	}
}

func (S *SemanticContext) parseFuncBlock(current base.ModelPath, comment base.Comment) *packages.Funktion {
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

	errorElement := assertNodeState(node, "Funktion Block Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return nil
	}

	// 'func'
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(cursor.Node(), errors.New("func Keyword fehlt")))
		return nil
	}
	defer cursor.GotoParent()

	// Return Type
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(cursor.Node(), errors.New("return-Type fehlt")))
		return nil
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
		if referenz == nil {
			return nil
		}
		funktion.ReturnType = referenz
	default:
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cursor.Node(), errors.New("return-Type ungültig"), node))
		return nil
	}

	// Funktion GetName
	hasNextSibling = cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("GetName fehlt")))
		return nil
	}
	funktion.Name = S.parseIdentifier(false)

	// '('
	hasNextSibling = cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("'(' fehlt")))
		return nil
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
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cursor.Node(), errors.New("es dürfen keine 2 Kommas hintereinander vorkommen"), node))
			}
			commaMode = !commaMode
		default:
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cursor.Node(), errors.New(cursor.Node().Kind()+" ungültiger Parameter"), node))
		}
	}

	if !closedParameter {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cursor.Node(), errors.New("parameter nicht beendet. ')' fehlt"), node))
	}

	// Semikolon
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein Semikolon")))
		return nil
	}
	errorElement = assertNodeState(S.Cursor.Node(), "Semikolon")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}

	return &funktion
}

func (S *SemanticContext) parseReferenz(current base.ModelPath) *packages.Referenz {
	refType, element := S.ParseRefType(current)
	if element != nil {
		S.ErrorElements = append(S.ErrorElements, *element)
		return nil
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
		sErrors = append(sErrors, errElement.CreateErrorElementCxt(cursor.Node(), errors.New("type fehlt"), node))
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
		sErrors = append(sErrors, errElement.CreateErrorElement(node, errors.New(cursor.Node().Kind()+" ist kein gültiger Parameter Typ")))
		return nil, sErrors
	}

	// EntityIdentifier
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		sErrors = append(sErrors, errElement.CreateErrorElement(node, errors.New("GetName fehlt")))
		return nil, sErrors
	}

	identifier := S.parseIdentifier(false)
	cVar.SetName(identifier)
	return cVar, sErrors
}

func (S *SemanticContext) parseIdentifierStatement() *packages.EntityIdentifier {
	cursor := S.Cursor
	node := cursor.Node()

	state := assertNodeState(node, "EntityIdentifier Statement Node")
	if state != nil {
		return nil
	}
	iden := &packages.EntityIdentifier{
		ModelElement: base.ModelElement{
			Node: node,
		},
	}
	// 'identifier'
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("identifier fehlt")))
		return iden
	}
	defer cursor.GotoParent()

	// '('
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("( fehlt")))
		return iden
	}

	commaMode := false
IdentifierLoop:
	for cursor.GotoNextSibling() {
		cNode := cursor.Node()
		switch cNode.Kind() {
		case dmf_language.IDENTIFIER:
			identifier := S.parseIdentifier(false)
			iden.Variablen = append(iden.Variablen, identifier)
			commaMode = false
		case ",":
			if commaMode {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cNode, errors.New("kein zweites komma erlaubt"), node))
			}
			commaMode = true
		case ")":
			break IdentifierLoop
		default:
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cNode, errors.New("unbekanntes Element"), node))
		}
	}

	// Semikolon
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein Semikolon")))
		return iden
	}
	errorElement := assertNodeState(S.Cursor.Node(), "Semikolon")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
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
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("identifier fehlt")))
		return konstante
	}
	defer cursor.GotoParent()

	konstante.Name = S.parseIdentifier(false)

	// '('
	hasNextSibling := cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("( fehlt")))
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
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cNode, errors.New("kein zweites komma erlaubt"), node))
			}
			commaMode = true
		case ")":
			break ValueLoop
		default:
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElementCxt(cNode, errors.New("unbekanntes Element"), node))
		}
	}

	// Semikolon
	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt ein Semikolon")))
		return konstante
	}
	errorElement := assertNodeState(S.Cursor.Node(), "Semikolon")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
	}

	return konstante
}
