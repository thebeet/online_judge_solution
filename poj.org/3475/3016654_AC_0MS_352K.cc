#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long a, b, c, d, ans;
	while (cin >> a >> b >> c >> d)
	{
		if (a < b) swap (a, b);
		if (c < d) swap (c, d);
		ans = 0;
		while (a < c)
		{
			a <<= 1;
			++ans;
		}
		while (b < d)
		{
			b <<= 1;
			++ans;
		}
		cout << ans << endl;
	}
	return 0;
}
