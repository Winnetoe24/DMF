package fileService

import (
	"encoding/json"
	"errors"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/protokoll/textEdit"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

const didOpenMethod = "textDocument/didOpen"
const didChangeMethod = "textDocument/didChange"
const didCloseMethod = "textDocument/didClose"

var logger = logService.GetLogger()
var _ service.MethodHandler = &FileService{}

type FileService struct {
	mapActionChannel chan func()
	handleMap        map[string]*fileHandle
	listeners        []FileChangeListener
	con              connect.Connection
}

func NewFileService(con connect.Connection, listeners ...FileChangeListener) *FileService {
	if listeners == nil {
		listeners = make([]FileChangeListener, 0)
	}
	logService.GetLogger().Printf("%sFileChangeListeners: %+v\n", logService.TRACE, listeners)
	return &FileService{
		mapActionChannel: createActionChannel(),
		handleMap:        make(map[string]*fileHandle),
		listeners:        listeners,
		con:              con,
	}
}

func createActionChannel() chan func() {
	c := make(chan func(), 5)
	go func() {
		for f := range c {
			f()
		}
	}()
	return c
}

func (receiver *FileService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {
	result.Capabilities.TextDocumentSync = textEdit.TextDocumentSyncOptions{
		OpenClose: true,
		Change:    textEdit.TextDocumentSyncKindIncremental,
	}
}

func (receiver *FileService) HandleMethod(message protokoll.Message) {
	switch message.Method {
	case didOpenMethod:
		params := textEdit.DidOpenTextDocumentParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(receiver.con, message.ID, err, protokoll.ParseError)
			return
		}
		receiver.OpenFile(params)
	case didChangeMethod:
		params := textEdit.DidChangeTextDocumentParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(receiver.con, message.ID, err, protokoll.ParseError)
			return
		}
		receiver.EditFile(params)
	case didCloseMethod:
		params := textEdit.DidCloseTextDocumentParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(receiver.con, message.ID, err, protokoll.ParseError)
			return
		}
		receiver.mapActionChannel <- func() {
			handle, found := receiver.handleMap[string(params.TextDocument.URI)]
			if found {
				handle.Ast.Close()
			}
			delete(receiver.handleMap, string(params.TextDocument.URI))
		}
	}
}

func (receiver *FileService) GetMethods() []string {
	return []string{didOpenMethod, didChangeMethod, didCloseMethod}
}

func (receiver *FileService) OpenFile(params textEdit.DidOpenTextDocumentParams) {

	receiver.mapActionChannel <- func() {
		_, found := receiver.handleMap[string(params.TextDocument.URI)]

		if !found {
			logger.Printf("%sCreate FileHandle for %v\n", logService.TRACE, params.TextDocument.URI)
			handle, err := openFileHandle(params, receiver.listeners)
			if err != nil {
				logger.Printf("%sError Creating FileHandle for %v: %e\n", logService.ERROR, params.TextDocument.URI, err)
			} else {
				receiver.handleMap[string(params.TextDocument.URI)] = &handle
			}
		} else {
			logger.Panicf("%sFileHandle for opened file(%v) arleady exists!\n", logService.ERROR, params.TextDocument.URI)
		}
	}

}

func (receiver *FileService) EditFile(params textEdit.DidChangeTextDocumentParams) {
	receiver.mapActionChannel <- func() {
		handle, found := receiver.handleMap[string(params.TextDocument.URI)]

		if found {
			logger.Printf("%sEdit File for %v\n", logService.TRACE, params.TextDocument.URI)
			err := handle.editFileHandle(params, receiver.listeners)
			if err != nil {
				logger.Printf("%sError Editing FileHandle for %v: %e\n", logService.ERROR, params.TextDocument.URI, err)
			}
		} else {
			logger.Panicf("%sFileHandle for file(%v) doesn't exists!\n", logService.ERROR, params.TextDocument.URI)
		}
	}
}

type FileContent struct {
	Content string `json:"content"`
	Ast     *tree_sitter.Tree
	Model   smodel.Model
	LookUp  smodel.TypeLookUp
	Version int `json:"version"`
}

func (f FileContent) Close() {
	f.Ast.Close()
}

func (receiver *FileService) GetFileContent(uri protokoll.DocumentURI) (FileContent, error) {
	returnChannel := make(chan struct {
		FileContent
		error
	})
	defer close(returnChannel)
	receiver.mapActionChannel <- func() {
		handle, found := receiver.handleMap[string(uri)]

		if found {
			returnChannel <- struct {
				FileContent
				error
			}{FileContent: handle.ToContent(), error: nil}
		} else {
			logger.Printf("%sFileHandle for file(%v) doesn't exists!\n", logService.ERROR, uri)
			returnChannel <- struct {
				FileContent
				error
			}{FileContent: FileContent{}, error: errors.New("file is unknown")}
		}
	}
	ret := <-returnChannel
	return ret.FileContent, ret.error
}
