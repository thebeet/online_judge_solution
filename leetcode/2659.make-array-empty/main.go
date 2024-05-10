package main

import (
	"sort"
)

func countOperationsToEmptyArray(nums []int) int64 {
	n := len(nums)
	indices := make([]int, n)
	for i := range n {
		indices[i] = i
	}
	sort.Slice(indices, func(a, b int) bool {
		return nums[indices[a]] < nums[indices[b]]
	})
	sum := int64(n)
	for i := 1; i < n; i++ {
		if indices[i] < indices[i-1] {
			sum += int64(n - i)
		}
	}
	return sum
}
