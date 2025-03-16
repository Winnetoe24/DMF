package ignore

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"slices"
)

const SetTrace string = "$/setTrace"

var knownServices []string = []string{SetTrace}

type IgnoreService struct {
	Methods []string `json:"methods"`
}

func CreateIgnoreService(methods []string) *IgnoreService {
	for _, method := range methods {
		if !slices.Contains(knownServices, method) {
			panic("unknown method: " + method)
		}
	}
	return &IgnoreService{Methods: methods}
}

func (i *IgnoreService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {
}

func (i *IgnoreService) GetMethods() []string {
	return i.Methods
}

func (i *IgnoreService) HandleMethod(message protokoll.Message) {
	switch message.Method {
	case SetTrace:

	}
}
