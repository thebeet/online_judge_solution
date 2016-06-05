#include <stdio.h>
#include <memory.h>

long ans[100];

int main()
{
	long i,n,m;
	scanf("%d",&n);
	memset(ans,0,sizeof(ans));
	m=0;
	while (n!=0)
	{
		m++;
		if ((n % 2)!=0) 
		{
			ans[m]=1;
			n--;
		}
		n/=(-2);
	}
	if (m==0) m=1;
	for (i=m;i>=1;i--)
		printf("%d",ans[i]);
	printf("\n");
	return 0;
}


