#include <stdio.h>

int main()
{
	long i,n,k,pr;
	scanf("%d%d",&n,&k);
	pr=0;
	for (i=1;i<=n;i++)
	{
		if ((i*k/100)>pr)
		{
			printf("%d",1);
			pr=i*k/100;
		}
		else
		{
			printf("%d",0);
		}
	}
	printf("\n");
	return 0;
}
