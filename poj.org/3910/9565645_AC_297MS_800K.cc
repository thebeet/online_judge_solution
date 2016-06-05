/*
 * GCD_Determinant.cpp
 *
 *  Created on: 2011-11-15
 *      Author: acer
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

template <typename T = int>
class Z
{
public:
	Z(const T d, const T n) :
		m_d(d), m_n(n)
	{
	}

	Z &operator *=(const Z &z2)
	{
		(m_d *= z2.m_d) %= m_n;
		return *this;
	}

	T m_d;
	const T m_n;
};

void FindPrime(const int n, vector<int> *primes)
{
	vector<bool> isprime = vector<bool>(n, true);
	primes->clear();
	for (int i = 2; i < n; ++i)
	{
		if (isprime[i])
		{
			primes->push_back(i);
			if (n / i > i)
			{
				int j = i * i;
				while (j < n)
				{
					isprime[j] = false;
					j += i;
				}
			}
		}
	}
}

int Euler(const int n, const vector<int> &primes)
{
	int tn(n);
	int result(1);
	for (int i = 0; i < primes.size(); ++i)
	{
		if (tn < primes[i]) break;
		int s(0);
		while (tn % primes[i] == 0)
		{
			tn /= primes[i];
			result *= primes[i];
			++s;
		}
		if (s > 0)
		{
			(result /= primes[i]) *= (primes[i] - 1);
		}
	}
	if (tn > 1)
	{
		result *= (tn - 1);
	}
	return result;
}

int main()
{
	vector<int> primes;
	FindPrime(45000, &primes);

	for (int n; cin >> n; )
	{
		set<int> inp;
		bool flag(true);
		inp.clear();
		Z<long long> ans(1, 1000000007);
		for (int i = 0; i < n; ++i)
		{
			int a;
			cin >> a;
			if (inp.find(a) != inp.end())
			{
				flag = false;
			}
			Z<long long> ea(Euler(a, primes), 1000000007);
			ans *= ea;
		}
		if (flag)
		{
			cout << ans.m_d << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}

	return 0;
}
