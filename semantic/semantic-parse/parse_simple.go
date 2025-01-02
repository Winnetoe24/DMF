package semantic_parse

import (
	"errors"
	"github.com/Winnetoe24/DMF/grammar/dmf_language"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"
	"github.com/tree-sitter/go-tree-sitter"
	"math"
	"math/big"
	"strconv"
	"strings"
	"time"
)

func (S *SemanticContext) parseVersion() ([]int32, []errElement.ErrorElement) {
	cursor := S.Cursor
	node := cursor.Node()

	errorElement := assertNodeState(node, "Version Node")
	if errorElement != nil {
		return nil, []errElement.ErrorElement{*errorElement}
	}
	var version []int32
	var errorEle []errElement.ErrorElement

	for i, child := range node.Children(cursor.Copy()) {
		if i == 0 || i == 2 || i == 4 {
			number, element := S.parseNumber(&child)
			if element != nil {
				errorEle = append(errorEle, *element)
			} else {
				version = append(version, number)
			}
		}
		if i > 4 {
			errorEle = append(errorEle, errElement.CreateErrorElement(&child, errors.New("zu Viele Versions Elemente")))
		}
	}
	if version == nil {
		errorEle = append(errorEle, errElement.CreateErrorElement(node, errors.New("keine Version angegeben")))
		version = make([]int32, 0)
	}
	return version, errorEle
}

func (S *SemanticContext) parseNumber(node *tree_sitter.Node) (int32, *errElement.ErrorElement) {
	errorElement := assertNodeState(node, "Number Node")
	if errorElement != nil {
		return 0, errorElement
	}
	utf8Text := node.Utf8Text(S.Text)
	i, err := strconv.ParseInt(utf8Text, 10, 32)
	if err != nil {
		return 0, errElement.CreateErrorElementRef(node, err)
	}
	return int32(i), nil
}

func (S *SemanticContext) parsePackageString(current base.ModelPath, dotForCurrent bool) (base.ModelPath, base.ElementIdentifier, *errElement.ErrorElement) {
	cursor := S.Cursor
	node := cursor.Node()
	errorElement := assertNodeState(node, "Package String Node")
	if errorElement != nil {
		return nil, base.ElementIdentifier{}, errorElement
	}
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		return nil, base.ElementIdentifier{}, errElement.CreateErrorElementRef(node, errors.New("keine Elemente im Package String"))
	}
	defer cursor.GotoParent()

	var elementIdentifier base.ElementIdentifier
	neuerPath := append(make([]string, 0), current...)
	for {
		cNode := cursor.Node()
		if cNode.Kind() == dmf_language.DOT {
			if dotForCurrent {
				if len(neuerPath) > 0 {
					neuerPath = neuerPath[:len(neuerPath)-1]
				} else {
					return nil, base.ElementIdentifier{}, errElement.CreateErrorElementCtxRef(cNode, errors.New("es existieren nicht genug Parent packages"), node)
				}
			} else {
				dotForCurrent = true
			}
		} else if cNode.Kind() == dmf_language.IDENTIFIER {
			elementIdentifier = S.parseIdentifier()
			neuerPath = append(neuerPath, elementIdentifier.Name)
			dotForCurrent = false
		} else {
			return nil, base.ElementIdentifier{}, errElement.CreateErrorElementCtxRef(cNode, errors.New("falsche Node"), node)
		}
		if !cursor.GotoNextSibling() {
			break
		}
	}
	return neuerPath, elementIdentifier, nil
}

func (S *SemanticContext) parseStringValue() (values.StringValue, *errElement.ErrorElement) {
	node := S.Cursor.Node()
	errorElement := assertNodeState(node, "String Value Node")
	if errorElement != nil {
		return values.StringValue{}, errorElement
	}
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return values.StringValue{}, nil
	}
	defer S.Cursor.GotoParent()

	var lastValue, value = "", ""

	for {
		hasSibling := S.Cursor.GotoNextSibling()
		if !hasSibling {
			break
		}

		value += lastValue
		lastValue = S.Cursor.Node().Utf8Text(S.Text)
	}
	return values.StringValue{
		ModelElement: base.ModelElement{
			Node: node,
		},
		Value: value,
	}, nil
}

