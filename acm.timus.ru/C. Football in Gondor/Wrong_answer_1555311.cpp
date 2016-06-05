#include <stdio.h>

long mx(long a,long b)
{
	return a>b?a:b;
}

long mn(long a,long b)
{
	return a<b?a:b;
}

long calc(long w,long l,long n)
{
	if (w-l>=n) return n*3;
	if (l==0) return w*3+n-w;
	if (w>=l) return (w-l)*3+n-(w-l);
	return 0;
}

long calc2(long w,long l,long n)
{
	if (l-w>=n) return 0;
	if (w==0) return n-l;
	if (l>=w) return (l-w);
	return n*3;
}

int main()
{
	long n,k,l,a,b;
	scanf("%ld%ld%ld",&k,&l,&n);
	a=mx(calc(k,l,n),calc(k,0,n-1));
	b=mn(calc2(k,l,n),calc2(0,l,n-1)+3);
	printf("%ld %ld\n",a,b);
	return 0;
}