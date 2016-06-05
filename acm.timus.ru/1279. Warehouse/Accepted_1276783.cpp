#include <stdio.h>
#include <memory.h>

long n;
long j[1002];

int main()
{
	long i,m,k,l;
	scanf("%d%d%d",&n,&m,&k);
	memset(j,0,sizeof(j));
	n*=m;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&l);	
		j[l]++;
	}
	for (i=1;i<=1000;i++)
	{
		k-=j[i];
		j[i+1]+=j[i];
		if (k<0)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("%d\n",1001+k/n);
	return 0;
}

