#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, m, ans, pr, tans, st;
		ans = 1;
		tans = 1;
		st = 1;
		scanf("%d", &n);
		scanf("%d", &pr);
		for (i = 2; i <= n; ++i)
		{
			scanf("%d", &m);
			if (st == 1)
			{
				if (pr > m)
				{
					st = 2;
					++tans;
				}
				else
				{
					ans = MAX(ans, tans);
					tans = 1;
				}
			}
			else
			{
				if (pr < m)
				{
					st = 1;
					++tans;
				}
				else
				{
					ans = MAX(ans, tans);
					tans = 2;
				}
			}
			pr = m;
		}
		ans = MAX(ans, tans);
		printf("%d\n", ans);
	}
	return 0;
}
