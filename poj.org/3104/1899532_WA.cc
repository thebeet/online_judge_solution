#include <stdio.h>

long w[100010];
long n;

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
	long i,m,a,b,s,k;
	scanf("%ld",&n);
	m=0;
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&w[i]);
		m=mx(m,w[i]);
	}
	scanf("%ld",&k);
	k--;
	a=m;
	b=0;
	if (k==0)
	{
		printf("%ld\n",m);
		return 0;
	}
	while (a!=(b+1))
	{
		m=(a+b)>>1;
		s=0;
		for (i=1;i<=n;i++)
		{
			s+=((w[i]-m+k-1)/k);
			if (s>m) break;
		}
		if (s>m) b=m;
		else a=m;
	}
	printf("%ld\n",a);
	return 0;
}

/* #include <stdio.h>
#include <algorithm>

using namespace std;

long n;
long heap[100010];

bool comp(long a,long b)
{
	if (a>b) return true;
	else return false;
}

void turndown(long p)
{
	long pt,tmp;
	pt=p<<1;
	if (pt>n) return;
	if ((pt<n) && (comp(heap[pt+1],heap[pt]))) pt++;
	if (comp(heap[pt],heap[p]))
	{
		tmp=heap[pt];
		heap[pt]=heap[p];
		heap[p]=tmp;
		turndown(pt);
	}
	return;
}

int main()
{
	long i,m,k;
	scanf("%ld",&n);
	for (i=1;i<=n;i++)
		scanf("%ld",&heap[i]);
	scanf("%ld",&k);
	k--;
	sort(heap+1,heap+1+n,comp);
	m=0;
	if (k==0)
	{
		printf("%ld\n",heap[1]);
		return 0;
	}
	while (heap[1]>m)
	{
		m++;
		heap[1]-=k;
		turndown(1);
	}
	printf("%ld\n",m);
	return 0;
}
*/
