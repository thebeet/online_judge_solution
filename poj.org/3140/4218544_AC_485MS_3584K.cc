/*
 * PKU3140::Contestants_Division.cpp
 *
 *  Created on: Oct 9, 2008 3:21:33 PM
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


int Node[100010];
long long Sum[100010];
int pp[100010];
int slotn;
int slot[200010];
int next[200010];

long long Sums(0);

long long ans(0x7fffffffffffffffLL);

long long dfs(const int p, const int pr)
{
	Sum[p] = Node[p];
	int ppp = pp[p];
	while (ppp >= 0)
	{
		if (slot[ppp] != pr)
		{
			Sum[p] += dfs(slot[ppp], p);
		}
		ppp = next[ppp];
	}
	long long dif = abs(Sums - Sum[p] - Sum[p]);
	if (ans > dif)
	{
		ans = dif;
	}
	return Sum[p];
}

int main()
{
	int n, m;
	int ti(0);
	while (scanf("%d%d", &n, &m), n > 0)
	{
		memset(next, -1, sizeof(next));
		memset(pp, -1, sizeof(pp));
		Sums = 0LL;
		slotn = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &Node[i]);
			Sums += (long long)Node[i];
		}
		ans = Sums;
		for (int i = 0; i < m; ++i)
		{
			int s, e;
			scanf("%d%d", &s, &e);
			slot[slotn] = e;
			next[slotn] = pp[s];
			pp[s] = slotn;
			++slotn;
			slot[slotn] = s;
			next[slotn] = pp[e];
			pp[e] = slotn;
			++slotn;
		}

		dfs(1, 0);
		cout << "Case " << ++ti << ": " << ans << endl;
	}
	return 0;
}

