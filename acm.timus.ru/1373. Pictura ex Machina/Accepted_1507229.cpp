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
//	freopen("Pictura_ex_machina.in","r",stdin);
	long x1,y1,x2,y2;
	double xm,ym,x3,y3;
	maxx=-100000;
	maxy=-100000;
	minx=100000;
	miny=100000;
	while (scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2)!=EOF)
	{
		xm=(x1+x2)/2.0;
		ym=(y1+y2)/2.0;
		x3=xm-(ym-y1);
		y3=ym+(xm-x1);
		if (x1>maxx) maxx=x1;
		if (x2>maxx) maxx=x2;
		if (x3>maxx) maxx=x3;
		if (y1>maxy) maxy=y1;
		if (y2>maxy) maxy=y2;
		if (y3>maxy) maxy=y3;
		if (x1<minx) minx=x1;
		if (x2<minx) minx=x2;
		if (x3<minx) minx=x3;
		if (y1<miny) miny=y1;
		if (y2<miny) miny=y2;
		if (y3<miny) miny=y3;
	}
	if (maxx<-50000)
	{
		printf("0.0000 0.0000\n");
		return 0;
	} 
	printf("%.4lf %.4lf\n",maxx-minx,maxy-miny);
	return 0;
}
