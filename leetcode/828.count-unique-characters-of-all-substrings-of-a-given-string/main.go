package main

func uniqueLetterString(s string) int {
	n := len(s)
	sum := 0
	pos := make([][]int, 26)
	for k := range 26 {
		pos[k] = make([]int, 0)
		pos[k] = append(pos[k], -1)
	}
	for i, c := range s {
		ci := int(c - 'A')
		pos[ci] = append(pos[ci], i)
	}
	for k := range 26 {
		pos[k] = append(pos[k], n)
		for i := 1; i < len(pos[k])-1; i++ {
			sum += (pos[k][i] - pos[k][i-1]) * (pos[k][i+1] - pos[k][i])
		}
	}
}
