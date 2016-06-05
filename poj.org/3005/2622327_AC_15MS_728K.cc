#include <stdio.h>
#include <string.h>

const long long maxn = 2000000000;

bool isprime[529424];

void prime_init(int primsize = 46340)
{
	int i, j;
	memset(isprime, true, sizeof(isprime));
	for (i = 2; i <= 46340; ++i)
	{
		if (isprime[i] == true)
		{
			j = i * i;
			while (j <= primsize)
			{
				isprime[j] = false;
				j += i;
			}
		}
	}
}

bool primetest(long long p)
{
	if (p <= 1)
	{
		return false;
	}
	return isprime[p];
}

int ans[10240];

int main()
{
	prime_init(529423);
	
	memset(ans, 0, sizeof(ans));
	long long a, b;
	long long p1, p, n;
	for (a = 1; a <= 514; ++a)
	{
		for (b = -a + 1; a * b <= 1050; ++b)
		{
			p1 = a + b;
			p = p1;
			for (n = 1; (p <= maxn) && primetest(p1); ++n)
			{
				if (n >= 3)
				{
					ans[++ans[0]] = (int)p;
				}
				p1 = a * p1 + b;
				p *= p1;
			}
		}
	}
	
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, lo, hi, tot;
		scanf("%d%d", &lo, &hi);
		tot = 0;
		for (i = 1; i <= ans[0]; ++i)
		{
			if ((ans[i] >= lo) && (ans[i] <= hi))
			{
				++tot;
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}
