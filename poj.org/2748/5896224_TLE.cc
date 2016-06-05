/*
 * Logs_Stacking.cpp
 *
 *  Created on: Sep 22, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

class Mat
{
public:
	Mat()
	{
		memset(mat, 0, sizeof(mat));
	}
	int mat[2][2];
};

Mat operator * (const Mat &mat1, const Mat &mat2)
{
	Mat res;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				(res.mat[i][j] += mat1.mat[i][k] * mat2.mat[k][j]) %= 100000;
			}
		}
	}
	return res;
}

int main()
{
	int tn;
	scanf("%d", &tn);

	for (int ti = 0; ti < tn; ++ti)
	{
		Mat e;
		Mat k;
		k.mat[0][1] = k.mat[1][0] = k.mat[1][1] = 1;
		for (int i = 0; i < 2; ++i)
		{
			e.mat[i][i] = 1;
		}
		long long n;
		scanf("%lld", &n);
		n = n * 2;
		while (n > 0)
		{
			if (n & 1LL)
			{
				e = e * k;
			}
			k = k * k;
			n >>= 1;
		}
		cout << e.mat[0][0] << endl;
	}
	return 0;
}
