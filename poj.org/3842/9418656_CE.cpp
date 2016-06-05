#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int N = 10000000;
bool isprime[N];
bool backisprime[N];
int main()
{
	memset(isprime, true, sizeof(isprime));
	isprime[0] = false;
	isprime[1] = false;
	for (int i = 2; i * i < N; ++i)
	{
		if (isprime[i])
		{
			int j = i * i;
			while (j < N)
			{
				isprime[j] = false;
				j += i;
			}
		}
	}

	int tn;
	cin >> tn;
	memcpy(backisprime, isprime, sizeof(bool) * N);
	for (int ti = 0; ti < tn; ++ti)
	{
		memcpy(isprime, backisprime, sizeof(bool) * N);
		string inp;
		cin >> inp;
		int perm[inp.size()];
		for (int i = 0; i < inp.size(); ++i)
		{
			perm[i] = i;
		}
		int result(0);
		do
		{
			int d(0);
			for (int i = 0; i < inp.size(); ++i)
			{
				(d *= 10) += (inp[perm[i]] - '0');
				if (isprime[d])
				{
					isprime[d] = false;
					++result;
				}
			}
		}while (next_permutation(perm, perm + inp.size()));
		cout << result << endl;
	}	
}
