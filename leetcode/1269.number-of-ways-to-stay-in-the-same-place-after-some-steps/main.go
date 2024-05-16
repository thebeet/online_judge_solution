package main

func numWays(steps int, arrLen int) int {
	P := 1000000007
	n := min(steps+1, arrLen)
	ans := [][]int{
		make([]int, n),
		make([]int, n),
	}
	ans[0][0] = 1
	for i := range steps {
		pf, pt := i%2, (i+1)%2
		for i := range n {
			ans[pt][i] = ans[pf][i]
			if i > 0 {
				ans[pt][i] = (ans[pt][i] + ans[pf][i-1]) % P
			}
			if i+1 < n {
				ans[pt][i] = (ans[pt][i] + ans[pf][i+1]) % P
			}
		}
	}
	return ans[steps%2][0]
}
