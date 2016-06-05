#include <stdio.h>
#include <memory.h>
int main()
{
	long i,n,ss,j;
	long s[10002];
	long m[10002];
	scanf("%d",&n);
	ss=0;
	memset(s,0,sizeof(s));
	for (i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		ss=(ss+m[i])%n;
		if (ss==0) 
		{
			printf("%d\n",i);
			for (j=1;j<=i;j++)
				printf("%d\n",m[j]);
			return 0;
		}
		if (s[ss]>0)
		{
			printf("%d\n",i-s[ss]);
			for (j=s[ss]+1;j<=i;j++)
				printf("%d\n",m[j]);
			return 0;
		}
		s[ss]=i;
	}
}