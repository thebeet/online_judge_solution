/*
 * PKU3139::Balancing_the_Scale.cpp
 *
 *  Created on: Oct 8, 2008 9:02:12 PM
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
#include <map>

using namespace std;

int arr[16];

int eightn(0);
int eight[6435];
int eight_b[6435];

int perm[32][4];

int ans[65536];

int tt[65536];
int ss[65536];

int pp[10231];
int slotn;
int slot[43680];
int next[43680];

void init(void)
{
	for (int i = 0; i < 32768; ++i)
	{
		int ans(0);
		for (int k = 0; k < 15; ++k)
		{
			if (i & (1 << k)) ++ans;
		}
		if (ans == 8)
		{
			eight[eightn] = i;
			eight_b[eightn] = (~i) & 0xffff;
			++eightn;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		perm[0][i] = i;
	}
	for (int j = 1; j < 24; ++j)
	{
		std::next_permutation(perm[0], perm[0] + 4);
		memcpy(perm[j], perm[0], sizeof(int) * 4);
	}
	std::next_permutation(perm[0], perm[0] + 4);
}

void calc4_0(const int arr4[4], const int ppp)
{
	for (int i = 0; i < 24; ++i)
	{
		int sums = arr4[perm[i][0]] + arr4[perm[i][1]] * 2 + arr4[perm[i][2]] * 3 + arr4[perm[i][3]] * 4;
		slot[slotn] = ppp;
		next[slotn] = pp[sums];
		pp[sums] = slotn;
		++slotn;
	}
}

int main()
{
	init();
	int ti(0);
	while ((scanf("%d", &arr[0])), arr[0] > 0)
	{
		for (int i = 1; i < 16; ++i)
		{
			scanf("%d", &arr[i]);
		}
		memset(ans, 0, sizeof(ans));
		slotn = 0;
		memset(pp, -1, sizeof(pp));
		memset(next, -1, sizeof(next));
		int arr4[4];
		for (int i1 = 0; i1 < 13; ++i1)
		{
			int pp1(1 << i1);
			arr4[0] = arr[i1];
			for (int i2 = i1 + 1; i2 < 14; ++i2)
			{
				int pp2  = pp1 | (1 << i2);
				arr4[1] = arr[i2];
				for (int i3 = i2 + 1; i3 < 15; ++i3)
				{
					int pp3 = pp2 | (1 << i3);
					arr4[2] = arr[i3];
					for (int i4 = i3 + 1; i4 < 16; ++i4)
					{
						int pp4 = pp3 | (1 << i4);
						arr4[3] = arr[i4];
						calc4_0(arr4, pp4);
					}
				}
			}
		}
		for (int i = 22; i <= 10230; ++i)
		{
			int ppp = pp[i];
			int nnn(0);
			while (ppp >= 0)
			{
				tt[nnn] = slot[ppp];
				++nnn;
				ppp = next[ppp];
			}
			if (nnn < 2) continue;
 			sort(tt, tt + nnn);
			int tnt(0);
			ss[0] = 1;
			for (int i1 = 1; i1 < nnn; ++i1)
			{
				if (tt[i1] != tt[i1 - 1])
				{
					++tnt;
					ss[tnt] = 1;
					tt[tnt] = tt[i1];
				}
				else
				{
					++ss[tnt];
				}
			}
			for (int i1 = 0; i1 < tnt; ++i1)
			{
				for (int i2 = i1 + 1; i2 <= tnt; ++i2)
				{
					if ((tt[i1] & tt[i2]) == 0)
					{
						ans[tt[i1] | tt[i2]] += ss[i1] * ss[i2];
					}
				}
			}
		}
		int total(0);
		for (int i = 0; i < eightn; ++i)
		{
			total += ans[eight[i]] * ans[eight_b[i]];
		}
		printf("Case %d: %d\n", ++ti, total);
	}
	return 0;
}

