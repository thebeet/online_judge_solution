#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char inp[300];
	bool is_cpp = false;
	bool isJava = false;
	scanf("%s", inp);
	if ((inp[0] == '_') || (inp[strlen(inp) - 1] == '_'))
	{
		is_cpp = true;
		isJava = true;
	}
	for (i = 0; i < strlen(inp); ++i)
	{
		if (inp[i] == '_')
		{
			is_cpp = true;
			if (inp[i + 1] == '_')
			{
				isJava = true;
			}
		}
		if ((inp[i] >= 'A') && (inp[i] <= 'Z'))
		{
			isJava = true;
		}
	}
	if (is_cpp & isJava)
	{
		printf("Error!\n");
	}
	else
	{
		if (is_cpp)
		{
			for (i = 0; i <strlen(inp); ++i)
			{
				if (inp[i] == '_')
				{
					++i;
					inp[i] += ('A' - 'a');
				}
				printf("%c", inp[i]);
			}
		}
		else
		{
			for (i = 0; i <strlen(inp); ++i)
			{
				if ((inp[i] >= 'A') && (inp[i] <= 'Z'))
				{
					printf("_");
					inp[i] += ('a' - 'A');
				}
				printf("%c", inp[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
