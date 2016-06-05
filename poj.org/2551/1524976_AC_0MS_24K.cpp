#include <stdio.h>

int main()
{
	long ans,n,p;
	while (scanf("%d",&n)!=EOF)
	{
		ans=1;
		p=1;
		while ((p%n)!=0)
		{
			p=(p*10+1)%n;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
