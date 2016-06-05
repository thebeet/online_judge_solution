#include <iostream>

using namespace std;

int prime[65536];
const int primsize = 46340;

void prime_init()
{
	int i, j;
	memset(prime, 0, sizeof(prime));
	for (i = 2; i <= primsize; ++i)
	{
		if (prime[i] == 0)
		{
			prime[++prime[0]] = i;
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
	int n;
	int p[32];
	int l[32];
};

template <typename T_INT>
Factorization Factorizate(T_INT m)
{
	Factorization ans;
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
	int i;
	int usage[32];
	T_INT phi = euler_phi(m);
	int ans = phi;
	Factorization f = Factorizate(phi);
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
bool primetest(T_INT p, int k = 50)
{
	return 0;
}

int main()
{
	int i, n;
	prime_init();
	while ((cin >> n), n > 0)
	{
		int ans = 0;
		Factorization f = Factorizate(n);
		for (i = 1; i <= f.n; ++i)
		{
			ans = gcd(ans, f.l[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
