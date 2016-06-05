#include <stdio.h>

long gcd(long a, long b)
{
	long c;
	while (b > 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	long i, n, ans;
	scanf("%ld", &n);
	ans = 0;
	for (i = 2; i < n; i += 2)
	{
		if (gcd(gcd(i, n), i/2) == 1)
		{
			ans++;
		}
	}
	printf("%ld\n", ans);
	return 0;
}
