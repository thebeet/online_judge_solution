#include <stdio.h>
#include <memory.h>

long nim[1000];
bool nimu[1000];
long bin[100];

int main()
{
	long i,j,t,n;
	nim[0]=0;
	nim[1]=1;
	nim[2]=1;
	for (i=3;i<=500;i++)
	{
		memset(nimu,false,sizeof(nimu));
		nimu[nim[i-2]]=true;
		for (j=0;j<=i-3;j++)
		{
			t=nim[i-3-j]^nim[j];
			nimu[t]=true;
		}
		t=0;
		while (nimu[t])
			t++;
		nim[i]=t;
	}
	scanf("%d",&n);
	if (n>200) n=(n%34)+34*2;
	if (nim[n]==0) printf("Black\n");
	else printf("White\n");
	return 0;
}
