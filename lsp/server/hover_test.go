package server

import (
	"errors"
	"fmt"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/util"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"testing"
)

func TestIdentifierHover(t *testing.T) {
	connection, server, logger, err, content := setUpTestFile(t)

	// Check that Package Element can be found
	finder := util.NewNodeFinder([]byte(content.Content))
	nodes := finder.FindSmallestNodeAroundPositionInSets(content.Ast, protokoll.Position{
		Line:      43,
		Character: 18,
	}, [][]string{{"package_block", "struct_block", "enum_block", "entity_block", "interface_block"}})
	if nodes[0] == nil {
		t.Error(errors.New("node for PackageElement not found"))
	}
	packageElement := content.LookUp["de.library.management.media.Book"]
	base := packageElement.GetBase()
	println(fmt.Sprintf("%v", base.Node.Range()))
	element := util.FindElementOfNode(content.LookUp, nodes[0])
	if element == nil {
		t.Error(errors.New("element not found"))
	}
	switch element.(type) {
	case *packages.EntityElement:
		// Richtiges Element
	default:
		t.Error(errors.New("element is not EntityElement"))
	}

	hoverRequest := "{\"jsonrpc\":\"2.0\",\"id\":\"5\",\"method\":\"textDocument/hover\",\"params\":{\"textDocument\":{\"uri\":\"file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf\"},\"position\":{\"line\":53,\"character\":16}}}"
	err = connection.WriteJson(hoverRequest)
	if err != nil {
		t.Error(err)
	}
	server.nextMethod(logger)

	hoverResponse := "{\"jsonrpc\":\"2.0\",\"id\":\"5\",\"result\":{\"contents\":{\"kind\":\"markdown\",\"value\":\"\\n#### EntityIdentifier von [Book](file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf#L44)\\n\\n---\\n* **string [isbn](file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf#L15)**\\n\\n* **int [copyNumber](file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf#L18)**\\n\\n\\n\"},\"range\":{\"start\":{\"line\":53,\"character\":16},\"end\":{\"line\":53,\"character\":16}}}}"
	actualHoverResponse, err := connection.ReadJson()
	if err != nil {
		t.Error(err)
	}
	if actualHoverResponse != hoverResponse {
		t.Error(errors.New("Hover response is wrong: " + actualHoverResponse))
	}
}

func TestHoverEntity(t *testing.T) {
	connection, server, logger, err, _ := setUpTestFile(t)

	hoverRequest := "{\"jsonrpc\":\"2.0\",\"id\":\"6\",\"method\":\"textDocument/hover\",\"params\":{\"textDocument\":{\"uri\":\"file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf\"},\"position\":{\"line\":43,\"character\":15}}}"
	err = connection.WriteJson(hoverRequest)
	if err != nil {
		t.Error(err)
	}
	server.nextMethod(logger)

	hoverResponse := "{\"jsonrpc\":\"2.0\",\"id\":\"6\",\"result\":{\"contents\":{\"kind\":\"markdown\",\"value\":\"\\n#### Book\\n###### Entity in Package [de.library.management.media](file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf#L10)\\nDetaillierte Buchinformationen\\n\\n\"},\"range\":{\"start\":{\"line\":43,\"character\":15},\"end\":{\"line\":43,\"character\":15}}}}"
	actualHoverResponse, err := connection.ReadJson()
	if err != nil {
		t.Error(err)
	}
	if actualHoverResponse != hoverResponse {
		t.Error(errors.New("Hover response is wrong: " + actualHoverResponse))
	}
}

func TestHoverStruct(t *testing.T) {
	connection, server, logger, err, _ := setUpTestFile(t)

	hoverRequest := "{\"jsonrpc\":\"2.0\",\"id\":\"3\",\"method\":\"textDocument/hover\",\"params\":{\"textDocument\":{\"uri\":\"file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf\"},\"position\":{\"line\":14,\"character\":4}}}"
	err = connection.WriteJson(hoverRequest)
	if err != nil {
		t.Error(err)
	}
	server.nextMethod(logger)

	hoverResponse := "{\"jsonrpc\":\"2.0\",\"id\":\"3\",\"result\":{\"contents\":{\"kind\":\"markdown\",\"value\":\"\\n#### MediaItem\\n###### Struct in Package [de.library.management.media](file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf#L10)\\nBasisstruktur für alle Medientypen\\n\\n\"},\"range\":{\"start\":{\"line\":14,\"character\":4},\"end\":{\"line\":14,\"character\":4}}}}"
	actualHoverResponse, err := connection.ReadJson()
	if err != nil {
		t.Error(err)
	}
	if actualHoverResponse != hoverResponse {
		t.Error(errors.New("Hover response is wrong: " + actualHoverResponse))
	}
}

