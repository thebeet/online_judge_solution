package main

func paintWalls(cost []int, time []int) int {
	dp := [][]int{make([]int, 512), make([]int, 512)}
	N := len(cost)
	for i := range N + 1 {
		dp[0][i] = 1000000000
	}
	dp[0][0] = 0
	for k := range N {
		k0, k1 := k%2, (k+1)%2
		for i := range N + 1 {
			dp[k1][i] = dp[k0][i]
		}
		for i := range N + 1 {
			next := min(N, i+time[k]+1)
			dp[k1][next] = min(dp[k1][next], dp[k0][i]+cost[k])
		}
	}
	return dp[N%2][N]
}

func main() {

}
