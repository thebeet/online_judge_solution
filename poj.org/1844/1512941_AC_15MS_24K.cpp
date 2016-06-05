#include <stdio.h>

int main()
{
	long i,n,s;
	scanf("%d",&n);
	s=0;
	for (i=1;i<=100000;i++)
	{
		s+=i;
		if ((s>n) && (((s-n)&1)==0))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}


