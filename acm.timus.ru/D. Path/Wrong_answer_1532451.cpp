#include <stdio.h>

long i,n,m,k,x,y,z,xmin,xmax,ymin,ymax,zmin,zmax;
char c;

int main()
{
	scanf("%ld%ld%ld",&n,&m,&k);
	x=0;y=0;z=0;
	scanf("%c",&c);
	scanf("%c",&c);
	while (c>20)
	{
		if (c=='u') y++;
		if (c=='d') y--;
		if (c=='l') x++;
		if (c=='r') x--;
		if (c=='f') z++;
		if (c=='b') z--;
		if (xmin>x) xmin=x;
		if (xmax<x) xmax=x;
		if (ymin>y) ymin=y;
		if (ymax<y) ymax=y;
		if (zmin>z) zmin=z;
		if (zmax<z) zmax=z;
		scanf("%c",&c);
	}
	x=xmax-xmin;
	y=ymax-ymin;
	z=zmax-zmin;
	n-=x;
	m-=y;
	k-=z;
	if (n<1) n=1;
	if (m<1) m=1;
	if (k<1) k=1;
	n=n*m*k;
	printf("%ld\n",n);
	return 0;
}
