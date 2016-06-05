/*
 * PKU3170::Knights_of_Ni.cpp
 *
 *  Created on: Nov 1, 2008 6:51:07 PM
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
#include <queue>

using namespace std;

int map[1024][1024];
int map_b[1024][1024];
int ans[2][1024][1024];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef pair<int, int> Pos;

int bfs(int map[1024][1024], const Pos st, const int tar, const int ppp)
{
	queue<Pos> q[2];
	int p0(0), p1(1);
	int tans(0);
	q[0].push(st);
	while (q[p0].empty() == false)
	{
		++tans;
		while (q[p0].empty() == false)
		{
			Pos topos;
			for (int i = 0; i < 4; ++i)
			{
				topos.first = q[p0].front().first + dx[i];
				topos.second = q[p0].front().second + dy[i];
				if (map[topos.first][topos.second] == tar)
				{
					ans[ppp][topos.first][topos.second] = tans;
				}
				if ((map[topos.first][topos.second] == 0) || (map[topos.first][topos.second] == 4))
				{
					map[topos.first][topos.second] = -1;
					q[p1].push(topos);
				}
			}
			q[p0].pop();
		}
		swap(p0, p1);
	}
	return -1;
}

int main()
{
	memset(map, -1, sizeof(map));
	memset(ans, 30, sizeof(ans));
	int n, m;
	scanf("%d%d", &m, &n);
	Pos start;
	Pos ed;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2)
			{
				start.first = i;
				start.second = j;
			}
			if (map[i][j] == 3)
			{
				ed.first = i;
				ed.second = j;
			}
		}
	}
	memcpy(map_b, map, sizeof(map));
	bfs(map, start, 4, 0);
	bfs(map_b, ed, 4, 1);
	int mans(0x7fffffff);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
//			cerr << i << " : " << j << "  " << ans[0][i][j] << " " << ans[1][i][j] << endl;
			mans = min(mans, ans[0][i][j] + ans[1][i][j]);
		}
	}
	cout << mans << endl;
	return 0;
}


