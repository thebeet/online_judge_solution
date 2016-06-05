#include <stdio.h>
#include <memory.h>

int main()
{
	int i, j, n, m, x, y;
	int map[128][128];
	bool flag;
	bool use[128];
	
	flag = true;
	
	scanf("%d", &n);
	m = n * n;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] > n)
			{
				flag = false;
			}
		}
	}
	for (i = 1; i <= m; i++)
	{
		memset(use, false, sizeof(use));
		for (j = 1; j <= m; j++)
		{
			if ((use[map[j][i]]) && (map[j][i] > 0))
			{
				flag = false;
			}
			else
			{
				use[map[i][j]] = true;
			}
		}
	}
	for (i = 1; i <= m; i++)
	{
		memset(use, false, sizeof(use));
		for (j = 1; j <= m; j++)
		{
			if ((use[map[j][i]]) && (map[j][i] > 0))
			{
				flag = false;
			}
			else
			{
				use[map[j][i]] = true;
			}
		}
	}
	for (i = 1; i <= m; i += n)
	{
		for (j = 1; j <= m; j += n)
		{
			memset(use, false, sizeof(use));
			for (x = i; x <= i + n - 1; x++)
			{
				for (y = j; y <= j + n - 1; y++)
				{
					if ((use[map[x][y]]) && (map[x][y] > 0))
					{
						flag = false;
					}
					else
					{
						use[map[x][y]] = true;
					}
				}
			}
		}
	}
	if (flag)
	{
		printf("CORRECT\n");
	}
	else
	{
		printf("INCORRECT\n");
	}
	return 0;
}
