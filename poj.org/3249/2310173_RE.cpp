#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAXN 10

int v[MAXN];
int d[MAXN];
int d2[MAXN];
int dl[MAXN];
int p[MAXN];
int dp[MAXN];

struct road
{
	int f, t;
}roads[1000010];

int mx(int a, int b)
{
	return (a > b) ? a : b;
}

bool comp(road road1, road road2)
{
	return (road1.f < road2.f);
}

int main()
{
	int n, m, j, ans, tar;
	int i;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(v, 0, sizeof(v));
		memset(d, 0, sizeof(d));
		memset(p, 0, sizeof(p));
		memset(d2, 0, sizeof(d2));
		memset(dl, 0, sizeof(dl));
		memset(dp, 0, sizeof(dp));
		memset(roads, 0, sizeof(roads));
		
		for (i = 1; i <= n; ++i)
		{
			dp[i] = -2000000002;
		}
		ans = -2000000002;
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &v[i]);
		}
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d", &roads[i].f, &roads[i].t);
			++d[roads[i].t];
			++d2[roads[i].f];
		}
		sort(roads + 1, roads + m + 1, comp);
		
		p[0] = 1;
		for (i = 1; i <= n; ++i)
		{
			p[i] = p[i - 1] + d2[i - 1];
		}
		
		for (i = 1; i <= n; ++i) 
		{
			if (d[i] == 0)
			{
				dp[i] = v[i];
				++dl[0];
				dl[dl[0]] = i;
			}
		}
		
		for (i = 1; i <= dl[0]; ++i)
		{
			for (j = 0; j < d2[dl[i]]; ++j)
			{
				tar = roads[p[dl[i]] + j].t;
				dp[tar] = mx(dp[tar], dp[dl[i]] + v[tar]);
				if (--d[tar] == 0)
				{
					++dl[0];
					dl[dl[0]] = tar;
				}
			}
			if (d2[dl[i]] == 0)
			{
				ans = mx(ans, dp[dl[i]]);
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}
