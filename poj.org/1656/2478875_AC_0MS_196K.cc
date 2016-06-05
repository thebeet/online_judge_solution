#include <stdio.h>
#include <string.h>

bool map[110][110];

void paint(int x, int y, int l, bool color)
{
	for (int i = x; i < x + l; ++i)
	{
		for (int j = y; j < y + l; ++j)
		{
			map[i][j] = color;
		}
	}
}

int test(int x, int y, int l)
{
	int sum = 0;
	for (int i = x; i < x + l; ++i)
	{
		for (int j = y; j < y + l; ++j)
		{
			if (map[i][j])
			{
				++sum;
			}
		}
	}
	return sum;
}

int main()
{
	int i, n, x, y, l;
	char inp[10];
	scanf("%d", &n);
	memset(map, 0, sizeof(map));
	for (i = 1; i <= n; ++i)
	{
		scanf("%s%d%d%d", inp, &x, &y, &l);
		switch (inp[0])
		{
			case 'B':
			{
				paint(x, y, l, true);
				break;
			} 
			case 'W':
			{
				paint(x, y, l, false);
				break;
			} 
			case 'T':
			{
				printf("%d\n", test(x, y, l));
				break;
			} 
			default:
			{
			}
		}
	}
	return 0;
}
