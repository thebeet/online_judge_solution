#include <stdio.h>
#include <memory.h>
#include <math.h>

#define INT __int64

#define MAXN 120000000

bool sq[MAXN];

bool checksqrt(INT m)
{
	INT d;
	if (m<MAXN) return sq[m];
	d=(INT)(sqrt(m+0.1));
	if (d*d==m) return true;
	else return false;
}

int main()
{
	INT ti,tn,i,n,m;
	bool flag;
	memset(sq,false,sizeof(sq));
	for (i=0;i*i<MAXN;i++)
	{
		sq[i*i]=true;
	}
	scanf("%I64d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%I64d",&n);
		if (checksqrt(n))
		{
			printf("YES\n");
			continue;
		}
		m=(INT)(sqrt(n/2+0.1));
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
