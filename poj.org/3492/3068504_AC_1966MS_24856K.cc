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

bool dp[25005000];

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
			scanf("%d", &item[i]);
			if (i == 0) g = item[0];
			else g = gcd(g, item[i]);
			minitem = min(minitem, item[i]);
		}
		if (g != 1)
		{
			cout << "INF" << endl;
			continue;
		}
		int os(0);
		int ans(0);
		memset(dp, false, sizeof(dp));
		dp[5000] = true;
		for (i = minitem; os < minitem; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				if (dp[i - item[j] + 5000]) break;
			}
			if (dp[i + 5000] = (j < n)) ++os;
			else { ans = i; os = 0;}
		}
		cout << ans << endl;
	}
	return 0;
}
