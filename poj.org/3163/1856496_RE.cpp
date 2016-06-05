#include <stdio.h>
#include <memory.h>

double p[12][100010];
double dp[1020];

double mx(double d1,double d2)
{
	if (d1>d2) return d1;
	else return d2;
}

int main()
{
	long i,j,k,n,m,l,t;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		memset(p,0,sizeof(p));
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				scanf("%lf",&p[i][j]);
				p[i][j]=1-p[i][j];
			}
		memset(dp,0,sizeof(dp));
		l=(1<<n)-1;
		dp[0]=1.0;
		for (i=1;i<=m;i++)
		{
			for (j=l;j>=1;j--)
				for (k=1;k<=n;k++)
				{
					t=1<<(k-1);
					if ((j&t)!=0) dp[j]=mx(dp[j],dp[j-t]*p[k][i]);
				}
		}
		printf("%.9lf\n",dp[l]);
	}
	return 0;
}
