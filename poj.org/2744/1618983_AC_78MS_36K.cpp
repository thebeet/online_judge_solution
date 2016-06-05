#include <stdio.h>
#include <memory.h>

long a[110];
double d[110];

int main()
{
	long i,j,n,r,p;
	double b,v,e,f,m;
	scanf("%d",&n);
	while (n)
	{
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		scanf("%lf",&b);
		scanf("%d%lf%lf%lf",&r,&v,&e,&f);
		p=1;
		for (i=0;i<a[n];i++)
		{
			for (j=0;j<p;j++)
				if (i-a[j]>=r)
					d[j]+=(1/(v-e*(i-a[j]-r)));
				else
					d[j]+=(1/(v-f*(r-(i-a[j]))));
			if (a[p]==i+1)
			{
				m=d[0];
				for (j=1;j<p;j++)
					if (d[j]<m) m=d[j];
				d[p]=m+b;
				p++;
			}
		}
		printf("%.4lf\n",d[n]-b);
		scanf("%d",&n);
	}
	return 0;
}

