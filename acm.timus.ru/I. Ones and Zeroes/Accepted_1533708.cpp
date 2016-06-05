#include <stdio.h>
#include <string.h>

char p[100010],q[100010];

int main()
{
	long i,j,n,m,sp;
	char c;
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
	scanf("%ld",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%c",&c);
		if ((c=='0') || (c=='1'))
		{
			p[i]=c-48;
		}
		else
		{
			i--;
		}
	}
	for (i=1;i<=n;i++)
	{
		scanf("%c",&c);
		if ((c=='0') || (c=='1'))
		{
			q[i]=c-48;
		}
		else
		{
			i--;
		}
	}
	i=n;
	q[i]++;
	while (q[i]==2)
	{
		q[i]=0;
		i--;
		q[i]++;
	}
	if (i==0)
	{
		i=n;
		p[i]++;
		while (p[i]==2)
		{
			p[i]=0;
			i--;
			p[i]++;
		}
		for (i=1;i<=n;i++)
		{
			printf("%c",p[i]+48);
		}
		printf("\n");
		for (i=1;i<=n;i++)
		{
			printf("%c",q[i]+48);
		}
		printf("\n");
		return 0;
	}
	sp=n;
	for (j=n;j>=1;j--)
	{
		if ((p[j]==1) && (q[j]==1))
		{
			sp=j;
			i=j;
			q[i]++;
			while (q[i]==2)
			{
				q[i]=0;
				i--;
				q[i]++;
			}
			if (i==0)
			{
				i=n;
				p[i]++;
				while (p[i]==2)
				{
					p[i]=0;
					i--;
					p[i]++;
				}
				for (i=1;i<=n;i++)
				{
					printf("%c",p[i]+48);
				}
				printf("\n");
				for (i=1;i<=n;i++)
				{
					printf("0");
				}
				printf("\n");
				return 0;
			}
/*			else
			{
				for (i=1;i<=n;i++)
				{
					printf("%c",p[i]+48);
				}
				printf("\n");
				for (i=1;i<j;i++)
				{
					printf("%c",q[i]+48);
				}
				for (i=j;j<=n;j++)
				{
					printf("0");
				}
				printf("\n");
			}
			return 0;*/
		}
	}
	for (i=1;i<=n;i++)
	{
		printf("%c",p[i]+48);
	}
	printf("\n");
	for (i=1;i<=sp;i++)
	{
		printf("%c",q[i]+48);
	}
	for (i=sp+1;i<=n;i++)
	{
		printf("0");
	}
	printf("\n");
	return 0;
}
