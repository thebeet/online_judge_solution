package main

import (
	"fmt"
	"sort"
)

type MeetTime struct {
	time int
	op   int
}

func calcMax(meetings [][]int) int {
	n := len(meetings)
	meetTime := make([]MeetTime, n*2)
	for i, v := range meetings {
		meetTime[i*2] = MeetTime{
			time: v[0],
			op:   1,
		}
		meetTime[i*2+1] = MeetTime{
			time: v[1],
			op:   -1,
		}
	}
	sort.Slice(meetTime, func(i, j int) bool {
		if meetTime[i].time != meetTime[j].time {
			return meetTime[i].time < meetTime[j].time
		} else {
			return meetTime[i].op < meetTime[j].op
		}
	})

	mx := 0
	current := 0
	for _, v := range meetTime {
		if v.op == -1 {
			current--
		}
		if v.op == 1 {
			current++
			if current > mx {
				mx = current
			}
		}
	}
	return mx
}

func main() {
	fmt.Println(calcMax([][]int{{0, 30}, {5, 10}, {15, 20}}))
	fmt.Println(calcMax([][]int{{0, 30}, {5, 10}, {9, 20}}))
	fmt.Println(calcMax([][]int{{7, 10}, {2, 4}}))

}
