#include <stdio.h>

int phi[1048576];
long long ans[1048576];
int prime[1024];

void prime_init(int primsize = 1000)
{
	int i, j;
	for (i = 2; i <= primsize; ++i)
	{
		if (prime[i] == 0)
		{
			prime[++prime[0]] = i;
			j = i * i;
			while (j <= primsize)
			{
				prime[j] = 1;
				j += i;
			}
		}
	}
}

template <typename T_INT>
T_INT gcd(T_INT b, T_INT a)
{
	T_INT r;
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int i, j, n;
	prime_init();
	for (i = 2; i <= 1000000; ++i)
	{
		for (j = 1; (prime[j] < i) && (j <= prime[0]); ++j)
		{
			if ((i % prime[j]) == 0)
			{
				break;
			}
		}
		if ((prime[j] < i) && (j <= prime[0]))
		{
			int d = i / prime[j];
			int g = gcd(d, prime[j]);
			if (g == 1)
			{
				phi[i] = phi[prime[j]] * phi[d];
			}
			else
			{
				phi[i] = g * phi[d];
			}
		}
		else
		{
			phi[i] = i - 1;
		}
		ans[i] = ans[i - 1] + (long long)phi[i];
	}
	while (scanf("%d", &n), n > 0)
	{
		printf("%I64d\n", ans[n]);
	}
}
