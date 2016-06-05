#include <stdio.h>

struct mt
{
	long x1,x2,y1,y2,id,d;
};
mt mts[120];
mt t;

long mn(long a,long b)
{
	if (a<0) a=-a;
	if (b<0) b=-b;
	if (a>b) return b;
	else return a;
}

int main()
{
	long i,j,n,x,y,x1,x2,y1,y2;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if (x1<x2)
		{
			mts[i].x1=x1;
			mts[i].x2=x2;
		}
		else
		{
			mts[i].x1=x2;
			mts[i].x2=x1;
		}
		if (y1<y2)
		{
			mts[i].y1=y1;
			mts[i].y2=y2;
		}
		else
		{
			mts[i].y1=y2;
			mts[i].y2=y1;
		}
		mts[i].id=i;
	}
	scanf("%d%d",&x,&y);
	for (i=1;i<=n;i++)
	{
		if ((x>=mts[i].x1) && (x<=mts[i].x2) && (y>=mts[i].y1) && (y<=mts[i].y2))
		{
			mts[i].d=0;
			continue;
		}
		if ((x>=mts[i].x1) && (x<=mts[i].x2))
		{
			mts[i].d=mn(mts[i].y1-y,y-mts[i].y2);
			mts[i].d*=mts[i].d;
			continue;
		}
		if ((y>=mts[i].y1) && (y<=mts[i].y2))
		{
			mts[i].d=mn(mts[i].x1-x,x-mts[i].x2);
			mts[i].d*=mts[i].d;
			continue;
		}
		mts[i].d=(mts[i].x1-x)*(mts[i].x1-x)+(mts[i].y1-y)*(mts[i].y1-y);
		mts[i].d=mn(mts[i].d,(mts[i].x1-x)*(mts[i].x1-x)+(mts[i].y2-y)*(mts[i].y2-y));
		mts[i].d=mn(mts[i].d,(mts[i].x2-x)*(mts[i].x2-x)+(mts[i].y1-y)*(mts[i].y1-y));
		mts[i].d=mn(mts[i].d,(mts[i].x2-x)*(mts[i].x2-x)+(mts[i].y2-y)*(mts[i].y2-y));
	}
	for (i=2;i<=n;i++)
		for (j=1;j<=i;j++)
			if (mts[i].d<mts[j].d)
			{
				t=mts[i];
				mts[i]=mts[j];
				mts[j]=t;
			}
	for (i=1;i<n;i++)
		printf("%d ",mts[i].id);
	printf("%d\n",mts[n].id);
	return 0;
}
