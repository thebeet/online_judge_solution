#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int ten[10];
char buf[2][16];
int circle[10][10] =
{
		{0},
		{1, 1},
		{2, 11, 1},
		{2, 111, 1},
		{3, 1111, 101, 1},
		{2, 11111, 1},
		{4, 111111, 10101, 1001, 1},
		{2, 1111111, 1},
		{4, 11111111, 1010101, 10001, 1},
		{3, 111111111, 1001001, 1},
};
int dd[10][10] =
{
		{0},
		{1, 1},
		{2, 2, 1},
		{2, 3, 1},
		{3, 4, 2, 1},
		{2, 5, 1},
		{4, 6, 3, 2, 1},
		{2, 7, 1},
		{4, 8, 4, 3, 1},
		{3, 9, 3, 1},
};

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
	ten[0] = 1;
	for (i = 1; i <= 9; ++i)
	{
		ten[i] = ten[i - 1] * 10;
	}
	scanf("%s%s", buf[0], buf[1]);
	sscanf(buf[0] + 1, "%d", &n);
	sscanf(buf[1] + 1, "%d", &m);
	
	int l = strlen(buf[0]) - 2;
	
	int d = n + m;
	int x = d / ten[l];
	
	int p, up;
	p = d;
	up = -1;
	int ip = l - 1;
	int iup = l - 1;
	if (x > 0)
	{
		p = d + 1 - ten[l];
		up = d - ten[l];
		while ((p / ten[ip]) == (up / ten[iup]))
		{
			p = (p % ten[ip]) * 10 + p / ten[ip];
			up %= ten[iup];
			--iup;
		}
	}
	for (i = 1; i < circle[l][0]; ++i)
	{
		if ((p % circle[l][i]) == 0)
		{
			l /= dd[l][i];
			break;
		}
	}
	printf("(");
	for (i = l - 1; i >= 0; --i)
	{
		printf("%d", (p % ten[i + 1]) / ten[i]);
		//p /= 10;
	}
	printf(")");
	if (up >= 0)
	{
		for (i = iup; i >= 0; --i)
		{
			printf("%d", (up % ten[i + 1]) / ten[i]);
			//up /= 10;
		}
	}
	return 0;
}
