#include <stdio.h>
#include <string.h>

char inp1[100010];
char inp2[100010];

int main()
{
	while (scanf("%s%s", inp1, inp2) != EOF)
	{
		char *p1 = inp1;
		char *p2;
		for (p2 = inp2; *p2 != '\0'; ++p2)
		{
			 if (*p2 == *p1)
			 {
			 	++p1;
			 }
		}
		if (*p1 == '\0')
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
