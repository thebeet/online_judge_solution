/*
 * A_Walk_Through_the_Forest.cpp
 *
 *  Created on: 2009-8-30
 *      Author: Administrator
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <queue>

//#define NODE_INFO_
#define START_FROM_ONE_
#define UNDIRECTED_GRAPH_
//#define PATH_FROM_
#define PATH_WEIGHT_

struct __DQ_Type
{
	__DQ_Type(const int id, const int initwei) :
		to_id(id), wei(initwei)
	{
	}
	int to_id;
	int wei;
	bool operator < (const __DQ_Type &dqt) const
	{
		return wei < dqt.wei;
	}
	bool operator > (const __DQ_Type &dqt) const
	{
		return wei > dqt.wei;
	}
};

class Graph
{
	friend int Dijkstra(Graph &g, const int st, const int ed)
	{
	    std::priority_queue<__DQ_Type, std::vector<__DQ_Type>, std::greater<__DQ_Type> > heap;
	    bool *gone = new bool[g.nodesize];
	    memset(gone, false, sizeof(bool) * g.nodesize);
	    memset(g.shortway, -1, sizeof(g.shortway));
	    heap.push(__DQ_Type(st, 0));
	    while (heap.empty() == false)
	    {
	    	__DQ_Type now(heap.top());
	        heap.pop();
	        if (gone[now.to_id])
	        {
	            continue;
	        }
	        gone[now.to_id] = true;
	        g.shortway[now.to_id] = now.wei;
	        if (now.to_id == ed)
	        {
	            delete [] gone;
	            return now.wei;
	        }
	        for (int pp = g.path_head[now.to_id]; pp != -1; pp = g.path_next[pp])
	        {
	            if (gone[g.path_to[pp]] == false)
	            {
	                heap.push(__DQ_Type(g.path_to[pp], g.path_weight[pp] + now.wei));
	            }
	        }
	    }
	    delete [] gone;
	    return -1;
	}

	friend int solve(Graph &g, const int st, const int ed)
	{
	    std::priority_queue<__DQ_Type, std::vector<__DQ_Type>, std::less<__DQ_Type> > heap;
	    bool *gone = new bool[g.nodesize];
	    memset(gone, false, sizeof(bool) * g.nodesize);
	    memset(g.ans, 0, sizeof(g.ans));
	    heap.push(__DQ_Type(st, g.shortway[st]));
	    g.ans[st] = 1;
	    while (heap.empty() == false)
	    {
	    	__DQ_Type now(heap.top());
	        heap.pop();
	        if (gone[now.to_id])
	        {
	            continue;
	        }
	        gone[now.to_id] = true;
	        if (now.to_id == ed)
	        {
	            delete [] gone;
	            return g.ans[ed];
	        }
	        for (int pp = g.path_head[now.to_id]; pp != -1; pp = g.path_next[pp])
	        {
	            if ((gone[g.path_to[pp]] == false) && (g.shortway[g.path_to[pp]] < g.shortway[now.to_id]) && (g.shortway[g.path_to[pp]] >= 0))
	            {
	                heap.push(__DQ_Type(g.path_to[pp], g.shortway[g.path_to[pp]]));
	                g.ans[g.path_to[pp]] += g.ans[now.to_id];
	            }
	        }
	    }
	    delete [] gone;
	    return -1;
	}

public:
	Graph(const int n = 0) :
		nodesize(n)
	{
		ClearPath();
	}
	~Graph(void)
	{
	}

	void ClearPath(void)
	{
		memset(path_head, -1, sizeof(path_head));
		memset(path_next, -1, sizeof(path_next));
		end_path_slot = 0;
	}

	int Size(void) const
	{
		return nodesize;
	}

	bool Input(void) // use scanf
	{
		if (scanf("%d%d", &nodesize, &pathsize) != EOF)
		{
#ifdef NODE_INFO_
			for (int i = 0; i < nodesize; ++i)
			{
				scanf("%d", &node_info[i]);
			}
#endif /* NODE_INFO_ */
			for (int i = 0; i < pathsize; ++i)
			{
				int f, t, wei;
				scanf("%d%d%d", &f, &t, &wei);
#ifdef START_FROM_ONE_
				--f; --t;
#endif /* START_FROM_ONE_ */
#ifdef PATH_FROM_
				path_from[end_path_slot] = f;
#endif /* PATH_FROM_ */
				path_to[end_path_slot] = t;
#ifdef PATH_WEIGHT_
				path_weight[end_path_slot] = wei;
#endif /* PATH_WEIGHT_ */
				path_next[end_path_slot] = path_head[f];
				path_head[f] = end_path_slot;
				++end_path_slot;
#ifdef UNDIRECTED_GRAPH_
#ifdef PATH_FROM_
				path_from[end_path_slot] = t;
#endif /* PATH_FROM_ */
				path_to[end_path_slot] = f;
#ifdef PATH_WEIGHT_
				path_weight[end_path_slot] = wei;
#endif /* PATH_WEIGHT_ */
				path_next[end_path_slot] = path_head[t];
				path_head[t] = end_path_slot;
				++end_path_slot;
#endif /* UNDIRECTED_GRAPH_ */
			}
			return true;
		}
		return false;
	}

private:
	static const int MAXPATH = 400010;
	static const int MAXNODE = 100010;
#ifdef NODE_INFO_
	int node_info[MAXNODE];
#endif /* NODE_INFO_ */
	int end_path_slot;
	int path_head[MAXNODE];
#ifdef PATH_FROM_
	int path_from[MAXPATH];
#endif /* PATH_FROM_ */
	int path_to[MAXPATH];
#ifdef PATH_WEIGHT_
	int path_weight[MAXPATH];
#endif /* PATH_WEIGHT_ */
	int path_next[MAXPATH];
	int shortway[MAXNODE];
	int ans[MAXNODE];
	int nodesize;
	int pathsize;
};

#endif /*GRAPH_H_*/

using namespace std;

Graph g;

int main()
{
	while (g.ClearPath(), (g.Input()))
	{
		Dijkstra(g, 1, 0);
		cout << solve(g, 0, 1) << endl;
	}
	return 0;
}
