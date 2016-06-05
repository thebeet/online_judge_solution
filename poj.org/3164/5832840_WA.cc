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

class UnionSet
{
public:
	UnionSet(const int n) :
		m_size(n)
	{
		m_father = new int[n];
		Clear();
	}
	~UnionSet()
	{
		delete [] m_father;
	}

	int FindRoot(const int p)
	{
		if (m_father[p] != p)
		{
			m_father[p] = FindRoot(m_father[p]);
		}
		return m_father[p];
	}

	void Clear()
	{
		for (int i = 0; i < m_size; ++i)
		{
			m_father[i] = i;
		}
	}

	void Merge(const int p1, const int p2)
	{
		int f1 = FindRoot(p1);
		int f2 = FindRoot(p2);
		m_father[f1] = f2;
	}

private:
	int m_size;
	int *m_father;
};

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
			for (int i = 0; i < g.m_size; ++i)
			{
				if ((i == st) || (del[i]))
				{
					continue;
				}
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
			UnionSet us(g.m_size);
			int cyc(-1);
			for (int i = 0; i < g.m_size; ++i)
			{
				if ((i == st) || (del[i]))
				{
					continue;
				}
				int fa1 = us.FindRoot(i);
				int fa2 = us.FindRoot(pre[i]);
				if (fa1 == fa2)
				{
					cyc = i;
					break;
				}
			}
			if (cyc == -1)
			{
				break;
			}
			WeightType cycwei(0);
			cycwei += g.m_mat[pre[cyc]][cyc];
			for (int j = pre[cyc]; j != cyc; j = pre[j])
			{
				cycwei += g.m_mat[pre[j]][j];
				del[j] = true;
			}
			ans += cycwei;

			for (int j = 0; j < g.m_size; ++j)
			{
				if (del[j]) continue;
				if (g.m_mat[j][cyc] < dINF)
				{
					g.m_mat[j][cyc] -= g.m_mat[pre[cyc]][cyc];
				}
			}
			for (int j = pre[cyc]; j != cyc; j = pre[j])
			{
				for (int k = 0; k < g.m_size; ++k)
				{
					if (del[k]) continue;
					g.m_mat[cyc][k] = min(g.m_mat[cyc][k], g.m_mat[j][k]);
					if (g.m_mat[k][j] < dINF)
					{
						g.m_mat[k][cyc] = min(g.m_mat[k][cyc], g.m_mat[k][j] - g.m_mat[pre[cyc]][cyc]);
					}
				}
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
		double x[n];
		double y[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> x[i] >> y[i];
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
			cout << fixed << setprecision(3) <<  MinTreeGraph(g, 0) << endl;
		}
	}
	return 0;
}
