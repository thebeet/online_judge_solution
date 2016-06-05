#include <stdio.h>

#define MAXN 100010
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int cost[MAXN];



int main()
{
	int i, n, k, lo, hi, mid, fn, st;
	scanf("%d%d", &n, &k);
	lo = 0;
	hi = 0;
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &cost[i]);
		lo = MAX(lo, cost[i]);
		hi += cost[i];
	}
	--lo;
	while (lo + 1 < hi)
	{
		mid = (lo + hi) >> 1;
		
		fn = 1;
		st = 0;
		
		for (i = 1; i <= n; ++i)
		{
			st += cost[i];
			if (st > mid)
			{
				++fn;
				if (fn > k)
				{
					break;
				}
				st = cost[i];
			}
		}
		if (i <= n)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	printf("%d\n", hi);
	return 0;
}
