#include <stdio.h>
#include <memory.h>

#define MAXN 100011

long f[MAXN];
long c[MAXN];
long cp[MAXN];
long cn[MAXN];
long dp[MAXN];
long aa[MAXN];

void sort(long l,long r)
{
	long i,j,x,y;
	i=l;
	j=r;
	x=aa[(l+r)/2];
	for (;;)
	{
		while (aa[i]>x) 
			i++;
		while (aa[j]<x)
			j--;
		if (i<=j)
		{
			y=aa[i];
			aa[i]=aa[j];
			aa[j]=y;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r);
}

void ddp(long a,long p)
{
	long i,m;
	for (i=0;i<cn[a];i++)
		if (p!=c[i+cp[a]]) ddp(c[i+cp[a]],a);
	if ((f[a]!=0) && (f[a]!=p))
		ddp(f[a],a);
	aa[0]=0;
	for (i=0;i<cn[a];i++)
		if (p!=c[i+cp[a]])
		{
			aa[0]++;
			aa[aa[0]]=dp[c[i+cp[a]]];
		}
	if ((f[a]!=0) && (f[a]!=p))
	{
		aa[0]++;
		aa[aa[0]]=dp[f[a]];
	}
	sort(1,aa[0]);
	m=0;
	for (i=1;i<=aa[0];i++)
		if (m<aa[i]+i)
			m=aa[i]+i;
	dp[a]=m;
}

int main()
{
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	memset(cp,0,sizeof(cp));
	memset(cn,0,sizeof(cn));
	memset(dp,0,sizeof(dp));
	long i,n,m;
	scanf("%d",&n);
	cn[0]=1;
	for (i=1;i<=n;i++)
	{
		cp[i]=cp[i-1]+cn[i-1];
		scanf("%d",&m);
		while (m>0)
		{
			f[m]=i;
			c[cn[i]+cp[i]]=m;
			cn[i]++;
			scanf("%d",&m);
		}
	}
	scanf("%d",&m);
	ddp(m,0);
	printf("%d\n",dp[m]);
	return 0;
}
