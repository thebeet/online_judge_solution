#include <stdio.h>

int main()
{
	long i,n,s,m,t,sp;
	scanf("%d",&n);
	m=1000000;
	while (n>0)
	{
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&sp,&t);
			if ((t>0) && (m>long(t+16200.0/sp+0.99999999)))
				m=long((t+16200.0/sp+0.99999999));
		}
		printf("%d\n",m);
		scanf("%d",&n);
		m=1000000;
	}
	return 0;
}
