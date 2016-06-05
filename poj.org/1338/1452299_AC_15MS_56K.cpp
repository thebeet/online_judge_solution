#include <stdio.h>
#include <memory.h>
long ans[1510];
long p[6];
long q[6];
int main()
{
	long i,j,n,m;
	memset(ans,0,sizeof(ans));
	ans[1]=1;
	q[1]=2;
	q[2]=3;
	q[3]=5;
	for (i=1;i<=3;i++)
		p[i]=1;
	for (i=2;i<=1500;i++)
	{
		m=q[1]*ans[p[1]];
		for (j=2;j<=3;j++)
			if (m>q[j]*ans[p[j]])
				m=q[j]*ans[p[j]];
		ans[i]=m;
		for (j=1;j<=3;j++)
			if (m==q[j]*ans[p[j]])
				p[j]++;
	}
	scanf("%d",&n);
	while (n>0)
	{
		printf("%d\n",ans[n]);
	    scanf("%d",&n);
	}	
	return 0;
}
	

