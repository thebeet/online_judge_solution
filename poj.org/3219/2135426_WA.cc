#include <stdio.h>

int main()
{
	long n, m;
	while (scanf("%ld%ld", &n, &m)!=EOF)
	{
		if ((m == 0) || ((n & m) > 0))
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
