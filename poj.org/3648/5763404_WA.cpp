/*
 * PKU3648::Wedding.cpp
 *
 *  Created on: Aug 27, 2009 12:23:30 PM
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

int n, m;

int getpeople()
{
	char buf[16];
	cin >> buf;
	int ans = 0;
	if (buf[strnlen(buf, 16) - 1] == 'w')
	{
		ans += n;
	}
	buf[strnlen(buf, 16) - 1] = '\0';
	int id;
	sscanf(buf, "%d", &id);
	ans += id;
	return ans;
}

bool rela[64][64];

int ansp[64];

bool DFS(const int p)
{
	if (p == n)
	{
		for (int i = 1; i < n; ++i)
		{
			cout << i << ((ansp[i] == 0) ? "h" : "w") << " ";
		}
		cout << endl;
		return true;
	}
	for (int k = 0; k < 2; ++k)
	{
		ansp[p] = k;
		bool flag = true;
		for (int j = 1; j < p; ++j)
		{
			if (((ansp[p] == ansp[j]) && (ansp[p] == 0) && rela[p + n][j + n]) ||
				((ansp[p] == ansp[j]) && (ansp[p] == 1) && rela[p][j]) ||
				((ansp[p] != ansp[j]) && (ansp[p] == 0) && rela[p + n][j]) ||
				((ansp[p] != ansp[j]) && (ansp[p] == 1) && rela[p][j + n]))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			if (DFS(p + 1)) return true;
		}
	}
	return false;
}

int main()
{
	while ((cin >> n >> m), n > 0)
	{
		memset(rela, false, sizeof(rela));
		for (int i = 0; i < m; ++i)
		{
			int p1 = getpeople();
			int p2 = getpeople();
			rela[p1][p2] = true;
			rela[p2][p1] = true;
		}
		memset(ansp, 0, sizeof(ansp));
		if (DFS(1) == false)
		{
			cout << "bad luck" << endl;
		}
	}
	return 0;
}
