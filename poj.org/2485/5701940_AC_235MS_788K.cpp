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

int fa[65536];

struct Relationship
{
	int a, b;
	int d;
}rs[65536];

bool operator <(const Relationship &r1, const Relationship &r2)
{
	return r1.d < r2.d;
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
		int n;
		scanf("%d", &n);
		init(n * n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				rs[i * n + j].a = i;
				rs[i * n + j].b = j;
				scanf("%d", &rs[i * n + j].d);
			}
		}
		sort(rs, rs + n * n);
		int con(1);
		int sum(0);
		for (int i = 0; (con < n) && (i < n * n); ++i)
		{
			int f1 = findf(rs[i].a);
			int f2 = findf(rs[i].b);
			if (f1 != f2)
			{
				fa[f1] = f2;
				++con;
				sum = rs[i].d;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
