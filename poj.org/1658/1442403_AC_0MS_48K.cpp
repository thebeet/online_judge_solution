#include <stdio.h>
int main()
{
	long i,n,ti,tn,a1,a2,a3,a4,a5;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
		if ((a1-a2)==(a2-a3) && ((a2-a3)==(a3-a4)))
			a5=a4+a4-a3;
		else
			a5=a4/a3*a4;
		printf("%d %d %d %d %d\n",a1,a2,a3,a4,a5);
	}
	return 0;
}
