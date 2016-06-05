#include <stdio.h>
#include <math.h>

bool check(__int64 s)
{
	__int64 i,q;
	if (s<=4) return false;
	q=__int64(ceil(sqrt(s*1.0)-0.001)+0.1);
	while ((q*q)>s)
		q--;
	for (i=2;i<=q;i++)
		if ((s%i)==0) return false;
	return true;
}

int main()
{
	__int64 i,n,s;
	char c;
	scanf("%I64d",&n);
	scanf("%c",&c);
	s=0;
	for (i=1;i<=n;i++)
	{
		scanf("%c",&c);
		s=s*10+c-48;
	}
	for (i=n;i<12;i++)
		s=s*10;
	while (!check(s))
		s++;
	if (s<100000000000) printf("0");
	if (s<10000000000) printf("0");
	if (s<1000000000) printf("0");
	if (s<100000000) printf("0");
	if (s<10000000) printf("0");
	if (s<1000000) printf("0");
	if (s<100000) printf("0");
	if (s<10000) printf("0");
	if (s<1000) printf("0");
	if (s<100) printf("0");
	if (s<10) printf("0");
	printf("%I64d\n",s);
	return 0;
}

