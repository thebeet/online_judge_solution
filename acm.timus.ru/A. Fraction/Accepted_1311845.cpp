#include <stdio.h>
#include <memory.h>

long s[100000];
long h[100000];
long z[100000];

void out(long n)
{
	char c1;
	if (n<10) printf("%d",n);
	else
	{
		c1=(n+55)%256;
		printf("%c",c1);
	}
}

int main()
{
	long i,j,n,p,q,a,b,k;
	bool flag;
	scanf("%d%d",&a,&b);
	while ((a>0) && (b>0))
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
			flag=false;
			for (;;)
			{
				n++;
				h[q]=n;
				q*=k;
				z[n]=q/b;
				q%=b;
				if (q==0)
				{
					for (i=1;i<=n;i++)
						out(z[i]);
					break;
				}
				if (h[q]!=0)
				{
					for (i=1;i<h[q];i++)
						out(z[i]);
					printf("(");
					for (i=h[q];i<=n;i++)
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
