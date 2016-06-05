#include <stdio.h>
#include <math.h>
#define pi 3.14159265353
int main()
{
	int ti,tn,ans;
	float x,y,d,s;
	scanf("%d",&tn);
 	for (ti=1;ti<=tn;ti++)
	{
		scanf("%f%f",&x,&y);
		d=sqrt(x*x+y*y);
		s=d*d*pi/2;
		ans=int(s/50)+1;
		printf("Property %d: This property will begin eroding in year %d.\n",ti,ans);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}