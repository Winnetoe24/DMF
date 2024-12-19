package protokoll

import "encoding/json"

// LSP Message types and other struct definitions remain the same...
type Message struct {
	// JsonRPC ist die Version des Protokolls → 2.0
	JsonRPC string `json:"jsonrpc"`
	// ID des Requests. Wird auch von Responses mit der ID des Requests befüllt.
	ID json.RawMessage `json:"id,omitempty"`
	// Method die aufgerufen wird. Nur Teil von Requests und Notifications.
	Method string `json:"method,omitempty"`
	// Params sind Teil von Requests und Notifications.
	// Sie werden in den entsprechenden Services geparst.
	Params json.RawMessage `json:"params,omitempty"`
	// Result wird nur bei erfolgreichen Responses mit der Antwort befüllt.
	Result interface{} `json:"result,omitempty"`
	// Error wird nur bei fehlgeschlagenen Responses befüllt.
	Error *Error `json:"error,omitempty"`
}

type Error struct {
	Code    ErrorCode `json:"code"`
	Message string    `json:"message"`
}

type ErrorCode int

const ParseError ErrorCode = -32700
const InvalidRequest ErrorCode = -32600
const MethodNotFound ErrorCode = -32601
const InvalidParams ErrorCode = -32602
const InternalError ErrorCode = -32603

// JsonrpcReservedErrorRangeStart
// This is the start range of JSON-RPC reserved error codes.
// It doesn't denote a real error code. No LSP error codes should
// be defined between the start and end range. For backwards
// compatibility the `ServerNotInitialized` and the `UnknownErrorCode`
// are left in the range.
const JsonrpcReservedErrorRangeStart ErrorCode = -32099

// ServerNotInitialized
// Error code indicating that a server received a notification or
// request before the server has received the `initialize` request.
const ServerNotInitialized ErrorCode = -32002
const UnknownErrorCode ErrorCode = -32001

// JsonrpcReservedErrorRangeEnd
// This is the end range of JSON-RPC reserved error codes.
// It doesn't denote a real error code.
const JsonrpcReservedErrorRangeEnd ErrorCode = -32000

// LspReservedErrorRangeStart
// This is the start range of LSP reserved error codes.
// It doesn't denote a real error code.
const LspReservedErrorRangeStart ErrorCode = -32899

// RequestFailed
// A request failed but it was syntactically correct, e.g the
// method name was known and the parameters were valid. The error
// message should contain human readable information about why
// the request failed.
const RequestFailed ErrorCode = -32803

// ServerCancelled
// The server cancelled the request. This error code should
// only be used for requests that explicitly support being
// server cancellable.
const ServerCancelled ErrorCode = -32802

// ContentModified
// The server detected that the content of a document got
// modified outside normal conditions. A server should
// NOT send this error code if it detects a content change
// in it unprocessed messages. The result even computed
// on an older state might still be useful for the client.
// If a client decides that a result is not of any use anymore
// the client should cancel the request.
const ContentModified ErrorCode = -32801

// RequestCancelled
// The client has canceled a request and a server has detected
// the cancel.
const RequestCancelled ErrorCode = -32800

// LspReservedErrorRangeEnd
// This is the end range of LSP reserved error codes.
// It doesn't denote a real error code.
const LspReservedErrorRangeEnd ErrorCode = -32800
