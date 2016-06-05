#include <stdio.h>

long xa,ya;

long abs(long n)
{
	if (n>0) return n;
	else return (-n);
}

long slen(long x,long y)
{
	return (abs(x-xa)+abs(y-ya));
}

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
	long i,j,xb,yb,s,ss,n,m,l,ans,tdam;
	scanf("%ld%ld%ld",&n,&m,&l);
	scanf("%ld%ld%ld%ld",&xa,&ya,&xb,&yb);
	s=abs(xa-xa)+abs(ya-yb);
	if (s>l+1)
	{
		printf("%d\n",0);
		return 0;
	}
	ans=0;
	for (i=1;i<=n;i++)
	{
		if (i==xb) continue;
		tdam=abs(xb-i)+1;
		if (tdam>ans)
		{
			if (yb>1)
			{
				ss=slen(i,yb-1);
				if ((ss+tdam-1)<=l) ans=tdam;
			}
			if (yb<m)
			{
				ss=slen(i,yb+1);
				if ((ss+tdam-1)<=l) ans=tdam;
			}
		}
		tdam--;
		if (tdam>ans)
		{
			ss=slen(i,yb);
			if (ya==yb)
			{
				if ((xa>xb) && (xb>i))
				{
					if (m==1)
					{
						ss=1000000;
					}
					else
					{
						ss+=2;
					}
				}
				if ((xa<xb) && (xb<i))
				{
					if (m==1)
					{
						ss=1000000;
					}
					else
					{
						ss+=2;
					}
				}
			}
			if ((ss+tdam-1)<=l) ans=tdam;
		}
	}
	for (j=1;j<=m;j++)
	{
		if (j==yb) continue;
		tdam=abs(yb-j)+1;
		if (tdam>ans)
		{
			if (xb>1)
			{
				ss=slen(xb-1,j);
				if ((ss+tdam-1)<=l) ans=tdam;
			}
			if (xb<n)
			{
				ss=slen(xb+1,j);
				if ((ss+tdam-1)<=l) ans=tdam;
			}
		}
		tdam--;
		if (tdam>ans)
		{
			ss=slen(xb,j);
			if (xa==xb)
			{
				if ((ya>yb) && (yb>j))
				{
					if (n==1)
					{
						ss=1000000;
					}
					else
					{
						ss+=2;
					}
				}
				if ((ya<yb) && (yb<j))
				{
					if (n==1)
					{
						ss=1000000;
					}
					else
					{
						ss+=2;
					}
				}
			}
			if ((ss+tdam-1)<=l) ans=tdam;
		}
	}
	printf("%ld\n",ans);
	return 0;
}	
