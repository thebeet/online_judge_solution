#include <stdio.h>
#include <memory.h>

int mx(int a,int b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
	long i,j,n,m;
	long dp[101][101];
	memset(&dp,0,sizeof(dp));
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
		{
			scanf("%d",&m);
			dp[i][j]=mx(dp[i-1][j-1],dp[i-1][j])+m;
		}
	}
	m=0;
	for (i=1;i<=n;i++)
		m=mx(m,dp[n][i]);
	printf("%d\n",m);
	return 0;
}
