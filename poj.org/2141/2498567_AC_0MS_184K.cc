#include <stdio.h>

char assigntable[256];

int main()
{
	scanf("%s", assigntable);
	scanf("%*c");
	char ch;
	while (scanf("%c", &ch) != EOF)
	{
		if ((ch >= 'a') && (ch <= 'z'))
		{
			ch = assigntable[ch - 'a'];
		}
		else if ((ch >= 'A') && (ch <= 'Z'))
		{
			ch = assigntable[ch - 'A'] - 'a' + 'A';
		}
		printf("%c", ch);
	}
	return 0;
}
