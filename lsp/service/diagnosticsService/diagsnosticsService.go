package diagnosticsService

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/diagnostics"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

var _ service.MethodHandler = &DiagnosticsService{}
var _ fileService.FileChangeListener = &DiagnosticsService{}

type DiagnosticsService struct {
	con                 connect.Connection
	publishCapabilities *initialize.PublishDiagnosticsClientCapabilities
}

func NewDiagnosticsService(con connect.Connection) *DiagnosticsService {
	return &DiagnosticsService{
		con: con,
	}
}

func (d *DiagnosticsService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {
	textDocument := params.Capabilities.TextDocument
	if textDocument != nil {
		d.publishCapabilities = textDocument.PublishDiagnostics
	}
	result.Capabilities.DiagnosticOptions = &initialize.DiagnosticOptions{
		Identifier:            "",
		InterFileDependencies: true,
		WorkspaceDiagnostics:  false,
	}
}

func (d *DiagnosticsService) HandleFileChange(file protokoll.DocumentURI, fileContent string, ast tree_sitter.Tree, model smodel.Model, lookup smodel.TypeLookUp, errorElements []errElement.ErrorElement, version int32) {
	//logService.GetLogger().Printf("%sHandleFileChange Diagnostics: %v\n", logService.TRACE, d)
	// Publish Diagnostics
	foundDiagnostics := make([]protokoll.Diagnostic, 0, len(errorElements))
	if errorElements != nil && len(errorElements) > 0 {

		context := errElement.ErrorContext{
			Dateiname:   string(file),
			Dateiinhalt: []byte(fileContent),
		}
		for _, element := range errorElements {
			severityError := protokoll.SeverityError
			if element.Fehler.Node != nil {
				diagnostic := protokoll.Diagnostic{
					Range:              protokoll.ToRange(element.Fehler.Node.Range()),
					Severity:           &severityError,
					Code:               nil,
					CodeDescription:    nil,
					Source:             element.ToErrorMsg(&context),
					Message:            element.Error.Error(),
					Tags:               nil,
					RelatedInformation: nil,
					Data:               nil,
				}
				if element.Cause != nil {
					diagnostic.RelatedInformation = []protokoll.DiagnosticRelatedInformation{{
						Location: protokoll.Location{
							URI:   file,
							Range: protokoll.ToRange(element.Cause.Node.Range()),
						},
						Message: "Ursprung des Fehlers",
					}}
				}
				foundDiagnostics = append(foundDiagnostics, diagnostic)
			} else {
				diagnostic := protokoll.Diagnostic{
					Range: protokoll.Range{
						Start: protokoll.Position{
							Line:      0,
							Character: 0,
						},
						End: protokoll.Position{
							Line:      0,
							Character: 0,
						},
					},
					Severity:           &severityError,
					Code:               nil,
					CodeDescription:    nil,
					Source:             "Keine Node im Fehler vorhanden:" + element.Error.Error(),
					Message:            element.Error.Error(),
					Tags:               nil,
					RelatedInformation: nil,
					Data:               nil,
				}
				foundDiagnostics = append(foundDiagnostics, diagnostic)

			}

		}

	}
	params := diagnostics.PublishDiagnosticsParams{
		URI:         string(file),
		Version:     nil,
		Diagnostics: foundDiagnostics,
	}
	if d.publishCapabilities == nil || d.publishCapabilities.VersionSupport {
		params.Version = &version
	}

	marshal, err := json.Marshal(params)
	logger := logService.GetLogger()
	if err != nil {
		logger.Printf("%sError while parsing PublishDiagnosticsParams. Error: %e Value: %v\n", logService.ERROR, err, params)
	} else {
		message := protokoll.Message{
			JsonRPC: "2.0",
			ID:      nil,
			Method:  "textDocument/publishDiagnostics",
			Params:  marshal,
			Result:  nil,
			Error:   nil,
		}
		d.con.WriteMessage(message)
		logger.Printf("%sPublished Diagnostics: %v\n", logService.INFO, message)
	}
}

func (d *DiagnosticsService) GetMethods() []string {
	return make([]string, 0)
}

func (d *DiagnosticsService) HandleMethod(message protokoll.Message) {
	//TODO implement me
	panic("implement me")
}
