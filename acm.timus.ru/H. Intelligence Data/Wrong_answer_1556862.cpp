#include <stdio.h>
#include <memory.h>

long a[110],al[110],ar[110],bl[110],br[110];

int main()
{
	long i,n,d,dd,ans,s;
	double inp;
	dd=1;
	scanf("%ld%ld",&d,&n);
	memset(al,0,sizeof(al));
	memset(al,0,sizeof(al));
	memset(bl,0,sizeof(bl));
	memset(br,0,sizeof(br));
	for (i=1;i<=d;i++)
	{
		dd*=10;
	}
	for (i=1;i<=n;i++)
	{
		scanf("%lf",&inp);
		a[i]=long(inp*dd)%dd;
		al[i]=a[i]*10-5;
		ar[i]=al[i]+10;
	}
	for (ans=1;;ans++)
	{
		s=0;
		for (i=1;i<=n;i++)
		{
			bl[i]+=al[i];
			br[i]+=ar[i];
			if (((br[i]-1)/10/dd)>((bl[i]-1)/10/dd)) s++;
		}
		if (s==n) break;
	}
	printf("%ld\n",ans);
	return 0;
}
