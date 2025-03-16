package server

import (
	"encoding/json"
	"errors"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/cancelService"
	"github.com/Winnetoe24/DMF/lsp/service/diagnosticsService"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/foldingService"
	"github.com/Winnetoe24/DMF/lsp/service/hoverService"
	"github.com/Winnetoe24/DMF/lsp/service/ignore"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/lsp/service/referenceService"
	"github.com/Winnetoe24/DMF/lsp/service/selectionRangeService"
	semantictokensService "github.com/Winnetoe24/DMF/lsp/service/semanticTokensService"
	"log"
)

type Server struct {
	con       connect.Connection
	methodMap map[string]service.MethodHandler
}

func NewServer(con connect.Connection) *Server {
	s := &Server{con: con, methodMap: make(map[string]service.MethodHandler)}

	newDiagnosticsService := diagnosticsService.NewDiagnosticsService(con)
	s.addHandler(newDiagnosticsService)

	fileServiceHandler := fileService.NewFileService(con, newDiagnosticsService)
	s.addHandler(fileServiceHandler)

	newCancelService := cancelService.NewCancelService(con)
	s.addHandler(newCancelService)

	//completionService := completionService.NewCompletionService(con, fileServiceHandler)
	//s.addHandler(completionService)

	newHoverService := hoverService.NewHoverService(con, fileServiceHandler)
	s.addHandler(newHoverService)

	newReferenceService := referenceService.NewReferenceService(con, fileServiceHandler)
	s.addHandler(newReferenceService)

	newFoldingService := foldingService.NewFoldingService(con, fileServiceHandler)
	s.addHandler(newFoldingService)

	newSemanticTokensService := semantictokensService.NewSemanticTokensService(con, fileServiceHandler)
	s.addHandler(newSemanticTokensService)

	newSelectionRangeService := selectionRangeService.NewSelectionRangeService(con, fileServiceHandler)
	s.addHandler(newSelectionRangeService)

	s.addHandler(ignore.CreateIgnoreService([]string{ignore.SetTrace}))
	return s
}

func (s *Server) addHandler(handler service.MethodHandler) {
	for _, method := range handler.GetMethods() {
		s.methodMap[method] = handler
	}
}

func (s *Server) MessageLoop() {
	logger := logService.GetLogger()

	// Init
	if !s.initialize(logger) {
		//TODO Exit
		return
	}
MessageLoop:
	for {
		if s.nextMethod(logger) {
			break MessageLoop
		}
	}
	err := s.con.Close()
	if err != nil {
		logger.Printf("%sError While Closing Connection: %e\n", logService.ERROR, err)
	}
	logger.Printf("%sServer Closed\n", logService.INFO)
}

func (s *Server) nextMethod(logger *log.Logger) bool {
	message, err := s.con.WaitForMessage()

	if err != nil {
		logger.Printf("%sError While Reading Message: %e\n", logService.ERROR, err)
		return false
	} else {
		// Lifecycle Methods
		switch message.Method {
		case "shutdown":
			logger.Printf("%sReceived Shutdown Request\n", logService.INFO)
			s.con.WriteMessage(protokoll.Message{
				JsonRPC: "2.0",
				ID:      message.ID,
				Method:  "",
				Params:  nil,
				Result:  nil,
				Error:   nil,
			})
			return true
		}
		handler, found := s.methodMap[message.Method]
		if !found {
			logger.Printf("%sMethod not Found: %v\n", logService.ERROR, message)
			connectUtils.WriteErrorToCon(s.con, message.ID, errors.New("method not found"), protokoll.MethodNotFound)
		} else {
			logger.Printf("%sHandle Method: %s \n", logService.INFO, message.Method)
			go handler.HandleMethod(message)
		}
	}
	return false
}

func (s *Server) initialize(logger *log.Logger) bool {
	message, err := s.con.WaitForMessage()
	if err != nil {
		logger.Printf("%sError While Reading initialize Message: %e\n", logService.ERROR, err)
		return false
	}
	if message.Method != "initialize" {
		logger.Printf("%sFirst Message isn't initialize: %v\n", logService.ERROR, message)
		return false
	}
	initializeParams := initialize.InitializeParams{}
	initializeResult := initialize.InitializeResult{
		Capabilities: initialize.ServerCapabilities{},
		ServerInfo: &initialize.ServerInfo{
			Name:    "DMF LSP Server",
			Version: "0.0.1",
		},
	}
	err = json.Unmarshal(message.Params, &initializeParams)
	if err != nil {
		logger.Printf("%sError While Parsing Initialize Params: %e\n", logService.ERROR, err)
		return false
	}
	for _, handler := range s.methodMap {
		handler.Initialize(&initializeParams, &initializeResult)
	}
	s.con.WriteMessage(protokoll.Message{
		JsonRPC: "2.0",
		ID:      message.ID,
		Method:  "",
		Params:  nil,
		Result:  initializeResult,
		Error:   nil,
	})

	initializedMessage, err := s.con.WaitForMessage()
	if err != nil {
		logger.Printf("%sError While Reading initialized Message: %e\n", logService.ERROR, err)
		return false
	}
	if initializedMessage.Method != "initialized" {
		logger.Printf("%sSecond Message isn't initialized: %v\n", logService.ERROR, message)
		return false
	}
	//logger.Printf("%sInitialized Message: %v\n", logService.TRACE, initializedMessage)
	return true
}
