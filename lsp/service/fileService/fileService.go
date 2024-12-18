package fileService

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll/textEdit"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
)

var logger = logService.GetLogger("File Service")

type FileService struct {
	//mapMutex  sync.RWMutex
	handleMap map[string]fileHandle
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
