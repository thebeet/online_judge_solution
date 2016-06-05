/*
 * PKU3692::Kindergarten.cpp
 *
 *  Created on: Oct 22, 2008 9:27:30 PM
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

using namespace std;

const int MAXN = 256;

int n;

class BGraph
{
public:
	BGraph(){}
	~BGraph(){}
	int Hungary(void)
	{
		int ans(0);
		memset(px, 0, sizeof(px));
		memset(py, 0, sizeof(py));

		for (int k = 0; k < n; ++k)
		{
			if (px[k] == 0)
			{
				memset(gone, false, sizeof(gone));
				if (hungary_dfs(k))
				{
					++ans;
				}
			}
		}
		return ans;
	}

//private:
	int n, m;
	bool connect[MAXN][MAXN];
	bool gone[MAXN];
	int px[MAXN];
	int py[MAXN];
	bool hungary_dfs(const int pp)
	{
		int i;
		if (gone[pp] == false)
		{
			gone[pp] = true;
			for (i = 0; i < m; ++i)
			{
				if (connect[pp][i] && ((py[i] == 0) || hungary_dfs(py[i])))
				{
					py[i] = pp;
					px[pp] = i;
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	BGraph bg;
	int m;
	int caseid(0);
	while (scanf("%d%d%d", &bg.n, &bg.m, &m), bg.n > 0)
	{
		memset(bg.connect, true, sizeof(bg.connect));
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			bg.connect[a - 1][b - 1] = false;
		}
		printf("Case %d: %d\n", ++caseid, bg.n + bg.m - bg.Hungary());
	}
	return 0;
}
