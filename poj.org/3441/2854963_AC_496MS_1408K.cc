#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

string res[MAXN];
int dp[MAXN][128];
int pre[MAXN][128];
int ans[MAXN];
int pans[MAXN];
int st[MAXN];
int ed[MAXN];
int mn[MAXN];

int main()
{
	int n, m;
	int ti(0);
	//freopen("inp", "r", stdin);
	while ((cin >> n >> m), n > 0)
	{
		memset(ans, 0, sizeof(ans));
		memset(pans, 0, sizeof(pans));
		memset(pre, 0, sizeof(pre));
		memset(st, 0, sizeof(st));
		memset(ed, 0, sizeof(ed));
		memset(dp, 0, sizeof(dp));
		memset(mn, 1, sizeof(mn));
		int i, j, k;
		for (i = 1; i <= n; ++i)
		{
			cin >> res[i];
		}
		int f, t;
		cin >> f >> t;
		if (ti != 0)
		{
			cout << endl;
		}
		cout << "Case " << ++ti << ":" << endl << endl;
		for (j = 0; j < m; ++j)
		{
			dp[f][j] = ((res[f][j] == 'O') ? 1 : 1000000);
			mn[f] = min(mn[f], dp[f][j]);
		}
		for (i = f + 1; i < t; ++i)
		{
			if (mn[i - 1] > 10000)
			{
				break;
			}
			for (j = 0; j < m; ++j)
			{
				if (res[i][j] == 'O')
				{
					dp[i][j] = min(dp[i - 1][j], mn[i - 1] + 1);
				}
				else
				{
					dp[i][j] = 1000000;
				}
				mn[i] = min(mn[i], dp[i][j]);
			}
		}
		if (mn[i - 1] > 10000)
		{
			cout << "Not available" << endl;
		}
		else
		{
			for (j = 0; j < m; ++j)
			{
				if (dp[t - 1][j] != mn[t - 1])
				{
					dp[t - 1][j] = 1000000;
				}
			}
			for (i = t - 2; i >= f; --i)
			{
				for (j = 0; j < m; ++j)
				{
					if ((dp[i][j] < 10000) && (dp[i][j] != dp[i + 1][j]))
					{
						for (k = 0; k < m; ++k)
						{
							if ((dp[i + 1][k] == dp[i][j] + 1) && (k != j))
							{
								break;
							}
						}
						if (k == m)
						{
							dp[i][j] = 1000000;
						}
					}
				}
			}
			for (i = f; i < t; ++i)
			{
				if (i == f)
				{
					for (j = 0; j < m; ++j)
					{
						if (dp[i][j] < 10000)
						{
							break;
						}
					}
					pans[0] = 1;
					pans[pans[0]] = j;
					st[pans[0]] = f;
					ed[pans[0]] = f + 1;
				}
				else
				{
					for (j = 0; j < m; ++j)
					{
						if (j != pans[pans[0]])
						{
							if (dp[i][j] == dp[i - 1][pans[pans[0]]] + 1)
							{
								break;
							}
						}
						else
						{
							if (dp[i][pans[pans[0]]] == dp[i - 1][pans[pans[0]]])
							{
								break;
							}
						}
					}
					if (j != pans[pans[0]])
					{
						++pans[0];
						pans[pans[0]] = j;
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
