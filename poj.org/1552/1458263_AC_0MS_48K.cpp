#include <stdio.h>

long a[100];

int main()
{
	long i,j,n;
	scanf("%d",&a[1]);
	while (a[1]>=0)
	{
		a[0]=1;
		scanf("%d",&a[a[0]+1]);
		while (a[a[0]+1]>0)
		{
			a[0]++;
			scanf("%d",&a[a[0]+1]);
		}
		n=0;
		for (i=1;i<=a[0];i++)
			for (j=1;j<=a[0];j++)
				if (a[i]==a[j]*2)
					n++;
		printf("%d\n",n);
		scanf("%d",&a[1]);
	}
	return 0;
}


