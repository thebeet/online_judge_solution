#include <stdio.h>
#include <memory.h>
char s;
long b1[300],b2[300],b3[300],b4[300];

int main()
{
	long i,n,t,j;
	scanf("%d",&n);
	scanf("%c",&s);
	for (i=1;i<=n;i++)
	{
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		memset(b3,0,sizeof(b3));
		memset(b4,0,sizeof(b4));
		b1[0]=1;
		scanf("%c",&s);
		b1[b1[0]]=s-48;
		while (s>40)
		{
			b1[0]++;
			scanf("%c",&s);
			b1[b1[0]]=s-48;
		}
		b1[0]--;
		for (j=1;j<=b1[0];j++)
			b3[j]=b1[b1[0]-j+1];
		b2[0]=1;
		scanf("%c",&s);
		b2[b2[0]]=s-48;
		while (s>40)
		{
			b2[0]++;
			scanf("%c",&s);
			b2[b2[0]]=s-48;
		}
		b2[0]--;
		for (j=1;j<=b2[0];j++)
			b4[j]=b2[b2[0]-j+1];
		t=0;
		for (j=1;j<=b1[0]+b2[0]+1;j++)
		{
			b3[j]=b3[j]+b4[j]+t;
			t=b3[j]/2;
			b3[j]=b3[j]%2;
		}
		b3[0]=200;
		while (b3[b3[0]]==0)
			b3[0]--;
		printf("%d ",i);
		if (b3[0]==0) printf("%d",0);
		for (j=b3[0];j>=1;j--)
			printf("%d",b3[j]);
		printf("\n");
	}
	return 0;
}