#include <stdio.h>
#include <string.h>

#define MAXN 1000010

bool isprime[MAXN];
int primes[MAXN];

int main()
{
	int i, j, n;
	memset(primes, 0, sizeof(primes));
	memset(isprime, true, sizeof(isprime));
	for (i = 2; i * i < MAXN; ++i)
	{
		if (isprime[i])
		{
			for (j = i * i; j <= MAXN; j += i)
			{
				isprime[j] = false;
			}
			primes[++primes[0]] = i;
		}
	}
	
	while (scanf("%d", &n), n > 0)
	{
		for (i = 1; ; ++i)
		{
			if (isprime[n - primes[i]])
			{
				break;
			}
		}
		printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
	}

	return 0;
}
