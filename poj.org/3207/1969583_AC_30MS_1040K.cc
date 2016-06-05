#include <stdio.h>
#include <memory.h>

char cnt[1010][1010];

void swap(long &a,long &b)
{
	long tmp;
	tmp=a;
	a=b;
	b=tmp;
	return;
}

int main()
{
	long i,j,k,a,b,n,m;
	memset(cnt,2,sizeof(cnt));
	scanf("%ld%ld",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%ld%ld",&a,&b);
		if (a>b) swap(a,b);
		if (cnt[a][b]==0)
		{
			printf("the evil panda is lying again\n");
			return 0;
		}
		for (j=a+1;j<b;j++)
		{
			for (k=1;k<a;k++)
			{
				cnt[j][k]--;
			}
			for (k=b+1;k<=n;k++)
			{
				cnt[j][k]--;
			}

		}
	}
	printf("panda is telling the truth...\n");
	return 0;
}
