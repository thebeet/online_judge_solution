/*
 * PKU3272::Cow_Traffic.cpp
 *
 *  Created on: Sep 2, 2008 9:42:35 PM
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
#include <set>

using namespace std;

multiset<int> node[5010];
multiset<int> rnode[5010];
vector<int> deg;
vector<int> in;
vector<int> out;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	deg.reserve(n + 1);
	in.reserve(n + 1);
	out.reserve(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		node[a].insert(b);
		rnode[b].insert(a);
		++deg[b];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (deg[i] == 0)
		{
			in[i] = 1;
		}
		for (set<int>::iterator it = node[i].begin(); it != node[i].end(); ++it)
		{
			in[*it] += in[i];
		}
	}
	out[n] = 1;
	for (int i = n; i >= 1; --i)
	{
		for (set<int>::iterator it = rnode[i].begin(); it != rnode[i].end(); ++it)
		{
			out[*it] += out[i];
		}
	}
	int ans(0);
	for (int i = 1; i <= n; ++i)
	{
		for (set<int>::iterator it = node[i].begin(); it != node[i].end(); ++it)
		{
			ans = max(ans, in[i] * out[*it]);
		}
	}
	cout << ans << endl;
	return 0;
}
