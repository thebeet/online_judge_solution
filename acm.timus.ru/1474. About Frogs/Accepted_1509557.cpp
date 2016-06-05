#include <stdio.h>
#include <memory.h>

long f[1010];
long fre;

void frog_go(long p,long n)
{
	long i;
	for (i=1;i<=n;i++)
	{
		f[fre]=p;
		if (p==1)
		{
			if (f[fre-1]==p)
			{
				printf("%ld ",fre-1);
				fre-=1;
			}
			else 
			{
				printf("%ld ",fre-2);
				fre-=2;
			}
		}
		else
		{
			if (f[fre+1]==p)
			{
				printf("%ld ",fre+1);
				fre+=1;
			}
			else 
			{
				printf("%ld ",fre+2);
				fre+=2;
			}
		}
	}
	return;
}

int main()
{
	long i,g,n;
	scanf("%ld",&n);
	memset(f,0,sizeof(f));
	for (i=0;i<n;i++)
	{
		f[i]=1;
	}
	f[n]=2;
	for (i=n+1;i<=n+n;i++)
	{
		f[i]=3;
	}
	fre=n;
	printf("%ld\n",n*(n+2));
	g=1;
	for (i=1;i<=n;i++)
	{
		frog_go(g,i);
		g^=2;
	}
	frog_go(g,n);
	g^=2;
	for (i=n;i>=1;i--)
	{
		frog_go(g,i);
		g^=2;
	}
	return 0;
}
