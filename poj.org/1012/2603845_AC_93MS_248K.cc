#include <iostream>

int ans[16];

int calc(int n)
{
	int i, k, x, n2;
	for (i = n; ; ++i)
	{
		if (i % (n + 1) <= 1)
		{
			n2 = n << 1;
			x = 0;
			for (k = 1; k <= n; ++k)
			{
				x = (x + i - 1) % n2;
				if (x < n)
				{
					break;
				}
				--n2;
			}
			if (k > n)
			{
				return i;
			}
		}
	}
}

int main()
{
	int i, n;
	for (i = 1; i <= 13; ++i)
	{
		ans[i] = calc(i);
	}
	while (scanf("%d", &n), n > 0)
	{
		printf("%d\n", ans[n]);
	}
	return 0;
}
