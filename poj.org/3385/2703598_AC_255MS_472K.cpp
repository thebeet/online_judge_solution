#include <stdio.h>

int deg[1000010];

int main()
{
	int i, n, m, d;
	int s = 0;
	scanf("%d%d", &n, &d);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &m);
		if (++deg[m] > d)
		{
			deg[m] = 2;
			++s;
		}
	}
	printf("%d\n", s);
	return 0;
}
