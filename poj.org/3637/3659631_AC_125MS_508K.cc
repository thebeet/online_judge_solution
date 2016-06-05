#include <iostream>
#include <algorithm>

using namespace std;

int value[65536];

int main()
{
	int tn;
	cin >> tn;
	while (tn--)
	{
		int i, n;
		cin >> n;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &value[i]);
		}
		sort(value, value + n);
		int ans(0);
		for (i = n - 3; i >= 0; i -= 3)
		{
			ans += value[i];
		}
		cout << ans << endl;
	}
	return 0;
}
