#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int hei[32768];
int bhei[32768];

int main()
{
	int i, n, m, ans, ansp;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &hei[i]);
		hei[i] %= m;
	}
	sort(hei + 1, hei + n + 1);
	ans = 0;
	ansp = 0;
	for (i = 1; i <= n; ++i)
	{
		int t = hei[i] * n - (i - 1) * m;
		if (t >= ans)
		{
			ans = t;
			ansp = i;
		}
	}
	printf("%d\n", (m - hei[ansp]) % m);
	return 0;
}
