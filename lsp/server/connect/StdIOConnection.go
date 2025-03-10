package connect

import (
	"bufio"
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"os"
)

type StdIOConnection struct {
	in       *bufio.Reader
	out      *os.File
	blockMap map[string]bool
	// Zur synchronisation paralleler Schreibvorgänge
	actionChannel chan func()
}

func NewStdIOConnection() *StdIOConnection {
	return &StdIOConnection{
		in:            bufio.NewReader(os.Stdin),
		out:           os.Stdout,
		blockMap:      make(map[string]bool),
		actionChannel: createAktionsChannel(),
	}

}

func createAktionsChannel() chan func() {
	channel := make(chan func(), 2)
	// AktionsSynchronisations Routine
	go func() {
		for f := range channel {
			f()
		}
	}()
	return channel
}

func (s *StdIOConnection) WriteMessage(message protokoll.Message) {
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
		err = writeMessage(s.out, message, logger)
		if err != nil {
			logger.Printf("%sError Writing Message: %v\n", logService.ERROR, message)
		}
	}
}

func (s *StdIOConnection) WaitForMessage() (protokoll.Message, error) {
	data, err := readMessage(s.in)
	if err != nil {
		return protokoll.Message{}, err
	}
	message := protokoll.Message{}
	err = json.Unmarshal(data, &message)
	if err != nil {
		return protokoll.Message{}, err
	}
	return message, nil
}
func (s *StdIOConnection) BlockResponse(id json.RawMessage) {
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

func (s *StdIOConnection) Close() error {
	var result = make(chan error)
	defer close(result)
	s.actionChannel <- func() { result <- s.out.Close() }
	return <-result
}
