#include <stdio.h>

int main()
{
	char ch;
	int st = 0;
	while (scanf("%c", &ch) != EOF)
	{
		if (ch == '"')
		{
			if (st == 1)
			{
				printf("''");
			}
			else
			{
				printf("``");
			}
			st ^= 1;
		}
		else
		{
			printf("%c", ch);
		}
	}
	return 0;
}
