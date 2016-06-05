#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long prime[65536];
const long long primsize = 65535;

void prime_init()
{
	long long i, j;
	memset(prime, 0, sizeof(prime));
	for (i = 2; i <= primsize; ++i)
	{
		if (prime[i] == 0)
		{
			prime[++prime[0]] = (long long)i;
			j = i * i;
			while (j <= primsize)
			{
				prime[j] = 1;
				j += i;
			}
		}
	}
}

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
T_INT modular_exp(T_INT a, T_INT b, T_INT p)// return a^b mod p
{
	T_INT ans = 1;
	T_INT t = a;
	while (b > 0)
	{
		if ((b & 1) == 1)
		{
			ans = (ans * t) % p;
		}
		t = (t * t) % p;
		b >>= 1;
	}
	return ans;
}

struct Factorization
{
	long long n;
	long long p[32];
	long long l[32];
};

template <typename T_INT>
Factorization Factorizate(T_INT m)
{
	Factorization ans;
	ans.n = 0;
	for (long long i = 1; (i <= prime[0]) && (prime[i] <= m); ++i)
	{
		T_INT tp;
		tp = prime[i];
		if ((m % tp) == 0)
		{
			m /= tp;
			++ans.n;
			ans.p[ans.n] = prime[i];
			ans.l[ans.n] = 1;
			while ((m % tp) == 0)
			{
				m /= tp;
				++ans.l[ans.n];
			}
		}
	}
	if (m > 1)
	{
		ans.p[++ans.n] = m;
		ans.l[ans.n] = 1;
	}
	return ans;
}

template <typename T_INT>
T_INT euler_phi(T_INT m)
{
	T_INT i, j, ans;
	Factorization factors;
	factors = Factorizate(m);
	ans = 1;
	for (i = 1; i <= factors.n; ++i)
	{
		for (j = 2; j <= factors.l[i]; ++j)
		{
			ans *= factors.p[i];
		}
		ans *= factors.p[i] - 1;
	}
	return ans;
}

template <typename T_INT>
T_INT calc_f1(T_INT m)
{
	long long i;
	long long usage[32];
	T_INT phi = euler_phi(m);
	long long ans = phi;
	Factorization f = Factorizate(phi);
	memset(usage, 0, sizeof(usage));
	long long x = 1;
	while (x < phi)
	{
		++usage[1];
		i = 1;
		x = 1;
		for (i = 1; i <= f.n; ++i)
		{
			while (usage[i] > f.l[i])
			{
				usage[i] = 0;
				++usage[++i];
			}
			for (long long j = 1; j <= usage[i]; ++j)
			{
				x *= f.p[i];
			}
		}
		if ((x < ans) && (modular_exp(2, x, m) == 1))
		{
			ans = x;
		}
	}
	return ans;
}

template <typename T_INT>
bool primetest(T_INT p, long long k = 50)
{
	return 0;
}

int main()
{
	long long i, n;
	prime_init();
	while ((cin >> n), n != 0)
	{
		long long m;
		long long ans = 0;
		m = (n > 0) ? n : -n;
		Factorization f = Factorizate(m);
		for (i = 1; i <= f.n; ++i)
		{
			ans = gcd(ans, f.l[i]);
		}
		if (ans == 0)
		{
			ans /= ans;
		}
		while (((ans & 1) == 0) && (n < 0))
		{
			ans >>= 1;
		}
		cout << ans << endl;
	}
	return 0;
}
