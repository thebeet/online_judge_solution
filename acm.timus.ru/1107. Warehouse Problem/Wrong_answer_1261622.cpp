#include <stdio.h>
int main()
{
	long i,j,s,n,k,m,nn,p;
	scanf("%d%d%d",&n,&k,&m);
	n++;
	for (i=1;i<=k;i++)
	{
		scanf("%d",&nn);
		s=0;
		for (j=1;j<=nn;j++)
		{
			scanf("%d",&p);
			s+=p;
		}
		printf("%d\n",(s%n)+1);
	}
	return 0;
}

