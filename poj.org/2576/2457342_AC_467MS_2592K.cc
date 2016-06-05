#include <stdio.h>
#include <string.h>

bool dp[55][45100];

int main()
{
	int i, j, h, k, n, m, sum;
	scanf("%d", &n);
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	sum = 0;
	for (i = 1, k = 1; i <= n; ++i, ++k)
	{
		 scanf("%d", &m);
		 if (k > ((n + 1) / 2))
		 {
		 	k = ((n + 1) / 2);
		 }
		 for (j = k - 1; j >= 0; --j)
		 {
		 	 for (h = sum; h >= 0; --h)
		 	 {
		 	 	dp[j + 1][h + m] |= dp[j][h];
		 	 }
		 }
		 sum += m;
	}
	for (i = sum / 2; ; --i)
	{
		if (dp[(n / 2)][i] || dp[(n / 2)][sum - i] || dp[((n + 1) / 2)][i] || dp[((n + 1) / 2)][sum - i])
		{
			break;
		}
	}
	printf("%d %d\n", i, sum - i);
	return 0;
}
