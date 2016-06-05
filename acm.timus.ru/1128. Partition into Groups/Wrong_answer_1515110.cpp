#include <stdio.h>
#include <memory.h>

long adv[10000][4];
bool team[10000];

int main()
{
	long i,j,n,s;
	bool flag;
	memset(adv,0,sizeof(adv));
	memset(team,false,sizeof(team));
	scanf("%ld",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&adv[i][0]);
		for (j=1;j<=adv[i][0];j++)
		{
			scanf("%ld",&adv[i][j]);
		}
	}
	flag=true;
	while (flag)
	{
		flag=false;
		for (i=1;i<=n;i++)
		{
			s=0;
			for (j=1;j<=adv[i][0];j++)
			{
				if (team[i]==team[adv[i][j]]) s++;
			}
			if (s>1)
			{
				team[i]=!team[i];
				flag=true;
			}
		}
	}
	s=0;
	for (i=1;i<=n;i++)
	{
		if (team[i]) s++;
	}
	if (s>n/2) 
	{
		printf("%ld\n",n-s);
	}
	else
	{
		printf("%ld\n",s);
	}
	for (i=1;i<=n;i++)
	{
		if (team[i]^(s>n/2)) printf("%ld ",i);
	}
	printf("\n");
	return 0;
}
