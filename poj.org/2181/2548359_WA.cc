#include <stdio.h>

int main()
{
	int i, n, m, sum;
	int st = 1;
	scanf("%d", &n);
	sum = 0;
	m = 0;
	for (i = 1; i <= n; ++i)
	{
		int inp;
		scanf("%d", &inp);
		if ((st == 1) ^ (inp > m))
		{
			sum += st * m;
			st = -st;
		}
		m = inp;
	}
	if (st == 1)
	{
		sum += st * m;
	}
	printf("%d\n", sum + st * m);
	return 0;
}
