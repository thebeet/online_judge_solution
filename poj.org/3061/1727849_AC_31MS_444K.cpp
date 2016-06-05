#include <stdio.h>
#include <memory.h>

long a[100010];

int main()
{
	long ti,tn,i,n,s,ss,m,p1,p2;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d",&n,&s);
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[n+1]=s;
		p2=1;
		ss=a[1];
		m=n+1;
		for (p1=1;p1<=n;p1++)
		{
			while (ss<s)
			{
				p2++;
				ss+=a[p2];
			}
			if ((p2<=n) && (m>p2-p1)) m=p2-p1;
			if (p2>n)
			{
				p2=n;
				ss-=s;
			}
			ss-=a[p1];
		}
		if (m==n+1) m=-1;
		printf("%d\n",m+1);
	}
	return 0;
}
