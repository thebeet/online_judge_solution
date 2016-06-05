#include <stdio.h>
#include <memory.h>

long st[1500];
long ans[1500];

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	long i,j,n,t,h,m,s,p,g,wait,teeready;
	t=1676;
	scanf("%ld",&n);
	memset(st,0,sizeof(st));
	wait=0;
	for (i=1;i<=n+n;i++)
	{
		if (i>n)
		{
			st[i]=100000000;
		}
		else
		{
			scanf("%ld:%ld:%ld",&h,&m,&s);
			st[i]=(((h*60+m)*60+s)*10);
		}
		if (wait==0)
		{
			wait=1;
			teeready=st[i]+t;
			p=i;
		}
		else
		{
			while (teeready<=st[i])
			{
				for (j=p;j<=p+wait-1;j++)
					ans[j]=teeready;
				p+=wait;
				g=mn(5,i-p);
				if (g>0)
				{
					teeready+=g*t;
					wait=g;
				}
				else
				{
					teeready=st[i]+t;
					wait=1;
				}
			}
			if (p!=i)
			{
				if (wait<5)
				{
					wait++;
					teeready+=t;
				}
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		ans[i]=(ans[i]+5)/10;
		s=ans[i]%60;
		ans[i]/=60;
		m=ans[i]%60;
		ans[i]/=60;
		h=ans[i]%24;
		if (h<10) printf("0");
		printf("%ld:",h);
		if (m<10) printf("0");
		printf("%ld:",m);
		if (s<10) printf("0");
		printf("%ld\n",s);
	}
	return 0;
}
