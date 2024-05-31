package main

func permuteAll(arr []int) <-chan []int {
	c := make(chan []int, 0)
	n := len(arr)
	a := make([]int, n)
	for i := range n {
		a[i] = i
	}
	go func() {
		for {
			result := make([]int, n)
			for i, v := range a {
				result[i] = arr[v]
			}
			c <- result

			i := n - 2
			for i >= 0 && a[i] > a[i+1] {
				i--
			}
			if i == -1 {
				close(c)
				break
			}
			j := n - 1
			for a[j] < a[i] {
				j--
			}
			a[i], a[j] = a[j], a[i]
			for k, l := i+1, n-1; k < l; k, l = k+1, l-1 {
				a[k], a[l] = a[l], a[k]
			}
		}
	}()
	return c
}

func permute(nums []int) [][]int {
	result := make([][]int, 0)
	for v := range permuteAll(nums) {
		result = append(result, v)
	}
	return result
}
