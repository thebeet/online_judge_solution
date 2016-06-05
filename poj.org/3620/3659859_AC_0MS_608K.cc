#include <iostream>
#include <algorithm>

using namespace std;

int lake[128][128];

int n, m, k;

int s(int x, int y)
{
	if (lake[x][y] == 0) return 0;
	lake[x][y] = 0;
	return 1 + s(x - 1, y) + s(x + 1, y) + s(x, y - 1) + s(x, y + 1);
}

int main()
{
	int x, y;
	cin >> n >> m >> k;
	memset(lake, 0, sizeof(lake));
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%d", &x, &y);
		lake[x][y] = 1;
	}
	int ans(0);
	for (int x = 1; x <= n; ++x)
	{
		for (int y = 1; y <= m; ++y)
		{
			ans = max(ans, s(x, y));
		}
	}
	cout << ans << endl;
	return 0;
}