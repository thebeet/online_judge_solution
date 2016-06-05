#include <iostream>
#include <algorithm>

using namespace std;

const int pp = 1000000009;

bool isprime[1024];
int prime[1024];
int dp[2][1024];

void prime_init()
{
	int i, j;
	memset(isprime, true, sizeof(isprime));
	isprime[0] = false;
	isprime[1] = false;
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
}

int main()
{
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
}
