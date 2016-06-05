/*
 * PKU1158::TRAFFIC_LIGHTS.cpp
 *
 *  Created on: Aug 27, 2009 1:24:08 PM
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
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define USE_SCANF_
#define START_FROM_ONE_

const int Color_B = 0;
const int Color_P = 1;

template <typename T_COST>
class Path
{
public:
	Path(const int id = 0, const T_COST c = 0) :
		m_to_id(id), m_cost(c)
	{
	}
	~Path()
	{
	}

	typedef T_COST T_Cost;

	int m_to_id;
	T_COST m_cost;
	bool operator < (const Path &p) const
	{
		return m_cost < p.m_cost;
	}
	bool operator > (const Path &p) const
	{
		return m_cost > p.m_cost;
	}

private:

};

class Node
{
	friend std::istream &operator >> (std::istream &in, Node &n)
	{
		char buf[4];
		scanf("%s%d%d%d", buf, &n.ric, &n.ti[Color_B], &n.ti[Color_P]);
		n.c = ((buf[0] == 'B') ? Color_B : Color_P);
		return in;
	}
public:
	Node()
	{
	}
	~Node()
	{
	}

	int c;
	int ric;
	int ti[2];
};

template <typename T_PATH>
class Graph
{
public:
	typedef typename T_PATH::T_Cost T_COST;

	friend std::istream &operator >> (std::istream &in, Graph &g)
	{
		if (in >> g.m_node_size)
		{
			int totalpath;
#ifdef USE_SCANF_
			scanf("%d", &totalpath);
#else
			in >> totalpath;
#endif /* USE_SCANF_ */
			g.m_nodes.clear();
			g.m_nodes.resize(g.m_node_size);
			for (int i = 0; i < g.m_node_size; ++i)
			{
				cin >> g.m_nodes[i];
			}
			g.m_paths.clear();
			g.m_paths.resize(g.m_node_size, std::vector<T_PATH>(0));
			for (int i = 0; i < totalpath; ++i)
			{
				int f, t;
				T_COST c;
#ifdef USE_SCANF_
				scanf("%d%d%d", &f, &t, &c);
#else
				in >> f >> t >> c;
#endif /* USE_SCANF_ */
#ifdef START_FROM_ONE_
				--f;
				--t;
#endif /* START_FROM_ONE */
				g.m_paths[f].push_back(T_PATH(t, c));
				g.m_paths[t].push_back(T_PATH(f, c));
			}
		}
		return in;
	}
public:
	Graph(void)
	{
	}
	~Graph(void)
	{
	}

	T_COST Dijkstra(const int st, const int ed)
	{
		std::priority_queue<T_PATH, std::vector<T_PATH>, std::greater<typename std::vector<T_PATH>::value_type> > heap;
		bool gone[m_node_size];
		memset(gone, false, m_node_size);
		heap.push(T_PATH(st, (T_COST)0));
		while (heap.empty() == false)
		{
			T_PATH now = heap.top();
			heap.pop();
			if (gone[now.m_to_id])
			{
				continue;
			}
			gone[now.m_to_id] = true;
			if (now.m_to_id == ed)
			{
				return now.m_cost;
			}
			for (typename std::vector<T_PATH>::iterator it = m_paths[now.m_to_id].begin(); it != m_paths[now.m_to_id].end(); ++it)
			{
				if (gone[it->m_to_id] == false)
				{
					int t = CommonColor(now.m_to_id, it->m_to_id, now.m_cost);
					if (t >= 0)
					{
						heap.push(T_PATH(it->m_to_id, it->m_cost + now.m_cost + t));
					}
				}
			}
		}
		return (T_COST)(0);
	}

	int Size(void) const
	{
		return m_node_size;
	}
private:

	int GetColor(const int nodeid, const int nowtime, int &nextchangetime)
	{
		if (nowtime < m_nodes[nodeid].ric)
		{
			nextchangetime = m_nodes[nodeid].ric - nowtime;
			return m_nodes[nodeid].c;
		}
		else
		{
			int t = (nowtime - m_nodes[nodeid].ric) % (m_nodes[nodeid].ti[Color_B] + m_nodes[nodeid].ti[Color_P]);
			if (t >= m_nodes[nodeid].ti[m_nodes[nodeid].c ^ 1])
			{
				nextchangetime = m_nodes[nodeid].ti[Color_B] + m_nodes[nodeid].ti[Color_P] - t;
				return m_nodes[nodeid].c;
			}
			else
			{
				nextchangetime = m_nodes[nodeid].ti[m_nodes[nodeid].c ^ 1] - t;
				return m_nodes[nodeid].c ^ 1;
			}
		}
	}

	int CommonColor(const int fid, const int tid, const int nowtime)
	{
		int cf, ct;
		int nf, nt;
		cf = GetColor(fid, nowtime, nf);
		ct = GetColor(tid, nowtime, nt);
		if (cf == ct)
		{
			return 0;
		}
		else if (nf != nt)
		{
			return min(nf, nt);
		}
		else if (m_nodes[fid].ti[cf ^ 1] != m_nodes[tid].ti[ct ^ 1])
		{
			return min(m_nodes[fid].ti[cf ^ 1], m_nodes[tid].ti[ct ^ 1]) + nf;
		}
		else if (m_nodes[fid].ti[cf] != m_nodes[tid].ti[ct])
		{
			return min(m_nodes[fid].ti[cf], m_nodes[tid].ti[ct]) + m_nodes[fid].ti[cf ^ 1] + nf;
		}
		return -1;
	}

	int m_node_size;
	std::vector< Node > m_nodes;
	std::vector< std::vector<T_PATH> > m_paths;
};

int main()
{
	int f, t;
	cin >> f >> t;
	--f; --t;
	Graph< Path<int> > g;
	cin >> g;
	cout << g.Dijkstra(f, t) << endl;
	return 0;
}
