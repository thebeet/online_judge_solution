#include <stdio.h>
#include <string.h>

char map[16][16];
char inp[16][16];
char out[16][16];
bool bomb;
int n;

void spread(int x, int y)
{
	if ((x < 1) || (x > n) || (y < 1) || (y > n) || (out[x][y] != '.'))
	{
		return;
	}
	if (map[x][y] == '*')
	{
		bomb = true;
		return;
	}
	int i, j;
	int sum = 0;
	for (i = x - 1; i <= x + 1; ++i)
	{
		for (j = y - 1; j <= y + 1; ++j)
		{
			if (map[i][j] == '*')
			{
				++sum;
			}
		}
	}
	out[x][y]= '0' + sum;
/*	if (sum == 0)
	{
		for (i = x - 1; i <= x + 1; ++i)
		{
			for (j = y - 1; j <= y + 1; ++j)
			{
				spread(i, j);
			}
		}
	}*/
}

int main()
{
	int i, j;
	
	scanf("%d", &n);
	memset(map, 0, sizeof(map));
	memset(inp, 0, sizeof(inp));
	memset(out, '.', sizeof(out));
	bomb = false;
	for (i = 1; i <= n; ++i)
	{
		scanf("%s", map[i] + 1);
	}
	
	for (i = 1; i <= n; ++i)
	{
		scanf("%s", inp[i] + 1);
		for (j = 1; j <= n; ++j)
		{
			if (inp[i][j] == 'x')
			{
				spread(i, j);
			}
		}
	}
	
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if ((bomb) && (map[i][j] == '*'))
			{
				printf("%c", map[i][j]);
			}
			else
			{
				printf("%c", out[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
