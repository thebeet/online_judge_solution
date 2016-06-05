#include <stdio.h>
#include <memory.h>

#define MAXN 510

long y[MAXN][MAXN],b[MAXN][MAXN];
long sy[MAXN][MAXN],sb[MAXN][MAXN];
long dp[MAXN][MAXN];

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
	long i,j,k,n,m,s;
	scanf("%d%d",&n,&m);
	while (n>0)
	{
		memset(sy,0,sizeof(sy));
		memset(sb,0,sizeof(sb));
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				scanf("%d",&y[i][j]);
				sy[i][j]=sy[i][j-1]+y[i][j];
			}
		for (i=1;i<=m;i++)
			for (j=1;j<=n;j++)
				sy[j][i]+=sy[j-1][i];
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				scanf("%d",&b[i][j]);
			}
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
				sb[i][j]=sb[i-1][j]+b[i][j];
		memset(dp,0,sizeof(dp));
		for (i=0;i<=n;i++)
			dp[m][i]=sb[i][m]+sy[n-i][m];
		for (i=m-1;i>=1;i--)
			for (j=n;j>=0;j--)
				for (k=j;k<=n;k++)
					dp[i][j]=mx(dp[i][j],dp[i+1][k]+sy[k][i]-sy[j][i]+sb[j][i]);
		s=0;
		for (i=0;i<=n;i++)
			s=mx(s,dp[1][i]);
		printf("%d\n",s);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
