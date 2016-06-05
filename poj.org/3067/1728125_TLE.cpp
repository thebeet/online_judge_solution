#include <stdio.h>
#include <memory.h>

long a[20100];
long b[20100];

int main()
{
	long ti,tn,i,j,n,m,k,s;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		s=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d%d%d",&n,&m,&k);
		printf("Test case %d: ",ti);
		for (i=1;i<=k;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			for (j=1;j<i;j++)
				if (((a[i]-a[j])*(b[i]-b[j]))<0) s++;
		}
		printf("%d\n",s);
	}
	return 0;
}
