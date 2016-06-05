#include <stdio.h>
int main()
{
	int i,j,n,p1,p2,p3,p4;
	char ip[50];
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%s",ip);
		p1=0;
		p2=0;
		p3=0;
		p4=0;
		for (j=0;j<=7;j++)
			p1=p1*2+ip[j]-48;
		for (j=8;j<=15;j++)
			p2=p2*2+ip[j]-48;
		for (j=16;j<=23;j++)
			p3=p3*2+ip[j]-48;
		for (j=24;j<=31;j++)
			p4=p4*2+ip[j]-48;
		printf("%d.%d.%d.%d\n",p1,p2,p3,p4);
	}
	return 0;
}


