#include <iostream>
#include <algorithm>

using namespace std;

int h[65536];

int main()
{
	int n, m, i;
	cin >> n;
	cin >> m;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", h + i);
	}
	sort(h, h + n);
	int ans(0);
	for (int j = n - 1; m > 0; --j)
	{
		++ans;
		m -= h[j];
	}
	cout << ans << endl;
}