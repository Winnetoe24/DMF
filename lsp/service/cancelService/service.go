package cancelService

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
)

var _ service.MethodHandler = &CancelService{}

type CancelService struct {
	con connect.Connection
}

func NewCancelService(con connect.Connection) *CancelService {
	return &CancelService{con: con}
}

func (c *CancelService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {
	//Nothing
}

func (c *CancelService) HandleMethod(message protokoll.Message) {
	params := protokoll.CancelParams{}
	err := json.Unmarshal(message.Params, &params)
	if err != nil {
		connectUtils.WriteErrorToCon(c.con, message.ID, err, protokoll.ParseError)
		return
	}
	c.con.BlockResponse(params.ID)

}

func (c *CancelService) GetMethods() []string {
	return []string{"$/cancelRequest"}
}
