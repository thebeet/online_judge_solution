/*
 * graph.cpp
 *
 *  Created on: 2009-9-4
 *      Author: Administrator
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 0x3fffffff;

class GraphWeight
{
private:
	class PriQueueElem
	{
	public:
		PriQueueElem(const int id, const int initwei) :
			to_id(id), wei(initwei)
		{
		}
		int to_id;
		int wei;
		bool operator < (const PriQueueElem &dqt) const
		{
			return wei < dqt.wei;
		}
		bool operator > (const PriQueueElem &dqt) const
		{
			return wei > dqt.wei;
		}
	};

	friend int Dijkstra(const GraphWeight &g, const int st, const int ed)
	{
	    std::priority_queue<PriQueueElem, std::vector<PriQueueElem>, std::greater<PriQueueElem> > heap;
	    bool *gone = new bool[g.Size()];
	    memset(gone, false, sizeof(bool) * g.Size());
	    heap.push(PriQueueElem(st, 0));
	    while (heap.empty() == false)
	    {
	    	PriQueueElem now(heap.top());
	        heap.pop();
	        if (gone[now.to_id])
	        {
	            continue;
	        }
	        gone[now.to_id] = true;
	        if (now.to_id == ed)
	        {
	            delete [] gone;
	            return now.wei;
	        }
	        for (int pp = g.path_head[now.to_id]; pp != -1; pp = g.path_next[pp])
	        {
	            if (gone[g.path_to[pp]] == false)
	            {
	                heap.push(PriQueueElem(g.path_to[pp], g.path_weight[pp] + now.wei));
	            }
	        }
	    }
	    delete [] gone;
	    return -1;
	}

	friend int SPFA(const GraphWeight &g, const int st, const int ed)
	{
		queue<int> q;
	    bool *inqueue = new bool[g.Size()];
	    memset(inqueue, false, sizeof(bool) * g.Size());
	    int *dist = new int[g.Size()];
	    fill(dist, dist + g.Size(), INF);
	    q.push(st);
	    inqueue[st] = true;
	    dist[st] = 0;

	    while (q.empty() == false)
	    {
	    	int now = q.front();
	    	q.pop();
	    	inqueue[now] = false;
	    	for (int pp = g.path_head[now]; pp != -1; pp = g.path_next[pp])
	    	{
	    		if (dist[g.path_to[pp]] > dist[now] + g.path_weight[pp])
	    		{
	    			dist[g.path_to[pp]] = dist[now] + g.path_weight[pp];
	    			if (inqueue[g.path_to[pp]] == false)
	    			{
	    				q.push(g.path_to[pp]);
	    				inqueue[g.path_to[pp]] = true;
	    			}
	    		}
	    	}
	    }
	    delete [] inqueue;
	    delete [] dist;
	    int ret = dist[ed];
	    return ret;
	}

public:
	GraphWeight(const int n = 0) :
		nodesize(n)
	{
		ClearPath();
	}
	virtual ~GraphWeight(void)
	{
	}

	void AddPath(const int f, const int t, const int weight)
	{
		path_to[end_path_slot] = t;
		path_weight[end_path_slot] = weight;
		path_next[end_path_slot] = path_head[f];
		path_head[f] = end_path_slot;
		++end_path_slot;
	}

	void ClearPath()
	{
		memset(path_head, -1, sizeof(path_head));
		memset(path_next, -1, sizeof(path_next));
		end_path_slot = 0;
	}

	int Size() const
	{
		return nodesize;
	}

	void Input() // use scanf
	{
		if (scanf("%d%d", &nodesize, &pathsize) != EOF)
		{
			for (int i = 0; i < pathsize; ++i)
			{
				int f, t, wei;
				scanf("%d%d%d", &f, &t, &wei);
				--f, --t;
				AddPath(f, t, wei);
				AddPath(t, f, wei);
			}
		}
	}

protected:
	static const int MAXPATH = 65536;
	static const int MAXNODE = 128;
	int end_path_slot;
	int path_head[MAXNODE];
	int path_to[MAXPATH];
	int path_weight[MAXPATH];
	int path_next[MAXPATH];
	int nodesize;
	int pathsize;
};

class GraphWeightCost : public GraphWeight
{
	friend int SPFACost(const GraphWeightCost &g, const int st, const int ed, int pre[], int prepp[])
	{
		queue<int> q;
	    bool *inqueue = new bool[g.Size()];
	    memset(inqueue, false, sizeof(bool) * g.Size());
	    int *dist = new int[g.Size()];
	    fill(dist, dist + g.Size(), INF);
	    q.push(st);
	    inqueue[st] = true;
	    dist[st] = 0;

	    while (q.empty() == false)
	    {
	    	int now = q.front();
	    	q.pop();
	    	inqueue[now] = false;
	    	for (int pp = g.path_head[now]; pp != -1; pp = g.path_next[pp])
	    	{
				//printf("from %d(%d) to %d(%d) : %d %d\n", now, dist[now], g.path_to[pp], dist[g.path_to[pp]], g.path_weight[pp], g.path_cost[pp]);
	    		if ((g.path_weight[pp] > 0) && (dist[g.path_to[pp]] > dist[now] + g.path_cost[pp]))
	    		{
	    			dist[g.path_to[pp]] = dist[now] + g.path_cost[pp];
	    			pre[g.path_to[pp]] = now;
	    			prepp[g.path_to[pp]] = pp;
	    			if (inqueue[g.path_to[pp]] == false)
	    			{
	    				//printf("%d %d\n", g.path_to[pp], dist[g.path_to[pp]]);
	    				q.push(g.path_to[pp]);
	    				inqueue[g.path_to[pp]] = true;
	    			}
	    		}
	    	}
	    }
	    delete [] inqueue;
	    delete [] dist;
	    int ret = dist[ed];
	    return ret;
	}

	friend std::pair<int, int> MinCost(GraphWeightCost &g, const int st, const int ed)
	{
		int mincost(0);
		int maxflow(0);
		int *pre = new int[g.Size()];
		int *prepp = new int[g.Size()];
		int *path = new int[g.Size()];
		int totalcost;
		while ((totalcost = SPFACost(g, st, ed, pre, prepp)) < INF)
		{
			int neck(INF);
			int h(0);
			for (int i = ed; i != st; i = pre[i])
			{
				neck = min(neck, g.path_weight[prepp[i]]);
				path[h++] = prepp[i];
			}
			for (int i = 0; i < h; ++i)
			{
				g.path_weight[path[i]] -= neck;
				g.path_weight[path[i] ^ 1] += neck;
			}
			mincost += neck * totalcost;
			maxflow += neck;
		}
	    delete [] pre;
	    delete [] prepp;
	    delete [] path;
		return make_pair(maxflow, mincost);
	}

public:
	GraphWeightCost(const int n = 0) :
		GraphWeight(n)
	{

	}

	void AddPath(const int f, const int t, const int weight, const int cost)
	{
		path_cost[end_path_slot] = cost;
		GraphWeight::AddPath(f, t, weight);
		path_cost[end_path_slot] = -cost;
		GraphWeight::AddPath(t, f, 0);
	}

protected:
	int path_cost[MAXPATH];
};

int main()
{
	int n, m;
	int ti(0);
	while ((scanf("%d%d", &n, &m), n > 0))
	{
		GraphWeightCost g(n * 2);
		for (int i = 0; i < n; ++i)
		{
			g.AddPath(i * 2, i * 2 + 1, (((i == 0) || (i == n - 1)) ? 2 : 1), 0);
		}
		for (int i = 0; i < m; ++i)
		{
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			g.AddPath(a * 2 + 1, b * 2, 1, w);
		}
		pair<int, int> ans = MinCost(g, 0, g.Size() - 1);
		printf("Instance #%d: ", ++ti);
		if (ans.first != 2)
		{
			printf("Not possible\n");
		}
		else
		{
			printf("%d\n", ans.second);
		}
	}

	return 0;
}
