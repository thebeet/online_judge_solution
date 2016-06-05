#include <stdio.h>
#include <memory.h>

long a[500001];
long b[500001];
long s;

void m(long l,long r)
{
	long i,j,n,t,p1,p2,p;
	if (l+4>r)
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
	p1=1;
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
	long i,n;
	scanf("%d",&n);
	while (n>0)
	{
		s=0;
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		m(1,n);
		printf("%d\n",s);
		scanf("%d",&n);
	}
	return 0;
}
