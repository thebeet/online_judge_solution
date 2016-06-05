#include <stdio.h>

long a[1001];

void ss(long l,long r)
{
	long i,j,x,y;
	i=l;j=r;x=a[(i+j)/2];
	for (;;)
	{
		while (a[i]>x)
			i++;
		while (a[j]<x)
			j--;
		if (i<=j)
		{
			y=a[i];
			a[i]=a[j];
			a[j]=y;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (l<j) ss(l,j);
	if (i<r) ss(i,r);
}

int main()
{
	long ti,tn,i,n,s,m;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d",&s,&n);
		printf("Scenario #%d:\n",ti);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ss(1,n);
		m=0;
		for (i=1;i<=n;i++)
		{
			m+=a[i];
			if (m>=s) break;
		}
		if (i<=n) printf("%d\n",i);
		else printf("impossible\n");
	}
	return 0;
}

	
