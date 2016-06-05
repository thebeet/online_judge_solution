#include <iostream>
#include <algorithm>

using namespace std;

int map[16][16];
int prem[16];

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		int i, j, k;
		for (i = 0; i <= n; ++i)
		{
			for (j = 0; j <= n; ++j)
			{
				cin >> map[i][j];
			}
		}
		for (k = 0; k <= n; ++k)
		{
			for (i = 0; i <= n; ++i)
			{
				for (j = 0; j <= n; ++j)
				{
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}
		memset(prem, 0, sizeof(prem));
		for (i = 0; i <= n; ++i)
		{
			prem[i] = i;
		}
		int minans = 2000000000;
		for (;;)
		{
			int s(0);
			for (i = 0; i <= n; ++i)
			{
				s += map[prem[i]][prem[i + 1]];
			}
			minans = min(minans, s);
			if (next_permutation(prem + 1, prem + n + 1) == false)
			{
				break;
			}
		}
		cout << minans << endl;
	}
	return 0;
}
