#include <stdio.h>
#include <memory.h>

long h[2][3010];

int main()
{
	long i,j,n,m,p,p1,d1,d2;
	scanf("%d%d",&m,&n);
	if ((m*n)<1)
	{
		printf("Yes\n");
		return 0;
	}
	p=0;
	p1=1;
	memset(h,0,sizeof(h));
	for (j=1;j<=n;j++)
		scanf("%d",&h[p][j]);
	for (i=2;i<=m;i++)
	{
		for (j=1;j<=n;j++)
			scanf("%d",&h[p1][j]);
		d1=1;
		while (d1<=n)
		{
			while ((h[p][d1]!=1) && (d1<n))
				d1++;
			if ((d1==n) && (h[p][d1]==0)) break;
			d2=d1+1;
			while (h[p][d2]==1) 
				d2++;
			if (h[p1][d1]==1)
			{
				for (j=d1;j<d2;j++)
					if (h[p1][j]==0)
					{
						printf("No\n");
						return 0;
					}
			}
			else
			{
				for (j=d1;j<d2;j++)
					if (h[p1][j]==1)
					{
						printf("No\n");
						return 0;
					}
			}
			if ((h[p1][d1-1]==1) && (h[p1][d1]==1))
			{
				printf("No\n");
				return 0;
			}
			if ((h[p1][d2]==1) && (h[p1][d2-1]==1))
			{
				printf("No\n");
				return 0;
			}
			d1=d2;
			p^=1;
			p1^=1;
		}
	}
	printf("Yes\n");
	return 0;
}






	