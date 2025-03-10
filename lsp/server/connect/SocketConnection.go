package connect

import (
	"bufio"
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"net"
)

var _ Connection = &SocketConnection{}

type SocketConnection struct {
	conn     net.Conn
	in       *bufio.Reader
	blockMap map[string]bool
	// Zur synchronisation paralleler Schreibvorgänge
	actionChannel chan func()
}

func NewSocketConnection(conn net.Conn) *SocketConnection {
	return &SocketConnection{
		conn:          conn,
		in:            bufio.NewReader(conn),
		blockMap:      make(map[string]bool),
		actionChannel: createAktionsChannel(),
	}
}

func (s *SocketConnection) WriteMessage(message protokoll.Message) {
	logger := logService.GetLogger()

	// Check Block
	marshalJSON, err := message.ID.MarshalJSON()
	if err != nil {
		logger.Printf("%sError Decoding ID while Writing Message: %v\n", logService.ERROR, message)
	}
	s.actionChannel <- func() {
		if err == nil {
			if s.blockMap[string(marshalJSON)] {
				logger.Printf("%sBlocked Message: %v\n", logService.TRACE, message)
				return
			}
		}
		err = writeMessage(s.conn, message, logger)
		if err != nil {
			logger.Printf("%sError Writing Message: %v\n", logService.ERROR, message)
		}
	}
}

func (s *SocketConnection) WaitForMessage() (protokoll.Message, error) {
	return handleWaitForMessage(s.in)
}

func (s *SocketConnection) BlockResponse(id json.RawMessage) {
	marshalJSON, err := id.MarshalJSON()
	if err != nil {
		logger := logService.GetLogger()
		logger.Printf("%sError While Decoding ID for BlockResponse: %v\n", logService.ERROR, err)
	} else {
		s.actionChannel <- func() {
			s.blockMap[string(marshalJSON)] = true
		}
	}
}

func (s *SocketConnection) Close() error {
	var result = make(chan error)
	defer close(result)
	s.actionChannel <- func() {
		result <- s.conn.Close()
	}
	return <-result
}
