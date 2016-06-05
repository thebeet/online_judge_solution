#include <stdio.h>
#include <memory.h>

long s[4512];

int main()
{
	long i,j,n,m,p,pp,dd;
	pp=1000000007;
	scanf("%d%d",&m,&n);
	memset(s,0,sizeof(s));
	s[n]=1;
	for (i=0;i<m;i++)
	{
		dd=m-i;
		for (j=n;j>=dd;j--)
			s[j-dd]=(s[j-dd]+s[j])%pp;
	}
	printf("%d\n",s[0]);
	return 0;
}
