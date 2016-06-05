/*
 * Primes.cpp
 *
 *  Created on: 2011-11-15
 *      Author: acer
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void FindPrime(const int n, vector<int> *primesum)
{
	vector<bool> isprime(n, true);
	primesum->resize(n, 0);
	for (int i = 2; i < n; ++i)
	{
		if (isprime[i])
		{
			(*primesum)[i] = (*primesum)[i - 1] + 1;
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
		else
		{
			(*primesum)[i] = (*primesum)[i - 1];
		}
	}
}

int main()
{
	int a, b;
	vector<int> primesum;
	FindPrime(100001, &primesum);
	while ((cin >> a >> b), (a != -1) && (b != -1))
	{
		cout << primesum[max(0, b)] - primesum[max(0, a - 1)] << endl;
	}
	return 0;
}
