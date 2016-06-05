#include <stdio.h>
#include <string.h>

char map[510][510];

int ans[1010][1010]; 
int x[1000010];
int y[1000010];


int xend;
int yend;

int main()
{
	int i, j, n, m, tarx, tary;
	while (scanf("%d%d", &n, &m), n > 0)
	{
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(ans, 0, sizeof(ans));
		memset(map, 0, sizeof(map));
		for (i = 0; i < n; ++i)
		{
			scanf("%s", map[i]);
			for (j = 0; j < m; ++j)
			{
				if (map[i][j] == 'O')
				{
					xend = i * 2 + 1;
					yend = j * 2 + 1;
				}
				else if (map[i][j] == 'X')
				{
					x[1] = i * 2 + 1;
					y[1] = j * 2 + 1;
				}
			}
		}
		x[0] = 1;
		y[0] = 1;
		ans[x[1]][y[1]] = 1;
		while ((x[0] <= y[0]) && (ans[xend][yend] == 0))
		{
			if ((x[x[0]] & 1) == 0)
			{
				tarx = x[x[0]];
				tary = y[x[0]] + 2;
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2 + 1][tary / 2] != '#')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
				tary = y[x[0]] - 2;
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2 + 1][tary / 2] != '#')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
				tarx = x[x[0]] + 3;
				tary = y[x[0]];
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2][tary / 2] != 'E')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
				tarx = x[x[0]] - 3;
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2][tary / 2] != 'E')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
			}
			else if ((y[x[0]] & 1) == 0)
			{
				tarx = x[x[0]] + 2;
				tary = y[x[0]];
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2][tary / 2 + 1] != '#')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
				tarx = x[x[0]] - 2;
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2][tary / 2 + 1] != '#')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
				tarx = x[x[0]];
				tary = y[x[0]] + 3;
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2][tary / 2] != 'E')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
				tary = y[x[0]] - 3;
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2][tary / 2] != 'E')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
			}
			else
			{
				tarx = x[x[0]] + 3;
				tary = y[x[0]];
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2][tary / 2] != 'E')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
				tarx = x[x[0]] - 3;
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2][tary / 2] != 'E')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
				tarx = x[x[0]];
				tary = y[x[0]] + 3;
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2][tary / 2] != 'E')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
				tary = y[x[0]] - 3;
				if ((ans[tarx][tary] == 0) && (map[tarx / 2][tary / 2] != '#') && (map[tarx / 2][tary / 2] != 'E')) 
				{
					x[++y[0]] = tarx;
					y[y[0]] = tary;
					ans[tarx][tary] = ans[x[x[0]]][y[x[0]]] + 1;
				}
			}
			++x[0];
		}
		if (x[0] <= y[0])
		{
			printf("%d\n", ans[xend][yend]);
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}
