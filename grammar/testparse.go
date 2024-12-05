package main

import (
	"fmt"

	"os"
)

func main() {
	_, err := os.ReadFile(os.Args[1])
	if err != nil {
		panic(fmt.Sprintf("Error reading file: %e", err))
	}

}
