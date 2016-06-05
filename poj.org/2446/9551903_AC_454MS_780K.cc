/*
 * Chessboard.cpp
 *
 *  Created on: 2011-11-11
 *      Author: acer
 */

#include <iostream>
#include <cstdio>
#include <cstring>
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

class Chessboard : public BGraph
{
public:
	Chessboard(const int width, const int height) :
		BGraph((width * height + 1) / 2, (width * height) / 2),
		m_width(width), m_height(height)
	{
		for (int x = 0; x < width; ++x)
		{
			for (int y = 0; y < height; ++y)
			{
				if ((x + y) % 2 == 0)
				{
					for (int i = 0; i < 4; ++i)
					{
						int dx = x;
						int dy = y;
						switch (i)
						{
						case 0:
							++dx;
							break;
						case 1:
							--dx;
							break;
						case 2:
							++dy;
							break;
						case 3:
							--dy;
							break;
						}
						if (((dx >= 0) && (dx < width)) && ((dy >= 0) && (dy < height)))
						{
							m_conn[(x * height + y) / 2][(dx * height + dy) / 2] = true;
						}
					}
				}
			}
		}
	}

	void cutHole(const int x, const int y)
	{
		if ((x + y) % 2 == 0)
		{
			for (int i = 0; i < m_m; ++i)
			{
				m_conn[(x * m_height + y) / 2][i] = false;
			}
		}
		else
		{
			for (int i = 0; i < m_n; ++i)
			{
				m_conn[i][(x * m_height + y) / 2] = false;
			}
		}
	}

private:
	int m_width, m_height;
};

int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	Chessboard chessboard(m, n);
	for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y; --x; --y;
		chessboard.cutHole(x, y);
	}
	cout << ((chessboard.Hungry() * 2 + k == m * n) ? "YES" : "NO") << endl;
	return 0;
}
