#include <stdio.h>
#include <math.h>

double dist(double x1,double y1,double x2,double y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{
	long xxa,yya,xxb,yyb,xxc,yyc,i;
	double xa,ya,xb,yb,xc,yc,l,da,db,lmx,lmn,ld,lmx1,lmx2,lmy1,lmy2,dl1,dl2;
	scanf("%d%d%d%d%d%d%lf",&xxa,&yya,&xxb,&yyb,&xxc,&yyc,&l);
	xa=xxa;
	ya=yya;
	xb=xxb;
	yb=yyb;
	xc=xxc;
	yc=yyc;
	da=dist(xa,ya,xc,yc);
	db=dist(xb,yb,xc,yc);
	if (da>db) 
	{
		lmx=da;
		lmn=db;
	}
	else
	{
		lmx=db;
		lmn=da;
	}
	if ((xxa==xxb) && (yya==yyb))
	{
		lmx=sqrt(lmx);
		lmn=sqrt(lmn);
		lmx=lmx-l;
		lmn=lmn-l;
		if (lmx<0) lmx=0;
		if (lmn<0) lmn=0;
		printf("%.2lf\n%.2lf\n",lmn,lmx);
		return 0;
	}
	ld=((yb-ya)*(xc-xa)-(xb-xa)*(yc-ya))*((yb-ya)*(xc-xa)-(xb-xa)*(yc-ya))/dist(0,0,(xb-xa),(yb-ya));
	lmx1=(xa+xb)/2;
	lmx2=lmx1;
	lmy1=(ya+yb)/2;
	lmy2=lmy1;
	for (i=1;i<=30;i++)
	{
		lmx1=(lmx1+xa)/2;
		lmy1=(lmy1+ya)/2;
		lmx2=(lmx2+xb)/2;
		lmy2=(lmy2+yb)/2;
	}
	dl1=dist(lmx1,lmy1,xc,yc);
	dl2=dist(lmx2,lmy2,xc,yc);
	if (dl1>dl2) dl1=dl2;
	if (dl1<lmn) lmn=ld;
	lmx=sqrt(lmx);
	lmn=sqrt(lmn);
	lmx=lmx-l;
	lmn=lmn-l;
	if (lmx<0) lmx=0;
	if (lmn<0) lmn=0;
	printf("%.2lf\n%.2lf\n",lmn,lmx);
	return 0;
}
