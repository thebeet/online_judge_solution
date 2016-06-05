#include <stdio.h>
#include <memory.h>

long a[50010];
long s[50010];

int main()
{
	long i,n,m;
	double ans,p;
	scanf("%d%d",&n,&m);
	while ((n>0) && (m>0))
	{
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (i=1;i<=n;i++)
			s[i]=a[n-i+1]-a[i];
		p=m*1.0/n;
		ans=p*s[1];
		for (i=1;i<=(n-m+1);i++)
		{
			p*=(n-m-i+1)*1.0/(n-i);
			ans+=p*s[i+1];
		}
		printf("%.3lf\n",ans);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
