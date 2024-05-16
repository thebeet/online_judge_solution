package main

func stoneGameIII(stoneValue []int) string {
	n := len(stoneValue)
	tStoneValue := append(stoneValue, 0, 0)
	scores := make([]int, n+3)
	for i := n - 1; i >= 0; i-- {
		scores[i] = max(
			tStoneValue[i]-scores[i+1],
			tStoneValue[i]+tStoneValue[i+1]-scores[i+2],
			tStoneValue[i]+tStoneValue[i+1]+tStoneValue[i+2]-scores[i+3],
		)
	}
	switch {
	case scores[0] > 0:
		return "Alice"
	case scores[0] < 0:
		return "Bob"
	default:
		return "Tie"
	}
}
