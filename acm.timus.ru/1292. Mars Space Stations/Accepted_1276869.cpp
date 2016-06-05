#include <stdio.h>
#include <memory.h>

long f[33340];
long p[11];

int main()
{
	long ti,tn,i,n,k,l;
	memset(f,0,sizeof(f));
	memset(p,0,sizeof(p));
	for (i=1;i<=9;i++)
		p[i]=i*i*i;
	for (i=3;i<=33333;i=i+3)
	{
		n=i;
		l=0;
		while (n>0)
		{
			l+=p[n%10];
			n/=10;
		}
		f[i]=l;
	}
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d%d",&n,&k,&l);
		for (i=1;i<n;i++)
		{
			k=f[k];
			if (k==f[k]) break;
		}
		printf("%d\n",k-l);
	}
	return 0;
}

