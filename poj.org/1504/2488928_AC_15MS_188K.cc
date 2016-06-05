#include <stdio.h>
#include <string.h>

char inp1[100];
char inp2[100];
char oup[100];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int a, b, c;
		scanf("%s%s", inp1, inp2);
		strrev(inp1);
		strrev(inp2);
		sscanf(inp1, "%d", &a);
		sscanf(inp2, "%d", &b);
		sprintf(oup, "%d", a + b);
		strrev(oup);
		sscanf(oup, "%d", &c);
		printf("%d\n", c);
	}
	return 0;
}
