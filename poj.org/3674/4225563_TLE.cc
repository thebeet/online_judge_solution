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

using namespace std;

int skill[16][512];
int p[64];

#define TTT 15

int calc(int h, int p[], int enh)
{
	if (h == 5)
	{
		int ans(0);
		for (int i = 0; i <= 10; ++i)
		{
			ans = max(ans, skill[i][p[i]]);
		}
		return ans * (10 + enh);
	}
	++h;
	int m(6 - h);
	int ans(0);
	int big[16];
	memset(big, 0, sizeof(big));
	for (int i = 10; i >= 0; --i)
	{
		for (int j = p[i]; j >= p[i] - m; --j)
		{
			if (j > 0)
			{
				if (big[0] == TTT)
				{
					if (big[TTT] >= skill[i][j])
					{
						break;
					}
				}
				int k;
				for (k = 1; k <= big[0]; ++k)
				{
					if (big[k] < skill[i][j])
					{
						for (int h = big[0]; h >= k; --h)
						{
							big[h + 1] = big[h];
						}
						++big[0];
						break;
					}
				}
				big[k] = skill[i][j];
				if (k > big[0]) big[0] = k;
				if (big[0] > TTT)
				{
					big[0] = TTT;
				}
				int t = skill[i][j];
				for (int k = j; k < p[i]; ++k)
				{
					skill[i][k] = skill[i][k + 1];
				}
				skill[i][p[i]] = t;

				int nowdam = skill[i][p[i]] * (10 + enh);
				--p[i];
				nowdam += calc(h, p, i);
				ans = max(ans, nowdam);
				++p[i];

				t = skill[i][p[i]];
				for (int k = p[i]; k > j; --k)
				{
					skill[i][k] = skill[i][k - 1];
				}
				skill[i][j] = t;
			}
		}
	}
	return ans;
}

int main()
{
	int i, j, n;
	while (scanf("%d", &n) != EOF)
	{
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
		printf("%d\n", calc(0, p, 0));
	}
	return 0;
}