func (S *SemanticContext) parseComment() (base.Comment, *errElement.ErrorElement) {
	cursor := S.Cursor
	node := cursor.Node()
	errorElement := assertNodeState(node, "Comment Block Node")
	if errorElement != nil {
		return nil, errorElement
	}

	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		return make(base.Comment, 0), nil
	}
	defer cursor.GotoParent()
	var comment base.Comment

	for {
		cNode := cursor.Node()
		errorElement := assertNodeState(cNode, "Comment Node")
		if errorElement != nil {
			return nil, errorElement
		}
		commentText := cNode.Utf8Text(S.Text)
		after, _ := strings.CutPrefix(commentText, "//")
		commentContent := strings.TrimLeft(after, " ")
		comment = append(comment, commentContent+"\n")
		if !cursor.GotoNextSibling() {
			break
		}
	}

	return comment, nil
}

func (S *SemanticContext) parseRefType(current base.ModelPath) (base.ModelPath, *errElement.ErrorElement) {
	cursor := S.Cursor
	node := cursor.Node()
	errorElement := assertNodeState(node, "Ref Type Node")
	if errorElement != nil {
		return nil, errorElement
	}
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		return nil, errElement.CreateErrorElementRef(node, errors.New("keine Elemente im Ref Type"))
	}
	defer cursor.GotoParent()

	dotForCurrent := false
	neuerPath := append(make([]string, 0, len(current)), current...)
	cNode := cursor.Node()
	for cNode.Kind() == dmf_language.DOT {
		if !dotForCurrent {
			dotForCurrent = true
		} else {
			if len(neuerPath) > 0 {
				neuerPath = neuerPath[:len(neuerPath)-1]
			} else {
				return nil, errElement.CreateErrorElementCtxRef(cNode, errors.New("es existieren nicht genug Parent packages"), node)
			}
		}

		// goto Package String
		hasNextSibling := cursor.GotoNextSibling()
		if !hasNextSibling {
			return current, nil
		}
		cNode = cursor.Node()
	}

	packageString, _, element := S.parsePackageString(neuerPath, dotForCurrent)
	return packageString, element
}

func (S *SemanticContext) parsePrimitiveType() (base.PrimitivType, *errElement.ErrorElement) {
	node := S.Cursor.Node()
	errorElement := assertNodeState(node, "Primitive Type Node")
	if errorElement != nil {
		return "", errorElement
	}

	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return "", errElement.CreateErrorElementRef(node, errors.New("kein Typ vorhanden"))
	}
	defer S.Cursor.GotoParent()

	primitivType := base.PrimitivType(S.Cursor.Node().Kind())
	switch primitivType {
	case base.STRING:
	case base.DATE:
	//TODO case BYTE:
	case base.INT:
	case base.LONG:
	case base.BOOLEAN:
	case base.DATETIME:
	case base.DOUBLE:
	default:
		return "", errElement.CreateErrorElementCtxRef(node, errors.New(S.Cursor.Node().Kind()+" gehört nicht zu den Primitiven Typen"), node.Parent())
	}
	return primitivType, nil
}

func (S *SemanticContext) parsePrimitiveValue() (values.Value, *errElement.ErrorElement) {
	node := S.Cursor.Node()

	if node.Kind() == dmf_language.ENUM_INDEX {
		return values.IntValue{
			ModelElement: base.ModelElement{
				Node: node,
			},
			Ignored: true,
			Value:   0,
		}, nil
	}
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return nil, errElement.CreateErrorElementRef(node, errors.New("kein Wert vorhanden"))
	}
	defer S.Cursor.GotoParent()

	switch S.Cursor.Node().Kind() {
	case dmf_language.INTEGERVALUE:
		return S.parseIntegerValue()
	case dmf_language.DOUBLEVALUE:
		return S.parseDoubleValue()
	case dmf_language.STRINGVALUE:
		return S.parseStringValue()
	case dmf_language.DATEVALUE:
		dateText := S.Cursor.Node().Utf8Text(S.Text)
		parse, err := time.Parse("D2006-01-02", dateText)
		if err != nil {
			return nil, errElement.CreateErrorElementRef(node, err)
		}
		return values.DateValue{
			ModelElement: base.ModelElement{
				Node: node,
			},
			Value: parse,
		}, nil
	case dmf_language.DATETIMEVALUE:
		dateText := S.Cursor.Node().Utf8Text(S.Text)
		parse, err := time.Parse("D2006-01-02T15:04:05", dateText)
		if err != nil {
			return nil, errElement.CreateErrorElementRef(node, err)
		}
		return values.DateTimeValue{
			ModelElement: base.ModelElement{
				Node: node,
			},
			Value: parse,
		}, nil
	case dmf_language.LONGVALUE:
		return S.parseLongValue()
	case dmf_language.BOOLEANVALUE:
		boolText := S.Cursor.Node().Utf8Text(S.Text)
		parseBool, err := strconv.ParseBool(boolText)
		if err != nil {
			return nil, errElement.CreateErrorElementRef(node, err)
		}
		return values.BooleanValue{
			ModelElement: base.ModelElement{
				Node: node,
			},
			Value: parseBool,
		}, nil

	}
	return nil, errElement.CreateErrorElementRef(node, errors.New("Unbekannter Wert"))
}

