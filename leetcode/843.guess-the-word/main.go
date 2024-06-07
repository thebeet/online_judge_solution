package main

import "math/rand"

type Master struct {
}

func (this *Master) Guess(word string) int {
	return 0
}

func testWord(word string, secret string) int {
	c := 0
	for i := range 6 {
		if word[i] == secret[i] {
			c++
		}
	}
	return c
}

func filter(words []string, guess string, k int) []string {
	res := make([]string, 0)
	for _, w := range words {
		t := testWord(w, guess)
		if k == t {
			res = append(res, w)
		}
	}
	return res
}

func findSecretWord(words []string, master *Master) {
	alive := words
	for len(alive) > 0 {
		m := rand.Intn(len(alive))
		r := master.Guess(alive[m])
		if r == 6 {
			break
		}
		alive = filter(alive, alive[m], r)
	}
}
