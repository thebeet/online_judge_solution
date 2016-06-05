/*
 * USTC_1::Constellations.cpp
 *
 *  Created on: Sep 29, 2008 2:13:48 PM
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

const int MAX(1024);

int n, m;
char map[1024][1024];
int sum[1024][1024];
int tsum[1024][1024];
int ssum[1024][1024];
int tssum[1024][1024];
int sssum[1024][1024];
int asum[1024][1024];

int a, b;
char smap[128][64][64];

int msum[128];
int masum[128];
bool ok[128];
/*
3 6 1 3 2
*00*00
000000
00*000

00
00
00
 */
bool check(const int x, const int y, const int p)
{
	/*	return true;
	return ((map[x][y] == smap[p][0][0]) &&
			(map[x + a - 1][y] == smap[p][a - 1][0]) &&
			(map[x + a - 1][y + b - 1] == smap[p][a - 1][b - 1]) &&
			(map[x][y + b - 1] == smap[p][0][b - 1]));
	*/
	for (int i = 0; i < (a + 1) / 2; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			if (map[i + x][j + y] != smap[p][i][j])
			{
				return false;
			}
		}
	}
		return true;

	/*for (int i = 0; i < a; ++i)
	{
		if ((map[i + x][y] != smap[p][i][0]) || (map[i + x][y + b - 1] != smap[p][i][b - 1]))
		{
			return false;
		}
	}
	for (int j = 0; j < b; ++j)
	{
		if ((map[x][j + y] != smap[p][0][j]) || (map[x + a - 1][j + y] != smap[p][a - 1][j]))
		{
			return false;
		}
	}
	return true;*/
}

void debugout(int mm[MAX][MAX], int n, int m, char * name)
{
	cout << name << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << mm[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int i, j;
	int ans(0);
	int caseid(0);
	while (scanf("%d%d", &n, &m), n > 0)
	{
		memset(map, 0, sizeof(map));
		memset(sum, 0, sizeof(sum));
		memset(tsum, 0, sizeof(tsum));
		memset(ssum, 0, sizeof(ssum));
		memset(tssum, 0, sizeof(tssum));
		memset(sssum, 0, sizeof(sssum));
		memset(asum, 0, sizeof(asum));
		memset(smap, 0, sizeof(smap));
		memset(ok, false, sizeof(ok));
		ans = 0;

		cout << "Case " << ++caseid << ": ";

		int tt(0);

		memset(msum, 0, sizeof(msum));
		memset(masum, 0, sizeof(masum));
		scanf("%d", &tt);
		scanf("%d%d", &a, &b);
		for (i = 1; i <= n; ++i)
		{
			scanf("%s", map[i] + 1);
		}
		for (int ti = 0; ti < tt; ++ti)
		{
			for (i = 0; i < a; ++i)
			{
				scanf("%s", smap[ti][i]);
				for (j = 0; j < b; ++j)
				{
					//smap[ti][i][j] -= '*';
					msum[ti] += (int)smap[ti][i][j];
					masum[ti] += (int)smap[ti][i][j] * ((a - i) * 256 + b - j);
				}
			}
		}
		//cout << msum << " " << masum << endl;
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= m; ++j)
			{
				//map[i][j] -= '*';
				sum[i][j] = sum[i][j - 1] + (int)map[i][j];
				if (j > b)
				{
					sum[i][j] -= (int)map[i][j - b];
				}
				tsum[i][j] = tsum[i][j - 1] + sum[i][j];
				if (j > b)
				{
					tsum[i][j] -= b * (int)map[i][j - b];
				}

				ssum[i][j] = ssum[i - 1][j] + sum[i][j];
				tssum[i][j] = tssum[i - 1][j] + tsum[i][j];
				if (i > a)
				{
					ssum[i][j] -= sum[i - a][j];
					tssum[i][j] -= tsum[i - a][j];
				}
				sssum[i][j] = sssum[i - 1][j] + (ssum[i][j] << 8);
				if (i > a)
				{
					sssum[i][j] -= a * (sum[i - a][j] << 8);
				}
				asum[i][j] = sssum[i][j] + tssum[i][j];
				if ((i >= a) && (j >= b))
				{
					for (int ti = 0; ti < tt; ++ti)
					{
						if (ok[ti] == false)
						{
							if ((ssum[i][j] == msum[ti]) && (masum[ti] == asum[i][j]))
							{
								if (check(i - a + 1, j - b + 1, ti))
								{
									++ans;
									ok[ti] = true;
		/*							if (++ans == 1)
									{
										ansx = i - a;
										ansy = j - b;
									}
									else
									{
										cout << "ambiguous" << endl;
										return 0;
									}*/
								}
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
		/*

		debugout(sum, n, m, "sum");
		debugout(tsum, n, m, "tsum");
		debugout(ssum, n, m, "ssum");
		debugout(tssum, n, m, "tssum");
		debugout(sssum, n, m, "sssum");
		debugout(asum, n, m, "asum");//*/
	}
	return 0;
}
