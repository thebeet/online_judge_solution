#include <stdio.h>
#include <memory.h>

#define MAXN 32768

long dp[5][327680];

int main()
{
	long i,j,n,k,h,sq;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	n=0;
	for (i=1;i<=256;i++)
	{
		sq=i*i;
		if ((n+sq)>MAXN) n=MAXN-sq;
		for (j=n;j>=0;j--)
		{
			for (k=4;k>=1;k--)
				for (h=1;h<=k;h++)
					dp[k][j+sq*h]+=dp[k-h][j];
		}
		n=n+sq*4;
	}
	scanf("%d",&n);
	while (n>0)
	{
		printf("%d\n",dp[4][n]+dp[3][n]+dp[2][n]+dp[1][n]);
		scanf("%d",&n);
	}
	return 0;
}

