/*
 * Multipliction_Puzzle.cpp
 *
 *  Created on: 2009-8-28
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[128];
int dp[128][128];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n - 2; ++i)
	{
		dp[i][i + 2] = arr[i] * arr[i + 1] * arr[i + 2];
	}
	for (int k = 3; k < n; ++k)
	{
		for (int i = 0; i + k < n; ++i)
		{
			dp[i][i + k] = 1000000000;
			for (int j = i + 1; j < i + k; ++j)
			{
				dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j][i + k] + arr[i] * arr[j] * arr[i + k]);
			}
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
