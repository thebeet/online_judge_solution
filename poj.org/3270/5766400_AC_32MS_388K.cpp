/*
 * PKU3270::Cow_Sorting.cpp
 *
 *  Created on: Sep 24, 2008 9:58:14 PM
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

struct Cow
{
	int gru;
	int place;
};

bool operator <(const Cow &c1, const Cow &c2)
{
	return c1.gru < c2.gru;
}

Cow cows[10010];
bool gone[10010];

int findunion(const int p, int &s, int &tm)
{
	if (gone[p])
	{
		return 0;
	}
	else
	{
		gone[p] = true;
		tm = min(tm, cows[p].gru);
		s += cows[p].gru;
		return 1 + findunion(cows[p].place, s, tm);
	}
}

int main()
{
	int n;
	cin >> n;
	int m(1000000000);
	for (int i = 0; i < n; ++i)
	{
		cin >> cows[i].gru;
		m = min(m, cows[i].gru);
		cows[i].place = i;
	}
	sort(cows + 0, cows + n);
	memset(gone, false, sizeof(gone));
	int ans(0);
	for (int i = 0; i < n; ++i)
	{
		if (gone[i] == false)
		{
			int tm = 1000000000;
			int s = 0;
			int sz = findunion(i, s, tm);
			s -= tm;
			ans += min((s + (sz - 1) * tm), (m + tm) * 2 + s + (sz - 1) * m);
		}
	}
	cout << ans << endl;
	return 0;
}
