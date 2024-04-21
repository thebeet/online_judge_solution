package main

import "sort"

func earliestFullBloom(plantTime []int, growTime []int) int {
	n := len(plantTime)
	id := make([]int, n)
	for i := range n {
		id[i] = i
	}
	sort.Slice(id, func(i, j int) bool {
		return growTime[id[i]] > growTime[id[j]]
	})
	mx := 0
	plantTimeSum := 0
	for i := range n {
		plantTimeSum += plantTime[id[i]]
		mx = max(mx, plantTimeSum+growTime[id[i]])
	}
	return mx
}

func main() {

}
