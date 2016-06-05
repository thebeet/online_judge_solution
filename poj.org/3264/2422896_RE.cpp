#include <stdio.h>
#include <memory.h>

#define d 65535
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int height[2][140010];

int main()
{
	int i, n, q, lo, hi, plo, phi, anslo, anshi;
	memset(height[0], 50, 140010 * sizeof(int));
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
		plo = lo;
		phi = hi;
		anslo = 100000000;
		anshi = -1;
		for (; plo <= phi; )
		{
			anslo = MIN(anslo, height[0][plo]);
			anslo = MIN(anslo, height[0][phi]);
			anshi = MAX(anshi, height[1][plo]);
			anshi = MAX(anshi, height[1][phi]);
			if (plo == phi) break;
			plo = (plo + 1) >> 1;
			phi = (phi - 1) >> 1;
		}
		printf("%d\n", anshi - anslo);
	}
	return 0;
}	
