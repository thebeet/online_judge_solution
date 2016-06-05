#include <stdio.h>
#include <math.h>

int main()
{
	long i,a,b,x2,x3,s2,s3,ans;
	double t;
	scanf("%ld%ld",&a,&b);
	while ((a>0) && (b>0))
	{
		t=log(a);
		t=t/b;
		t=exp(t);
		x2=long(t);
		x3=x2+1;
		s2=1;s3=1;
		for (i=1;i<=b;i++)
		{
			s2*=x2;
			s3*=x3;
		}
		if ((s3-a)<(a-s2)) ans=x3;
		else ans=x2;
		printf("%ld\n",ans);
		scanf("%ld%ld",&a,&b);
	}
	return 0;
}
