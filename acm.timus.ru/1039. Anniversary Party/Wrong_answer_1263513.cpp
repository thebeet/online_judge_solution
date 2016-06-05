#include <stdio.h>
#include <memory.h>

long h[6010];
long c[6010];
long f[6010];
long b[6010];
long go[6010];
long ug[6010];

void dfs(long p)
{
	if (c[p]>0) dfs(c[p]);
	if (b[p]>0) dfs(b[p]);
	if (h[p]>0) go[p]+=h[p];
	if (ug[p]>0) go[f[p]]+=ug[p];
	if (go[p]>0) ug[f[p]]+=go[p];
}

int main()
{
	long i,n,l,k,t,root;
	scanf("%d",&n);
	memset(h,0,sizeof(h));
	memset(c,0,sizeof(c));
	memset(f,0,sizeof(f));
	memset(b,0,sizeof(b));
	for (i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&l,&k);
		f[l]=k;
		if (c[k]==0)
			c[k]=l;
		else
		{
			t=c[k];
			while (b[t]>0)
				t=b[t];
			b[t]=l;
		}
	}
	root=1;
	while (f[root]>0)
		root=f[root];
	dfs(root);
	if (go[root]>ug[root])
		printf("%d\n",go[root]);
	else
		printf("%d\n",ug[root]);
	return 0;
}


