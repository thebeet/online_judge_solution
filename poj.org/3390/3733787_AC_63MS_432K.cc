#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][128];

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, m, m2;
		cin >> m >> n;
		m2 = m >> 1;
		memset(dp, 50, sizeof(dp));
		int p0(0);
		int p1(1);
		int leng;
		scanf("%d", &leng);
		dp[p0][leng] = 0;
		for (i = 1; i < n; ++i)
		{
			scanf("%d", &leng);
			memset(dp[p1], 50, sizeof(dp[p1]));
			for (int j = 1; j <= m; ++j)
			{
				if (j + leng < m)
				{
					dp[p1][j + leng + 1] = min(dp[p1][j + leng + 1], dp[p0][j]);
				}
				dp[p1][leng] = min(dp[p1][leng], dp[p0][j] + (m - j) * (m - j));
			}
			swap(p0, p1);
		}
		int minans(0x3fffffff);
		for (int j = 1; j <= m; ++j)
		{
			minans = min(minans, dp[p0][j] + (m - j) * (m - j));
		}
		cout << minans << endl;
	}
	return 0;
}
