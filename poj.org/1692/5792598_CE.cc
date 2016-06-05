/*
 * Crossed_Matchings.cpp
 *
 *  Created on: 2009-9-1
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>

using namespace std;

int arr[2][128];

int dp[128][128];

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[0][i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> arr[1][i];
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				if (arr[0][i] == arr[1][j])
				{
					continue;
				}
				int pi(-1), pj(-1);
				for (int k = i - 1; k >= 0; --k)
				{
					if (arr[0][k] == arr[1][j])
					{
						pi = k;
						break;
					}
				}
				for (int k = j - 1; k >= 0; --k)
				{
					if (arr[1][k] == arr[0][i])
					{
						pj = k;
						break;
					}
				}
				if ((pi == -1) || (pj == -1))
				{
					continue;
				}
				dp[i + 1][j + 1] = max(dp[pi][pj] + 1, dp[i + 1][j + 1]);
			}
		}
		cout << dp[n][m] * 2 << endl;
	}
	return 0;
}
