#include <stdio.h>
#include <memory.h>

long map[200][200];
long ans[200][200];
long tans[200][200];
bool gone[200][200];
long d[200][200];
long x[40000];
long y[40000];
long p[40000];


int main()
{
	long i,j,w,h,tx,ty;
	memset(map,0,sizeof(map));
	memset(ans,0,sizeof(ans));
	memset(tans,0,sizeof(tans));
	memset(d,0,sizeof(d));
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(gone,true,sizeof(gone));
	scanf("%d%d",&w,&h);
	for (i=1;i<=h;i++)
		for (j=1;j<=w;j++)
		{
			scanf("%d",&map[i][j]);
			if (map[i][j]!=0) 
			{
				ans[i][j]=-1;
				d[i][j]=1;
				x[0]++;
				x[x[0]]=i;
				y[x[0]]=j;
				p[x[0]]=map[i][j];
				gone[i][j]=false;
			}
		}
	y[0]=1;
	while (y[0]<=x[0])
	{
		tx=x[y[0]];
		ty=y[y[0]];
		if (((d[tx+1][ty]==0) || (d[tx+1][ty]>d[tx][ty])) && (tx<h))
		{
			ans[tx+1][ty]|=p[y[0]];
			if (gone[tx+1][ty])
			{
				d[tx+1][ty]=d[tx][ty]+1;
				x[0]++;
				x[x[0]]=tx+1;
				y[x[0]]=ty;
				p[x[0]]=p[y[0]];
				gone[tx+1][ty]=false;
			}
		}
		if (((d[tx-1][ty]==0) || (d[tx-1][ty]>d[tx][ty])) && (tx>1))
		{
			ans[tx-1][ty]|=p[y[0]];
			if (gone[tx-1][ty])
			{
				d[tx-1][ty]=d[tx][ty]+1;
				x[0]++;
				x[x[0]]=tx-1;
				y[x[0]]=ty;
				p[x[0]]=p[y[0]];
				gone[tx-1][ty]=false;
			}
		}
		if (((d[tx][ty+1]==0) || (d[tx][ty+1]>d[tx][ty])) && (ty<w))
		{
			ans[tx][ty+1]|=p[y[0]];
			if (gone[tx][ty+1])
			{
				d[tx][ty+1]=d[tx][ty]+1;
				x[0]++;
				x[x[0]]=tx;
				y[x[0]]=ty;
				p[x[0]]=p[y[0]];
				gone[tx][ty+1]=false;
			}
		}
		if (((d[tx][ty-1]==0) || (d[tx][ty-1]>d[tx][ty])) && (ty>1))
		{
			ans[tx][ty-1]|=p[y[0]];
			if (gone[tx][ty-1])
			{
				d[tx][ty-1]=d[tx][ty]+1;
				x[0]++;
				x[x[0]]=tx;
				y[x[0]]=ty-1;
				p[x[0]]=p[y[0]];
				gone[tx][ty-1]=false;
			}
		}
		y[0]++;
	}
	for (i=1;i<=h;i++)
	{
		for (j=1;j<=w;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}

