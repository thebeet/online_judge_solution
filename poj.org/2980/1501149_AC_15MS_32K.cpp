#include <stdio.h>
#include <math.h>

long t1[1011],t2[1011];

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	long i,n,n1,n2,n0,r,m,t0,y1,y2,y0;
	scanf("%d%d%d%d",&n1,&n2,&n0,&r);
	while (r>0)
	{
		m=1000000000;
		y0=100;
		t0=0;
		while (y0>0)
		{
			t0++;
			y0=y0-r;
		}
		for (i=0;i<=1000;i++)
		{
			t1[i]=0;
			t2[i]=0;
			y1=100;
			y2=100;
			while ((y1>0) && (t1[i]<i))
			{
				t1[i]++;
				y1=y1-(r+2);
			}
			while (y1>0)
			{
				t1[i]++;
				y1=y1-r;
			}
			while ((y2>0) && (t2[i]<i))
			{
				t2[i]++;
				y2=y2-(r-1);
			}
			while (y2>0)
			{
				t2[i]++;
				y2=y2-r;
			}
			if ((t1[i]*n1+t2[i]*n2+t0*n0)<m) m=t1[i]*n1+t2[i]*n2+t0*n0;
		}
		printf("%d\n",m);
		scanf("%d%d%d%d",&n1,&n2,&n0,&r);
	}
	return 0;
}



			


