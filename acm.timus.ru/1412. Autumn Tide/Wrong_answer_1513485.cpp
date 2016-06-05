#include <stdio.h>
#include <math.h>

double myabs(double a)
{
	if (a>0.0)
	{
		return a;
	}
	else
	{
		return -a;
	}
}

int main()
{
	long i,l;
	double n,m,x,y,s,xx1,xx2,yy1,yy2,d;
	scanf("%lf%lf",&n,&m);
	s=n*m;
	scanf("%ld",&l);
	for (i=1;i<=l;i++)
	{
		scanf("%lf%lf",&x,&y);
		if (myabs(y)<1.0)
		{
			d=sqrt(1.0-y*y);
			xx1=x-d;
			xx2=x+d;
			if (xx1<0) xx1=0;
			if (xx2>n) xx2=n;
			s-=((xx2-xx1)*y/2.0);
		}
		if (myabs(m-y)<1.0)
		{
			d=sqrt(1.0-(m-y)*(m-y));
			xx1=x-d;
			xx2=x+d;
			if (xx1<0) xx1=0;
			if (xx2>n) xx2=n;
			s-=((xx2-xx1)*(m-y)/2.0);
		}
		if (myabs(x)<1.0)
		{
			d=sqrt(1.0-x*x);
			yy1=y-d;
			yy2=y+d;
			if (yy1<0) yy1=0;
			if (yy2>m) yy2=m;
			s-=((yy2-yy1)*x/2.0);
		}
		if (myabs(n-x)<1.0)
		{
			d=sqrt(1.0-(n-x)*(n-x));
			yy1=y-d;
			yy2=y+d;
			if (yy1<0) yy1=0;
			if (yy2>m) yy2=m;
			s-=((yy2-yy1)*(n-x)/2.0);
		}
	}
	printf("%.10lf\n",s);
	return 0;
}
