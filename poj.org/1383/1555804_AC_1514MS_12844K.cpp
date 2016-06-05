#include <stdio.h>
#include <memory.h>

long xx[1000010];
long yy[1000010];
char map[1010][1010];
long mm[1010][1010];
long r,c;

void bfs(long x,long y,long d)
{
	long xp,yp;
	d++;
	xp=x;yp=y+1;
	if ((yp<c) && (mm[xp][yp]==0) && (map[xp][yp]=='.'))
	{
		yy[0]++;
		xx[yy[0]]=xp;
		yy[yy[0]]=yp;
		mm[xp][yp]=d;
	}
	xp=x;yp=y-1;
	if ((yp>=0) && (mm[xp][yp]==0) && (map[xp][yp]=='.'))
	{
		yy[0]++;
		xx[yy[0]]=xp;
		yy[yy[0]]=yp;
		mm[xp][yp]=d;
	}
	xp=x+1;yp=y;
	if ((xp<r) && (mm[xp][yp]==0) && (map[xp][yp]=='.'))
	{
		yy[0]++;
		xx[yy[0]]=xp;
		yy[yy[0]]=yp;
		mm[xp][yp]=d;
	}
	xp=x-1;yp=y;
	if ((xp>=0) && (mm[xp][yp]==0) && (map[xp][yp]=='.'))
	{
		yy[0]++;
		xx[yy[0]]=xp;
		yy[yy[0]]=yp;
		mm[xp][yp]=d;
	}
}

int main()
{
	long ti,tn,i,j,x,y;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d",&c,&r);
		memset(map,0,sizeof(map));
		for (i=0;i<r;i++)
			scanf("%s",&map[i]);
		c--;
		r--;
		for (i=0;i<r;i++)
			for (j=0;j<c;j++)
				if (map[i][j]=='.')
				{
					x=i;
					y=j;
					break;
				}
		memset(xx,0,sizeof(xx));
		memset(yy,0,sizeof(yy));
		memset(mm,0,sizeof(mm));
		xx[0]=1;
		xx[1]=x;
		yy[0]=1;
		yy[1]=y;
		mm[x][y]=1;
		while (xx[0]<=yy[0])
		{
			bfs(xx[xx[0]],yy[xx[0]],mm[xx[xx[0]]][yy[xx[0]]]);
			xx[0]++;
		}
		x=xx[yy[0]];
		y=yy[yy[0]];
		memset(xx,0,sizeof(xx));
		memset(yy,0,sizeof(yy));
		memset(mm,0,sizeof(mm));
		xx[0]=1;
		xx[1]=x;
		yy[0]=1;
		yy[1]=y;
		mm[x][y]=1;
		while (xx[0]<=yy[0])
		{
			bfs(xx[xx[0]],yy[xx[0]],mm[xx[xx[0]]][yy[xx[0]]]);
			xx[0]++;
		}
		printf("Maximum rope length is %d.\n",mm[xx[yy[0]]][yy[yy[0]]]-1);
	}
	return 0;
}
	
