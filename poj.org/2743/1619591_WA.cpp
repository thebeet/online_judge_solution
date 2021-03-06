#include <stdio.h>
#include <memory.h>

#define MAXN 7

long w[MAXN];
double a[MAXN];
double b[MAXN];
double ans,r;

double mx(double d1,double d2)
{
	if (d1>d2) return d1;
	else return d2;
}

void ss(long n,long w[MAXN],double a[MAXN],double b[MAXN])
{
	long i,j,h;
	double pa,pb,ba,bb;
	long tw[MAXN];
	double ta[MAXN];
	double tb[MAXN];
	if (n==1)
	{
		if ((ans<a[1]+b[1]) && (a[1]+b[1]<r))
			ans=a[1]+b[1];
		return;
	}
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++)
		{
			memset(tw,0,sizeof(tw));
			memset(ta,0,sizeof(ta));
			memset(tb,0,sizeof(tb));
			for (h=1;h<i;h++)
			{
				tw[h]=w[h];
				ta[h]=a[h];
				tb[h]=b[h];
			}
			for (h=i+1;h<j;h++)
			{
				tw[h]=w[h];
				ta[h]=a[h];
				tb[h]=b[h];
			}
			for (h=j;h<n;h++)
			{
				tw[h]=w[h+1];
				ta[h]=a[h+1];
				tb[h]=b[h+1];
			}
			tw[i]=w[i]+w[j];
			pa=w[i]*1.0/(w[i]+w[j]);
			pb=1-pa;
			ba=mx(pa+a[i],a[j]-pb);
			bb=mx(pb+b[j],b[i]-pa);
/*			memcpy(&ta[1],&a[1],i-1);
			memcpy(&ta[i+1],&a[i+1],j-i-1);
			memcpy(&ta[j],&a[j+1],n-j);
			memcpy(&tb[1],&b[1],i-1);
			memcpy(&tb[i+1],&b[i+1],j-i-1);
			memcpy(&tb[j],&b[j+1],n-j);*/
			ta[i]=ba;
			tb[i]=bb;
			ss(n-1,tw,ta,tb);
			ta[i]=bb;
			tb[i]=ba;
			ss(n-1,tw,ta,tb);
		}
}

int main()
{
	long ti,tn;
	long i,s;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		memset(w,0,sizeof(w));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%lf",&r);
		scanf("%d",&s);
		for (i=1;i<=s;i++)
			scanf("%d",&w[i]);
		ans=-1;
		ss(s,w,a,b);
		if (ans<-0.5) printf("%d\n",-1);
		else
			printf("%.12lf\n",ans);
	}
	return 0;
}
