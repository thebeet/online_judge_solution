#include <iostream>
#include <algorithm>

using namespace std;

const int ppp = 9901;

template <typename T_INT>
T_INT exgcd(const T_INT &a, const T_INT &b, T_INT &ra, T_INT &rb)
{
	ra = 0;
	rb = 0;
	if (a == 0)
	{
		return b;
	}
	if (b == 0)
	{
		return a;
	}
	T_INT xx1(1), xx2(0), xx3(a);
	T_INT yy1(0), yy2(1), yy3(b);
	T_INT tt1, tt2, tt3;
	T_INT k;
	while ((tt3 = xx3 % yy3) != 0)
	{
		k = xx3 / yy3;
		tt2 = xx2 - k * yy2;
		tt1 = xx1 - k * yy1;
		xx1 = yy1;
		xx2 = yy2;
		xx3 = yy3;
		yy1 = tt1;
		yy2 = tt2;
		yy3 = tt3;
	}
	if (yy3 == 1)
	{
		ra = yy2;
		rb = xx1;
		return 1;
	}
	else
	{
		return yy3;
	}
}

template <typename T_INT>
T_INT modular_exp(const T_INT &a, const T_INT &b, const T_INT &p)// return a^b mod p
{
	T_INT ans(1);
	T_INT ta(a);
	T_INT tb(b);
	while (tb > 0)
	{
		if ((tb % (T_INT)2) == (T_INT)1)
		{
			ans = (ans * ta) % p;
		}
		ta = (ta * ta) % p;
		tb /= (T_INT)2;
	}
	return ans;
}

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		int ans(1);
		for (int i = 2; i * i <= a; ++i)
		{
			int tans;
			if ((a % i) == 0)
			{
				int k = 1;
				a /= i;
				while ((a % i) == 0)
				{
					a /= i;
					++k;
				}
				k *= b;
				tans = modular_exp(i - 1, k + 1, ppp) - 1;
				(tans *= (modular_exp(i - 1, ppp - 2, ppp) - 1)) %= ppp;
			}
			(ans *= tans) %= ppp;
		}
		if (a > 1)
		{
			int tans;
			int k = 1;
			k *= b;
			tans = modular_exp(a, k + 1, ppp) - 1;
			(tans *= (modular_exp(a - 1, ppp - 2, ppp))) %= ppp;
			(ans *= tans) %= ppp;
		}
		cout << ans << endl;
	}
	return 0;
}
