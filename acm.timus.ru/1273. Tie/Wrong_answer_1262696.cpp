#include <stdio.h>

long x[110],y[110],dp[110];

long mx(long n1,long n2)
{
	if (n1>n2) return n1;
	else return n2;
}

int main()
{
	long i,j,k,t,m;
	scanf("%d",&k);
	for (i=1;i<=k;i++)
		scanf("%d%d",&x[i],&y[i]);
	for (i=1;i<=k;i++)
		for (j=i+1;j<=k;j++)
			if (x[i]>x[j])
			{
				t=x[i];
				x[i]=x[j];
				x[j]=t;
				t=y[i];
				y[i]=y[j];
				y[j]=t;
			}
	m=1;
	for (i=1;i<=k;i++)
	{
		dp[i]=1;
		for (j=1;j<i;j++)
			if (y[j]<y[i])
			{
				dp[i]=mx(dp[i],dp[j]+1);
				if (m<dp[i]) m=dp[i];
			}
	}
	printf("%d\n",k-m);
	return 0;
}

