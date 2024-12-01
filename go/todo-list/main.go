package main

import (
	"flag"
	"fmt"
)

type taskType struct {
	id          int
	description string
	completed   bool
	startedTime float64
	dueTime     float64
}

type commandType struct {
	opcode      string
	description string
	//action      func()
}

var commands = []commandType{
	{"add", "Add a new task to the todo list"},
	{"completed", "Mark a task as completed"},
	{"delete", "Remove a task from the todo list, by its id"},
	{"list", "Display all tasks in the todo list"},
	{"help", "Help about any command"},
}

func main() {
	flag.Parse()

	fmt.Println("ToDo list for terminal application v0.1\n")
	fmt.Println("Usage:\n\ttasks[command]\n")
	fmt.Println("Available commands:")

	for _, cmd := range commands {
		message := fmt.Sprintf("%s\t%s", cmd.opcode, cmd.description)
		fmt.Println(message)
	}
	fmt.Println("")
}
