package main

import "fmt"

func nthMagicalNumber(n int, a int, b int) int {
	nums := make([]int, 1)
	p1, p2 := a, b
	for {
		if p1 == p2 {
			break
		}
		if p1 < p2 {
			nums = append(nums, p1)
			p1 += a
		} else {
			nums = append(nums, p2)
			p2 += b
		}
	}
	return int(int64(nums[n%len(nums)]) + int64(p1)*int64(n/len(nums))%1000000007)
}

func main() {
	fmt.Println(nthMagicalNumber(4, 2, 3))
}
