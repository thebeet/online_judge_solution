#include <iostream>
#include <stdio.h>

using namespace std;

int map[8][8];
bool dp[4][8][8][1024];
bool ans[1000010];

int main()
{
	int i, j, k, h, st;
	memset(dp, false, sizeof(dp));
	memset(ans, false, sizeof(ans));
	for (i = 1; i <= 5; ++i)
	{
		for (j = 1; j <= 5; ++j)
		{
			cin >> map[i][j];
			dp[1][i][j][map[i][j]] = true;
		}
	}
	st = 1;
	for (k = 2; k <= 3; ++k)
	{
		st *= 10;
		for (h = 0; h < st; ++h)
		{
			for (i = 1; i <= 5; ++i)
			{
				for (j = 1; j <= 5; ++j)
				{
					if (dp[k - 1][i][j][h])
					{
						dp[k][i + 1][j][h * 10 + map[i + 1][j]] = true;
						dp[k][i][j + 1][h * 10 + map[i][j + 1]] = true;
						dp[k][i - 1][j][h * 10 + map[i - 1][j]] = true;
						dp[k][i][j - 1][h * 10 + map[i][j - 1]] = true;
					}
				}
			}
		}
	}
	for (i = 1; i <= 4; ++i)
	{
		for (j = 1; j <= 5; ++j)
		{
			for (k = 0; k < 1000; ++k)
			{
				for (h = 0; h < 1000; ++h)
				{
					if (dp[3][i][j][k] && dp[3][i + 1][j][h])
					{
						ans[k * 1000 + h] = true;
						ans[h * 1000 + k] = true;
					}
				}
			}
		}
	}
	for (i = 1; i <= 4; ++i)
	{
		for (j = 1; j <= 5; ++j)
		{
			for (k = 0; k < 1000; ++k)
			{
				for (h = 0; h < 1000; ++h)
				{
					if (dp[3][j][i][k] && dp[3][j][i + 1][h])
					{
						ans[k * 1000 + h] = true;
						ans[h * 1000 + k] = true;
					}
				}
			}
		}
	}
	int tans = 0;
	for (i = 0; i < 1000000; ++i)
	{
		if (ans[i])
		{
			++tans;
		}
	}
	printf("%d\n", tans);
	return 0;
}
