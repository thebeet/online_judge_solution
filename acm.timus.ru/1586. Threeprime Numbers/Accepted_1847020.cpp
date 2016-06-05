#include <iostream>
#include <algorithm>

using namespace std;

const long long pp = 1000000009;

bool isprime[1024];
long long prime[1024];
long long dp[2][1024];

void prime_init()
{
	long long i, j;
	memset(isprime, true, sizeof(isprime));
	isprime[0] = false;
	isprime[1] = true;
	for (i = 2; i < 1000; ++i)
	{
		if (isprime[i])
		{
			j = i * i;
			while (j < 1000)
			{
				isprime[j] = false;
				j += i;
			}
		}
	}
	for (i = 0; i < 100; ++i)
	{
		isprime[i] = false;
	}
}

int main()
{
	///*
	int i, j, k, n;
	prime_init();
	cin >> n;
 	memset(prime, 0, sizeof(prime));
	for (i = 100; i < 1000; ++i)
	{
		if (isprime[i])
		{
			prime[++prime[0]] = i;
			++dp[0][i % 100];
		}
	}
	int p0(0), p1(1);
	for (i = 3; i < n; ++i)
	{
		memset(dp[p1], 0, sizeof(dp[p1]));
		for (j = 10; j < 100; ++j)
		{
			if (dp[p0][j] > 0)
			{
				for (k = 0; k < 10; ++k)
				{
					int tar = j * 10 + k;
					if (isprime[tar])
					{
						(dp[p1][(tar % 100)] += dp[p0][j]) %= pp;
					}
				}
			}
		}
		p0 ^= 1;
		p1 ^= 1;
	}
	int ans = 0;
	for (j = 1; j < 100; ++j)
	{
		(ans += dp[p0][j]) %= pp;
	}
	cout << ans << endl;
	return 0;
	//*/
	prime_init();
	int s = 0;
	for (int i = 10000; i < 100000; ++i)
	{
		if ((isprime[i % 1000]) && (isprime[(i / 10) % 1000]) && (isprime[(i / 100) % 1000]))
		{
			++s;
		}
	}
	cout << s << endl;
	return 0;
}
