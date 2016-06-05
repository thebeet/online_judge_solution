#include <stdio.h>
int main()
{
	long ti,tn,n,m;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d",&n,&m);
		if ((n<m) || (((n+m)%2)==1) || (((n-m)%2)==1))
			printf("impossible\n");
		else
			printf("%d %d\n",(n+m)/2,(n-m)/2);
	}
	return 0;
}