#include <stdio.h>

__int64 mx(__int64 a,__int64 b)
{
	return a>b?a:b;
}

__int64 mn(__int64 a,__int64 b)
{
	return a<b?a:b;
}

__int64 calc(__int64 w,__int64 l,__int64 n)
{
	if (w-l>=n) return n*3;
	if (l==0) return w*3+n-w;
	if (w>=l) return (w-l)*3+n-(w-l);
	return 0;
}

__int64 calc2(__int64 w,__int64 l,__int64 n)
{
	if (l-w>=n) return 0;
	if (w==0) return n-l;
	if (l>=w) return n-(l-w);
	return n*3;
}

int main()
{
	__int64 n,k,l,a,b;
	scanf("%I64d%I64d%I64d",&k,&l,&n);
	a=mx(calc(k,l,n),calc(k,0,n-1));
	b=mn(calc2(k,l,n),calc2(0,l,n-1)+3);
	printf("%I64d %I64d\n",a,b);
	return 0;
}