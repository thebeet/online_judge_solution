#include <iostream>
 
const int Size = sizeof(long long) * 16 * 16;
using namespace std;

long long mat[16][16] =
{
	//   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1}, //0
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //1
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //2
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, //3
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //4
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //5
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, //6
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //7
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //8
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //9
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //10
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //11
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //12
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //13
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //14
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //15
};

int n;
long long pp;
long long ans[16][16];
long long t[16][16];

void mat_e(long long m[16][16])
{
	int i;
	memset(m, 0, Size);
	for (i = 0; i < 16; ++i)
	{
		m[i][i] = 1;
	}
}

void mat_mul(long long m1[16][16], long long m2[16][16])
{
	int i, j, k;
	long long m3[16][16];
	memset(m3, 0, Size);
	for (i = 0; i < 16; ++i)
	{
		for (j = 0; j < 16; ++j)
		{
			for (k = 0; k < 16; ++k)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
			m3[i][j] %= pp;
		}
	}
	memcpy(m1, m3, Size);
}

int main()
{
	while ((cin >> n >> pp), n > 0)
	{
		mat_e(ans);
		memcpy(t, mat, Size);
		while (n > 0)
		{
			if ((n & 1) == 1)
			{
				mat_mul(ans, t);
			}
			mat_mul(t, t);
			n >>= 1;
		}
		cout << ans[0][0] << endl;
	}
	return 0;
}
