#include <stdio.h>
#include <memory.h>

bool ss[1001000];

int main()
{
	long i,j,a,d,n;
	memset(ss,true,sizeof(ss));
	ss[1]=false;
	for (i=2;i<=10000;i++)
		if (ss[i])
		{
			j=i*i;
			while (j<=1000000)
			{
				ss[j]=false;
				j+=i;
			}
		}
	scanf("%d%d%d",&a,&d,&n);
	while (n>0)
	{
		for (i=a;n>0;i+=d)
			if (ss[i]) n--;
		printf("%d\n",i-d);
		scanf("%d%d%d",&a,&d,&n);
	}
	return 0;
}
