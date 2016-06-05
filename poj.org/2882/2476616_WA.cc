#include <stdio.h>
#include <string.h>

bool map3d[110][110][110];

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
		
		for (x = 2; x <= 99; ++x)
		{
			for (y = 2; y <= 99; ++y)
			{
				for (z = 2; z <= 99; ++z)
				{
					if ((map3d[x][y][z] == false) &&
						(map3d[x + 1][y][z]) &&
						(map3d[x][y + 1][z]) &&
						(map3d[x][y][z + 1]) &&
						(map3d[x][y][z - 1]) &&
						(map3d[x][y - 1][z]) &&
						(map3d[x - 1][y][z]))
					{
						++ans;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
