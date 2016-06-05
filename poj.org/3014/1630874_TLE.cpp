#include <stdio.h>
#include <memory.h>

__int64 s[4510][4510];

int main()
{
	__int64 i,j,k,n,m,p,pp;
	pp=1000000007;
	scanf("%I64d%I64d",&m,&n);
/*	memset(s,0,sizeof(s));*/
	s[n][0]=1;
	for (i=1;i<=m;i++)
	{
		for (j=0;j<=n;j++)
		{
			for (k=0;k<=j;k++)
			{
				p=j-k*(m-i+1);
				if (p>=0)
					s[p][i]=(s[p][i]+s[j][i-1])%pp;
				else
					break;
			}
		}
	}
	printf("%I64d\n",s[0][m]);
	return 0;
}
