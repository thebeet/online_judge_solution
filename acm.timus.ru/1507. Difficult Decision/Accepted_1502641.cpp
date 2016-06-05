#include <stdio.h>
#include <memory.h>

bool a[60][60],b[60][60],c[60][60],d[60][60];
long n;
long bin[50];

void m_mul()
{
	long i,j,k;
	memset(c,false,sizeof(c));
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			for (k=1;k<=n;k++)
				c[i][j]|=(a[i][k]&b[k][j]);
}

void m_sqr()
{
	long i,j,k;
	memset(c,false,sizeof(c));
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			for (k=1;k<=n;k++)
				c[i][j]|=(b[i][k]&b[k][j]);
}

void m_m()
{
	long i,p;
	p=n*(n-1);
	memset(bin,0,sizeof(bin));
	while (p>0)
	{
		bin[0]++;
		bin[bin[0]]=p&1;
		p>>=1;
	}
	memcpy(&b,a,sizeof(a));
	for (i=bin[0]-1;i>=1;i--)
	{
		m_sqr();
		memcpy(&b,c,sizeof(c));
		if (bin[i]==1)
		{
			m_mul();
			memcpy(&b,c,sizeof(c));
		}
	}
}

void m_mul2()
{
	long i,j,k;
	memset(c,false,sizeof(c));
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			for (k=1;k<=n;k++)
				c[i][j]|=(a[i][k]&b[k][j]);
			d[i][j]|=c[i][j];
		}
}

void m_mix()
{
	long i,j;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			d[i][j]|=c[i][j];
}

int main()
{
	long i,j,t;
	bool ans;
	scanf("%ld",&n);
	memset(a,false,sizeof(a));
	memset(d,false,sizeof(d));
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			scanf("%ld",&t);
			if (t!=0) a[i][j]=true;
		}
	memcpy(&b,a,sizeof(a));
	memcpy(&c,a,sizeof(a));
	m_m();
	m_mix();
	for (i=n*(n-1)+1;i<=n*(n+1);i++)
	{
		m_mul2();
		memcpy(&b,c,sizeof(c));
	}
	ans=true;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			ans&=d[i][j];
	if (ans) printf("Yes\n");
	else printf("No\n");
	return 0;
}
