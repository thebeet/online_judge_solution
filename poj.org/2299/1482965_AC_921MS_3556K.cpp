#include <stdio.h>
#include <memory.h>

long a[500001];
long b[500001];
__int64 s;

void m(__int64 l,__int64 r)
{
	__int64 i,j,n,p1,p2,p;
	long t;
	if (l+30>r)
	{
		for (i=l+1;i<=r;i++)
			for (j=l;j<i;j++)
				if (a[i]<a[j])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
					s=s+1;
				}
		return;
	}
	n=(l+r)/2;
	m(l,n);
	m(n+1,r);
	p1=l;
	p2=n+1;
	for (i=l;i<=r;i++)
		b[i]=a[i];
	p=l;
	while ((p1<=n) && (p2<=r))
		if (b[p1]<=b[p2])
		{
			a[p]=b[p1];
			p1++;
			p++;
		}
		else
		{
			a[p]=b[p2];
			s=s+n-p1+1;
			p2++;
			p++;
		}
	for (i=p1;i<=n;i++)
	{
		a[p]=b[i];
		p++;
	}
	for (i=p2;i<=r;i++)
	{
		a[p]=b[i];
		p++;
	}
	return;
}

int main()
{
	__int64 i,n;
	scanf("%I64d",&n);
	while (n>0)
	{
		s=0;
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		m(1,n);
		printf("%I64d\n",s);
		scanf("%I64d",&n);
	}
	return 0;
}
