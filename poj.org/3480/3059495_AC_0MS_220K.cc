#include <stdio.h>

int stone[100010];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, xr;
		int s1;
		xr = 0;
		s1 = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &stone[i]);
			xr ^= stone[i];
			if (stone[i] != 1)
			{
				++s1;
			}
		}
		if (s1 == 0)
		{
			if ((n & 1) == 1)
			{
				printf("Brother\n");
			}
			else
			{
				printf("John\n");
			}
		}
		else if (s1 == 1)
		{
			printf("John\n");
		}
		else if (s1 == 2)
		{
			if (xr > 0)
			{
				printf("John\n");
			}
			else
			{
				printf("Brother\n");
			}
		}
		else
		{
			if (xr > 0)
			{
				printf("John\n");
			}
			else
			{
				printf("Brother\n");
			}
		}
	}
	return 0;
}
