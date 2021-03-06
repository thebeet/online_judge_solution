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
	vector<int> halls;
	bool operator ^ (const Request req) const
	{
		if ((b < req.a) || (a > req.b)) return false;
		else return true;
	}
};

vector<Request> reqs;

int use[16];

bool dfs(const int p)
{
	if (p == reqs.size())
	{
		return true;
	}
	for (unsigned int i = 0; i < reqs[p].halls.size(); ++i)
	{
		use[p] = reqs[p].halls[i];
		int j;
		for (j = 0; j < p; ++j)
		{
			if (use[j] == use[p])
			{
				if (reqs[j] ^ reqs[p])
				{
					break;
				}
			}
		}
		if (j == p)
		{
			if (dfs(p + 1))
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
		int n;
		cin >> n;
		reqs.clear();
		reqs.resize(n);
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin >> reqs[i].a >> reqs[i].b >> k;
			reqs[i].halls.clear();
			reqs[i].halls.resize(k, 0);
			for (int j = 0; j < k; ++j)
			{
				cin >> reqs[i].halls[j];
			}
		}
		cout << (dfs(0) ? "YES" : "NO") << endl;
	}
	return 0;
}


