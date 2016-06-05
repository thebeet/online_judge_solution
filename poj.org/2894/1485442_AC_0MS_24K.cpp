#include <stdio.h>
#include <memory.h>

char a[1005];

int main()
{
	long ti,tn,i,j,n,b,e;
	char bb,c;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		memset(a,64,sizeof(a));
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%c%c%d%d",&bb,&c,&b,&e);
			for (j=b;j<e;j++)
				a[j]++;
		}
		for (i=0;i<=1001;i++)
			if (a[i]>64)
				printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}
