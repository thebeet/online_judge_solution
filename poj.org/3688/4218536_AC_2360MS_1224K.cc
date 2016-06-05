/*
 * Cheat_in_the_Game.cpp
 *
 *  Created on: 2008-10-14
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>

using namespace std;

int dp[200010];

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m), n > 0)
	{
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; ++i)
		{
			int a;
			scanf("%d", &a);
			for (int j = m; j >= a; --j)
			{
				if (dp[j - a] & 1)
				{
					dp[j] |= 2;
				}
				if (dp[j - a] & 2)
				{
					dp[j] |= 1;
				}
			}
		}
		int total(0);
		for (int j = 1; j <= m; ++j)
		{
			if (dp[j] == 2) ++total;
		}
		cout << total << endl;
	}
}
