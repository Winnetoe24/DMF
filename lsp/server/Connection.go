package server

type Connection interface {
	// WriteMessage Writes Message. May queue the Message the syncronise the Writing
	WriteMessage(message Message)

	// WaitForMessage Waits for the next Message and returns the Message or the error.
	// Call to this method blocks execution.
	WaitForMessage() (Message, error)
}

type Message string
