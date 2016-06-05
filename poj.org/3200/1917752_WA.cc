#include <stdio.h>
#include <memory.h>

long n;
double r[1010];
double x[1010];
double y[1010];

bool check(double xx1,double yy1,double xx2,double yy2,double r)
{
	if ((xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2)<=r*r) return true;
	else return false;
}

int main()
{
	long i,j;
	double m,tx,ty;
	bool ans;
	scanf("%ld",&n);
	while (n>0)
	{
		memset(r,0,sizeof(r));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		ans=true;
		for (i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
		}
		for (i=0;i<n;i++)
		{
			m=0.0;
			tx=0.0;
			ty=0.0;
			for (j=i;j>=1;j--)
			{
				tx=(m*tx+r[j]*r[j]*x[j])/(m+r[j]*r[j]);
				ty=(m*ty+r[j]*r[j]*y[j])/(m+r[j]*r[j]);
				m+=(r[j]*r[j]);
				if (check(tx,ty,x[j-1],y[j-1],r[j-1])==false)
				{
					ans=false;
					break;
				}
			}
			if (ans==false) break;
		}
		if (i>=n) 
		{
			printf("Feasible\n");
		}
		else
		{
			printf("Unfeasible %ld\n",i);
		}
		scanf("%ld",&n);
	}
	return 0;
}
