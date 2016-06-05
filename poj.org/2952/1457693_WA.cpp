#include <stdio.h>
#include <memory.h>

long m[21];
long a[21];
long pp[21][10];

int main()
{
	long i,j,k,h,n,g,mm,pm,nn;
	scanf("%d%d",&g,&n);
	while (g>0)
	{
		for (i=1;i<=g;i++)
		{
			scanf("%d",&m[i]);
			for (j=1;j<=n;j++)
				scanf("%d",&pp[i][j]);
		}
		nn=n;
		for (i=1;i<nn;i++)
		{
			memset(a,0,sizeof(a));
			for (j=1;j<=g;j++)
				a[pp[j][1]]=a[pp[j][1]]+m[j];
			mm=10000000;
			for (j=1;j<=n;j++)
				if ((mm>=a[j]) && (a[j]>0))
				{
					mm=a[j];
					pm=j;
				}
			for (j=1;j<=g;j++)
				for (k=1;k<=n;k++)
					if (pp[j][k]==pm)
					{
						for (h=k+1;h<=n;h++)
							pp[j][h-1]=pp[j][h];
						break;
					}
			n--;
		}
		printf("%d\n",pp[1][1]);
		scanf("%d%d",&g,&n);
	}
	return 0;
}

			