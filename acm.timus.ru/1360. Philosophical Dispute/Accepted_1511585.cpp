#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932

double r;

bool eq(double a,double b)
{
	if (((a+r-0.000000001)>b) && ((a-r+0.000000001)<b))
	{
		return true;
	}
	return false;
}

int main()
{
	double x,y;
	double t;
	scanf("%lf%lf",&x,&y);
	scanf("%lf",&r);
	t=acos(y);
	while (eq(sin(sqrt(t)),x)==false)
	{
		t+=(PI*2);
	}
	printf("%.10lf\n",t);
	return 0;
}
