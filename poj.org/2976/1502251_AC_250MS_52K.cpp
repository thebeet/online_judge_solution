#include <stdio.h>
#include <memory.h>

double a[1011];
double b[1011];
bool d[1011];

int main()
{
	double sa,sb,ta,tb,ma,mb,ans;
	long i,j,k,n,p;
	scanf("%d%d",&n,&k);
	while (n>0)
	{
		sa=0;
		sb=0;
		memset(d,true,sizeof(d));
		for (i=1;i<=n;i++)
		{
			scanf("%lf",&a[i]);
			sa+=a[i];
		}
		for (i=1;i<=n;i++)
		{
			scanf("%lf",&b[i]);
			sb+=b[i];
		}
/*		for (j=1;j<=k;j++)
		{
			ma=-1;
			mb=1;
			for (i=1;i<=n;i++)
				if (d[i])
				{
					ta=sa-a[i];
					tb=sb-b[i];
					if ((ta/tb)>(ma/mb)) 
					{
						p=i;
						ma=ta;
						mb=tb;
					}
				}
			d[p]=false;
			sa-=a[p];
			sb-=b[p];
		}
		*/
		sa=0;
		sb=0;
		k=n-k;
		for (j=1;j<=k;j++)
		{
			ma=-1;
			mb=1;
			for (i=1;i<=n;i++)
				if (d[i])
				{
					ta=sa+a[i];
					tb=sb+b[i];
					if ((ta/tb)>(ma/mb)) 
					{
						p=i;
						ma=ta;
						mb=tb;
					}
				}
			d[p]=false;
			sa+=a[p];
			sb+=b[p];
		}
		ans=sa*100.0/sb+0.0001;
		printf("%.0lf\n",ans);
		scanf("%d%d",&n,&k);
	}
	return 0;
}
		

