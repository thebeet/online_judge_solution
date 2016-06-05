#include <iostream>
#include <cmath>

using namespace std;

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

template <typename T_INT>
T_INT modular_mul(T_INT a, T_INT b, T_INT p)// return a^b mod p
{
	if (b > 0)
	{
		T_INT ret = modular_mul(a, b >> 1, p);
		return (ret + ret + a * (b & 1)) % p;
	}
	return 0;
}

template <typename T_INT>
T_INT myrand(T_INT lo, T_INT hi)
{
	T_INT n = hi - lo + 1;
	return lo + abs((T_INT)(n * sin((double)rand() * (double)rand() * (double)rand())));
}

template <typename T_INT>
bool Miller_Rabin(T_INT p, T_INT k)
{
	T_INT ans = 1;
	T_INT t = k;
	T_INT b = p - 1;
	T_INT i, j;
	j = 0;
	while ((b & 1) == 0)
	{
		b >>= 1;
		++j;
	}
	while (b > 0)
	{
		if ((b & 1) == 1)
		{
			ans = modular_mul(ans, t, p);
		}
		t = modular_mul(t, t, p);
		b >>= 1;
	}
	if ((ans == 1) || (ans == p - 1))
	{
		return true;
	}
	else
	{
		i = 1;
		while (ans != p - 1)
		{
			if (i == j)
			{
				return false;
			}
			ans = modular_mul(ans, ans, p);
			++i;
		}
		return true;
	}
}

template <typename T_INT>
bool primetest(T_INT p, int k = 64) //use Miller-Rabin
{
	int i;
	const T_INT minprime = 223092870; // 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23
	if (gcd(p, minprime) > 1)
	{
		if ((p == 2) || (p == 3) || (p == 5) || (p == 7) || (p == 11) || (p == 13) || (p == 17) || (p == 19) || (p == 23))
		{
			return true;
		}
		return false;
	}
	for (i = 1; i <= k; ++i)
	{
		if (Miller_Rabin(p, myrand((T_INT)2, p - 1)) == false)
		{
			return false;
		}
	}
	return true;
}

template <typename T_INT>
T_INT Pol_f(T_INT x, T_INT n)
{
	T_INT ret = modular_mul(x, x, n);
	if (ret == n)
	{
		return 1;
	}
	else
	{
		return ret + 1;
	}
}

template <typename T_INT>
T_INT Pollard(T_INT n)
{
	T_INT i, p, x, xx;
	for(i = 1; ; i++)
	{
		x = i;
		xx = Pol_f(x, n);
		p = gcd((xx - x + n) % n, n);
		while (p == 1)
		{
			x = Pol_f(x, n);
			
			xx = Pol_f(Pol_f(xx, n), n);
			p = gcd((xx - x + n) % n, n);
		}
		if ((p == 0) || (p == n))
		{
			continue;
		}
		else
		{
			if ((n / p) > p)
			{
				return p;
			}
			else
			{
				return n / p;
			}
		}
	}
	return n;
}


int main()
{
	int ti, tn;
	long long n;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		cin >> n;
		if (primetest(n))
		{
			cout << "Prime" << endl;
		}
		else
		{
			long long f = Pollard(n);
			while (primetest(f) == false)
			{
				f = Pollard(f);
			}
			cout << f << endl;
		}
	}
	return 0;
}
