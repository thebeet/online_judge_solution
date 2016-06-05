#include <stdio.h>

int inp[65536];
int incnum[65536];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, tot;
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &inp[i]);
		}
		tot = 0;
		for (i = 1; i <= n; ++i)
		{
			int lo = 0;
			int hi = tot + 1;
			while (lo + 1 < hi)
			{
				int mid = (lo + hi) >> 1;
				((incnum[mid] < inp[i]) ? lo : hi) = mid;
			}
			incnum[hi] = inp[i];
			if (hi > tot)
			{
				tot = hi;
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}
