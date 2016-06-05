#include <stdio.h>
#include <memory.h>

__int64 bin[50];

__int64 m_mod(__int64 x,__int64 k,__int64 p)
{
	__int64 i,s;
	memset(bin,0,sizeof(bin));
	while (k>0)
	{
		bin[0]++;
		bin[bin[0]]=k&1;
		k>>=1;
	}
	s=1;
	for (i=bin[0];i>=1;i--)
	{
		s=(s*s)%p;
		if (bin[i]==1)
			s=(s*x)%p;
	}
	return s;
}

int main()
{
	__int64 ti,tn,k,n,m,e;
	scanf("%I64d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%I64d%I64d%I64d",&n,&k,&m);
		if (n==0) printf("%d\n",1);
		else
		{
			e=(1+m_mod(10,k,m))%m;
			printf("%I64d\n",m_mod(e,n,m));
		}
	}
	return 0;
}
