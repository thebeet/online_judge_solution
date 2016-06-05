#include <stdio.h>
#include <memory.h>

#define MAXN 100010

long a[200010];
long b[200010];
long p[MAXN];
long s[MAXN];
long ss[MAXN];
long dl[MAXN];
bool us[MAXN];
long ansa[MAXN];
long ansb[MAXN];

void sort(long l,long r)
{
	long i,j,x,y;
	i=l;
	j=r;
	x=a[(i+j)/2];
	while (i<=j)
	{
		while (a[i]<x) 
			i++;
		while (a[j]>x) 
			j--;
		if (i<=j)
		{
			y=a[i];
			a[i]=a[j];
			a[j]=y;
			y=b[i];
			b[i]=b[j];
			b[j]=y;
			i++;
			j--;
		}
	}
	if (i<r) sort(i,r);
	if (j>l) sort(l,j);
}

int main()
{
	long i,j,k,n,m,t,ans;
	scanf("%d%d",&n,&m);
	m<<=1;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for (i=1;i<=m;i+=2)
	{
		scanf("%d%d",&a[i],&b[i]);
		a[i+1]=b[i];
		b[i+1]=a[i];
	}
	sort(1,m);
	memset(s,0,sizeof(s));
	memset(ss,0,sizeof(ss));
	memset(p,0,sizeof(p));
	n=0;
	for (i=1;i<=m;i++)
	{
		if (a[i]!=a[i-1])
		{
			if (ss[n]==0)
			{
				dl[0]++;
				dl[dl[0]]=n;
			}
			p[n+1]=p[n]+ss[n]+1;
			s[n]=p[n]+s[n];
			n++;
		}
		else
			ss[n]++;
	}
	if (s[n]==0)
	{
		dl[0]++;
		dl[dl[0]]=n;
	}
	p[n+1]=p[n]+s[n]+1;
	ss[n]=s[n];
	memset(us,false,sizeof(us));
	ans=0;
	for (i=2;i<=dl[0];i++)
	{
		t=dl[i];
		if (!us[t])
		{
			us[t]=true;
			for (j=p[t];j<=s[t];j++)
				if (!us[b[j]])
					break;
			k=b[j];
			ans++;
			ansa[ans]=t;
			ansb[ans]=k;
			us[k]=true;
			for (j=p[k];j<=s[k];j++)
				if (!us[b[j]])
				{
					ss[b[j]]--;
					if (ss[b[j]]==0)
					{
						dl[0]++;
						dl[dl[0]]=b[j];
					}
					if (ss[b[j]]==-1)
						us[b[j]]=true;
				}
		}
	}
	printf("%d\n",ans);
	for (i=1;i<=ans;i++)
		printf("%d %d\n",ansa[i],ansb[i]);
	return 0;
}
