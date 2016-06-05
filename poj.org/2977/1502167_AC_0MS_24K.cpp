#include <stdio.h>

long mn(long a,long b)
{
	if (a<b) return a;
	else return b;
}

int main()
{
	long m,l1,l2,l3,x,y,z;
	scanf("%d%d%d%d%d%d",&l1,&l2,&l3,&x,&y,&z);
	while ((l1!=0) || (l2!=0) || (l3!=0) || (x!=0) || (y!=0) || (z!=0))
	{
		if (x<0) x=-x;
		if (y<0) y=-y;
		if (z<0) z=-z;
		m=2000000000;
 		if ((x==0) || (y==0) || (z==0))
			m=mn(m,x*x+y*y+z*z); 
		if (x==l1)
		{
			m=mn(m,(x+z)*(x+z)+y*y);
			m=mn(m,(x+y)*(x+y)+z*z);
			m=mn(m,(l3-z+x)*(l3-z+x)+(l3+y)*(l3+y));
			m=mn(m,(l2-y+x)*(l2-y+x)+(l2+z)*(l2+z));
		}
		if (y==l2)
		{
			m=mn(m,(y+z)*(y+z)+x*x);
			m=mn(m,(y+x)*(y+x)+z*z);
			m=mn(m,(l1-x+y)*(l1-x+y)+(l1+z)*(l1+z));
			m=mn(m,(l3-z+y)*(l3-z+y)+(l3+x)*(l3+x));
		}
		if (z==l3)
		{
			m=mn(m,(z+x)*(z+x)+y*y);
			m=mn(m,(z+y)*(z+y)+x*x);
			m=mn(m,(l1-x+z)*(l1-x+z)+(l1+y)*(l1+y));
			m=mn(m,(l2-y+z)*(l2-y+z)+(l2+x)*(l2+x));
		}
		printf("%d\n",m);
		scanf("%d%d%d%d%d%d",&l1,&l2,&l3,&x,&y,&z);
	}
	return 0;
}


	