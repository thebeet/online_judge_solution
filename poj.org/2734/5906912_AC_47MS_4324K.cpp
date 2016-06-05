/*
 * Queens_Knights_and_Pawns.cpp
 *
 *  Created on: Sep 22, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int board[1024][1024];

const int Shift = 10;

int main()
{
	int n, m;
	int ti(0);
	while (scanf("%d%d", &n, &m), (n > 0))
	{
		memset(board, 0, sizeof(board));
		for (int i = 1; i <= 3; ++i)
		{
			int n;
			scanf("%d", &n);
			for (int j = 0; j < n; ++j)
			{
				int x, y;
				scanf("%d%d", &x, &y);
				board[x + Shift][y + Shift] = -i;
			}
		}
		for (int x = Shift + 1; x <= Shift + n; ++x)
		{
			for (int y = Shift + 1; y <= Shift + m; ++y)
			{
				if (board[x][y] < 0)
				{
					if (board[x][y] == -1)
					{
						for (int i = x - 1; i >= Shift; --i)
						{
							if (board[i][y] < 0)
							{
								break;
							}
							board[i][y] = 1;
						}
						for (int i = x + 1; i <= Shift + n; ++i)
						{
							if (board[i][y] < 0)
							{
								break;
							}
							board[i][y] = 1;
						}

						for (int i = y - 1; i >= Shift; --i)
						{
							if (board[x][i] < 0)
							{
								break;
							}
							board[x][i] = 1;
						}
						for (int i = y + 1; i <= Shift + m; ++i)
						{
							if (board[x][i] < 0)
							{
								break;
							}
							board[x][i] = 1;
						}

						for (int i = x - 1, j = y - 1; (i >= Shift) && (j >= Shift); --i, --j)
						{
							if (board[i][j] < 0)
							{
								break;
							}
							board[i][j] = 1;
						}
						for (int i = x + 1, j = y - 1; (i <= Shift + n) && (j >= Shift); ++i, --j)
						{
							if (board[i][j] < 0)
							{
								break;
							}
							board[i][j] = 1;
						}
						for (int i = x - 1, j = y + 1; (i >= Shift) && (j <= Shift + m); --i, ++j)
						{
							if (board[i][j] < 0)
							{
								break;
							}
							board[i][j] = 1;
						}
						for (int i = x + 1, j = y + 1; (i <= Shift + n) && (j <= Shift + m); ++i, ++j)
						{
							if (board[i][j] < 0)
							{
								break;
							}
							board[i][j] = 1;
						}

					}
					else if (board[x][y] == -2)
					{
						if (board[x + 1][y + 2] == 0) board[x + 1][y + 2] = 1;
						if (board[x - 1][y + 2] == 0) board[x - 1][y + 2] = 1;
						if (board[x + 1][y - 2] == 0) board[x + 1][y - 2] = 1;
						if (board[x - 1][y - 2] == 0) board[x - 1][y - 2] = 1;
						if (board[x + 2][y + 1] == 0) board[x + 2][y + 1] = 1;
						if (board[x - 2][y + 1] == 0) board[x - 2][y + 1] = 1;
						if (board[x + 2][y - 1] == 0) board[x + 2][y - 1] = 1;
						if (board[x - 2][y - 1] == 0) board[x - 2][y - 1] = 1;
					}
				}
			}
		}
		int sum(0);
		for (int x = Shift + 1; x <= Shift + n; ++x)
		{
			for (int y = Shift + 1; y <= Shift + m; ++y)
			{
				if (board[x][y] == 0) ++sum;
			}
		}
		cout << "Board " << ++ti << " has " << sum << " safe squares." << endl;
	}
	return 0;
}
