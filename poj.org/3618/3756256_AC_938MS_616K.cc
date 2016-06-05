#include <iostream>
#include <algorithm>

using namespace std;

int x[65536];

bool comp(const int x1, const int x2)
{
	return abs(x1) < abs(x2);
}

int main()
{
	int i, t, n;
	cin >> t >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	sort(x, x + n, comp);
	int now = 0;
	i = 0;
	int ans = 0;
	while (t >= abs(now - x[i]))
	{
		++ans;
		t -= abs(now - x[i]);
		now = x[i];
		++i;
		
	}
	cout << ans << endl;
	return 0;
}
