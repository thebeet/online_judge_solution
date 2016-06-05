#include <iostream>

using namespace std;

int ans[100010];

int calc(int n)
{
	if (n < 100000)
	{
		if (ans[n] == 0)
		{
			if ((n & 1) == 0)
			{
				ans[n] = calc(n >> 1) + 1;
			}
			else
			{
				ans[n] = calc(n * 3 + 1) + 1;
			}
		}
		return ans[n];
	}
	else
	{
		if ((n & 1) == 0)
		{
			return calc(n >> 1) + 1;
		}
		else
		{
			return calc(n * 3 + 1) + 1;
		}
	}
}

int main()
{
	int i;
	int f, t;
	memset(ans, 0, sizeof(ans));
	ans[1] = 1;
	for (i = 1; i <= 10000; ++i)
	{
		calc(i);
	}
	while (cin >> f >> t)
	{
		cout << f << " " << t << " ";
		if (f > t)
		{
			int tmp = f;
			f = t;
			t = tmp;
		}
		int mx = 0;
		for (i = f; i <= t; ++i)
		{
			if (ans[i] > mx)
			{
				mx = ans[i];
			}
		}
		cout << mx << endl;
	}
	return 0;
}
