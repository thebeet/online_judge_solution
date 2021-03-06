#include <stdio.h>
#include <memory.h>
#define mx 502
int dp[mx][mx],s[mx],uh[mx][mx];

int mn(int a,int b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	int i,j,h,n,k,c;
	scanf("%d%d",&n,&k);
	memset(dp,127,sizeof(dp));
	memset(uh,0,sizeof(uh));
	memset(s,0,sizeof(s));
	s[0]=0;
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
		{
			for (h=(i-1);h<=(j-1);h++)
				dp[i][j]=mn(dp[i][j],dp[i-1][h]+uh[h+1][j]);
		}
	}
	printf("%d\n",dp[k][n]);
	return 0;
}

		
