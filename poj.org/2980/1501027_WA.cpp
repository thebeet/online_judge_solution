#include <stdio.h>
#include <math.h>

long t1[200],t2[200];

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	long i,n,n1,n2,n0,r,m,t0,y1,y2;
	scanf("%d%d%d%d",&n1,&n2,&n0,&r);
	while (r>0)
	{
		m=100000000;
		t0=long(ceil(100.0/r-0.0000001));
		for (i=0;i<=100;i++)
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
			while ((y2>0) && (t2[i]<i))
			{
				t2[i]++;
				y2=y2-(r-1);
			}
			t1[i]=t1[i]+long(ceil(y1/r-0.0000001));
			t2[i]=t2[i]+long(ceil(y2/r-0.0000001));
			if ((t1[i]*n1+t2[i]*n2+t0*n0)<m) m=t1[i]*n1+t2[i]*n2+t0*n0;
		}
		printf("%d\n",m+1);
		scanf("%d%d%d%d",&n1,&n2,&n0,&r);
	}
	return 0;
}



			


