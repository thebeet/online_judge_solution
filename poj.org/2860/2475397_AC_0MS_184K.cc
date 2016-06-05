#include <stdio.h>

int main()
{
	int i, m, k, ans;
	int blocks[11];
	scanf("%*d%*d%d", &k);
	ans = 0;
	for (i = 1; i <= k; ++i)
	{
		scanf("%d", &blocks[i]);
	}
	for (i = 1; i <= k; ++i)
	{
		scanf("%d", &m);
		if (m > blocks[i])
		{
			ans += m - blocks[i];
		}
		else
		{
			ans += blocks[i] - m;
		}
	}
	printf("%d\n", ans / 2);
	return 0;
}
