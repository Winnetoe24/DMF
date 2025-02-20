package semantic_parse

import (
	"errors"
	dmf_lang "github.com/Winnetoe24/DMF/grammar/dmf_language"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
)

func (S *SemanticContext) parseOverride() *base.Override {
	cursor := S.Cursor
	node := cursor.Node()
	errorElement := assertNodeState(node, "Override Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return nil
	}
	// 'grammar'
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt das Keyword grammar")))
	}
	defer cursor.GotoParent()

	// {
	sibling := cursor.GotoNextSibling()
	if !sibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(cursor.Node(), errors.New("es fehlt }")))
	}

	sibling = cursor.GotoNextSibling()
	if !sibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(cursor.Node(), errors.New("es fehlt }")))
	}
	override := base.Override{}
	for sibling {
		switch cursor.Node().Kind() {
		case dmf_lang.JAVA_OVERRIDE:
			if override.JavaOverride != nil {
				S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(cursor.Node(), errors.New("Overrides dürfen nur einmal vorkommen")))
			} else {
				override.JavaOverride = S.parseJavaOverride()
			}
		case "}":
			return &override
		}
		sibling = cursor.GotoNextSibling()
	}

	S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(cursor.Node(), errors.New("es fehlt }")))

	return &override
}

func (S *SemanticContext) parseJavaOverride() *base.JavaOverride {
	cursor := S.Cursor
	node := cursor.Node()
	errorElement := assertNodeState(node, "Java Override Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return nil
	}

	// java_override
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt java")))
	}
	defer cursor.GotoParent()
	// java
	sibling := cursor.GotoNextSibling()
	if !sibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(cursor.Node(), errors.New("es fehlt {")))
	}
	// {
	sibling = cursor.GotoNextSibling()
	if !sibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(cursor.Node(), errors.New("es fehlt {")))
	}
	override := base.JavaOverride{}
	for sibling {
		switch cursor.Node().Kind() {
		case dmf_lang.JAVA_CLASS:
			value := S.parseOverrideValue()
			override.Class = value
		case dmf_lang.JAVA_EXTENDS:
			value := S.parseOverrideValue()
			override.Extends = value
		case dmf_lang.JAVA_ANNOTATION:
			value := S.parseOverrideValue()
			override.Annotations = value
		case dmf_lang.JAVA_NAME:
			value := S.parseOverrideValue()
			override.Name = value
		case dmf_lang.JAVA_IMPLEMENTS:
			value := S.parseOverrideValue()
			override.Implements = value
		case dmf_lang.JAVA_DOC:
			value := S.parseOverrideValue()
			override.JavaDoc = value
		case dmf_lang.JAVA_TYPE:
			value := S.parseOverrideValue()
			override.Type = value
		case "}":
			return &override

		default:
			S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(cursor.Node(), errors.New("Unbekannter Override: "+S.Cursor.Node().GrammarName())))
		}
		sibling = cursor.GotoNextSibling()
	}

	return &override
}

func (S *SemanticContext) parseOverrideValue() *base.StringValue {
	cursor := S.Cursor
	node := cursor.Node()
	errorElement := assertNodeState(node, "Override Value Node")
	if errorElement != nil {
		S.ErrorElements = append(S.ErrorElements, *errorElement)
		return nil
	}

	// Name
	hasFirstChild := cursor.GotoFirstChild()
	if !hasFirstChild {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(node, errors.New("es fehlt der Name der Überschriebenen Konfiguration")))
		return nil
	}
	defer cursor.GotoParent()

	// StringValue
	sibling := cursor.GotoNextSibling()
	if !sibling {
		S.ErrorElements = append(S.ErrorElements, errElement.CreateErrorElement(cursor.Node(), errors.New("es fehlt der Wert")))
		return nil
	}

	value, element := S.parseStringValue()
	if element != nil {
		S.ErrorElements = append(S.ErrorElements, *element)
	}
	return &value
}
