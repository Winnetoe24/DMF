package service

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
)

type MethodHandler interface {
	Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult)
	GetMethods() []string
	HandleMethod(message protokoll.Message)
	//TODO Edit Capabilities
}
