#include <stdio.h>
#include <memory.h>

long sr[110],sc[110],ans[110][110];
long n;

long check(long d)
{
	long i;
	long s;
	s=0;
	for (i=1;i<=n;i++)
	{
		if (sc[i]>d)
		{
			if ((sc[i]-d)>100)
			{
				s+=100;
			}
			else
			{
				s+=(sc[i]-d);
			}
		}
	}
	return s;
}

int main()
{
	long i,j,a,b,m,ret;
	bool aans;
	scanf("%ld",&n);
	aans=true;
	memset(sr,0,sizeof(sr));
	memset(sc,0,sizeof(sc));
	memset(ans,0,sizeof(ans));
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&sr[i]);
		if (sr[i]>n*100) aans=false;
		sr[0]+=sr[i];
	}
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&sc[i]);
		if (sc[i]>n*100) aans=false;
		sc[0]+=sc[i];
	}
	if (sc[0]!=sr[0]) aans=false;
	if (aans)
	{
		for (i=1;i<=n;i++)
		{
			a=0;
			if (sr[i]==0) continue;
			if (check(0)<sr[i])
			{
				aans=false;
				break;
			}
			b=10010;
			while (a+1!=b)
			{
				m=(a+b)>>1;
				ret=check(m);
				if (sr[i]<=ret)
				{
					a=m;
				}
				else
				{
					b=m;
				}
			}
			ret=check(a);
			for (j=1;j<=n;j++)
			{
				if (sc[j]>a)
				{
					if ((sc[j]-a)>100)
					{
						sc[j]-=100;
						ans[i][j]=100;
					}
					else
					{
						ans[i][j]=(sc[j]-a);
						sc[j]=a;
					}
				}
			}
			ret-=sr[i];
			for (j=1;ret>0;j++)
			{
				if ((ans[i][j]>0) && (sc[j]==a))
				{
					ans[i][j]--;
					sc[j]++;
					ret--;
				}
			}	
		}	
				
		if (aans)
		{
			printf("YES\n");
			for (i=1;i<=n;i++)
			{
				for (j=1;j<n;j++)
				{
					printf("%ld ",ans[i][j]);
				}
				printf("%ld\n",ans[i][j]);
			}
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
