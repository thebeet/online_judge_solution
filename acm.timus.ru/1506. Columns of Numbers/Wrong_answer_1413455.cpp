#include <stdio.h>
#include <memory.h>

long a[1010];

int main()
{
	long i,n,m,t,r,m2;
	scanf("%d%d",&n,&m);
	m2=(n/m);
	if ((n%m)>0) m2++;
	memset(a,0,sizeof(a));
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	t=1;
	r=1;
	for (i=1;i<=n;i++)
	{
		printf("%4d",a[t]);
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
