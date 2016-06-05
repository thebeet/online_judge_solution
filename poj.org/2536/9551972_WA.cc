/*
 * Gopher_II.cpp
 *
 *  Created on: 2011-11-11
 *      Author: acer
 */


#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

class BGraph
{
public:
	BGraph(const int n = 0, const int m = 0) :
		m_conn(n, std::vector<bool>(m, false)),
		m_n(n), m_m(m)
	{
	}

	void AddPath(const int x, const int y)
	{
		m_conn[x][y] = true;
	}

	int Hungry() const
	{
		int sum(0);
		int matchx[m_n];
		int matchy[m_m];
		bool gone[m_m];
		memset(matchx, -1, sizeof(matchx));
		memset(matchy, -1, sizeof(matchy));
		for (int i = 0; i < m_n; ++i)
		{
			if (matchx[i] == -1)
			{
				memset(gone, false, sizeof(gone));
				if (Hungry_Dfs(i, matchx, matchy, gone))
				{
					++sum;
				}
			}
		}
		return sum;
	}

protected:
	bool Hungry_Dfs(const int p, int matchx[], int matchy[], bool gone[]) const
	{
		for (int i = 0; i < m_m; ++i)
		{
			if (m_conn[p][i] && (gone[i] == false))
			{
				gone[i] = true;
				if ((matchy[i] == -1) || Hungry_Dfs(matchy[i], matchx, matchy, gone))
				{
					matchx[p] = i;
					matchy[i] = p;
					return true;
				}
			}
		}
		return false;
	}

	std::vector<std::vector<bool> > m_conn;
	int m_n, m_m;
};

struct Point
{
	double x, y;
};

double dist(const Point &p1, const Point &p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

class GophertoHole : public BGraph
{
public:
	GophertoHole(const int n, const int m) :
		BGraph(n, m), m_gopher(n), m_hole(m)
	{

	}

	void makeConnect(const double maxdist)
	{
		for (int i = 0; i < m_gopher.size(); ++i)
		{
			for (int j = 0; j < m_hole.size(); ++j)
			{
				if (dist(m_gopher[i], m_hole[j]) <= maxdist + 0.000001)
				{
					AddPath(i, j);
				}
			}
		}
	}

	vector<Point> m_gopher;
	vector<Point> m_hole;
};

int main()
{
	int n, m, s, v;
	cin >> n >> m >> s >> v;
	GophertoHole gh(n, m);
	for (int i = 0; i < n; ++i)
	{
		cin >> gh.m_gopher[i].x >> gh.m_gopher[i].y;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> gh.m_hole[i].x >> gh.m_hole[i].y;
	}
	gh.makeConnect(s * v);

	cout << n - gh.Hungry() << endl;
	return 0;
}
