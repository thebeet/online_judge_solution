#include <iostream>
#include <algorithm>

using namespace std;

int inp[128];

int main()
{
	int i, n, m, p1, p2;
	cin >> n >> m;
	for (i = 0; i < n; ++i)
	{
		cin >> inp[i];
	}
	p1 = 0;
	p2 = n - 1;
	int ans = 0;
	while (p1 <= p2)
	{
		int t1 = 1;
		int t2 = 1;
		for (i = 1; i <= m; ++i)
		{
			t1 *= inp[p1];
			t2 *= inp[p2];
		}
		if (t1 > t2)
		{
			if (t1 < 0) break;
			ans += t1;
			++p1;
		}
		else
		{
			if (t2 < 0) break;
			ans += t2;
			--p2;
		}
	}
	cout << ans << endl;
	return 0;
}
