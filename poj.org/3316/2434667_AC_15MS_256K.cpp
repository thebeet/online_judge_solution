#include <stdio.h>
#include <memory.h>

struct snake
{
	int x1, y1;
	int x2, y2;
	int tp;
};

char map[210][210];
int s[210][210];
int n, m;

bool check(int x, int y)
{
	if ((x > 1) && (map[x - 1][y] == '0') && (s[x - 1][y] == 1))
	{
		return true;
	} 
	if ((y > 1) && (map[x][y - 1] == '0') && (s[x][y - 1] == 1))
	{
		return true;
	} 
	if ((x < n) && (map[x + 1][y] == '0') && (s[x + 1][y] == 1))
	{
		return true;
	} 
	if ((y < m) && (map[x][y + 1] == '0') && (s[x][y + 1] == 1))
	{
		return true;
	}
	return false;
}

int main()
{
	while (scanf("%d%d", &n, &m), n > 0)
	{
		int i, j, ans;
		
		ans = 0;
		
		memset(map, '0', sizeof(map));
		for (i = 1; i <= n; ++i)
		{
			scanf("%s", map[i] + 1);
			map[i][m + 1] = '0';
		}
		
		memset(s, 3, sizeof(s));
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= m; ++j)
			{
				s[i][j] = map[i - 1][j] + map[i][j - 1] + map[i + 1][j] + map[i][j + 1] - 4 * '0';
			}
		}
		
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= m; ++j)
			{
				if (map[i][j] == '1') 
				{
					if (s[i][j] == 0)
					{
						if (check(i, j) == false)
						{
							++ans;
						}
					}
					else
					{
						if (s[i][j] == 1)
						{
							int x, y;
							if (check(i, j) == true)
							{
								continue;
							}
							x = i;
							y = j;
							do
							{
								map[x][y] = '2';
								if (map[x + 1][y] == '1')
								{
									++x;
								}
								else if (map[x - 1][y] == '1')
								{
									--x;
								}
								else if (map[x][y + 1] == '1')
								{
									++y;
								}
								else if (map[x][y - 1] == '1') 
								{
									--y;
								}
							}while (s[x][y] == 2);
							if (s[x][y] > 2)
							{
								continue;
							}
							s[x][y] = 3;
							if (check(x, y) == false)
							{
								++ans;
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
