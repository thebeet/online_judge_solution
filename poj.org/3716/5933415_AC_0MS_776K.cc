/*
 * Pandas_Birthday_Present.cpp
 *
 *  Created on: Sep 29, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 7 * 7 * 7 * 7;

int poss[5][N];
int pwei[N];
int wei[N];
double ans[5][5];

int C[8][8];

void Init()
{
	C[0][0] = 1;
	for (int i = 1; i < 8; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j < i; ++j)
		{
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
		C[i][i] = 1;
	}
	memset(poss, 0, sizeof(poss));
	memset(wei, 0, sizeof(wei));
	for (int k = 0; k < N; ++k)
	{
		int c[5][5];
		memset(c, 0, sizeof(c));
		c[0][0] = 1;
		int n = k;
		pwei[k] = 1;
		for (int i = 0; i < 4; ++i)
		{
			int d = n % 7;
			wei[k] += d;
			pwei[k] *= C[6][d];
			n /= 7;
			for (int j = 0; j <= i; ++j)
			{
				c[i + 1][j + 1] += c[i][j] * d;
				c[i + 1][j] += c[i][j] * (6 - d);
			}
		}
		for (int i = 0; i <= 4; ++i)
		{
			poss[i][k] = c[4][i];
		}
	}
}

void Calc()
{
	for (int i = 0; i <= 4; ++i)
	{
		for (int j = i; j <= 4; ++j)
		{
			double totsum(0.0);
			double weisum(0.0);
			for (int k = 0; k < N; ++k)
			{
				 weisum += (double)poss[i][k] * poss[j][k] * wei[k] * pwei[k];
				 totsum += (double)poss[i][k] * poss[j][k] * pwei[k];
			}
			ans[i][j] = ans[j][i] = weisum / totsum / 6.0;
		}
	}
}

int main()
{
	Init();
	Calc();
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		int a, b;
		cin >> a >> b;
		cout << fixed << std::setprecision(3) << ans[a][b] << endl;
	}
	return 0;
}
