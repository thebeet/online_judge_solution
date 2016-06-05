#include <stdio.h>
#include <memory.h>

long l[4],p[4],c[4];
long s[10010],dp[10010];

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	long i,j,n,a,b,t;
	scanf("%d%d%d%d%d%d",&l[1],&l[2],&l[3],&c[1],&c[2],&c[3]);
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	for (i=2;i<=n;i++)
		scanf("%d",&s[i]);
	memset(dp,117,sizeof(dp));
	if (a>b)
	{
		t=a;
		a=b;
		b=t;
	}
	for (j=1;j<=3;j++)
		p[j]=a;
	dp[a]=0;
	for (i=a+1;i<=b;i++)
		for (j=1;j<=3;j++)
		{
			while (s[p[j]]+l[j]<s[i])
				p[j]++;
			dp[i]=mn(dp[i],dp[p[j]]+c[j]);
		}
	printf("%d\n",dp[b]);
	return 0;
}
		




