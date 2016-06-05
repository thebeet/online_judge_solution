#include <stdio.h>
#include <memory.h>

long dp[110000];
long nn[110000];
long ss[110000];
long mir[25];
long c[25];
long n;

void crt(long p,long f,long m,long s)
{
	long i;
	if ((f+p)>n) return;
	if (p==0)
	{
		nn[0]++;
		nn[nn[0]]=m;
		ss[m]=s;
	}
	p--;
	for (i=f;i<n;i++)
	{
		crt(p,i+1,m+(1<<i),s+mir[i+1]);
	}
}

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	long i,j,s;
	memset(dp,1,sizeof(dp));
	dp[0]=0;
	memset(mir,0,sizeof(mir));
	memset(c,0,sizeof(c));
	memset(nn,0,sizeof(nn));
	scanf("%ld",&n);
	s=0;
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&mir[i]);
		s+=mir[i];
	}
	for (i=1;i<=n;i++)
	{
		crt(i,0,0,0);
	}
	c[1]=1+(3<<(n-2));
	c[2]=3+(1<<(n-1));
	c[3]=7;
	for (i=4;i<=n;i++)
	{
		c[i]=c[i-1]<<1;
	}
	nn[0]=0;
	for (i=0;i<(1<<n);i++)
	{
		for (j=1;j<=n;j++)
		{
			dp[nn[i]|c[j]]=mn(dp[nn[i]|c[j]],dp[nn[i]]+s-ss[nn[i]|c[j]]);
		}
	}
	printf("%ld\n",dp[nn[(1<<n)-1]]);
	return 0;
}
