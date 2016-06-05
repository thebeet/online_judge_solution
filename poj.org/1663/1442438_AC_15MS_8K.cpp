#include <stdio.h>
int main()
{
	long ti,tn,n,m;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d",&n,&m);
		if ((n==m)||(n-2==m))
			printf("%d\n",n+m-(n%2));
		else
			printf("No Number\n");
	}
	return 0;
}