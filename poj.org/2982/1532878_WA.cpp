#include <stdio.h>
#include <memory.h>

long dp[102][10002];

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
		dp[0][0]=1;
		for (i=1;i<=k;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			for (ia=0;ia<=n;ia++)
			{
				if (b>0)
				{
					for (ib=0;ib<=10000;ib++)
					{
						if ((ia+a>n) || (ib+b>10000)) break;
						if (dp[ia][ib]>0) dp[ia+a][ib+b]=mn(dp[ia+a][ib+b],dp[ia][ib]+c);
					}
				}
				else
				{
					for (ib=10000;ib>=0;ib--)
					{
						if ((ia+a>n) || (ib+b<0)) break;
						if (dp[ia][ib]>0) dp[ia+a][ib+b]=mn(dp[ia+a][ib+b],dp[ia][ib]+c);
					}
				}
			}
		}
		printf("%d\n",dp[n][m]-1);
		scanf("%d%d%d",&n,&m,&k);
	}
	return 0;
}

