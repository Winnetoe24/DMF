package err_element

import (
	"fmt"
	"github.com/tree-sitter/go-tree-sitter"
	"strings"
)

type ErrorContext struct {
	Dateiname   string `json:"dateiname"`
	Dateiinhalt []byte `json:"dateiinhalt"`
}

type ErrorElement struct {
	Fehler FehlerStelle
	Error  error
	// Falls es einen Grund gibt, weshalb ein Fehler aufgetreten ist und dieser Grund an einer anderen Stelle des Codes liegt
	Cause    *FehlerStelle
	rendered *string
}

type FehlerStelle struct {
	// Die Node von der, der ModelCode stammt, und die ein Parent von der eigentlichen Node ist.
	// Ist nil, wenn der ModelCode von der eigentlichen Node kommt
	ContextNode *tree_sitter.Node
	ModelCode   string
	Node        *tree_sitter.Node
}

func (f *FehlerStelle) render(ctx *ErrorContext) {
	if f.ContextNode != nil {
		f.ModelCode = f.ContextNode.Utf8Text(ctx.Dateiinhalt)
	} else if f.Node != nil {
		f.ModelCode = f.Node.Utf8Text(ctx.Dateiinhalt)
	}
}

func (e ErrorElement) ToErrorMsg(ctx *ErrorContext) string {
	if e.rendered != nil {
		return *e.rendered
	}
	var offsetStart int
	var offsetEnd int
	if e.Fehler.ContextNode != nil {
		offsetStart = int(e.Fehler.Node.StartPosition().Column - e.Fehler.ContextNode.StartPosition().Column)
		if e.Fehler.ContextNode.EndPosition().Row == e.Fehler.Node.EndPosition().Row && e.Fehler.Node.StartPosition().Row == e.Fehler.Node.EndPosition().Row {
			offsetEnd = int(e.Fehler.ContextNode.EndPosition().Column - e.Fehler.Node.EndPosition().Column)
		}
	}
	e.Fehler.render(ctx)

	underline := strings.Repeat(" ", offsetStart) + strings.Repeat("^", len(e.Fehler.ModelCode)-offsetStart-offsetEnd) + strings.Repeat(" ", offsetEnd)
	render := fmt.Sprintf("FehlerStelle in Position %v:%v:%v\n%s\n%s\n%v\n", ctx.Dateiname, e.Fehler.Node.StartPosition().Row+1, e.Fehler.Node.StartPosition().Column, e.Fehler.ModelCode, underline, e.Error)
	if e.Cause != nil {
		e.Cause.render(ctx)
		render += fmt.Sprintf("=> Grund (%v:%v:%v):\n%s\n", ctx.Dateiname, e.Cause.Node.StartPosition().Row+1, e.Cause.Node.StartPosition().Column, "    "+strings.ReplaceAll(e.Cause.ModelCode, "\n", "\n    "))
	}
	e.rendered = &render
	return render
}

type ErrorCapable interface {
	GetAllErrorElements() []ErrorElement
}
