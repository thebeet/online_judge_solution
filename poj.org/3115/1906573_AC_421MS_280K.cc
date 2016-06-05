#include <stdio.h>
#include <memory.h>

long edp[30][1010],dp[30][1010];

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	long i,j,f,g,p,e,a,x,y,m;
	scanf("%ld%ld%ld%ld",&f,&p,&e,&a);
	while (f>0)
	{
		e*=a;
		memset(edp,0,sizeof(edp));
		memset(dp,50,sizeof(dp));
		dp[1][0]=0;
		for (i=1;i<=p;i++)
		{
			for (j=1;j<=f;j++)
			{
				scanf("%ld%ld",&x,&y);
				edp[j][i]=x*y;
				m=1000000000;
				for (g=1;g<=f;g++)
				{
					if (g==j) m=mn(m,dp[g][i-1]);
					else m=mn(m,dp[g][i-1]+e);
				}
				dp[j][i]=m+edp[j][i];
			}
		}
		m=1000000000;
		for (g=1;g<=f;g++)
		{
			m=mn(m,dp[g][p]);
		}
		printf("%ld\n",m);
		scanf("%ld%ld%ld%ld",&f,&p,&e,&a);
	}
	return 0;
}
