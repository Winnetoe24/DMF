package connectUtils

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
)

func WriteErrorToCon(connection connect.Connection, id json.RawMessage, err error, code protokoll.ErrorCode) {
	errorMessage := protokoll.Message{
		JsonRPC: "2.0",
		ID:      id,
		Method:  "",
		Params:  nil,
		Result:  nil,
		Error: &protokoll.Error{
			Code:    code,
			Message: err.Error(),
		},
	}
	connection.WriteMessage(errorMessage)
}
