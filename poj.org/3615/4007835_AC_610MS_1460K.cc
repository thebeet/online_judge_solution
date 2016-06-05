/*
 * PKU3615::Cow_Hurdles.cpp
 *
 *  Created on: Sep 2, 2008 9:16:40 PM
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

int map[512][512];

int main()
{
	int n, m, t;
	cin >> n >> m >> t;
	memset(map, 50, sizeof(map));
	for (int i = 0; i < m; ++i)
	{
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		map[a][b] = min(map[a][b], l);
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				map[i][j] = min(map[i][j], max(map[i][k], map[k][j]));
			}
		}
	}
	for (int i = 0; i < t; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (map[a][b] > 10000000)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", map[a][b]);
		}
	}
	return 0;
}
