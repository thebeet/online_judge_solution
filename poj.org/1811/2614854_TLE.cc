#include <iostream>
#include <cmath>

using namespace std;

long long prime[65536];
bool isprime[65536];

void prime_init(int primsize = 46340)
{
	long long i, j;
	memset(prime, 0, sizeof(prime));
	memset(isprime, true, sizeof(isprime));
	for (i = 2; i <= primsize; ++i)
	{
		if (isprime[i] == true)
		{
			prime[++prime[0]] = i;
			j = i * i;
			while (j <= primsize)
			{
				isprime[j] = false;
				j += i;
			}
		}
	}
}


template <typename T_INT>
T_INT gcd(T_INT a, T_INT b)
{
	T_INT r;
	if (b < 0)
	{
		b = -b;
	}
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
	return lo + abs((T_INT)(n * sin((double)rand() * (double)rand() * (double)rand() * (double)rand())));
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
bool primetest(T_INT p, int k = 4096) //use Miller-Rabin
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
	if (ret == n - 1)
	{
		return 0;
	}
	else
	{
		return ret + 1;
	}
}

template <typename T_INT>
T_INT brute(T_INT n)
{
	T_INT i;
	for (i = 1; i <= prime[0]; ++i)
	{
		if ((n % prime[i]) == 0)
		{
			return prime[i];
		}
	}
	return n;
}

template <typename T_INT>
T_INT Pollard(T_INT n)
{
	T_INT i, k, d, x, y;
	i = 1;
	k = 2;
	x = myrand((T_INT)2, n - 1);
	y = x;
	while (true)
	{
		++i;
		x = Pol_f(x, n);
		d = gcd(n, y - x);
		if ((d > 1) && (d < n))
		{
			if ((n / d) >= d)
			{
				return d;
			}
			else
			{
				return n / d;
			}
		}
		else
		{
			if (i == k)
			{
				x = myrand((T_INT)2, n - 1);
				y = x;
				k <<= 1;
			}
		}
	}
	return n;
}

template <typename T_INT>
T_INT findminfactor(T_INT n)
{
	long long f = Pollard(n);
	long long f2 = n / f;
	bool isf = primetest(f);
	bool isf2 = primetest(f2);
	
	if ((isf) && (isf2))
	{
		return f;
	}
	if ((isf == false) && (isf2))
	{
		return brute(f);
	}
	if ((isf) && (isf2 == false))
	{
		return min(f, brute(f2));
	}
	if ((isf == false) && (isf2 == false))
	{
		return min(brute(f), brute(f2));
	}
}

int main()
{
	int ti, tn;
	long long n;
	prime_init();
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
			cout << findminfactor(n) << endl;
		}
	}
	return 0;
}
