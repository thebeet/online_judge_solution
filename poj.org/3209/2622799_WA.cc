#include <iostream>
#include <cmath>

using namespace std;

unsigned long long prime[2097152];
bool isprime[2097152];

void prime_init(unsigned long long primsize = 46340)
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
struct Factors
{
	T_INT n;
	T_INT p[32];
	T_INT l[32];
};

template <typename T_INT>
Factors<T_INT> Factorizate(T_INT m)
{
	Factors<T_INT> ans;
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
	return lo + (T_INT)abs((long long)(n * sin((double)rand() * (double)rand() * (double)rand())));
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
bool primetest(T_INT p, int k = 512) //use Miller-Rabin
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

template <typename T_INT>
T_INT findminfactor(T_INT n)
{
	if (n < 60000)
	{
		return brute(n);
	}
	T_INT f = Pollard(n);
	T_INT f2 = n / f;
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
	unsigned long long ti, tn;
	unsigned long long n;
	prime_init(2097151);
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		unsigned long long i;
		cin >> n;
		if (n < 0)
		{
			cout << "NO" << endl;
			continue;
		}
		if (n == 0)
		{
			n = 1;
		}
		Factors<unsigned long long> f = Factorizate(n);
		for (i = 1; i <= f.n; ++i)
		{
			if ((f.p[i] > 2097151) || (((f.p[i] % 4) == 3) && ((f.l[i] % 2) == 1)))
			{
				break;
			}
		}
		if (i > f.n)
		{
			cout << "YES" << endl;
		}
		else
		{
			if (f.p[i] > 2097151)
			{
				if (primetest(f.p[i]))
				{
					if ((f.p[i] % 4) == 1)
					{
						cout << "YES" << endl;
					}
					else
					{
						cout << "NO" << endl;
					}
				}
				else
				{
					unsigned long long df = Pollard(f.p[i]);
					if (df * df == f.p[i])
					{
						cout << "YES" << endl;
					}
					else
					{
						if ((((f.p[i] / df) % 4) == 1) && ((df % 4) == 1))
						{
							cout << "YES" << endl;
						}
						else
						{
							cout << "NO" << endl;
						}
					}
				}
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
