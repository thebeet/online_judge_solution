#include <stdio.h>
#include <string.h>

typedef char map[32][32];

int ans;
int n, m;

map st_map;

inline int Min(int a, int b)
{
	return (a < b) ? a : b;
}

bool inmap(int x, int y)
{
	if ((x > 0) && (y > 0) && (x <= n) && (y <= m))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int dfs(map tm, int x0, int y0, int h);

int go(map tm, int x0, int y0, int dx, int dy, int h)
{
	x0 += dx;
	y0 += dy;
	if (tm[x0][y0] == 3)
	{
		return h;
	}
	if (tm[x0][y0] == 1)
	{
		return 10000;
	}
	for (x0 += dx, y0 += dy; inmap(x0, y0); x0 += dx, y0 += dy)
	{
		if (tm[x0][y0] == 3)
		{
			return h;
		}
		if (tm[x0][y0] == 1)
		{
			map newmap;
			memcpy(newmap, tm, 32 * 32);
			newmap[x0][y0] = 0;
			return dfs(newmap, x0 - dx, y0 - dy, h + 1);
		}
	}
	return 10000;
}

int dfs(map tm, int x0, int y0, int h)
{
	if (h >= ans)
	{
		return 10000;
	}
	ans = Min(ans, go(tm, x0, y0, 1, 0, h));
	ans = Min(ans, go(tm, x0, y0, 0, 1, h));
	ans = Min(ans, go(tm, x0, y0, -1, 0, h));
	ans = Min(ans, go(tm, x0, y0, 0, -1, h));
	return ans;
}

int main()
{
	memset(st_map, 0, sizeof(st_map));
	while (scanf("%d%d", &m, &n), m > 0)
	{
		int i, j;
		int x1, y1;
		
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= m; ++j)
			{
				int m;
				scanf("%d", &m);
				st_map[i][j] = m;
				if (st_map[i][j] == 2)
				{
					x1 = i;
					y1 = j;
				st_map[i][j] = 0;
				}
			}
		}
		ans = 11;
		dfs(st_map, x1, y1, 1);
		if (ans > 10)
		{
			ans = -1;
		}
		printf("%d\n", ans);
	}	
	return 0;
}
