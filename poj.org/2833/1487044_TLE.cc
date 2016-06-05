#include <stdio.h>

__int64 mx[12],mn[12];

int main()
{
	__int64 i,j,k,n1,n2,n,s,m;
	double ans;
	scanf("%I64d%I64d%I64d",&n1,&n2,&n);
	while (n>0)
	{
		s=0;
		for (i=1;i<=10;i++)
		{
			mx[i]=-1000000000;
			mn[i]=1000000000;
		}
		for (i=1;i<=n;i++)
		{
			scanf("%I64d",&m);
			s+=m;
			for (j=1;j<=n1;j++)
				if (m>mx[j])
				{
					for (k=n1;k>j;k--)
						mx[k]=mx[k-1];
					mx[j]=m;
					break;
				}
			for (j=1;j<=n2;j++)
				if (m<mn[j])
				{
					for (k=n2;k>j;k--)
						mn[k]=mn[k-1];
					mn[j]=m;
					break;
				}
		}
		for (i=1;i<=n1;i++)
			s-=mx[i];
		for (i=1;i<=n2;i++)
			s-=mn[i];
		ans=s*1.0/(n-n1-n2);
		printf("%.6lf\n",ans);
		scanf("%I64d%I64d%I64d",&n1,&n2,&n);
	}
	return 0;
}

	