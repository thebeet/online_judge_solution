#include <stdio.h>
#include <string.h>

long txt[100010];
long ans[100010];

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	long i,n,m,l,p;
	char c;
	memset(txt,0,sizeof(txt));
	memset(ans,0,sizeof(ans));
	scanf("%ld%ld",&n,&m);
	l=0;
	scanf("%c",&c);
	scanf("%c",&c);
	while (c>15)
	{
		l++;
		txt[l]=txt[l-1]+1;
		if (((c>='A') && (c<='Z')) || ((c>='a') && (c<='z')) || (c==' '))
		{
			txt[l]--;
		}
		scanf("%c",&c);
	}
	for (i=1;i<=n;i++)
	{
		ans[i]=1;
	}
	p=0;
	for (i=n+1;i<=l;i++)
	{
		if (p+m<i) p++;
		while (txt[i]!=txt[p])
		{
			p++;
		}
		if (p!=i)
		{
			ans[i]=mn(ans[i-n],ans[p])+1;
		}
		else
		{
			ans[i]=ans[i-n]+1;
		}
	}
	printf("%ld\n",ans[l]);
	return 0;
}
