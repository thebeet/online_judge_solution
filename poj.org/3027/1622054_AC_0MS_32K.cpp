#include <stdio.h>
#include <memory.h>

long d[100];

int main()
{
	long ti,tn,i,j,n,m,k1,k2,r1,r2;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d%d%d",&k1,&k2,&r1,&r2);
		for (i=r2;i>=r1;i--)
		{
			memset(d,0,sizeof(d));
			n=i;
			while (n>0)
			{
				d[0]++;
				d[d[0]]=n%k1;
				n/=k1;
			}
			m=0;
			for (j=d[0];j>=1;j--)
				m=m*k2+d[j];
			if ((m%i)==0) break;
		}
		if (i>=r1) printf("%d\n",i);
		else printf("Non-existent.\n");
	}
	return 0;
}
