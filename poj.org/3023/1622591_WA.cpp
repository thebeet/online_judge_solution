#include <stdio.h>
#include <memory.h>

long x1[1010];
long y1[1010];
long x2[1010];
long y2[1010];
long k[52];
long vx[52][22];
long vy[52][22];

bool cc(long x1,long y1,long x2,long y2,long x3,long y3,long x4,long y4)
{
	long xa,xb,ya,yb,t1,t2,t3,t4;
	xa=x3-x1;
	ya=y3-y1;
	xb=x4-x1;
	yb=y4-y1;
	t1=xa*yb-xb*ya;
	xa=x3-x2;
	ya=y3-y2;
	xb=x4-x2;
	yb=y4-y2;
	t2=xa*yb-xb*ya;
	xa=x1-x3;
	ya=y1-y3;
	xb=x2-x3;
	yb=y2-y3;
	t3=xa*yb-xb*ya;
	xa=x1-x4;
	ya=y1-y4;
	xb=x2-x4;
	yb=y2-y4;
	t4=xa*yb-xb*ya;
	if ((t1*t2<0) && (t3*t4<0)) return true;
	else return false;
}

int main()
{
	long i,j,h,n,m,w1,w2;
	memset(x1,0,sizeof(x1));
	memset(y1,0,sizeof(y1));
	memset(x2,0,sizeof(x2));
	memset(y2,0,sizeof(y2));
	memset(k,0,sizeof(k));
	memset(vx,0,sizeof(vx));
	memset(vy,0,sizeof(vy));
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	scanf("%d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d",&k[i]);
		for (j=1;j<=k[i];j++)
			scanf("%d%d",&vx[i][j],&vy[i][j]);
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			for (h=1;h<k[j];h++)
				if (cc(x1[i],y1[i],x2[i],y2[i],vx[j][h],vy[j][h],vx[j][h+1],vy[j][h+1])) break;
			if (h<k[j]) 
				break;
			if (cc(x1[i],y1[i],x2[i],y2[i],vx[j][h],vy[j][h],vx[j][1],vy[j][1])) break;
		}
		if (j<=m)
		{
			printf("Submarine %d is partially on land.\n",i);
			continue;
		}
		for (j=1;j<=m;j++)
		{
			w1=0;
			w2=0;
			for (h=1;h<k[j];h++)
			{
				if (cc(x1[i],y1[i],x1[i],5000,vx[j][h],vy[j][h],vx[j][h+1],vy[j][h+1])) w1++;
				if (cc(x2[i],y2[i],x2[i],5000,vx[j][h],vy[j][h],vx[j][h+1],vy[j][h+1])) w2++;
			}
			if (cc(x1[i],y1[i],x1[i],5000,vx[j][h],vy[j][h],vx[j][1],vy[j][1])) w1++;
			if (cc(x2[i],y2[i],x2[i],5000,vx[j][h],vy[j][h],vx[j][1],vy[j][1])) w2++;
/*			if ((w1&1)!=(w2&1)) 
				printf("fault\n");*/
			if (w1&1) break;
		}
		if (j<=m) printf("Submarine %d is completely on land.\n",i);
		else printf("Submarine %d is still in water.\n",i);
	}
	return 0;
}
