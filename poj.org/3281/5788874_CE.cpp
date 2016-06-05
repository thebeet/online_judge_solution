/*
 * Dining.cpp
 *
 *  Created on: 2009-8-31
 *      Author: thebeet
 */

/*
 * NetworkFlow.cpp
 *
 *  Created on: 2009-8-31
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

class NetWork
{
public:
	NetWork(const int nodesize = 0) :
		m_path(nodesize, vector<int>(nodesize, 0))
	{
	}

	void Resize(const int newsize)
	{
		m_path.clear();
		m_path.resize(newsize, vector<int>(newsize, 0));
	}

	virtual void AddPath(const int p1, const int p2, const int wei = 1)
	{
		m_path[p1][p2] += wei;
	}

	int MaxFlow(const int st, const int ed) const
	{
		int ans(0);
		vector< vector< int > > cf(m_path);
		for ( ; ; )
		{
			int pre[m_path.size()];
			memset(pre, -1, sizeof(pre));
			pre[st] = st;
			queue<int> q;
			q.push(st);
			while (q.empty() == false)
			{
				int now = q.front();
				q.pop();
				for (int i = 0; i < cf[now].size(); ++i)
				{
					if ((pre[i] == -1) && (cf[now][i] > 0))
					{
						pre[i] = now;
						q.push(i);
						if (i == ed) break;
					}
				}
			}
			if (pre[ed] == -1)
			{
				break;
			}
			int mx(1000000000);
			for (int p = ed; p != st; p = pre[p])
			{
				mx = min(mx, cf[pre[p]][p]);
			}
			for (int p = ed; p != st; p = pre[p])
			{
				cf[pre[p]][p] -= mx;
				cf[p][pre[p]] += mx;
			}
			ans += mx;
		}
		return ans;
	}

	void Debug() const
	{
		for (int i = 0; i < m_path.size(); ++i)
		{
			for (int j = 0; j < m_path[i].size(); ++j)
			{
				cout << m_path[i][j] << " ";
			}
			cout << endl;
		}
	}

protected:
	vector< vector< int > > m_path;
};

class SuperSimpleNetWork : public NetWork
{
public:
	static const int SOURCE = 0;
	static const int DEST = 1;

public:
	SuperSimpleNetWork(istream &in)
	{
		in >> m_n >> m_f >> m_d;
		Resize(m_n + m_f + m_d + 2);
		for (int i = 1; i <= m_f; ++i)
		{
			AddPath(SOURCE, FoodNodeID(i));
		}
		for (int i = 1; i <= m_d; ++i)
		{
			AddPath(DrinkNodeID(i), DEST);
		}
		for (int i = 0; i < m_n; ++i)
		{
			int fn, dn;
			in >> fn >> dn;
			for (int j = 0; j < fn; ++j)
			{
				int fid;
				in >> fid;
				AddPath(FoodNodeID(fid), CowNodeID(i));
			}
			for (int j = 0; j < dn; ++j)
			{
				int did;
				in >> did;
				AddPath(CowNodeID(i), DrinkNodeID(did), 2);
			}
		}
	}

private:

	int CowNodeID(const int c) const
	{
		return c + 2;
	}

	int FoodNodeID(const int p) const
	{
		return p + m_n + 1;
	}

	int DrinkNodeID(const int d) const
	{
		return d + m_n + m_f + 1;
	}

	int m_n, m_f, m_d;

};

int main()
{
	SuperSimpleNetWork network(cin);
	cout << network.MaxFlow(network.SOURCE, network.DEST) << endl;
	return 0;
}
