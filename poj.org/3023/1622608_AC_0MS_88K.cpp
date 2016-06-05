#include <stdio.h>
#include <memory.h>

__int64 x1[1010];
__int64 y1[1010];
__int64 x2[1010];
__int64 y2[1010];
__int64 k[52];
__int64 vx[52][22];
__int64 vy[52][22];

bool cc(__int64 x1,__int64 y1,__int64 x2,__int64 y2,__int64 x3,__int64 y3,__int64 x4,__int64 y4)
{
	__int64 xa,xb,ya,yb,t1,t2,t3,t4;
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
	__int64 i,j,h,n,m,w1,w2;
	memset(x1,0,sizeof(x1));
	memset(y1,0,sizeof(y1));
	memset(x2,0,sizeof(x2));
	memset(y2,0,sizeof(y2));
	memset(k,0,sizeof(k));
	memset(vx,0,sizeof(vx));
	memset(vy,0,sizeof(vy));
	scanf("%I64d",&n);
	for (i=1;i<=n;i++)
		scanf("%I64d%I64d%I64d%I64d",&x1[i],&y1[i],&x2[i],&y2[i]);
	scanf("%I64d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%I64d",&k[i]);
		for (j=1;j<=k[i];j++)
			scanf("%I64d%I64d",&vx[i][j],&vy[i][j]);
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
			printf("Submarine %I64d is partially on land.\n",i);
			continue;
		}
		for (j=1;j<=m;j++)
		{
			w1=0;
			w2=0;
			for (h=1;h<k[j];h++)
			{
				if (cc(x1[i],y1[i],3000,5000,vx[j][h],vy[j][h],vx[j][h+1],vy[j][h+1])) w1++;
				if (cc(x2[i],y2[i],3000,5000,vx[j][h],vy[j][h],vx[j][h+1],vy[j][h+1])) w2++;
			}
			if (cc(x1[i],y1[i],3000,5000,vx[j][h],vy[j][h],vx[j][1],vy[j][1])) w1++;
			if (cc(x2[i],y2[i],3000,5000,vx[j][h],vy[j][h],vx[j][1],vy[j][1])) w2++;
/*			if ((w1&1)!=(w2&1)) 
				printf("fault\n");*/
			if (w1&1) break;
		}
		if (j<=m) printf("Submarine %I64d is completely on land.\n",i);
		else printf("Submarine %I64d is still in water.\n",i);
	}
	return 0;
}
