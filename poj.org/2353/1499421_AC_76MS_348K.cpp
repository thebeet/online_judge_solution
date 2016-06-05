#include <stdio.h>
#include <memory.h>

long p[110][510],dp[510];
long map[510];
long ans[50005];

int main()
{
	long i,j,n,m,mn,px;
	scanf("%d%d",&n,&m);
	memset(p,0,sizeof(p));
	for (j=1;j<=m;j++)
	{
		scanf("%d",&dp[j]);
		p[1][j]=-1;
	}
	for (i=2;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			scanf("%d",&map[j]);
			dp[j]+=map[j];
		}
		for (j=2;j<=m;j++)
			if ((dp[j-1]+map[j])<dp[j])
			{
				dp[j]=dp[j-1]+map[j];
				p[i][j]=j-1;
			}
		for (j=m-1;j>=1;j--)
			if ((dp[j+1]+map[j])<dp[j])
			{
				dp[j]=dp[j+1]+map[j];
				p[i][j]=j+1;
			}
	}
	mn=2000000000;
	for (j=1;j<=m;j++)
		if (mn>dp[j])
		{
			mn=dp[j];
			px=j;
		}
	i=n;
	ans[0]=1;
	ans[1]=px;
	while (p[i][px]>=0)
	{
		if (p[i][px]==0)
		{
			ans[0]++;
			ans[ans[0]]=px;
			i--;
		}
		else
		{
			ans[0]++;
			ans[ans[0]]=p[i][px];
			px=p[i][px];
		}
	}
	for (i=ans[0];i>0;i--)
		printf("%d\n",ans[i]);
	return 0;
}
