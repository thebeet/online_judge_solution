package main

import "fmt"

func rotate(nums []int, k int) {
	n := len(nums)
	rk := k % n
	newarr := append(nums[rk:], nums[:rk]...)
	for i := range n {
		nums[i] = newarr[i]
	}
}

func main() {
	a := []int{1, 2, 3, 4, 5, 6, 7}
	rotate(a, 3)
	fmt.Println(a)
}
