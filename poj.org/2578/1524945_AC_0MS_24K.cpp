#include <stdio.h>

int main()
{
	long i,n;
	for (i=1;i<=3;i++)
	{
		scanf("%d",&n);
		if (n<=168) 
		{
			printf("CRASH %d\n",n);
			return 0;
		}
	}
	printf("NO CRASH\n");
	return 0;
}
