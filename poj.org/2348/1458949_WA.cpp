#include <stdio.h>

void swap(long *a,long *b)
{
	long *p;
	p=a;
	a=b;
	b=p;
}

long d(long a,long b)
{
	if (b>a) swap(&a,&b);
	if ((a%b)==0) return 1;
	if ((d(b,a%b)==1) && ((b/a)==1)) return -1;
	else return 1;
}

int main()
{
	long n,m;
	scanf("%d%d",&n,&m);
	while (n>0)
	{
		if (d(n,m)==1) printf("Stan wins\n");
		else printf("Ollie wins\n");
		scanf("%d%d",&n,&m);
	}
	return 0;
}
