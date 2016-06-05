#include <stdio.h>

int main()
{
	long n,m,p,c;
	scanf("%d%d%d%d",&n,&m,&p,&c);
	while (!((n==0) && (m==0) && (p==0) && (c==0)))
	{
		printf("%d\n",n-(m-p));
		scanf("%d%d%d%d",&n,&m,&p,&c);
	}
	return 0;
}