#include <stdio.h>
#include <memory.h>

long dp[2001];
long d[2001];
long ans[2001];

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
	long i,n,f,e,t;
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	memset(d,0,sizeof(d));
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&f,&e);
		f+=1000;
		e+=1000;
		if (f>e)
		{
			t=f;
			f=e;
			e=t;
		}
		if (f>d[e]) d[e]=f;
	}
	for (i=1;i<=2000;i++)
	{
		dp[i]=dp[i-1];
		if (d[i]>0) dp[i]=mx(dp[i],dp[d[i]]+1);
	}
	printf("%d\n",dp[2000]);
	for (i=2000;i>=1;i--)
		if (dp[i]>dp[i-1])
		{
			ans[0]++;
			ans[ans[0]]=i;
		}
	for (i=ans[0];i>0;i--)
		printf("%d %d\n",d[ans[i]]-1000,ans[i]-1000);
	return 0;
}


