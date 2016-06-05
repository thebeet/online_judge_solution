/*
 * PKU3519::Minimal_Backgammon.cpp
 *
 *  Created on: Oct 10, 2008 12:35:57 PM
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

double poss[128][128];
int board[128];

int main()
{
	int n, t, l, b;
	while ((cin >> n >> t >> l >> b), n > 0)
	{
		int pos;
		for (int i = 0; i <= n; ++i)
		{
			board[i] = i;
		}
		for (int i = 0; i < l; ++i)
		{
			cin >> pos;
			board[pos] = -pos;
		}
		for (int i = 0; i < b; ++i)
		{
			cin >> pos;
			board[pos] = 0;
		}
		for (int i = n + 1; i < n + 6; ++i)
		{
			board[i] = board[n - (i - n)];
		}
		memset(poss, 0, sizeof(poss));
		poss[0][0] = 1.0;
		for (int i = 1; i <= t; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 1; k <= 6; ++k)
				{
					if (board[j + k] < 0)
					{
						poss[i + 1][-board[j + k]] += poss[i - 1][j] / 6.0;
					}
					else
					{
						poss[i][board[j + k]] += poss[i - 1][j] / 6.0;
					}
				}
			}
			poss[i][n] += poss[i - 1][n];
		}
		printf("%.10lf\n", poss[t][n]);
	}
	return 0;
}

