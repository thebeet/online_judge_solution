/*
 * PKU3674::Super_Assassin.cpp
 *
 *  Created on: Oct 15, 2008 6:26:25 PM
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

using namespace std;

const int TTT = 50;
int skill[16][512];
int p[16];
int pp[16];
int ss[16];

struct Enh
{
	Enh(const int p = 0, const int pe = 0) :
		pos(p), preenh(pe)
	{

	}
	int pos;
	int preenh;
	bool operator < (const Enh &e) const
	{
		return preenh > e.preenh;
	}
};

vector<Enh> Enhs[16];
int ans(0);

void calc(int h)
{
	if (h == 6)
	{
		int st[16];
		int en[16];
		int tans(0);
		memset(en, 0, sizeof(en));
		for (int i = 0; i <= 10; i++)
		{
			Enhs[i].clear();
		}
		Enhs[ss[1]].push_back(Enh(1, 0));
		for (int i = 2; i <= 6; i++)
		{
			Enhs[ss[i]].push_back(Enh(i, ss[i - 1]));
		}
		for (int i = 0; i <= 10; i++)
		{
			sort(Enhs[i].begin(), Enhs[i].end());
			for (int j = 0; j < Enhs[i].size(); --j)
			{
				st[Enhs[i][j].pos] = skill[i][pp[i] - j];
				en[Enhs[i][j].pos + 1] = i;
			}
		}
		for (int i = 1; i <= 6; i++)
		{
			tans += st[i] * (10 + en[i]);
		}
		ans = max(ans, tans);
		return;
	}
	++h;
	for (int i = 0; i <= 10; ++i)
	{
		if (p[i] > 0)
		{
			--p[i];
			ss[h] = i;
			calc(h);
			++p[i];
		}
	}
}

int main()
{
	int i, n;
	while (scanf("%d", &n) != EOF)
	{
		ans = 0;
		memset(skill, 0, sizeof(skill));
		for (i = 1; i <= n; ++i)
		{
			int dam, enh;
			scanf("%d%d", &dam, &enh);
			skill[enh][++skill[enh][0]] = dam / 10;
		}
		for (int i = 0; i <= 10; ++i)
		{
			sort(skill[i] + 1, skill[i] + skill[i][0] + 1);
			p[i] = skill[i][0];
		}
		memcpy(pp, p, sizeof(p));
		calc(0);
		printf("%d\n", ans);
	}
	return 0;
}
