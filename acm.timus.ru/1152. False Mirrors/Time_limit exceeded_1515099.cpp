#include <stdio.h>
#include <memory.h>

long dp[1100000];
long nn[1100000];
long ss[1100000];
long mir[25];
long c[25];
long n,sss;

void crt(long p,long f,long m,long s)
{
	long i;
	if ((f+p)>n) return;
	if (p==0)
	{
		nn[0]++;
		nn[nn[0]]=m;
		ss[m]=sss-s;
		return;
	}
	p--;
	if ((f+2<n) && (p>10) && (f>2))
	{
		if ((m&(1<<(f-2))==0))
		{
			p--;
			m+=(1<<f);
			f++;
			s+=mir[f];
			p--;
			m+=(1<<f);
			f++;
			s+=mir[f];
		}
	}
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
	long i,j,nnn,k;
	memset(dp,120,sizeof(dp));
	dp[0]=0;
	memset(mir,0,sizeof(mir));
	memset(c,0,sizeof(c));
	memset(nn,0,sizeof(nn));
	scanf("%ld",&n);
	sss=0;
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&mir[i]);
		sss+=mir[i];
	}
	for (i=3;i<=n;i++)
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
	nnn=nn[0];
	nn[0]=0;
	for (i=0;i<nnn;i++)
	{
		for (j=1;j<=n;j++)
		{
			k=nn[i]|c[j];
			dp[k]=mn(dp[k],dp[nn[i]]+ss[k]);
		}
	}
	printf("%ld\n",dp[nn[nnn]]);
	return 0;
}
