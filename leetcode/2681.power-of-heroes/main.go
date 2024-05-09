package main

import (
	"fmt"
	"slices"
)

var P = int64(1000000007)

func sumOfPower(nums []int) int {
	slices.Sort(nums)
	result := int64(0)
	sq := int64(0)
	for i := len(nums) - 1; i >= 0; i-- {
		tsq := int64(nums[i]) * int64(nums[i]) % P
		result = (result + int64(nums[i])*(sq+tsq)) % P
		sq = (sq*int64(2) + tsq) % P
	}
	return int(result)
}

func main() {
	fmt.Printf("%d", sumOfPower([]int{1, 2, 4}))
}
