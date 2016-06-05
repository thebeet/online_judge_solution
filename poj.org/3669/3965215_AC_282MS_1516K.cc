/*
 * PKU3669::Meteor_Shower.cpp
 *
 *  Created on: Aug 25, 2008 10:29:17 PM
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
#include <queue>

using namespace std;

vector< vector< pair<int, int> > > meteor;

int map[512][512];

void setpoint(const int x, const int y, const int t)
{
	if ((x >= 0) && (y >= 0))
	{
		map[x][y] = min(map[x][y], t);
	}
}

int expend(queue<pair <int, int> > &q, const int x, const int y, const int ans)
{
	if ((x >= 0) && (y >= 0))
	{
		if (map[x][y] > 1024) return 1;
		if (map[x][y] > ans)
		{
			map[x][y] = -1;
			q.push(make_pair(x, y));
		}
	}
	return 0;
}

int bfs(const int x = 0, const int y = 0)
{
	if (map[x][y] > 1024)
	{
		return 0;
	}
	int p0(0), p1(1);
	queue< pair<int, int> > q[2];
	q[p0].push(make_pair(x, y));
	map[x][y] = -1;
	int ans(1);
	while (q[p0].empty() == false)
	{
		while (q[p0].empty() == false)
		{
			int tx = q[p0].front().first;
			int ty = q[p0].front().second;
			q[p0].pop();
			if ((expend(q[p1], tx + 1, ty, ans) +
				 expend(q[p1], tx - 1, ty, ans) +
				 expend(q[p1], tx, ty + 1, ans) +
				 expend(q[p1], tx, ty - 1, ans)) > 0)
			{
				return ans;
			}
		}
		++ans;
		swap(p0, p1);
	}
	return -1;
}

int main()
{
	int i, n;
	scanf("%d", &n);
	meteor.resize(1024);
	memset(map, 10, sizeof(map));
	for (i = 0; i < n; ++i)
	{
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		setpoint(x, y, t);
		setpoint(x + 1, y, t);
		setpoint(x - 1, y, t);
		setpoint(x, y + 1, t);
		setpoint(x, y - 1, t);
	}
	cout << bfs() << endl;
	return 0;
}
