package main

func consecutiveNumbersSum(n int) int {
	sum := 0
	for i := 1; i <= n; i++ {
		if i%2 == 1 {
			d := n / i
			if d < (i+1)/2 {
				break
			}
			if d*i == n {
				sum++
			}
		} else {
			d := n / i
			if d < i/2 {
				break
			}
			if d*i+i/2 == n {
				sum++
			}
		}
	}
	return sum
}
