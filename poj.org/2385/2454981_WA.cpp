#include <stdio.h>
#include <string.h>

int dp[30][2];

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main()
{
	int t, w, m, ans;
	scanf("%d%d", &t, &w);
	memset(dp, 0, sizeof(dp));
	ans = 0;
	dp[0][1] = -10000;
	for (int i = 1; i <= t; ++i)
	{
		scanf("%d", &m);
		--m;
		for (int j = w; j >= 0; --j)
		{
			dp[j][m] = MAX(dp[j][m], dp[j - 1][m ^ 1]) + 1;
			ans = MAX(ans, dp[j][m]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
