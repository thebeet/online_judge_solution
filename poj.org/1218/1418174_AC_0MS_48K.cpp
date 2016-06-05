#include <stdio.h>
#include <memory.h>
int main()
{
	int i,n,j,k,m;
	int c[101];
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&m);
		memset(c,false,sizeof(c));
		for (k=1;k<=m;k++)
			for (j=k;j<=m;j=j+k)
				c[j]=!c[j];
		k=0;
		for (j=1;j<=m;j++)
			if (c[j]) k++;
		printf("%d\n",k);
	}
	return 0;
}


