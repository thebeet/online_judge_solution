#include <stdio.h>
#include <string.h>

int deg[100010];

int main()
{
	int i, n, m, d, dc;
	int s = 0;
	scanf("%d%d", &n, &d);
	dc = d - 1;
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &m);
		if (++deg[m] > d)
		{
			deg[m] -= dc;
			++s;
		}
	}
	printf("%d\n", s);
	return 0;
}
