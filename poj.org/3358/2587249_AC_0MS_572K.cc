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
	for (T_INT i = 1; (i <= prime[0]) && (prime[i] <= m); ++i)
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
T_INT calc_f1(T_INT m) //2^x == 1 mod m
{
	T_INT i;
	T_INT usage[32];
	T_INT phi = euler_phi(m);
	T_INT ans = phi;
	Factorization<T_INT> f = Factorizate(phi);
	memset(usage, 0, sizeof(usage));
	T_INT x = 1;
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
			for (T_INT j = 1; j <= usage[i]; ++j)
			{
				x *= f.p[i];
			}
		}
		if ((x < ans) && (modular_exp((long long)2, x, m) == 1))
		{
			ans = x;
		}
	}
	return ans;
}

int main()
{
	prime_init();
	
	int ti = 0;
	long long n, m;
	char ch;
	while (cin >> n >> ch >> m)
	{
		long long pr = 1;
		long long g = gcd(n, m);
		n /= g;
		m /= g;
		
		printf("Case #%d: ", ++ti);
		
		pr = 1;
		while ((m & 1) == 0)
		{
			++pr;
			m >>= 1;
		}
		
		cout << pr << "," << calc_f1(m) << endl;
	}
	return 0;
}
