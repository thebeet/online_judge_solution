/*
 * PKU3279::Fliptile.cpp
 *
 *  Created on: Oct 9, 2008 10:02:52 PM
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

int n, m;

int square[32][32];

int ans[32][32];

bool dfs(const int x, const int y)
{
	if (y == 1)
	{
		if (dfs(x % n + 1, x / n + y)) return true;
		ans[x][y] = 1;
		square[x - 1][y] ^= 1;
		square[x][y] ^= 1;
		square[x + 1][y] ^= 1;
		square[x][y + 1] ^= 1;
		if (dfs(x % n + 1, x / n + y)) return true;
		square[x - 1][y] ^= 1;
		square[x][y] ^= 1;
		square[x + 1][y] ^= 1;
		square[x][y + 1] ^= 1;
	}
	else if (y <= m)
	{
		ans[x][y] = square[x][y - 1];
		if (ans[x][y])
		{
			square[x - 1][y] ^= 1;
			square[x][y] ^= 1;
			square[x + 1][y] ^= 1;
			square[x][y + 1] ^= 1;
			square[x][y - 1] ^= 1;
		}
		if (dfs(x % n + 1, x / n + y)) return true;
		if (ans[x][y])
		{
			square[x - 1][y] ^= 1;
			square[x][y] ^= 1;
			square[x + 1][y] ^= 1;
			square[x][y + 1] ^= 1;
			square[x][y - 1] ^= 1;
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			if (square[i][m] == 1)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> square[i][j];
		}
	}
	if (dfs(1, 1))
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cout << ans[j][i] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}


