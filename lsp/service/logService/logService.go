package logService

import (
	"fmt"
	"log"
	"os"
	"time"
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
	prefix := logsDir + string(os.PathSeparator) + "server"
	//i := 0
	//logname := prefix
	//for {
	//	if _, err := os.Stat(logname + ".log"); err == nil {
	//		i++
	//		logname = prefix + "_" + strconv.Itoa(i)
	//	} else {
	//		if prefix != logname {
	//			err := os.Rename(prefix+".log", logname+".log")
	//			if err != nil {
	//				panic(err)
	//			}
	//		}
	//		break
	//	}
	//}
	logFile, err = os.OpenFile(prefix+".log", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0666)
	if err != nil {
		_, _ = fmt.Fprintf(os.Stderr, "Failed to open log file: %v\n", err)
		os.Exit(1)
	}
	baseLogger = log.New(logFile, "", log.Ldate|log.Ltime|log.Lshortfile)

	logPath := logsDir + string(os.PathSeparator) + "connection_in_" + time.Now().Format("2006_01_02_15_04_05") + ".log"
	conLogFile, err := os.Create(logPath)
	if err != nil {
		_, _ = fmt.Fprintf(os.Stderr, "Failed to open log file: %v\n", err)
		os.Exit(1)
	}
	connectionLoggerIn = log.New(conLogFile, "LSPMESSAGE", log.Ltime|log.Lmicroseconds)

	logPath = logsDir + string(os.PathSeparator) + "connection_out_" + time.Now().Format("2006_01_02_15_04_05") + ".log"
	conLogFile, err = os.Create(logPath)
	if err != nil {
		_, _ = fmt.Fprintf(os.Stderr, "Failed to open log file: %v\n", err)
		os.Exit(1)
	}
	connectionLoggerOut = log.New(conLogFile, "LSPMESSAGE", log.Ltime|log.Lmicroseconds)
}

func GetLogger() *log.Logger {
	return baseLogger
}

var connectionLoggerOut *log.Logger

func GetConnectionLoggerOut() *log.Logger {
	return connectionLoggerOut
}

var connectionLoggerIn *log.Logger

func GetConnectionLoggerIn() *log.Logger {
	return connectionLoggerIn
}
func Close() {
	err := logFile.Close()
	if err != nil {
		fmt.Printf("Error while Closing Log File: %e\n", err)
	}
}
