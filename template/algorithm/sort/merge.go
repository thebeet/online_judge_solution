package main

func merge(arr1, arr2 []int) []int {
	result := make([]int, 0)
	p1, p2 := 0, 0
	for range len(arr1) + len(arr2) {
		t := 1
		if p1 == len(arr1) {
			t = 2
		} else if p2 == len(arr2) {
			t = 1
		} else if arr1[p1] > arr2[p2] {
			t = 2
		}
		if t == 1 {
			result = append(result, arr1[p1])
			p1++
		} else {
			result = append(result, arr2[p2])
			p2++
		}
	}
	return result
}

func mergeSort(arr []int) []int {
	if len(arr) >= 2 {
		mid := len(arr) / 2
		arr1 := mergeSort(arr[:mid])
		arr2 := mergeSort(arr[mid:])
		arr := merge(arr1, arr2)
		return arr
	} else {
		return arr
	}
}
