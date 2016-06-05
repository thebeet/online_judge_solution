#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int prime[2097152];
bool isprime[65536];

void prime_init(long long primsize = 46340) //2097152
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

template <typename T_INT>
struct Factorization
{
	T_INT n;
	T_INT p[32];
	T_INT l[32];
};

template <typename T_INT>
Factorization<T_INT> Factorizate(T_INT m)
{
	Factorization<T_INT> ans;
	ans.n = 0;
	for (int i = 1; (i <= prime[0]) && (prime[i] <= m); ++i)
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
	Factorization<T_INT> factors;
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
	int i;
	int usage[32];
	T_INT phi = euler_phi(m);
	int ans = phi;
	Factorization<T_INT> f = Factorizate(phi);
	memset(usage, 0, sizeof(usage));
	int x = 1;
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
			for (int j = 1; j <= usage[i]; ++j)
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
	T_INT i, p, x, xx;
	for (i = 1; ; ++i)
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
		if ((p > 1) && (p < n)) 
		{
			if (p <= (n / p))
			{
				return p;
			}
			else
			{
				return (n / p);
			}
		}
	}
	return n;
}

int main()
{
	long long i, j, n, ans1;
	long long ans2;
	prime_init();
	while (cin >> n)
	{
		Factorization<long long> f = Factorizate(n);
		ans1 = 0;
		for (i = 1; i <= f.n; ++i)
		{
			ans1 += f.l[i];
		}
		ans2 = 1;
		for (i = 1; i <= ans1; ++i)
		{
			ans2 *= i;
		}
		for (i = 1; i <= f.n; ++i)
		{
			for (j = 1; j <= f.l[i]; ++j)
			{
				ans2 /= j;
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
