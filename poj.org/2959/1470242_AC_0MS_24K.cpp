#include <stdio.h>
#include <math.h>

#define pi 3.1415926535897932384626433832795

int main()
{
	long ti,tn,i,n,ans;
	double r1,r2,s,g;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%lf%lf%lf",&r1,&r2,&s);
		r1/=2;
		r2/=2;
		r1-=r2;
		s=s/2+r2;
		g=asin(s/r1);
		ans=long(pi/g+0.00000001);
		printf("%d\n",ans);
	}
	return 0;
}

	


