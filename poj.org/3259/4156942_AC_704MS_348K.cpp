/*
 * PKU3259::Wormholes.cpp
 *
 *  Created on: Oct 1, 2008 9:57:31 PM
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
#include <vector>

using namespace std;

struct Path
{
	int f, t, len;
};

Path paths[6400];
int u[512];

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		int n, m, w;
		cin >> n >> m >> w;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &paths[i << 1].f, &paths[i << 1].t, &paths[i << 1].len);
			paths[(i << 1) + 1] = paths[i << 1];
			swap(paths[(i << 1) + 1].f, paths[(i << 1) + 1].t);
		}
		m += m;
		w += m;
		for (int i = m; i < w; ++i)
		{
			scanf("%d%d%d", &paths[i].f, &paths[i].t, &paths[i].len);
			paths[i].len = -paths[i].len;
		}
		m = w;
		int i;
		for (i = 1; i <= n; ++i)
		{
			memset(u, 127, sizeof(u));
			u[i] = 0;
			bool flag(true);
			for (int k = 1; k < n; ++k)
			{
				flag = false;
				for (int j = 0; j < m; ++j)
				{
					if ((u[paths[j].f] < 1000000000) &&
						(u[paths[j].t] > u[paths[j].f] + paths[j].len))
					{
						u[paths[j].t] = u[paths[j].f] + paths[j].len;
						flag = true;
					}
				}
				if (flag == false) break;
				if (u[i] < 0)
				{
					break;
				}
			}
			if (u[i] < 0)
			{
				break;
			}
		}
		cout << ((i <= n) ? "YES" : "NO") << endl;
	}
	return 0;
}
