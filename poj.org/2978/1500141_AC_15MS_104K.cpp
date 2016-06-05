#include <stdio.h>
#include <memory.h>

long dp[101][33][6];
long a[101];

long mx(long a,long b)
{
	if (a>b) return a;
	return b;
}

int main()
{
	long i,j,h,m,k,p,ans,nn;
	scanf("%d%d",&m,&k);
	while (m>0)
	{
		nn=(1<<k)-1;
		memset(dp,0,sizeof(dp));
		for (i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			p=1<<(a[i]-1);
			for (j=0;j<=nn;j++)
				for (h=1;h<=k;h++)
					dp[i][j][h]=dp[i-1][j][h];
			for (j=0;j<=nn;j++)
				if ((j&p)>0)
					dp[i][j][a[i]]=dp[i-1][j][a[i]]+1;
			for (j=0;j<=nn;j++)
				if ((j&p)==0)
					for (h=1;h<=k;h++)
						if (dp[i-1][j][h])
							dp[i][j+p][a[i]]=mx(dp[i][j+p][a[i]],dp[i-1][j][h]+1);
		}
		ans=0;
		for (j=0;j<=nn;j++)
			for (h=1;h<=5;h++)
				ans=mx(ans,dp[m][j][h]);
		printf("%d\n",m-ans);
		scanf("%d%d",&m,&k);
	}
	return 0;
}

