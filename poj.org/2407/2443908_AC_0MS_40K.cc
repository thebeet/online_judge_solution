#include <stdio.h>

int euler(int n)
{
	int i, ans;
	ans = 1;
	for (i = 2; i * i <= n; ++i)
	{
		if ((n % i) == 0)
		{
			ans *= (i - 1);
			n /= i;
			while ((n % i) == 0)
			{
				ans *= i;
				n /= i;
			}
		}		
	}
	if (n > 1) ans *= (n - 1);
	return ans;
}

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		printf("%d\n", euler(n));
	}
	return 0;
}
