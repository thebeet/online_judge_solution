#include <stdio.h>

int main()
{
	__int64 i,j,n,m,s;
	scanf("%I64d",&n);
	s=0;
	j=0;
	for (i=n-1;i>=0;i--)
	{
		m=n*n-i*i;
		while (j*j<m) j++;
		s+=j;
	}
	s<<=2;
	printf("%I64d\n",s);
	return 0;
}
