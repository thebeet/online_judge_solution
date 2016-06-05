#include <stdio.h>

int main()
{
	long i, j, n, m, win, p, pmax;
	while (scanf("%ld", &n) != EOF)
	{
		pmax = -1;
		for (i = 1; i <= n; i++)
		{
			win = 0;
			for (j = 1; j <= n; j++)
			{
				scanf("%ld", &m);
				if (m == 3) win++;
			}
			if (win > pmax)
			{
				pmax = win;
				p = i;
			}
		}
		printf("%ld\n", p);
	}
	return 0;
}
