#include <stdio.h>
#include <memory.h>

__int64 a[110],al[110],ar[110],bl[110],br[110];

int main()
{
	__int64 i,n,d,dd,ans,s;
	double inp;
	dd=1;
	scanf("%I64d%I64d",&d,&n);
	memset(al,0,sizeof(al));
	memset(ar,0,sizeof(ar));
	memset(bl,0,sizeof(bl));
	memset(br,0,sizeof(br));
	for (i=1;i<=d;i++)
	{
		dd*=10;
	}
	for (i=1;i<=n;i++)
	{
		scanf("%lf",&inp);
		a[i]=__int64(inp*dd+0.1);
		if (a[i]==0)
		{
			i--;
			n--;
			continue;
		}
		al[i]=a[i]*10-5;
		ar[i]=al[i]+10;
	}
	dd*=10;
	for (ans=1;;ans++)
	{
		s=0;
		for (i=1;i<=n;i++)
		{
			bl[i]+=al[i];
			br[i]+=ar[i];
			if (bl[i]>=dd)
			{
				bl[i]-=dd;
				br[i]-=dd;
			}
			if (br[i]>dd) s++;
		}
		if (s==n) break;
	}
	printf("%I64d\n",ans);
	return 0;
}
