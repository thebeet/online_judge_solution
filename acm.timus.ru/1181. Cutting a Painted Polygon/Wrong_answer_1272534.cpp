#include <stdio.h>

char c[1001];
long p[1001];

int main()
{
	long i,t,j,n;
	scanf("%d",&n);
	for (i=0;i<=n;i++)
	{
		scanf("%c",&c[i]);
		p[i]=i;
	}
	p[0]=n;
	printf("%d\n",n-3);
	for (t=4;t<=n;t++)
	{
		for (i=1;i<=p[0];i++)
		{
			if (c[p[i]]!=c[p[i+2]])
			{
				printf("%d %d\n",p[i],p[i+2]);
				for (j=i+1;j<p[0];j++)
					p[j]=p[j+1];
				p[0]--;
				break;
			}
		}
	}
	return 0;
}
	
