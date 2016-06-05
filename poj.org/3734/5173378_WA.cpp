#include <iostream>
#include <algorithm>

using namespace std;

int mat[4][4] = 
{
	{2, 1, 1, 0},
	{1, 2, 0, 1},
	{1, 0, 2, 1},
	{0, 1, 1, 2},
};

void mat_mul(int m1[4][4], const int m2[4][4])
{
	int m3[4][4];
	memset(m3, 0, sizeof(int)*4*4);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				(m3[i][j] += m1[i][k] * m2[k][j]) %= 10007;
			}
		}
	}
	memcpy(m1, m3, sizeof(int) * 4 * 4);
}

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		int n;
		cin >> n;
		int mat_e[4][4] =
		{
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
		};
		mat_mul(mat_e, mat);
		while (n > 1)
		{
			mat_mul(mat_e, mat_e);
			if ((n & 1) == 1)
			{
				mat_mul(mat_e, mat);
			}
			n >>= 1;
		}
		cout << mat_e[0][0] << endl;
	}
	return 0;
}
