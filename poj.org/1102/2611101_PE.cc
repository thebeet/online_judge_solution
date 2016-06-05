#include <stdio.h>
#include <string.h>

void out(char ch, int m)
{
	for (int i = 1; i <= m; ++i)
	{
		printf("%c", ch);
	}
}

int main()
{
	char inp[16];
	int i, j, n;
	while (scanf("%d%s", &n, inp), n > 0)
	{
		for (i = 0; i < strlen(inp); ++i)
		{
			switch (inp[i])
			{
			case '1': case '4':
				out(' ', n + 2);
				break;
			default:
				out(' ', 1);
				out('-', n);
				out(' ', 1);
			}
			printf("%c", (i == strlen(inp) - 1) ? '\n' : ' ');
		}
		for (j = 1; j <= n; ++j)
		{
			for (i = 0; i < strlen(inp); ++i)
			{
				switch (inp[i])
				{
				case '1': case '2': case '3': case '7':
					out(' ', 1);
					break;
				default:
					out('|', 1);
				}
				out(' ', n);
				switch (inp[i])
				{
				case '5': case '6':
					out(' ', 1);
					break;
				default:
					out('|', 1);
				}
				printf("%c", (i == strlen(inp) - 1) ? '\n' : ' ');
			}
		}
		for (i = 0; i < strlen(inp); ++i)
		{
			switch (inp[i])
			{
			case '1': case '7': case '0':
				out(' ', n + 2);
				break;
			default:
				out(' ', 1);
				out('-', n);
				out(' ', 1);
			}
			printf("%c", (i == strlen(inp) - 1) ? '\n' : ' ');
		}
		for (j = 1; j <= n; ++j)
		{
			for (i = 0; i < strlen(inp); ++i)
			{
				switch (inp[i])
				{
				case '1': case '3': case '4': case '5': case '7': case '9':
					out(' ', 1);
					break;
				default:
					out('|', 1);
				}
				out(' ', n);
				switch (inp[i])
				{
				case '2':
					out(' ', 1);
					break;
				default:
					out('|', 1);
				}
				printf("%c", (i == strlen(inp) - 1) ? '\n' : ' ');
			}
		}
		for (i = 0; i < strlen(inp); ++i)
		{
			switch (inp[i])
			{
			case '1': case '4': case '7':
				out(' ', n + 2);
				break;
			default:
				out(' ', 1);
				out('-', n);
				out(' ', 1);
			}
			printf("%c", (i == strlen(inp) - 1) ? '\n' : ' ');
		}
	}
	return 0;
}