func TestHoverKonstante(t *testing.T) {
	connection, server, logger, err, _ := setUpTestFile(t)

	hoverRequest := "{\"jsonrpc\":\"2.0\",\"id\":\"3\",\"method\":\"textDocument/hover\",\"params\":{\"textDocument\":{\"uri\":\"file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf\"},\"position\":{\"line\":39,\"character\":14}}}"
	err = connection.WriteJson(hoverRequest)
	if err != nil {
		t.Error(err)
	}
	server.nextMethod(logger)

	hoverResponse := "{\"jsonrpc\":\"2.0\",\"id\":\"3\",\"result\":{\"contents\":{\"kind\":\"markdown\",\"value\":\"\\n#### HISTORY\\n###### In [Category](file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf#L34)\\n\\n\\n**[Index]()**: 5\\u003cbr\\u003e\\n**[name](file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf#L35)**: Geschichte\\u003cbr\\u003e\\n\\n\"},\"range\":{\"start\":{\"line\":39,\"character\":14},\"end\":{\"line\":39,\"character\":14}}}}"
	actualHoverResponse, err := connection.ReadJson()
	if err != nil {
		t.Error(err)
	}
	if actualHoverResponse != hoverResponse {
		t.Error(errors.New("Hover response is wrong: " + actualHoverResponse))
	}
}

func TestHoverRef(t *testing.T) {
	connection, server, logger, err, _ := setUpTestFile(t)

	hoverRequest := "{\"jsonrpc\":\"2.0\",\"id\":\"4\",\"method\":\"textDocument/hover\",\"params\":{\"textDocument\":{\"uri\":\"file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf\"},\"position\":{\"line\":46,\"character\":22}}}"
	err = connection.WriteJson(hoverRequest)
	if err != nil {
		t.Error(err)
	}
	server.nextMethod(logger)

	hoverResponse := "{\"jsonrpc\":\"2.0\",\"id\":\"4\",\"result\":{\"contents\":{\"kind\":\"markdown\",\"value\":\"\\n#### [Category](file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf#L34 \\\"Kategorisierung der MedienEnum Category in Package de.library.management.media\\\") category\\nsad\\n\\n\\n\"},\"range\":{\"start\":{\"line\":46,\"character\":22},\"end\":{\"line\":46,\"character\":22}}}}"
	actualHoverResponse, err := connection.ReadJson()
	if err != nil {
		t.Error(err)
	}
	if actualHoverResponse != hoverResponse {
		t.Error(errors.New("Hover response is wrong: " + actualHoverResponse))
	}
}

func TestHoverArg(t *testing.T) {
	connection, server, logger, err, _ := setUpTestFile(t)

	hoverRequest := "{\"jsonrpc\":\"2.0\",\"id\":\"5\",\"method\":\"textDocument/hover\",\"params\":{\"textDocument\":{\"uri\":\"file:///home/alex/LocalNAS/Bachelorarbeit/DMF/intellijTest/edit-after.dmf\"},\"position\":{\"line\":49,\"character\":22}}}"
	err = connection.WriteJson(hoverRequest)
	if err != nil {
		t.Error(err)
	}
	server.nextMethod(logger)

	hoverResponse := "{\"jsonrpc\":\"2.0\",\"id\":\"5\",\"result\":{\"contents\":{\"kind\":\"markdown\",\"value\":\"\\n#### int pageCount\\nasd\\n\\n\\n\"},\"range\":{\"start\":{\"line\":49,\"character\":22},\"end\":{\"line\":49,\"character\":22}}}}"
	actualHoverResponse, err := connection.ReadJson()
	if err != nil {
		t.Error(err)
	}
	if actualHoverResponse != hoverResponse {
		t.Error(errors.New("Hover response is wrong: " + actualHoverResponse))
	}
}
