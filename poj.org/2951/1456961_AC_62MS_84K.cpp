#include <stdio.h>
#include <memory.h>

long dp[21][21][21];

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	long i,j,k,g,l,w,h,m;
	memset(dp,127,sizeof(dp));
	for (i=1;i<=20;i++)
		for (j=1;j<=20;j++)
			dp[i][j][0]=i*j;
	for (k=1;k<=19;k++)
		for (i=1;i<=20;i++)
			for (j=1;j<=20;j++)
			{
				if (k>=(i*j)) continue;
				for (g=1;g<i;g++)
					for (l=0;l<k;l++)
						dp[i][j][k]=mn(dp[i][j][k],mx(dp[g][j][l],dp[i-g][j][k-l-1]));
				for (g=1;g<j;g++)
					for (l=0;l<k;l++)
						dp[i][j][k]=mn(dp[i][j][k],mx(dp[i][g][l],dp[i][j-g][k-l-1]));
			}
	scanf("%d%d%d",&w,&h,&m);
	while (w>0)
	{
		printf("%d\n",dp[w][h][m-1]);
		scanf("%d%d%d",&w,&h,&m);
	}
	return 0;
}
		
