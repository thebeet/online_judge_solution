/*
 * PKU3184::Finicky_Grazers.cpp
 *
 *  Created on: Aug 27, 2009 6:12:45 PM
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
#include <cstring>
#include <cstdio>

using namespace std;

int pos[10010];
int dp[2][10010];

int main()
{
	int n, l;
	scanf("%d%d", &n, &l);
	int d = (l / (n - 1));
	int m = l - d * (n - 1);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &pos[i]);
	}
	memset(dp, 63, sizeof(dp));
	int p1(0), p2(1);
	dp[p1][0] = pos[0];
	for (int i = 1; i < n; ++i)
	{
		memset(dp[p2], 63, sizeof(dp[p2]));
		int tt(min(i, m));
		dp[p2][0] = dp[p1][0] + abs(i * d - pos[i]);
		for (int k = 1; k <= tt; ++k)
		{
			dp[p2][k] = min(dp[p1][k], dp[p1][k - 1]) + abs(i * d + k - pos[i]);
		}
		swap(p1, p2);
	}
	cout << dp[p1][m] << endl;
	return 0;
}
