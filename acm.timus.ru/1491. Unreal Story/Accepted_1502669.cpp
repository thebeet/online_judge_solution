#include <stdio.h>
#include <memory.h>

#define W 131072
long linetree[250000];

void linetree_init()
{
	memset(linetree,0,sizeof(linetree));
}

void linetree_insert(long f,long t,long p,long sf,long st,long n)
{
	long mid;
	mid=(sf+st)>>1;
	if ((f==sf) && (t==st))
	{
		linetree[p]+=n;
		return;
	}
	if (t<=mid)
	{
		linetree_insert(f,t,p<<1,sf,mid,n);
		return;
	}
	if (f>mid)
	{
		linetree_insert(f,t,(p<<1)+1,mid+1,st,n);
		return;
	}
	linetree_insert(f,mid,p<<1,sf,mid,n);
	linetree_insert(mid+1,t,(p<<1)+1,mid+1,st,n);
}

long linetree_read(long p)
{
	long s;
	p+=(W-1);
	s=0;
	while (p>0)
	{
		s+=linetree[p];
		p>>=1;
	}
	return s;
}

int main()
{
	long i,n,a,b,c;
	scanf("%ld",&n);
	linetree_init();
	for (i=0;i<=n;i++)
	{
		scanf("%ld%ld%ld",&a,&b,&c);
		linetree_insert(a,b,1,1,W,c);
	}
	for (i=1;i<n;i++)
		printf("%ld ",linetree_read(i));
	printf("%ld\n",linetree_read(n));
	return 0;
}
