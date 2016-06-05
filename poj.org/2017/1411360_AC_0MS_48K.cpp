#include <stdio.h>
int main()
{
	long i,n,s,ph,h,l;
	scanf("%d",&n);
	while (n>0)
	{
		ph=0;
		l=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&s,&h);
			l=l+s*(h-ph);
			ph=h;
		}
		printf("%d miles\n",l);
		scanf("%d",&n);
	}
	return 0;
}

