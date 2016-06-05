#include <stdio.h>
#include <memory.h>
#include <math.h>

#define INT unsigned __int64

#define MAXN 120000000

bool sq[MAXN];

bool checksqrt(INT m)
{
	INT d;
	__int64 t;
	t=m;
	if (m<MAXN) return sq[m];
	d=(INT)(sqrt(t+0.1));
	if (d*d==m) return true;
	else return false;
}

int main()
{
	INT ti,tn,i,n,m;
	__int64 t;
	bool flag;
	memset(sq,false,sizeof(sq));
	for (i=0;i*i<MAXN;i++)
	{
		sq[i*i]=true;
	}
	scanf("%I64u",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%I64u",&n);
		if (checksqrt(n))
		{
			printf("YES\n");
			continue;
		}
		t=n/2;
		m=(INT)(sqrt(t));
		flag=false;
		for (;m*m<=n;m++)
		{
			if (checksqrt(n-m*m))
			{
				flag=true;
				break;
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
