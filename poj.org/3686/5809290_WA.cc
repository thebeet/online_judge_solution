/*
 * PKU3686::The_Windys.cpp
 *
 *  Created on: Sep 3, 2009 2:07:30 PM
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
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 64;
const int INF = 0x7fffffff;

class BGraph_Weight
{
public:
	BGraph_Weight(const int n, const int m) :
		m_n(n), m_m(m)
	{
	}

	void AddPath(const int x, const int y, const int w)
	{
		m_weight[x][y] = w;
	}

	int KM()
	{
		neg();
		int lx[MAXN * MAXN];
		int ly[MAXN * MAXN];
		int match[MAXN * MAXN];

		bool gone_x[MAXN * MAXN];
		bool gone_y[MAXN * MAXN];

		int ans(0);
		memset(lx, -1, sizeof(lx));
		memset(ly, 0, sizeof(ly));

		for (int i = 0; i < m_n; ++i)
		{
			lx[i] = -INF;
			for (int j = 0; j < m_m; ++j)
			{
				lx[i] = max(lx[i], m_weight[i][j]);
			}
		}
		memset(match, -1, sizeof(match));
		for (int i = 0; i < m_n; ++i)
		{
			for ( ; ; )
			{
				memset(gone_x, false, sizeof(gone_x));
				memset(gone_y, false, sizeof(gone_y));
				if (find(i, gone_x, gone_y, lx, ly, match))
				{
					break;
				}
				int d = INF;
				for (int j = 0; j < m_n; ++j)
				{
					if (gone_x[j])
					{
						for (int k = 0; k < m_m; ++k)
						{
							if (gone_y[k] == false)
							{
								d = min(d, lx[j] + ly[k] - m_weight[j][k]);
							}
						}
					}
				}
				for (int j = 0; j < m_n; ++j)
				{
					if (gone_x[j])
					{
						lx[j] -= d;
					}
				}
				for (int j = 0; j < m_m; ++j)
				{
					if (gone_y[j])
					{
						ly[j] += d;
					}
				}
			}
		}
		for (int i = 0; i < m_m; ++i)
		{
			if (match[i] != -1)
			{
				ans -= m_weight[match[i]][i];
			}
		}
		return ans;
	}

//private:
	int m_n, m_m;
	int m_weight[MAXN][MAXN * MAXN];

	void neg(void)
	{
		for (int i = 0; i < m_n; ++i)
		{
			for (int j = 0; j < m_m; ++j)
			{
				m_weight[i][j] = -m_weight[i][j];
			}
		}
	}
	bool find(const int p, bool gone_x[], bool gone_y[], int lx[], int ly[], int match[]) const
	{
		gone_x[p] = true;
		for (int i = 0; i < m_m; ++i)
		{
			if ((gone_y[i] == false) && (lx[p] + ly[i] == m_weight[p][i]))
			{
				gone_y[i] = true;
				if ((match[i] == -1) || (find(match[i], gone_x, gone_y, lx, ly, match)))
				{
					match[i] = p;
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 0; ti < tn; ++ti)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		BGraph_Weight graph(n, m * n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int w;
				scanf("%d", &w);
				for (int h = 0; h < n; ++h)
				{
					graph.AddPath(i, j * n + h, w * (h + 1));
				}
			}
		}

		printf("%.6lf\n", graph.KM() / (double)n);
	}
	return 0;
}

