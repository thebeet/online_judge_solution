#include <stdio.h>

#define w 131072

long t[270000];

void insert(long p)
{
	while (p>0)
	{
		t[p]++;
		p>>=1;
	}
	return;
}

long find(long p,long b,long e,long r)
{
	long pt1,pt2,m,sr;
	m=(b+e)>>1;
	if (p>=w) return p;
	pt1=p<<1;
	pt2=pt1+1;
	sr=m-b+1-t[pt1];
	if (sr>=r)
	{
		return find(pt1,b,m,r);
	}
	else
	{
		return find(pt2,m+1,e,r-sr);
	}
}

int main()
{
	long i,n,m,p,ans;
	p=0;
	scanf("%ld%ld",&n,&m);
	for (i=1;i<=n;i++)
	{
		p=(p+m-1)%(n-i+1);
		ans=find(1,1,w-1,p+1);
		printf("%ld ",ans-w+1);
		insert(ans);
	}
	printf("\n");
	return 0;
}
