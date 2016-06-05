#include <stdio.h>

long a[55];
long pa[55];
long b[5];
long da[5];
double x[5];

int main()
{
	long ti,tn,i,j,k;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		for (i=1;i<=3;i++)
			scanf("%d%d%d%d",&a[i*10+1],&a[i*10+2],&a[i*10+3],&b[i]);
		for (i=1;i<=3;i++)
			for (j=1;j<=3;j++)
				pa[i*10+j]=a[i*10+j];
		da[4]=pa[11]*(pa[22]*pa[33]-pa[23]*pa[32])-pa[12]*(pa[21]*pa[33]-pa[23]*pa[31])+pa[13]*(pa[21]*pa[32]-pa[22]*pa[31]);
		for (k=1;k<=3;k++)
		{
			for (i=1;i<=3;i++)
				for (j=1;j<=3;j++)
					pa[i*10+j]=a[i*10+j];
			for (i=1;i<=3;i++)
				pa[i*10+k]=b[i];
			da[k]=pa[11]*(pa[22]*pa[33]-pa[23]*pa[32])-pa[12]*(pa[21]*pa[33]-pa[23]*pa[31])+pa[13]*(pa[21]*pa[32]-pa[22]*pa[31]);
		}
		for (i=1;i<=3;i++)
			printf("%d ",da[i]);
		printf("%d\n",da[4]);
		if (da[4]!=0)
		{
			for (i=1;i<=3;i++)
			{
				x[i]=da[i]*1.0/da[4];
				if ((x[i]>-0.000499999999) && (x[i]<0.1)) x[i]=0;
			}
			printf("Unique solution: %.3lf %.3lf %.3lf\n\n",da[1]*1.0/da[4],da[2]*1.0/da[4],da[3]*1.0/da[4]);
		}
		else
		{
			printf("No unique solution\n\n");
		}
	}
	return 0;
}
	