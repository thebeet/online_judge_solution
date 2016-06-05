#include <stdio.h>
#include <memory.h>

#define INT __int64

INT d[10010];

void add(INT n,INT op)
{
	INT i;
	for (i=2;i*i<=n;i++)
		if ((n%i)==0)
		{
			n/=i;
			d[i]+=op;
			i--;
		}
	if (n!=1) d[n]+=op;
}

int main()
{
	INT i,n,m,s;
	while (scanf("%I64d%I64d",&n,&m)!=EOF)
	{
		memset(d,0,sizeof(d));
		for (i=1;i<=m;i++)
		{
			add(n-i+1,1);
			add(i,-1);
		}
		s=1;
		for (i=2;i<=10010;i++)
			s*=(d[i]+1);
		printf("%I64d\n",s);
	}
	return 0;
}



