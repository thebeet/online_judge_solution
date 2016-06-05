#include <stdio.h>

long v[2010];
long dp[2010][2010];

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
	long i,j,n,tj;
	scanf("%ld",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&v[i]);
		dp[i][i]=v[i]*n;
	}
	for (j=1;j<n;j++)
		for (i=1;j+i<=n;i++)
		{
			tj=i+j;
			dp[i][tj]=mx(dp[i+1][tj]+v[i]*(n-j),dp[i][tj-1]+v[tj]*(n-j));
		}
	printf("%ld\n",dp[1][n]);
	return 0;
}
