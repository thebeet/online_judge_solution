/*
 * PKU3609::Reset_Sequence.cpp
 *
 *  Created on: Oct 10, 2008 5:38:36 PM
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
#include <queue>

using namespace std;

int oper[16][16];

int n, m;

class State
{
	friend ostream &operator << (ostream &out, const State &s)
	{
		for (int i = 0; i < n; ++i)
		{
			out << s.stat[i] << " ";
		}
		return out;
	}
public:
	int stat[8];
	vector<int> ans;
	void Sort(void)
	{
		sort(stat, stat + n);
	}
	bool operator < (const State &s) const
	{
		return (memcmp(stat, s.stat, sizeof(int) * n) < 0);
	}
	bool operator > (const State &s) const
	{
		return (memcmp(stat, s.stat, sizeof(int) * n) > 0);
	}
	bool operator == (const State &s) const
	{
		return (memcmp(stat, s.stat, sizeof(int) * n) == 0);
	}
};

map<State, bool> hash;

int main()
{
	while (cin >> n >> m)
	{
		hash.clear();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> oper[i][j];
			}
		}
		State initstat;
		for (int i = 0; i < n; ++i)
		{
			initstat.stat[i] = i;
		}
		State endstat;
		for (int i = 0; i < n; ++i)
		{
			endstat.stat[i] = 0;
		}
		queue<State> q;
		bool flag(false);
		while (q.empty() == false) q.pop();
		q.push(initstat);
		hash[initstat] = true;
		State now;
		while (q.empty() == false)
		{
			int j;
			for (j = 0; j < m; ++j)
			{
				now = q.front();
				for (int i = 0; i < n; ++i)
				{
					now.stat[i] = oper[now.stat[i]][j];
				}
				now.Sort();
				if (hash[now] == false)
				{
					now.ans.push_back(j);
					if (now == endstat)
					{
						flag = true;
						break;
					}
					hash[now] = true;
					q.push(now);
				}
			}
			if (flag)
			{
				break;
			}
			q.pop();
		}
		if (flag)
		{
			for (int i = 0; i < now.ans.size(); ++i)
			{
				if (now.ans[i] > 9)
				{
					cout << ('a' + now.ans[i] - 10) << " ";
				}
				else
				{
					cout << now.ans[i] << " ";
				}
			}
			cout << endl;
		}
		else
		{
			cout << "*" << endl;
		}

	}
	return 0;
}


