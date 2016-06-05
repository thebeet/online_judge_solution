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
			int i, j;
			for (i = f; i < t; ++i)
			{
				for (j = i + 1; j < t; ++j)
				{
					if (((calc(f, i) == 1) && (calc(j + 1, t) == 1) && ((f != i) || (j + 1 != t) || (inp[i] == inp[t])))
						&&
						(calc(i + 1, j) == 1))
					{
						dp[f][t] = 1;
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
