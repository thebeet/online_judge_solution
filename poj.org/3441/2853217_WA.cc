#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

string res[128];
int dp[128][32];
int ans[128];
int pans[128];
int st[128];
int ed[128];

int main()
{
	int n, m;
	int ti(0);
	while ((cin >> n >> m), n > 0)
	{
		memset(ans, 0, sizeof(ans));
		memset(pans, 0, sizeof(pans));
		memset(st, 0, sizeof(st));
		memset(ed, 0, sizeof(ed));
		memset(dp, 0, sizeof(dp));
		int i, j;
		for (i = 1; i <= n; ++i)
		{
			cin >> res[i];
		}
		int f, t;
		cin >> f >> t;
		cout << "Case " << ++ti << ":" << endl << endl;
		int mn(1000000);
		for (j = 0; j < m; ++j)
		{
			dp[f][j] = ((res[f][j] == 'O') ? 1 : 1000000);
			mn = min(mn, dp[f][j]);
		}
		for (i = f + 1; i < t; ++i)
		{
			if (mn > 10000)
			{
				break;
			}
			++mn;
			int next_mn = 1000000;
			for (j = 0; j < m; ++j)
			{
				if (res[i][j] == 'O')
				{
					dp[i][j] = min(dp[i - 1][j], mn);
				}
				else
				{
					dp[i][j] = 1000000;
				}
				next_mn = min(next_mn, dp[i][j]);
			}
			mn = next_mn;
		}
		if (mn > 10000)
		{
			cout << "Not available" << endl;
		}
		else
		{
			int mn = 1000000;
			for (j = 0; j < m; ++j)
			{
				mn = min(mn, dp[t - 1][j]);
			}
			for (i = t - 2; i >= f; --i)
			{
				int next_mn(1000000);
				for (j = 0; j < m; ++j)
				{
					if (dp[i][j] < dp[i + 1][j])
					{
						if (dp[i][j] != mn - 1)
						{
							dp[i][j] = 1000000;
						}
					}
					next_mn = min(next_mn, dp[i][j]);
				}
			}
			for (i = f; i < t; ++i)
			{
				int p = 0;
				for (j = 1; j < m; ++j)
				{
					if (dp[i][p] > dp[i][j])
					{
						p = j;
					}
				}
				if (i == f)
				{
					pans[0] = 1;
					pans[pans[0]] = p;
					st[pans[0]] = f;
					ed[pans[0]] = f + 1;
				}
				else
				{
					
					if (p != pans[pans[0]])
					{
						pans[++pans[0]] = p;
						st[pans[0]] = i;
						ed[pans[0]] = i + 1;
					}
					else
					{
						++ed[pans[0]];
					}
				}
			}
			for (i = 1; i <= pans[0]; ++i)
			{
				cout << (char)(pans[i] + 'A') << ": " << st[i] << "-" << ed[i] << endl;
			}
		}
	}
	return 0;
}
