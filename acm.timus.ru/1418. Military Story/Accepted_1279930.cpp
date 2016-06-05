#include <stdio.h>
#include <memory.h>

#define MAXN 5000

long x[MAXN];
long y[MAXN];
long st[MAXN];
bool us[MAXN];

void sort(long l,long r)
{
	long i,j,xx,xy,yy;
	i=l;
	j=r;
	xx=x[(l+r)/2];
	xy=y[(l+r)/2];
	for (;;)
	{
		while ((x[i]<xx) || ((x[i]==xx) && (y[i]<xy)))
			i++;
		while ((x[j]>xx) || ((x[j]==xx) && (y[j]>xy)))
			j--;
		if (i<=j)
		{
			yy=x[i];
			x[i]=x[j];
			x[j]=yy;
			yy=y[i];
			y[i]=y[j];
			y[j]=yy;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r);
}

long xj(long x1,long y1,long x0,long y0,long x2,long y2)
{
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}


int main()
{
	long i,n,ans,di,p,ret;
	bool flag;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	ans=0;
	sort(1,n);
	while (n>=3)
	{
		memset(us,true,sizeof(us));
		i=3;
		st[0]=2;
		st[1]=1;
		st[2]=2;
		flag=false;
		while (i<=n)
		{
			ret