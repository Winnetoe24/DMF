package server

import (
	"errors"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"log"
	"testing"
)

func setUpTestFile(t *testing.T) (*connect.TestConnection, *Server, *log.Logger, error, fileService.FileContent) {
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

	err = connection.WriteJson("{\"jsonrpc\":\"2.0\",\"method\":\"textDocument/didOpen\",\"params\":{\"textDocument\":{\"uri\":\"file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf\",\"languageId\":\"text\",\"version\":1,\"text\":\"dmf 1.0.0\\nmodel \\\"edit\\\" version 1.0.0\\n\\n\\npackage de.library.management {\\n\\n    // Basispaket für Medienverwaltung\\n    // asdas d\\n    // Das ist ein neuer Kommentar\\n    package media {\\n\\n        // Basisstruktur für alle Medientypen\\n        struct MediaItem {\\n            arg string title;\\n            arg string isbn;\\n            arg date publishedDate;\\n            arg double price;\\n            arg int copyNumber;\\n            func boolean isAvailable(int copyId);\\n            arg double asd;\\n        }\\n\\n        // Verschiedene Medientypen\\n        enum MediaType {\\n            BOOK(_);\\n            EBOOK(_);\\n            AUDIO_BOOK(_);\\n            DVD(_);\\n            MAGAZINE(_);\\n            NEWSPAPER(_);\\n        }\\n\\n        // Kategorisierung der Medien\\n        enum Category {\\n            arg string name;\\n            FICTION(1, \\\"Belletristik\\\");\\n            NON_FICTION(2, \\\"Sachbuch\\\");\\n            CHILDREN(3, \\\"Kinderbuch\\\");\\n            SCIENCE(4, \\\"Wissenschaft\\\");\\n            HISTORY(5, \\\"Geschichte\\\");\\n        }\\n\\n        // Detaillierte Buchinformationen\\n        entity Book extends MediaItem{\\n            arg string author;\\n            // sad\\n            ref .Category category;\\n            ref .MediaType type;\\n            // asd\\n            arg int pageCount;\\n            arg string publisher;\\n            arg string language;\\n\\n            identifier(isbn, copyNumber);\\n        }\\n\\n        // Verwaltung von Zeitschriften\\n        entity Magazine extends MediaItem {\\n            arg int issueNumber;\\n            arg string publisher;\\n            arg boolean isSubscription;\\n            arg date validUntil;\\n\\n            identifier(isbn, issueNumber);\\n        }\\n    }\\n\\n    // Benutzerverwaltung\\n    package users {\\n\\n        // Adressinformationen\\n        struct Address {\\n            arg string street;\\n            arg string houseNumber;\\n            arg string postalCode;\\n            arg string city;\\n            arg string country;\\n        }\\n\\n        // Verschiedene Mitgliedsarten\\n        enum MembershipType {\\n            arg int preis;\\n            arg date startdatum;\\n            STANDARD(1, 10, D2024-01-01);\\n            PLUS(4, 15, D2024-01-01);\\n            PREMIUM(2, 20, D2024-01-01);\\n            STUDENT(3, 15, D2024-01-01);\\n        }\\n\\n        // Benutzerstatus\\n        enum UserStatus {\\n            ACTIVE(_);\\n            SUSPENDED(_);\\n            EXPIRED(_);\\n            UNVERIFED(_);\\n        }\\n\\n        // Benutzerentität\\n        entity User {\\n            arg string firstName;\\n            arg string lastName;\\n            arg date dateOfBirth;\\n            arg string email;\\n            ref .Address address;\\n            ref .MembershipType membershipType;\\n            ref .UserStatus status;\\n            arg date memberSince;\\n            arg date membershipExpiry;\\n\\n            identifier(email, firstName);\\n        }\\n    }\\n}\\n\"}}}")
	if err != nil {
		t.Error(err)
	}
	server.nextMethod(logger)

	methodHandler := server.methodMap["textDocument/didOpen"]
	fileS := methodHandler.(*fileService.FileService)

	content, err := fileS.GetFileContent("file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf")
	if err != nil {
		t.Error(err)
	}
	if content.Content != "dmf 1.0.0\nmodel \"edit\" version 1.0.0\n\n\npackage de.library.management {\n\n    // Basispaket für Medienverwaltung\n    // asdas d\n    // Das ist ein neuer Kommentar\n    package media {\n\n        // Basisstruktur für alle Medientypen\n        struct MediaItem {\n            arg string title;\n            arg string isbn;\n            arg date publishedDate;\n            arg double price;\n            arg int copyNumber;\n            func boolean isAvailable(int copyId);\n            arg double asd;\n        }\n\n        // Verschiedene Medientypen\n        enum MediaType {\n            BOOK(_);\n            EBOOK(_);\n            AUDIO_BOOK(_);\n            DVD(_);\n            MAGAZINE(_);\n            NEWSPAPER(_);\n        }\n\n        // Kategorisierung der Medien\n        enum Category {\n            arg string name;\n            FICTION(1, \"Belletristik\");\n            NON_FICTION(2, \"Sachbuch\");\n            CHILDREN(3, \"Kinderbuch\");\n            SCIENCE(4, \"Wissenschaft\");\n            HISTORY(5, \"Geschichte\");\n        }\n\n        // Detaillierte Buchinformationen\n        entity Book extends MediaItem{\n            arg string author;\n            // sad\n            ref .Category category;\n            ref .MediaType type;\n            // asd\n            arg int pageCount;\n            arg string publisher;\n            arg string language;\n\n            identifier(isbn, copyNumber);\n        }\n\n        // Verwaltung von Zeitschriften\n        entity Magazine extends MediaItem {\n            arg int issueNumber;\n            arg string publisher;\n            arg boolean isSubscription;\n            arg date validUntil;\n\n            identifier(isbn, issueNumber);\n        }\n    }\n\n    // Benutzerverwaltung\n    package users {\n\n        // Adressinformationen\n        struct Address {\n            arg string street;\n            arg string houseNumber;\n            arg string postalCode;\n            arg string city;\n            arg string country;\n        }\n\n        // Verschiedene Mitgliedsarten\n        enum MembershipType {\n            arg int preis;\n            arg date startdatum;\n            STANDARD(1, 10, D2024-01-01);\n            PLUS(4, 15, D2024-01-01);\n            PREMIUM(2, 20, D2024-01-01);\n            STUDENT(3, 15, D2024-01-01);\n        }\n\n        // Benutzerstatus\n        enum UserStatus {\n            ACTIVE(_);\n            SUSPENDED(_);\n            EXPIRED(_);\n            UNVERIFED(_);\n        }\n\n        // Benutzerentität\n        entity User {\n            arg string firstName;\n            arg string lastName;\n            arg date dateOfBirth;\n            arg string email;\n            ref .Address address;\n            ref .MembershipType membershipType;\n            ref .UserStatus status;\n            arg date memberSince;\n            arg date membershipExpiry;\n\n            identifier(email, firstName);\n        }\n    }\n}\n" {
		t.Error(errors.New("Content is wrong: " + content.Content))
	}

	publishDiagnosticReponse, err := connection.ReadJson()
	if err != nil {
		t.Error(err)
	}
	if publishDiagnosticReponse != "{\"jsonrpc\":\"2.0\",\"method\":\"textDocument/publishDiagnostics\",\"params\":{\"uri\":\"file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf\",\"version\":1,\"diagnostics\":[]}}" {
		t.Error(errors.New("Content is wrong: " + publishDiagnosticReponse))
	}
	return connection, server, logger, err, content
}
