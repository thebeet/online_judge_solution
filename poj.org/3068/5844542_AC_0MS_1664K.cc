/*

 * graph.cpp

 *

 *  Created on: 2009-9-4

 *      Author: Administrator

 */



#include <iostream>

#include <iomanip>

#include <vector>

#include <stack>

#include <queue>

#include <algorithm>

#include <cstdio>

#include <cstring>



using namespace std;



const int INF = 0x3fffffff;



class Graph

{

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



	void Input() // use scanf

	{

		int pathsize;

		if (scanf("%d%d", &nodesize, &pathsize) != EOF)

		{

			for (int i = 0; i < pathsize; ++i)

			{

				int f, t;

				scanf("%d%d", &f, &t);

				--f, --t;

				AddPath(f, t);

			}

		}

	}



	int CountConnect(const int st) const

	{

		bool gone[nodesize];

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

			for (int pp = path_head[now]; pp != -1; pp = path_next[pp])

			{

				if (gone[path_to[pp]] == false)

				{

					gone[path_to[pp]] = true;

					stac.push(path_to[pp]);

				}

			}

		}

		return sum;

	}



protected:

	static const int MAXPATH = 65536;

	static const int MAXNODE = 128;

	int end_path_slot;

	int path_head[MAXNODE];

	int path_to[MAXPATH];

	int path_next[MAXPATH];

	int nodesize;

};



class GraphWeight : public Graph

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

public:

	GraphWeight(const int n = 0) :

		Graph(n)

	{

	}



	virtual ~GraphWeight(void)

	{

	}



	void AddPath(const int f, const int t, const int weight)

	{

		path_weight[end_path_slot] = weight;

		Graph::AddPath(f, t);

	}



	void Input() // use scanf

	{

		int pathsize;

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



	int Dijkstra(const int st, const int ed) const

	{

	    std::priority_queue<PriQueueElem, std::vector<PriQueueElem>, std::greater<PriQueueElem> > heap;

	    bool gone[Size()];

	    memset(gone, false, sizeof(bool) * Size());

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

	            return now.wei;

	        }

	        for (int pp = path_head[now.to_id]; pp != -1; pp = path_next[pp])

	        {

	            if (gone[path_to[pp]] == false)

	            {

	                heap.push(PriQueueElem(path_to[pp], path_weight[pp] + now.wei));

	            }

	        }

	    }

	    return -1;

	}



	int SPFA(const int st, const int ed) const

	{

		queue<int> q;

	    bool inqueue[Size()];

	    memset(inqueue, false, sizeof(bool) * Size());

	    int dist[Size()];

	    fill(dist, dist + Size(), INF);

	    q.push(st);

	    inqueue[st] = true;

	    dist[st] = 0;



	    while (q.empty() == false)

	    {

	    	int now = q.front();

	    	q.pop();

	    	inqueue[now] = false;

	    	for (int pp = path_head[now]; pp != -1; pp = path_next[pp])

	    	{

	    		if (dist[path_to[pp]] > dist[now] + path_weight[pp])

	    		{

	    			dist[path_to[pp]] = dist[now] + path_weight[pp];

	    			if (inqueue[path_to[pp]] == false)

	    			{

	    				q.push(path_to[pp]);

	    				inqueue[path_to[pp]] = true;

	    			}

	    		}

	    	}

	    }

	    int ret = dist[ed];

	    return ret;

	}



protected:

	int path_weight[MAXPATH];

};



class GraphWeightCost : public GraphWeight

{

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



	std::pair<int, int> MinCost(const int st, const int ed)

	{

		int mincost(0);

		int maxflow(0);

		int pre[Size()];

		int prepp[Size()];

		int path[Size()];

		int totalcost;

		while ((totalcost = SPFACost(st, ed, pre, prepp)) < INF)

		{

			int neck(INF);

			int h(0);

			for (int i = ed; i != st; i = pre[i])

			{

				neck = min(neck, path_weight[prepp[i]]);

				path[h++] = prepp[i];

			}

			for (int i = 0; i < h; ++i)

			{

				path_weight[path[i]] -= neck;

				path_weight[path[i] ^ 1] += neck;

			}

			mincost += neck * totalcost;

			maxflow += neck;

		}

		return make_pair(maxflow, mincost);

	}





protected:

	int path_cost[MAXPATH];



private:

	int SPFACost(const int st, const int ed, int pre[], int prepp[]) const

	{

		queue<int> q;

	    bool inqueue[Size()];

	    memset(inqueue, false, sizeof(inqueue));

	    int dist[Size()];

	    fill(dist, dist + Size(), INF);

	    q.push(st);

	    inqueue[st] = true;

	    dist[st] = 0;



	    while (q.empty() == false)

	    {

	    	int now = q.front();

	    	q.pop();

	    	inqueue[now] = false;

	    	for (int pp = path_head[now]; pp != -1; pp = path_next[pp])

	    	{

	    		if ((path_weight[pp] > 0) && (dist[path_to[pp]] > dist[now] + path_cost[pp]))

	    		{

	    			dist[path_to[pp]] = dist[now] + path_cost[pp];

	    			pre[path_to[pp]] = now;

	    			prepp[path_to[pp]] = pp;

	    			if (inqueue[path_to[pp]] == false)

	    			{

	    				q.push(path_to[pp]);

	    				inqueue[path_to[pp]] = true;

	    			}

	    		}

	    	}

	    }

	    return dist[ed];

	}

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

			//a = rand() % n; b = rand() % n; w = (rand() % 100) + 10;

			g.AddPath(a * 2 + 1, b * 2, 1, w);

		}

		pair<int, int> ans = g.MinCost(0, g.Size() - 1);

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

