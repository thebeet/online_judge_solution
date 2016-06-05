#include <stdio.h>
#include <memory.h>

char s[100];
long hp[1000];
long inp[1000];
long dx;
long op;

int main()
{
	long i,ti,j,n;
	scanf("%d",&n);
	memset(hp,0,sizeof(hp));
	for (ti=1;ti<=n;ti++)
	{
		memset(s,0,sizeof(s));
		memset(inp,0,sizeof(inp));
		scanf("%s",&s);
		i=2;
		inp[1]=s[0]-48;
		inp[0]=1;
		if (s[1]=='e') i--;
		while (s[i]!='e')
		{
			inp[0]++;
			inp[inp[0]]=s[i]-48;
			i++;
		}
		op=1;
		dx=0;
		i++;
		if (s[i]=='-')
		{
			op=-1;
			i++;
		}
		while (s[i]>20)
		{
			dx=dx*10+s[i]-48;
			i++;
		}
		dx*=op;
		dx+=500;
		for (i=1;i<=inp[0];i++)
			hp[dx-i]+=inp[i];
	}
	i=900;
	while (hp[i]==0)
		i--;
	if (hp[i-19]>=5) hp[i-18]++;
	j=i-18;
	while (hp[j]==10)
	{
		hp[j]=0;
		j++;
		hp[j]++;
	}
	if (hp[i+1]>0) i++;
	printf("%d.",hp[i]);
	for (j=1;j<=18;j++)
		printf("%d",hp[i-j]);
	printf("e%d\n",i-499);
	return 0;
}
