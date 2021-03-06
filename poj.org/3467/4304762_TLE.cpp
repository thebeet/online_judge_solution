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


int n, m;

void calc_x(const int y)
{
	for (int i = 1; i <= n; ++i)
	{
		int j;
		for (j = i + 1; board[j][y] == board[i][y]; ++j)
		{
		}
		--j;
		for (int k = i; k <= j; ++k)
		{
			ans[0][k][y] = j - k;
		}
		i = j;
	}
	for (int i = n; i >= 1; --i)
	{
		int j;
		for (j = i - 1; board[j][y] == board[i][y]; --j)
		{
		}
		++j;
		for (int k = i; k >= j; --k)
		{
			ans[1][k][y] = k - j;
		}
		i = j;
	}
}

void calc_y(const int x)
{
	for (int i = 1; i <= m; ++i)
	{
		int j;
		for (j = i + 1; board[x][j] == board[x][i]; ++j)
		{
		}
		--j;
		for (int k = i; k <= j; ++k)
		{
			ans[2][x][k] = j - k;
		}
		i = j;
	}
	for (int i = m; i >= 1; --i)
	{
		int j;
		for (j = i - 1; board[x][j] == board[x][i]; --j)
		{
		}
		++j;
		for (int k = i; k >= j; --k)
		{
			ans[3][x][k] = k - j;
		}
		i = j;
	}
}

void modify(const int x, const int y, const int k)
{
	board[x][y] = k;
	for (int i = 1; i <= x; ++i)
	{
		int j;
		for (j = i + 1; board[j][y] == board[i][y]; ++j)
		{
		}
		--j;
		if (j >= x - 1)
		{
			for (int k = i; k <= j; ++k)
			{
				ans[0][k][y] = j - k;
			}
		}
		i = j;
	}
	for (int i = n; i >= x; --i)
	{
		int j;
		for (j = i - 1; board[j][y] == board[i][y]; --j)
		{
		}
		++j;
		if (j <= x + 1)
		{
			for (int k = i; k >= j; --k)
			{
				ans[1][k][y] = k - j;
			}
		}
		i = j;
	}
	for (int i = 1; i <= y; ++i)
	{
		int j;
		for (j = i + 1; board[x][j] == board[x][i]; ++j)
		{
		}
		--j;
		if (j >= y - 1)
		{
			for (int k = i; k <= j; ++k)
			{
				ans[2][x][k] = j - k;
			}
		}
		i = j;
	}
	for (int i = m; i >= y; --i)
	{
		int j;
		for (j = i - 1; board[x][j] == board[x][i]; --j)
		{
		}
		++j;
		if (j <= y + 1)
		{
			for (int k = i; k >= j; --k)
			{
				ans[3][x][k] = k - j;
			}
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
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d", &board[i][j]);
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			calc_y(i);
		}
		for (int j = 1; j <= m; ++j)
		{
			calc_x(j);
		}
		for (int r = 0; r < q; ++r)
		{
			char op[4];
			scanf("%s", op);
			if (op[0] == 'C')
			{
				int x, y, k;
				scanf("%d%d%d", &x, &y, &k);
				modify(x, y, k);
			}
			else
			{
				int c;
				scanf("%d", &c);
				int sans(0);
				for (int i = 1; i <= n; ++i)
				{
					for (int j = 1; j <= m; ++j)
					{
						if (board[i][j] == c)
						{
							sans += min(min(ans[0][i][j], ans[1][i][j]), min(ans[2][i][j], ans[3][i][j]));
						}
					}
				}
				printf("%d\n", sans);
			}
		}
	}
	return 0;
}


