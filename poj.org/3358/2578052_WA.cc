#include <cstdio>
#include <cstring>

#define fmt "%lld"

int prime[65536];

template <typename T_INT>
T_INT gcd(T_INT a, T_INT b)
{
	T_INT r;
	if (a < b)
	{
		r = a;
		a = b;
		b = r;
	}
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
	int i, j;
	memset(prime, 0, sizeof(prime));
	for (i = 2; i <= 46340; ++i)
	{
		if (prime[i] == 0)
		{
			prime[++prime[0]] = i;
			j = i * i;
			while (j <= 46340)
			{
				prime[j] = 1;
				j += i;
			}
		}
	}

	
	int ti = 0;
	long long n, m;
	while (scanf(fmt "/" fmt, &n, &m) != EOF)
	{
		long long pr = 1;
		long long g = gcd(n, m);
		n /= g;
		m /= g;
		
		printf("Case #%d: ", ++ti);
		
		pr = 1;
		while ((m & 1) == 0)
		{
			++pr;
			m >>= 1;
		}
		
		printf(fmt ",", pr);
		
		long long width = 1;
		for (i = 1; (i <= prime[0] + 1) && (m >= prime[i]); ++i)
		{
			int tp = prime[i];
			if (i > prime[0])
			{
				tp = m;
			}
			if ((m % tp) == 0)
			{
				long long newwidth = 1;
				while ((m % tp) == 0)
				{
					m /= tp;
				}
				long long rest = 1;
				if (((tp & 7) == 3) || ((tp & 7) == 5))
				{
					newwidth = tp - 1;
				}
				else
				{
					while (rest > 0)
					{
						rest += rest + 1;
						if (rest >= tp)
						{
							rest -= tp;
						}
						++newwidth;
					}
				}
				long long widthgcd = gcd(newwidth, width);
				newwidth /= widthgcd;
				width *= newwidth;
			}
		}
		printf(fmt"\n", width);
	}
	return 0;
}
/*
 * 1/3
Case #1: 1,2
1/5
Case #2: 1,4
1/15
Case #3: 1,4
1/7
Case #4: 1,3
1/35
Case #5: 1,12
1234567891/1987242167
Case #6: 1,941325228
1/11
Case #7: 1,10
1/13
Case #8: 1,12
1/15
Case #9: 1,4
1/17
Case #10: 1,8
1/341
Case #11: 1,10
1/2
Case #12: 2,1
*/
