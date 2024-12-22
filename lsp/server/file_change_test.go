package server

import (
	"errors"
	"fmt"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"testing"
)

func TestFileChange(t *testing.T) {
	connection := connect.NewTestConnectionHandle()
	server := NewServer(connection)
	logger := logService.GetLogger()

	err := connection.WriteJson("{\"jsonrpc\":\"2.0\",\"id\":\"1\",\"method\":\"initialize\",\"params\":{\"processId\":25904,\"rootPath\":\"C:/Code/DMF/intellijTest\",\"rootUri\":\"file:///C:/Code/DMF/intellijTest\",\"initializationOptions\":{},\"capabilities\":{\"workspace\":{\"applyEdit\":true,\"workspaceEdit\":{\"documentChanges\":true,\"resourceOperations\":[\"create\",\"delete\",\"rename\"]},\"didChangeConfiguration\":{\"dynamicRegistration\":true},\"didChangeWatchedFiles\":{\"dynamicRegistration\":true},\"symbol\":{},\"executeCommand\":{\"dynamicRegistration\":true},\"workspaceFolders\":true,\"configuration\":true,\"semanticTokens\":{\"refreshSupport\":true},\"codeLens\":{\"refreshSupport\":true},\"fileOperations\":{\"didRename\":true,\"willRename\":true,\"dynamicRegistration\":true},\"inlayHint\":{\"refreshSupport\":true}},\"textDocument\":{\"synchronization\":{\"willSave\":true,\"willSaveWaitUntil\":true,\"didSave\":true},\"completion\":{\"completionItem\":{\"snippetSupport\":true,\"documentationFormat\":[\"markdown\",\"plaintext\"],\"deprecatedSupport\":true,\"resolveSupport\":{\"properties\":[\"documentation\",\"detail\",\"additionalTextEdits\"]},\"insertTextModeSupport\":{\"valueSet\":[1,2]},\"labelDetailsSupport\":true},\"completionList\":{\"itemDefaults\":[\"editRange\"]},\"dynamicRegistration\":true},\"hover\":{\"contentFormat\":[\"markdown\",\"plaintext\"],\"dynamicRegistration\":true},\"signatureHelp\":{\"signatureInformation\":{\"parameterInformation\":{\"labelOffsetSupport\":true}},\"dynamicRegistration\":true},\"references\":{\"dynamicRegistration\":true},\"documentHighlight\":{\"dynamicRegistration\":true},\"documentSymbol\":{\"symbolKind\":{\"valueSet\":[18,17,5,14,9,10,22,24,8,1,12,11,20,6,2,3,21,16,19,25,4,7,15,23,26,13]},\"hierarchicalDocumentSymbolSupport\":true,\"dynamicRegistration\":true},\"formatting\":{\"dynamicRegistration\":true},\"rangeFormatting\":{\"dynamicRegistration\":true},\"declaration\":{\"linkSupport\":true,\"dynamicRegistration\":true},\"definition\":{\"linkSupport\":true,\"dynamicRegistration\":true},\"typeDefinition\":{\"linkSupport\":true,\"dynamicRegistration\":true},\"implementation\":{\"linkSupport\":true,\"dynamicRegistration\":true},\"codeAction\":{\"codeActionLiteralSupport\":{\"codeActionKind\":{\"valueSet\":[\"quickfix\",\"refactor\",\"refactor.extract\",\"refactor.inline\",\"refactor.rewrite\",\"source\",\"source.organizeImports\"]}},\"dataSupport\":true,\"resolveSupport\":{\"properties\":[\"edit\"]},\"dynamicRegistration\":true},\"codeLens\":{\"dynamicRegistration\":true},\"documentLink\":{\"dynamicRegistration\":true},\"colorProvider\":{\"dynamicRegistration\":true},\"rename\":{\"prepareSupport\":true,\"dynamicRegistration\":true},\"publishDiagnostics\":{\"relatedInformation\":true,\"tagSupport\":{\"valueSet\":[1,2]},\"codeDescriptionSupport\":true,\"dataSupport\":true},\"foldingRange\":{\"dynamicRegistration\":true},\"typeHierarchy\":{\"dynamicRegistration\":true},\"callHierarchy\":{\"dynamicRegistration\":true},\"semanticTokens\":{\"requests\":{\"range\":false,\"full\":true},\"tokenTypes\":[\"namespace\",\"type\",\"class\",\"enum\",\"interface\",\"struct\",\"typeParameter\",\"parameter\",\"variable\",\"property\",\"enumMember\",\"event\",\"function\",\"method\",\"macro\",\"keyword\",\"modifier\",\"comment\",\"string\",\"number\",\"regexp\",\"operator\",\"decorator\",\"label\"],\"tokenModifiers\":[\"declaration\",\"definition\",\"readonly\",\"static\"],\"formats\":[\"relative\"],\"multilineTokenSupport\":true,\"serverCancelSupport\":true,\"dynamicRegistration\":true},\"inlayHint\":{\"dynamicRegistration\":true}},\"window\":{\"workDoneProgress\":true,\"showMessage\":{},\"showDocument\":{\"support\":true}},\"general\":{\"staleRequestSupport\":{\"cancel\":true,\"retryOnContentModified\":[]},\"positionEncodings\":[\"utf-16\"]}},\"clientInfo\":{\"name\":\"IntelliJ\",\"version\":\"IntelliJ IDEA (build IU-241.15989.150)\"},\"trace\":\"off\",\"workspaceFolders\":[{\"uri\":\"file:///C:/Code/DMF/intellijTest\",\"name\":\"intellijTest\"}]}}")
	if err != nil {
		t.Error(err)
	}

	err = connection.WriteJson("{\"jsonrpc\":\"2.0\",\"method\":\"initialized\",\"params\":{}}")
	if err != nil {
		t.Error(err)
	}

	isError := server.initialize(logger)
	if isError {
		t.Fatal("Failed to initialize server")
	}
	_, err = connection.ReadJson()
	if err != nil {
		t.Error(err)
	}

	err = connection.WriteJson("{\"jsonrpc\":\"2.0\",\"method\":\"textDocument/didOpen\",\"params\":{\"textDocument\":{\"uri\":\"file:///C:/Code/DMF/intellijTest/test.dmf\",\"languageId\":\"dmf\",\"version\":1,\"text\":\"dmf 1.0.0\\nmodel \\\"dp_success\\\" version 0.0.0\\n\\npackage de.alex.brand {\\n    package other {\\n\\n        struct Test{\\n\\n\\n        }\\n\\n        enum Ort {\\n\\n            VOR_HAUS(_);\\n        }\\n\\n        entity Person implements Inte {\\n            arg int i;\\n            arg string me;\\n            identifier(i, me);\\n        }\\n\\n        interface Inte  {\\n\\n        }\\n\\n\\n\\n    }\\n\\n   package rekur {\\n        struct One  {\\n        }\\n\\n        entity OneE {\\n            arg int i;\\n            arg string me;\\n           identifier(i, me);\\n        }\\n        entity TwoE extends .OneE {\\n           identifier(i, me);\\n        }\\n    }\\n    package grund {\\n         interface IGrund  {\\n\\n         }\\n    }\\n}\"}}}")
	if err != nil {
		t.Error(err)
	}
	server.nextMethod(logger)

	methodHandler := server.methodMap["textDocument/didOpen"]
	fileS := methodHandler.(*fileService.FileService)

	content, err := fileS.GetFileContent("file:///C:/Code/DMF/intellijTest/test.dmf")
	if err != nil {
		t.Error(err)
	}
	if content.Content != "dmf 1.0.0\nmodel \"dp_success\" version 0.0.0\n\npackage de.alex.brand {\n    package other {\n\n        struct Test{\n\n\n        }\n\n        enum Ort {\n\n            VOR_HAUS(_);\n        }\n\n        entity Person implements Inte {\n            arg int i;\n            arg string me;\n            identifier(i, me);\n        }\n\n        interface Inte  {\n\n        }\n\n\n\n    }\n\n   package rekur {\n        struct One  {\n        }\n\n        entity OneE {\n            arg int i;\n            arg string me;\n           identifier(i, me);\n        }\n        entity TwoE extends .OneE {\n           identifier(i, me);\n        }\n    }\n    package grund {\n         interface IGrund  {\n\n         }\n    }\n}" {
		t.Error(errors.New("Content is wrong: " + content.Content))
	}

	err = connection.WriteJson("{\"jsonrpc\":\"2.0\",\"method\":\"textDocument/didChange\",\"params\":{\"textDocument\":{\"version\":2,\"uri\":\"file:///C:/Code/DMF/intellijTest/test.dmf\"},\"contentChanges\":[{\"range\":{\"start\":{\"line\":1,\"character\":31},\"end\":{\"line\":1,\"character\":32}},\"rangeLength\":1,\"text\":\"\"}]}}")
	if err != nil {
		t.Error(err)
	}
	server.nextMethod(logger)
	contentEdit1, err := fileS.GetFileContent("file:///C:/Code/DMF/intellijTest/test.dmf")
	if err != nil {
		t.Error(err)
	}
	if contentEdit1.Version != 2 {
		t.Error(errors.New(fmt.Sprintf("Content Version is wrong: %v", content.Version)))
	}
	if contentEdit1.Content != "dmf 1.0.0\nmodel \"dp_success\" version 0.0.\n\npackage de.alex.brand {\n    package other {\n\n        struct Test{\n\n\n        }\n\n        enum Ort {\n\n            VOR_HAUS(_);\n        }\n\n        entity Person implements Inte {\n            arg int i;\n            arg string me;\n            identifier(i, me);\n        }\n\n        interface Inte  {\n\n        }\n\n\n\n    }\n\n   package rekur {\n        struct One  {\n        }\n\n        entity OneE {\n            arg int i;\n            arg string me;\n           identifier(i, me);\n        }\n        entity TwoE extends .OneE {\n           identifier(i, me);\n        }\n    }\n    package grund {\n         interface IGrund  {\n\n         }\n    }\n}" {
		t.Error(errors.New("Content is wrong: " + content.Content))
	}
	err = connection.WriteJson("{\"jsonrpc\":\"2.0\",\"method\":\"textDocument/didChange\",\"params\":{\"textDocument\":{\"version\":3,\"uri\":\"file:///C:/Code/DMF/intellijTest/test.dmf\"},\"contentChanges\":[{\"range\":{\"start\":{\"line\":1,\"character\":31},\"end\":{\"line\":1,\"character\":31}},\"rangeLength\":0,\"text\":\"1\"}]}}")
	if err != nil {
		t.Error(err)
	}
	server.nextMethod(logger)

	contentEdit, err := fileS.GetFileContent("file:///C:/Code/DMF/intellijTest/test.dmf")
	if err != nil {
		t.Error(err)
	}
	if contentEdit.Version != 3 {
		t.Error(errors.New(fmt.Sprintf("Content Version is wrong: %v", content.Version)))
	}
	if contentEdit.Content != "dmf 1.0.0\nmodel \"dp_success\" version 0.0.1\n\npackage de.alex.brand {\n    package other {\n\n        struct Test{\n\n\n        }\n\n        enum Ort {\n\n            VOR_HAUS(_);\n        }\n\n        entity Person implements Inte {\n            arg int i;\n            arg string me;\n            identifier(i, me);\n        }\n\n        interface Inte  {\n\n        }\n\n\n\n    }\n\n   package rekur {\n        struct One  {\n        }\n\n        entity OneE {\n            arg int i;\n            arg string me;\n           identifier(i, me);\n        }\n        entity TwoE extends .OneE {\n           identifier(i, me);\n        }\n    }\n    package grund {\n         interface IGrund  {\n\n         }\n    }\n}" {
		t.Error(errors.New("Content is wrong: " + content.Content))
	}
}
