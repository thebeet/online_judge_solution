#include <stdio.h>
#include <memory.h>

double dp[110][11];

int main()
{
	int i, j, n, k;
	double s;
	while (scanf("%d%d", &k, &n) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		for (j = 1; j <= k + 1; ++j)
		{
			dp[1][j] = 100.0 / (k + 1);
		}
		for (i = 2; i <= n; ++i)
		{
			for (j = 1; j <= k + 1; ++j)
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) / (k + 1);
			}
		}
		s = 0.0;
		for (j = 1; j <= k + 1; ++j)
		{
			s += dp[n][j];
		}
		printf("%.5lf\n", s);
	}
	return 0;
}
