package main

import (
	"bytes"
	"fmt"
	"net/http"
	"os"

	"github.com/joho/godotenv"
)

var created bool = false
var BASE_URL = "https://api.machines.dev"

func machineCreateUrl() string {
	return fmt.Sprintf("%s/v1/apps/my-app-name/machines", BASE_URL)
}

func createMachine() error {
	return nil
}

func main() {
	godotenv.Load()
	url := machineCreateUrl()

	fmt.Println("WFT !\n")
	body := []byte(`{
    "name": "vim-arcade",
    "config": {
      "image": "registry.fly.io/"
      "env": "APP_ENV"
    },
    "services": [
    ]
  }`)

	r, err := http.NewRequest("POST", machineCreateUrl(), bytes.NewBuffer(body))
	if err != nil {
		return
	}

	r.Header.Add("Content-Type", "application-json")
	r.Header.Add("Authorization", fmt.Sprintf("Bearer %s", os.Getenv("FLY_IO_ORG_TOKEN")))

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "Hello from Go HTTP Server!\n")
	})

	fmt.Println("Server listening on http://localhost:8080")
	http.ListenAndServe(":8081", nil)

	client := &http.Client{}

	client.Do(r)
}
