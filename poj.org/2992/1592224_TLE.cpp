#include <stdio.h>
#include <memory.h>

#define INT __int64

INT dd[500][500];

void add(INT n,INT p)
{
	INT i;
	for (i=2;i*i<=n;i++)
		if ((n%i)==0)
		{
			n/=i;
			dd[p][i]++;
			i--;
		}
	if (n!=1) dd[p][n]++;
}

int main()
{
	INT i,n,m,s;
	memset(dd,0,sizeof(dd));
	for (i=2;i<=450;i++)
	{
		memcpy(dd[i],dd[i-1],sizeof(dd[i-1]));
		add(i,i);
	}
	while (scanf("%I64d%I64d",&n,&m)!=EOF)
	{
		s=1;
		for (i=1;i<=n;i++)
			s*=(dd[n][i]-dd[m][i]-dd[n-m][i]+1);
		printf("%I64d\n",s);
	}
	return 0;
}
