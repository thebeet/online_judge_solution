#include <stdio.h>
#include <memory.h>

#define d 65535
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int height[2][140010];

int main()
{
	int i, n, q, lo, hi, anslo, anshi;
	memset(height[0], 3, 140010 * sizeof(int));
	memset(height[1], 0, 140010 * sizeof(int));
	
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &height[1][i + d]);
		height[0][i + d] = height[1][i + d];
	}
	for (i = d; i >= 1; --i)
	{
		height[1][i] = MAX(height[1][(i << 1)], height[1][(i << 1) + 1]);
		height[0][i] = MIN(height[0][(i << 1)], height[0][(i << 1) + 1]);
	}
	
	for (i = 1; i <= q; ++i)
	{
		scanf("%d%d", &lo, &hi);
		lo += d;
		hi += d;
		anslo = 10000000;
		anshi = 0;
		for (; lo <= hi; )
		{
			anslo = MIN(anslo, height[0][lo]);
			anslo = MIN(anslo, height[0][hi]);
			anshi = MAX(anshi, height[1][lo]);
			anshi = MAX(anshi, height[1][hi]);
			if (lo == hi) break;
			lo = (lo + 1) >> 1;
			hi = (hi - 1) >> 1;
		}
		printf("%d\n", anshi - anslo);
	}
	return 0;
}	
