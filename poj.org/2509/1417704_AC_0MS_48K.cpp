#include <stdio.h>
int main()
{
	int i,n,m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		if ((n%(m-1)==0)) n=n+n/(m-1)-1;
		else n=n+n/(m-1);
		printf("%d\n",n);
	}
	return 0;
}
