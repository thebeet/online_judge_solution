#include <stdio.h>

int main()
{
	char ch, ret;
	while (true)
	{
		while ((ret = scanf("%c", &ch)), ch != '\n')
		{
			if (ret == EOF)
			{
				return 0;
			}
		}
		while ((ret = scanf("%c", &ch)), ch != '\n')
		{
			if (ret == EOF)
			{
				return 0;
			}
			if ((ch >= 'A') && (ch <= 'Z'))
			{
				ch = 'A' + ((ch - 'A') + 21) % 26;
			}
			printf("%c", ch);	
		}
		printf("\n");
		if (ret == EOF)
		{
			return 0;
		}
		while ((ret = scanf("%c", &ch)), ch != '\n')
		{
			if (ret == EOF)
			{
				return 0;
			}
		}
	}
	return 0;
}
