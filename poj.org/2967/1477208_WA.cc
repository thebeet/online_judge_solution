#include <stdio.h>

long a[1000001];

void ss(long l,long r)
{
	long i,j,x,y;
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
	if (i<r) ss(i,r);
}

int main()
{
	long i,n;
	bool f1,f2;
	scanf("%d",&n);
	if (n<3)
	{
		printf("The set is rejected.\n");
		return 0;
	}
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ss(1,n);
	f1=false;
	if ((a[1]+a[2])<=a[3]) f1=true;
	if (f1==false)
	{
		printf("The set is rejected.\n");
		return 0;
	}
	f2=false;
	for (i=3;i<=n;i++)
		if ((a[i-1]+a[i-2])>a[i])
		{
			printf("The set is accepted.\n");
			return 0;
		}
	printf("The set is rejected.\n");
	return 0;
}
