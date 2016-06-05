#include <stdio.h>

int main()
{
	__int64 i,j,n,nn,s,t,ti,tn;
	__int64 bin[50];
	scanf("%I64d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%I64d",&n);
		bin[0]=0;
		nn=n;
		while (nn>0)
		{
			bin[0]++;
			bin[bin[0]]=nn%2;
			nn/=2;
		}
		for (i=1;i<=bin[0];i++)
			if (bin[i]==1) break;
		for (j=1;j<=i;j++)
			bin[j]=1;
		s=0;
		for (i=bin[0];i>0;i--)
			s=s*2+bin[i];
		t=n*2-s;
		printf("%I64d %I64d\n",t,s);
	}
	return 0;
}





		