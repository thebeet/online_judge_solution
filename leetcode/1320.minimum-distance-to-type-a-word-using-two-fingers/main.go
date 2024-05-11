package main

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minimumDistance(word string) int {
	n := len(word)
	dp := [][][]int{
		make([][]int, 26),
		make([][]int, 26),
	}
	distances := make([][]int, 26)
	for i := range 26 {
		distances[i] = make([]int, 26)
		dp[0][i] = make([]int, 26)
		dp[1][i] = make([]int, 26)
		for j := range 26 {
			distances[i][j] = abs(i/6-j/6) + abs(i%6-j%6)
			dp[0][i][j] = 0
		}
	}

	for k := range n {
		pf, pt := k%2, (k+1)%2
		for i := range 26 {
			for j := range 26 {
				dp[pt][i][j] = 1000000000
			}
		}

		c := int(word[k] - 'A')
		for i := range 26 {
			for j := range 26 {
				if c == i || c == j {
					dp[pt][i][j] = min(dp[pt][i][j], dp[pf][i][j])
				} else {
					dp[pt][c][j] = min(dp[pt][c][j], dp[pf][i][j]+distances[i][c])
					dp[pt][i][c] = min(dp[pt][i][c], dp[pf][i][j]+distances[j][c])
				}
			}
		}
	}
	ans := 1000000000
	pt := n % 2
	for i := range 26 {
		for j := range 26 {
			ans = min(ans, dp[pt][i][j])
		}
	}
	return ans
}
