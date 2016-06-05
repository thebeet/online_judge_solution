/*
 * PKU3740::Easy_Finding.cpp
 *
 *  Created on: Aug 23, 2009 12:51:01 PM
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
#include <cstring>

using namespace std;

int mat[16][512];

bool st[512];

int n, m;

bool s(int p)
{
	int j;
	for (j = 0; j < n; ++j)
	{
		if (st[j] == false) break;
	}
	if (j == n)
	{
		return true;
	}
	for (int i = p; i < m; ++i)
	{
		int j;
		for (j = 0; j < n; ++j)
		{
			if (st[j] && (mat[i][j] == 1))
			{
				break;
			}
		}
		if (j < n)
		{
			continue;
		}
		for (j = 0; j < n; ++j)
		{
			if (mat[i][j] == 1)
			{
				st[j] = true;
			}
		}
		if (s(i + 1)) return true;
		for (j = 0; j < n; ++j)
		{
			if (mat[i][j] == 1)
			{
				st[j] = false;
			}
		}
	}
	return false;
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &mat[i][j]);
			}
		}
		memset(st, false, sizeof(st));
		if (s(0))
		{
			cout << "Yes, I found it" << endl;
		}
		else
		{
			cout << "It is impossible" << endl;
		}

	}
	return 0;
}
