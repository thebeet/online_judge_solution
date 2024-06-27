package qsort

import (
	"context"
)

func partition(ctx context.Context, a []int) {
	lo, hi := 0, len(a)-1
	p := a[(lo+hi)/2]
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

	if 0 < hi {
		partition(ctx, a[:hi+1])
	}
	if lo < len(a)-1 {
		partition(ctx, a[lo:])
	}
}

func Sort(a []int) {
	partition(context.Background(), a)
}
