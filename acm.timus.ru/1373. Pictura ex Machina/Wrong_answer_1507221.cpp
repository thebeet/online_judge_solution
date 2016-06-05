#include <stdio.h>

double maxx,maxy,minx,miny;

double mx(double a,double b)
{
	if (a>b) return a;
	else return b;
}

double mn(double a,double b)
{
	if (a<b) return a;
	else return b;
}

long double_eq(long a,long b)
{
	if (a-0.0000000001>b) return 1;
	if (a+0.0000000001<b) return -1;
	return 0;
}

int main()
{
	freopen("Pictura_ex_machina.in","r",stdin);
	double x1,y1,x2,y2,xm,ym,x3,y3;
	maxx=-100000;
	maxy=-100000;
	minx=100000;
	miny=100000;
	while (scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		xm=(x1+x2)/2.0;
		ym=(y1+y2)/2.0;
		x3=xm-(ym-y1);
		y3=ym+(xm-x1);
		maxx=mx(maxx,x1);
		maxx=mx(maxx,x2);
		maxx=mx(maxx,x3);
		maxy=mx(maxy,y1);
		maxy=mx(maxy,y2);
		maxy=mx(maxy,y3);
		minx=mn(minx,x1);
		minx=mn(minx,x2);
		minx=mn(minx,x3);
		miny=mn(miny,y1);
		miny=mn(miny,y2);
		miny=mn(miny,y3);
	}
	if (maxx<-50000)
	{
		printf("0.0000 0.0000\n");
		return 0;
	} 
	printf("%.4lf %.4lf\n",maxx-minx,maxy-miny);
	return 0;
}
