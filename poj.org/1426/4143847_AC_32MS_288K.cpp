/*
 * PKU1426::Find_The_Multiple.cpp
 *
 *  Created on: Sep 28, 2008 6:22:02 PM
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
#include <queue>

using namespace std;

string ans[256];

struct CMP
{
	bool operator() (const int x1, const int x2)
	{
		return ans[x1] > ans[x2];
	}
};


int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			ans[i] = "";
		}
		ans[1] = "1";
		priority_queue<int, vector<int>, CMP > q[2];
		while (q[0].empty() == false) q[0].pop();
		while (q[1].empty() == false) q[1].pop();
		int p0(0), p1(1);
		q[p0].push(1);
		while (q[p0].empty() == false)
		{
			while (q[p0].empty() == false)
			{
				int t = q[p0].top();
				q[p0].pop();
				if (t == 0)
				{
					goto ans;
				}
				int t1 = (t * 10) % n;
				string tostr = ans[t] + "0";
				if (ans[t1] == "")
				{
					ans[t1] = tostr;
					q[p1].push(t1);
				}
				if (ans[t1].size() == tostr.size())
				{
					if (ans[t1] > tostr)
					{
						ans[t1] = tostr;
					}
				}
				t1 = (t * 10 + 1) % n;
				tostr = ans[t] + "1";
				if (ans[t1] == "")
				{
					ans[t1] = tostr;
					q[p1].push(t1);
				}
				if (ans[t1].size() == tostr.size())
				{
					if (ans[t1] > tostr)
					{
						ans[t1] = tostr;
					}
				}
			}
			swap(p0, p1);
		}
ans:
		cout << ans[0] << endl;
	}
	return 0;
}
