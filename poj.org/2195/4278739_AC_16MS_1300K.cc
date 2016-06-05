/*
 * PKU2195::Going_Home.cpp
 *
 *  Created on: Oct 26, 2008 7:35:50 PM
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
const int INF = 0x7fffffff;

class BGraph_Weight
{
public:
	BGraph_Weight(){}
	~BGraph_Weight(){}
	int KM(const bool maxsum = false)
	{
		int ans(0);
		memset(lx, -1, sizeof(lx));
		memset(ly, 0, sizeof(ly));

		if (maxsum) neg();

		for (int i = 0; i < n; ++i)
		{
			lx[i] = -INF;
			for (int j = 0; j < m; ++j)
			{
				lx[i] = max(lx[i], weight[i][j]);
			}
		}
		memset(match, -1, sizeof(match));
		for (int i = 0; i < n; ++i)
		{
			for ( ; ; )
			{
				memset(gone_x, false, sizeof(gone_x));
				memset(gone_y, false, sizeof(gone_y));
				if (find(i))
				{
					break;
				}
				int d = INF;
				for (int j = 0; j < n; ++j)
				{
					if (gone_x[j])
					{
						for (int k = 0; k < m; ++k)
						{
							if (gone_y[k])
							{
								d = min(d, lx[j] + ly[k] - weight[i][j]);
							}
						}
					}
				}
				for (int j = 0; j < n; ++j)
				{
					if (gone_x[j])
					{
						lx[j] -= gone_x[j];
					}
				}
				for (int j = 0; j < m; ++j)
				{
					if (gone_y[j])
					{
						ly[j] += gone_y[j];
					}
				}
			}
		}
		for (int i = 0; i < m; ++i)
		{
			if (match[i] != -1)
			{
				ans += weight[match[i]][i];
			}
		}
		if (maxsum) neg();
		return ans;
	}

//private:
	int n, m;
	int weight[MAXN][MAXN];
	int lx[MAXN];
	int ly[MAXN];
	int match[MAXN];

	bool gone_x[MAXN];
	bool gone_y[MAXN];

	void neg(void)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				weight[i][j] = -weight[i][j];
			}
		}
	}
	bool find(const int p)
	{
		gone_x[p] = true;
		for (int i = 0; i < m; ++i)
		{
			if ((gone_y[i] == false) && (lx[p] + ly[i] == weight[p][i]))
			{
				gone_y[i] = true;
				if ((match[i] == -1) || (find(match[i])))
				{
					match[i] = p;
					return true;
				}
			}
		}
		return false;
	}
};

BGraph_Weight bg;

char map[128][128];

int mx[128];
int my[128];
int hx[128];
int hy[128];

int main()
{
	int n, m;
	while ((cin >> n >> m), n > 0)
	{
		memset(&bg, 0, sizeof(bg));
		for (int i = 0; i < n; ++i)
		{
			cin >> map[i];
			for (int j = 0; j < m; ++j)
			{
				if (map[i][j] == 'm')
				{
					mx[bg.n] = i;
					my[bg.n] = j;
					++bg.n;
				}
				else if (map[i][j] == 'H')
				{
					hx[bg.m] = i;
					hy[bg.m] = j;
					++bg.m;
				}
			}
		}
		for (int i = 0; i < bg.n; ++i)
		{
			for (int j = 0; j < bg.m; ++j)
			{
				bg.weight[i][j] = abs(mx[i] - hx[j]) + abs(my[i] - hy[j]);
			}
		}
		cout << -bg.KM(true) << endl;
	}
	return 0;
}


