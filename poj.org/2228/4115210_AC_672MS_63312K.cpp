/*
 * PKU2228::Naptime.cpp
 *
 *  Created on: Sep 23, 2008 2:43:58 PM
 *      Author: TheBeet
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU Affero General Public License as
 *	published by the Free Software Foundation, either version 3 of the
 *	License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Affero General Public License for more details.
 *
 *	You should have received a copy of the GNU Affero General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 4010;

int ult[MAXN];
int dp[MAXN][MAXN];
int mxdp[MAXN];

int main()
{
	int n, b;
	cin >> n >> b;
	cin >> ult[1];
	for (int i = 2; i <= n; ++i)
	{
		cin >> ult[i];
		for (int j = b; j >= 2; --j)
		{
			dp[i][j] = max(dp[i - 1][j - 1] + ult[i], mxdp[j - 1]);
			mxdp[j] = max(mxdp[j], dp[i - 1][j]);
		}
	}
/*	for (int k = 1; k <= n; ++k)
	{
		for (int h = 1; h <= b; ++h)
		{
			cout << dp[k][h] << " ";
		}
		cout << endl;
	}*/
	int ans(max(dp[n][b], mxdp[b]));
	memset(dp, 0, sizeof(dp));
	memset(mxdp, 0, sizeof(mxdp));
	dp[1][1] = ult[1];
	for (int i = 2; i <= n; ++i)
	{
		for (int j = b; j >= 2; --j)
		{
			dp[i][j] = max(dp[i - 1][j - 1] + ult[i], mxdp[j - 1]);
			mxdp[j] = max(mxdp[j], dp[i - 1][j]);
		}
		mxdp[1] = ult[1];
	}
	ans = max(ans, dp[n][b]);
/*	for (int k = 1; k <= n; ++k)
	{
		for (int h = 1; h <= b; ++h)
		{
			cout << dp[k][h] << " ";
		}
		cout << endl;
	}*/
	cout << ans << endl;
	return 0;
}
