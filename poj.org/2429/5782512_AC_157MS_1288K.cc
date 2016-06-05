#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int hipirme = 65536;

long long prime[hipirme];
bool isprime[hipirme];

void prime_init(long long primsize = hipirme)
{
	long long i, j;
	memset(prime, 0, sizeof(prime));
	memset(isprime, true, sizeof(isprime));
	for (i = 2; i < primsize; ++i)
	{
		if (isprime[i] == true)
		{
			prime[++prime[0]] = i;
			j = i * i;
			while (j < primsize)
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
T_INT modular_mul(T_INT a, T_INT b, T_INT p)// return a*b mod p
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
			return p;
		}
	}
	return n;
}

template <typename T_INT>
struct Factorization
{
	T_INT n;
	T_INT p[32];
	T_INT l[32];
	T_INT s[32];
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
			ans.p[ans.n] = prime[i];
			ans.l[ans.n] = 1;
			ans.s[ans.n] = prime[i];
			while ((m % tp) == 0)
			{
				m /= tp;
				++ans.l[ans.n];
				ans.s[ans.n] *= prime[i];
			}
			++ans.n;
		}
	}
	if (m > 1)
	{
		if (primetest(m))
		{
			ans.p[ans.n] = m;
			ans.l[ans.n] = 1;
			ans.s[ans.n] = m;
			++ans.n;
		}
		else
		{
			T_INT fz1 = Pollard(m);
			T_INT fz2 = m / fz1;
			if (fz1 == fz2)
			{
				ans.p[ans.n] = fz1;
				ans.l[ans.n] = 2;
				ans.s[ans.n] = fz1 * fz2;
				++ans.n;
			}
			else
			{
				if (fz1 > fz2)
				{
					swap(fz1, fz2);
				}
				ans.p[ans.n] = fz1;
				ans.l[ans.n] = 1;
				ans.s[ans.n] = fz1;
				++ans.n;
				ans.p[ans.n] = fz2;
				ans.l[ans.n] = 1;
				ans.s[ans.n] = fz2;
				++ans.n;
			}
		}
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
	for (i = 0; i < factors.n; ++i)
	{
		for (j = 2; j <= factors.l[i]; ++j)
		{
			ans *= factors.p[i];
		}
		ans *= factors.p[i] - 1;
	}
	return ans;
}

Factorization<long long> f;
long long a1, a2, m;
long long a, b;

void DFS(const int p, const long long s)
{
	if (p == f.n)
	{
		long long ta1 = s;
		long long ta2 = b / s;
		if (ta1 > ta2) swap(ta1, ta2);
		if ((ta2 - ta1) < m)
		{
			a1 = ta1;
			a2 = ta2;
			m = ta2 - ta1;
		}
	}
	else
	{
		DFS(p + 1, s);
		DFS(p + 1, s * f.s[p]);
	}
}

int main()
{
	prime_init();
	while (cin >> a >> b)
	{
		b /= a;
		f = Factorizate(b);
		m = b;
		DFS(0, 1);
		cout << a1 * a << " " << a2 * a << endl;
	}
	return 0;
}


