#include <stdio.h>
#include <memory.h>

#define MAXN 102

long map[MAXN][MAXN];
long dp[MAXN][MAXN];
long n,m;

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

long s(long x,long y)
{
	if ((x<1) || (y<1) || (x>n) || (y>m)) return 0;
	if (dp[x][y]>0) return dp[x][y];
	dp[x][y]=1;
	if (map[x][y]>map[x+1][y]) dp[x][y]=mx(dp[x][y],s(x+1,y)+1);
	if (map[x][y]>map[x-1][y]) dp[x][y]=mx(dp[x][y],s(x-1,y)+1);
	if (map[x][y]>map[x][y+1]) dp[x][y]=mx(dp[x][y],s(x,y+1)+1);
	if (map[x][y]>map[x][y-1]) dp[x][y]=mx(dp[x][y],s(x,y-1)+1);
	return dp[x][y];
}


int main()
{
	long i,j,ans;
	scanf("%d%d",&n,&m);
	memset(map,0,sizeof(map));
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	memset(dp,0,sizeof(dp));
	ans=0;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			s(i,j);
			if (ans<dp[i][j]) ans=dp[i][j];
		}
	printf("%d\n",ans);
	return 0;
}


