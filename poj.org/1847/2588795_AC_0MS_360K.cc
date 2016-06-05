#include <iostream>

using namespace std;

int tmap[128][128];

int main()
{
	int i, j, k, n, a, b;
	cin >> n >> a >> b;
	memset(tmap, 1, sizeof(tmap));
	for (i = 1; i <= n; ++i)
	{
		int m, t;
		cin >> m;
		for (j = 1; j <= m; ++j)
		{
			cin >> t;
			tmap[i][t] = ((j == 1) ? 0 : 1);
		}
	}
	for (k = 1; k <= n; ++k)
	{
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= n; ++j)
			{
				if (tmap[i][j] > tmap[i][k] + tmap[k][j])
				{
					tmap[i][j] = tmap[i][k] + tmap[k][j];
				}
			}
		}
	}
	if (tmap[a][b] < 128)
	{
		cout << tmap[a][b] << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	return 0;
}
