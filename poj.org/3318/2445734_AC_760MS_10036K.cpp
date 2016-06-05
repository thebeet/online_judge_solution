#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int mat[1010][1010];

mat a, b, c, d, e, f, g;
int n;

void mat_mul_mat(mat a, mat b, mat c)
{
	int k, i, j;
	i = 1;
	for (j = 1; j <= n; ++j)
	{
		for (k = 1; k <= n; ++k)
		{
			c[i][j] += a[i][k] * b[k][j];
		}
	}
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
	int i;
	scanf("%d", &n);
	inp(a);
	inp(b);
	inp(c);
	memset(d, 0, sizeof(d));
	for (i = 1; i <= n; ++i)
	{
		d[1][i] = (int)(rand());
	}
		
	mat_mul_mat(d, a, e);
	mat_mul_mat(e, b, f);
	mat_mul_mat(d, c, g);
	
	for (i = 1; i <= n; ++i)
	{
		if (g[1][i] != f[1][i])
		{
			break;
		}
	}
	
	if (i <= n)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	return 0;
}
