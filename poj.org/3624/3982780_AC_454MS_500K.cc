/*
 * PKU3624::Charm_Bracelet.cpp
 *
 *  Created on: Aug 29, 2008 12:27:14 PM
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

int dp[16000];

int main()
{
	int n, m;
	cin >> n >> m;
	dp[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int w, d;
		cin >> w >> d;
		for (int j = m; j >= w; --j)
		{
			dp[j] = max(dp[j], dp[j - w] + d);
		}
	}
	int ans(0);
	for (int j = 0; j <= m; ++j)
	{
		ans = max(ans, dp[j]);
	}
	cout << ans << endl;
	return 0;
}
