#include <iostream>
#include <algorithm>

using namespace std;

int n;

int net[2][128][128];
int netans[2][128];

void floyd(int kind)
{
	int i, j, k;
	for (k = 1; k <= n; ++k)
	{
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= n; ++j)
			{
				net[kind][i][j] = min(net[kind][i][j], net[kind][i][k] + net[kind][k][j]);
			}
		}
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (net[kind][i][j] <= n)
			{
				++netans[kind][i];
			}
		}
	}
}
int main()
{
	int i, j, m;
	cin >> n >> m;
	memset(net, 1, sizeof(net));
	memset(netans, 0, sizeof(netans));
	for (int i = 1; i <= n; ++i)
	{
		net[0][i][i] = 0;
		net[1][i][i] = 0;
	}
	for (i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		net[0][a][b] = 1;
		net[1][b][a] = 1;
	}
	floyd(0);
	floyd(1);
	int ans(0);
	for (int i = 1; i <= n; ++i)
	{
		//cout << netans[0][i]  << " " << netans[1][i]  << endl;
		if (netans[0][i] + netans[1][i] == n + 1)
		{
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
