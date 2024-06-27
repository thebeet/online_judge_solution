package qsort_test

import (
	"math/rand"
	"sort"
	"testing"

	"github.com/stretchr/testify/assert"
	"github.com/thebeet/online_judge_solution/template/algorithm/qsort"
)

func TestSort(t *testing.T) {
	assert := assert.New(t)
	a := rand.Perm(1000)
	qsort.Sort(a)
	for i := 1; i < 1000; i++ {
		assert.True(a[i-1] <= a[i])
	}
}

func BenchmarkQsort(b *testing.B) {
	for n := 0; n < b.N; n++ {
		b.StopTimer()
		a := rand.Perm(1000000)
		b.StartTimer()
		qsort.Sort(a)
	}
}
func BenchmarkQsortParallel(b *testing.B) {
	for n := 0; n < b.N; n++ {
		b.StopTimer()
		a := rand.Perm(1000000)
		b.StartTimer()
		qsort.SortParallel(a)
	}
}

func BenchmarkSort(b *testing.B) {
	for n := 0; n < b.N; n++ {
		b.StopTimer()
		a := rand.Perm(1000000)
		b.StartTimer()
		sort.Ints(a)
	}
}
