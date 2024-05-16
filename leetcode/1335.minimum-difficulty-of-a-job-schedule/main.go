package main

import "fmt"

func minDifficulty(jobDifficulty []int, d int) int {
	n := len(jobDifficulty)
	dp := [][]int{
		make([]int, n+1),
		make([]int, n+1),
	}
	for j := range n + 1 {
		dp[0][j] = -1
	}
	dp[0][0] = 0

	for i := range d {
		pf, pt := i%2, (i+1)%2
		for j := range n + 1 {
			dp[pt][j] = -1
		}

		fmt.Println(dp)

		for j := range n + 1 {
			if dp[pf][j] == -1 {
				continue
			}
			difficulty := 0
			for k := j + 1; k <= n; k++ {
				difficulty = max(difficulty, jobDifficulty[k-1])
				if dp[pt][k] == -1 || dp[pf][j]+difficulty < dp[pt][k] {
					dp[pt][k] = dp[pf][j] + difficulty
				}
			}
		}
		fmt.Println(dp)
	}
	return dp[d%2][n]
}

func main() {
	fmt.Println(minDifficulty([]int{6, 5, 4, 3, 2, 1}, 2))
}
