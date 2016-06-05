/*
 * PKU2265::Bee_Maja.cpp
 *
 *  Created on: Sep 14, 2008 1:52:18 PM
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

pair<int, int> op(const pair<int, int> o, const int tp)
{
	pair<int, int> ret(o);
	switch (tp)
	{
		case 0:
		{
			++ret.second;
			return ret;
		}
		case 1:
		{
			--ret.first;
			++ret.second;
			return ret;
		}
		case 2:
		{
			--ret.first;
			return ret;
		}
		case 3:
		{
			--ret.second;
			return ret;
		}
		case 4:
		{
			++ret.first;
			--ret.second;
			return ret;
		}
		case 5:
		{
			++ret.first;
			return ret;
		}
	}
	return ret;
}

int main()
{
	vector< pair<int, int> > ans(128 * 1024);
	ans[1].first = 0;
	ans[1].second = 0;
	int k(1);
	for (int i = 1; ; ++i)
	{
		for (int h = 0; h < 6; ++h)
		{
			int t(i);
			if (h == 1) t = i - 1;
			for (int j = 1; j <= t; ++j, ++k)
			{
				ans[k] = op(ans[k - 1], h);
			}
		}
		if (k > 100000) break;
	}
	int n;
	while (cin >> n)
	{
		cout << ans[n].first << " " << ans[n].second << endl;
	}
}
