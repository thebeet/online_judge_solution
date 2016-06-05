/*
 * PKU3467::Cross_Counting.cpp
 *
 *  Created on: Oct 31, 2008 6:51:56 PM
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

int board[128][128];
int ans[4][128][128];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool change[4][128][128];

int n, m;

int calc(const int p, const int x, const int y)
{
	if (change[p][x][y])
	{
		int i;
		for (i = 1; ; ++i)
		{
			if (board[x + dx[p] * i][y + dy[p] * i] != board[x][y])
			{
				break;
			}
		}
		ans[p][x][y] = i - 1;
		change[p][x][y] = false;
	}
	return ans[p][x][y];
}

void modify(const int x, const int y, const int k)
{
	board[x][y] = k;
	for (int i = 1; i <= x; ++i)
	{
		int j;
		for (j = i + 1; ; ++j)
		{
			if (board[j][y] != board[i][y])
			{
				break;
			}
		}
		--j;
		for (int k = i; k <= j; ++k)
		{
			ans[0][k][y] = j - k;
		}
		i = j;
	}
	for (int i = n; i >= x; --i)
	{
		int j;
		for (j = i - 1; ; --j)
		{
			if (board[j][y] != board[i][y])
			{
				break;
			}
		}
		++j;
		for (int k = i; k >= j; --k)
		{
			ans[1][k][y] = k - j;
		}
		i = j;
	}
	for (int i = 1; i <= y; ++i)
	{
		int j;
		for (j = i + 1; ; ++j)
		{
			if (board[x][j] != board[x][i])
			{
				break;
			}
		}
		--j;
		for (int k = i; k <= j; ++k)
		{
			ans[2][x][k] = j - k;
		}
		i = j;
	}
	for (int i = m; i >= y; --i)
	{
		int j;
		for (j = i - 1; ; --j)
		{
			if (board[x][j] != board[x][i])
			{
				break;
			}
		}
		++j;
		for (int k = i; k >= j; --k)
		{
			ans[3][x][k] = k - j;
		}
		i = j;
	}
}

int main()
{
	int c, q;
	while (scanf("%d%d%d%d", &n, &m, &c, &q) != EOF)
	{
		memset(board, 0, sizeof(board));
		memset(change, true, sizeof(change));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d", &board[i][j]);
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				for (int h = 0; h < 4; ++h)
				{
					calc(h, i, j);
				}
			}
		}
		for (int r = 0; r < q; ++r)
		{
			char op[4];
			scanf("%s", op);
			switch (op[0])
			{
				case 'C':
				{
					int x, y, k;
					scanf("%d%d%d", &x, &y, &k);
					modify(x, y, k);
					break;
				}
				case 'Q':
				{
					int c;
					scanf("%d", &c);
					int ans(0);
					for (int i = 1; i <= n; ++i)
					{
						for (int j = 1; j <= m; ++j)
						{
							if (board[i][j] == c)
							{
								int tans(1024);
								for (int h = 0; h < 4; ++h)
								{
									tans = min(tans, calc(h, i, j));
								}
								ans += tans;
							}
						}
					}
					printf("%d\n", ans);
					break;
				}
				default:
				{

				}
			}
		}
	}
	return 0;
}


