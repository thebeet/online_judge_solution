#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
	int i, j, n, m, bm;
	int ans, ansp;
	ansp = 0;
	ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &m);
		bm = m;
		for (j = 2; j * j <= bm; ++j)
		{
			while ((bm % j) == 0)
			{
				bm /= j;
				if (bm == j)
				{
					break;
				}
			}
		}
		if (bm > ansp)
		{
			ansp = bm;
			ans = m;
		}
	}
	printf("%d\n", ans);
	return 0;
}
