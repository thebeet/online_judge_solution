package main

import "fmt"

type CalcFunc func(start, end int, c int) int

func dpCalc(n int, s string) CalcFunc {
	dp := make([][][]int, n)
	for i := range n {
		dp[i] = make([][]int, n)
		for j := range n {
			dp[i][j] = make([]int, 32)
			for k := range 27 {
				dp[i][j][k] = -1
			}
		}
		for k := range 27 {
			dp[i][i][k] = 1
			if k == int(s[i]-'a')+1 {
				dp[i][i][k] = 0
			}
		}
	}
	var calc CalcFunc
	calc = func(start, end int, c int) int {
		if dp[start][end][c] == -1 {
			result := end - start + 1
			paint := int(s[start]-'a') + 1
			for i := start; i < end; i++ {
				result = min(result, calc(start, i, c)+calc(i+1, end, c))
			}
			for i := start; i < end; i++ {
				result = min(result, calc(start, i, paint)+1+calc(i+1, end, c))
			}
			if paint != c {
				result = min(result, calc(start, end, paint)+1)
			}
			dp[start][end][c] = result
		}
		return dp[start][end][c]
	}
	return calc
}

func strangePrinter(s string) int {
	n := len(s)
	calc := dpCalc(n, s)

	return calc(0, n-1, 0)
}

func main() {
	fmt.Println(strangePrinter("aaabbb"))
}
