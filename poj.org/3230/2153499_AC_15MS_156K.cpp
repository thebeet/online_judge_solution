#include <stdio.h>
#include <memory.h>

#define MAXN 110

long map[MAXN][MAXN];
long income[MAXN][MAXN];
long dp[MAXN][MAXN];
long n, m;

long mx(long a, long b)
{
	return (a > b) ? a : b;
}

int main()
{
	long i, j, k, ans;
	while (scanf("%ld%ld", &n, &m), n > 0)
	{
		memset(map, 0, sizeof(map));
		memset(income, 0, sizeof(income));
		memset(dp, 200, sizeof(dp));
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%ld", &map[i][j]);
			}
		}
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%ld", &income[i][j]);
			}
		}
		dp[0][1] = 0;
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				for (k = 1; k <= n; k++)
				{
					dp[i][j] = mx(dp[i][j], dp[i - 1][k] - map[k][j] + income[i][j]);
				}
			}
		}
		ans = -1000000;
		for (i = 1; i <= n; i++)
		{
			ans = mx(ans, dp[m][i]);
		}
		printf("%ld\n", ans);
	}
	return 0;
}
