package main

import (
	"fmt"
	"strconv"
)

var ten = []int{
	1, 10, 100, 1000, 10000,
	100000, 1000000, 10000000, 100000000, 1000000000,
}

func calc(digits []int, n int, k int) int {
	if k == -1 {
		return 1
	}
	if n/10 >= ten[k] {
		sum := 1
		for range k + 1 {
			sum *= len(digits)
		}
		return sum
	}
	sum := 0
	for _, v := range digits {
		if n >= ten[k]*v {
			sum += calc(digits, n-ten[k]*v, k-1)
		}
	}
	return sum
}

func atMostNGivenDigitSet(digits []string, n int) int {
	d := make([]int, len(digits))
	for i, v := range digits {
		d[i], _ = strconv.Atoi(v)
	}
	sum := 0
	for i := 0; i <= 8; i++ {
		sum += calc(d, n, i)
	}
	return sum
}

func main() {
	fmt.Println(atMostNGivenDigitSet([]string{"1", "4", "9"}, 1000000000))
}
