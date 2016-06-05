#include <stdio.h>
#include <memory.h>

bool w[10001];
bool f[10001];
long s[101];

int main()
{
	long i,j,n,l,m,t;
	bool flag;
	scanf("%d",&n);
	while (n>0)
	{
		m=1000000;
		memset(w,false,sizeof(w));
		memset(f,false,sizeof(f));
		for (i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			w[s[i]]=true;
		}
		for (i=1;i<=10000;i++)
			if (w[i]==false)
				for (j=1;j<=n;j++)
					if ((i-s[j]>0) && (w[i-s[j]]==false))
					{
						w[i]=true;
						break;
					}
		for (i=1;i<=10000;i++)
			for (j=1;j<=n;j++)
				if ((i-s[j]>0) && (f[i-s[j]]==false))
				{
					f[i]=true;
					break;
				}
		scanf("%d",&m);
		for (i=1;i<=m;i++)
		{
			scanf("%d",&l);
			flag=false;
			for (j=1;j<=l;j++)
			{
				scanf("%d",&t);
				flag^=w[t];
				flag^=f[t];
			}
			if (flag) printf("W");
			else printf("L");
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
		


