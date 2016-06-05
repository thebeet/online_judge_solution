#include <stdio.h>
#include <memory.h>

long ans[15][1200];
long ss[1200];

int main()
{
	long i,j,h,n,m;
	memset(ss,0,sizeof(ss));
	memset(ans,0,sizeof(ans));
	for (i=2;i<=1150;i++)
		if (ss[i]==0)
		{
			j=i*i;
			while (j<1150)
			{
				ss[j]=1;
				j+=i;
			}
			ss[0]++;
			ss[ss[0]]=i;
		}
	ans[0][0]=1;
	for (h=1;h<=ss[0];h++)
		for (i=14;i>=1;i--)
			for (j=1130-ss[h];j>=0;j--)
				ans[i][j+ss[h]]+=ans[i-1][j];
	scanf("%ld%ld",&n,&m);
	while ((n>0) && (m>0))
	{
		printf("%ld\n",ans[m][n]);
		scanf("%ld%ld",&n,&m);
	}
	return 0;
}
