#include <stdio.h>

int main()
{
	long i,n,m,s;
	scanf("%d",&n);
	s=1;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&m);
		if (m>s)
		{
			printf("%d\n",s);
			return 0;
		}
		s+=m;
	}
	printf("%d\n",s);
	return 0;
}
