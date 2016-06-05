#include <iostream>
#include <algorithm>

int step = 5010;

using namespace std;

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

int main()
{
	int n;
	while (cin >> n)
	{
		int i, j;
		int item[512];
		int minitem(10000000);
		int g(0);
		for (i = 0; i < n; ++i)
		{
			cin >> item[i];
			if (i == 0) g = item[0];
			else g = gcd(g, item[i]);
			minitem = min(minitem, item[i]);
		}
		if (g != 1)
		{
			cout << "INF" << endl;
			continue;
		}
		bool dp[10010];
		int os(1);
		int ans(0);
		memset(dp, false, sizeof(dp));
		dp[0] = true;
		for (i = 1; os < 10000; ++i)
		{
			int ip = i % 10003;
			if (dp[ip]) --os;
			for (j = 0; j < n; ++j)
			{
				if (dp[(i + 10003 - item[j]) % 10003]) break;
			}
			dp[ip] = (j < n);
			if (dp[ip]) ++os;
			else ans = i;
		}
		cout << ans << endl;
	}
	return 0;
}
