/*
 * Matrix::matrix.cpp
 *
 *  Created on: Aug 25, 2009 3:44:49 PM
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
#include <cstdio>

using namespace std;

template <typename Elem = long long>
class Matrix : public vector< vector<Elem> >
{
public:
	Matrix(const int N, const int M) :
		vector< vector<Elem> >(N, vector<Elem>(M, Elem())),
		m_N(N), m_M(M)
	{
	}

	~Matrix()
	{
	}

	int m_N;
	int m_M;

};

template <typename Elem>
Matrix<Elem> operator *(const Matrix<Elem> &m1, const Matrix<Elem> &m2)
{
	Matrix<Elem> ans(m1.m_N, m2.m_M);
	for (int i = 0; i < m1.m_N; ++i)
	{
		for (int j = 0; j < m2.m_M; ++j)
		{
			for (int k = 0; k < m1.m_M; ++k)
			{
				ans[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	return ans;
}

template <typename Elem>
Matrix<Elem> gen(int N)
{
	Matrix<Elem> ans(N, N);
	for (int i = 0; i < N; ++i)
	{
		ans[i][i] = 1;
	}
	char s[4];
	scanf("%s", s);
	switch (s[0])
	{
		case 'g':
		{
			int a;
			scanf("%d", &a);
			--a;
			ans[N - 1][a] = 1;
			break;
		}
		case 's':
		{
			int a, b;
			scanf("%d%d", &a, &b);
			--a; --b;
			ans[a][a] = 0;
			ans[b][b] = 0;
			ans[a][b] = 1;
			ans[b][a] = 1;
			break;
		}
		case 'e':
		{
			int a;
			scanf("%d", &a);
			--a;
			ans[a][a] = 0;
			break;
		}
	}
	return ans;
}

int main()
{
	int n, m, k;
	while ((cin >> n >> m >> k), n > 0)
	{
		Matrix<> w(n + 1, n + 1);
		for (int i = 0; i < n + 1; ++i)
		{
			w[i][i] = 1;
		}
		for (int i = 0; i < k; ++i)
		{
			w = w * gen<long long>(n + 1);
		}

		Matrix<> s(n + 1, n + 1);
		for (int i = 0; i < n + 1; ++i)
		{
			s[i][n] = 1;
		}

		while (m > 0)
		{
			if (m & 1)
			{
				s = s * w;
			}
			w = w * w;
			m >>= 1;
		}

		for (int i = 0; i < n; ++i)
		{
			cout << s[i][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
