#include <stdio.h>
#include <string.h>

const int p = 1000000;
int ants[1024];
int dp[102400];

int main()
{
	int t, a, s, b;
	int i, m;
	scanf("%d%d%d%d", &t, &a, &s, &b);
	memset(ants, 0, sizeof(ants));
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	
	for (i = 1; i <= a; ++i)
	{
		scanf("%d", &m);
		++ants[m];
	}
	int sum = 0;
	int j;
	for (i = 1; i <= t; ++i)
	{
		if (sum > b)
		{
			sum = b;
		}
		for (j = sum; j >= 0; --j)
		{
			int t = j + ants[i];
			if (t > b)
			{
				t = b;
			}
			for (int k = j + 1; k <= t; ++k)
			{
				dp[k] += dp[j];
				if (dp[k] > p)
				{
					dp[k] -= p;
				}
			}
		}
		sum += ants[i];
	}
	int ans = 0;
	for (i = s; i <= b; ++i)
	{
		ans += dp[i];
	}
	printf("%d\n", ans % p);
	return 0;
}
