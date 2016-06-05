#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int nine[10];

template <typename T_INT>
T_INT gcd(T_INT a, T_INT b)
{
	T_INT r;
	if (b > a)
	{
		swap(a, b);
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
	int i, n, m;
	nine[1] = 9;
	for (i = 2; i <= 9; ++i)
	{
		nine[i] = nine[i - 1] * 10 + 9;
	}
	scanf("(%d)\n(%d)", &n, &m);
	int d, s;
	
	for (i = 1; nine[i] < n; ++i)
	{
	}
	s = nine[i];
	d = n + m;
	if ((d % s) == 0)
	{
		printf("%d\n", d / s);
	}
	else
	{
		if ((d / s) > 0)
		{
			printf("%d", d / s);
		}
		d %= s;
		int g = gcd(d, s);
		s /= g;
		for (i = 1; ; ++i)
		{
			if ((nine[i] % s) == 0)
			{
				break;
			}
		}
		int p = nine[i] / s;
		d = d / g * p;
		char out[32];
		for (int j = 1; j <= i; ++j)
		{
			out[j] = (d % 10) + '0';
			d /= 10;
		}
		printf("(");
		for (int j = i; j >= 1; --j)
		{
			printf("%c", out[j]);
		}
		printf(")\n");
	}
	return 0;
}
