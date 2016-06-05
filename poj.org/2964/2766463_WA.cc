#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char map[128][128];
int dp[128][128][128];

int n, m;

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, k;
		scanf("%d%d", &n, &m);
		
		memset(map, '#', sizeof(map));
		memset(dp, 200, sizeof(dp));
		
		for (i = 1; i <= m; ++i)
		{
			scanf("%s", map[i] + 1);
		}
		
		for (i = 1; i <= n; ++i)
		{
			for (j = i; j <= n; ++j)
			{
				dp[0][i][j] = 0;
			}
		}
		
		for (k = 1; k <= m; ++k)
		{
			for (i = 1; i <= n; ++i)
			{
				if (map[k][i] == '#')
				{
					continue;
				}
				for (j = i; j <= n; ++j)
				{
					if (map[k][j] == '#')
					{
						continue;
					}
					int d1 = ((map[k][i] == '*') ? 1 : 0);
					int d2 = ((map[k][j] == '*') ? 1 : 0);
					if (i == j)
					{
						d2 = 0;
					}
					dp[k][i][j] = max(dp[k - 1][i][j] + d1 + d2,
									max(dp[k][i][j - 1] + d2, dp[k][i - 1][j] + d1)); 
				}
			}
		}
		printf("%d\n", dp[m][n][n]);
	}
	return 0;
}
