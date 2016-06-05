#include <stdio.h>
#include <memory.h>

#define MAXN 1010

long h[MAXN];
long w[MAXN];
long id[MAXN];
long ans[MAXN];

void sort(long l,long r)
{
	long i,j,x,xw,y;
	i=l;j=r;
	x=h[(i+j)/2];
	xw=w[(i+j)/2];
	for (;;)
	{
		while ((h[i]<x) || ((h[i]==x) && (w[i]>xw)))
			i++;
		while ((h[j]>x) || ((h[j]==x) && (w[j]<xw)))
			j--;
		if (i<=j)
		{
			y=h[i];
			h[i]=h[j];
			h[j]=y;
			y=w[i];
			w[i]=w[j];
			w[j]=y;
			y=id[i];
			id[i]=id[j];
			id[j]=y;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r);
}

int main()
{
	long i,n,r;
	scanf("%d",&n);
	memset(h,0,sizeof(h));
	memset(w,0,sizeof(w));
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&h[i],&w[i]);
		id[i]=i;
	}
	sort(1,n);
	r=0;
	memset(ans,0,sizeof(ans));
	for (i=1;i<=n;i++)
	{
		r+=h[i]-h[i-1];
		if (r)
		{
			r--;
			ans[0]++;
			ans[ans[0]]=id[i];
		}
	}
	printf("%d\n",ans[0]);
	for (i=1;i<ans[0];i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[ans[0]]);
	return 0;
}
			
	
