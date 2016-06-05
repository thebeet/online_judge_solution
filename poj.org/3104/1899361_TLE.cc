#include <stdio.h>
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
	while (heap[1]>m)
	{
		m++;
		heap[1]-=k;
		turndown(1);
	}
	printf("%ld\n",m);
	return 0;
}
