#include <cstdio>
#include <cstring>

char map[32][32];

int qx[1024];
int qy[1024];
int diss[32][32];
int tx[4] = {0, 1, 0, -1};
int ty[4] = {1, 0, -1, 0};

bool go(int x, int y, int disp)
{
	if ((map[x][y] == '.') && (diss[x][y] == 0))
	{
		diss[x][y] = disp;
		qx[++qx[0]] = x;
		qy[qx[0]] = y;
		return true;
	}
	return false;
}

int bfs(int x0, int y0, int xe, int ye)
{
	int i;
	memset(diss, 0, sizeof(diss));
	qx[0] = 1;
	qx[1] = x0;
	qy[1] = y0;
	diss[x0][y0] = 1;
	for (i = 1; diss[xe][ye] == 0; ++i)
	{
		int disp = diss[qx[i]][qy[i]] + 1;
		go(qx[i] + 1, qy[i], disp);
		go(qx[i] - 1, qy[i], disp);
		go(qx[i], qy[i] + 1, disp);
		go(qx[i], qy[i] - 1, disp);
	}
	return diss[xe][ye];
}

int turn(int x0, int y0, int xe, int ye, int isleft)
{
	int ans;
	int tw = 1;
	memset(diss, 0, sizeof(diss));
	for (ans = 1; (x0 != xe) || (y0 != ye); ++ans)
	{
		tw -= isleft;
		if (tw == -1)
		{
			tw = 3;
		}
		else if (tw == 4)
		{
			tw = 0;
		}
		while (go(x0 + tx[tw], y0 + ty[tw], 0) == false)
		{
			tw += isleft;
			if (tw == -1)
			{
				tw = 3;
			}
			else if (tw == 4)
			{
				tw = 0;
			}
		}
		x0 += tx[tw];
		y0 += ty[tw];
	}
	return ans;
}

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j;
		int n, m;
		int x0, y0;
		int xe, ye;
		scanf("%d%d", &m, &n);
		memset(map, '#', sizeof(map));
		for (i = 1; i <= n; ++i)
		{
			scanf("%s", map[i] + 1);
			for (j = 1; j <= m; ++j)
			{
				if (map[i][j] == 'S')
				{
					x0 = i;
					y0 = j;
					map[i][j] = '.';
				}
				if (map[i][j] == 'E')
				{
					xe = i;
					ye = j;
					map[i][j] = '.';
				}
			}
		}
		printf("%d %d %d\n", turn(x0, y0, xe, ye, 1), turn(x0, y0, xe, ye, -1), bfs(x0, y0, xe, ye));
	}
	return 0;
}
