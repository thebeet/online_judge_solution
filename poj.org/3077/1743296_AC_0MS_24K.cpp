#include <stdio.h>

int main ()
{
		long ti,tn,i,n,m;
		scanf("%d",&tn);
		for (ti=1;ti<=tn;ti++)
		{
			scanf("%d",&n);
			m=0;
			while (n>=10)
			{
				m++;
				n=((n+5)/10);
			}
			printf("%d",n);
			for (i=1;i<=m;i++)
				printf("0");
			printf("\n");
		}
	return 0;
}
