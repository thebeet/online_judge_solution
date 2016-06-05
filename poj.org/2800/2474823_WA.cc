#include <stdio.h>
#include <string.h>
#include <math.h>

#define INT long long
#define fmt "%I64d"

int main()
{
	INT i, j, s, n, k, mid;
	scanf(fmt fmt, &n, &k);
	s = 0;
	mid = (INT)(sqrt(k) + 0.000000001);
	if (n <= mid)
	{
		for (i = 1; i <= n; ++i)
		{
			s += k % i;
		}
	}
	else
	{
		INT lo, hi;
		INT st, ed;
		for (i = 1; i <= mid; ++i)
		{
			s += k % i;
		}
		for (j = mid; j >= 0; --j)
		{
			lo = k / (j + 1) + 1;
			if (lo > n)
			{
				break;
			}
			if (j != 0)
			{
				hi = k / j;
				if (hi > n)
				{
					hi = n;
				}
			}
			else
			{
				hi = n;
			}
			st = k % lo;
			ed = k % hi;
			s += (st + ed) * (hi - lo + 1) / 2;
		}
	}
		printf(fmt"\n", s);
	return 0;
}
