#include <cstdio>
#include <cctype>

int main()
{
	char c;
	int st = 1;
	while (scanf("%c", &c) != EOF)
	{
		if ((c == '.') || (c == '?') || (c == '!'))
		{
			st = 1;
		}
		if ((c >= 'A') && (c <= 'Z'))
		{
			if (st == 0)
			{
				c += 'a' - 'A';
			}
			else
			{
				st = 0;
			}
		}
		printf("%c", c);
	}
	return 0;
}
