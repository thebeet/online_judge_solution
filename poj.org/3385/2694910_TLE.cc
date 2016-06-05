#include <stdio.h>
#include <string.h>

int deg[100010];

int main()
{
	int i, n, m, d;
	int s = 0;
	scanf("%d%d", &n, &d);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &m);
		++deg[m];
		if (deg[m] > d)
		{
			deg[m] -= d - 1;
			++s;
		}
	}
	printf("%d\n", s);
	return 0;
}
