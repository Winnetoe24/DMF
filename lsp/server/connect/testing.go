package connect

import (
	"bufio"
	"bytes"
	"encoding/json"
	"fmt"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
)

type TestConnection struct {
	ServerIn  *bytes.Buffer
	ServerOut *bytes.Buffer
}

func (h *TestConnection) BlockResponse(id json.RawMessage) {

}

func (h *TestConnection) Close() error {
	return nil
}

var _ Connection = &TestConnection{}

func NewTestConnectionHandle() *TestConnection {
	return &TestConnection{
		ServerIn:  new(bytes.Buffer),
		ServerOut: new(bytes.Buffer),
	}
}

func (h *TestConnection) WriteJson(message string) error {
	bytes := []byte(message)
	header := fmt.Sprintf("Content-Length: %d\r\n\r\n", len(bytes))
	if _, err := h.ServerIn.Write([]byte(header)); err != nil {
		return err
	}
	_, err := h.ServerIn.Write(bytes)
	return err
}
func (h *TestConnection) ReadJson() (string, error) {
	message, err := readMessage(bufio.NewReader(h.ServerOut))
	if err != nil {
		return "", err
	}
	return string(message), nil
}
func (h *TestConnection) WriteMessage(message protokoll.Message) {
	logger := logService.GetLogger()

	// Check Block
	_, err := message.ID.MarshalJSON()
	if err != nil {
		logger.Printf("%sError Decoding ID while Writing Message: %v\n", logService.ERROR, message)
	}
	err = writeMessage(h.ServerOut, message, logger)
	if err != nil {
		logger.Printf("%sError Writing Message: %v\n", logService.ERROR, message)
	}
}

func (h *TestConnection) WaitForMessage() (protokoll.Message, error) {
	data, err := readMessage(bufio.NewReader(h.ServerIn))
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
