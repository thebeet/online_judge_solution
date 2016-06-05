#include <stdio.h>

int main()
{
	const int assigntable[30] = { 0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2 };
	char inp[30];
	int pr;
	while (scanf("%s", inp) != EOF)
	{
		char *p;
		pr = -1;
		for (p = inp; *p != '\0'; ++p)
		{
			if (pr != assigntable[*p - 'A'])
			{
				pr = assigntable[*p - 'A'];
				if (pr != 0)
				{
					printf("%d", pr);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
