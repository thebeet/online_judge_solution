/*
 * Closest_Common_Ancestors.cpp
 *
 *  Created on: 2011-11-8
 *      Author: acer
 */


#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int m_data;
	vector<int> m_children;
};

typedef Node *pNode;

void expect_char(const char c)
{
	while (getchar() != c);
}

void dfs(const vector<Node>& nodes, int p, int nowdepth,
		vector<int> &depth, vector<int> &result, vector<int> &pos)
{
	pos[p] = depth.size();
	depth.push_back(nowdepth);
	result.push_back(p);

	for (unsigned int i = 0; i < nodes[p].m_children.size(); ++i)
	{
		dfs(nodes, nodes[p].m_children[i], nowdepth + 1, depth, result, pos);
		depth.push_back(nowdepth);
		result.push_back(p);
	}
}

template <typename T = int>
class RMQ
{
public:
	RMQ(const vector<T> &array) :
		orig_array(array)
	{
		m_extend_size = 1;
		for (; m_extend_size < orig_array.size(); m_extend_size <<= 1)
		{
		}
		rmq_extend_array.resize(m_extend_size * 2, -1);
		for (unsigned int i = m_extend_size; i < m_extend_size + array.size(); ++i)
		{
			rmq_extend_array[i] = i - m_extend_size;
		}
		for (unsigned int i = m_extend_size - 1; i > 0; --i)
		{
			rmq_extend_array[i] = minPos((i << 1), (i << 1) + 1);
		}
	}

	int findminPos(const int start, const int end) const
	{
		int posstart(start + m_extend_size);
		int posend(end + m_extend_size);
		if (posstart > posend) swap(posstart, posend);
		int ans(start);
		while (posstart <= posend)
		{
			ans = minPos(ans + m_extend_size, minPos(posstart, posend) + m_extend_size);
			if (posstart == posend) break;
			(posstart += 1) >>= 1;
			(posend -= 1) >>= 1;
		}
		return ans;
	}

private:
	int minPos(const int p1, const int p2) const
	{
		if (rmq_extend_array[p1] == -1) return rmq_extend_array[p2];
		if (rmq_extend_array[p2] == -1) return rmq_extend_array[p1];

		if (orig_array[rmq_extend_array[p1]] < orig_array[rmq_extend_array[p2]]) return rmq_extend_array[p1];
		else return rmq_extend_array[p2];
	}

	unsigned int m_extend_size;
	const vector<T> &orig_array;
	vector<int> rmq_extend_array;
};

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int root(-1);
		vector<Node> nodes(n + 1);
		vector<bool> isroot(n + 1, true);
		for (int i = 0; i < n; ++i)
		{
			int data;
			scanf("%d", &data);
			nodes[data].m_data = data;
			expect_char(':');
			expect_char('(');
			int m;
			scanf("%d", &m);
			expect_char(')');
			for (int j = 0; j < m; ++j)
			{
				int c;
				scanf("%d", &c);
				nodes[data].m_children.push_back(c);
				isroot[c] = false;
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			if (isroot[i])
			{
				root = i;
				break;
			}
		}

		vector<int> depth;
		vector<int> result;
		vector<int> pos(n + 1);
		dfs(nodes, root, 0, depth, result, pos);

		RMQ<int> rmq(depth);
		vector<int> ans(n + 1, 0);
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
		{
			expect_char('(');
			int a, b;
			scanf("%d%d", &a, &b);
			int minpos = rmq.findminPos(pos[a], pos[b]);
			++ans[result[minpos]];
			expect_char(')');
		}
		for (int i = 1; i <= n; ++i)
		{
			if (ans[i] > 0)
			{
				printf("%d:%d\n", i, ans[i]);
			}
		}
	}
	return 0;
}
