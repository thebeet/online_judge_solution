#include <stdio.h>
int main()
{
	int n,s,m,i;
	int b[40];
	scanf("%d",&n);
	while (n>0)
	{
		s=0;
		printf("%d: ",n);
		m=0;
		while (n>0)
		{
			m++;
			b[m]=n%10;
			if (b[m]>4) b[m]--;
			n=n/10;
		}
		for (i=m;i>=1;i--)
			s=s*9+b[i];	
		printf("%d\n",s);
		scanf("%d",&n);
	}
	return 0;
}