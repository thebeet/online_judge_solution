#include <iostream>

using namespace std;

int main()
{
	int n, m, c;
	while ((cin >> n >> m >> c), n > 0)
	{
		n -= 7;
		m -= 7;
		int ans = (n ^ (n & 1)) * (m >> 1);
		if (n & 1)
		{
			ans += ((m + c) >> 1);
		}
		cout << ans << endl;
	}
	return 0;
}
