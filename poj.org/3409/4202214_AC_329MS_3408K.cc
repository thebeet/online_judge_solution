/*
 * PKU3409::Broken_line.cpp
 *
 *  Created on: Oct 10, 2008 4:30:09 PM
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
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 5010;

// make pre-star graph
struct path
{
	int f, t;
}paths[100010];
int s[MAXN];
int p[MAXN];

bool operator < (const path &p1, const path &p2)
{
	return (p1.f < p2.f);
}

map<string, int> pid;

int frpid(0);

int gpid(const string &p1)
{
	int ret = pid[p1];
	if (ret == 0)
	{
		pid[p1] = ++frpid;
		ret = frpid;
	}
	return ret;
}

bool gone[10010];

int go(int pp)
{
	if (gone[pp])
	{
		return 0;
	}
	else
	{
		int i;
		int s(1);
		gone[pp] = true;
		for (i = p[pp]; i < p[pp + 1]; ++i)
		{
			s += go(paths[i].t);
		}
		return s;
	}
}

char inp[1024];

int inputpoint(void)
{
	scanf("%s", inp);
	char *inpp = inp;
	while (*inpp == '0') ++inpp;
	string str(inpp);
	str += ',';
	scanf("%s", inp);
	inpp = inp;
	while (*inpp == '0') ++inpp;
	str += inpp;
	return gpid(str);
}

int main()
{
	int i, k;
	while (scanf("%d", &k) != EOF)
	{
		memset(paths, 0, sizeof(paths));
		memset(s, 0, sizeof(s));
		memset(p, 0, sizeof(p));
		frpid = 0;
		for (i = 1; i <= k; ++i)
		{
			int pid1 = inputpoint();
			int pid2 = inputpoint();
			paths[i].f = pid1;
			paths[i].t = pid2;
			paths[i + k].f = pid2;
			paths[i + k].t = pid1;
			++s[pid1];
			++s[pid2];
		}
		sort(paths + 1, paths + 1 + k + k);
		p[1] = 1;
		for (i = 1; i <= k; ++i)
		{
			if ((s[i] & 1) == 1)
			{
				break;
			}
			p[i + 1] = p[i] + s[i];
		}
		if (i <= k)
		{
			cout << 0 << endl;
		}
		else
		{
			memset(gone, false, sizeof(gone));
			if (go(1) == k)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}
	return 0;
}
