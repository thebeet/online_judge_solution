#include <stdio.h>

int main()
{
	long i,n,x,y,x0,y0,xp,yp;
	long x1,x2,y1,y2,xy1,xy2,yx1,yx2;
	scanf("%d",&n);
	x1=100000;
	y1=100000;
	x2=-100000;
	y2=-100000;
	xy1=100000;
	xy2=-100000;
	yx1=100000;
	yx2=-100000;
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if (x1>x) x1=x;
		if (y1>y) y1=y;
		if (x2<x) x2=x;
		if (y2<y) y2=y;
		if (xy1>x+y) xy1=x+y;
		if (xy2<x+y) xy2=x+y;
		if (yx1>y-x) yx1=y-x;
		if (yx2<y-x) yx2=y-x;
	}
	x=x2;
	y=yx1+x2;
	x0=x;
	y0=y;
	xp=x;
	yp=y;
	printf("%d %d\n",x,y);
	x=x2;
	y=xy2-x2;
	if (((x!=xp) || (y!=yp)) && ((x!=x0) || (y!=y0)))
	{
		printf("%d %d\n",x,y);
		xp=x;
		yp=y;
	}
	x=xy2-y2;
	y=y2;
	if (((x!=xp) || (y!=yp)) && ((x!=x0) || (y!=y0)))
	{
		printf("%d %d\n",x,y);
		xp=x;
		yp=y;
	}
	x=y2-yx2;
	y=y2;
	if (((x!=xp) || (y!=yp)) && ((x!=x0) || (y!=y0)))
	{
		printf("%d %d\n",x,y);
		xp=x;
		yp=y;
	}
	x=x1;
	y=yx2+x1;
	if (((x!=xp) || (y!=yp)) && ((x!=x0) || (y!=y0)))
	{
		printf("%d %d\n",x,y);
		xp=x;
		yp=y;
	}
	x=x1;
	y=xy1-x1;
	if (((x!=xp) || (y!=yp)) && ((x!=x0) || (y!=y0)))
	{
		printf("%d %d\n",x,y);
		xp=x;
		yp=y;
	}
	x=xy1-y1;
	y=y1;
	if (((x!=xp) || (y!=yp)) && ((x!=x0) || (y!=y0)))
	{
		printf("%d %d\n",x,y);
		xp=x;
		yp=y;
	}
	x=y1-yx1;
	y=y1;
	if (((x!=xp) || (y!=yp)) && ((x!=x0) || (y!=y0)))
	{
		printf("%d %d\n",x,y);
		xp=x;
		yp=y;
	}
	return 0;
}



