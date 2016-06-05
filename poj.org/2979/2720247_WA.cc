#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int sht[16][16];

int dp[128][64];

int dx[256];
int dy[256];
int dn(0);

int key[16] =
{
		0, 7, 8, 9, 4, 5, 6, 1, 2, 3, 0, 0, 0, 0, 0, 0
};

int main()
{
	int i, j;
	for (i = 1; i <= 11; ++i)
	{
		for (j = 1; j <= 11; ++j)
		{
			sht[i][j] = abs(((i - 1) % 3) - ((j - 1) % 3)) + abs(((i - 1) / 3) - ((j - 1) / 3));
			if (((i - 1) % 3) < ((j - 1) % 3))
			{
				dx[++dn] = i;
				dy[dn] = j;
			}
			if ((i > 10) && (j > 10))
			{
				--dn;
			}
		}
	}
	string inp;
	while ((cin >> inp), inp != "eof")
	{
		memset(dp, 1, sizeof(dp));
		dp[0][13] = 0;
		unsigned int k;
		for (k = 0; k < inp.size(); ++k)
		{
			int tar = inp[k] - '0';
			for (i = 1; i <= dn; ++i)
			{
				if (dp[k][i] < 10000)
				{
					for (j = 1; j <= dn; ++j)
					{
						if (key[dx[j]] == tar)
						{
							if ((dy[i] == 11) && (((dx[j] - 1) % 3) == 1) && (sht[dx[i]][dx[j]] == 1))
							{
								dp[k + 1][j] = min(dp[k + 1][j], dp[k][i] + max(sht[dx[i]][dx[j]] + 2, sht[dy[i]][dy[j]]));
							}
							else
							{
								dp[k + 1][j] = min(dp[k + 1][j], dp[k][i] + max(sht[dx[i]][dx[j]] + 1, sht[dy[i]][dy[j]]));
							}
						}
						if (key[dy[j]] == tar)
						{
							dp[k + 1][j] = min(dp[k + 1][j], dp[k][i] + max(sht[dx[i]][dx[j]], sht[dy[i]][dy[j]] + 1));
						}
					}
				}
			}
		}
		int ans = 10000;
		for (i = 1; i <= dn; ++i)
		{
			ans = min(ans, dp[k][i]);
		}
		cout << ans << endl;
	}
	return 0;
}
