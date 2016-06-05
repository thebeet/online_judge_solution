/*
 * PKU3616::Milking_Time.cpp
 *
 *  Created on: Aug 28, 2008 6:37:56 PM
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

map<int, int> ans;

struct milk
{
	int t1, t2;
	int eff;
};

bool operator < (const milk &m1, const milk &m2)
{
	return m1.t2 < m2.t2;
}

istream &operator >> (istream &in, milk &m)
{
	in >> m.t1 >> m.t2 >> m.eff;
	return in;
}

milk milks[1024];

int main()
{
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 0; i < m; ++i)
	{
		cin >> milks[i];
	}
	sort(milks, milks + m);
	ans[-n] = 1;
	for (int i = 0; i < m; ++i)
	{
		int pret(milks[i].t1 - r);
		if (ans[pret] == 0)
		{
			map<int, int>::iterator it = ans.find(pret);
			--it;
			ans[milks[i].t2] = max(ans[milks[i].t2], it->second + milks[i].eff);
			ans.erase(++it);
		}
		else
		{
			ans[milks[i].t2] = max(ans[milks[i].t2], ans[pret] + milks[i].eff);
		}
	}
	if (ans[n] == 0)
	{
		map<int, int>::iterator it = ans.find(n);
		--it;
		cout << it->second - 1 << endl;
	}
	else
	{
		cout << ans[n] - 1 << endl;
	}
	return 0;
}
