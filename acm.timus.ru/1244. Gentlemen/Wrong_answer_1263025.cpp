#include <stdio.h>
#include <memory.h>

long dp[100010];
long p[100010];
long w[110],ss[110],ans[110],ans2[110];

int main()
{
	long i,j,s,n,px,m;
	scanf("%d%d",&s,&n);
	ss[0]=0;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		ss[i]=ss[i-1]+w[i];
	}
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	m=1;
	for (i=1;i<=n;i++)
		for (j=0;j<=ss[i-1];j++)
			if (dp[j]>0)
			{
				dp[j+w[i]]+=dp[j];
				if (dp[j+w[i]]>2) dp[j+w[i]]=2;
				p[j+w[i]]=i;
			}
	if (dp[s]==2) 
	{
		printf("%d\n",-1);
		return 0;
	}
	if (dp[s]==0) 
	{
		printf("%d\n",0);
		return 0;
	}
	px=s;
	ans[0]=0;
	while (px!=0)
	{
		ans[0]++;
		ans[ans[0]]=p[px];
		px=px-w[p[px]];
	}
	ans2[0]=0;
	for (i=1;i<=n;i++)
		if (ans[ans[0]]!=i)
		{
			ans2[0]++;
			ans2[ans2[0]]=i;
		}
		else
			ans[0]--;
	for (i=1;i<ans2[0];i++)
		printf("%d ",ans2[i]);
	printf("%d\n",ans2[ans2[0]]);
	return 0;
}


