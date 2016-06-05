#include <stdio.h>
#include <memory.h>

double x[110];
double y[110];
double r[110];
bool d[110][110];
long p[110];
long n;

#define e 0.0000000001

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

long ss(long w,long c)
{
	long i,s;
	s=0;
	for (i=1;i<=n;i++)
		if ((d[w][i]) && (p[i]==0))
		{
			p[i]=c;
			s++;
			s+=ss(i,c);
		}
	return s;
}

int main()
{
	long i,j,k,m;
	scanf("%d",&n);
	while (n>0)
	{
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(r,0,sizeof(r));
		memset(d,false,sizeof(d));
		memset(p,0,sizeof(p));
		for (i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
			for (j=1;j<i;j++)
				if ((((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+e)<(r[i]+r[j])*(r[i]+r[j])) && (((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])-e)>(r[i]-r[j])*(r[i]-r[j])))
				{
					d[i][j]=true;
					d[j][i]=true;
				}
		}
		k=0;
		m=0;
		for (i=1;i<=n;i++)
			if (p[i]==0)
			{
				k++;
				p[i]=k;
				m=mx(m,ss(i,k)+1);
			}
		printf("The largest component contains %d rings\n",m);
		scanf("%d",&n);
	}
	return 0;
}







