package main

import "fmt"

var ops []rune = []rune{'+', '-', '*', '/'}

func eq(a, b float64) bool {
	return (a+1e-10 > b) && (a-1e-10 < b)
}

func permuteAll(arr []int) <-chan []int {
	c := make(chan []int)
	n := len(arr)
	a := make([]int, n)
	for i := range n {
		a[i] = i
	}
	go func() {
		for {
			result := make([]int, n)
			for i, v := range a {
				result[i] = arr[v]
			}
			c <- result

			i := n - 2
			for i >= 0 && a[i] > a[i+1] {
				i--
			}
			if i == -1 {
				close(c)
				return
			}
			j := n - 1
			for a[j] < a[i] {
				j--
			}
			a[i], a[j] = a[j], a[i]
			for k, l := i+1, n-1; k < l; k, l = k+1, l-1 {
				a[k], a[l] = a[l], a[k]
			}
		}
	}()
	return c
}

type suffixOpEle struct {
	op  rune
	num int
}

func calc(arr []suffixOpEle) (float64, error) {
	stack := make([]float64, 0)
	for _, v := range arr {
		if v.op != 'n' && len(stack) < 2 {
			return 0., fmt.Errorf("op error")
		}
		switch v.op {
		case 'n':
			stack = append(stack, float64(v.num))
		case '+':
			n1, n2 := stack[len(stack)-1], stack[len(stack)-2]
			stack = append(stack[0:len(stack)-2], n1+n2)
		case '-':
			n1, n2 := stack[len(stack)-1], stack[len(stack)-2]
			stack = append(stack[0:len(stack)-2], n1-n2)
		case '*':
			n1, n2 := stack[len(stack)-1], stack[len(stack)-2]
			stack = append(stack[0:len(stack)-2], n1*n2)
		case '/':
			n1, n2 := stack[len(stack)-1], stack[len(stack)-2]
			if eq(n2, 0.) {
				return 0., fmt.Errorf("divid by zero")
			}
			stack = append(stack[0:len(stack)-2], n1/n2)
		}
	}
	return stack[len(stack)-1], nil
}

func bruteforce(c chan<- []suffixOpEle, cards []int, arr []suffixOpEle, p int, s int) {
	if s < 2 {
		if p == len(cards) {
			clone := make([]suffixOpEle, len(arr))
			copy(clone, arr)
			c <- clone
		} else {
			bruteforce(c, cards, append(arr, suffixOpEle{
				op:  'n',
				num: cards[p],
			}), p+1, s+1)
		}
	} else {
		if p < len(cards) {
			bruteforce(c, cards, append(arr, suffixOpEle{
				op:  'n',
				num: cards[p],
			}), p+1, s+1)
		}
		for _, op := range ops {
			bruteforce(c, cards, append(arr, suffixOpEle{
				op:  op,
				num: 0,
			}), p, s-1)
		}
	}
}

func judgePoint24(cards []int) bool {
	c := make(chan []suffixOpEle)
	go func() {
		p := permuteAll(cards)
		for nums := range p {
			arr := make([]suffixOpEle, 0)
			bruteforce(c, nums, arr, 0, 0)
		}
		close(c)
	}()
	result := false
	for v := range c {
		r, err := calc(v)
		if err == nil && eq(r, 24.) {
			result = true
		}
	}
	return result
}

func main() {
	fmt.Println(judgePoint24([]int{4, 1, 8, 7}))
}
