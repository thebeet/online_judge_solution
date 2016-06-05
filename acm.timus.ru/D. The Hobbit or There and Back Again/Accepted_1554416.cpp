#include <stdio.h>
#include <memory.h>

long ans[50010];

int main()
{
	long i,j,n,p1,p2;
	scanf("%ld",&n);
	memset(ans,0,sizeof(ans));
	p1=2;p2=n;
	ans[1]=1;
	for (i=2,j=n;p1<p2;)
	{
		if ((p1&1)==0)
		{
			ans[p1]=j;
			j--;
			ans[p2]=j;
			j--;
		}
		else
		{
			ans[p1]=i;
			i++;
			ans[p2]=i;
			i++;
		}
		p1++;
		p2--;
	}
	if (p1==p2) ans[p1]=i;
	for (i=1;i<=n;i++)
	{
		printf("%ld ",ans[i]);
	}
	printf("\n");
	memset(ans,0,sizeof(ans));
	p1=2;p2=n;
	ans[1]=n;
	for (j=n-1;p1<p2;)
	{
		ans[p1]=j;
		j--;
		ans[p2]=j;
		j--;
		p1++;
		p2--;
	}
	if (p1==p2) ans[p1]=j;
	for (j=1;j<=n;j++)
	{
		if (ans[j]==1) break;
	}
	for (i=j;i<=n;i++)
	{
		printf("%ld ",ans[i]);
	}
	for (i=1;i<j;i++)
	{
		printf("%ld ",ans[i]);
	}
	printf("\n");
	return 0;
}
