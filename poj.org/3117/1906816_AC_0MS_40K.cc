#include <stdio.h>

int main()
{
	long t,n,s,i,m;
	char inp[1000];
	scanf("%ld%ld",&t,&n);
	s=n*3;
	while (t>0)
	{
		for (i=1;i<=t;i++)
		{
			scanf("%s %ld",inp,&m);
			s-=m;
		}
		printf("%ld\n",s);
		scanf("%ld%ld",&t,&n);
		s=n*3;
	}
	return 0;
}
