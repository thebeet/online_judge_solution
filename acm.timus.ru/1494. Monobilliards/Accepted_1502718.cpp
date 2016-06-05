#include <stdio.h>
#include <memory.h>

long a[100010];
long st[100010];

int main()
{
	long i,n,m;
	bool ans;
	ans=true;
	memset(a,0,sizeof(a));
	memset(st,0,sizeof(st));
	scanf("%ld",&n);
	for (i=1;i<=n;i++)
		scanf("%ld",&a[i]);
	m=0;
	st[0]=1;
	for (i=1;i<=n;i++)
	{
		if (st[st[0]]!=a[i])
		{
			if (a[i]<m) 
			{
				ans=false;
				break;
			}
			else
			{
				m++;
				for (;m<a[i];m++)
				{
					st[0]++;
					st[st[0]]=m;
				}
			}
		}
		else st[0]--;
	}
	if (ans) printf("Not a proof\n");
	else printf("Cheater\n");
	return 0;
}
	