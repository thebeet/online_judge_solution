#include <stdio.h>
#include <algorithm>

using namespace std;

int pos[4096];
int dp[2][2][4096];

int main()
{
	int i, k, n, l, p1, p2;
	scanf("%d%d", &n, &l);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &pos[i]);
	}
	sort(pos + 1, pos + 1 + n);
	
	p1 = 0;
	p2 = 1;
	dp[0][0][1] = 0;
	dp[0][1][1] = 0;
	for (k = n - 2; k >= 0; --k)
	{
		int invk = (n - k);
		//memset(dp[p2], 127, sizeof(dp[p2]));
		dp[p2][0][1] = dp[p1][1][1] + (invk - 1) * (pos[k + 2] - pos[1]);
		dp[p2][1][1] = dp[p1][1][1] + (invk - 1) * (pos[k + 2] - pos[k + 1]);
		for (i = 2; i < invk; ++i)
		{
			dp[p2][0][i] = dp[p1][1][i] + (invk - 1) * (pos[k + i + 1] - pos[i]);
			dp[p2][1][i] = dp[p1][1][i] + (invk - 1) * (pos[k + i + 1] - pos[k + i]);
			dp[p2][0][i] = min(dp[p2][0][i], dp[p1][0][i - 1] + (invk - 1) * (pos[i] - pos[i - 1]));
			dp[p2][1][i] = min(dp[p2][1][i], dp[p1][0][i - 1] + (invk - 1) * (pos[k + i] - pos[i - 1]));
		}
		dp[p2][0][i] = dp[p1][0][i - 1] + (invk - 1) * (pos[i] - pos[i - 1]);
		dp[p2][1][i] = dp[p1][0][i - 1] + (invk - 1) * (pos[k + i] - pos[i - 1]);
		p1 ^= 1;
		p2 ^= 1;
	}
	int ans = 2000000000;
	for (i = 1; i <= n; ++i)
	{
		ans = min(ans, dp[p1][0][i] + abs(pos[i] - l) * n);
	}
	printf("%d\n", ans);
	return 0;
}