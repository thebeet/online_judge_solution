#include <iostream>
#include <algorithm>

using namespace std;

long long pos[10010];

int main()
{
	int i, n;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> pos[i];
	}
	sort(pos, pos + n);
	long long ans, d;
	ans = 0;
	d = pos[0];
	for (i = 1; i < n; ++i)
	{
		ans += pos[i] * i - d;
		d += pos[i];
	}
	cout << (ans << 1) << endl;
	return 0;
}
