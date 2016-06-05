#include <stdio.h>

int main()
{
	long n, m;
	while (scanf("%ld%ld", &n, &m) != EOF)
	{
		if ((m & n) == m)
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