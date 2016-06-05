#include <iostream>
#include <cmath>

using namespace std;

int prs[1048576];
int sprs[1048576];
bool isprime[1048576];
bool issquare[1048576];

void prime_init(unsigned long long primsize = 1000000) //2097152
{
	unsigned long long i, j;
	memset(isprime, true, sizeof(isprime));
	for (i = 2; i <= primsize; ++i)
	{
		if (isprime[i] == true)
		{
			j = i * i;
			while (j <= primsize)
			{
				isprime[j] = false;
				j += i;
			}
		}
	}
}

int main()
{
	memset(issquare, false, sizeof(issquare));
	prime_init();
	for (int i = 0; i <= 1000; ++i)
	{
		int si = i * i;
		for (int j = i; j <= 1000; ++j)
		{
			int sj = j * j;
			int ssum = sj + si;
			if (ssum > 1000000) break;
			issquare[ssum] = true;
		}
	}
	prs[0] = prs[1] = 0;
	sprs[0] = sprs[1] = 0;
	for (int i = 2; i <= 1000000; ++i)
	{
		prs[i] = (isprime[i] ? (prs[i - 1] + 1) : prs[i - 1]);
		sprs[i] = ((isprime[i] && issquare[i]) ? (sprs[i - 1] + 1) : sprs[i - 1]);
	}
	int L, U;
	while ((cin >> L >> U), ((L != -1) && (U != -1)))
	{
		cout << L << " " << U << " " << prs[U] - prs[L - 1] << " " << sprs[U] - sprs[L - 1] << endl;
	}
	return 0;
}
