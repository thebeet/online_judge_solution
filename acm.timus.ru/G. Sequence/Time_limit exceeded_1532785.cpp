#include <stdio.h>
#include <memory.h>

int main()
{
	__int64 i,j,f,g,sg,n,p;
	scanf("%I64d%I64d",&n,&p);
	while (n>0)
	{
		g=1;
		sg=1;
		f=1;
		for (i=2;i<=n;i++)
		{
			f=(f+f*g)%p;
			sg=(sg+g+g)%p;
			g=(sg-g*g)%p;
		}
		printf("%I64d\n",(f+p)%p);
		scanf("%I64d%I64d",&n,&p);
	}
	return 0;
}
