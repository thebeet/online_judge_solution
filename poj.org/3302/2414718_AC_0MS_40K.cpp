#include <stdio.h>

char strmain[110];
char strsub[110];

int main()
{
	int ti, tn;
	char *p, *psub;
	
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		scanf("%s%s", strmain, strsub);
		for (p = strmain, psub = strsub; *p != '\0'; ++p)
		{
			if (*p == *psub)
			{
				++psub;
				if (*psub == '\0')
				{
					break;
				}
			}
		}
		if (*psub == '\0') 
		{
			printf("YES\n");
			continue;
		}
		for (--p, psub = strsub; ; --p)
		{
			if (*p == *psub)
			{
				++psub;
				if (*psub == '\0')
				{
					break;
				}
			}
			if (p == strmain) 
			{
				break;
			}
		}
		if (*psub == '\0') 
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
