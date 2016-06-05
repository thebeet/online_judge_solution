/*
 * Ranking_the_Cows.cpp
 *
 *  Created on: 2009-9-11
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

using namespace std;

const int INF = 0x3fffffff;

class Graph
{
	friend int CountConnect(const Graph &g, const int st)
	{
		bool gone[g.nodesize];
		memset(gone, false, sizeof(gone));
		int sum(0);
		stack<int> stac;
		stac.push(st);
		gone[st] = true;
		while (stac.empty() == false)
		{
			int now = stac.top();
			stac.pop();
			++sum;
			for (int pp = g.path_head[now]; pp != -1; pp = g.path_next[pp])
			{
				if (gone[g.path_to[pp]] == false)
				{
					gone[g.path_to[pp]] = true;
					stac.push(g.path_to[pp]);
				}
			}
		}
		return sum;
	}

public:
	Graph(const int n = 0) :
		nodesize(n)
	{
		Clear();
	}
	virtual ~Graph()
	{
	}

	int Size() const
	{
		return nodesize;
	}

	void AddPath(const int f, const int t)
	{
		path_to[end_path_slot] = t;
		path_next[end_path_slot] = path_head[f];
		path_head[f] = end_path_slot;
		++end_path_slot;
	}

	void Clear()
	{
		memset(path_head, -1, sizeof(path_head));
		memset(path_next, -1, sizeof(path_next));
		end_path_slot = 0;
	}

	void Input(Graph &g2) // use scanf
	{
		int pathsize;
		if (scanf("%d%d", &nodesize, &pathsize) != EOF)
		{
			g2.nodesize = nodesize;
			for (int i = 0; i < pathsize; ++i)
			{
				int f, t;
				scanf("%d%d", &f, &t);
				--f, --t;
				AddPath(f, t);
				g2.AddPath(t, f);
			}
		}
	}

//protected:
	static const int MAXPATH = 10010;
	static const int MAXNODE = 1024;
	int end_path_slot;
	int path_head[MAXNODE];
	int path_to[MAXPATH];
	int path_next[MAXPATH];
	int nodesize;
};

Graph g1, g2;

int main()
{
	g1.Input(g2);
	int ans(0);
	for (int i = 0; i < g1.nodesize; ++i)
	{
		ans += g1.nodesize + 1 - (CountConnect(g1, i) + CountConnect(g2, i));
	}
	printf("%d\n", ans / 2);
	return 0;
}
