#include <stdio.h>
#include <memory.h>

long s[4510][4510];

int main()
{
	long i,j,k,n,m,p,pp,dd;
	pp=1000000007;
	scanf("%d%d",&m,&n);
/*	memset(s,0,sizeof(s));*/
	s[n][0]=1;
	for (i=1;i<=m;i++)
	{
		dd=m-i+1;
		for (j=0;j<=n;j++)
		{
			p=j;
			while (p>=0)
			{
				s[p][i]=(s[p][i]+s[j][i-1])%pp;
				p-=dd;
			}
		}
	}
	printf("%d\n",s[0][m]);
	return 0;
}
