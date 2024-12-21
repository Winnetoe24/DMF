package logService

import (
	"fmt"
	"log"
	"os"
)

var TRACE = "Trace | "
var DEBUG = "Debug | "
var INFO = "INFO  | "
var ERROR = "ERROR | "

var baseLogger *log.Logger
var logFile *os.File

func init() {
	// Set up logging to file
	var err error
	logsDir := os.Getenv("DMF_LSP_LOG")
	if logsDir == "" {
		logsDir = "C:\\Code\\DMF\\logs"
	}
	//println(logsDir)
	logFile, err = os.OpenFile(logsDir+string(os.PathSeparator)+"server.log", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0666)
	if err != nil {
		_, _ = fmt.Fprintf(os.Stderr, "Failed to open log file: %v\n", err)
		os.Exit(1)
	}
	baseLogger = log.New(logFile, "", log.Ldate|log.Ltime|log.Lshortfile)
}

func GetLogger() *log.Logger {
	return baseLogger
}

func Close() {
	err := logFile.Close()
	if err != nil {
		fmt.Printf("Error while Closing Log File: %e\n", err)
	}
}
