/*
 * USTC_7::The_Luckies_number.cpp
 *
 *  Created on: Sep 29, 2008 1:00:20 PM
 *      Author: TheBeet
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU Affero General Public License as
 *	published by the Free Software Foundation, either version 3 of the
 *	License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Affero General Public License for more details.
 *
 *	You should have received a copy of the GNU Affero General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <algorithm>

using namespace std;


const long long hiprime = 47000;

long long prime[850000];

void prime_init(long long primsize = hiprime)
{
	long long i, j;
	bool *isprime = new bool[hiprime];
	memset(prime, 0, sizeof(prime));
	memset(isprime, true, hiprime);
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
	delete [] isprime;
}

template <typename T_INT>
T_INT modular_mul(const T_INT &a, const T_INT &b, const T_INT &p)// return a^b mod p
{
	T_INT ans(0);
	T_INT ta(a);
	T_INT tb(b);
	while (tb > 0)
	{
		if ((tb % (T_INT)2) == (T_INT)1)
		{
			ans = (ans + ta) % p;
		}
		ta = (ta + ta) % p;
		tb /= (T_INT)2;
	}
	return ans;
}

template <typename T_INT>
T_INT modular_exp(const T_INT &a, const T_INT &b, const T_INT &p)// return a^b mod p
{
	T_INT ans(1);
	T_INT ta(a);
	T_INT tb(b);
	while (tb > 0)
	{
		if ((tb % (T_INT)2) == (T_INT)1)
		{
			ans = modular_mul(ans, ta, p);
			//ans = (ans * ta) % p;
		}
		//ta = (ta * ta) % p;
		ta = modular_mul(ta, ta, p);
		tb /= (T_INT)2;
	}
	return ans;
}

long long p[64];
long long l[64];
int s;

long long fac(const long long n)
{
	long long tn(n);
	s = 0;
	long long ans(1);
	memset(p, 0, sizeof(s));
	memset(l, 0, sizeof(l));
	for (long long i = 1; i <= prime[0]; ++i)
	{
		if (prime[i] * prime[i] > tn)
		{
			break;
		}
		if ((tn % prime[i]) == 0)
		{
			++s;
			p[s] = prime[i];
			ans *= (prime[i] - 1);
			tn /= prime[i];
			l[s] = 1;
			while ((tn % prime[i]) == 0)
			{
				tn /= prime[i];
				ans *= prime[i];
				++l[s];
			}
		}
	}
	if (tn > 1)
	{
		++s;
		p[s] = tn;
		ans *= (tn - 1);
		l[s] = 1;
	}
	return ans;
}

int main()
{
	long long n;
	int ti(0);
	prime_init();
	while ((cin >> n), n > 0)
	{
		cout << "Case " << ++ti << ": ";
		if ((n & 1) == 0) n >>= 1;
		if ((n & 1) == 0) n >>= 1;
		if ((n & 1) == 0) n >>= 1;
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		if (((n % 2) == 0) || ((n % 5) == 0))
		{
			cout << 0 << endl;
			continue;
		}
		if ((n % 3) == 0)
		{
			n *= 9;
		}
		long long eul = fac(n);
		long long tans(0x7fffffff);
		for (long long i = 1; i * i <= eul; ++i)
		{
			if ((eul % i) == 0)
			{
				if ((tans > i) && (modular_exp(10LL, i, n) == 1))
				{
					tans = i;
				}
				if ((tans > (eul / i)) && (modular_exp(10LL, eul / i, n) == 1))
				{
					tans = eul / i;
				}
			}
		}
		cout << tans << endl;
	}
}
