#include <stdio.h>
#include <memory.h>
long ans[6000];
long p[6];
long q[6];
int main()
{
	long i,j,n,m;
	char c1,c2;
	memset(ans,0,sizeof(ans));
	ans[1]=1;
	q[1]=2;
	q[2]=3;
	q[3]=5;
	q[4]=7;
	for (i=1;i<=4;i++)
		p[i]=1;
	for (i=2;i<=5842;i++)
	{
		m=q[1]*ans[p[1]];
		for (j=2;j<=4;j++)
			if (m>q[j]*ans[p[j]])
				m=q[j]*ans[p[j]];
		ans[i]=m;
		for (j=1;j<=4;j++)
			if (m==q[j]*ans[p[j]])
				p[j]++;
	}
	scanf("%d",&n);
	while (n>0)
	{
		c1=116;
		c2=104;
		if ((n%10)==1) 
		{
			c1=115;
			c2=116;
		}
		if ((n%10)==2) 
		{
			c1=110;
			c2=100;
		}
		if ((n%10)==3) 
		{
			c1=114;
			c2=100;
		}
		if (((n/10)%10)==1
			)
		{
			c1=116;
			c2=104;
		}
		printf("The %d%c%c humble number is %d.\n",n,c1,c2,ans[n]);
	    scanf("%d",&n);
	}	
	return 0;
}
	

