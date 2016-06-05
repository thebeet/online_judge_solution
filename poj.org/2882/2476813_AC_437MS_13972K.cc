#include <stdio.h>
#include <string.h>

bool map3d[110][110][110];

int xx[1100010];
int yy[1100010];
int zz[1100010];

void floodfill(int x, int y, int z)
{
	int gx, gy, gz;
	xx[0] = 1;
	xx[1] = x;
	yy[1] = y;
	zz[1] = z;
	map3d[x][y][z] = true; 
	for (int i = 1; i <= xx[0]; ++i)
	{
		gx = xx[i] + 1;
		gy = yy[i];
		gz = zz[i];
		if (gx <= 101)
		{
			if (map3d[gx][gy][gz] == false)
			{
				map3d[gx][gy][gz] = true;
				++xx[0];
				xx[xx[0]] = gx;
				yy[xx[0]] = gy;
				zz[xx[0]] = gz;
			}
		}
		gx = xx[i] - 1;
		gy = yy[i];
		gz = zz[i];
		if (gx >= 0)
		{
			if (map3d[gx][gy][gz] == false)
			{
				map3d[gx][gy][gz] = true;
				++xx[0];
				xx[xx[0]] = gx;
				yy[xx[0]] = gy;
				zz[xx[0]] = gz;
			}
		}
		gx = xx[i];
		gy = yy[i] + 1;
		gz = zz[i];
		if (gy <= 101)
		{
			if (map3d[gx][gy][gz] == false)
			{
				map3d[gx][gy][gz] = true;
				++xx[0];
				xx[xx[0]] = gx;
				yy[xx[0]] = gy;
				zz[xx[0]] = gz;
			}
		}
		gx = xx[i];
		gy = yy[i] - 1;
		gz = zz[i];
		if (gy >= 0)
		{
			if (map3d[gx][gy][gz] == false)
			{
				map3d[gx][gy][gz] = true;
				++xx[0];
				xx[xx[0]] = gx;
				yy[xx[0]] = gy;
				zz[xx[0]] = gz;
			}
		}
		gx = xx[i];
		gy = yy[i];
		gz = zz[i] + 1;
		if (gz <= 101)
		{
			if (map3d[gx][gy][gz] == false)
			{
				map3d[gx][gy][gz] = true;
				++xx[0];
				xx[xx[0]] = gx;
				yy[xx[0]] = gy;
				zz[xx[0]] = gz;
			}
		}
		gx = xx[i];
		gy = yy[i];
		gz = zz[i] - 1;
		if (gz >= 0)
		{
			if (map3d[gx][gy][gz] == false)
			{
				map3d[gx][gy][gz] = true;
				++xx[0];
				xx[xx[0]] = gx;
				yy[xx[0]] = gy;
				zz[xx[0]] = gz;
			}
		}
	}
}

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 1; ti <= tn; ++ti)
	{
		int i, n, x, y, z, ans;
		
		memset(map3d, false, sizeof(map3d));
		ans = 0;
		
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d%d%d", &x, &y, &z);
			map3d[x][y][z] = true;
		}
		
		for (x = 1; x <= 100; ++x)
		{
			for (y = 1; y <= 100; ++y)
			{
				for (z = 1; z <= 100; ++z)
				{
					if (map3d[x][y][z] == false)
					{
						++ans;
						floodfill(x, y, z);
					}
				}
			}
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}
