#include <stdio.h>
#include <memory.h>

long dp[310][310];

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	long ti,tn,k,i,j,n,m,x,y,ans;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		memset(dp,1,sizeof(dp));
		dp[0][0]=0;
		scanf("%d%d",&n,&m);
		for (k=1;k<=n;k++)
		{
			scanf("%d%d",&x,&y);
			for (i=0;i<=m-x;i++)
				for (j=0;j<=m-y;j++)
					dp[i+x][j+y]=mn(dp[i+x][j+y],dp[i][j]+1);
		}
		ans=10000000;
		for (i=0;i<=m;i++)
			for (j=0;j<=m;j++)
				if ((i*i+j*j)==(m*m)) ans=mn(ans,dp[i][j]);
		if (ans<10000) printf("%d\n",ans);
		else printf("not possible\n");
	}
	return 0;
}

