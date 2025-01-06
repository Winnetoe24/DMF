package main

import (
	"flag"
	"github.com/Winnetoe24/DMF/lsp/server"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/lsp/util"
)

func main() {
	var useStd = flag.Bool("stdio", true, "useStdio for communication")
	var characterInMarkdown = flag.Bool("characterInMarkdownLinks", false, "activates MarkdownLinks where the Character is transmitted with the schema #L<line>.<character>")
	flag.Parse()
	if characterInMarkdown != nil {
		util.CharacterInMarkdownLinksActiv = *characterInMarkdown
	}

	defer logService.Close()

	// Connection Loop
	if *useStd {
		newServer := server.NewServer(connect.NewStdIOConnection())
		newServer.MessageLoop()
	} else {
		// TODO Handle Internet Connections
	}
	logService.GetLogger().Println("Server Shutdown")
}
