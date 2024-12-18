package logService

import "log"

var TRACE = "Trace | "
var DEBUG = "Debug | "
var INFO = "INFO  | "
var ERROR = "ERROR | "

func GetLogger(prefix string) *log.Logger {
	return log.Default()
}
