#include <iostream>
#include <algorithm>

using namespace std;

int pos[100010];

int main()
{
	int i, n, k;
	cin >> n >> k;
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &pos[i]);
	}
	pos[0] = -1000000010;
	sort(pos + 1, pos + 1 + n);
	int lo, hi, mid;
	lo = 0;
	hi = 1000000010;
	while (lo + 1 < hi)
	{
		int u = 0;
		mid = (lo + hi) >> 1;
		for (i = 1; i <= n; ++i)
		{
			int pr = i - 1;
			while ((pos[i] - pos[pr]) < mid)
			{
				++i;
				if (i > n)
				{
					break;
				}
			}
			if (i > n)
			{
				break;
			}
			++u;
			if (u == k)
			{
				break;
			}
		}
		if (u == k)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << lo << endl;
	return 0;
}
