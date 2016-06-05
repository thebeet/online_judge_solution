#/*
 * PKU3625::Building_Roads.cpp
 *
 *  Created on: Aug 29, 2008 12:38:35 PM
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

#include <cmath>

using namespace std;

double x[1024];
double y[1024];

struct Road
{
	int f1, f2;
	double d;
};

bool operator < (const Road &r1, const Road &r2)
{
	return r1.d < r2.d;
}

Road roads[1024 * 1024];

int father[1024];

void init(void)
{
	for (int i = 0; i < 1024; ++i)
	{
		father[i] = i;
	}
}

int findset(const int f)
{
	if (f != father[f])
	{
		father[f] = findset(father[f]);
	}
	return father[f];
}

int connectset(const int f1, const int f2)
{
	int ff1 = findset(f1);
	int ff2 = findset(f2);
	if (ff1 == ff2) return 0;
	father[ff1] = ff2;
	return 1;
}

int main()
{
	int n, m;
	int k(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i];
		for (int j = 1; j < i; ++j)
		{
			roads[k].f1 = i;
			roads[k].f2 = j;
			roads[k].d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			++k;
		}
	}
	sort(roads, roads + k);
	int connected(1);
	init();
	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		connected += connectset(a, b);
	}
	double ans(0);
	for (int i = 0; i < k; ++i)
	{
		if (connectset(roads[i].f1, roads[i].f2) == 1)
		{
			ans += roads[i].d;
			if (++connected == n)
			{
				break;
			}
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}
