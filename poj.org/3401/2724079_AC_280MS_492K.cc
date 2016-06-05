#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char inp[512];
int dp[256][256];
char dpch[256][256];

int calc(int f, int t)
{
	if (dp[f][t] > 100000)
	{
		int i, j;
		if (((t - f) & 1) == 0)
		{
			for (i = f; i < t; i += 2)
			{
				for (j = i + 1; j < t; j += 2)
				{
					if (((calc(f, i) == 1) && (calc(j + 1, t) == 1) && (dpch[f][i] == dpch[j + 1][t]))
						&&
						(calc(i + 1, j) == 1))
					{
						dp[f][t] = 1;
						dpch[f][t] = dpch[i + 1][j];
						return 1;
					}
				}
			}
		}
		for (i = f; i < t; ++i)
		{
			dp[f][t] = min(dp[f][t], calc(f, i) + calc(i + 1, t));
		}
	}
	return dp[f][t];
}

int main()
{
	int n;
	scanf("%s", inp);
	n = strlen(inp);
	memset(dp, 1, sizeof(dp));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
			{
				dp[i][j] = 1;
				dpch[i][j] = inp[i];
			}
			else if (i > j)
			{
				dp[i][j] = 0;
			}
		}
	}
	printf("%d\n", calc(0, n - 1));
	return 0;
}
