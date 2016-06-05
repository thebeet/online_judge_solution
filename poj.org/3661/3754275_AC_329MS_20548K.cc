#include <iostream>
#include <algorithm>

using namespace std;

int d[10010];
int dp[10010][512];

int main()
{
	int i, j, n, m;
	cin >> n >> m;
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &d[i]);
	}
	memset(dp, 200, sizeof(dp));
	dp[0][0] = 0;
	for (i = 1; i <= n; ++i)
	{
		dp[i][0] = dp[i - 1][0];
		for (j = 1; j <= m; ++j)
		{
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + d[i]);
			if (i >= j)
			{
				dp[i][0] = max(dp[i][0], dp[i - j][j]);
			}
		}
	}
	cout << dp[n][0] << endl;
	return 0;
}
