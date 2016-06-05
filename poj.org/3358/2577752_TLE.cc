#include <cstdio>

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
	int ti = 0;
	unsigned int n, m;
	while (scanf("%u/%u", &n, &m) != EOF)
	{
		unsigned int pr = 1;
		unsigned int g = gcd(n, m);
		n /= g;
		m /= g;
		
		printf("Case #%d: ", ++ti);
		
		pr = 1;
		while ((m & 1) == 0)
		{
			++pr;
			m >>= 1;
		}
		
		printf("%u,", pr);
		
		unsigned int width = 1;
		unsigned int rest = 1 % m;
		while (rest > 0)
		{
			rest <<= 1;
			++rest;
			rest %= m;
			++width;
		}
		
		printf("%u\n", width);
	}
	return 0;
}
