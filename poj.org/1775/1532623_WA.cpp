#include <stdio.h>
#include <memory.h>

bool ans[1000001];

int main()
{
	long i,n,j,s;
	s=1;
	memset(ans,false,sizeof(ans));
	ans[1]=true;
	for (i=1;i<=100;i++)
	{
		s*=i;
		if (s>1000000) break;
		for (j=1000000-s;j>=0;j--)
			if (ans[j]) ans[j+s]=true;
	}
	scanf("%d",&n);
	while (n>=0)
	{
		if (ans[n]) printf("YES\n");
		else printf("NO\n");
		scanf("%d",&n);
	}
	return 0;
}