package main

import (
	"github.com/Winnetoe24/DMF/lsp/args"
	"github.com/Winnetoe24/DMF/lsp/server"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/lsp/util"
	"net"
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
		logService.SwitchToStdIO()
		logger := logService.GetLogger()
		listener, err := net.Listen("tcp", args.Port)
		if err != nil {
			logger.Println("Error listening:", err)
			return
		}
		defer func(listener net.Listener) {
			err := listener.Close()
			if err != nil {
				logger.Println("Error closing listener:", err)
			}
		}(listener)

		logger.Println("Server gestartet auf Port" + args.Port)
		for {
			conn, err := listener.Accept()
			if err != nil {
				logger.Println("Error accepting connection:", err)
				continue
			}

			// Server starten
			go func(conn net.Conn) {
				newServer := server.NewServer(connect.NewSocketConnection(conn))
				newServer.MessageLoop()
			}(conn)
		}
	}
	logService.GetLogger().Println("Server Shutdown")
}
