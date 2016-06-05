#include <iostream>
#include <algorithm>

using namespace std;

struct coin
{
	int value;
	int num;
}coins[32];

bool operator < (const coin &c1, const coin &c2)
{
	return (c1.value < c2.value);
}

int main()
{
	int i, n, c, ans;
	ans = 0;
	cin >> n >> c;
	for (int i = 1; i <= n; ++i)
	{
		cin >> coins[i].value >> coins[i].num;
	}
	sort(coins + 1, coins + 1 + n);
	for ( ; ;)
	{
		int s = 0;
		int usage[32];
		memset(usage, 0, sizeof(usage));
		for (i = n; i >= 1; --i)
		{
			while ((usage[i] < coins[i].num) && ((s + coins[i].value) < c))
			{
				++usage[i];
				s += coins[i].value;
			}
		}
		for (i = 1; i <= n; ++i)
		{
			if ((usage[i] < coins[i].num) && ((s + coins[i].value) >= c))
			{
				++usage[i];
				break;
			}
		}
		if (i > n)
		{
			break;
		}
		int mx = 2000000000;
		for (i = 1; i <= n; ++i)
		{
			if (usage[i] > 0)
			{
				mx = min(mx, coins[i].num / usage[i]);
			}
		}
		for (i = 1; i <= n; ++i)
		{
			coins[i].num -= usage[i] * mx;
		}
		ans += mx;
	}
	cout << ans << endl;
	return 0;
}
