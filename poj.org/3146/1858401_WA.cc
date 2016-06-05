#include <stdio.h>
#include <memory.h>

long nn[100];
long ss[100];

int main()
{
	long i,j,n,p,nt,pt,s;
	scanf("%d%d",&p,&n);
	while (p>0)
	{
		nt=n;
		memset(nn,0,sizeof(nn));
		while (nt>0)
		{
			nn[0]++;
			nn[nn[0]]=nt%p;
			nt/=p;
		}
		pt=1;
		for (i=2;i<=nn[0];i++)
		{
			pt*=p;
			ss[i]=((pt-n%pt-1)+ss[i-1])*nn[i]+ss[i-1];
		}
		s=n+1-ss[nn[0]];
		printf("%d",s%10000/1000);
		printf("%d",s%1000/100);
		printf("%d",s%100/10);
		printf("%d\n",s%10);
		scanf("%d%d",&p,&n);
	}
	return 0;
}
