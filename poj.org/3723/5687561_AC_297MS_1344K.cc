/*
 * PKU3723::Conscription.cpp
 *
 *  Created on: Aug 18, 2009 12:12:40 PM
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
#include <cstdio>
#include <cstring>

int fa[20010];

struct Relationship
{
	int a, b;
	int d;
}rs[65536];

bool operator <(const Relationship &r1, const Relationship &r2)
{
	return r1.d > r2.d;
}

void init(int n)
{
	for (int i = 0; i < n; ++i)
	{
		fa[i] = i;
	}
}

int findf(int p)
{
	if (fa[p] != p)
	{
		fa[p] = findf(fa[p]);
	}
	return fa[p];
}

using namespace std;

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 0; ti < tn; ++ti)
	{
		int n, m, r;
		scanf("%d%d%d", &n, &m, &r);
		init(n + m);
		for (int i = 0; i < r; ++i)
		{
			scanf("%d%d%d", &rs[i].a, &rs[i].b, &rs[i].d);
			rs[i].b += n;
		}
		sort(rs, rs + r);
		int con(1);
		int sum(0);
		for (int i = 0; (con < n + m) && (i < r); ++i)
		{
			int f1 = findf(rs[i].a);
			int f2 = findf(rs[i].b);
			if (f1 != f2)
			{
				fa[f1] = f2;
				++con;
				sum += rs[i].d;
			}
		}
		printf("%d\n", (n + m) * 10000 - sum);
	}
	return 0;
}
