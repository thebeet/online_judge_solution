/*
 * PKU3303::Halls.cpp
 *
 *  Created on: Oct 27, 2008 3:44:25 PM
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

struct Request
{
	int a, b;
	int k;
	int halls[16];
	bool operator ^ (const Request req) const
	{
		if ((b < req.a) || (a > req.b)) return false;
		else return true;
	}
};

Request reqs[16];
bool connect[16][16];
int n;

int use[16];

bool dfs(const int p)
{
	if (p < 0)
	{
		return true;
	}
	for (int i = 0; i < reqs[p].k; ++i)
	{
		use[p] = reqs[p].halls[i];
		int j;
		for (j = n - 1; j > p; --j)
		{
			if ((use[j] == use[p]) && (connect[j][p]))
			{
				break;
			}
		}
		if (j == p)
		{
			if (dfs(p - 1))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> reqs[i].a >> reqs[i].b >> reqs[i].k;
			for (int j = 0; j < reqs[i].k; ++j)
			{
				cin >> reqs[i].halls[j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				connect[i][j] = reqs[i] ^ reqs[j];
			}
		}
		cout << (dfs(n - 1) ? "YES" : "NO") << endl;
	}
	return 0;
}


