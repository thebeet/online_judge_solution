#include <stdio.h>
#include <string.h>

int prime[10010];
int pow[10];

int main()
{
	int i, j, n, m;
	prime[0] = 0;
	for (i = 2; i < 100; ++i)
	{
		if (prime[i] == 0)
		{
			prime[++prime[0]] = i;
			j = i * i;
			while (j < 10000)
			{
				prime[j] = 1;
				j += i;
			}
		}
	}
	for ( ; i < 10000; ++i)
	{
		if (prime[i] == 0)
		{
			prime[++prime[0]] = i;
		}
	}
	prime[++prime[0]] = 10000000;
	
	while (scanf("%d", &n) != EOF)
	{
		printf("%5d -> ", n);
		memset(pow, 0, sizeof(pow));
		for (i = 1; prime[i] <= n; ++i)
		{
			int tp = prime[i];
			m = 0;
			while (n >= tp)
			{
				m += n / tp;
				tp *= prime[i];
			}
			pow[prime[i] % 10] += m;
		}
		int ans = 1;
		if (pow[2] > 0)
		{
			ans = 6;
			pow[2] = (pow[2] - pow[5]) & 3;
			for (j = 1; j <= pow[2]; ++j)
			{
				ans = (ans * 2) % 10;
			}
		}
		pow[3] &= 3;
		for (j = 1; j <= pow[3]; ++j)
		{
			ans = (ans * 3) % 10;
		}
		pow[7] &= 3;
		for (j = 1; j <= pow[7]; ++j)
		{
			ans = (ans * 7) % 10;
		}
		if ((pow[9] & 1) > 0)
		{
			ans = 10 - ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
