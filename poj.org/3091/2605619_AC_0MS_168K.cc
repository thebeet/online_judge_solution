#include <cstdio>

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int n, i, k, x, m;
		scanf("%d", &n);
		k = 0;
		x = 1;
		m = ((n << 1) + 1) / 3;
		printf("%d %d %d\n", ti, n, m);
		for (i = n - m + 1; i <= n; ++i)
		{
			++k;
			if (x > i)
			{
				x = 2;
			}
			printf("[%d,%d]%c", i, x, (k & 7) ? ' ' : '\n');
			x += 2;
		}
		if (k & 7)
		{
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
