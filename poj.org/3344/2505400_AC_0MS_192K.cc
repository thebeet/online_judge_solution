#include <stdio.h>
#include <string.h>

char map[16][16];

char action[16];

int x, y;
int dx, dy;

void findstart()
{
	for (int i = 1; i <= 8; ++i)
	{
		for (int j = 1; j <= 8; ++j)
		{
			if (map[i][j] == '^') 
			{
				x = i;
				y = j;
				dx = -1;
				dy = 0;
			}
			if (map[i][j] == 'v') 
			{
				x = i;
				y = j;
				dx = 1;
				dy = 0;
			}
			if (map[i][j] == '<') 
			{
				x = i;
				y = j;
				dx = 0;
				dy = -1;
			}
			if (map[i][j] == '>') 
			{
				x = i;
				y = j;
				dx = 0;
				dy = 1;
			}
		}
	}
}

void turnleft()
{
	int tdx = dx;
	int tdy = dy;
	dx = -tdy;
	dy = tdx;
}

void turnright()
{
	int tdx = dx;
	int tdy = dy;
	dx = tdy;
	dy = -tdx;
}

void turnback()
{
	dx = -dx;
	dy = -dy;
}

void push(int tx, int ty)
{
	if (map[tx][ty] == '.')
	{
		return;
	}
	if (((tx >= 1) && (tx <= 8)) && ((ty >= 1) && (ty <= 8)))
	{
		push(tx + dx, ty + dy);
		map[tx + dx][ty + dy] = map[tx][ty];
	}
} 

void paint()
{
	if (dx == 1)
	{
		map[x][y] = 'v';
	}
	if (dx == -1)
	{
		map[x][y] = '^';
	}
	if (dy == 1)
	{
		map[x][y] = '>';
	}
	if (dy == -1)
	{
		map[x][y] = '<';
	}
}

int main()
{
	memset(map, '.', sizeof(map));
	while (scanf("%s", map[1] + 1), map[1][1] != '-')
	{
		int i, j;
		for (i = 2; i <= 8; ++i)
		{
			scanf("%s", map[i] + 1);
			map[i][9] = '.';
		}
		findstart();
		map[x][y] = '.';
		
		while (scanf("%s", action), action[0] != '#')
		{
			if (action[0] == 't')
			{
				scanf("%s", action);
				switch (action[0])
				{
					case 'l':
					{
						turnleft();
						break;
					}
					case 'r':
					{
						turnright();
						break;
					}
					case 'b':
					{
						turnback();
						break;
					}
					default:
					{
						break;
					}
				}
			}
			else
			{
				int m;
				scanf("%d", &m);
				for (i = 1; i <= m; ++i)
				{ 
					x += dx;
					y += dy;
					if ((x <= 8) && (x >= 1) && (y <= 8) && (y >= 1))
					{
						push(x, y);
						map[x][y] = '.';
					}
					else
					{
						x -= dx;
						y -= dy;
						break;
					}
				}
			}
		}
		paint();
		for (i = 1; i <= 8; ++i)
		{
			for (j = 1; j <= 8; ++j)
			{
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}	
	return 0;
}
