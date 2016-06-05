#include <iostream>
#include <algorithm>

using namespace std;

int wheel[1024];

int main()
{
	int n;
	cin >> n;
	int ans(0);
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;
		++wheel[m];
	}
	for (int i = 600; i <= 700; ++i)
	{
		ans += (wheel[i] / 4);
	}
	cout << ans << endl;
	return 0;
}
