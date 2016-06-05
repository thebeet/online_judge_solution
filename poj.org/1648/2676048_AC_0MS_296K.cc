#include <iostream>

using namespace std;

int n, w, e, st, n100;

bool iscross(int t)
{
	return (((t % (n * 100)) == 0) && (t != 100 * n) && (t != 0));
}

int main()
{
	while (cin >> n >> w >> e)
	{
		int ans(n);
		n100 = n * 100;
		if (e < w)
		{
			swap(e, w);
		}
		int dx(e - w);
		w *= n;
		e *= n;
		st = w;
		for (int i(1); i <= n; ++i)
		{
			int pr(st);
			st += dx;
			ans += ((st + n100) / n100) - ((pr - 1 + n100) / n100);
			if ((st == n * n100) || (pr == 0))
			{
				--ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
