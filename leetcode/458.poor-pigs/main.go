package main

import (
	"fmt"
)

func poorPigs(buckets int, minutesToDie int, minutesToTest int) int {
	n := minutesToTest / minutesToDie
	dp := make([][]int, n+1)
	for i := range n + 1 {
		dp[i] = make([]int, buckets+1)
	}

	C := func(a, b int) int {
		r := 1
		for i := range b {
			r *= i + 1
		}
		for i := range a {
			r /= i + 1
		}

		for i := range b - a {
			r /= i + 1
		}
		return r
	}

	var calc func(c, t int) int
	calc = func(c, t int) int {
		if dp[t][c] == 0 {
			if t == 1 {
				dp[t][c] = 1 << c
			} else {
				sum := 0
				for i := 0; i <= c; i++ {
					sum += calc(i, t-1) * C(i, c)
				}
				dp[t][c] = sum
			}
		}
		return dp[t][c]
	}
	for ans := 0; ; ans++ {
		if calc(ans, n) >= buckets {
			return ans
		}
	}
}

func main() {
	fmt.Println(poorPigs(1000, 15, 60))
}
