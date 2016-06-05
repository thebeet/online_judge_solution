/*
 * PKU2626::Chess.cpp
 *
 *  Created on: Sep 13, 2008 8:55:16 PM
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
#include <vector>

using namespace std;

int dp[32][32];
int ab[1024][2];

int main()
{
	int n(1);
	while(cin >> ab[n][0] >> ab[n][1])
	{
		++n;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 15; j >= 0; --j)
		{
			for (int k = 15; k >= 0; --k)
			{
				dp[j + 1][k] = max(dp[j + 1][k], dp[j][k] + ab[i][0]);
				dp[j][k + 1] = max(dp[j][k + 1], dp[j][k] + ab[i][1]);
			}
		}
	}
	cout << dp[15][15] << endl;
	return 0;
}
