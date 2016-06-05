#include <stdio.h>
#include <string.h>

int w, h;
char map[1024][128];
int queuex[100010];
int queuey[100010];

int floodfill(int x, int y)
{
	map[x][y] = '.';
	queuex[0] = 1;
	queuex[1] = x;
	queuey[1] = y;
	for (int i = 1; i <= queuex[0]; ++i)
	{
		int tx = queuex[i];
		int ty = queuey[i];
		tx = queuex[i] + 1;
		if (map[tx][ty] == '*')
		{
			map[tx][ty] = '.';
			queuex[++queuex[0]] = tx;
			queuey[queuex[0]] = ty;
		}
		tx = queuex[i] - 1;
		if (map[tx][ty] == '*')
		{
			map[tx][ty] = '.';
			queuex[++queuex[0]] = tx;
			queuey[queuex[0]] = ty;
		}
		tx = queuex[i];
		ty = queuey[i] + 1;
		if (map[tx][ty] == '*')
		{
			map[tx][ty] = '.';
			queuex[++queuex[0]] = tx;
			queuey[queuex[0]] = ty;
		}
		ty = queuey[i] - 1;
		if (map[tx][ty] == '*')
		{
			map[tx][ty] = '.';
			queuex[++queuex[0]] = tx;
			queuey[queuex[0]] = ty;
		}
	}
	return queuex[0];
}

int main()
{
	int i, j;
	scanf("%d%d", &w, &h);
	memset(map, '.', sizeof(map));
	
	for (i = 1; i <= h; ++i)
	{
		scanf("%s", map[i] + 1);
	}
	
	int ans = 0;
	for (i = 1; i <= h; ++i)
	{
		for (j = 1;j <= w; ++j)
		{
			if (map[i][j] == '*')
			{
				int ret = floodfill(i, j);
				if (ret > ans)
				{
					ans = ret;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
