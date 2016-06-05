#include <stdio.h>
#include <memory.h>

long m[1000010];

long mn(long a,long b)
{
	if ((a>b) || (a==0)) return b;
	else return a;
}

int main()
{
	long i,j,n,p,pt,rs,d;
	scanf("%ld",&n);
	if (n<=2)
	{
		printf("%ld\n",n);
		return 0;
	}
	p=1;
	rs=0;
	memset(m,0,sizeof(m));
	m[0]=1;
	for (i=2;i<=30;i++)
	{
		d=1<<i;
		rs=(rs-p+n)%n;
		for (j=0;j<n;j++)
		{
			if ((m[j]>0) && ((m[j]&d)==0))
			{
				pt=(j+p)%n;
				m[pt]=mn(m[pt],m[j]+d);
			}
		}
		if (m[rs]>0) break;
		p=(p*10)%n;
	}
	if (i>30) 
	{
		printf("Impossible\n");
		return 0;
	}
	n=i;
	for (i=n;i>=1;i--)
	{
		if ((m[rs]&(1<<i))>0) printf("2");
		else printf("1");
	}
	printf("\n");	
	return 0;
}
