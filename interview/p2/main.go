package main

import (
	"fmt"
)

type Node struct {
	Value int
	Left  *Node
	Right *Node
}

func split(str string) (string, string) {
	stack := 0
	for i, c := range str {
		if c == '(' {
			stack++
		} else if c == ')' {
			stack--
			if stack == 0 {
				return str[1:i], str[i+2 : len(str)-1]
			}
		}
	}
	return "", ""
}

func parse(str string) *Node {
	if str == "#" {
		return nil
	}
	node := &Node{
		Value: int(str[0] - '0'),
	}
	if len(str) == 1 {
		return node
	}
	left, right := split(str[1:])
	node.Left = parse(left)
	node.Right = parse(right)
	return node
}

func main() {
	// var a int
	// fmt.Scan(&a)
	fmt.Println(parse("1(2)(3)"))
}
