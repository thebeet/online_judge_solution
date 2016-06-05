#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char inp[512];
int dp[512][512];

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
		if (dp[f][t] > 100000)
		{
			if ((calc(f + 1, t - 1) == 1) && (inp[f] == inp[t]))
			{
				dp[f][t] = 1;
			}
			else
			{
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
	memset(dp, 1, sizeof(dp));
	printf("%d\n", calc(0, n - 1));
	return 0;
}
