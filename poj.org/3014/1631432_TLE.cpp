#include <stdio.h>
#include <memory.h>

long s[2][4510];

int main()
{
	long i,j,n,m,p,pp,dd,p1,p2;
	pp=1000000007;
	scanf("%d%d",&m,&n);
	memset(s,0,sizeof(s));
	s[0][n]=1;
	p1=0;
	p2=1;
	for (i=1;i<=m;i++)
	{
		dd=m-i+1;
		memcpy(s[p2],s[p1],sizeof(s[p1]));
		for (j=n;j>=dd;j--)
		{
			p=j-dd;
			while (p>=0)
			{
				s[p2][p]=(s[p2][p]+s[p1][j])%pp;
				p-=dd;
			}
		}
		p1^=1;
		p2^=1;
	}
	printf("%d\n",s[p1][0]);
	return 0;
}
