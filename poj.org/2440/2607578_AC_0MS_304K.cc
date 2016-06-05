#include <iostream>

using namespace std;

const int p = 2005;

int mat[4][4] = { {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {1, 0, 0, 0} };
int ans[4][4];
int tmp[4][4];
int tmp2[4][4];
int bin[32];

void mat_mul(int mat1[][4], int mat2[][4], int mat3[][4])
{
	int i, j, k;
	memset(mat3, 0, 64);
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			for (k = 0; k < 4; ++k)
			{
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
			mat3[i][j] %= p;
		}
	}
}


int main()
{
	int i, j, n;
	while (cin >> n)
	{
		if (n == 1)
		{
			cout << "2" << endl;
			continue;
		}
		else if (n == 2)
		{
			cout << "4" << endl;
		}
		else
		{
			n -= 2;
			memset(bin, 0, sizeof(bin));
			while (n > 0)
			{
				bin[++bin[0]] = n & 1;
				n >>= 1;
			}
			memcpy(ans, mat, 64);
			for (i = bin[0] - 1; i > 0; --i)
			{
				memcpy(tmp, ans, 64);
				mat_mul(tmp, tmp, ans);
				if (bin[i] == 1)
				{
					memcpy(tmp, ans, 64);
					mat_mul(tmp, mat, ans);
				}
			}
			int tans = 0;
			for (i = 0; i < 4; ++i)
			{
				for (j = 0; j < 4; ++j)
				{
					tans += ans[i][j];
				}
			}
			cout << (tans % p) << endl;
		}
	}
	return 0;
}
