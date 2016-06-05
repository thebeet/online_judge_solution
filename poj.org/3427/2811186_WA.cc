#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int hei[32768];
int bhei[32768];

int main()
{
	int i, n, m;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &hei[i]);
		hei[i] %= m;
	}
	sort(hei + 1, hei + n + 1);
	printf("%d\n", m - hei[n / 2]);
	return 0;
}
