#include <stdio.h>
#include <memory.h>

long f[1001];
long c[1001];
long b[1001];
long w[1001];

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

long mx(long a,long b)
{
	if (a<b) return b;
	else return a;
}

long s(long p,long a)
{
	long t;
	if (w[p]<=1) return w[p];
	t=c[p];
	w[p]=s(t,-a);
	t=b[t];
	if (a==1)
	{
		while ((w[p]<=0) && (t!=0))
		{
			w[p]=mx(w[p],s(t,-a));
			t=b[t];
		}
		return w[p];
	}
	else
	{
		while ((w[p]>=0) && (t!=0))
		{
			w[p]=mn(w[p],s(t,-a));
			t=b[t];
		}
		return w[p];
	}
}


int main()
{
	long i,n,t;
	char l,op;
	scanf("%d",&n);
	scanf("%c",&l);
	memset(w,2,sizeof(w));
	memset(f,0,sizeof(f));
	for (i=2;i<=n;i++)
	{
		scanf("%c%d",&op,&f[i]);
		if (c[f[i]]==0)
			c[f[i]]=i;
		else
		{
			t=c[f[i]];
			while (b[t]>0)
				t=b[t];
			b[t]=i;
		}
		if (op=='L') scanf("%d",&w[i]);
		scanf("%c",&l);
	}
	t=s(1,1);
	if (t>0) printf("+");
	printf("%d\n",t);
	return 0;
}



