package main

import (
	"github.com/Winnetoe24/DMF/lsp/args"
	"github.com/Winnetoe24/DMF/lsp/server"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/lsp/util"
)

func main() {
	args.ParseArgs()
	logService.InitLogger()
	util.CharacterInMarkdownLinksActiv = args.CharacterInMarkdown

	defer logService.Close()
	//go func() {
	//	http.DefaultServeMux.HandleFunc("/debug/pprof/", pprof.Index)
	//	err := http.ListenAndServe(":8080", http.DefaultServeMux)
	//	if err != nil {
	//		panic(err)
	//	}
	//}()

	// Connection Loop
	if args.UseStd {
		newServer := server.NewServer(connect.NewStdIOConnection())
		newServer.MessageLoop()
	} else {
		// TODO Handle Internet Connections
	}
	logService.GetLogger().Println("Server Shutdown")
}
