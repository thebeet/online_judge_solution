#include <stdio.h>
#include <memory.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int dp[410][410];

int main()
{
	int i, j, n, m;
	scanf("%d", &n);
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			scanf("%d", &m);
			dp[i][j] = MAX(dp[i - 1][j - 1], dp[i - 1][j]) + m;
		}
	}
	m = dp[n][1];
	for (i = 2; i <= n; ++i)
	{ 
		m = MAX(m, dp[n][i]);
	}
	printf("%d\n", m);
	return 0;
}
