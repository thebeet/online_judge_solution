#include <stdio.h>

int main()
{
	long i,n,h,m;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d:%d",&h,&m);
		if (m!=0) printf("0\n");
		if (m==0)
		{
			if (h<=12) h=h+12;
			else h=h-12;
			printf("%d\n",h);
		}
	}
	return 0;
}
