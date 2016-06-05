#include <stdio.h>
#include <memory.h>

/*
 * t[1] = 1
 * t[2] = 2
 * t[3] = 5
 * t[4] = 14
 * t[5] = 42
 * t[6] = 132
 * t[7] = 429
 */

int t[50];

void painttree(int n, int m)
{
	int j;
	
	if (n == 0) return;
	if (n == 1)
	{
		printf("X");
		return;
	}
	for (j = 1; (m - (t[j - 1] * t[n - j])) > 0; ++j)
	{
		  m -= (t[j - 1] * t[n - j]);
	}
	if ((j - 1) > 0)
	{
		printf("(");
		painttree(j - 1, (m - 1) / t[n - j] + 1);
		printf(")");
	}
	printf("X");
	if ((n - j) > 0) 
	{
		printf("(");
		painttree(n - j, (m - 1) % t[n - j] + 1);
		printf(")"); 
	}
	return;
}	

void maketree(int n)
{
	int i;
	
	if (n == 0) return;
	if (n == 1)
	{
		printf("X");
		return;
	}
	for (i = 1; (n - t[i]) > 0; ++i)
	{
		n -= t[i];
	}
	
	painttree(i, n);
	
	return;
}

int main()
{
	int i, j, n;
	
	memset(t, 0, sizeof(0));
	
	setbuf(stdout, NULL);
	
	t[0] = t[1] = 1;
	for (i = 2; i <= 18; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			  t[i] += (t[j - 1] * t[i - j]);
		}
	}
	
	while (scanf("%d", &n), n > 0)
	{
		maketree(n);
		printf("\n");
	}
	
	return 0;
}
