#include <stdio.h>
#include <memory.h>

long s[4510][4510];

int main()
{
	long i,j,k,n,m,p,pp,dd;
	pp=1000000007;
	scanf("%d%d",&m,&n);
/*	memset(s,0,sizeof(s));*/
	s[0][n]=1;
	for (i=1;i<=m;i++)
	{
		dd=m-i+1;
		memcpy(s[i],s[i-1],sizeof(s[i]));
		for (j=n;j>=dd;j--)
		{
			p=j-dd;
			while (p>=0)
			{
				s[i][p]=(s[i][p]+s[i-1][j])%pp;
				p-=dd;
			}
		}
	}
	printf("%d\n",s[m][0]);
	return 0;
}
