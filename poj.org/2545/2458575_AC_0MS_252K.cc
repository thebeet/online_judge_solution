#include <stdio.h>

#define INT __int64
INT hnum[100010];
INT p[5];
INT *pp[5];
INT s[5];

int main()
{
	int n, i, j, k;
	INT big;
	hnum[1] = 1;
	pp[1] = pp[2] = pp[3] = hnum + 1;
	scanf("%I64d%I64d%I64d%d", &p[1], &p[2], &p[3], &n);
	s[1] = p[1];
	s[2] = p[2];
	s[3] = p[3];
	big = (INT)1;
	for (i = 1; i <= 18; i++)
	{
		big *= (INT)10;
	}
	
	for (i = 2; hnum[i - 1] < big; ++i)
	{
		j = 1;
		if (s[2] < s[j]) j = 2;
		if (s[3] < s[j]) j = 3;
		hnum[i] = s[j];
		for (k = 1; k <= 3; ++k)
		{
			if (s[k] == hnum[i])
			{
				++pp[k];
				s[k] = p[k] * *pp[k];
			}
		}
	}
	printf("%I64d\n", hnum[n + 1]);
	return 0;
}
