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

int bit1[MAXN];
double dp[128][MAXN];

int main()
{
	//init
	int i, j;
	memset(bit1, 0, sizeof(bit1)); 
	for (i = 0; i < 10; ++i)
	{
		int t = 1 << i;
		for (j = 0; j < t; ++j)
		{
			bit1[j + t] = bit1[j] + 1;
		}
	}
	
	int k, n, e;
	while (scanf("%d%d%d", &k, &n, &e), k > 0)
	{
		int i, j, ik;
		int bn = 1 << n;
		memset(dp, 0, sizeof(dp));
		memset(s, 0, sizeof(s));
		
		for (i = 1; i <= e; ++i)
		{
			scanf("%d%d", &paths[i].f, &paths[i].t);
			paths[i + e].f = paths[i].t;
			paths[i + e].t = paths[i].t;
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
			dp[1][i] = (double)bit1[i]; 
		}
		
		for (ik = 2; ik <= k; ++ik)
		{
			for (i = 0; i < bn; ++i)
			{
				for (j = p[i]; j < p[i + 1]; ++j)
				{
					dp[ik][i] += dp[ik - 1][paths[j].t];
				}
				dp[ik][i] = ((dp[ik][i] * (ik - 1) + (double)(bit1[i] * s[i])) / ik / s[i]);
			}
		}
		
		double ans(0);
		for (i = 0; i < bn; ++i)
		{
			ans += dp[k][i];
		}
		ans /= bn * n;
		if ((ans <= 0.7500000000001) && (ans >= 0.2500000000001))
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
