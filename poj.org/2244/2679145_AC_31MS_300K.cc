#include <iostream>

using namespace std;

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		int ans;
		--n;
		for (ans = 1; ; ++ans)
		{
			int i;
			int s = 0;
			for (i = 2; i <= n; ++i)
			{
				(s += ans) %= i;
			}
			if (s == 0)
			{
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
