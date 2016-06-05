#include <stdio.h>
#include <memory.h>

long a[1010];

int main()
{
	long i,n,m,t,r;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	t=1;
	r=1;
	for (i=1;i<=n;i++)
	{
		if (a[t]<1000) printf(" ");
		if (a[t]<100) printf(" ");
		if (a[t]<10) printf(" ");
		printf("%d",a[t]);
		t+=m;
		if (t>n) 
		{
			r++;
			t=r;
			printf("\n");
		}
	}
	return 0;
}
