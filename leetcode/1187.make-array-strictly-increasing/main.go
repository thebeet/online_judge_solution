package main

import (
	"fmt"
	"sort"
)

func RemoveDuplicates(nums []int) []int {
	i := 0
	for j := 1; j < len(nums); j++ {
		if nums[j] != nums[i] {
			i++
			nums[i] = nums[j]
		}
	}
	return nums[:i+1]
}

func makeArrayIncreasing(arr1 []int, arr2 []int) int {
	rank := make(map[int]int)
	inarr2 := make(map[int]bool)
	all := make([]int, 0)
	all = append(all, arr1...)
	all = append(all, arr2...)
	sort.Ints(all)
	all = RemoveDuplicates(all)
	m := len(all)
	for i, v := range all {
		rank[v] = i
	}

	dp := [][]int{
		make([]int, m),
		make([]int, m),
	}
	for i := range m {
		dp[0][i] = 100000
	}
	for _, v := range arr2 {
		dp[0][rank[v]] = 1
		inarr2[rank[v]] = true
	}
	dp[0][rank[arr1[0]]] = 0

	for i := 1; i < len(arr1); i++ {
		pf, pt := (i-1)%2, i%2
		r := rank[arr1[i]]
		for k := range m {
			dp[pt][k] = 100000
		}
		mn := 100000
		for k := range m {
			if r > k {
				dp[pt][r] = min(dp[pt][r], dp[pf][k])
			}
			if _, ok := inarr2[k]; ok {
				dp[pt][k] = min(dp[pt][k], mn+1)
			}
			mn = min(mn, dp[pf][k])
		}
	}
	p := (len(arr1) - 1) % 2
	ans := 100000
	for _, v := range dp[p] {
		ans = min(ans, v)
	}
	if ans >= 100000 {
		ans = -1
	}
	return ans
}

func main() {
	fmt.Println(makeArrayIncreasing([]int{0, 11, 6, 1, 4, 3}, []int{5, 4, 11, 10, 1, 0}))
}
