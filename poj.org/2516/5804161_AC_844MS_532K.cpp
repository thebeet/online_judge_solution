/*

 * Minimum_Cost.cpp

 *

 *  Created on: 2009-9-3

 *      Author: Administrator

 */



#include <iostream>

#include <algorithm>

#include <vector>

#include <cstring>



using namespace std;



const int MAXN = 256;

const int INF = 0x7fffffff;



class BGraph_Weight

{

public:

	BGraph_Weight(const int n, const int m) :

		m_n(n), m_m(m)

	{

		//memset(m_weight, 0, sizeof(int) * MAXN * MAXN);

	}



	virtual ~BGraph_Weight()

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



		int ans(0);

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

							if (gone_y[k])

							{

								d = min(d, lx[j] + ly[k] - m_weight[i][j]);

							}

						}

					}

				}

				for (int j = 0; j < m_n; ++j)

				{

					if (gone_x[j])

					{

						--lx[j];

					}

				}

				for (int j = 0; j < m_m; ++j)

				{

					if (gone_y[j])

					{

						++ly[j];

					}

				}

			}

		}

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





class BGraphWeightNode : public BGraph_Weight

{

public:

	BGraphWeightNode(const int n, const int m) :

		BGraph_Weight(n, m)

	{

		m_nodex = new int[n];

		m_nodey = new int[m];

	}



	virtual ~BGraphWeightNode()

	{

		delete [] m_nodex;

		delete [] m_nodey;

	}



	int *m_nodex;

	int *m_nodey;

};



int mat[64][64][64];

int shop[64][64];

int store[64][64];

int sumshop[64];

int sumstore[64];



int main()

{

	int n, m, k;

	while ((cin >> n >> m >> k), k > 0)

	{

		memset(sumshop, 0, sizeof(sumshop));

		memset(sumstore, 0, sizeof(sumstore));

		for (int i = 0; i < n; ++i)

		{

			for (int h = 0; h < k; ++h)

			{

				cin >> shop[i][h];

				sumshop[h] += shop[i][h];

			}

		}

		bool flag(true);

		for (int i = 0; i < m; ++i)

		{

			for (int h = 0; h < k; ++h)

			{

				cin >> store[i][h];

				sumstore[h] += store[i][h];

			}

		}

		for (int h = 0; h < k; ++h)

		{

			if (sumshop[h] > sumstore[h])

			{

				flag = false;

				break;

			}

		}

		int sum(0);

		if (flag == false) sum = -1;

		for (int h = 0; h < k; ++h)

		{

			BGraph_Weight graph(sumshop[h], sumstore[h]);

			int kshop(0);

			for (int i = 0; i < n; ++i)

			{

				int kstore(0);

				for (int j = 0; j < m; ++j)

				{

					int w;

					cin >> w;

					for (int x = 0; x < shop[i][h]; ++x)

					{

						for (int y = 0; y < store[j][h]; ++y)

						{

							graph.AddPath(kshop + x, kstore + y, w);

						}

					}

					kstore += store[j][h];

				}

				kshop += shop[i][h];

			}

			if (flag)

			{

				sum += graph.KM();

			}

		}

		cout << sum << endl;

	}

	return 0;

}

