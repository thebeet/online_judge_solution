/*
 * SegTree.cpp
 *
 *  Created on: Sep 16, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

class SegTree
{
private:
	class SegTreeNode
	{
	public:
		SegTreeNode(const int s, const int e) :
			m_val(0), m_total(1), m_s(s), m_e(e), m_left(NULL), m_right(NULL)
		{
			if (s != e)
			{
				int mid((s + e) >> 1);
				m_left = new SegTreeNode(s, mid);
				m_right = new SegTreeNode(mid + 1, e);
			}
		}

		~SegTreeNode()
		{
			if (m_left) delete m_left;
			if (m_right) delete m_right;
		}

		void Color(const int s, const int e, const int p)
		{
			if (s > e) return;
			if (m_val == p) return;
			if ((s == m_s) && (e == m_e))
			{
				m_val = p;
				m_total = (1 << p);
				return;
			}
			int mid((m_s + m_e) >> 1);
			if (s <= mid)
			{
				if (e < mid)
				{
					m_left->Color(s, e, p);
					if (m_val != MIXEDCOLOR)
					{
						m_left->Color(m_s, s - 1, m_val);
						m_left->Color(e + 1, mid, m_val);
						m_right->Color(mid + 1, m_e, m_val);
					}
				}
				else
				{
					m_left->Color(s, mid, p);
					m_right->Color(mid + 1, e, p);
					if (m_val != MIXEDCOLOR)
					{
						m_left->Color(m_s, s - 1, m_val);
						m_right->Color(e + 1, m_e, m_val);
					}
				}
			}
			if (s > mid)
			{
				m_right->Color(s, e, p);
				if (m_val != MIXEDCOLOR)
				{
					m_left->Color(m_s, mid, m_val);
					m_right->Color(mid + 1, s - 1, m_val);
					m_right->Color(e + 1, m_e, m_val);
				}
			}
			if (m_left->m_val == m_right->m_val)
			{
				m_val = m_left->m_val;
			}
			else
			{
				m_val = MIXEDCOLOR;
			}
			m_total = m_left->m_total | m_right->m_total;
		}

		int TotalColor(const int s, const int e) const
		{
			if (s > e) return 0;
			if (((s == m_s) && (e == m_e)) || (m_val != MIXEDCOLOR))
			{
				return m_total;
			}
			int mid((m_s + m_e) >> 1);
			if (s <= mid)
			{
				if (e < mid)
				{
					return m_left->TotalColor(s, e);
				}
				else
				{
					return (m_left->TotalColor(s, mid) | m_right->TotalColor(mid + 1, e));
				}
			}
			if (s > mid)
			{
				return m_right->TotalColor(s, e);
			}
			printf("err\n");
		}

		int m_val;
		int m_total;
		int m_s, m_e;
		SegTreeNode *m_left, *m_right;
		static const int MIXEDCOLOR = -1;
	};

public:
	SegTree(const int size)
	{
		m_root = new SegTreeNode(1, size);
	}

	~SegTree()
	{
		delete m_root;
	}

	void Color(const int s, const int e, const int p)
	{
		m_root->Color(s, e, p);
	}

	int TotalColor(const int s, const int e) const
	{
		int totalcolor = m_root->TotalColor(s, e);
		int sum(0);
		while (totalcolor > 0)
		{
			if (totalcolor & 1)
			{
				++sum;
			}
			totalcolor >>= 1;
		}
		return sum;
	}

	SegTreeNode *m_root;
};

int main()
{
	int l, t, o;
	scanf("%d%d%d", &l, &t, &o);
	char inp[4];
	SegTree segtree(l);
	segtree.Color(1, l, 0);
	for (int i = 0; i < o; ++i)
	{
		int a, b, c;
		scanf("%s", inp);
		if (inp[0] == 'C')
		{
			scanf("%d%d%d", &a, &b, &c);
			if (a <= b)
			{
				--c;
				segtree.Color(a, b, c);
			}
		}
		else
		{
			scanf("%d%d", &a, &b);
			if (a > b)
			{
				printf("1\n");
			}
			else
			{
				printf("%d\n", segtree.TotalColor(a, b));
			}
		}
	}
	return 0;
}
