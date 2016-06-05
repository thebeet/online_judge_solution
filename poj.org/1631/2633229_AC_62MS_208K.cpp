#include <stdio.h>

int ans[65536];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, m, tot;
		tot = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &m);
			int lo = 0;
			int hi = tot + 1;
			while (lo + 1 < hi)
			{
				int mid = (lo + hi) >> 1;
				((ans[mid] < m) ? lo : hi) = mid;
			}
			ans[hi] = m;
			if (hi > tot)
			{
				tot = hi;
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}