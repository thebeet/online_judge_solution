/*
 * URAL_70_H::Far_Away_Kingdom_s_Army.cpp
 *
 *  Created on: Nov 1, 2008 8:14:18 PM
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

vector<int> armys;

int ans[16][16];

int main()
{
	int n;
	cin >> n;
	armys.resize(n * n, 0);
	for (int i = 0; i < n * n; ++i)
	{
		cin >> armys[i];
	}
	sort(armys.begin(), armys.end(), greater<int>());

	int n2(n / 2);
	int k = 0;
	ans[n2][n2] = armys[0];

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			int x = n2 - j;
			int y = n2 - i + j;
			if ((x >= 0) && (x < n) && (y >= 0) && (y < n))
			{
				ans[x][y] = armys[++k];
			}
		}
		for (int j = 0; j < i; ++j)
		{
			int x = n2 - i + j;
			int y = n2 + j;
			if ((x >= 0) && (x < n) && (y >= 0) && (y < n))
			{
				ans[x][y] = armys[++k];
			}
		}
		for (int j = 0; j < i; ++j)
		{
			int x = n2 + j;
			int y = n2 + i - j;
			if ((x >= 0) && (x < n) && (y >= 0) && (y < n))
			{
				ans[x][y] = armys[++k];
			}
		}
		for (int j = 0; j < i; ++j)
		{
			int x = n2 + i - j;
			int y = n2 - j;
			if ((x >= 0) && (x < n) && (y >= 0) && (y < n))
			{
				ans[x][y] = armys[++k];
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}


