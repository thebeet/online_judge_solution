#include <stdio.h>

void out(int n, bool isempty)
{
	if (n == 0)
	{
		if (isempty)
		{
			printf(" ");
		}
		else
		{
			printf("-");
		}
	}
	else
	{
		out(n - 1, isempty);
		out(n - 1, true);
		out(n - 1, isempty);
	}
}

int main()
{		
	int n;
	while (scanf("%d", &n) != EOF)
	{
		out(n, false);
		printf("\n");
	}
	return 0;
}
