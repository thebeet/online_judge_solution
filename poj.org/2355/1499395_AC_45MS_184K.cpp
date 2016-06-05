#include <stdio.h>
#include <memory.h>

__int64 l[4],p[4],c[4];
__int64 s[10010],dp[10010];

__int64 mn(__int64 a,__int64 b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	__int64 i,j,n,a,b,t;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&l[1],&l[2],&l[3],&c[1],&c[2],&c[3]);
	scanf("%I64d",&n);
	scanf("%I64d%I64d",&a,&b);
	for (i=2;i<=n;i++)
		scanf("%I64d",&s[i]);
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
	printf("%I64d\n",dp[b]);
	return 0;
}
