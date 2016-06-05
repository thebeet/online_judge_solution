/*
 * PKU1611::The_Suspects.cpp
 *
 *  Created on: Aug 27, 2009 9:34:16 PM
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

int fa[65536];
int n, m;

void init()
{
	for (int i = 0; i < n; ++i)
	{
		fa[i] = i;
	}
}

int findf(const int p)
{
	if (fa[p] != p)
	{
		fa[p] = findf(fa[p]);
	}
	return fa[p];
}

int main()
{
	while (scanf("%d%d", &n, &m), n > 0)
	{
		init();
		for (int i = 0; i < m; ++i)
		{
			int gn;
			scanf("%d", &gn);
			int fir;
			scanf("%d", &fir);
			for (int g = 1; g < gn; ++g)
			{
				int mem;
				scanf("%d", &mem);
				fa[findf(mem)] = findf(fir);
			}
		}
		int ans(1);
		for (int i = 1; i < n; ++i)
		{
			if (findf(0) == findf(i))
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
