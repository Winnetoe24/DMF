package main

import (
	"flag"
	"log"
	"net"
	"os"
	"sync"
)

func main() {
	address := flag.String("address", "localhost:8080", "server address")
	flag.Parse()
	if address == nil || *address == "" {
		log.Panic("address is required")
	}
	dial, err := net.Dial("tcp", *address)
	if err != nil {
		log.Panic("dial error:", err)
	}
	group := sync.WaitGroup{}
	group.Add(1)
	go func() {
		_, err2 := os.Stdin.WriteTo(dial)
		if err2 != nil {
			log.Println(err2)
			group.Done()
		}
	}()
	go func() {
		_, err2 := os.Stdout.ReadFrom(dial)
		if err2 != nil {
			log.Println(err2)
			group.Done()
		}
	}()
	group.Wait()
}
