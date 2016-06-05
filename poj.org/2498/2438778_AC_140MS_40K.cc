#include <stdio.h>
#include <string.h>

const int pr[3] = { 9, 7, 3};
char inp[20];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, s, x;
		char *p, *tp;
		memset(inp, 0, sizeof(inp));
		scanf("%s", inp);
		printf("Scenario #%d:\n", ti);
		s = 0;
		p = inp;
		if (strlen(inp) == 6)
		{
			i = 1;
		}
		else
		{
			i = 0;
		}
		while (*p != '\0')
		{
			if (*p != '?')
			{
				s = (s + pr[i] * (*p - '0')) % 10;
			}
			else
			{
				tp = p;
				x = pr[i];
			}
			i = (i + 1) % 3;
			++p;
		}
		for (i = 0; ; ++i)
		{
			if (s == 0)
			{
				break;
			}
			s = (s + x) % 10;
		}
		*tp = '0' + i;
		printf("%s\n\n", inp);
	}
	return 0;
} 