func (S *SemanticContext) parseLongValue() (values.LongValue, *errElement.ErrorElement) {
	node := S.Cursor.Node()
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return values.LongValue{}, errElement.CreateErrorElementRef(node, errors.New("keine Nummer vorhanden"))
	}
	defer S.Cursor.GotoParent()

	stringValue, element := S.extractIntegerString()
	defer S.Cursor.GotoParent()
	if element != nil {
		return values.LongValue{}, element
	}
	i := new(big.Int)
	i.SetString(stringValue, 10)
	return values.LongValue{
		ModelElement: base.ModelElement{
			Node: node,
		},
		Value: i,
	}, nil
}
func (S *SemanticContext) parseDoubleValue() (values.DoubleValue, *errElement.ErrorElement) {
	node := S.Cursor.Node()
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return values.DoubleValue{}, errElement.CreateErrorElementRef(node, errors.New("keine Nummer vorhanden"))
	}
	defer S.Cursor.GotoParent()

	value, element := S.parseIntegerValue()
	if element != nil {
		return values.DoubleValue{}, element
	}
	hasNextSibling := S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		return values.DoubleValue{}, errElement.CreateErrorElementRef(node, errors.New("kein . vorhanden"))
	}

	hasNextSibling = S.Cursor.GotoNextSibling()
	if !hasNextSibling {
		return values.DoubleValue{}, errElement.CreateErrorElementRef(node, errors.New("keine Nummer vorhanden"))
	}
	afterPointValue, errorElement := S.parseIntegerValue()
	if errorElement != nil {
		return values.DoubleValue{}, errorElement
	}

	// Convert (int,int) to float
	f := float64(afterPointValue.Value)
	for i := 0.0; i < 100; i++ {
		pow := math.Pow(10, i)
		if f/pow <= 0 {
			return values.DoubleValue{
				ModelElement: base.ModelElement{
					Node: node,
				},
				Value: float64(value.Value) + (f / pow),
			}, nil
		}
	}

	return values.DoubleValue{}, errElement.CreateErrorElementRef(node, errors.New("konnte Integer nicht verarbeiten"))
}

func (S *SemanticContext) parseIntegerValue() (values.IntValue, *errElement.ErrorElement) {
	node := S.Cursor.Node()

	stringValue, element := S.extractIntegerString()
	defer S.Cursor.GotoParent()
	if element != nil {
		return values.IntValue{}, element
	}
	i, err := strconv.ParseInt(stringValue, 10, 64)
	if err != nil {
		return values.IntValue{}, errElement.CreateErrorElementRef(node, errors.New("Text ist keine Zahl"))
	}
	return values.IntValue{
		ModelElement: base.ModelElement{
			Node: node,
		},
		Ignored: false,
		Value:   int(i),
	}, nil
}

// Doesnt Go to Parent!!!
func (S *SemanticContext) extractIntegerString() (string, *errElement.ErrorElement) {
	stringValue := ""
	hasFirstChild := S.Cursor.GotoFirstChild()
	if !hasFirstChild {
		return "", errElement.CreateErrorElementRef(S.Cursor.Node(), errors.New("keine Nummer vorhanden"))
	}

	for {
		if S.Cursor.Node().Kind() == dmf_language.NUMBER {
			stringValue += S.Cursor.Node().Utf8Text(S.Text)
		}
		if !S.Cursor.GotoNextSibling() {
			break
		}
	}
	return stringValue, nil
}
