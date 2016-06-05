#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char inp[128];
int dp[128][128];

int calc(int f, int t)
{
	if (f > t)
	{
		return 0;
	}
	else if (f == t)
	{
		return 1;
	}
	else
	{
		if (dp[f][t] == 0)
		{
			if ((calc(f + 1, t - 1) == 1) && (inp[f - 1] == inp[t - 1]))
			{
				dp[f][t] = 1;
			}
			else
			{
				dp[f][t] = 10000;
				for (int i = f; i < t; ++i)
				{
					dp[f][t] = min(dp[f][t], calc(f, i) + calc(i + 1, t));
				}
			}
		}
		return dp[f][t];
	}
}

int main()
{
	int n;
	scanf("%s", inp);
	n = strlen(inp);
	memset(dp, 0, sizeof(dp));
	printf("%d\n", calc(1, n));
	return 0;
}
