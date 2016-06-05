#include <stdio.h>
#include <string.h>

char inp[200];

void swap(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int i, a, b, c, l;
	while (scanf("%s", inp) != EOF)
	{
		l = strlen(inp) - 1;
		for (i = 0; i + i < l; ++i)
		{
			swap(inp[i], inp[l - i]);
		}
		sscanf(inp, "%d=%d+%d", &c, &b, &a);
		if (c == a + b)
		{
			printf("True\n");
		}
		else
		{
			printf("False\n");
		}
	}
	return 0;
} 
