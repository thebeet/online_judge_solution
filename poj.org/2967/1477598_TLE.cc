#include <stdio.h>

__int64 a[1000002];

void ss(__int64 l,__int64 r)
{
	__int64 i,j,x,y;
	i=l;j=r;x=a[(i+j)/2];
	for (;;)
	{
		while (x>a[i])
			i++;
		while (x<a[j])
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
	if ((i<r) && (i<=60)) ss(i,r);
}

int main()
{
	__int64 i,n,m;
	bool f1;
	scanf("%I64d",&n);
	if (n<=3)
	{
		printf("The set is rejected.\n");
		return 0;
	}
	m=-1;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (m<a[i]) m=a[i];
	}
	ss(1,n);
	f1=false;
	if ((a[1]+a[2])<=m) f1=true;
	if (f1==false)
	{
		printf("The set is rejected.\n");
		return 0;
	}
	if (n>=60) 
	{
		printf("The set is accepted.\n");
		return 0;
	}
	for (i=3;i<=n;i++)
		if ((a[i-1]+a[i-2])>a[i])
		{
			printf("The set is accepted.\n");
			return 0;
		}
	printf("The set is rejected.\n");
	return 0;
}
