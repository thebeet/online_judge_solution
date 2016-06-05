#include <cstdio>

int map[512][512];
int hashx[512][512];
int hashy[512][512];

bool check(int x, int y, int w)
{
	int i;
	int ex = x + w - 1;
	int ey = y + w - 1;
	if ((map[x][y] != map[x][ey]) ||
		(map[x][ey] != map[ex][ey]) ||
		(map[ex][ey] != map[ex][y]) ||
		(hashx[ex][y] - hashx[x][y]) != (hashx[ex][ey] - hashx[x][ey]) ||
		(hashy[x][ey] - hashy[x][y]) != (hashy[ex][ey] - hashy[ex][y]))		
	{
		return false;
	}
	for (i = 0; i < w; ++i)
	{
		if ((map[x + i][y] != map[x + i][ey]) || (map[x][y + i] != map[ex][y + i]))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int i, j, k, n;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			scanf("%d", &map[i][j]);
			hashx[i][j] = hashx[i - 1][j] + map[i][j] * i;
			hashy[i][j] = hashy[i][j - 1] + map[i][j] * j;
		}
	}
	for (k = n; k >= 1; --k)
	{
		int d = n - k + 1;
		for (i = 1; i <= d; ++i)
		{
			for (j = 1; j <= d; ++j)
			{
				if (check(i, j, k))
				{
					printf("%d %d %d\n", i, j, k);
					return 0;
				}
			}
		}
	}
	return 0;
}
