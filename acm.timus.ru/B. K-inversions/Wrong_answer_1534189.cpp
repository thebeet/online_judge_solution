#include <stdio.h>
#include <memory.h>

#define q 32767
#define pp 1000000000
__int64 numtree[11][70000];

void insert(__int64 tp,__int64 p,__int64 f,__int64 t,__int64 d,__int64 s)
{
	__int64 m;
	if (p>q) 
	{
		numtree[tp][p]=(s+numtree[tp][p])%pp;
		return;
	}
	m=(f+t)>>1;
	if (d>=m) 
	{
		numtree[tp][p<<1]=(numtree[tp][p<<1]+s)%pp;
		if (d>m)
		{
			insert(tp,(p<<1)+1,m+1,t,d,s);
		}
	}
	else
	{
		insert(tp,(p<<1),f,m,d,s);
	}
	return;
}

__int64 read_tree(__int64 tp,__int64 p)
{
	__int64 s;
	s=0;
	p+=q;
	while (p>0)
	{
		s+=numtree[tp][p];
		p>>=1;
	}
	return s;
}

int main()
{
	__int64 i,j,n,m,k,s,ss;
	memset(numtree,0,sizeof(numtree));
	numtree[0][1]=1;
	scanf("%I64d%I64d",&n,&k);
	ss=0;
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&m);
		ss+=read_tree(k-1,m);
		for (j=k-1;j>=1;j--)
		{
			s=read_tree(j-1,m);
			insert(j,1,1,q+1,m,s);
		}
	}
	printf("%I64d\n",ss);
	return 0;
}
