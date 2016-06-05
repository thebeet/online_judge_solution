/*
 * Command_Network.cpp
 *
 *  Created on: Sep 7, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

class GraphWeight_Matrix
{
public:
	typedef double WeightType;

	friend int CountConnect(const GraphWeight_Matrix &g, const int st)
	{
		bool gone[g.m_size];
		memset(gone, false, sizeof(gone));
		gone[st] = true;
		stack<int> stac;
		stac.push(st);
		int sum(0);
		while (stac.empty() == false)
		{
			int now = stac.top();
			stac.pop();
			++sum;
			for (int i = 0; i < g.m_size; ++i)
			{
				if ((gone[i] == false) && (g.m_mat[now][i] < dINF))
				{
					gone[i] = true;
					stac.push(i);
				}
			}
		}
		return sum;
	}

	friend WeightType MinTreeGraph(GraphWeight_Matrix &g, const int st)
	{
		bool del[g.m_size];
		memset(del, false, sizeof(del));
		int pre[g.m_size];
		double ans(0);
		for ( ; ; )
		{
			int myset[g.m_size];
			myset[st] = st;
			for (int i = 0; i < g.m_size; ++i)
			{
				if ((i == st) || (del[i]))
				{
					continue;
				}
				myset[i] = i;
				pre[i] = i;
				g.m_mat[i][i] = dINF;
				for (int j = 0; j < g.m_size; ++j)
				{
					if (del[j])
					{
						continue;
					}
					if (g.m_mat[j][i] < g.m_mat[pre[i]][i])
					{
						pre[i] = j;
					}
				}
			}
			bool hascyc(false);
			for (int i = 0; i < g.m_size; ++i)
			{
				if ((i == st) || (del[i]))
				{
					continue;
				}
				if (myset[pre[i]] == myset[i])
				{
					hascyc = true;
					WeightType cycwei(0);
					cycwei += g.m_mat[pre[i]][i];
					for (int j = pre[i]; j != i; j = pre[j])
					{
						cycwei += g.m_mat[pre[j]][j];
						del[j] = true;
					}
					ans += cycwei;

					for (int k = 0; k < g.m_size; ++k)
					{
						if (del[k]) continue;
						if (g.m_mat[k][i] < dINF)
						{
							g.m_mat[k][i] -= g.m_mat[pre[i]][i];
						}
					}
					for (int j = pre[i]; j != i; j = pre[j])
					{
						for (int k = 0; k < g.m_size; ++k)
						{
							if (del[k]) continue;
							g.m_mat[i][k] = min(g.m_mat[i][k], g.m_mat[j][k]);
							if (g.m_mat[k][j] < dINF)
							{
								g.m_mat[k][i] = min(g.m_mat[k][i], g.m_mat[k][j] - g.m_mat[pre[j]][j]);
							}
						}
					}
				}
				else
				{
					myset[pre[i]] = myset[i];
				}
			}
			if (hascyc == false)
			{
				break;
			}
		}
		for (int i = 0; i < g.m_size; ++i)
		{
			if (del[i]) continue;
			if (i == st) continue;
			ans += g.m_mat[pre[i]][i];
		}
		return ans;
	}

public:
	GraphWeight_Matrix(const int size) :
		m_size(size)
	{
		Clear();
	}

	void Clear()
	{
		for (int i = 0; i < m_size; ++i)
		{
			for (int j = 0; j < m_size; ++j)
			{
				m_mat[i][j] = dINF;
			}
		}
	}

	void AddPath(const int f, const int t, const WeightType weight)
	{
		m_mat[f][t] = weight;
	}

private:
	static const int MAXNODE = 128;
	int m_size;
	WeightType m_mat[MAXNODE][MAXNODE];
	static const int INF = 0x3fffffff;
	static const WeightType dINF = 1e100;
};

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		GraphWeight_Matrix g(n);
		int x[n];
		int y[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &x[i], &y[i]);
		}
		for (int i = 0; i < m; ++i)
		{
			int f, t;
			scanf("%d%d", &f, &t);
			--f; --t;
			g.AddPath(f, t, sqrt((double)((x[f] - x[t]) * (x[f] - x[t]) + (y[f] - y[t]) * (y[f] - y[t]))));
		}
		if (CountConnect(g, 0) != n)
		{
			printf("poor snoopy\n");
		}
		else
		{
			printf("%.2f\n", MinTreeGraph(g, 0));
		}
	}
	return 0;
}

