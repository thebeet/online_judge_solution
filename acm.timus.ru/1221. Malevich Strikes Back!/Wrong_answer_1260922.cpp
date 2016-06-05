#include <stdio.h>
#include <memory.h>
#define max 203
long map[max][max];
long tm[max][max];

void crt(long m)
{
	long i,j;
	memset(tm,0,sizeof(tm));
	for (i=1;i<=m/2;i++)
	{
		for (j=1;j<=m/2-i+1;j++)
			tm[i][j]=1;
		for (j=m/2+i+1;j<=m;j++)
			tm[i][j]=1;
	}
	for (i=m/2+2;i<=m;i++)
	{
		for (j=1;j<=i-m/2-1;j++)
			tm[i][j]=1;
		for (j=m-i+m/2+2;j<=m;j++)
			tm[i][j]=1;
	}
}

int main()
{
	long i,j,k,h,n,m,mx;
	bool flag;
	scanf("%d",&n);
	while (n>0)
	{
		mx=0;
		memset(map,2,sizeof(map));
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				scanf("%d",&map[i][j]);
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				flag=false;
				for (k=j;k<=n;k++)
				{
					if (map[i][k]!=1) 
						break;
				}
				if (k==j) continue;
				for (h=k+1;h<=2*k-j;h++)
					if (map[i][h]!=1)
					{
						flag=true;
						break;
					}
				if (flag) continue;
				m=(k-j)*2+1;
				crt(m);
				for 