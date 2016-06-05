#include <stdio.h>
#include <memory.h>

#define MAXN 100

typedef int Matrix[MAXN][MAXN];

void Matrix_mul_Matrix(Matrix m1, Matrix m2, Matrix m3, int n, int m) /* m1 * m2 = m3 */
{
	int i, j, k;
	
	memset(m3, 0, sizeof(int) * MAXN * MAXN);
	
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			for (k = 1; k <= n; ++k)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
			m3[i][j] %= m;
		}
	}
	return;
}

int main()
{
	int i, j, n, k, m;
	int bink[50];
	Matrix m1, m2, m3;
	
	scanf("%d%d%d", &n, &k, &m);
	
	memset(m1, 0, sizeof(m1));
	
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			scanf("%d", &m1[i][j]);
			m1[i][j] %= m;
			m1[i][j + n] = m1[i][j];
		}
		m1[i + n][i + n] = 1;
	}
	
	memcpy(m2, m1, sizeof(m1));
	
	memset(bink, 0, sizeof(bink));
	while (k > 0)
	{
		bink[++bink[0]] = k & 1;
		k >>= 1;
	}
	
	for (i = bink[0] - 1; i >= 1; --i)
	{
		Matrix_mul_Matrix(m1, m1, m3, n + n, m);
		if (bink[i] == 1)
		{
			Matrix_mul_Matrix(m3, m2, m1, n + n, m);
		}
		else
		{
			memcpy(m1, m3, sizeof(m1));
		}
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = n + 1; j <= n + n; ++j)
		{
			printf("%d", m1[i][j]);
			if (j == n + n)
			{
				printf("\n");
			}
			else
			{
				printf(" ");
			}
		}
	}
	return 0;
}
