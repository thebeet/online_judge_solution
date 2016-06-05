#include <stdio.h>

int main()
{
	long n;
	scanf("%ld", &n);
	while (n > 0)
	{
		if ((n & 1) == 1)
		{
			if ((n & 3) == 3) n += 2;
			printf("%ld\n",(n - 1) >> 1);
		}
		else
		{
			printf("No Solution!\n");
		}
		scanf("%ld", &n);
	}
	return 0;
}
