package main

import "fmt"

type ZeroValueMap map[int]int

func NewZeroValueMap() ZeroValueMap {
	return make(map[int]int)
}

func (z ZeroValueMap) get(key int) int {
	if v, ok := z[key]; ok {
		return v
	} else {
		return 0
	}
}

func (z ZeroValueMap) set(key int, reducer func(int) int) int {
	if v, ok := z[key]; ok {
		z[key] = reducer(v)
	} else {
		z[key] = reducer(0)
	}
	return z[key]
}

func (z ZeroValueMap) inc(key int) int {
	return z.set(key, func(v int) int {
		return v + 1
	})
}

func (z ZeroValueMap) dec(key int) int {
	return z.set(key, func(v int) int {
		return v - 1
	})
}

type LampArray struct {
	row       ZeroValueMap
	col       ZeroValueMap
	diagonal1 ZeroValueMap
	diagonal2 ZeroValueMap
	n         int

	lamps map[int]ZeroValueMap
}

func NewLampArray(n int) *LampArray {
	la := &LampArray{}
	la.row = NewZeroValueMap()
	la.col = NewZeroValueMap()
	la.diagonal1 = NewZeroValueMap()
	la.diagonal2 = NewZeroValueMap()
	la.n = n
	la.lamps = make(map[int]ZeroValueMap)
	return la
}

func (la *LampArray) AddLamp(x, y int) {
	la.row.inc(x)
	la.col.inc(y)
	la.diagonal1.inc(x - y + la.n)
	la.diagonal2.inc(y + x)

	if v, ok := la.lamps[x]; ok {
		v.inc(y)
	} else {
		la.lamps[x] = NewZeroValueMap()
		la.lamps[x][y] = 1
	}
}

func (la *LampArray) RemoveLamp(x, y int) {
	if v, ok := la.lamps[x]; ok {
		if c := v.get(y); c > 0 {
			reducer := func(v int) int {
				return v - c
			}
			la.row.set(x, reducer)
			la.col.set(y, reducer)
			la.diagonal1.set(x-y+la.n, reducer)
			la.diagonal2.set(y+x, reducer)
			v.set(y, func(int) int {
				return 0
			})
		}
	}
}

func (la *LampArray) Query(x, y int) int {
	if la.row.get(x) > 0 || la.col.get(y) > 0 || la.diagonal1.get(x-y+la.n) > 0 || la.diagonal2.get(x+y) > 0 {
		return 1
	} else {
		return 0
	}
}

func gridIllumination(n int, lamps [][]int, queries [][]int) []int {
	la := NewLampArray(n)
	for _, lamp := range lamps {
		la.AddLamp(lamp[0], lamp[1])
	}
	m := len(queries)
	result := make([]int, m)
	for i, query := range queries {
		result[i] = la.Query(query[0], query[1])
		if result[i] > 0 {
			for i := -1; i <= 1; i++ {
				for j := -1; j <= 1; j++ {
					tx := query[0] + i
					ty := query[1] + j
					if tx >= 0 && ty >= 0 && tx < n && ty < n {
						la.RemoveLamp(tx, ty)
					}
				}
			}
		}
	}
	return result
}

func main() {
	fmt.Printf("%v", gridIllumination(5, [][]int{{0, 0}, {4, 4}}, [][]int{{1, 1}, {1, 0}}))
}
