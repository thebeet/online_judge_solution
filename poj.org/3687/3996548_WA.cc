/*
 * PKU3687::Labeling_Balls.cpp
 *
 *  Created on: Aug 31, 2008 12:09:08 PM
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
#include <stack>
#include <map>

using namespace std;

bool pre[256];

char balls[256][256];

int deg[256];

bool gone[256];
int ans[256];
int tans[256];

int n;

map<int, bool> hash;
map<int, bool> tt[256];

bool check(void)
{
	int i, j;
	memset(gone, false, sizeof(gone));
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (deg[j] == 0)
			{
				for (int k = 1; k <= n; ++k)
				{
					if (balls[k][j] == 1)
					{
						--deg[k];
					}
				}
				deg[j] = -1;
				break;
			}
		}
		if (j > n) break;
	}
	return (i > n);
}

void maketree(const int p)
{
	if (gone[p]) return;
	hash[p] = true;
	gone[p] = true;
	for (int i = 1; i <= n; ++i)
	{
		if (balls[p][i] == 1)
		{
			maketree(i);
		}
	}
}

void maketree_u(const int p)
{
	memset(gone, false, sizeof(gone));
	hash.clear();
	maketree(p);
	tt[p] = hash;
}


int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 0; ti < tn; ++ti)
	{
		int i, m;
		scanf("%d%d", &n, &m);
		memset(balls, 0, sizeof(balls));
		memset(deg, 0, sizeof(deg));
		bool flag(false);
		for (i = 0; i < m; ++i)
		{
			int a, b;
			scanf("%d%d", &b, &a);
			if ((balls[a][b] == 2) || (a == b))
			{
				flag = true;
			}
			balls[a][b] = 1;
			balls[b][a] = 2;
			++deg[a];
		}
		if (flag)
		{
			printf("-1\n");
		}
		else
		{
			if (check())
			{
				memset(ans, 0, sizeof(ans));
				memset(tans, 0, sizeof(tans));
				vector<int> ansset;
				ansset.push_back(0);
				stack<int> st;
				for (i = 1; i <= n; ++i)
				{
					maketree_u(i);
					ansset.push_back(i);
				}
				for (i = n; i >= 1; --i)
				{
					st.push(i);
				}
				while (st.empty() == false)
				{
					int x = st.top();
					st.pop();
					if (ans[x] > 0) continue;
					//cerr << tt[x].size() << endl;
					ans[x] = ansset[tt[x].size()];
					ansset.erase(ansset.begin() + tt[x].size());
					for (int j = 1; j <= n; ++j)
					{
						if (tt[j].find(x) != tt[j].end())
						{
							tt[j].erase(x);
						}

					}
					for (map<int, bool>::reverse_iterator it = tt[x].rbegin(); it != tt[x].rend(); ++it)
					{
						int ti = it->first;
						if (ti == x) continue;
						st.push(it->second);
					}
				}

				for (i = 1; i <= n; ++i)
				{
					printf("%d ", ans[i]);
				}
				printf("\n");
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}
