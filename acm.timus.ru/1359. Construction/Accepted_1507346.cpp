#include <stdio.h>
#include <memory.h>
#include <math.h>

double t[60][60];

double mn(double a,double b)
{
	if (a>b) return b;
	else return a;
}

double tim(double x1,double y1,double x2,double y2)
{
	double v,s;
	v=(sqrt(20.0*y1)+sqrt(20.0*y2))/2.0;
	s=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return (s/v);
}
	
	

int main()
{
	long i,j,g,h,n,m;
	scanf("%ld%ld",&m,&n);
	memset(t,0,sizeof(t));
	for (i=0;i<=m;i++)
		for (j=0;j<=n;j++)
			t[i][j]=100000;
	t[0][0]=0;
	for (i=0;i<=m;i++)
		for (j=1;j<=n;j++)
			for (h=0;h<=i;h++)
				for (g=0;g<j;g++)
					if ((i!=h) || (g!=j))
						t[i][j]=mn(t[i][j],t[h][g]+tim(i,j,h,g));
	printf("%.10lf\n",t[m][n]);
	return 0;
}
