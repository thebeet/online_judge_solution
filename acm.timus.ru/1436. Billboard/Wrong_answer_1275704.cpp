#include <stdio.h>
#include <math.h>

#define minn 0.000000000001
#define pi 3.1415926535897932384626433832795

int main()
{
	double x1,y1,x2,y2,xa,xb,x,t,m,t1,t2;
	__int64 i;
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	if ((y1*y2)<minn)
		printf("%.6lf\n",pi);
	else
	{
		if (y1<0) y1=-y1;
		if (y2<0) y2=-y2;
		if (x1>x2)
		{
			t=x1;
			x1=x2;
			x2=t;
		}
		if (y2<y1)
		{
			t=y1;
			y1=y2;
			y2=t;
		}
		xa=x1;
		xb=10000;
		t1=pi/2-atan(y2/(x2-x1));
		m=t1;
		t2=pi/2-atan(y1/(x2-x1));
		if (m<t2) m=t2;
		while ((xb-xa)>=1)
		{
			x=(xa+xb)/2;
			if (x>x2+minn)
				t=atan(y2/(x-x2))-atan(y1/(x-x1));
			else
				if (x<x2-minn)
					t=pi-atan(y1/(x-x1))-atan(y2/(x2-x));
				else
					t=pi/2-atan(y1/(x-x1));
			if (t>m)
				m=t;
			x=x+0.01;
			x=(xa+xb)/2;
			if (x>x2+minn)
				t1=atan(y2/(x-x2))-atan(y1/(x-x1));
			else
				if (x<x2-minn)
					t1=pi-atan(y1/(x-x1))-atan(y2/(x2-x));
				else
					t1=pi/2-atan(y1/(x-x1));
			x=x-0.01;
			if (t1>t) xa=x;
			else xb=x;
		}
		for (i=__int64(floor(xa*1000000+0.1)+1);i<=__int64(ceil(xb*1000000-0.1));i++)
		{
			x=i/1000000.0;
			if (x>x2+minn)
				t=atan(y2/(x-x2))-atan(y1/(x-x1));
			else
				if (x<x2-minn)
					t=pi-atan(y1/(x-x1))-atan(y2/(x2-x));
				else
					t=pi/2-atan(y1/(x-x1));
			if (t>m)
				m=t;
		}
		printf("%.6lf\n",m);
	}
	return 0;
}
			