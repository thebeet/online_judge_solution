#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, m;
	while (cin >> n >> k >> m)
	{
		if (n == 0) break;
		int ans(0);
		for (int i = 1; i <= n; ++i)
		{
			(ans += k) %= i;
		}
		(ans += m) -= k;
		((ans %= n) += n) %= n;
		cout << ans + 1 << endl;
	}
	return 0;
}
