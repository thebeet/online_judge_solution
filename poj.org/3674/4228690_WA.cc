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

long long skill[16][512];
long long p[16];
long long pp[16];
int ss[16];

struct Enh
{
	Enh(const int p = 0, const int pe = 0) :
		pos(p), preenh(pe)
	{

	}
	int pos;
	long long preenh;
	bool operator > (const Enh &e) const
	{
		return preenh > e.preenh;
	}
};

vector<Enh> Enhs[16];
long long ans(0);

void calc(int h)
{
	if (h == 6)
	{
		long long tans(0);
		for (int i = 0; i <= 10; i++)
		{
			Enhs[i].clear();
		}
		for (int i = 1; i <= 6; i++)
		{
			Enhs[ss[i]].push_back(Enh(i, ss[i - 1]));
		}
		for (int i = 0; i <= 10; ++i)
		{
			sort(Enhs[i].begin(), Enhs[i].end(), greater<Enh>());
			for (unsigned int j = 0; j < Enhs[i].size(); ++j)
			{
				tans += skill[i][pp[i] - j] * (10LL + Enhs[i][j].preenh);
			}
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
		memset(ss, 0, sizeof(ss));
		memset(skill, 0, sizeof(skill));
		for (i = 1; i <= n; ++i)
		{
			int dam, enh;
			scanf("%d%d", &dam, &enh);
			skill[enh][++skill[enh][0]] = (long long)(dam / 10);
		}
		for (int i = 0; i <= 10; ++i)
		{
			sort(skill[i] + 1, skill[i] + skill[i][0] + 1);
			p[i] = skill[i][0];
		}
		memcpy(pp, p, sizeof(p));
		calc(0);
		cout << ans << endl;
	}
	return 0;
}
