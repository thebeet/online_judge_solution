/*

 * km.cpp

 *

 *  Created on: 2009-9-3

 *      Author: Administrator

 */



#include <iostream>

#include <algorithm>

#include <vector>

#include <cstring>

#include <cstdio>



using namespace std;



const int MAXN = 64;

const int INF = 0x7fffffff;



class BGraph

{

public:

	BGraph(const int n = 0, const int m = 0) :

		m_n(n), m_m(m)

	{

		Clear();

	}



	bool Input()

	{

		if (scanf("%d", &m_n) != EOF)

		{

			Clear();

			m_m = 7 * 12;

			for (int i = 0; i < m_n; ++i)

			{

				int m;

				scanf("%d", &m);

				for (int j = 0; j < m; ++j)

				{

					int p, q;

					scanf("%d%d", &p, &q);

					AddPath(i, (p - 1) * 12 + q - 1);

				}

			}

			return true;

		}

		return false;

	}



	void AddPath(const int x, const int y)

	{

		m_conn[x][y] = true;

	}



	void Clear()

	{

		memset(m_conn, false, sizeof(m_conn));

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



private:

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





	bool m_conn[512][128];



	int m_n;

	int m_m;

};



class BGraph_Weight

{

public:

	BGraph_Weight(const int n, const int m) :

		m_n(n), m_m(m)

	{

	}



	void AddPath(const int x, const int y, const int w)

	{

		m_weight[x][y] = w;

	}



	int KM()

	{

		neg();

		int lx[MAXN];

		int ly[MAXN];

		int match[MAXN];



		bool gone_x[MAXN];

		bool gone_y[MAXN];



		memset(lx, -1, sizeof(lx));

		memset(ly, 0, sizeof(ly));



		for (int i = 0; i < m_n; ++i)

		{

			lx[i] = -INF;

			for (int j = 0; j < m_m; ++j)

			{

				lx[i] = max(lx[i], m_weight[i][j]);

			}

		}

		memset(match, -1, sizeof(match));

		for (int i = 0; i < m_n; ++i)

		{

			for ( ; ; )

			{

				memset(gone_x, false, sizeof(gone_x));

				memset(gone_y, false, sizeof(gone_y));

				if (find(i, gone_x, gone_y, lx, ly, match))

				{

					break;

				}

				int d = INF;

				for (int j = 0; j < m_n; ++j)

				{

					if (gone_x[j])

					{

						for (int k = 0; k < m_m; ++k)

						{

							if (gone_y[k] == false)

							{

								d = min(d, lx[j] + ly[k] - m_weight[j][k]);

							}

						}

					}

				}

				for (int j = 0; j < m_n; ++j)

				{

					if (gone_x[j])

					{

						lx[j] -= d;

					}

				}

				for (int j = 0; j < m_m; ++j)

				{

					if (gone_y[j])

					{

						ly[j] += d;

					}

				}

			}

		}

		int ans(0);

		for (int i = 0; i < m_m; ++i)

		{

			if (match[i] != -1)

			{

				ans -= m_weight[match[i]][i];

			}

		}

		return ans;

	}



private:

	int m_n, m_m;

	int m_weight[MAXN][MAXN];



	void neg(void)

	{

		for (int i = 0; i < m_n; ++i)

		{

			for (int j = 0; j < m_m; ++j)

			{

				m_weight[i][j] = -m_weight[i][j];

			}

		}

	}

	bool find(const int p, bool gone_x[], bool gone_y[], int lx[], int ly[], int match[]) const

	{

		gone_x[p] = true;

		for (int i = 0; i < m_m; ++i)

		{

			if ((gone_y[i] == false) && (lx[p] + ly[i] == m_weight[p][i]))

			{

				gone_y[i] = true;

				if ((match[i] == -1) || (find(match[i], gone_x, gone_y, lx, ly, match)))

				{

					match[i] = p;

					return true;

				}

			}

		}

		return false;

	}

};



BGraph g;



int main()

{

	while (g.Input())

	{

		cout << g.Hungry() << endl;

	}

}

