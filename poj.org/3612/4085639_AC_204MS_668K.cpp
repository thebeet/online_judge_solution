/*
 * Telephone_Wire.cpp
 *
 *  Created on: 2008-9-17
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int h[100010];
int dp[2][128];
int seq[2][128];

int main()
{
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
	}
	memset(dp, 0, sizeof(dp));
	int p0(0), p1(1);
	for (int i = 1; i <= 100 - h[0]; ++i)
	{
		dp[p0][i + h[0]] = i * i;
	}
	for (int i = 1; i < n; ++i)
	{
		seq[0][h[i - 1]] = dp[p0][h[i - 1]] - c * h[i - 1];
		for (int j = h[i - 1] + 1; j <= 100; ++j)
		{
			seq[0][j] = min(seq[0][j - 1], dp[p0][j] - c * j);
		}

		seq[1][100] = dp[p0][100] + c * 100;
		for (int j = 99; j >= h[i - 1]; --j)
		{
			seq[1][j] = min(seq[1][j + 1], dp[p0][j] + c * j);
		}

		for (int j = h[i]; j <= 100; ++j)
		{
			if (j < h[i - 1])
			{
				dp[p1][j] = seq[1][h[i - 1]] - c * j + (j - h[i]) * (j - h[i]);
			}
			else
			{
				dp[p1][j] = min(seq[1][j] - c * j, seq[0][j] + c * j) + (j - h[i]) * (j - h[i]);
			}
		}
		swap(p0, p1);
	}
	int ans(0x7fffffff);
	for (int i = h[n - 1]; i <= 100; ++i)
	{
		ans = min(ans, dp[p0][i]);
	}
	cout << ans << endl;
	return 0;
}
