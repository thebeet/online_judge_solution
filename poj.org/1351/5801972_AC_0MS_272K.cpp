/*
 * Number_of_Locks.cpp
 *
 *  Created on: Sep 2, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long dp[32][32][4];
long long ans[32];

int main()
{
	memset(dp, 0, sizeof(dp));
	memset(ans, 0, sizeof(ans));
	for (int h = 0; h < 4; ++h)
	{
		dp[1][(1 << h)][h] = 1;
	}
	for (int i = 1; i < 16; ++i)
	{
		for (int k = 0; k < 32; ++k)
		{
			for (int j = 0; j < 4; ++j)
			{
				for (int h = 0; h < 4; ++h)
				{
					int t(0);
					if (((j == 0) && (h == 3)) || ((j == 3) && (h == 0)))
					{
						t = 16;
					}
					dp[i + 1][t | k | (1 << h)][h] += dp[i][k][j];
				}
			}
		}
	}
	for (int i = 2; i <= 16; ++i)
	{
		for (int k = 16; k < 32; ++k)
		{
			int mk(k & 0xf);
			int s(0);
			while (mk > 0)
			{
				if (mk & 1) ++s;
				mk >>= 1;
			}
			if (s < 3) continue;
			for (int h = 0; h < 4; ++h)
			{
				ans[i] += dp[i][k][h];
			}
		}
	}
	int n;
	while ((cin >> n), n > 0)
	{
		cout << n << ": " << ans[n] << endl;
	}
	return 0;
}
