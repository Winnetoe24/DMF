package main

import (
	"flag"
	"github.com/Winnetoe24/DMF/lsp/server"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
)

func main() {
	var useStd = flag.Bool("stdio", true, "useStdio for communication")
	flag.Parse()

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
