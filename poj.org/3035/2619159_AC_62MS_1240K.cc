#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

struct path
{
	friend bool operator < (const path &p1, const path &p2)
	{
		return (p1.f < p2.f);
	}
	int f, t;
}paths[4096];
int s[MAXN];
int p[MAXN];

double dp[128][MAXN];

int main()
{
	
	int k, n, e;
	while (scanf("%d%d%d", &k, &n, &e), k > 0)
	{
		int i, j, ik, ib;
		int bn = 1 << n;
		memset(dp, 0, sizeof(dp));
		memset(s, 0, sizeof(s));
		memset(p, 0, sizeof(p));
		memset(paths, 0, sizeof(paths));
		
		for (i = 1; i <= e; ++i)
		{
			scanf("%d%d", &paths[i].f, &paths[i].t);
			paths[i + e].f = paths[i].t;
			paths[i + e].t = paths[i].f;
			++s[paths[i].f];
			++s[paths[i].t];
		}
		sort(paths + 1, paths + 1 + e + e);
		p[0] = 1;
		for (i = 0; i < bn; ++i)
		{
			p[i + 1] = p[i] + s[i];
		}
		
		for (i = 0; i < bn; ++i)
		{
			dp[1][i] = 1.0 / (double)bn; 
		}
		
		for (ik = 2; ik <= k; ++ik)
		{
			for (i = 0; i < bn; ++i)
			{
				double pp = dp[ik - 1][i] / (double)s[i];
				for (j = p[i]; j < p[i + 1]; ++j)
				{
					dp[ik][paths[j].t] += pp;
				}
			}
			for (ib = 0; ib < n; ++ib)
			{
				double ans(0.0);
				for (i = 0; i < bn; ++i)
				{
					if ((i & (1 << ib)) > 0)
					{
						ans += dp[ik][i];
					}
				}
				if ((ans > 0.7500000000001) || (ans < 0.2500000000001))
				{
					break;
				}
			}
			if (ib < n)
			{
				break;
			}
		}
		
		if (ik > k)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
