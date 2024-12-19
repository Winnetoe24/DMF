package connect

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
)

type Connection interface {
	// WriteMessage Writes Message. May queue the Message the syncronise the Writing
	WriteMessage(message protokoll.Message)

	// WaitForMessage Waits for the next Message and returns the Message or the error.
	// Call to this method blocks execution.
	WaitForMessage() (protokoll.Message, error)

	BlockResponse(id json.RawMessage)
	Close() error
}
