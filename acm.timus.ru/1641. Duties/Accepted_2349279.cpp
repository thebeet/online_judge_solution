/*
 * URAL1641::Duties.cpp
 *
 *  Created on: Nov 17, 2008 8:34:40 PM
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
#include <map>

using namespace std;

map<pair<int, int>, bool> hash;

int main()
{
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 0; i < n; ++i)
	{
		cout << (i % k) + 1 << endl;
	}
	int kk(0);
	for (int i = 0; i + 1 < n; i += 2)
	{
		cout << i + 1 << " " << (i + 1) % n + 1 << endl;
		hash[make_pair(i + 1, (i + 1) % n + 1)] = true;
		++kk;
	}
	if ((n & 1) == 1)
	{
		cout << n - 1 << " " << n << endl;
		hash[make_pair(n - 1, n)] = true;
		++kk;
	}
	if (kk == m) return 0;
	for (int i = 0; i < k; ++i)
	{
		for (int j = i + 1; j < k; ++j)
		{
			for (int h = i; h < n; h += k)
			{
				for (int g = j; g < n; g += k)
				{
					int t1 = min(h + 1, g + 1);
					int t2 = max(h + 1, g + 1);
					if (hash[make_pair(t1, t2)])
					{
						continue;
					}
					++kk;
					cout << t1 << " " << t2 << endl;
					if (kk == m)
					{
						return 0;
					}
				}
			}
		}
	}
	return 0;
}


