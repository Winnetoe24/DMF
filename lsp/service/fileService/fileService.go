package fileService

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/protokoll/textEdit"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
)

var logger = logService.GetLogger()
var _ service.MethodHandler = &FileService{}

type FileService struct {
	//mapMutex  sync.RWMutex
	handleMap map[string]fileHandle
	con       connect.Connection
}

func NewFileService(con connect.Connection) *FileService {
	return &FileService{
		handleMap: make(map[string]fileHandle),
		con:       con,
	}
}

func (receiver *FileService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {
	result.Capabilities.TextDocumentSync = textEdit.TextDocumentSyncOptions{
		OpenClose: true,
		Change:    textEdit.TextDocumentSyncKindIncremental,
	}
}

func (receiver *FileService) HandleMethod(message protokoll.Message) {
	switch message.Method {
	case "textDocument/didOpen":
		params := textEdit.DidOpenTextDocumentParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(receiver.con, message.ID, err, protokoll.ParseError)
			return
		}
		receiver.OpenFile(params)
	}
}

func (receiver *FileService) GetMethods() []string {
	return []string{"textDocument/didOpen"}
}

func (receiver *FileService) OpenFile(params textEdit.DidOpenTextDocumentParams) {

	_, found := receiver.handleMap[string(params.TextDocument.URI)]

	if !found {
		logger.Printf("%sCreate FileHandle for %v\n", logService.TRACE, params.TextDocument.URI)
		handle, err := openFileHandle(params)
		if err != nil {
			logger.Printf("%sError Creating FileHandle for %v: %e\n", logService.ERROR, params.TextDocument.URI, err)
		} else {
			receiver.handleMap[string(params.TextDocument.URI)] = handle
		}
	} else {
		logger.Panicf("%sFileHandle for opened file(%v) arleady exists!\n", logService.ERROR, params.TextDocument.URI)
	}
}

func (receiver *FileService) EditFile(params textEdit.DidChangeTextDocumentParams) {
	handle, found := receiver.handleMap[string(params.TextDocument.URI)]

	if found {
		logger.Printf("%sEdit File for %v\n", logService.TRACE, params.TextDocument.URI)
		handle.EditFile(params)
	} else {
		logger.Panicf("%sFileHandle for file(%v) doesn't exists!\n", logService.ERROR, params.TextDocument.URI)
	}
}
