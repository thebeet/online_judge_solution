#include <iostream>

using namespace std;

long long prime[2097152];
bool isprime[65536];

void prime_init(unsigned long long primsize = 46340) //2097152
{
	unsigned long long i, j;
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

int main()
{
	prime_init();
	long long n;
	while (cin >> n)
	{
		long long i, j, ans, t, t2;
		Factorization<long long> f = Factorizate(n);
		ans = 1;
		for (i = 1; i <= f.n; ++i)
		{
			t = f.p[i] * 2 - 1;
			t2 = f.p[i] - 1;
			for (j = 2; j <= f.l[i]; ++j)
			{
				t2 *= f.p[i];
				(t *= f.p[i]) += t2;
			}
			ans *= t;
		}
		cout << ans << endl;
	}
}
