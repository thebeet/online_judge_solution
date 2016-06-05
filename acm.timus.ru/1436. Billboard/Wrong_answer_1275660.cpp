#include <stdio.h>
#include <math.h>

#define minn 0.000000000001
#define pi 3.1415926535897932384626433832795

int main()
{
	double x1,y1,x2,y2,xa,xb,x,t,m;
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	if ((y1*y2)<minn)
		printf("%.6lf\n",pi);
	else
	{
		if (y1<0) y1=-y1;
		if (y2<0) y2=-y2;
		m=-1;
		if (x1>x2)
		{
			t=x1;
			x1=x2;
			x2=t;
		}
		if (y2>y1)
		{
			t=y1;
			y1=y2;
			y2=t;
		}
		xa=x1;
		xb=x2;
		m=pi/2-atan(y1/(x2-x1));
		while ((xb-xa)>minn)
		{
			x=(xa+xb)/2;
			t=pi-atan(y1/(x-x1))-atan(y2/(x2-x));
			if (t>m)
			{
				xb=x;
				m=t;
			}
			else xa=x;
		}
		printf("%.6lf\n",m);
	}
	return 0;
}
			