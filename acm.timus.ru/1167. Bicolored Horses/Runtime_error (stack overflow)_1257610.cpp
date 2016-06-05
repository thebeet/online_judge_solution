#include <stdio.h>
#include <memory.h>
#define mx 500
long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}
int main()
{
	long i,j,h,n,k,c;
	long dp[mx][mx];
	long s[mx];
	long uh[mx][mx];
	memset(dp,127,sizeof(dp));
	memset(s,0,sizeof(s));
	memset(uh,0,sizeof(uh));
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&c);
		s[i]=s[i-1]+c;
	}
	for (i=1;i<=n;i++)
		for (j=i+1;j<=n;j++)
			uh[i][j]=(s[j]-s[i-1])*(j+1-i-(s[j]-s[i-1]));
	dp[0][0]=0;
	for (i=1;i<=k;i++)
	{
		for (j=1;j<=n;j++)
			for (h=(i-1);h<=(j-1);h++)
				dp[i][j]=mn(dp[i][j],dp[i-1][h]+uh[h+1][j]);
	}
	printf("%d\n",dp[k][n]);
	return 0;
}

		
