#include <stdio.h>

long p[101];
long bin[101];

int main()
{
	long i,n;
	scanf("%d",&n);
	bin[0]=0;
	while (n>0)
	{
		bin[0]++;
		bin[bin[0]]=n&1;
		n/=2;
	}
	n=0;
	p[0]=0;
	for (i=bin[0]-1;i>0;i--)
	{
		if (bin[i]>0)
		{
			n++;
			p[n]=1;
			n++;
			p[n]=0;
		}
		else
		{
			n++;
			p[n]=1;
		}
	}
	for (i=n;i>=0;i--)
		if (p[i]==0)
			printf("BELL&RET\n");
		else
			printf("CALL %d\n",n-i+1);
	return 0;
}

		


