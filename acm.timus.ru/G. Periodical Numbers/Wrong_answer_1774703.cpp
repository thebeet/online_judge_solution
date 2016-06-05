#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int nine[10];
char buf[2][16];

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
	scanf("%s%s", buf[0], buf[1]);
	sscanf(buf[0] + 1, "%d", &n);
	sscanf(buf[1] + 1, "%d", &m);
	int d, s;
	
	i = strlen(buf[0]) - 2;
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
		for (int j 