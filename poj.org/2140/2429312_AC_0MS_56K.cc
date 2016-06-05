#include <stdio.h>

int main()
{
	int i, n, s, ans;
	scanf("%d", &n);
	ans = 0;
	s = 0;
	
	for (i = 1; (s += i) <= n; ++i)
	{
		if (((n - s) % i) == 0)
		{
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
