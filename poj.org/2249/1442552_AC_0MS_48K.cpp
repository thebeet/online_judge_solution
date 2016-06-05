#include <stdio.h>
int main()
{
	long i,s,n,k,a,c;
	scanf("%d%d",&n,&k);
	while (n>0)
	{
		s=1;
		a=2;
		if (k>n/2) k=n-k;
		for (i=1;i<=k;i++)
		{
			c=n-i+1;
			while (((s%a)==0) && (a<=k)) 
			{
				s/=a;
				a++;
			}
			while (((c%a)==0) && (a<=k)) 
			{
				c/=a;
				a++;
			}
			s*=c;
		}
		printf("%d\n",s);
		scanf("%d%d",&n,&k);
	}
	return 0;
}
		