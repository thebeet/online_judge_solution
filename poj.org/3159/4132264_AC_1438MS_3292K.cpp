/*
 * Graph::main.cpp
 *
 *  Created on: Sep 25, 2008 4:37:41 PM
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

#define START_FROM_ONE_
#define USE_SCANF_

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


template <typename T_PATH, bool IsUnDirect>
class Graph
{
public:
	typedef typename T_PATH::T_Cost T_COST;

	friend std::istream &operator >> (std::istream &in, Graph &g)
	{
		if (in >> g.m_node_size)
		{
			g.m_paths.clear();
			g.m_paths.resize(g.m_node_size, std::vector<T_PATH>(0));
			int totalpath;
#ifdef USE_SCANF_
			scanf("%d", &totalpath);
#else
			in >> totalpath;
#endif /* USE_SCANF_ */
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
				if (IsUnDirect)
				{
					g.m_paths[t].push_back(T_PATH(f, c));
				}
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
		bool *gone = new bool[m_node_size];
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
				delete [] gone;
				return now.m_cost;
			}
			for (typename std::vector<T_PATH>::iterator it = m_paths[now.m_to_id].begin(); it != m_paths[now.m_to_id].end(); ++it)
			{
				if (gone[it->m_to_id] == false)
				{
					heap.push(T_PATH(it->m_to_id, it->m_cost + now.m_cost));
				}
			}
		}
		delete [] gone;
		return (T_COST)(-1);
	}

	int Size(void) const
	{
		return m_node_size;
	}
private:
	int m_node_size;
	std::vector< std::vector<T_PATH> > m_paths;
};

int main()
{
	Graph<Path<int>, false> g;
	std::cin >> g;
	std::cout << g.Dijkstra(0, g.Size() - 1) << std::endl;
	return 0;
}
