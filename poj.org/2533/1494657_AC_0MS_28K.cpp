#include <stdio.h>

long a[1001];
long dp[1001];
 
long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
	long i,j,n,m;
	scanf("%d",&n);
	m=0;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for (j=1;j<i;j++)
			if (a[j]<a[i])
			{
				dp[i]=mx(dp[i],dp[j]+1);
				if (dp[i]>m) m=dp[i];
			}
	}
	printf("%d\n",m+1);
	return 0;
}

