/*
 * URAL_70_C::Shortest_Subchain.cpp
 *
 *  Created on: Nov 1, 2008 8:32:41 PM
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
#include <queue>

using namespace std;

int arr[100010];
class Graph_Adjacency_Table
{
public:
	Graph_Adjacency_Table(const int n = 0) :
		node_size(n)
	{
		node_info = new int[MAXN];
		path_h = new int[MAXN];
		path_to = new int[MAXPATH];
		path_weight = new int[MAXPATH];
		path_next = new int[MAXPATH];
		Clear();
	}
	~Graph_Adjacency_Table(void)
	{
		delete [] node_info;
		delete [] path_h;
		delete [] path_to;
		delete [] path_weight;
		delete [] path_next;
	}

	void Clear(void)
	{
		memset(node_info, -1, sizeof(int) * MAXN);
		memset(path_h, -1, sizeof(int) * MAXN);
		memset(path_next, -1, sizeof(int) * MAXPATH);
		path_end = 0;
	}

	int Size(void) const
	{
		return node_size;
	}

	Graph_Adjacency_Table &Connect(const int st, const int ed, const int wei)
	{
		path_to[path_end] = ed;
		path_weight[path_end] = wei;
		path_next[path_end] = path_h[st];
		path_h[st] = path_end;
		++path_end;
		return *this;
	}

	void BFS(const int st)
	{
		node_info[st] = 0;
		queue<int> q;
		q.push(st);
		while (q.empty() == false)
		{
			int m = path_h[q.front()];
			while (m >= 0)
			{
				if (node_info[path_to[m]] < 0)
				{
					node_info[path_to[m]] = node_info[q.front()] + 1;
					q.push(path_to[m]);
				}
				m = path_next[m];
			}
			q.pop();
		}
	}

//private:
	static const int MAXN = 10010;
	static const int MAXPATH = 100010;
	int node_size;
	int *node_info;
	int *path_h;
	int *path_to;
	int *path_weight;
	int *path_next;
	int path_end;
};


int main()
{
	int n;
	scanf("%d", &n);
	scanf("%d", &arr[1]);
	Graph_Adjacency_Table g;
	Graph_Adjacency_Table g_pre;
	for (int i = 2; i <= n; ++i)
	{
		scanf("%d", &arr[i]);
		g.Connect(arr[i - 1], arr[i], 1);
		g_pre.Connect(arr[i], arr[i - 1], 1);
	}
	g_pre.BFS(arr[n]);
	int pp(arr[1]);
	cout << pp << " ";
	while (pp != arr[n])
	{
		int m = g.path_h[pp];
		while (m >= 0)
		{
			if (g_pre.node_info[g.path_to[m]] + 1 == g_pre.node_info[pp])
			{
				pp = g.path_to[m];
				cout << pp << " ";
				break;
			}
			m = g.path_next[m];
		}
	}
	return 0;
}


