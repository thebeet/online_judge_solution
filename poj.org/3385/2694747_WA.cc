#include <stdio.h>
#include <string.h>

int deg[100010];

int main()
{
	int i, n, m, d;
	memset(deg, 0, sizeof(deg));
	scanf("%d%d", &n, &d);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &m);
		++deg[m];
	}
	int s = 0;
	for (i = 1; i <= n; ++i)
	{
		if (deg[i] > d)
		{
			deg[i] -= d;
			s += ((deg[i] + d - 2) / (d - 1));
		}
	}
	printf("%d\n", s);
	return 0;
}
