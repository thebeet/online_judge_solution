#include <stdio.h>
#include <string.h>

typedef int mat[1010][1010];

mat a, b, c, d;
int n;

bool mat_mul_mat(mat a, mat b, mat c)
{
	int k, i, j, m;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			m = 0;
			for (k = 1; k <= n; ++k)
			{
				m += a[i][k] * b[k][j];
			}
			if (m != c[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void inp(mat a)
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
	return;
}

int main()
{
	scanf("%d", &n);
	inp(a);
	inp(b);
	inp(c);
	if (mat_mul_mat(a, b, c))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}
