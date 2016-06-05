#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
	int tn, ans;
	scanf("%d", &tn);
	for (int ti = 1; ti <= tn; ++ti)
	{
		int n, i, j, k, nn;
		scanf("%d", &n);
		ans = 100000000;
		if (n == 0)
		{
			ans = 6;
		}
		for (i = 1; i * i <= n; ++i)
		{
			if ((n % i) == 0)
			{
				nn = n / i;
				for (j = i; i * j * j <= n; ++j)
				{
					if ((nn % j) == 0)
					{
						k = nn / j;
						ans = MIN(ans, 2 * (i * j + nn + i * k));
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
