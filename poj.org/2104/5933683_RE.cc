/*
 * USTC_6::Rectangles.cpp
 *
 *  Created on: Sep 29, 2008 3:53:00 PM
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
#include <cstring>
#include <algorithm>

using namespace std;

const int Size = 64;

int xx[1024];
int yy[1024];

int xb[Size];
int yb[Size];

int s[Size][Size];
bool map[Size][Size];
bool use[32];
bool ansmap[1024][Size][Size];
bool ansmap2[1024][Size][Size];

struct Rect
{
	int x1, y1, x2, y2;
};

Rect rects[32];

int main()
{
	int n, m;
	int caseid(0);
	while (scanf("%d%d", &n, &m), n > 0)
	{
		printf("Case %d:\n", ++caseid);
		memset(xx, 0, sizeof(xx));
		memset(yy, 0, sizeof(yy));
		memset(xb, 0, sizeof(xb));
		memset(yb, 0, sizeof(yb));
		memset(s, 0, sizeof(s));

		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d%d%d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);
			xx[rects[i].x1] = 1;
			xx[rects[i].x2] = 1;
			yy[rects[i].y1] = 1;
			yy[rects[i].y2] = 1;
		}
		int xk(-1), yk(-1);
		for (int i = 0; i <= 1000; ++i)
		{
			if (xx[i] > 0)
			{
				xx[i] = ++xk;
				xb[xk] = i;
			}
		}
		for (int i = 0; i <= 1000; ++i)
		{
			if (yy[i] > 0)
			{
				yy[i] = ++yk;
				yb[yk] = i;
			}
		}
		for (int i = 0; i < xk; ++i)
		{
			for (int j = 0; j < yk; ++j)
			{
				s[i][j] = (xb[i + 1] - xb[i]) * (yb[j + 1] - yb[j]);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			rects[i].x1 = xx[rects[i].x1];
			rects[i].x2 = xx[rects[i].x2];
			rects[i].y1 = yy[rects[i].y1];
			rects[i].y2 = yy[rects[i].y2];
		}

		memset(ansmap, false, sizeof(ansmap));
		memset(ansmap2, false, sizeof(ansmap2));
		int mm1 = min(n, 10);
		int mmm = 1 << mm1;
		for (int i = 0; i < mmm; ++i)
		{
			for (int j = 0; j < mm1; ++j)
			{
				if (i & (1 << j))
				{
					for (int x = rects[j].x1; x < rects[j].x2; ++x)
					{
						memset(&ansmap[i][x][rects[j].y1], true, rects[j].y2 - rects[j].y1);
/*						for (int y = rects[j].y1; y < rects[j].y2; ++y)
						{
							ansmap[i][x][y] = true;
						}*/
					}

				}
			}
		}
		mm1 = n - 10;
		if (mm1 >= 0)
		{
			mmm = 1 << mm1;
		}
		else
		{
			mmm = 0;
		}
		for (int i = 0; i < mmm; ++i)
		{
			for (int j = 0; j < mm1; ++j)
			{
				if (i & (1 << j))
				{
					for (int x = rects[j + 10].x1; x < rects[j + 10].x2; ++x)
					{
						memset(&ansmap2[i][x][rects[j + 10].y1], true, rects[j + 10].y2 - rects[j + 10].y1);
/*						for (int y = rects[j + 10].y1; y < rects[j + 10].y2; ++y)
						{
							ansmap2[i][x][y] = true;
						}*/
					}

				}
			}
		}

		for (int i = 1; i <= m; ++i)
		{
			int r;
			scanf("%d", &r);
			memset(use, false, sizeof(use));
			for (int j = 0; j < r; ++j)
			{
				int w;
				scanf("%d", &w);
				use[--w] = true;
			}
			int start(0);
			int ed(0);
			for (int w = 0; w < 10; ++w)
			{
				if (use[w])
				{
					start += (1 << w);
				}
			}
			for (int w = 10; w < 20; ++w)
			{
				if (use[w])
				{
					ed += (1 << (w - 10));
				}
			}
			int ans(0);
			for (int x = 0; x < xk; ++x)
			{
				for (int y = 0; y < yk; ++y)
				{
					if (ansmap[start][x][y] || ansmap2[ed][x][y])
					{
						ans += s[x][y];
					}
				}
			}
			printf("Query %d: %d\n", i, ans);
		}
		printf("\n");
	}
	return 0;
}
