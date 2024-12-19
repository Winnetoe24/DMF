package protokoll

import "encoding/json"

type CancelParams struct {
	ID json.RawMessage `json:"id"`
}
