#include <stdio.h>

char c[100001];

int main()
{
	long i,n,k,m,nn,ans,ansp,s;
	scanf("%d%d",&n,&k);
	scanf("%c",&c[0]);
	c[0]=0;
	nn=0;
	ans=1000000000;
	ansp=0;
	s=0;
	for (i=1;i<=n;i++)
	{
		scanf("%c",&c[i]);
		while (c[i]<20)
			scanf("%c",&c[i]);
		if (c[i]=='*')
		{
			s=0;
			nn=0;
		}
		else
		{
			nn++;
			s=s+c[i]-48;
			if (nn>k)
			{
				nn--;
				s=s-c[i-k]+48;
			}
			if ((nn==k) && (ans>s))
			{
				ans=s;
				ansp=i-k+1;
			}
		}
	}
	printf("%d\n",ansp);
	return 0;
}
			
	
