#include <stdio.h>
#include <math.h>

double x11,y11,z11,x22,y22,z22,xa,ya,za;
double a,b,c,x,y;

long double_eq(double d1,double d2)
{
	if ((d1+0.00000000001)<d2) return -1;
	if ((d1-0.00000000001)>d2) return 1;
	return 0;
}

void change(double x,double y)
{
	if (double_eq(x,c)<1)
	{
		xa=0;
		ya=y-c-b;
		za=c-x;
		return;
	}
	if (double_eq(x,a+c)>-1)
	{
		xa=a;
		ya=y-c-b;
		za=x-a-c;
		return;
	}
	xa=x-c;
	if (double_eq(y,b)<1)
	{
		ya=b-y;
		za=c;
		return;
	}
	if (double_eq(y,b+c)<1)
	{
		ya=0;
		za=c+b-y;
		return;
	}
	if (double_eq(y,b+b+c)<1)
	{
		ya=y-b-c;
		za=0;
		return;
	}
	ya=b;
	za=y-b-b-c;
}

int main()
{
	scanf("%lf%lf%lf",&a,&b,&c);
	scanf("%lf%lf",&x,&y);
	change(x,y);
	x11=xa;y11=ya;z11=za;
	scanf("%lf%lf",&x,&y);
	change(x,y);
	x22=xa;y22=ya;z22=za;
	printf("%.16lf\n",sqrt((x11-x22)*(x11-x22)+(y11-y22)*(y11-y22)+(z11-z22)*(z11-z22)));
	return 0;
}
