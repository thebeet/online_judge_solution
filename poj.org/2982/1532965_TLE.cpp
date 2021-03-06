#include <stdio.h>
#include <memory.h>

long dp[102][20012];

long mn(long a,long b)
{
	if (a==0) return b;
	if (a>b) return b;
	else return a;
}

int main()
{
	long n,m,k,i,ia,ib,a,b,c;
	scanf("%d%d%d",&n,&m,&k);
	while ((n>0) || (m>0) || (k>0))
	{
		memset(dp,0,sizeof(dp));
		dp[0][10000]=1;
		for (i=1;i<=k;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			for (ia=0;ia<=n;ia++)
			{
				if (b>0)
				{
					for (ib=-10000;ib<=10000;ib++)
					{
						if ((ia+a>n) || (ib+b>10000)) break;
						if (dp[ia][ib+10000]>0) dp[ia+a][ib+b+10000]=mn(dp[ia+a][ib+b+10000],dp[ia][ib+10000]+c);
					}
				}
				else
				{
					for (ib=10000;ib>=-10000;ib--)
					{
						if ((ia+a>n) || (ib+b<-10000)) break;
						if (dp[ia][ib+10000]>0) dp[ia+a][ib+b+10000]=mn(dp[ia+a][ib+b+10000],dp[ia][ib+10000]+c);
					}
				}
			}
		}
		printf("%d\n",dp[n][m+10000]-1);
		scanf("%d%d%d",&n,&m,&k);
	}
	return 0;
}
