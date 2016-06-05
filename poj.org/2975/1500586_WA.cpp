#include <stdio.h>

long a[1011];

int main()
{
	long i,n,t,ans;
	scanf("%d",&n);
	while (n>0)
	{
		ans=0;
		t=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			t^=a[i];
		}
		for (i=1;i<=n;i++)
			if ((t^a[i])<=a[i]) ans++;
		if (t=0) ans=0;
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
