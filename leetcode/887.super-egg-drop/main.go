package main

import "fmt"

func superEggDrop(k int, n int) int {
	dp := [][]int{
		make([]int, k+1),
		make([]int, k+1),
	}
	pf, pt := 0, 1
	ans := 0
	for dp[pf][k] < n {
		fmt.Println(dp)
		ans++
		for i := 1; i < k+1; i++ {
			dp[pt][i] = 1 + dp[pf][i] + dp[pf][i-1]
		}

		pt, pf = pf, pt
	}

	return ans
}

func main() {
	fmt.Println(superEggDrop(5, 1000))
}
