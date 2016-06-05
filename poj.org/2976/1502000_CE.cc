#include <stdio.h>
#include <memory.h>

__int64 a[1011];
__int64 b[1011];
bool d[1011];

int main()
{
	__int64 i,j,k,n,sa,sb,ta,tb,ma,mb,p,ans;
	scanf("%I64d%I64d",&n,&k);
	while (n>0)
	{
		sa=0;
		sb=0;
		memset(d,true,sizeof(d));
		for (i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			sa+=a[i];
		}
		for (i=1;i<=n;i++)
		{
			scanf("%I64d",&b[i]);
			sb+=b[i];
		}
		for (j=1;j<=k;j++)
		{
			ma=-1;
			mb=1;
			for (i=1;i<=n;i++)
				if (d[i])
				{
					ta=sa-a[i];
					tb=sb-b[i];
					if ((ta*1.0/tb)>(ma*1.0/mb)) 
					{
						p=i;
						ma=ta;
						mb=tb;
					}
				}
			d[p]=false;
			sa=sa-a[p];
			sb=sb-b[p];
		}
		ans=__int64(sa*100.0/sb+0.5);
		printf("%I64d\n",ans);
		scanf("%I64d%I64d",&n,&k);
	}
	return 0;
}
		

