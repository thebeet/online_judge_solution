#include <stdio.h>
#include <memory.h>

long a[510][1010];
long id[510];
long dp[510];

void qsort(long p,long l,long r)
{
	long i,j,x,y;
	i=l;
	j=r;
	x=a[p][(i+l)>>1];
	for (;;)
	{
		while (a[p][i]<x) i++;
		while (a[p][j]>x) j--;
		if (i<=j)
		{
			y=a[p][i];
			a[p][i]=a[p][j];
			a[p][j]=y;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (i<r) qsort(p,i,r);
	if (l<j) qsort(p,l,j);
}

int main()
{
	long i,j,k,n,d,t,ans;
	while (scanf("%d%d",&n,&d)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for (i=0;i<=n;i++)
		{
			for (j=1;j<=d;j++)
				scanf("%d",&a[i][j]);
			qsort(i,1,d);
		}
		for (i=0;i<=n;i++)
			id[i]=i;
		for (i=0;i<=n;i++)
			for (j=0;j<i;j++)
				if (a[id[i]][1]<a[id[j]][1])
				{
					t=id[i];
					id[i]=id[j];
					id[j]=t;
				}
		ans=0;
		for (i=0;i<=n;i++)
		{
			if (id[i]==0) dp[i]=0;
			else dp[i]=-10000;
			for (j=0;j<i;j++)
				if (dp[j]+1>dp[i])
				{
					for (k=1;k<=d;k++)
						if (a[id[i]][k]<=a[id[j]][k]) break;
					if (k<=d) continue;
					dp[i]=dp[j]+1;
				}
			if (dp[i]>ans) ans=dp[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
