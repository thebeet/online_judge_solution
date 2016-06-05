#include <stdio.h>
int main()
{
	int t,n;
	scanf("%d",&n);
	while (n>0)
	{
		while (n>9)
		{
			t=0;
			while (n>0)
			{
				t=t+n%10;
				n=n/10;
			}
			n=t;
		}
		printf("%d\n",n);
		scanf("%d",&n);
	}
	return 0;
}