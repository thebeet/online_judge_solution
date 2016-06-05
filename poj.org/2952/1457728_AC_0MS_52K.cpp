#include <stdio.h>
#include <memory.h>

long m[21];
long a[21];
long pp[21][10];
long del[21];

int main()
{
	long i,j,k,h,n,g,mm,pm,nn;
	scanf("%d%d",&g,&n);
	while (g>0)
	{
		memset(del,false,sizeof(del));
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
				if ((del[j]==false) && (mm>=a[j]))
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
			del[pm]=true;
		}
		printf("%d\n",pp[1][1]);
		scanf("%d%d",&g,&n);
	}
	return 0;
}

			