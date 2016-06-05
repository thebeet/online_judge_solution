#include <iostream>

using namespace std;

int f[20020];
int g[20020];

int main()
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &f[i]);
	}
	g[1] = 1;
	printf("1");
	for (i = 2; i <= n; ++i)
	{
		int sum = 0;
		for (j = 2; j * j < i; ++j)
		{
			if ((i % j) == 0)
			{
				sum -= f[j] * g[i / j] + f[i / j] * g[j];
			}
		}
		if (j * j == i)
		{
			sum -= f[j] * g[j];
		}
		sum -= f[i];
		((sum %= 2007) += 2007) %= 2007;
		g[i] = sum;
		printf(" %d", sum);
	}
	printf("\n");
	return 0;
}
