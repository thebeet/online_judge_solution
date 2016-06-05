/*
 * PKU2513::Colored_Stricks.cpp
 *
 *  Created on: Sep 28, 2008 2:12:18 PM
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
#include <string>
#include <map>

using namespace std;

int id[500010];
int father[500010];

int findx(const int p)
{
	if (father[p] != p)
	{
		father[p] = findx(father[p]);
	}
	return father[p];
}

int main()
{
	char inp1[16];
	char inp2[16];
	int n(0);
	for (int i = 0; i < 500010; ++i)
	{
		father[i] = i;
	}
	map<string, int> hash;
	while (scanf("%s%s", inp1, inp2) != EOF)
	{
		string str1(inp1);
		string str2(inp2);
		int &d1 = hash[str1];
		int &d2 = hash[str2];
		if (d1 == 0)
		{
			d1 = ++n;
		}
		if (d2 == 0)
		{
			d2 = ++n;
		}
		++id[d1];
		++id[d2];
		father[findx(d1)] = findx(d2);
	}
	int flag(2);
	for (int i = 1; i <= n; ++i)
	{
		if ((id[i] & 1) == 1)
		{
			if (--flag < 0)
			{
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		if (findx(1) != findx(i))
		{
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;
	return 0;
}
