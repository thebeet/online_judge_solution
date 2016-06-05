#include <stdio.h>

int main()
{
	int l, m;
	while (scanf("%d%d", &l, &m), m > 0)
	{
		++l;
		int i, f, t;
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d", &f, &t);
			l -= (t - f + 1);
		}
		printf("%d\n", l);
	}
	return 0;
}
