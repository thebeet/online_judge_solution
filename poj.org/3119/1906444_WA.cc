#include <stdio.h>
#include <memory.h>

long x[200000];
long y[200000];
long p[200000];
bool side[200000];

int main()
{
	long ti,tn,a,b,i,j,n,m,k,xx,yy;
	scanf("%ld",&tn);
	x[0]= 0;y[0]= 0;
	x[1]=-1;y[1]= 0;
	x[2]=-1;y[2]= 1;
	k=2;
	xx=-1;yy=1;
	for (i=2;k<=70000;i++)
	{
		for (j=1;j<=i;j++)
		{
			k++;
			xx++;
			x[k]=xx;
			y[k]=yy;
		}
		for (j=1;j<=i;j++)
		{
			k++;
			yy--;
			x[k]=xx;
			y[k]=yy;
		}
		i++;
		for (j=1;j<=i;j++)
		{
			k++;
			xx--;
			x[k]=xx;
			y[k]=yy;
		}
		for (j=1;j<=i;j++)
		{
			k++;
			yy++;
			x[k]=xx;
			y[k]=yy;
		}
	}
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%ld%ld",&a,&b);
		scanf("%ld",&n);
		printf("Caso %ld\n",ti);
		memset(p,0,sizeof(p));
		k=0;
		for (i=1;k<=100000;i++)
		{
			if (y[i]!=a*x[i]+b)
			{
				k++;
				p[k]=i;
			}
		}
		for (i=1;i<=n;i++)
		{
			scanf("%ld%ld",&xx,&yy);
			if ((y[p[xx]]-a*x[p[xx]]-b)*(y[p[yy]]-a*x[p[yy]]-b)<0)
			{
				printf("Lados opostos da fronteira\n");
			}
			else
			{
				printf("Mesmo lado da fronteira\n");
			}
		}
	}
	return 0;
}
		