#include <stdio.h>

__int64 a[55];
__int64 pa[55];
__int64 b[5];
__int64 da[5];
double x[5];

int main()
{
	__int64 ti,tn,i,j,k;
	scanf("%I64d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		for (i=1;i<=3;i++)
			scanf("%I64d%I64d%I64d%I64d",&a[i*10+1],&a[i*10+2],&a[i*10+3],&b[i]);
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
			printf("%I64d ",da[i]);
		printf("%I64d\n",da[4]);
		if (da[4]!=0)
		{
			for (i=1;i<=3;i++)
			{
				x[i]=da[i]*1.0/da[4];
				if ((x[i]>-0.00049999999999) && (x[i]<0.0001)) 
					x[i]=0.0001;
			}
			printf("Unique solution: %.3lf %.3lf %.3lf\n\n",x[1],x[2],x[3]);
		}
		else
		{
			printf("No unique solution\n\n");
		}
	}
	return 0;
}
	