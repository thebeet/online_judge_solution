#include <stdio.h>
int main()
{
	int t,n;
	char c;
	scanf("%c",&c);
	n=0;
	while (c>20)
	{
		n=n+c-48;
		scanf("%c",&c);
	}
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
		scanf("%c",&c);
		n=0;
		while (c>20)
		{
			n=n+c-48;
			scanf("%c",&c);
		}
	}
	return 0;
}