#include <stdio.h>
#include <memory.h>

long ss[20001];
long ans[20001];

int main()
{
	long i,t,n;
	memset(ss,0,sizeof(ss));
	memset(ans,0,sizeof(ans));
	for (i=2;i<=20000;i++)
		if (ss[i]==0)
		{
			ss[0]++;
			ss[ss[0]]=i;
			t=i*i;
			if (t>20000) continue;
			ss[t]=1;
			while (t<=20000)
			{
				ss[t]=1;
				t+=i;
			}
		}
	for (i=1;i<=ss[0];i++)
	{
		t=ss[i];
		n=i;
		while (t<=10000)
		{
			ans[t]++;
			n++;
			t+=ss[n];
		}
	}
	scanf("%d",&n);
	while(n)
	{
		printf("%d\n",ans[n]);
		scanf("%d",&n);
	}
	return 0;
}
