package qsort

import (
	"context"
	"sync"
)

func partitionParallel(ctx context.Context, a []int, lo, hi int) {
	s, e := lo, hi
	p := a[(s+e)/2]
	for lo <= hi {
		for a[lo] < p {
			lo++
		}
		for a[hi] > p {
			hi--
		}
		if lo <= hi {
			a[lo], a[hi] = a[hi], a[lo]
			lo++
			hi--
		}
	}

	wg := sync.WaitGroup{}
	if s < hi {
		if s+100 < hi {
			wg.Add(1)
			go func() {
				partitionParallel(ctx, a, s, hi)
				wg.Done()
			}()
		} else {
			partitionParallel(ctx, a, s, hi)
		}
	}
	if lo < e {
		if lo+10000 < e {
			wg.Add(1)
			go func() {
				partitionParallel(ctx, a, lo, e)
				wg.Done()
			}()
		} else {
			partitionParallel(ctx, a, lo, e)
		}
	}
	wg.Wait()
}

func SortParallel(a []int) {
	partitionParallel(context.Background(), a, 0, len(a)-1)
}
