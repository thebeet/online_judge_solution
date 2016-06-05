/*
 * PKU1655::Balancing_Act.cpp
 *
 *  Created on: Sep 3, 2008 4:50:44 PM
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

vector< vector<int> > graph;
vector< int > contain;

int n, ans, ansp;

int dfs(const int p, const int pre)
{
	int tans(0);
	contain[p] = 1;
	for (vector<int>::iterator it = graph[p].begin(); it != graph[p].end(); ++it)
	{
		if (*it != pre)
		{
			contain[p] += dfs(*it, p);
			tans = max(tans, contain[*it]);
		}
	}
	tans = max(tans, n - contain[p]);
	if ((tans < ans) || ((tans == ans) && (p < ansp)))
	{
		ans = tans;
		ansp = p;
	}
	return contain[p];
}

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 0; ti < tn; ++ti)
	{
		int i;
		cin >> n;
		ans = n;
		ansp = 0;
		graph.resize(n + 1, vector<int>());
		contain.resize(n + 1, 0);
		for (i = 1; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1, 0);
		cout << ansp << " " << ans << endl;
	}
	return 0;
}
