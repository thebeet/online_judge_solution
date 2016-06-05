#include <iostream>
#include <cmath>

using namespace std;

int prime[65536];

void prime_init(int primsize = 46340)
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
int myrand(T_INT lo, T_INT hi)
{
	T_INT n = hi - lo + 1;
	return lo + abs((T_INT)(n * sin((double)rand() * (double)rand() * (double)rand())));
}

/*
template <typename T_INT>
bool Miller_Rabin(T_INT p, T_INT k)
{
	T_INT ans = 1;
	T_INT t = k;
	T_INT b = p - 1;
	for ( ; ; )
	{
		if ((b & 1) == 1)
		{
			ans = modular_mul(ans, t, p);
		}
		b >>= 1;
		if (b > 0)
		{
			t = modular_mul(t, t, p);
			if (modular_mul(ans, ans, p) == 1)
			{
				
			}
		}
		else
		{
			return (ans == 1);
		}
	}
}

template <typename T_INT>
bool primetest(T_INT p, int k = 50) //use Miller-Rabin
{
	int i;
	const T_INT minprime = 223092870; // 2 * 3 * 5 * 7 * 11 * 13 * 17 * 23
	if (gcd(p, minprime) > 1)
	{
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
*/

template <typename T_INT>
T_INT Pollard_rho(T_INT n)   
{   
	T_INT i = 1;   
	T_INT x = myrand((long long)1, n - 1);
	T_INT y = x;   
	T_INT k = 2;
	T_INT d;
	while   (k < 1048576)   
	{   
		++i;   
		x = modular_mul(x, x, n);
		++x;
		d = gcd(n, y - x);   
		  
		if((d != 1) && (d != n))   
		{   
			if (n / d > d)
			{
				return d;
			}
			else
			{
				return n / d;
			}
		}   
		  
		if(i == k)   
		{   
			y = x;   
			k <<= 1;   
		}   
	}
	return n;
}

int main()
{
	int ti, tn;
	long long n, f, pn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		cin >> n;
		pn = n;
		while (f = Pollard_rho(pn), f != pn)
		{
			pn = f;
		}
		if (n == pn)
		{
			cout << "Prime" << endl;
		}
		else
		{
			cout << f << endl;
		}
	}
	return 0;
}
