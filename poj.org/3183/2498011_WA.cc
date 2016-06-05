#include <stdio.h>

int main()
{
	int n, m, pr, st;
	scanf("%d", &n);
	pr = 0;
	st = 1;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &m);
		if (st == 1)
		{
			if (pr >= m)
			{
				printf("%d\n", i - 1);
				if (pr > m)
				{
					st = 2;
				}
				else
				{
					st = 1;
				}
			}
		}
		else
		{
			if (pr < m)
			{
				st = 1;
			}
		}
		pr = m;
	}
	if (st == 1)
	{
		printf("%d\n", n);
	}
	return 0;
}
