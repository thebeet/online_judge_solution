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

bool st[65536];

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(st, false, sizeof(st));
		st[0] = true;
		int mm = 1 << m;
		for (int i = 0; i < m; ++i)
		{
			int s(0);
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &mat[i][j]);
				(s <<= 1) += mat[i][j];
			}
			for (int j = 0; j < mm; ++j)
			{
				if ((st[j]) && ((j & s) == 0))
				{
					st[j | s] = true;
				}
			}
		}
		if (st[mm - 1])
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
