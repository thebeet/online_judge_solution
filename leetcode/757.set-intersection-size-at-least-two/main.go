package main

import "sort"

func intersectionSizeTwo(intervals [][]int) int {
	sort.SliceStable(intervals, func(i, j int) bool {
		if intervals[i][1] == intervals[j][1] {
			return intervals[i][0] > intervals[j][0]
		}
		return intervals[i][1] < intervals[j][1]
	})
	nums := make([]int, 0)
	for _, v := range intervals {
		c := 0
		for i := len(nums) - 1; i >= max(len(nums)-2, 0); i-- {
			if nums[i] >= v[0] {
				c++
			}
		}
		if c == 0 {
			nums = append(nums, v[1]-1)
			nums = append(nums, v[1])
		} else if c == 1 {
			nums = append(nums, v[1])
		}
	}
	return len(nums)
}

func main() {

}
