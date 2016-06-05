#include <iostream>
#include <algorithm>

using namespace std;

int wei[1024];

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n;
		cin >> n;
		for (i = 1; i <= n; ++i)
		{
			cin >> wei[i];
		}
		sort(wei + 1, wei + 1 + n);
		int ans = wei[1] * n;
		for (i = 2; i <= n; ++i)
		{
			ans = max(ans, wei[i] * (n - i + 1));
		}
		cout << ans << endl;
	}
	return 0;
}
