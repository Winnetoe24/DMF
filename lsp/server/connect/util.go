package connect

import (
	"bufio"
	"encoding/json"
	"fmt"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"io"
	"log"
	"strconv"
	"strings"
)

func readMessage(reader *bufio.Reader) ([]byte, error) {
	var contentLength int64

	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			return nil, err
		}
		//logService.GetConnectionLoggerIn().Println(line)
		line = strings.TrimSpace(line)

		if line == "" {
			break
		}

		if strings.HasPrefix(line, "Content-Length: ") {
			length := strings.TrimPrefix(line, "Content-Length: ")
			contentLength, err = strconv.ParseInt(length, 10, 64)
			if err != nil {
				return nil, fmt.Errorf("invalid Content-Length: %v", err)
			}
			logService.GetLogger().Printf("%sRead Content-Length: %d from %s\n", logService.TRACE, contentLength, line)
		}
	}

	content := make([]byte, contentLength)
	_, err := io.ReadFull(reader, content)
	//logService.GetConnectionLoggerIn().Println(string(content))
	if err != nil {
		return nil, err
	}
	logService.GetLogger().Printf("%sRead content: %s\n", logService.TRACE, content)
	return content, nil
}

func writeMessage(writer io.Writer, msg protokoll.Message, logger *log.Logger) error {
	data, err := json.Marshal(msg)
	if err != nil {
		return err
	}

	header := fmt.Sprintf("Content-Length: %d\r\n\r\n", len(data))

	if _, err := writer.Write([]byte(header)); err != nil {
		return err
	}

	logger.Printf("%sSending message: %s\n", logService.INFO, string(data))
	//logService.GetConnectionLoggerOut().Println(string(data))
	_, err = writer.Write(data)
	return err
}
