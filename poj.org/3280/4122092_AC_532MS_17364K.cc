/*
 * PKU3280::Cheapest_Palindrome.cpp
 *
 *  Created on: Sep 24, 2008 6:54:45 PM
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
#include <string>
#include <map>

using namespace std;

int dp[2048][2048];
string inp;
map<char, pair<int, int> > cost;

int calc(const int st, const int ed)
{
	if (dp[st][ed] == -1)
	{
		if (st >= ed)
		{
			dp[st][ed] = 0;
		}
		else
		{
			dp[st][ed] = 0x7fffffff;
			if (inp[st] == inp[ed])
			{
				dp[st][ed] = min(dp[st][ed], calc(st + 1, ed - 1));
			}
			dp[st][ed] = min(dp[st][ed], calc(st + 1, ed) + cost[inp[st]].first);
			dp[st][ed] = min(dp[st][ed], calc(st + 1, ed) + cost[inp[st]].second);
			dp[st][ed] = min(dp[st][ed], calc(st, ed - 1) + cost[inp[ed]].first);
			dp[st][ed] = min(dp[st][ed], calc(st, ed - 1) + cost[inp[ed]].second);
		}
	}
	return dp[st][ed];
}

int main()
{
	int n, m;
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	cin >> inp;
	for (int i = 0; i < n; ++i)
	{
		char c;
		int lo, hi;
		cin >> c >> lo >> hi;
		cost[c] = make_pair(lo, hi);
	}
	cout << calc(0, m - 1) << endl;
	return 0;
}
