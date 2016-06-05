#include <stdio.h>
#include <memory.h>
long ans[11][11];
long ti,tn,n,m;

long p(long m,long n)
{
	if (m<n) n=m;
	if (m==0) return 1;
	if (n==1) return 1;
	return p(m-n,n)+p(m,n-1);
}

int main()
{
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",p(n,m));
	}
	return 0;
}

