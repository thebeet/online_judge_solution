package main

import "sort"

type Line struct {
	height int
	pos    int
}

func maxArea(height []int) int {
	lines := make([]Line, len(height))
	for i, h := range height {
		lines[i] = Line{h, i}
	}
	sort.Slice(lines, func(i, j int) bool {
		return lines[i].height < lines[j].height
	})
	return 0
}
