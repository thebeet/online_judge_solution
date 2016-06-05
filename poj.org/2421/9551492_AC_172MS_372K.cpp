/*
 * Constructing_Roads.cpp
 *
 *  Created on: 2011-11-11
 *      Author: acer
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class DisjointSet
{
public:
	DisjointSet(const int n) :
		m_root(n)
	{
		for (int i = 0; i < n; ++i)
		{
			m_root[i] = i;
		}
	}

	void Connect(const int p1, const int p2)
	{
		m_root[findRoot(p1)] = findRoot(p2);
	}

	bool isConnect(const int p1, const int p2) const
	{
		return (findRoot(p1) == findRoot(p2));
	}

private:

	int findRoot(const int p) const
	{
		if (m_root[p] == p) return p;
		return (m_root[p] = findRoot(m_root[p]));
	}

	mutable std::vector<int> m_root;
};

int main()
{
	int n;
	cin >> n;
	vector<pair<int, pair<int, int> > > dist(n * n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int d;
			cin >> d;
			dist[i * n + j] = make_pair(d, make_pair(i, j));
		}
	}

	DisjointSet ds(n);
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		ds.Connect(a, b);
	}

	sort(dist.begin(), dist.end());

	int ans(0);
	for (int i = 0; i < dist.size(); ++i)
	{
		int a = dist[i].second.first;
		int b = dist[i].second.second;
		if (ds.isConnect(a, b) == false)
		{
			ds.Connect(a, b);
			ans += dist[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}

