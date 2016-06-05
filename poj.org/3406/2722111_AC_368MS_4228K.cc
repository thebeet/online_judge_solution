#include <iostream>
#include <algorithm>

using namespace std;

int prime[1000010];
int dd[16];

int calc(int n, int p)
{
	int s = 0;
	for ( ; ; )
	{
		n /= p;
		s += n;
		if (n < p)
		{
			return s;
		}
	}
}

int main()
{
	int i, j;
	prime[0] = 0;
	for (i = 2; i <= 1000; ++i)
	{
		if (prime[i] == 0)
		{
			prime[++prime[0]] = i;
			j = i * i;
			while (j < 1000000)
			{
				prime[j] = 1;
				j += i;
			}
		}
	}
	for ( ; i < 1000000; i += 2)
	{
		if (prime[i] == 0)
		{
			prime[++prime[0]] = i;
		}
	}
	prime[++prime[0]] = 100000000;
	int n, m;
	cin >> n >> m;
	int s2 = calc(n, 2) - calc(m, 2) - calc(n - m, 2);
	int s5 = calc(n, 5) - calc(m, 5) - calc(n - m, 5);
	if (s5 > s2)
	{
		cout << 5 << endl;
	}
	else
	{
		int ans = 1;
		for (i = 1; prime[i] <= n; ++i)
		{
			int p = prime[i];
			int pp = p % 10;
			int s;
			if ((pp == 3) || (pp == 7) || (pp == 9))
			{
				s = calc(n, p) - calc(m, p) - calc(n - m, p);
				dd[pp] += s;
			}
		}
		s2 -= s5;
		if (s2 > 16)
		{
			s2 = (s2 - 8) % 4 + 8;
		}
		dd[2] = s2;
		for (int k = 2; k <= 9; ++k)
		{
			dd[k] &= 3;
			for (i = 1; i <= dd[k]; ++i)
			{
				(ans *= k) %= 10;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
