#include <stdio.h>

long d(long a,long b)
{
	if ((a%b)==0) return 1;
	if ((d(b,a%b)==1) && ((a/b)==1)) return -1;
	else return 1;
}

int main()
{
	long n,m,t;
	scanf("%d%d",&n,&m);
	while (n>0)
	{
		if (m>n)
		{
			t=m;
			m=n;
			n=t;
		}
		if (d(n,m)==1) printf("Stan wins\n");
		else printf("Ollie wins\n");
		scanf("%d%d",&n,&m);
	}
	return 0;
}
