#include <stdio.h>
#include <memory.h>

long s[1000];
long h[1000];
long z[1000];

void out(long n)
{
	if (n<10) printf("%d",n);
	else
		printf("%c",n+55);
}

int main()
{
	long i,j,n,p,q,a,b,k;
	bool flag;
	scanf("%d%d",&a,&b);
	while (a>0)
	{
		scanf("%d",&k);
		memset(s,0,sizeof(s));
		memset(h,0,sizeof(h));
		memset(z,0,sizeof(z));
		p=a/b;
		q=a%b;
		if (p==0) printf("0");
		else
		{
			while (p>0)
			{
				s[0]++;
				s[s[0]]=p%k;
				p/=k;
			}
			for (i=s[0];i>=1;i--)
				out(s[i]);
		}
		if (q==0)
			printf("\n");
		else
		{
			printf(".");
			n=0;
			for (;;)
			{
				n++;
				h[n]=q;
				q*=k;
				z[n]=q/b;
				q%=b;
				if (q==0)
				{
					for (i=1;i<=n;i++)
						out(z[i]);
					break;
				}
				flag=false;
				for (j=1;j<=n;j++)
					if (h[j]==q)
					{
						flag=true;
						break;
					}
				if (flag)
				{
					for (i=1;i<j;i++)
						out(z[i]);
					printf("(");
					for (i=j;i<=n;i++)
						out(z[i]);
					printf(")");
					break;
				}
			}
			printf("\n");
		}
		scanf("%d%d",&a,&b);
	}
	return 0;
}