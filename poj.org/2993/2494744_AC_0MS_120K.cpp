#include <stdio.h>
#include <string.h>

char map[16][16];

int main()
{
	int i, j;
	char ch;
	scanf("%*s");
	memset(map, 0, sizeof(map));
	while (scanf("%c", &ch), ((ch == ',') || (ch == ' ')))
	{
		char c, l;
		scanf("%c", &ch);
		if (ch > 'Z')
		{
			c = ch;
			ch = 'P';
			scanf("%c", &l);
		}
		else
		{
			scanf("%c%c", &c, &l);
		}
		map[9 - ((int)l - '0')][(int)c - 'a' + 1] = ch;
	}
	scanf("%*s");
	while (scanf("%c", &ch), ((ch == ',') || (ch == ' ')))
	{
		char c, l;
		scanf("%c", &ch);
		if (ch > 'Z')
		{
			c = ch;
			ch = 'P';
			scanf("%c", &l);
		}
		else
		{
			scanf("%c%c", &c, &l);
		}
		ch += 'a' - 'A';
		map[9 - ((int)l - '0')][(int)c - 'a' + 1] = ch;
	}
	for (i = 1; i <= 8; ++i)
	{
		printf("+---+---+---+---+---+---+---+---+\n");
		for (j = 1; j <= 8; ++j)
		{
			printf("|");
			if (((i + j) & 1) == 1)
			{
				printf(":");
			}
			else
			{
				printf(".");
			}
			if (map[i][j] != 0)
			{
				printf("%c", map[i][j]);
			}
			else
			{
				if (((i + j) & 1) == 1)
				{
					printf(":");
				}
				else
				{
					printf(".");
				}
			}
			if (((i + j) & 1) == 1)
			{
				printf(":");
			}
			else
			{
				printf(".");
			}
		}
		printf("|\n");
	}
	printf("+---+---+---+---+---+---+---+---+\n");
	return 0;
}
