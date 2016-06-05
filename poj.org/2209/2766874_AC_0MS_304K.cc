#include <iostream>

using namespace std;

int inp[128];

int main()
{
	int i, j, n, m, ans;
	ans = 0;
	cin >> n >> m;
	for (i = 0; i < n; ++i)
	{
		cin >> inp[i];
		int t = 1;
		for (j = 1; j <= m; ++j)
		{
			t *= inp[i];
		}
		if (t > 0) ans += t;
	}
	cout << ans << endl;
	return 0;
}
