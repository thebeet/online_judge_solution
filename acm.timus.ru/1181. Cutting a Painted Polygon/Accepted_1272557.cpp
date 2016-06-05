#include <stdio.h>
#include <memory.h>

char c[1001];
long p[1001];
long tt[100];

int main()
{
	long i,t,j,n,pp;
	scanf("%d",&n);
	memset(tt,0,sizeof(tt));
	for (i=0;i<=n;i++)
	{
		
		scanf("%c",&c[i]);
		tt[c[i]]++;
		p[i]=i;
	}
	p[0]=n;
	printf("%d\n",n-3);
	pp=1;
	for (t=4;t<=n;t++)
	{
		if ((tt['R']==1) || (tt['B']==1) || (tt['G']==1))
			break;
		for (i=1;i<=p[0];i++)
			if (c[p[i]]!=c[p[i+2]])
			{
				printf("%d %d\n",p[i],p[i+2]);
				tt[c[p[i+1]]]--;
				for (j=i+1;j<p[0];j++)
					p[j]=p[j+1];
				p[0]--;
				break;
			}
	}
	if (tt['R']==1)
	{
		for (i=1;i<=p[0];i++)
			if (c[p[i]]=='R')
			{
				pp=i;
				break;
			}
		for (i=1;i<=p[0]-3;i++)
			printf("%d %d\n",p[pp],p[(pp+i)%p[0]+1]);
		return 0;
	}
	if (tt['B']==1)
	{
		for (i=1;i<=p[0];i++)
			if (c[p[i]]=='B')
			{
				pp=i;
				break;
			}
		for (i=1;i<=p[0]-3;i++)
			printf("%d %d\n",p[pp],p[(pp+i)%p[0]+1]);
		return 0;
	}
	if (tt['G']==1)
	{
		for (i=1;i<=p[0];i++)
			if (c[p[i]]=='G')
			{
				pp=i;
				break;
			}
		for (i=1;i<=p[0]-3;i++)
			printf("%d %d\n",p[pp],p[(pp+i)%p[0]+1]);
	}
	return 0;
}
	
