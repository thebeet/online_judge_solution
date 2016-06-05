#include <stdio.h>

int main()
{
	long ti,tn,i,n,m,s;
	scanf("%ld",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		s=1;
		scanf("%ld",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%ld",&m);
			s+=m;
		}
		s-=n;
		printf("%ld\n",s);
	}
	return 0;
}
