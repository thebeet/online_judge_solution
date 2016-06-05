#include <stdio.h>
#include <memory.h>

int main()
{
	int i,n;
	char c[15],ans[15];
	memset(ans,0,sizeof(ans));
	while (scanf("%s",&c)!=EOF)
	{
		n=0;
		while (c[n]>20)
		{
			ans[n]+=c[n]-48;
			ans[n]%=10;
			n++;
		}
	}
	for (i=0;i<n;i++)
		printf("%d",ans[i]);
	printf("\n");
	return 0;
}

		

