#include <stdio.h>

#define INT long long

INT calcn(INT n)
{
	INT ans = 0;
	while (n > 0)
	{
		if ((n % 10) == 0)
		{
			++ans;
		}
		n /= 10;
	}
	return ans;
}

INT calc(INT n)
{
	if (n < 0) return -1;
	if (n < 10) return 0;
	return calc((n - 10) / 10) * 10 +  calcn(n / 10) * (n % 10 + 1) + n / 10;
} 

int main()
{
	INT n, m;
	setbuf(stdout, NULL);
	while (scanf("%I64d%I64d", &n, &m), n >= 0)
	{
		printf("%I64d\n", calc(m) - calc(n - 1));
	}
	return 0;
}
